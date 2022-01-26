package sudoku.exceptions;

public class WrongValueException extends NumberFormatException {
    public WrongValueException(String message) {
        super(message);
    }
}
