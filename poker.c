#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int winner[5],trial[5];

void score_calc(char,char,char,char,char,char,char,char,char,char);
void different_numbers(char,char,char,char,char,int[]);

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
  
  printf("%i\n",r);
  int x[5];
  score_calc(p1_number[0],p1_suit[0],p1_number[1],p1_suit[1],p1_number[2],p1_suit[2],
    p1_number[3],p1_suit[3],p1_number[4],p1_suit[4]);
  fclose(fp);
}

void score_calc(char card1n,char card1s,char card2n,char card2s,char card3n,
  char card3s,char card4n,char card4s,char card5n,char card5s)
{
  int x[5]={0,0,0,0,0};
  //int diff_num=
  different_numbers(card1n,card2n,card3n,card4n,card5n,x);
}

void different_numbers(char card1n,char card2n,char card3n,char card4n,char card5n,int x[5])
{
  char y[5]={card1n,card2n,card3n,card4n,card5n};
  char check[5]={'0','0','0','0','0'};
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      //if(y[i]==check[j])
        //check[j]++;
    }
  }
}
