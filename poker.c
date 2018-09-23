#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void score_calc(int[],int[],int[],char[]);
void different_numbers(int,int,int,int,int,int[]);
void order(int,int,int,int,int,int[]);
int same_suit(char,char,char,char,char);
int check_exception(int[]);
void royal_flush_straight_flush();
void straight();
void flush();
void high_card();
void one_pair();
void three_of_a_kind();
void two_pairs();
void four_of_a_kind();
void full_house();

void main()
{
  FILE *fp = fopen("input.txt", "r");
  char buff[255];
  int p1_number[7],p2_number[7],p3_number[7];
  char p1_suit[7],p2_suit[7],p3_suit[7];

  //while
  (fgets(buff,255,(FILE*)fp));
  //{


  //}
  int buffer[32];
  for(int i=0;i<32;i++)
  {
    if(buff[i]=='2')buffer[i]=2;
    else if(buff[i]=='3')buffer[i]=3;
    else if(buff[i]=='4')buffer[i]=4;
    else if(buff[i]=='5')buffer[i]=5;
    else if(buff[i]=='6')buffer[i]=6;
    else if(buff[i]=='7')buffer[i]=7;
    else if(buff[i]=='8')buffer[i]=8;
    else if(buff[i]=='9')buffer[i]=9;
    else if(buff[i]=='1')buffer[i]=10;
    else if(buff[i]=='J')buffer[i]=11;
    else if(buff[i]=='Q')buffer[i]=12;
    else if(buff[i]=='K')buffer[i]=13;
    else if(buff[i]=='A')buffer[i]=14;
    else buffer[i]=0;
  }

  p1_number[0]=buffer[0];p1_suit[0]=buff[1];p1_number[1]=buffer[3];p1_suit[1]=buff[4];
  p2_number[0]=buffer[6];p2_suit[0]=buff[7];p2_number[1]=buffer[9];p2_suit[1]=buff[10];
  p3_number[0]=buffer[12];p3_suit[0]=buff[13];p3_number[1]=buffer[15];p3_suit[1]=buff[16];

  p1_number[2]=buffer[18];p1_suit[2]=buff[19];p2_number[2]=buffer[18];
  p2_suit[2]=buff[19];p3_number[2]=buffer[18];p3_suit[2]=buff[19];

  p1_number[3]=buffer[21];p1_suit[3]=buff[22];p2_number[3]=buffer[21];
  p2_suit[3]=buff[22];p3_number[3]=buffer[21];p3_suit[3]=buff[22];

  p1_number[4]=buffer[24];p1_suit[4]=buff[25];p2_number[4]=buffer[24];
  p2_suit[4]=buff[25];p3_number[4]=buffer[24];p3_suit[4]=buff[25];

  p1_number[5]=buffer[27];p1_suit[5]=buff[28];p2_number[5]=buffer[27];
  p2_suit[5]=buff[28];p3_number[5]=buffer[27];p3_suit[5]=buff[28];

  p1_number[6]=buffer[30];p1_suit[6]=buff[31];p2_number[6]=buffer[30];
  p2_suit[6]=buff[31];p3_number[6]=buffer[30];p3_suit[6]=buff[31];

  for(int i=0;i<32;i++)
    printf("%d ",buffer[i]);
  printf("\n" );
  for(int i=0;i<32;i++)
      printf("%c ",buff[i]);
  printf("\n" );
  //printf("%c\n",p1_suit[3]);
//  printf("%d\n",p1_number[4]);
  int score[5]={0,0,0,0,0};
  int winner[6]={0,0,0,0,0,0};
  int better[5]={0,0,0,0,0};
  int temp[21][5],count=0,counter;

  for(int i=0;i<7;i++)
  {
    for(int j=i+1;j<7;j++)
    {
      counter=0;
      for(int k=0;k<7;k++)
      {
        if((k!=i)&&(k!=j))
        {
          temp[count][counter]=k;
          counter++;
        }
      }
      count++;
    }
  }
  for(int i=0;i<21;i++)
  {
    for(int j=0;j<5;j++)
      {
        score_calc(temp[i],score,p1_number,p1_suit);
        for(int i=0;i<5;i++)
          printf("\n%d ",score[i] );

      }
    printf("\n" );
  }
  score_calc(temp[20],score,p1_number,p1_suit);
  for(int i=0;i<5;i++)
    printf("\n%d ",score[i] );
  fclose(fp);
}



void royal_flush_straight_flush(int y[],int score[])
{
  score[0]=900+y[0];
}

void four_of_a_kind(int y[],int score[])
{
  if(y[0]==y[1])
  {
    score[0]=800+y[0];
    score[1]=y[4];
  }
  else
  {
    score[0]=800+y[4];
    score[1]=y[0];
  }
}

void full_house(int y[],int score[])
{
  if(y[0]==y[2])
  {
    score[0]=700+y[0];
    score[1]=700+y[3];
  }
  else
  {
    score[0]=700+y[2];
    score[1]=y[0];
  }
}

void flush(int y[],int score[])
{
  score[0]=600+y[0];
  for(int i=1;i<5;i++)
  {
    score[i]=y[i];
  }
}

void straight(int y[],int score[])
{
  score[0]=500+y[0];
}

void three_of_a_kind(int y[],int score[])
{
  if(y[0]==y[2])
  {
    score[0]=400+y[0];
    score[1]=y[3];
    score[2]=y[4];
  }
  else if(y[1]==y[3])
  {
    score[0]=400+y[1];
    score[1]=y[0];
    score[2]=y[4];
  }
  else
  {
    score[0]=400+y[2];
    score[1]=y[0];
    score[2]=y[1];
  }
}

void two_pairs(int y[],int score[])
{
  if(y[0]==y[1])
  {
    score[0]=300+y[0];

    if(y[2]==y[3])
    {
      score[1]=y[2];
      score[2]=y[4];
    }
    else
    {
      score[1]=y[3];
      score[2]=y[2];
    }
  }
  else
  {
    score[0]=300+y[1];
    score[1]=y[0];
    score[2]=y[3];
  }
}

void one_pair(int y[],int score[])
{
  if(y[0]==y[1])
  {
    score[0]=200+y[0];
    score[1]=y[2];
    score[2]=y[3];
    score[3]=y[4];
  }
  else
  {
    score[1]=y[0];
    if(y[1]==y[2])
    {
      score[0]=200+y[1];
      score[2]=y[3];
      score[3]=y[4];
    }
    else
    {
      score[2]=y[1];
      if(y[2]==y[3])
      {
        score[0]=200+y[2];
        score[3]=y[4];
      }
      else
      {
        score[0]=200+y[3];
        score[3]=y[2];
      }
    }
  }
}

void high_card(int y[],int score[])
{
  score[0]=100+y[0];
  for(int i=1;i<5;i++)
  {
    score[i]=y[i];
  }
}






void score_calc(int temp[],int score[],int p1_number[],char p1_suit[])
{
  int x[5]={0,0,0,0,0},no_of_zero=0,y[5]={0,0,0,0,0},c;
  //int diff_num=

  int card1n=p1_number[temp[0]];
  int card2n=p1_number[temp[1]];
  int card3n=p1_number[temp[2]];
  int card4n=p1_number[temp[3]];
  int card5n=p1_number[temp[4]];

  char card1s=p1_suit[temp[0]];
  char card2s=p1_suit[temp[1]];
  char card3s=p1_suit[temp[2]];
  char card4s=p1_suit[temp[3]];
  char card5s=p1_suit[temp[4]];
  different_numbers(card1n,card2n,card3n,card4n,card5n,x);
  for(int i=0;i<5;i++)
  {
    printf("%d ",x[i] );
  }
  for(int i=0;i<5;i++)
  {
    if(x[i]==0)
      no_of_zero++;
  }
  //printf("%d\n",no_of_zero);
  order(card1n,card2n,card3n,card4n,card5n,y);

  for(int i=0;i<5;i++)
    printf("%d ",y[i] );

  int count=y[4];
  for(int i=4;i>=0;i--)
  {
    if(count==y[i])
      {
        count++;
      }
  }
  if(count==(y[4]+5))
    c=1;
  else c=0;

  printf("\n%d",c);

  int ss=same_suit(card1s,card2s,card3s,card4s,card5s);
  printf(" %d\n",ss );

  int exception=check_exception(y);
  printf("%d\n",exception );

  if(no_of_zero==0)
  {
    if(c==1)
    {
      if(ss==1)
        royal_flush_straight_flush(y,score);
      else
        straight(y,score);
    }
    else if(exception==1&&ss==0)
    {
      for(int i=0;i<5;i++)
      {
        y[i]=5-i;
      }
      straight(y,score);
    }
    else
    {
      if(ss=1)
        flush(y,score);
      else
        high_card(y,score);
    }
  }

  else if(no_of_zero==1)
    one_pair(y,score);

  else if(no_of_zero==2)
  {
    int flag=0;
    for(int i=0;i<5;i++)
    {
      if(x[i]==3)
        flag=1;
    }
    if(flag==1)
      three_of_a_kind(y,score);
    else
      two_pairs(y,score);
  }

  else if(no_of_zero==3)
  {
    int flag=0;
    for(int i=0;i<5;i++)
    {
      if(x[i]==4)
        flag=1;
    }
    if(flag==1)
      four_of_a_kind(y,score);
    else
      full_house(y,score);
  }


}

int check_exception(int y[])
{
  int count=y[4];
  for(int i=4;i>0;i--)
  {
    if(count==y[i])
      {
        count++;
      }
  }
  if(count==(y[4]+4)&&y[0]==14)
    return 1;
  else return 0;
}

int same_suit(char card1s,char card2s,char card3s,char card4s,char card5s)
{
  int count=0;
  char r[5]={card1s,card2s,card3s,card4s,card5s};
  char repeat=card1s;
  for(int i=0;i<5;i++)
    if(r[i]==repeat)
      count++;
  if(count==5)
    return 1;
  else
   return 0;
}

void order(int card1n,int card2n,int card3n,int card4n,int card5n,int y[5])
{
  int z[5]={card1n,card2n,card3n,card4n,card5n},a,min,count=0;
  for(int i=0;i<5;i++)
  {
    for(int j=i+1;j<5;j++)
    {
      if(z[i]<z[j])
        {
          a=z[i];
          z[i]=z[j];
          z[j]=a;
        }
    }
  }
  printf("\n");
  for(int i=0;i<5;i++)
  {
    y[i]=z[i];
  }

}


void different_numbers(int card1n,int card2n,int card3n,int card4n,int card5n,int x[5])
{
  int y[5]={card1n,card2n,card3n,card4n,card5n};
  for(int i=0;i<5;i++)
    printf("%d\n",y[i] );
  int check[5]={0,0,0,0,0},dummy[5]={0,0,0,0,0},count=0;
  for(int i=0;i<5;i++)
  {
    int flag=0;
    for(int j=0;j<count;j++)
    {
      if(y[i]==dummy[j])
        {
          check[j]++;
          flag=1;
        }
    }
    if(flag==0)
      {
        dummy[count]=y[i];
        check[count]++;
        count++;
      }
  }
  for(int i=0;i<5;i++)
  {
    x[i]=check[i];
  }
}
