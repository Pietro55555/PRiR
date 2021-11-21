public class MonteCarlo extends Thread
{
    double x1, x0, y1, y0;
    int n;
    double wynik = 0;

    public MonteCarlo(double x1, double x0, double y1, double y0, int n)
    {
        this.x1 = x1;
        this.x0 = x0;
        this.y1 = y1;
        this.y0 = y0;
        this.n = n;
    }

    @Override
    public void run()
    {
        int wewn = 0;
        for (int i = 0; i < this.n; i++)
        {
            double x = Math.random();
            double y = Math.random();

            if (x * x + y * y <= 1) wewn++;
        }
        this.wynik = wewn;
    }
    public double getWynik()
    {
        return this.wynik;
    }
}
