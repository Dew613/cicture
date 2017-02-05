#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
int main(){
  int fd, r, g, b, i, j;
  char line[20];

  fd = open("board.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);


  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line));
  for (i=0; i < 500; i++){
    for (j=0; j < 500; j++){
      if (j%100<50 && i%100<50){
	r=255;
	g=255;
	b=255;
      }
      else if( j%100>50 && i%100>50){
	r=255;
	b=255;
	g=255;
      }
      else{
	r=0;
	b=0;
	g=0;
      }
      snprintf(line, sizeof(line), "%d %d %d\n", r, g, b);
      write (fd, line, strlen(line));
    }
  }
}
