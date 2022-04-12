#include <stdio.h>
void main() {
  FILE * out;
  out = fopen("color_test.ppm", "wb");
  fprintf(out, "P6 256 256 255\n");
  for(int r=0; r<256; r++) {
    for(int b=0; b<256; b++) {
        if (r==b){
            fputc(r, out); fputc(r, out); fputc(r, out);
        }
        else {
            fputc(0, out); fputc(0, out); fputc(0, out);
        }
    }
  }
  fclose(out);
}