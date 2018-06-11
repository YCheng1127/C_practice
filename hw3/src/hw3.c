#include<stdio.h>
#include<string.h>
void write(char plate[6][7]);

void read(char NAM [],char plate[6][7]);

int formatcheck(void);

void shpl(char plate[6][7]);

int checkfull(int Column, char platecheck[6][7]);

int win(int A, char plate[6][7]);

int blank(int column, char plate[6][7]);

int main (int argc, char *argv[]){

int allfull(char plate [6][7]);

int count(char plate[6][7]);
char plate [6][7];//建立棋盤矩陣
int i=0;//控制for迴圈所需的變數
int j=0;//控制for迴圈所需的變數
for(i=0;i<6;i=i+1)//將棋盤的每個空格填入N
  {
  for(j=0;j<7;j=j+1)
    {
    plate[i][j]='N';
    }
  }
char NAM [20];
if(argc==2)
{printf("%s\n",argv[1]);
strcpy(NAM,argv[1]);
read(NAM,plate);
}

int turn=0;//計算現在場上棋子數
turn=count(plate);//將結果存入turn
printf("------棋盤------\n");
shpl(plate);
int Aop=0;//儲存A玩家輸入的指令
int Bop=0;//儲存B玩加輸入的指令
int checkinput=0;
int AR='R';
int BY='Y';

printf("歡迎進行四子棋遊戲~\n");



//玩家A輸入指令
while(1==1){
if(turn==1){
printf("請玩家A輸入指令(數字1~7 example: 3): ");
checkinput=0;
while(checkinput==0)//使用者輸入
  {  
  scanf("%d",&Aop);  
  if(formatcheck()==0)//檢查scanf是否成功將輸入值存入，若沒有則清空緩衝區
    printf("請重新輸入: ");
  else
    {
    if(Aop>7||Aop<1)
      printf("請重新輸入: ");
    else if(checkfull(Aop-1,plate)==0)
      printf("該欄位已無空格，請重新輸入: ");
    else
    checkinput=1;
    }
  }
Aop=Aop-1;
plate[blank(Aop,plate)][Aop]='R';
shpl(plate);
if(win(AR,plate)==1)
  {
  printf("玩家A獲勝!");
  break;
  }
turn=2;
}
//玩家二輸入指令
if(turn==2){
printf("請玩家B輸入指令(數字1~7 example: 3): ");
checkinput=0;
while(checkinput==0)//使用者輸入
  {
  scanf("%d",&Bop);
  if(formatcheck()==0)//檢查scanf是否成功將輸入值存入，若沒有則清空緩衝區
    printf("請重新輸入: ");
  else
    {
    if(Bop>7||Bop<1)
      printf("請重新輸入: ");
    else if(checkfull(Bop-1,plate)==0)
      printf("該欄位已無空格，請重新輸入: ");
    else
    checkinput=1;
    }
  }


Bop=Bop-1;
plate[blank(Bop,plate)][Bop]='Y';
shpl(plate);
if(win(BY,plate)==1)
  {
  printf("玩家B獲勝!");
  break;
  }
if(allfull(plate)==1)
  {
  printf("玩家B獲勝!");
  break;
  }
turn=1;
}

}






}

int checkfull(int Column, char platecheck[6][7])
{
int i=0;//控制for迴圈所需的變數
int count=0;//計算空格數所需的變數
for(i=0;i<6;i=i+1)
 {
  if(platecheck[i][Column]=='N')
  {
   count=count+1;
  }
 }
if(count==0)
 return 0;
else
 return 1;
}

int formatcheck(void){
char c;
int v=1;
while(((c=getchar())!='\n')&&c !=EOF) v=0;
return v;
}

void shpl(char plate[6][7]){
int i=0;
int j=0;
for(i=0;i<6;i=i+1)
  {
  for(j=0;j<7;j=j+1)
    {
    printf("%c ",plate[i][j]);
    }
  printf("\n\n"); 
  }
}
//判斷勝負
int win(int A,char plate[6][7]){
int i=0;
int j=0;
int wn=0;
for(i=0;i<6;i=i+1)
  {
  for(j=0;j<7;j=j+1) 
    {
    int up=i-0;
    int down=5-i;
    int left=j-0;
    int right=6-j;
    int lu,ld,ru,rd;
    if(left>up)
      lu=up;
    else
      lu=left;
    if(left>down)
      ld=down;
    else
      ld=left;
    if(right>up)
      ru=up;
    else
      ru=right;
    if(right>down)
      rd=down;
    else
      rd=right;
    
    int s=0;
       
    if(up>=3)   
      {
      int r=0;
      for(s=0;s<=up;s=s+1)
        {
         if(plate[i-s][j]==A)
            r=r+1; 
         else
            break;
        } 
      if(r>=4)      
        wn=wn+1;
      }
    if(down>=3)
      {
      int r=0;
      for(s=0;s<=down;s=s+1)
        {
         if(plate[i+s][j]==A)
            r=r+1;
         else 
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(left>=3)
      {
      int r=0;
      for(s=0;s<=left;s=s+1)
        {
         if(plate[i][j-s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(right>=3)
      {
      int r=0;
      for(s=0;s<=up;s=s+1)
        {
         if(plate[i][j+s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(lu>=3)
      {
      int r=0;
      for(s=0;s<=lu;s=s+1)
        {
         if(plate[i-s][j-s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(ld>=3)
      {
      int r=0;
      for(s=0;s<=ld;s=s+1)
        {
         if(plate[i+s][j-s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(ru>=3)
      {
      int r=0;
      for(s=0;s<=ru;s=s+1)
        {
         if(plate[i-s][j+s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      }
    if(rd>=3)
      {
      int r=0;
      for(s=0;s<=rd;s=s+1)
        {
         if(plate[i+s][j+s]==A)
            r=r+1;
         else
            break;
        }
      if(r>=4)
        wn=wn+1;
      } 
    }
  }
 if(wn!=0)
      return 1;//玩家獲勝
 else
      return 0;//玩家沒有贏
}
//判斷要在哪個欄位放棋子
int blank(int column,char plate[6][7]){
int i=0;
for(i=5;i>=0;i=i-1 )
  {
  if(plate[i][column]=='N')
    break;
  }
return i;
}

//讀檔
void read(char NAM [],char plate[6][7])
{
  char V;
  FILE *cfPtr;
  if((cfPtr=fopen(NAM,"r"))==NULL){
    puts("File could not be opened");
  }
  else{
    printf("        棋盤\n");
    int i=0;
    int j=0;
    for(i=0;i<6;i=i+1){
      for(j=0;j<7;j=j+1){
      
      fscanf(cfPtr," %c",&V);  
      plate[i][j]=V;
      
      
      }
    }
    
    fclose(cfPtr);
  }

}
//寫入txt檔 但是用不到
void write(char plate[6][7]){
  
  FILE *cfPtr;
  if((cfPtr=fopen("殘局.txt","w"))==NULL){
    puts("File could not be opened");
  }
  else{
    int i=0;
    int j=0;
    for(i=0;i<6;i=i+1){
      for(j=0;j<7;j=j+1){
      fprintf(cfPtr,"%c ",plate[i][j]);
      }
    fprintf(cfPtr,"\n\n");
    }
    fclose(cfPtr); 
    }  
}

int allfull(char plate [6][7]){
int i=0;
int j=0;
int NN=0;//計算N的數量
for(i=0;i<6;i=i+1)
{
  for(j=0;j<7;j=j+1){
  if(plate[i][j]=='N')
    {
     NN=NN+1;
    }

  }
} 
if(NN==0)
return 1;
else
return 0;
}

int count(char plate[6][7]){
int i=0;
int j=0;
int kr=0;
int ky=0;
for(i=0;i<6;i=i+1)
  {
  for(j=0;j<7;j=j+1)
     {
     if(plate[i][j]=='R')
     kr=kr+1;
     }
  }
for(i=0;i<6;i=i+1)
  {
  for(j=0;j<7;j=j+1)
     {
     if(plate[i][j]=='Y')
     ky=ky+1;
     }
  }
if(kr>ky)
  return 2;
else if(kr==ky)
  return 1;
}
