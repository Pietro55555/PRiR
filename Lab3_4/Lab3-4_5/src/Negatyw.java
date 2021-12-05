import java.awt.*;
import java.awt.image.BufferedImage;

public class Negatyw extends Thread
{
    BufferedImage picture;
    int xStart, yStart, xStop, yStop;

    public Negatyw(BufferedImage picture, int xStart, int xStop, int yStart, int yStop)
    {
        this.picture = picture;
        this.xStart = xStart;
        this.xStop = xStop;
        this.yStart = yStart;
        this.yStop = yStop;
    }

    @Override
    public void run()
    {
        for(int i = xStart; i < xStop; i++)
        {
            for(int j = yStart; j < yStop; j++)
            {
                Color c = new Color(picture.getRGB(i, j));
                int r=c.getRed();
                int g=c.getGreen();
                int b=c.getBlue();
                int R = 255 - r;
                int G = 255 - g;
                int B = 255 - b;
                Color newColor = new Color(R, G, B);
                picture.setRGB(i, j, newColor.getRGB());
            }
        }
    }

}
