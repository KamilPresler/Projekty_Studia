


package sudoku;

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.apache.commons.lang3.builder.ToStringBuilder;
import sudoku.exceptions.CloneException;

public class SudokuBoard implements Serializable, Cloneable {
    private final List<List<SudokuField>> board;
    private BacktrackingSudokuSolver bss;

    public SudokuBoard(BacktrackingSudokuSolver solver) {
        bss = solver;
        board = Arrays.asList(new List[9]);


        for (int i = 0; i < 9; i++) {
            board.set(i, Arrays.asList(new SudokuField[9]));
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                this.board.get(i).set(j, new SudokuField(0));
            }
        }

    }

    public SudokuField getField(int x, int y) {
        return board.get(x).get(y);
    }

    public int get(int x, int y) {
        return board.get(x).get(y).getValue();
    }

    public String getString(int x, int y) {
        return board.get(x).get(y).getStringValue();
    }

    public void set(int x, int y, int value) {
        this.board.get(x).get(y).setValue(value);
    }

    public void setLoad(int x, int y, int value, boolean editable) {
        this.board.get(x).get(y).setValue(value);
        this.board.get(x).get(y).setEditable(editable);
    }

    public void setString(int x,int y, String s) {
        this.board.get(x).get(y).setStringValue(s);
    }

    public void solveGame() {
        bss.solve(this);
    }

    public SudokuRow getRow(int row) {
        List<SudokuField> fields = Arrays.asList(new SudokuField[9]);
        for (int i = 0; i < 9; i++) {
            fields.set(i, board.get(row).get(i));
        }

        return new SudokuRow(fields);
    }

    public SudokuColumn getColumn(int column) {
        List<SudokuField> fields = Arrays.asList(new SudokuField[9]);
        for (int i = 0; i < 9; i++) {
            fields.set(i, board.get(i).get(column));
        }

        return new SudokuColumn(fields);
    }

    public SudokuBox getBox(int rowIndex, int columnIndex) {
        List<SudokuField> fields = Arrays.asList(new SudokuField[9]);
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                fields.set(index++, board.get(rowIndex * 3 + i).get(columnIndex * 3 + j));
            }
        }

        return new SudokuBox(fields);
    }

    private boolean checkBoard() {
        boolean check = true;
        for (int i = 0; i < 9; i++) {
            check = getRow(i).verify();
            if (!check) {
                break;
            }
            check = getColumn(i).verify();
            if (!check) {
                break;
            }
            for (int j = 0; j < 9; j++) {
                check = getBox(i / 3, j / 3).verify();
                if (!check) {
                    break;
                }
            }
        }
        return check;
    }

    public boolean getCheckBoard() {
        return checkBoard();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }

        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        SudokuBoard that = (SudokuBoard) o;

        return new EqualsBuilder().append(board, that.board).isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder(17, 37).append(board).append(bss).toHashCode();
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this)
                .append("board", board)
                .append("bss", bss)
                .toString();
    }


    @Override
    public SudokuBoard clone() throws CloneException {
        SudokuBoard sudoku = new SudokuBoard(bss);
        try {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    sudoku.board.get(i).set(j, this.board.get(i).get(j).clone());
                }
            }
        } catch (CloneNotSupportedException e) {
            throw new CloneException(e.getMessage());
        }
        return sudoku;
    }
}



