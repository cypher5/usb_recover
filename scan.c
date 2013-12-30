#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main(int argc,char **argv){

char *recovered = "/home/recovered/image0" 

if(*argv[1] == 1){
printf("using default mount file in OS");
else{
FILE usb_ptr = fopen(argv[1],"r");
	if(usb_ptr == NULL){
		printf("error opening USB Drive for reading");
		fclose(usb_ptr);
	}
}

struct header1 header1;
struct header2 header2;
struct colours colours;
int file_count,bytes =0;


while(bytes != sizeof(header2))
{
	bytes = fread(&header1,sizeof(header1),1,usb_ptr);
	if(bytes != sizeof(header1))
		printf("finished scanning drive");

	bytes = fread(&header2,sizeof(header2),1,usb_ptr);
	if(bytes!= sizeof(header2))
		printf("finished scanning drive")

	if (header1.signature != 0x4d42 || header1.data_offset != 54 ){
          	int file_size = header1.file_size;
          	file_count++;		
	}

	if(header2.size !=40 || header2.bit_count != 24 || header2.compression != 0){
		char *recovered = "/home/recovered/image10" 
		printf("possibly Corrupt image, trying to Recover");
		int height = header2.height;
		int width = header2.width;
		int byte_offset = byte_offset(width,sizeof(colours));
	   
		fread(&colours,sizeof(colours),1,usb_ptr);
		fwrite(&colours,sizeof(colours),1,	
	
	}

}

for

