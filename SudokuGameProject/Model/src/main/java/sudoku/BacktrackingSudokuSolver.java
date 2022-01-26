
package sudoku;

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class BacktrackingSudokuSolver implements SudokuSolver, Serializable {
    public boolean isValid(int index, SudokuBoard board) {
       int row = index / 9;
       int column = index % 9;
        int number = board.get(row,column);
        for (int i = 0; i < column; i++) {
            if (number == board.get(row,i)) {
                return false;
            }
        }
        for (int i = 0; i < row; i++) {
            if (number == board.get(i,column)) {
                return false;
            }
        }
        int smallSquareRow = row / 3;
        int smallSquareColumn = column / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int mainRow = i + smallSquareRow * 3;
                int mainColumn = j + smallSquareColumn * 3;
                if (board.get(mainRow,mainColumn) == number
                        && (mainRow * 9 + mainColumn) < row * 9 + column) {
                    return false;
                }
            }
        }
        return true;
    }

    public void solve(SudokuBoard board) {
        Random rand = new Random();
        List<Integer> startNumbers = Arrays.asList(new Integer[81]);

        for (int i = 0; i < startNumbers.size(); i++) {
            startNumbers.set(i, 0);
        }
        for (int i = 0; i < 81; i++) {
            {
                boolean valid = false;
                if (startNumbers.get(i) == 0) {
                    startNumbers.set(i, rand.nextInt(9) + 1);
                    board.set(i / 9,i % 9,startNumbers.get(i));
                    do {
                        if (isValid(i,board)) {
                            valid = true;
                            break;
                        }
                        board.set(i / 9,i % 9,board.get(i / 9, i % 9) % 9 + 1);
                    } while (board.get(i / 9, i % 9) != startNumbers.get(i));
                } else {
                    board.set(i / 9, i % 9,board.get(i / 9, i % 9) % 9 + 1);
                    while (board.get(i / 9, i % 9) != startNumbers.get(i)) {
                        if (isValid(i,board)) {
                            valid = true;
                            break;
                        }
                        board.set(i / 9, i % 9,board.get(i / 9, i % 9) % 9 + 1);
                    }
                }
                if (!valid) {
                    startNumbers.set(i,0);
                    board.set(i / 9, i % 9,0);
                    i -= 2;
                    }
                }
            }
        }
}

