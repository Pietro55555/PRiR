public class Main
{
    static int ilosc_gokartow=27;
    static int ilosc_miejsc=5;
    static Tor t;

    public static void main(String[] args)
    {
        t=new Tor(ilosc_miejsc, ilosc_gokartow);
        for(int i=0;i<ilosc_gokartow;i++)
            new Gokart(i,300,t).start();
    }
}
