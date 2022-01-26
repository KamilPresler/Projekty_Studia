


package sudoku;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.junit.Assert.assertNotNull;

public class SudokuBoardTest {
    private SudokuBoard sudoku;
    private BacktrackingSudokuSolver solver;
    private BacktrackingSudokuSolver solver1;
    private SudokuBoard sudoku2;
    private SudokuField field;

    @Before
    public void setUp() {
        solver = new BacktrackingSudokuSolver();
        sudoku = new SudokuBoard(solver);
        field = new SudokuField(3);
    }

    @Test
    public void getSetMethodsTest() {
        assertEquals(sudoku.get(3, 3), 0);
        sudoku.set(3, 3, 9);
        assertEquals(sudoku.get(3, 3), 9);
        assertEquals(sudoku.getString(3,3),"9");
        sudoku.setString(3, 3, "8");
        assertEquals(sudoku.get(3, 3), 8);
    }

    @Test
    public void solveGameTest() {
        sudoku.solveGame();
        assertTrue(sudoku.getCheckBoard());
    }
    @Test
    public void errorRowTest() {
        sudoku.solveGame();
        sudoku.set(1,1,7);
        sudoku.set(2,1,7);
        assertFalse(sudoku.getCheckBoard());
    }
    @Test
    public void errorColumnTest() {
        sudoku.solveGame();
        sudoku.set(0,0,1);
        sudoku.set(0,1,2);
        sudoku.set(0,2,3);
        sudoku.set(0,3,4);
        sudoku.set(0,4,5);
        sudoku.set(0,5,6);
        sudoku.set(0,6,7);
        sudoku.set(0,7,8);
        sudoku.set(0,8,9);
        sudoku.set(1,0,1);
        assertFalse(sudoku.getCheckBoard());
    }

    @Test
    public void errorBoxTest() {
        sudoku.solveGame();
        sudoku.set(1,1,7);
        sudoku.set(2,2,7);
        assertFalse(sudoku.getCheckBoard());
    }

    @Test
    public void getRowTest() {
        assertNotNull(sudoku.getRow(4));
    }

    @Test
    public void getColumnTest() {
        assertNotNull(sudoku.getColumn(1));
    }

    @Test
    public void getBoxTest() {
        assertNotNull(sudoku.getBox(2, 1));
    }

    @Test
    public void toStringTest() {
        assertNotNull(sudoku.toString());
    }

    @Test
    public void equalsTest() {
        sudoku2 = new SudokuBoard(solver);
        assertTrue(sudoku.equals(sudoku2)
                && sudoku2.equals(sudoku));
        assertTrue(sudoku.equals(sudoku));
    }
    @Test
public void notEqualsTest() {
        assertFalse(sudoku.equals(null));
        assertFalse(sudoku.equals(solver));
    }

    @Test
    public void hashCodeTest() {
        sudoku2 = new SudokuBoard(solver);
        assertEquals(sudoku.hashCode(), sudoku2.hashCode());
    }

    @Test
    public void cloneTest() throws CloneNotSupportedException {
        sudoku2 = sudoku.clone();
        assertTrue(sudoku.equals(sudoku2) && sudoku2.equals(sudoku));
        sudoku2.set(1,2,5);
        assertFalse(sudoku.equals(sudoku2) && sudoku2.equals(sudoku));
    }

@Test
    public void testGetField() {
  assertNotNull(sudoku.getField(2,2));
    }
}

