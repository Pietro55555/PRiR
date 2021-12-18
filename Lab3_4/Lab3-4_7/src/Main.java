import com.intellij.openapi.editor.actions.DeleteSelectionHandler;

import java.util.Scanner;

public class Main
{
    public static void main ( String [] args )
    {

        Scanner sc = new Scanner(System.in);
        int liczbaFilozofow = 0;

        while( liczbaFilozofow < 2 || liczbaFilozofow > 100 )
        {
            System.out.println("Podaj liczbe filozofów od 2 do 100: ");
            liczbaFilozofow = sc.nextInt();
        }

            System.out.print("1.Pierwszy sposób\n2.Drugi sposób\n3.Trzeci sposób)\nPodaj numer wariantu: ");
            int wybor = sc.nextInt();

            if (wybor == 1)
            {
                for (int i = 0; i < liczbaFilozofow; i++)
                    new Wariant1(i, liczbaFilozofow).start();
            }
            else if (wybor == 2)
            {
                for (int i = 0; i < liczbaFilozofow; i++)
                    new Wariant2(i, liczbaFilozofow).start();
            }
            else if (wybor == 3)
            {

                for (int i = 0; i < liczbaFilozofow; i++)
                    new Wariant3(i, liczbaFilozofow).start();
            }
            else
                System.out.print("");


    }
}
