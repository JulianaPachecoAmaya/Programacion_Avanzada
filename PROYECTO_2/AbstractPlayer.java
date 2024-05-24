public abstract class AbstractPlayer implements PlayerInterface {
    protected String name;
    protected char disc;

    public AbstractPlayer(String name, char disc) {
        this.name = name;
        this.disc = disc;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public char getDisc() {
        return disc;
    }

    @Override
    public abstract int makeMove(Board board);
}
