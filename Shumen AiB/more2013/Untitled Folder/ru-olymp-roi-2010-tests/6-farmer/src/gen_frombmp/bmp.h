#ifndef _BMP
#define _BMP

#include <vector>

using namespace std;

typedef struct {
  char id1;
  char id2;
  char tmp1, tmp2;
  unsigned int file_size;
  unsigned int reserved;
  unsigned int bmp_data_offset;
  unsigned int bmp_header_size;
  unsigned int width;
  unsigned int height;
  unsigned short int planes;
  unsigned short int bits_per_pixel;
  unsigned int compression;
  unsigned int bmp_data_size;
  unsigned int h_resolution;
  unsigned int v_resolution;
  unsigned int colors;
  unsigned int important_colors;
} bmp_header;

/*
 *  Opens a 24 bit true color bmp file and strips its header and its data.
 *  The data starts at location "data", its grouped into 3 layers of "size"
 *  floats of size and they represent the colors blue, green and red.
 */

void bmpRead(char *str, bmp_header *header, vector<vector<int> > &data)
{

    FILE *bmp_file;
    unsigned long int size, i, j, rd;
    unsigned char *ptr;

    /* Open bmp file and read header */
    bmp_file=fopen(str,"rb");

    if (bmp_file == NULL)
    {
        printf("File \"%s\" couldn't be opened.\n\n", str);
        exit(EXIT_FAILURE);
    }

    i = fread(header,56,1,bmp_file);

    /* Make header fit into struct */
    for (i = 0; i < 51; i++)
    {
        ptr = (unsigned char*)(header) + (55 - i);
        *ptr= *(ptr - 2);
    }

    /* Check color depth */
    if ((*header).bits_per_pixel != 24)
    {
        printf("Sorry, but can handle only 24-bit true color mode pictures.\n\n");
        exit(EXIT_FAILURE);
    }

    size = (*header).width*(*header).height;

    fseek(bmp_file, 54, SEEK_SET);

    /* Read pixel data into color layers */
    rd = 0;
    //cerr << "Width = " << header->width << " Height = " << header->height << "\n";
    data.resize(header->height);
    for (i = 0; i < header->height; i++)
    {
    	data[header->height - 1 - i].resize(header->width);
		for (j = 0; j < header->width; j++)
		{
			int a1 = (unsigned char)fgetc (bmp_file);
	  	    int a2 = (unsigned char)fgetc (bmp_file);
  		    int a3 = (unsigned char)fgetc (bmp_file);
  		    data[header->height - 1 - i][j] = a1 + (a2 << 8) + (a3 << 16);
  		    rd += 3;
  		}
  		while ((rd & 3) != 0)
  		{
  			fgetc(bmp_file);
  			rd++;
  		}
    }

    fclose(bmp_file);
}

#endif
