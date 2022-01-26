package sudoku;

import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class SudokuBoxTest {
    private SudokuBox box;

    @Before
    public void setUp() {
        box = new SudokuBox(Arrays.asList(
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
        SudokuBox box2 =  box.clone();
        assertTrue(box.equals(box2) && box2.equals(box));
    }
}
