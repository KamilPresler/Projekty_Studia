package sudoku;

import org.junit.Before;
import org.junit.Test;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.DaoException;
import sudoku.exceptions.ReadException;
import sudoku.exceptions.WriteException;

import java.io.*;
import java.util.Locale;
import java.util.ResourceBundle;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThrows;

public class FileSudokuBoardDaoTest {

    private SudokuBoardDaoFactory factory = new SudokuBoardDaoFactory();
    private BacktrackingSudokuSolver solver = new BacktrackingSudokuSolver();
    private SudokuBoard sudoku = new SudokuBoard(solver);
    private SudokuBoard sudoku2;
    private String sFile1 ="test_re";

    @Test
    public void writeReadTest() throws DaoException {
        try {
            try (Dao<SudokuBoard> sudokuDao = factory.getFileDao("test_wr")) {
                sudokuDao.write(sudoku);
                sudoku2 = sudokuDao.read();
                assertEquals(sudoku, sudoku2);
            } catch (Exception e) {
                throw new DaoException(e.getMessage(),e);
            }
        }catch (DaoException e) {
            throw e;
        }
    }
    @Test(expected = ReadException.class)
    public void readIOExceptionTest() throws ReadException {
        Locale.setDefault(new Locale("pl"));
        try {
            try (Dao<SudokuBoard> sudokuDao = factory.getFileDao("testr")) {
                sudokuDao.read();
            } catch (Exception e) {
                throw new ReadException(e.getMessage(), e);
            }
        } catch (ReadException e) {
            throw e;
        }
    }

    @Test(expected = WriteException.class)
    public void writeIOExceptionTest() throws WriteException {
        Locale.setDefault(new Locale("en"));
        try {
            try (Dao<SudokuBoard> sudokuDao = factory.getFileDao("?testw?")) {
                sudokuDao.write(sudoku);
            } catch (Exception e) {
                throw new WriteException(e.getMessage(), e);
            }
        } catch (WriteException e) {
            throw e;
        }
    }
}

