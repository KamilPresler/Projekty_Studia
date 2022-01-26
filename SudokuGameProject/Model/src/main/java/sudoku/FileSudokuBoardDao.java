package sudoku;


import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ResourceBundle;
import sudoku.exceptions.CloseException;
import sudoku.exceptions.ReadException;
import sudoku.exceptions.WriteException;


public class FileSudokuBoardDao implements Dao<SudokuBoard>  {
private String filename;

    public FileSudokuBoardDao(String filename) {
        this.filename = filename + ".txt";
    }


    @Override
    public SudokuBoard read() throws ReadException {
        SudokuBoard sudoku = null;
        try {
            try (FileInputStream filein = new FileInputStream(filename);
                 ObjectInputStream object = new ObjectInputStream(filein)) {
                sudoku = (SudokuBoard) object.readObject();
            } catch (ClassNotFoundException | IOException e) {
                StringBuilder s1 = new StringBuilder();
                s1.append(ResourceBundle.getBundle("sudoku.Lang").getString("readAlert"));
                s1.append(" ");
                s1.append(e.getLocalizedMessage());
                throw new ReadException(s1.toString(), e);
            }
        } catch (ReadException e) {
           throw e;
        }
        return sudoku;
    }


    @Override
    public void write(SudokuBoard object) throws WriteException {
        try {
            try (FileOutputStream fileout = new FileOutputStream(filename);
                 ObjectOutputStream obj = new ObjectOutputStream(fileout)) {
                obj.writeObject(object);
            } catch (IOException e) {
                StringBuilder s1 = new StringBuilder();
                s1.append(ResourceBundle.getBundle("sudoku.Lang").getString("writeAlert"));
                s1.append(" ");
                s1.append(e.getMessage());
                throw new WriteException(s1.toString(), e);
            }
        } catch (WriteException e) {
            throw e;
        }
    }

    @Override
    public void close() throws CloseException {
        File file = new File(this.filename);
        if (file == null) {
            try {
                throw new CloseException(ResourceBundle.getBundle("sudoku.Lang")
                        .getString("closeAlert"));
            } catch (CloseException e) {
                throw e;
            }
        }

    }
}
