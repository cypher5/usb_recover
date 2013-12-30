#include <stdint.h>

struct header1
{
    uint16_t signature;
    uint32_t file_size;
    uint32_t reserved;
    uint32_t data_offset;
    
}__attribute__((__packed__)) ;

struct header2
{
    uint32_t size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t image_size;
    uint32_t x_pixels_per_m;
    uint32_t y_pixles_per_m;
    uint32_t colours_used;
    uint32_t colours_important;
}__attribute__((__packed__)) ;

//24bits of colour information, 8 bits per R,G,B
struct colours
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}__attribute__((__packed__)) ;

int byte_offset(int width, size_t colours)
{
 int byte_offset =  (4 - (header2.width * colours) % 4) % 4;
 return byte_offset;
}

