public class M_prostokatow extends Thread
{
    double dx, calka;

    M_prostokatow(double a, double b, int n)
    {
        calka = 0;
        dx = (b - a) / (double)n;
        for (int i=1; i<=n; i++)
        {
            calka += funkcja(a + i * dx);
        }
        calka *= dx;
    }

    private static double funkcja(double x)
    {
        return Math.pow((Math.pow(x,2)+2),3);
    }

    public double getCalka()
    {
        return calka;
    }
}
