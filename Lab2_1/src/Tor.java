public class Tor
{
    static int TOR=1;
    static int WJAZD=2;
    static int JAZDA=3;
    static int WYJAZD=4;
    static int WYPADEK=5;

    int ilosc_miejsc;
    int ilosc_zajetych;
    int ilosc_gokartow;
    Tor(int ilosc_miejsc,int ilosc_gokartow)
    {
        this.ilosc_miejsc=ilosc_miejsc;
        this.ilosc_gokartow=ilosc_gokartow;
        this.ilosc_zajetych=0;
    }
    synchronized int start(int numer)
    {
        ilosc_zajetych--;
        System.out.println("Gokart nr "+numer + "może wjechać bezpiecznie na tor");
        return WJAZD;
    }
    synchronized int  wyjazd()
    {
        try
        {
            Thread.currentThread().sleep(2000);
        }
        catch(Exception e)
        {}
        if(ilosc_zajetych<ilosc_miejsc)
        {
            ilosc_zajetych++;
            System.out.println("Prosze wyjechać torem nr "+ilosc_zajetych);
            return TOR;
        }
        else
        {
            return WYJAZD;
        }

    }
    synchronized void zmniejsz()
    {
        ilosc_gokartow--;
        System.out.println("Wypadek");
        if(ilosc_gokartow==ilosc_miejsc) System.out.println("Wszystkie miejsca sa zajete");
    }

}