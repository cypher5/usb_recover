#include <stdio.h>




int main(int argc, char **argv)
{
    if (argc != 3) {
        print("usage: ./copy orginal duplicate\n");
        return 1;
    }
    
    char *original = argv[1];
    char *duplicate = argv[2];
    
    FILE *original_ptr = fopen(original,r);
    if (original == NULL) {
        printf("error opening original file");
    }
    
    FILE *duplicate_ptr = fopen(duplicate,w);
    if (duplicate_ptr== NULL) {
        printf("error opening duplicate file");
        fclose(original_ptr);
    }
    
    struct header1 header1;
    struct header2 header2;
    
    fread(&header1,sizeof(header1),1,original_ptr);
    fwrite(&header1,sizeof(header1),1,duplicate_ptr);
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    fread(&header2,sizeof(header2),1,original_ptr);
    fwrite(&header2),sizeof(header2),1,duplicate_ptr);
    
    
    
    
    
    
    
    
    
    
    
}