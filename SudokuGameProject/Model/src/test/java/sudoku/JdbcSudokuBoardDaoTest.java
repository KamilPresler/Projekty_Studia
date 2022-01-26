package sudoku;

import org.junit.Test;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.DatabaseException;


import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;



public class JdbcSudokuBoardDaoTest {

    JdbcSudokuBoardDao sudokuBase = new JdbcSudokuBoardDao("name");
    BacktrackingSudokuSolver bss = new BacktrackingSudokuSolver();
    SudokuBoard sudoku = new SudokuBoard(bss);
    SudokuBoard sudoku2 = new SudokuBoard(bss);


    @Test
    public void createTableTest() throws DatabaseException, CloseException {
        try (JdbcSudokuBoardDao sudokuBase = new JdbcSudokuBoardDao("name");) {
            assertTrue(sudokuBase.createTable());
        } catch (DatabaseException | CloseException e) {
            throw e;
        }
    }


    @Test
    public void readWriteTest() throws DatabaseException, CloseException {
        try (JdbcSudokuBoardDao sudokuBase = new JdbcSudokuBoardDao("name");) {
            sudoku.solveGame();
            sudokuBase.write(sudoku);
            sudoku2 = sudokuBase.read();
            assertEquals(sudoku, sudoku2);
        } catch (DatabaseException | CloseException e) {
            throw e;
        }
    }

    @Test(expected = DatabaseException.class)
    public void readWriteExceptionTest() throws DatabaseException, CloseException {
        try (JdbcSudokuBoardDao sudokuBase = new JdbcSudokuBoardDao("name");) {
            sudoku.solveGame();
            sudokuBase.write(sudoku);
            sudoku2 = sudokuBase.read();
            assertEquals(sudoku, sudoku2);
        } catch (DatabaseException | CloseException e) {
            throw e;
        }
    }

    @Test
    public void nameFromBaseTest() throws DatabaseException, CloseException {
        try (JdbcSudokuBoardDao sudokuBase = new JdbcSudokuBoardDao("name");) {
            assertNotNull(sudokuBase.nameFromBase());
        } catch (DatabaseException | CloseException e) {
            throw e;
        }

    }
}
