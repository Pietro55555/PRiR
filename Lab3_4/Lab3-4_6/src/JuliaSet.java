import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class JuliaSet extends Thread
{
    final static int N = 4096;
    final static int STOP = 150;

    static int[][] tab = new int[N][N];
    int nr;
    double X, Y;

    public static void main(String[] args) throws IOException
    {
        JuliaSet[] julia=new JuliaSet[4];
        for(int i=0;i<4;i++)
        {
            julia[i]=new JuliaSet(i);
            julia[i].start();
        }

        try
        {
            for(int i=0;i<4;i++)
            {
                julia[i].join();
            }
        }
        catch (Exception e)
        {
        System.out.println(e);
        }

        BufferedImage img = new BufferedImage(N, N, BufferedImage.TYPE_INT_ARGB);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int k=tab[i][j];
                Color c=new Color((float)k/STOP,(float)k/STOP,0);
                img.setRGB(i,j,c.getRGB());
            }
        }
        ImageIO.write(img,"PNG",new File("JuliaFractal.png"));
    }


    public JuliaSet(int nr)
    {
        this.nr=nr;
        this.X=2.0/N;
        this.Y=2.0/N;
    }

    public void run()
    {
        int beg=0,end=0;
        if (nr==0)
        {
            beg=0;
            end=(N/4)*1;
        }
        else
            if(nr==1)
            {
            beg=(N/4)*1;
            end=(N/4)*2;
            }
        else
            if(nr==2)
            {
            beg=(N / 4)*2;
            end=(N / 4)*3;
            }
        else
            if(nr==3)
            {
            beg=(N/4)*3;
            end=(N/4)*4;
            }


        for (int i=beg;i<end;i++)
        {
            for (int j=0;j<this.N;j++)
            {
                double rzeczywista=(i*this.Y)-1.25;
                double urojona=(j*this.X)-1.25;

                int k = 0;

                Complex z0=new Complex(rzeczywista, urojona);
                Complex z1=new Complex(-0.039, 0.700);

                while(z0.mod()<2.0&&k<100)
                {
                    k++;
                    z0=z1.add(z0.pow2());
                }
                this.tab[i][j]=k;
            }
        }
    }

    public class Complex
    {
        private double rzeczywista;
        private double urojona;

        public Complex(double r, double i)
        {
            this.rzeczywista = r;
            this.urojona = i;
        }

        public double mod()
        {
            return Math.sqrt(rzeczywista * rzeczywista +urojona*urojona);
        }

        public Complex add(Complex in)
        {
            return new Complex(this.rzeczywista +in.rzeczywista,this.urojona+in.urojona);
        }

        public Complex pow2()
        {
            double r = (this.rzeczywista * this.rzeczywista) - (this.urojona * this.urojona);
            double i = (this.rzeczywista * this.urojona) + (this.urojona * this.rzeczywista);
            return new Complex(r,i);
        }
    }
}
