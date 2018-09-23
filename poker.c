#include<stdio.h>
#include<stdlib.h>
int winner[5],trial[5];

void score_calc(char,char,char,char,char,char,char,char,char,char);

void main()
{
  FILE *fp = fopen("input.txt", "r");
  char buff[255];
  char p1_number[5],p1_suit[5],p2_number[5],p2_suit[5],p3_number[5],p3_suit[5],
  c1_number[5],c1_suit[5],c2_number[5],c2_suit[5],c3_number[5],c3_suit[5],
  c4_number[5],c4_suit[5],c5_number[5],c5_suit[5];
  //while
  (fgets(buff,255,(FILE*)fp));
  //{

    p1_number[0]=buff[0];p1_suit[0]=buff[1];p1_number[1]=buff[3];p1_suit[1]=buff[4];
    p2_number[0]=buff[6];p2_suit[0]=buff[7];p2_number[1]=buff[9];p2_suit[1]=buff[10];
    p3_number[0]=buff[12];p3_suit[0]=buff[13];p3_number[1]=buff[15];p3_suit[1]=buff[16];

    p1_number[2]=buff[18];p1_suit[2]=buff[19];p2_number[2]=buff[18];
    p2_suit[2]=buff[19];p3_number[2]=buff[18];p3_suit[2]=buff[19];

    p1_number[3]=buff[21];p1_suit[3]=buff[22];p2_number[3]=buff[21];
    p2_suit[3]=buff[22];p3_number[3]=buff[21];p3_suit[3]=buff[22];

    p1_number[4]=buff[24];p1_suit[4]=buff[25];p2_number[4]=buff[24];
    p2_suit[4]=buff[25];p3_number[4]=buff[24];p3_suit[4]=buff[25];
  //}
  printf("%c\n",p1_number[4]);
  int x[5];
  score_calc(p1_number[0],p1_suit[0],p1_number[1],p1_suit[1],p1_number[2],p1_suit[2],
    p1_number[3],p1_suit[3],p1_number[4],p1_suit[4]);
  fclose(fp);
}

void score_calc(char p1_number,char p1_suit,char p2_number,char p2_suit,
  char p3_number,char p3_suit,char p4_number,char p4_suit,char p5_number,char p6_suit)
{
  ;
}
