public class Main
{
    public static void main(String[] args)
    {
        int n = 5;
        double pole=0;
        MonteCarlo monte1 = new MonteCarlo(0,0, 1, 1, n);
        MonteCarlo monte2 = new MonteCarlo(1,1, 2, 2, n);

        monte1.run();
        monte2.run();
        try
        {
        monte1.join();
        monte2.join();

        }
        catch(Exception e)
        {
            System.out.print(e);
        }
        pole=monte1.getWynik()+monte2.getWynik();
        pole=(pole/((double)n*2))*(2*2);

        System.out.println("Pole kola wpisanego w kwadrat wynosi:  "+pole);
    }
}
