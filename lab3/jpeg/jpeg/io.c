#include "coder.h"

// input+ref-output data in const array to have a self-testing-application

BYTE RGB_buffer[]={
#include "input.data"
};
#define RGB_width   256
#define RGB_height  160
unsigned char ref_out[]={
#include "refout.data"
};
unsigned char output[8192];
unsigned char* pOut = output;

void writebyte(BYTE b)
{
  *pOut++ = b;
}   
void writeword(WORD w)
{
    *pOut++ = w>>8;
    *pOut++ = w/*&0xff*/;
}
void writearray(void* p, int n)
{
  char* pw = (char*)p;
  for (int i=0; i<n; i++) {
    writebyte(pw[i]);
  }
}

void init_input(struct image* img)
{
    img->RGB_buffer = (colorRGB *)RGB_buffer;
    img->width  = RGB_width;
    img->height = RGB_height;
} 
void fini_input(struct image * img)
{
    //img = img;
}
 
void init_output()
{
    pOut = output;
}

#include <stdio.h>
int fini_output()
{ 
  int n = sizeof(ref_out);
  int error=0;
  for (int i=0; i<n; i++) {
    if (output[i] != ref_out[i]) {
      //printf("error [%d] ok=%d got=%d\n", i, ref_out[i], output[i]);
      error++;
    }
  }
  if (error==0) {
    printf("OK -- Similar results between golden and generated images (nr=%d)\n",n);
  }
  else {
    printf("ERROR (nr=%d)\n",error);
  }
  return error;
}
