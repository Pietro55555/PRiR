import java.util.Random;

import static java.lang.Thread.sleep;

public class Gokart extends Thread
{
    static int TOR=1;
    static int WJAZD=2;
    static int JAZDA=3;
    static int WYJAZD=4;
    static int WYPADEK=5;
    static int TANKUJ=300;
    static int REZERWA=100;

    int numer;
    int paliwo;
    int stan;
    Tor l;
    Random rand;
    public Gokart(int numer, int paliwo, Tor l)
    {
        this.numer=numer;
        this.paliwo=paliwo;
        this.stan=JAZDA;
        this.l=l;
        rand=new Random();
    }

    public void run()
    {
        while(true)
        {
            if(stan==TOR)
            {
                if(rand.nextInt(2)==1){
                    stan=WJAZD;
                    paliwo=TANKUJ;
                    System.out.println("Prosze o wjazd na tor gokart z numerem "+numer);
                    stan=l.start(numer);
                }
                else
                {
                    System.out.println("Prosze jeszcze nie wjezdzac "+numer );
                }
            }
            else if(stan==WJAZD)
            {
                System.out.println("Na tor wjechal gokart nr "+numer);
                stan=JAZDA;
            }
            else if(stan==JAZDA)
            {
                paliwo-=rand.nextInt(40);
                if(paliwo<=REZERWA)
                {
                    stan=WYJAZD;
                }
                else try
                {
                    sleep(rand.nextInt(60));
                }
                catch (Exception e)
                {}
            }
            else if(stan==WYJAZD)
            {
                System.out.println("Konczy mi się paliwo więc gokart nr "+numer+" opuszcza tor z ilosc paliwa na poziomie: "+paliwo);
                stan=l.wyjazd();
                if(stan==WYJAZD)
                {
                    paliwo-=rand.nextInt(40);
                    System.out.println("REZERWA "+paliwo);
                    if(paliwo<=0)
                        stan=WYPADEK;
                }
            }
            else if(stan==WYPADEK)
            {
                System.out.println("Gokart o numerze "+numer+" miał wypadek i nie może dalej jechać");
                l.zmniejsz();
            }
        }
    }

}
