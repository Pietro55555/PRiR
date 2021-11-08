public class M_Simpsona extends Thread
{
    double h, calka;

    M_Simpsona(double a, double b, int n)
    {
        double x[] = new double[2 * n + 1];
        h = (b - a) / (2 * n);
        x[0] = a;
        x[2 * n] = b;
        calka = 0;
        calka += funkcja(x[0]);
        calka += funkcja(x[2 * n]);

        for (int i = 1; i < 2 * n; i++)
        {
            x[i] = x[i - 1] + h;
        }
        for (int i = 1; i < 2 * n; i++)
        {
            if ((i % 2) != 0)
            {
                calka += 4 * funkcja(x[i]);
            } else if ((i % 2) == 0)
            {
                calka += 2 * funkcja(x[i]);
            }
        }
        calka = h / 3 * calka;
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
