package sudoku;

import java.io.Serializable;
import java.util.ListResourceBundle;

public class Lang_en extends ListResourceBundle implements Serializable {

    @Override
    protected Object[][] getContents() {
        return new Object[][]{
                {"readAlert", "File read error"},
                {"writeAlert", "File write error"},
                {"closeAlert", "File close error: A file that does not exist cannot be closed"},
                {"cloneAlert", "Clone error"},
                {"wrongValueAlert", "Value error"},
                {"methodAlert", "Method does not exist"},
                {"connectionAlert", "Database connection error"},
                {"createTableAlert", "Table creation error "},
                {"rollbackAlert", "Rollback transaction error "},
                {"insertAlert", "Adding data to the database error "},
                {"raedDatabaseAlert", "Loading data from the database error  "},
                {"classNotFoundAlert", "Class not found "},
                {"selectAlert", "Getting data from the database error"}
        };
    }
}
