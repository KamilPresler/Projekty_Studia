package sudoku;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.ResourceBundle;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.DatabaseException;


public class JdbcSudokuBoardDao implements Dao<SudokuBoard> {

    public static final String DRIVER = "org.sqlite.JDBC";
    public static final String URL = "jdbc:sqlite:sudokuBase.db";

    Logger logger = LoggerFactory.getLogger(JdbcSudokuBoardDao.class);


    private String name;

    public JdbcSudokuBoardDao(String name) {
        this.name = name;
            try {
                try {
                    Class.forName(JdbcSudokuBoardDao.DRIVER);
                } catch (ClassNotFoundException e) {
                    throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                                    .getString("classNotFoundAlert"),e);
                }
                createTable();
        } catch (DatabaseException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
    }


    public boolean createTable() throws DatabaseException {
        String startTransaction = "BEGIN TRANSACTION";
        String rollBackTransaction = "ROLLBACK";
        String commit = "COMMIT";
        String boards = "CREATE TABLE IF NOT EXISTS Boards (sudokuBoardId INTEGER PRIMARY KEY , name varchar(200) NOT NULL UNIQUE)";
        String fields = "CREATE TABLE IF NOT EXISTS Fields (x INTEGER, y INTEGER, value INTEGER, sudokuBoardId INTEGER, editable BOOLEAN, CONSTRAINT fk_sudokuBoardID FOREIGN KEY (sudokuBoardId)REFERENCES Boards(sudokuBoardId))";
        try (Connection connection = DriverManager.getConnection(URL);
             Statement statement = connection.createStatement()) {
                statement.execute(startTransaction);
                statement.execute(boards);
                statement.execute(fields);
                statement.execute(commit);
            } catch (SQLException e) {
                try (Connection connection = DriverManager.getConnection(URL);
                     Statement  statement = connection.createStatement()) {
                    statement.execute(rollBackTransaction);
                } catch (SQLException e1) {
                    throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                            .getString("rollbackAlert"), e1);
                }
                throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                        .getString("createTableAlert"), e);
            }
        return true;
    }


    public boolean insertInto(SudokuBoard s, String boardName) throws DatabaseException {
            String startTransaction = "BEGIN TRANSACTION";
            String rollBackTransaction = "ROLLBACK";
            String commit = "COMMIT";
            try (
                    Connection connection = DriverManager.getConnection(URL);
                    Statement  statement = connection.createStatement();
                    PreparedStatement pstmt1 = connection.prepareStatement(
                            "INSERT INTO Boards VALUES(?,?)");
                    PreparedStatement pstmt2 = connection.prepareStatement(
                            "INSERT INTO Fields VALUES(?,?,?,?,?)");
            ) {
                statement.execute(startTransaction);
                pstmt1.setString(2, boardName);
                pstmt1.executeUpdate();
                ResultSet result = statement.executeQuery("SELECT MAX(rowid) FROM Boards");
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        pstmt2.setInt(1, i);
                        pstmt2.setInt(2, j);
                        pstmt2.setInt(3, s.get(i, j));
                        pstmt2.setInt(4, result.getInt(1));
                        pstmt2.setBoolean(5, s.getField(i,j).isEditable());
                        pstmt2.executeUpdate();
                    }
                }
                statement.execute(commit);
            } catch (SQLException e) {
                try (Connection connection = DriverManager.getConnection(URL);
                     Statement  statement = connection.createStatement()) {
                     statement.execute(rollBackTransaction);
                } catch (SQLException e1) {
                    throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                                    .getString("rollbackAlert"), e1);
                }
                throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                        .getString("insertAlert"), e);
            }
        return true;
    }


    public ArrayList<String> nameFromBase() throws DatabaseException {
        ArrayList<String> names = new ArrayList<String>();
        String query = "SELECT name FROM Boards";
        try (Connection connection = DriverManager.getConnection(URL);
             Statement statement = connection.createStatement();
             ResultSet readBoard = statement.executeQuery(query)) {
            while (readBoard.next()) {
                names.add(readBoard.getString(1));
            }
        } catch (SQLException e) {
            throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                    .getString("selectAlert"), e);
        }
        return  names;
    }

    @Override
    public SudokuBoard read() throws DatabaseException {
        BacktrackingSudokuSolver bss = new BacktrackingSudokuSolver();
        SudokuBoard loadedSudoku = new SudokuBoard(bss);
        String query = "SELECT x, y, value, editable FROM Fields WHERE sudokuBoardId = (SELECT sudokuBoardId FROM Boards WHERE name ='" + name + "') ";
        try (Connection connection = DriverManager.getConnection(URL);
             Statement statement = connection.createStatement();
             ResultSet rs = statement.executeQuery(query)
        ) {
            while (rs.next()) {
                loadedSudoku.setLoad(rs.getInt("x"),rs.getInt("y"),rs.getInt("value"),rs.getBoolean("editable"));
            }
        } catch (SQLException e) {
            throw new DatabaseException(ResourceBundle.getBundle("sudoku.Lang")
                    .getString("readDatabaseAlert"), e);
        }
        return loadedSudoku;
    }


    @Override
    public void write(SudokuBoard object) throws DatabaseException {
        try {
            insertInto(object, name);
        } catch (DatabaseException e) {
            throw e;
        }
    }

    @Override
    public void close() throws CloseException {

    }
}

