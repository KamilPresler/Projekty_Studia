package sudokuviewer;

public enum Difficulty {

    Easy(1),
    Normal(20),
    Hard(30),
    Data(81);

    private int empty;

    Difficulty(int empty) {
        this.empty = empty;
    }

    public int getEmpty() {
        return empty;
    }

}
