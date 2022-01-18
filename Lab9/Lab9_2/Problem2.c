%%cu
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	clock_t start, stop; 
	start=clock();
	FILE* fp = fopen("sample.bmp", "rb");  

	unsigned char *imageData; 
	unsigned char *newimageData; 
        unsigned char imageHeader[54];
        unsigned char colorTable[1024];

	int i,j; 

	fread(imageHeader, sizeof(unsigned char), 54, fp);
	      
	  
	      
        int width = *(int*)&imageHeader[18];
        int height = *(int*)&imageHeader[22];
	int bitDepth = *(int*)&imageHeader[28];

        int imgDataSize = width * height; 

        imageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char)); 
        newimageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char));
	
	if(bitDepth <= 8)	
		fread(colorTable, sizeof(unsigned char), 1024, fp); 
		
	
	fread( imageData, sizeof(unsigned char), imgDataSize, fp);
	   
		
	
 int ii;
 for(ii=0;ii<10;ii++)
 { 
		for(i = 1; i <= height; i++)
	{
					for(j = 1; j <= width; j++)
				{                   
					newimageData[i*width + j] = (i/10+ii) - imageData[i*width + j]; 
					newimageData[i*width + j] = (j/10+ii) - imageData[i*width + j]; 
		  	}   
		}
  }

	FILE *fo = fopen("sample_jasniej.bmp", "wb");

        fwrite(imageHeader, sizeof(unsigned char), 54, fo); 

	if(bitDepth <= 8)	// COLOR TABLE Present
        	fwrite(colorTable, sizeof(unsigned char), 1024, fo); 
	
        fwrite( newimageData, sizeof(unsigned char), imgDataSize, fo); 

        fclose(fo);
	fclose(fp);
        stop = clock(); 
	double d = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;                                                   
        printf("%lf\n",d);

}
