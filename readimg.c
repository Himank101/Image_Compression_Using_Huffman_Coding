// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	FILE *fp;
// 	fp=fopen("intense.txt","w");
// 	char filename[] = "5by5.bmp";
// 	int i,j,data,offset,hbytes,width,height;
// 	long bmpsize=0,bmpdataoff=0,bpp=0;
// 	int **image;
// 	int temp=0;
// 	FILE *image_file;
// 	image_file = fopen(filename,"rb");
// 	if(image_file==NULL)
// 	{
// 		printf("Error Opening File!!");
// 		exit(1);
// 	}
// 	else
// 	{
// 		//Set file position of the stream to the beginning
// 		printf("Processing BMP Header...\n\n");
// 		offset = 0;
// 		fseek(image_file,offset,SEEK_SET);
// 		printf("Getting file ID...\n\n");
// 		for(i=0;i<2;i++)
// 		{
// 			fread(&data,1,1,image_file);
// 			printf("%c",data);
// 		}
// 		printf("\n\nGetting size of BMP File...\n\n");
// 		fread(&bmpsize,4,1,image_file);
// 		printf("Size of the BMP File:: %ld bytes\n\n",bmpsize);
// 		printf("Getting offset where the pixel arrray starts...\n\n");
// 		offset = 10;
// 		fseek(image_file,offset,SEEK_SET);
// 		fread(&bmpdataoff,4,1,image_file);
// 		printf("Bitmap data offset:: %ld\n\n",bmpdataoff);
// 		printf("DIB Header\n\n");
// 		fread(&hbytes,4,1,image_file);
// 		printf("Number of bytes in header:: %d\n\n",hbytes);
// 		fread(&width,4,1,image_file);
// 		fread(&height,4,1,image_file);
// 		printf("Width of Image: %d\n",width);
// 		printf("Height of image: %d\n\n",height);
// 		fseek(image_file,2,SEEK_CUR);
// 		fread(&bpp,2,1,image_file);
// 		printf("Number of bits per pixel: %ld\n\n",bpp);
// 		printf("Setting offset to start of pixel data...\n\n");
// 		fseek(image_file,bmpdataoff,SEEK_SET);
// 		printf("Creating Image array...\n\n");
// 		int **image = (int **)malloc(height*sizeof(int *));
// 		for(i=0;i<height;i++)
// 		{
// 			image[i] = (int *)malloc(width*sizeof(int));
// 		}
// 		int numbytes = (bmpsize - bmpdataoff)/3;
// 		printf("Number of bytes: %d \n\n",numbytes);
// 		int r,c;
// 		printf("Reading the BMP File into Image Array...\n\n");
// 		for(r=0;r<height;r++)
// 		{
// 			for(c=0;c<width;c++)
// 			{	int t;
// 				fread(&temp,3,1,image_file);
// 				temp = temp&0x0000FF;
// 				image[r][c] = temp;
// 			}
// 		}
// 		int hist[256];
  
// 		for (i = 0; i < 256; i++){
//     		hist[i] = 0;
// 		}
// 		for (i = 0; i < height; i++){
// 			for (j = 0; j < width; j++){
// 				hist[image[i][j]] += 1;
// 			}
// 		}
// 		for (i = 0; i < 256; i++){
//     		printf("%d %d\n", hist[i], i);
// 		}
// 		// for (i = 0; i < height; i++){
// 		// 	for (j = 0; j < width; j++){
// 		// 		// hist[image[i][j]] += 1;
// 		// 		printf("%d",image[i][j]);
	
// 		// 	}
// 		// }

// 		printf("Reading the BMP File into Image Array Completed...\n\n");
// 	}

// 	fclose(image_file);
// 	return EXIT_SUCCESS;
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char filename[] = "_DSC0082 (2).bmp";
	int i,j,data,offset,hbytes,width,height;
	long bmpsize=0,bmpdataoff=0,bpp=0;
	int **image;
	int temp=0;
	FILE *image_file;
	image_file = fopen(filename,"rb");
	if(image_file==NULL)
	{
		printf("Error Opening File!!");
		exit(1);
	}
	else
	{
		//Set file position of the stream to the beginning
		printf("Processing BMP Header...\n\n");
		offset = 0;
		fseek(image_file,offset,SEEK_SET);
		printf("Getting file ID...\n\n");
		for(i=0;i<2;i++)
		{
			fread(&data,1,1,image_file);
			printf("%c",data);
		}
		printf("\n\nGetting size of BMP File...\n\n");
		fread(&bmpsize,4,1,image_file);
		printf("Size of the BMP File:: %ld bytes\n\n",bmpsize);
		printf("Getting offset where the pixel arrray starts...\n\n");
		offset = 10;
		fseek(image_file,offset,SEEK_SET);
		fread(&bmpdataoff,4,1,image_file);
		printf("Bitmap data offset:: %ld\n\n",bmpdataoff);
		printf("DIB Header\n\n");
		fread(&hbytes,4,1,image_file);
		printf("Number of bytes in header:: %d\n\n",hbytes);
		fread(&width,4,1,image_file);
		fread(&height,4,1,image_file);
		printf("Width of Image: %d\n",width);
		printf("Height of image: %d\n\n",height);
		fseek(image_file,2,SEEK_CUR);
		fread(&bpp,2,1,image_file);
		printf("Number of bits per pixel: %ld\n\n",bpp);
		printf("Setting offset to start of pixel data...\n\n");
		fseek(image_file,bmpdataoff,SEEK_SET);
		printf("Creating Image array...\n\n");
		int *image = (int *)malloc(height*sizeof(int *));
		for(i=0;i<height;i++)
		{
			image[i] = (int *)malloc(width*sizeof(int));
		}
		int numbytes = (bmpsize - bmpdataoff)/3;
		printf("Number of bytes: %d \n\n",numbytes);
		int r,c;
		printf("Reading the BMP File into Image Array...\n\n");
		for(r=0;r<height;r++)
		{
			for(c=0;c<width;c++)
			{
				fread(&temp,3,1,image_file);
				temp = temp&0x0000FF;
				image[r][c] = temp;
				printf("%d ",image[r][c]);
			}
			printf("\n");
		}
		printf("Reading the BMP File into Image Array Completed...\n\n");
		
		

		int intensity[256];
		int freq[256];
		
		for(int i=0;i<256;i++)
		{	int count=0;
			intensity[i]=i;
			for(int j=0;j<256;j++)
			{
				if(intensity[i]==image[r][c])
					count++;
			}
			freq[i]=count;
		}

	}

	
	
	fclose(image_file);
	return EXIT_SUCCESS;
}
