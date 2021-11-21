import java.util.Random;

public class Samochod extends Thread {
    private String nrRej;
    private int pojZbiornika;
    private int paliwo;
    private boolean dziala=false;

    public Samochod(String nr, int _pojZbiornika)
    {
        nrRej = nr;
        pojZbiornika = _pojZbiornika;
        paliwo=_pojZbiornika;
    }

    public void tankowanie(int _paliwo)
    {
        if( this.pojZbiornika+ this.paliwo > this.pojZbiornika)
        {
            this.paliwo=this.pojZbiornika;
        }
        else
            this.paliwo += _paliwo;
    }
    @Override
    public void start() //start samochodu, uruchamiamy wątek zużycia paliwa
    {
        System.out.println("Malucz z numerami "+this.nrRej+" ruszył w świat");
        this.dziala=true;
        super.start();
    }

    public void stopp() //zatrzymanie samochodu, zatrzymujemy wątek zużycia paliwa
    {
        System.out.println("Maluch o numerach "+this.nrRej+" stoi");
        this.dziala=false;
    }
    @Override
    public void run() //kod, który wykonuje się w odrębnym wątku, co 1 s programu zużywany jest 1 litr paliwa
    {
            while(dziala)
            {
                Random rand= new Random();
                if(paliwo <= 0 || paliwo >this.pojZbiornika)
                {
                    System.out.println("Maluch o numerach "+nrRej+" nie może dalej kontynuować jazdy");
                    this.dziala=false;
                }
                else
                {
                    System.out.println("Dla malucha o numerach "+this.nrRej+" Zostało " + this.paliwo + "l");
                    this.paliwo-=rand.nextInt(5)+1;
                    try {
                        sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                    if (this.paliwo >= 1 && this.paliwo <= 3)
                    {
                        this.tankowanie(rand.nextInt(12)+1);
                    }
                }
            }
    }
}
