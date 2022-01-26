module sudoku {
    requires java.desktop;
    requires org.apache.commons.lang3;
    requires slf4j.api;
    requires java.sql;
    opens sudoku;
    exports sudoku;
    exports sudoku.exceptions;
}