package sudoku;

import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.assertTrue;

public class SudokuRowTest {
    private SudokuRow row;

    @Before
    public void setUp() {
        row = new SudokuRow(Arrays.asList(
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
        SudokuRow row2 =  row.clone();
        assertTrue(row.equals(row2) && row2.equals(row));
    }
}
