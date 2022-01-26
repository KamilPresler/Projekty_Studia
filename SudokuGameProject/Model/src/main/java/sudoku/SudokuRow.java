


package sudoku;

import java.util.List;

public class SudokuRow extends SudokuFieldType {
    public SudokuRow(final List<SudokuField> fields) {
        super(fields);
    }

    @Override
    protected SudokuRow clone() throws CloneNotSupportedException {
        SudokuRow row = new SudokuRow(fields);
        for (int i = 0; i < 9; i++) {
            row.fields.set(i,this.fields.get(i).clone());
        }
        return row;
    }
}
