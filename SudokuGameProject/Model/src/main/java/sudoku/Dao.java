package sudoku;


import sudoku.exceptions.CloseException;
import sudoku.exceptions.DaoException;



public interface Dao<T> extends AutoCloseable {

    T read() throws DaoException;

    void write(T object) throws DaoException;

    @Override
    void close() throws CloseException;
}
