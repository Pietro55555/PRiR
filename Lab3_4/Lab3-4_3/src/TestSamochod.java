import java.util.Random;

public class TestSamochod
{
    public static void main(String[] args)
    {
        int ilosc_samochodow=5;
        Random rand =new Random();
        for(int i=1;i<=ilosc_samochodow;i++)
        {
            Samochod s=new Samochod("BIA"+i,21);
            s.start();
        }
    }
}
