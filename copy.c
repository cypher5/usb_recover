#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include <math.h>


int main(int argc, char **argv)
{
    if (argc != 3) {
        p("usage: ./copy orginal duplicate\n");
        return 1;
    }
    
    char *original = argv[1];
    char *duplicate = argv[2];

    //takes pointers to the file path and what to do with it all pointers//
    FILE *original_ptr = fopen(original,"r");
    if (original == NULL) {
        printf("error opening original file");
    return 2;
    }
    
    FILE *duplicate_ptr = fopen(duplicate,"w");
    if (duplicate_ptr== NULL) {
        printf("error opening duplicate file");
        fclose(original_ptr);
	return 3;
    }
    
    struct header1 header1;
    struct header2 header2;
    
    fread(&header1,sizeof(header1),1,original_ptr);
    fwrite(&header1,sizeof(header1),1,duplicate_ptr);
     fread(&header2,sizeof(header2),1,original_ptr);
    fwrite(&header2,sizeof(header2),1,duplicate_ptr);


    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
//reading from memory is little endian, since we are reading an int, so its M first then the B.
    if (header1.signature != 0x4d42 || header1.data_offset != 54 || header2.size != 40 ||
        header2.bit_count != 24 || header2.compression != 0){
        fclose(original_ptr);
        fclose(duplicate_ptr);
        printf("unsupported File Format");
        //fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    struct colours colours;  
    int byte_offset =  (4 - (header2.width * sizeof(colours)) % 4) % 4;

        printf("%d",byte_offset);
        int width,height;
	height = abs(header2.height);
	width = header2.width;   
	   

     for(int j=0;j<height;j++)
{
	for(int i=0;i<width;i++)
	{
	fread(&colours,sizeof(colours),1,original_ptr);
	fwrite(&colours,sizeof(colours),1,duplicate_ptr);
        
   		for (int k = 0; k < byte_offset; k++)
           		fputc(0x00, duplicate_ptr);
	fseek(original_ptr,byte_offset,SEEK_CUR);
	}

}
fclose(original_ptr);
fclose(duplicate_ptr);

return 0;
}
