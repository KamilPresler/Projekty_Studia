


package sudoku;

import java.util.List;

public class SudokuColumn extends SudokuFieldType {
    public SudokuColumn(final List<SudokuField> fields) {
        super(fields);
    }

    @Override
    protected SudokuColumn clone() throws CloneNotSupportedException {
        SudokuColumn column = new SudokuColumn(fields);
        for (int i = 0; i < 9; i++) {
            column.fields.set(i,this.fields.get(i).clone());
        }
        return column;
    }
}
