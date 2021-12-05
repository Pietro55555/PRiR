import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedImage picture;
        File inputJPG = new File("mona.jpg");
        picture = ImageIO.read(inputJPG);
        int width = picture.getWidth();
        int height = picture.getHeight();


        Negatyw n1 = new Negatyw(picture, 0, width/2, 0, height/2);
        Negatyw n2 = new Negatyw(picture, width/2, width, 0, height/2);
        Negatyw n3 = new Negatyw(picture, 0, width/2,height/2, height);
        Negatyw n4 = new Negatyw(picture, width/2, width,height/2 , height);

        n1.start();
        n2.start();
        n3.start();
        n4.start();

        try
        {
            n1.join();
            n2.join();
            n3.join();
            n4.join();
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        File outputJPG = new File("pictureNeg.jpg");
        ImageIO.write(picture, "jpg", outputJPG);

    }
}
