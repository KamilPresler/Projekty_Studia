package sudokuviewer;

import java.util.ListResourceBundle;

public class AuthorsBundle extends ListResourceBundle {

    private final Object[][] resources = {
            {"autor_1", "Urszula Frączek"}, {"autor_2", "Kamil Presler"}
    };

    @Override
    protected Object[][] getContents() {
        return resources;
    }
}
