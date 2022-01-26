module View {
    requires javafx.controls;
    requires javafx.fxml;
    requires org.apache.commons.lang3;
    requires sudoku;
    requires slf4j.api;
    requires logback.classic;


    opens sudokuviewer to javafx.fxml;
    exports sudokuviewer;
}