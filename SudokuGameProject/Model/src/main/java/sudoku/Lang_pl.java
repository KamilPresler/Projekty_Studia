package sudoku;

import java.io.Serializable;
import java.util.ListResourceBundle;

public class Lang_pl extends ListResourceBundle implements Serializable {

    @Override
    protected Object[][] getContents() {
        return new Object[][] {
                {"readAlert", "Błąd wczytania pliku"},
                {"writeAlert", "Błąd zapisania pliku"},
                {"closeAlert",
                        "Błąd zamknięcia pliku: Nie można zamknąć pliku, który nie istnieje"},
                {"cloneAlert", "Błąd klnowania"},
                {"wrongValueAlert", "Podano nieprawidłowy znak"},
                {"methodAlert", "Nie ma takiej metody"},
                {"connectionAlert", "Błąd połączenia z bazą danych "},
                {"createTableAlert", "Błąd tworzenia tabel "},
                {"rollbackAlert", "Błąd cofania transakcji "},
                {"insertAlert", "Błąd dodawania danych do bazy  "},
                {"raedDatabaseAlert", "Błąd wczyatnia danych z bazy  "},
                {"classNotFoundAlert", "Nie znalezniono klasy "},
                {"selectAlert", "Błąd pobrania danych z bazy"}
        };
    }
}
