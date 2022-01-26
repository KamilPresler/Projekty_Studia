package sudokuviewer;

import java.io.IOException;
import java.util.ResourceBundle;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;




public class SudokuApplication extends Application {
    private  FXMLLoader fxmlLoader = new FXMLLoader();



    @Override
    public void start(Stage stage) throws IOException {
        fxmlLoader.setResources(ResourceBundle.getBundle("Lang"));
        Parent root = fxmlLoader.load(getClass().getResourceAsStream("WelcomeScreen.fxml"));
        Scene scene = new Scene(root, 600, 400);
        stage.setTitle(ResourceBundle.getBundle("Lang").getString("Sudoku"));
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        Logger logger = LoggerFactory.getLogger(SudokuApplication.class);
        if (logger.isInfoEnabled()) {
            logger.info(ResourceBundle.getBundle("Lang").getString("run"));
        }
        launch();
    }
}