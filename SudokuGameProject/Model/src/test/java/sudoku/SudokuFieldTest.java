


package sudoku;

import org.junit.Before;
import org.junit.Test;
import sudoku.exceptions.WrongValueException;

import java.util.ResourceBundle;

import static org.junit.Assert.*;

public class SudokuFieldTest {
    private SudokuField field;
    private SudokuField field2;
    @Before
    public void setUp() {
        field = new SudokuField(0);
    }

    @Test
    public void getFieldValueTest() {
        assertEquals(field.getValue(), 0);
    }

    @Test
    public void setFieldValueTest() {
        field.setValue(4);
        assertEquals(field.getValue(), 4);
        assertEquals(field.getStringValue(), "4");
        field.setStringValue("5");
        assertEquals(field.getValue(), 5);
    }
    @Test
    public void setWrongValueTest() {
        assertFalse(field.setStringValue("x"));
        }


    @Test
    public void toStringTest() {
        assertNotNull(field.toString());
    }

    @Test
    public void equalsTest() {
        field2 = new SudokuField(0);
        assertTrue(field.equals(field2)
                && field2.equals(field));
        assertTrue(field.equals(field));
    }
    @Test
    public void notEqualsTest() {
        assertFalse(field.equals(null));
        BacktrackingSudokuSolver bss = new BacktrackingSudokuSolver();
        assertFalse(field.equals(bss));
    }
    @Test
    public void hashCodeTest() {
        field2 = new SudokuField(0);
        assertEquals(field.hashCode(), field2.hashCode());
    }
    @Test
    public void compareToTest(){
        field.setValue(0);
        field2 = new SudokuField(0);
        assertEquals(0, field.compareTo(field2));
        field2.setValue(1);
        assertEquals(-1, field.compareTo(field2));
        field.setValue(3);
        assertEquals(1, field.compareTo(field2));
        assertThrows(NullPointerException.class, () -> {
           field2 = null;
           field.compareTo(field2);
        });
    }

}

