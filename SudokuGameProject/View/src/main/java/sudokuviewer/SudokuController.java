package sudokuviewer;

import java.io.IOException;
import java.net.URL;
import java.util.Locale;
import java.util.Random;
import java.util.ResourceBundle;
import javafx.beans.binding.Bindings;
import javafx.beans.property.adapter.JavaBeanStringProperty;
import javafx.beans.property.adapter.JavaBeanStringPropertyBuilder;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import sudoku.BacktrackingSudokuSolver;
import sudoku.Dao;
import sudoku.SudokuBoard;
import sudoku.SudokuBoardDaoFactory;
import sudoku.exceptions.CloneException;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.DaoException;
import sudoku.exceptions.ReadException;
import sudoku.exceptions.WrongValueException;
import sudokuviewer.exceptions.MethodException;



public class SudokuController implements Initializable {
    public SudokuController() throws CloneNotSupportedException {
    }

    private final Error er = new Error();
    private final BacktrackingSudokuSolver bss = new BacktrackingSudokuSolver();
    private SudokuBoard sudoku2 = new SudokuBoard(bss);
    private SudokuBoard sudoku = sudoku2.clone();
    private SudokuBoard sudoku3;
    private Difficulty dif;
    private String nameBase = null;
    private Parent gamescreen;
    private Scene gameScene;
    private final FXMLLoader loader = new FXMLLoader(getClass().getResource("WelcomeScreen.fxml"));
    private final Logger logger = LoggerFactory.getLogger(SudokuController.class);


    @FXML
    private GridPane sudokuBoardGrid;

    private void fillGrid() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    TextField currentField = (TextField) sudokuBoardGrid
                            .getChildren().get(i * 9 + j);
                    if (!sudoku.getField(i, j).isEditable()) {
                        currentField.setDisable(true);
                    } else {
                        currentField.setText(String.valueOf(sudoku.get(i, j)));
                    }

                    try {
                        try {
                            JavaBeanStringPropertyBuilder builder =
                                    JavaBeanStringPropertyBuilder.create();
                            JavaBeanStringProperty stringProperty = null;
                            stringProperty = builder.bean(sudoku.getField(i, j))
                                    .name("StringValue").build();
                          Bindings.bindBidirectional(currentField.textProperty(),stringProperty);
                            if (sudoku.get(i, j) == 0) {
                                currentField.setText("");
                            }
                        } catch (NoSuchMethodException e) {
                            throw new MethodException(e.getMessage());
                        }
                    } catch (MethodException e) {
                        if (logger.isErrorEnabled()) {
                            logger.error(e.getMessage());
                        }
                    }


                    currentField.textProperty().addListener((observable, oldValue, newValue) -> {
                      try {
                          try {
                              if (Integer.parseInt(newValue) == 0) {
                                  currentField.setText(oldValue);
                              } else if (!(Integer.parseInt(newValue) >= 1
                                      && Integer.parseInt(newValue) <= 9)) {
                                  er.messageBox(ResourceBundle.getBundle("Lang").getString("alert"),
                                          ResourceBundle.getBundle("Lang").getString("alertValue"),
                                          Alert.AlertType.WARNING);
                                  if (logger.isErrorEnabled()) {
                                      logger.error(ResourceBundle.getBundle("Lang")
                                              .getString("alertValue"));
                                  }
                                  currentField.setText(oldValue);
                              }
                          } catch (NumberFormatException e) {
                              throw new WrongValueException(ResourceBundle.getBundle("sudoku.Lang")
                                      .getString("wrongValueAlert"));
                          }
                      } catch (WrongValueException e) {
                          currentField.clear();
                      }
                    });
                }
            }
    }

    public void prepareBoard(Difficulty dif) {
        int capacity = 0;
        int x;
        int y;
        Random random = new Random();
        if (dif != Difficulty.Data) {
            while (capacity < dif.getEmpty()) {
                x = random.nextInt(9);
                y = random.nextInt(9);
                if (sudoku.get(x, y) != 0) {
                    sudoku.set(x, y, 0);
                    capacity++;
                }

            }
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (sudoku.get(i, j) != 0) {
                        sudoku.getField(i, j).setEditable(false);
                    }
                }
            }
        }
    }


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        sudoku.solveGame();
        if (MenuController.getLevel().equals(ResourceBundle.getBundle("Lang")
                            .getString("easy"))) {
            dif = Difficulty.Easy;
        }
        if (MenuController.getLevel().equals(ResourceBundle.getBundle("Lang")
                .getString("normal"))) {
            dif = Difficulty.Normal;
        }
        if (MenuController.getLevel().equals(ResourceBundle.getBundle("Lang").getString("hard"))) {
            dif = Difficulty.Hard;
        }
        if (MenuController.getLevel().equals(ResourceBundle.getBundle("Lang").getString("data"))) {
            dif = Difficulty.Data;
        }

        if (logger.isInfoEnabled()) {
            if (dif == Difficulty.Easy) {
                logger.info(ResourceBundle.getBundle("Lang").getString("easy"));
            }
            if (dif == Difficulty.Normal) {
                logger.info(ResourceBundle.getBundle("Lang").getString("normal"));
            }
            if (dif == Difficulty.Hard) {
                logger.info(ResourceBundle.getBundle("Lang").getString("hard"));
            }
            if (dif == Difficulty.Data) {
                logger.info(ResourceBundle.getBundle("Lang").getString("data"));
            }

        }
        prepareBoard(dif);
  sudoku3 = cloneSudoku(sudoku3,sudoku);
  fillGrid();
    }

    @FXML
    public void pressButtonPowrot(ActionEvent ae)  {
           try {
               try {
                   loader.setResources(ResourceBundle.getBundle("Lang",
                           new Locale(MenuController.getLanguage())));
                   gamescreen = loader.load();
                   gameScene = new Scene(gamescreen, 600, 400);
                   Stage appStage = (Stage) ((Node) ae.getSource()).getScene().getWindow();
                   appStage.setScene(gameScene);
                   appStage.show();
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
    public void save() {
        try (Dao<SudokuBoard> emptyDao = SudokuBoardDaoFactory.getFileDao("sudokuEmpty");
            Dao<SudokuBoard> fullDao = SudokuBoardDaoFactory.getFileDao("sudokuFull");) {
            emptyDao.write(sudoku);
            fullDao.write(sudoku2);
            if (logger.isInfoEnabled()) {
                logger.info(ResourceBundle.getBundle("Lang").getString("save"));
            }
        } catch (DaoException  | CloseException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
    }


    @FXML
    public void read() {
        try (Dao<SudokuBoard> emptyDao = SudokuBoardDaoFactory.getFileDao("sudokuEmpty");
            Dao<SudokuBoard> fullDao = SudokuBoardDaoFactory.getFileDao("sudokuFull");) {
            sudoku = emptyDao.read();
            sudoku2 = fullDao.read();
            if (logger.isInfoEnabled()) {
                logger.info(ResourceBundle.getBundle("Lang").getString("read"));
            }
        } catch (DaoException | CloseException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
        fillGrid();
    }

    @FXML
    public void pressSaveBase() {
        String name = er.saveBaseBox(ResourceBundle.getBundle("Lang").getString("saveBaseName"),
                ResourceBundle.getBundle("Lang").getString("saveBaseMessage"),
                ResourceBundle.getBundle("Lang").getString("saveBaseTitle"));
        try {
            Dao<SudokuBoard> baseSudokuDao = SudokuBoardDaoFactory.getDatabaseDao(name);
            baseSudokuDao.write(sudoku);
        } catch (DaoException e) {
            if (name != "") {
                er.messageBoxWrongName(ResourceBundle.getBundle("Lang")
                                .getString("saveBaseWrongNameTitle"),
                        ResourceBundle.getBundle("Lang")
                                .getString("saveBaseWrongNameMessage"),
                        Alert.AlertType.INFORMATION);
            }
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
    }

    public SudokuBoard cloneSudoku(SudokuBoard s1,SudokuBoard s2) {
        try {
            try {
                s1 = s2.clone();
            } catch (CloneNotSupportedException e) {
                throw new CloneException(ResourceBundle.getBundle("sudoku.Lang")
                        .getString("cloneAlert"));
            }
        } catch (CloneException e) {
            if (logger.isErrorEnabled()) {
                logger.error(e.getMessage());
            }
        }
return s1;
    }

public void checkSudoku(ActionEvent ae) {
    if (logger.isInfoEnabled()) {
        logger.info(ResourceBundle.getBundle("Lang").getString("score"));
    }
    if (sudoku.getCheckBoard()) {
        er.messageBox(ResourceBundle.getBundle("Lang").getString("score"),
                ResourceBundle.getBundle("Lang").getString("win"),
                Alert.AlertType.INFORMATION);
        if (logger.isInfoEnabled()) {
            logger.info(ResourceBundle.getBundle("Lang").getString("win"));
        }
    } else {
        er.messageBox(ResourceBundle.getBundle("Lang").getString("score"),
                ResourceBundle.getBundle("Lang").getString("lose"),
                Alert.AlertType.INFORMATION);
        if (logger.isInfoEnabled()) {
            logger.info(ResourceBundle.getBundle("Lang").getString("lose"));
        }
    }
}

public void setNameBase(String name) {
        this.nameBase = name;
        if (nameBase != null) {
            try (Dao<SudokuBoard> baseSudokuDaoR = SudokuBoardDaoFactory
                    .getDatabaseDao(nameBase)) {

                sudoku = baseSudokuDaoR.read();
            } catch (DaoException | CloseException e) {
                if (logger.isErrorEnabled()) {
                    logger.error(e.getMessage());
                }
            }
        }
        sudoku3 = cloneSudoku(sudoku3,sudoku);
        fillGrid();
    }

}