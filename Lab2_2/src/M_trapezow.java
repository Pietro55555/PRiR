public class M_trapezow extends Thread
{
    double h, calka;

    M_trapezow(double a, double b, int n)
    {
        calka = 0;
        double xi[]= new double[n+1];
        h = (b-a)/n;
        xi[0] = a;
        xi[n] = b;

        for(int i=1;i<n;i++)
        {
            xi[i] = a + i*h;
        }
        for(int i=0;i<n;i++)
        {
            calka += funkcja(xi[i]) + funkcja(xi[i+1]);
        }
        calka = h/2 * calka;
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
