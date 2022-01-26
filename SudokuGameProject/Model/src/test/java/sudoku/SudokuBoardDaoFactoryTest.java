package sudoku;

import org.junit.Test;
import sudoku.exceptions.CloseException;

import static org.junit.Assert.assertNotNull;

public class SudokuBoardDaoFactoryTest {

    private SudokuBoardDaoFactory factory = new SudokuBoardDaoFactory();

    @Test
    public void getFileDaoTest()throws CloseException {
        try{
            try{
                assertNotNull(factory.getFileDao("factorytest"));
            } catch(Exception e) {
                throw new CloseException(e.getMessage());
            }
        }catch (CloseException e) {
            throw e;
        }

    }
    @Test
    public void getDatabaseDaoTest()throws CloseException {
        try{
            try{
                assertNotNull(factory.getDatabaseDao("factorytest"));
            } catch(Exception e) {
                throw new CloseException(e.getMessage());
            }
        }catch (CloseException e) {
            throw e;
        }
    }

}