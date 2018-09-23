#include<stdio.h>
#include<stdlib.h>

void main()
{
  FILE *fp = fopen("input.txt", "r");
  char buff[255];
  //while
  (fgets(buff,255,(FILE*)fp));
  //{
    printf("%c\n",buff[0] );
  //}
  printf("%c\n",buff[0] );
  fclose(fp);
}
