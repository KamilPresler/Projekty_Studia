package sudokuviewer;

import java.io.IOException;
import java.net.URL;
import java.util.Locale;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.stage.Stage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import sudoku.JdbcSudokuBoardDao;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.DatabaseException;
import sudoku.exceptions.ReadException;


public class MenuController implements Initializable  {

    @FXML
    private ComboBox difficult;
    @FXML
    private ComboBox changeLanguage;
    @FXML
    private ComboBox<String> changeBoard;
    private Parent gamescreen;
    private static String level;
    private static String language = ResourceBundle.getBundle("Lang").getString("lang");
    private Error er = new Error();
    private static Logger logger = LoggerFactory.getLogger(MenuController.class);
    private String nameBase = null;
    @FXML
    private Label authorsLabel;

    public static String getLanguage() {
        return language;
    }



    @FXML
    public String selectLevel(ActionEvent ae) {
        this.level = difficult.getSelectionModel().getSelectedItem().toString();
        return level;
    }

public void createScene(ActionEvent ae,Parent gamescreen) {
    Scene scene = new Scene(gamescreen, 600, 400);
    Stage stage = (Stage) ((Node) ae.getSource()).getScene().getWindow();
    stage.setTitle(ResourceBundle.getBundle("Lang").getString("Sudoku"));
    stage.setScene(scene);
    stage.show();
    setLevel(null);
}

    @FXML
    public void selectLanguage(ActionEvent ae) {
        try {
            try {
                if (changeLanguage.getSelectionModel().isSelected(0)) {
                    Locale.setDefault(new Locale("pl"));
                    language = "pl";
                    if (logger.isInfoEnabled()) {
                        logger.info(ResourceBundle.getBundle("Lang").getString("polish"));
                    }
                }
                if (changeLanguage.getSelectionModel().isSelected(1)) {
                    Locale.setDefault(new Locale("en"));
                    language = "en";
                    if (logger.isInfoEnabled()) {
                        logger.info(ResourceBundle.getBundle("Lang").getString("english"));
                    }
                }
                FXMLLoader fxmlLoader = new FXMLLoader();
                fxmlLoader.setResources(ResourceBundle.getBundle("Lang"));
                gamescreen = fxmlLoader.load(getClass().getResourceAsStream("WelcomeScreen.fxml"));
               createScene(ae,gamescreen);
            } catch (IOException e) {
                StringBuilder s1 = new StringBuilder();
                s1.append(ResourceBundle.getBundle("sudoku.Lang").getString("readAlert"));
                s1.append(" ");
                s1.append(e.getMessage());
                throw new ReadException(s1.toString(), e);
            }
        } catch (ReadException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
    }

    @FXML
    public void pressButton(ActionEvent ae) {
        if (level != null) {
            try {
                try {
                    FXMLLoader fxmlLoader = new FXMLLoader();
                    fxmlLoader.setResources(ResourceBundle.getBundle("Lang", new Locale(language)));
                    gamescreen = fxmlLoader.load(getClass().getResourceAsStream("Board.fxml"));
                    createScene(ae,gamescreen);
                } catch (IOException e) {
                    StringBuilder s1 = new StringBuilder();
                    s1.append(ResourceBundle.getBundle("sudoku.Lang").getString("readAlert"));
                    s1.append(" ");
                    s1.append(e.getMessage());
                    throw new ReadException(s1.toString(), e);
                }
            } catch (ReadException e) {
                if (logger.isErrorEnabled()) {
                    logger.error(e.getMessage());
                }
            }
        } else {
                er.messageBox(ResourceBundle.getBundle("Lang").getString("alert"),
                        ResourceBundle.getBundle("Lang").getString("alertLevel"),
                        Alert.AlertType.WARNING);
                if (logger.isErrorEnabled()) {
                    logger.error(ResourceBundle.getBundle("Lang").getString("alertLevel"));
                }

        }
    }

    @FXML
    public void pressComboBox(ActionEvent event) {
        for (int i = 0; i < changeBoard.getItems().size(); i++) {

            if (changeBoard.getSelectionModel().isSelected(i)) {
                nameBase = changeBoard.getItems().get(i);
            }
        }
        FXMLLoader loader = new FXMLLoader();
        setLevel(Difficulty.Data.toString());
        loader.setResources(ResourceBundle.getBundle("Lang", new Locale(language)));
        try {
            try {
                gamescreen = loader.load(getClass().getResourceAsStream("Board.fxml"));
                SudokuController sudokuController = loader.getController();
                sudokuController.setNameBase(nameBase);
                createScene(event, gamescreen);
            } catch (IOException e) {
                StringBuilder s1 = new StringBuilder();
                s1.append(ResourceBundle.getBundle("sudoku.Lang").getString("readAlert"));
                s1.append(" ");
                s1.append(e.getMessage());
                throw new ReadException(s1.toString(), e);
            }
        } catch (ReadException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
    }

    public static String getLevel() {
        return level;
    }

    public static void setLevel(String level) {
        MenuController.level = level;
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        changeLanguage.getItems().addAll(
                ResourceBundle.getBundle("Lang").getString("polish"),
                ResourceBundle.getBundle("Lang").getString("english")
        );
        difficult.getItems().addAll(
                ResourceBundle.getBundle("Lang").getString("easy"),
                ResourceBundle.getBundle("Lang").getString("normal"),
                ResourceBundle.getBundle("Lang").getString("hard")

        );

        try (JdbcSudokuBoardDao baza = new JdbcSudokuBoardDao("Baza");) {
            changeBoard.getItems().addAll(
                    baza.nameFromBase()
            );
        } catch (DatabaseException | CloseException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
        AuthorsBundle authorsBundle = new AuthorsBundle();
        Object[][] authors = authorsBundle.getContents();
        StringBuilder s1 = new StringBuilder();
        s1.append(resourceBundle.getBundle("Lang").getString("authorsMessageText"));
        s1.append("\n");
        for (Object[] author : authors) {
            s1.append(author[1]);
            s1.append("\n");
        }
        authorsLabel.textProperty().set(s1.toString());

    }

}


