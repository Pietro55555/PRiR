import java.util.ArrayList;
import java.util.Scanner;

public class main
{
    public static void main(String[] args)
    {
        double a, b;
        int n;
        double calka = 0;

        Scanner sc = new Scanner(System.in);
        System.out.print("Podaj a: ");
        a = sc.nextDouble();

        System.out.print("Podaj b: ");
        b = sc.nextDouble();

        System.out.print("Podaj n: ");
        n = sc.nextInt();

        double odcinek = (b - a) / (double)n;

        ArrayList<M_prostokatow> calkaP = new ArrayList<>();

        for (double i = a; i < b - odcinek; i += odcinek)
        {
            M_prostokatow t = new M_prostokatow(i, i+odcinek, n);
            calkaP.add(t);
            t.start();
        }

        try
        {
            for(M_prostokatow t : calkaP)
            {
                t.join();
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        for(M_prostokatow t : calkaP)
        {
            calka += t.getCalka();
        }

        System.out.println("###Metoda Prostokątów###\nWynik: " + calka);


        calka = 0;
        ArrayList<M_trapezow> calkaT = new ArrayList<>();

        for (double i = a; i < b - odcinek; i += odcinek)
        {
            M_trapezow t = new M_trapezow(i, i+odcinek, n);
            calkaT.add(t);
            t.start();
        }

        try
        {
            for(M_trapezow t : calkaT)
            {
                t.join();
            }
        }catch(Exception e)
        {
            e.printStackTrace();
        }
        for(M_trapezow t : calkaT)
        {
            calka += t.getCalka();
        }

        System.out.println("###Metoda Trapezów###\nWynik: " + calka);



        calka = 0;
        ArrayList<M_Simpsona> calkaS = new ArrayList<>();

        for (double i = a; i < b - odcinek; i += odcinek)
        {
            M_Simpsona t = new M_Simpsona(i, i+odcinek, n);
            calkaS.add(t);
            t.start();
        }

        try {
            for(M_Simpsona t : calkaS)
            {
                t.join();
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        for(M_Simpsona t : calkaS)
        {
            calka += t.getCalka();
        }
        System.out.println("###Metoda Simpsona###\nWynik: " + calka);

    }
}
