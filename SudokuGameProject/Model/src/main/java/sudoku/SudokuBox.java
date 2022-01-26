


package sudoku;

import java.util.List;

public class SudokuBox extends SudokuFieldType {
    public SudokuBox(final List<SudokuField> fields) {
        super(fields);
    }

    @Override
    protected SudokuBox clone() throws CloneNotSupportedException {
        SudokuBox box = new SudokuBox(fields);
        for (int i = 0; i < 9; i++) {
                box.fields.set(i,this.fields.get(i).clone());
            }
        return box;
    }
}
