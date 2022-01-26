


package sudoku;

import java.io.Serializable;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.apache.commons.lang3.builder.ToStringBuilder;


public abstract class SudokuFieldType implements Serializable, Cloneable {
    protected List<SudokuField> fields;

    public SudokuFieldType(List<SudokuField> field) {
        fields = Arrays.asList(new SudokuField[9]);
        for (int i = 0; i < 9; i++) {
            fields.set(i,field.get(i));
        }

    }

    public boolean verify() {
        for (int i = 0; i < 9; i++) {
            int b = Collections.frequency(fields,fields.get(i));
            if (b != 1) {
                return false;
            }
            if (fields.get(i).getValue() == 0) {
                return false;
            }
        }
        return true;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        SudokuFieldType that = (SudokuFieldType) o;

        return new EqualsBuilder().append(fields, that.fields).isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder(17, 37).append(fields).toHashCode();
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this)
                .append("fields", fields)
                .toString();
    }


}

