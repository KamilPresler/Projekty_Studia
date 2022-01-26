


package sudoku;

import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.*;

public class SudokuFieldTypeTest {
   private SudokuRow row;
   private SudokuRow row2;
   private SudokuRow invalidRow;
    private SudokuRow row0;
    @Before
    public void setUp(){
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
    invalidRow = new SudokuRow(Arrays.asList(
            new SudokuField(2),
            new SudokuField(2),
            new SudokuField(3),
            new SudokuField(4),
            new SudokuField(5),
            new SudokuField(6),
            new SudokuField(7),
            new SudokuField(8),
            new SudokuField(9)));
    row2 = new SudokuRow(Arrays.asList(
            new SudokuField(1),
            new SudokuField(2),
            new SudokuField(3),
            new SudokuField(4),
            new SudokuField(5),
            new SudokuField(6),
            new SudokuField(7),
            new SudokuField(8),
            new SudokuField(9)));
        row0 = new SudokuRow(Arrays.asList(
                new SudokuField(0),
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
    public void verifyValidTest() {

        assertTrue(row.verify());
        assertFalse(row0.verify());
    }

    @Test
    public void verifyInvalidTest() {

        assertFalse(invalidRow.verify());
    }
    @Test
    public void toStringTest() {
        assertNotNull(row.toString());
    }

    @Test
    public void equalsTest() {
        assertTrue(row.equals(row));
        assertTrue(row.equals(row2) && row2.equals(row));
    }
    @Test
    public void notEqualsTest() {
        assertFalse(row.equals(null));
        BacktrackingSudokuSolver bss= new BacktrackingSudokuSolver();
        assertFalse(row.equals(bss));
    }
    @Test
    public void hashCodeTest() {
        assertEquals(row.hashCode(), row2.hashCode());
    }
}
