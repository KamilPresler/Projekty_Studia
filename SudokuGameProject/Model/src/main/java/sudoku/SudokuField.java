


package sudoku;

import java.io.Serializable;
import java.util.Objects;
import java.util.ResourceBundle;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import sudoku.exceptions.WrongValueException;


public class SudokuField implements Serializable, Cloneable, Comparable<SudokuField> {
    private int value;
    private boolean isEditable = true;

    public boolean isEditable() {
        return isEditable;
    }

    public void setEditable(boolean editable) {
        isEditable = editable;
    }

    public SudokuField(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public String getStringValue() {
        return String.valueOf(value);
    }

    public boolean setStringValue(String s) {
        Logger logger = LoggerFactory.getLogger(SudokuField.class);
        boolean valid = true;
        try {
            try {
                this.value = Integer.parseInt(s);
            } catch (NumberFormatException e) {
                throw new WrongValueException(ResourceBundle.getBundle("sudoku.Lang")
                        .getString("wrongValueAlert"));
            }

        } catch (WrongValueException e) {
            if (logger.isErrorEnabled() && !Objects.equals(s, "")) {
                logger.error(e.getMessage());
            }
            valid = false;
        }
        return valid;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }

        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        SudokuField that = (SudokuField) o;

        return new EqualsBuilder().append(value, that.value).isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder(17, 37).append(value).toHashCode();
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this)
                .append("value", value)
                .toString();
    }

    @Override
    protected SudokuField clone() throws CloneNotSupportedException {
        return (SudokuField) super.clone();
    }

    @Override
    public int compareTo(SudokuField o) {
        if (this.getValue() == o.getValue()) {
            return 0;
        } else if (this.getValue() > o.getValue()) {
            return 1;
        }
        return -1;
    }
}
