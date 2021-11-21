import static java.lang.Thread.sleep;

public class Czasomierz
{
    private int sek = 0;
    private int min = 0;
    private int godz = 0;

    public Czasomierz()
    {
        this.sek = sek;
        this.min = min;
        this.godz = godz;
    }

    public void start()
    {
        while(true)
        {
            sek++;
            if(sek == 60)
            {
                sek=0;
                min++;
                if(min == 60)
                {
                    min=0;
                    godz++;
                }
            }
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println(godz+" : "+min+" : "+sek);
        }
    }

}
