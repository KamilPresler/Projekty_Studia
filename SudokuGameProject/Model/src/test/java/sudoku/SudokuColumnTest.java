package sudoku;

import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.assertTrue;

public class SudokuColumnTest {
    private SudokuColumn column;

    @Before
    public void setUp() {
        column = new SudokuColumn(Arrays.asList(
                new SudokuField(1),
                new SudokuField(2),
                new SudokuField(3),
                new SudokuField(4),
                new SudokuField(5),
                new SudokuField(6),
                new SudokuField(7),
                new SudokuField(8),
                new SudokuField(9)));
    }
    @Test
    public void cloneTest() throws CloneNotSupportedException {
        SudokuColumn column2 =  column.clone();
        assertTrue(column.equals(column2) && column2.equals(column));
    }
}
