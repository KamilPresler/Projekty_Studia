


package sudoku;

import org.junit.Before;
import org.junit.Test;


import static org.junit.Assert.*;


public class BacktrackingSudokuSolverTest {
    private SudokuBoard sudoku;
    private BacktrackingSudokuSolver solver;

    @Before
    public void setUp() {
        solver = new BacktrackingSudokuSolver();
        sudoku = new SudokuBoard(solver);
    }

//    public boolean checkRow(SudokuBoard board) {
//        for (int i = 0; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                for (int k = j + 1; k < 9; k++) {
//                    if (board.get(i, j) == board.get(i, k)) {
//                        fail("Row " + i + " is incorrect!");
//                        return false;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//
//    public boolean checkColumn(SudokuBoard board) {
//        for (int j = 0; j < 9; j++) {
//            for (int i = 0; i < 9; i++) {
//                for (int k = i + 1; k < 9; k++) {
//                    if (board.get(i, j) == board.get(k, j)) {
//                        fail("Column " + j + " is incorrect!");
//                        return false;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//
//    public boolean checkSmallSquare(SudokuBoard board) {
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                for (int checked = 0; checked < 9; checked++) {
//                    for (int compared = checked + 1; compared < 9; compared++) {
//                        if (board.get(i * 3 + (checked / 3), j * 3 + (checked % 3)) ==
//                                board.get(i * 3 + (compared / 3), j * 3 + (compared % 3))) {
//                            fail("Small board (" + i + ", " + j + ") is incorrect!");
//                            return false;
//                        }
//                    }
//                }
//            }
//        }
//        return true;
//    }
    @Test
    public void solveTest() {
        solver.solve(sudoku);
        assertTrue(sudoku.getCheckBoard());

    }
    @Test
    public void solveRepeatTest() {
        SudokuBoard s1 = new SudokuBoard(solver);
        SudokuBoard s2 = new SudokuBoard(solver);
        solver.solve(s1);
        solver.solve(s2);

        assertTrue(!(s1.equals(s2)));
    }
}

