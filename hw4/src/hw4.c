#include<stdio.h>
#include<string.h>

void split(char  **store, char  *str, const char *del){
char   * s = strtok(str, del);
  
while (s != NULL) {
  *store ++   = s;
  s = strtok(NULL, del);
}
}



int main(int argc, char *argv[]){

if(argc==3)
{
if((strcmp(argv[1],"./hw4/Board.txt")==0)&&(strcmp(argv[2],"./hw4/StepLog.txt")==0)) 
{
printf("");
}
else
{printf("error!!fuck\n");
 return 0;
}
}
else
{printf("error!\n");
 return 0;
}
//建立牌庫
int Spade[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Heart[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Diamond[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Club[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

FILE *fB;
FILE *fSt;
//判斷階段
char hand [100];
char *box[13];//儲存手牌資訊 
fB=fopen("Board.txt","r");
fSt=fopen("StepLog.txt","r");
while(fscanf(fB,"%s",hand)==1)
  {
  if(strcmp("Hand",hand)==0)
  break;
  }
fscanf(fB,"%s",hand);
split(box,hand,",");

int i=0;
while(strcmp(box[i],"")!=0)
  {
  printf("%s\n",box[i]);
  i=i+1;
  }//i等於手牌數

//將手牌資訊存入牌庫
int r=0;
for(r=0;r<i;r=r+1)
{
char *term [2]; int n=0;
split(term,box[r],"-");
n=atoi(term[1]);
if(strcmp(term[0],"S")==0)
Spade[n]=1;
if(strcmp(term[0],"H")==0)
Heart[n]=1;
if(strcmp(term[0],"D")==0)
Diamond[n]=1;
if(strcmp(term[0],"C")==0)
Club[n]=1;
}

//判斷自己是第幾個玩家
char nam [100];
int name=0;
fseek(fB,0L,SEEK_SET);
fscanf(fB,"%s",nam);
if(strcmp("Player1",nam)==0)
name=1;
if(strcmp("Player2",nam)==0)
name=2;
if(strcmp("Player3",nam)==0)
name=3;
if(strcmp("Player4",nam)==0)
name=4;

//判斷階段
char str [100];
int stage;//儲存目前是1叫牌還是2出牌
fseek(fB,0L,SEEK_SET);
while(fscanf(fB,"%s",str)==1)
  {
  if(strcmp("Stage",str)==0)
  break;
  }
fscanf(fB,"%s",str);
if(strcmp(str,"play")==0)
stage=2;
if(strcmp(str,"call")==0)
stage=1;   
fclose(fB);



//讀取StepLog資訊
if(stage==1)
{
//判斷自己排組

int status [4]={0,0,0,0};
int p=1;
for(p=1;p<14;p=p+1)
{
if(Spade[p]==1)
status[0]=status[0]+1;
if(Heart[p]==1)
status[1]=status[1]+1;
if(Diamond[p]==1)
status[2]=status[2]+1;
if(Club[p]==1)
status[3]=status[3]+1;
}
int Spadepoint=Spade[11]+Spade[12]*2+Spade[13]*3+Spade[1]*4;
int Heartpoint=Heart[11]+Heart[12]*2+Heart[13]*3+Heart[1]*4;
int Diamondpoint=Diamond[11]+Diamond[12]*2+Diamond[13]*3+Diamond[1]*4;
int Clubpoint=Club[11]+Club[12]*2+Club[13]*3+Club[1]*4;
int total=Spadepoint+Heartpoint+Diamondpoint+Clubpoint;
char take [100];
int partner;
partner=0;
partner=(name+2)%4;
char *p1c [35];
char *p2c [35];
char *p3c [35];
char *p4c [35];
int line=0;
fSt=fopen("Steplog.txt","r");
  while(fscanf(fSt,"%s",take)==1)
  {
    if(strcmp(take,"call")==0)
    break;
  }
  int count=0;
  int round=0;
while(fscanf(fSt,"%s",take)==1)
  {
   if(strcmp(take,"call")==0)
   {
      fscanf(fSt,"%s",take);
      count=(count+1)%4;
      if(count==1)
      round=round+1;
      switch(count)
      {
      case 1:
      {strcpy(p1c[round],take);break;}
      case 2:
      {strcpy(p2c[round],take);break;}
      case 3:
      {strcpy(p3c[round],take);break;}
      case 4:
      {strcpy(p4c[round],take);break;}
      }
    }
  }

char big[100];//獲取最大喊牌
switch(name)
{  case 1:
  {if(strcmp("pass",p4c[round-1])==0)
   {
    if(strcmp("pass",p3c[round-1])==0)
    strcpy(big,p2c[round-1]);
    else
    strcpy(big,p3c[round-1]); 
   } 
   else
   strcpy(big,p4c[round-1]);
  }
  case 2:
  {if(strcmp("pass",p1c[round])==0)
   {
    if(strcmp("pass",p4c[round-1])==0)
    strcpy(big,p3c[round-1]);
    else
    strcpy(big,p4c[round-1]);
   }
   else
   strcpy(big,p1c[round]);
  }
  case 3:
  {if(strcmp("pass",p2c[round])==0)
   {
    if(strcmp("pass",p1c[round])==0)
    strcpy(big,p4c[round-1]);
    else
    strcpy(big,p1c[round]);
   }
   else
   strcpy(big,p2c[round]);
  }
 case 4:
  {if(strcmp("pass",p3c[round])==0)
   {
    if(strcmp("pass",p2c[round])==0)
    strcpy(big,p1c[round]);
    else
    strcpy(big,p2c[round]);
   }
   else
   strcpy(big,p3c[round]);  }}//end switch
int A;//記錄花色
int B;//記錄喊數
char *catch[2];
split(catch,big,"-");
if(strcmp(catch[0],"S")==0)
A=1;
if(strcmp(catch[0],"H")==0)
A=2;
if(strcmp(catch[0],"D")==0)
A=3;
if(strcmp(catch[0],"C")==0)
A=4;
B=atoi(catch[1]);

//決定要喊什麼
int myA;
int S=0;
int H=0;
int D=0;
int C=0;
int X=0;
int myB;
if((status[0]>4)&&(Spadepoint>3))
S=1;
if((status[1]>4)&&(Heartpoint>3))
H=1;
if((status[2]>4)&&(Diamondpoint>3))
D=1;
if((status[3]>4)&&(Clubpoint>3))
C=1;

if(8>total&&total>6)
myB=1;
if(total<6)
myB=0;
if(12>total&&total>8)
myB=2;
if(total>12) 
myB=3;

char *ans;
char *ansnum;
if(B<myB)
{
strcpy(ans,"C");
switch (B){
case 1:
{strcpy(ansnum,"-2");break;}
case 2:
{strcpy(ansnum,"-3");break;}
}
}
else if(B=myB)
{
switch(A){
case 1:
{strcpy(ans,"pass");strcpy(ansnum,"");break;}
case 2:
{if(S==1){strcpy(ans,"S");strcpy(ansnum,catch[1]);}
else
{strcpy(ans,"pass");strcpy(ansnum,"");}
break;}
case 3:
{
if(D==1)
{strcpy(ans,"H");strcpy(ansnum,catch[1]);}
else
{strcpy(ans,"pass");strcpy(ansnum,"");}break;
}
case 4:
{
if(C==1)
{strcpy(ans,"D");strcpy(ansnum,catch[1]);}
else
{strcpy(ans,"pass");strcpy(ansnum,"");}break;
}
}


}
else if(B>myB)
strcpy(ans,"pass");

if(myB==0)
strcpy(ans,"pass");

FILE *write;
write=fopen("StepLog.txt","a");
switch(name){
case 1:
{fprintf(write,"%s","Player1");break;}
case 2:
{fprintf(write,"%s","Player2");break;}
case 3:
{fprintf(write,"%s","Player3");break;}
case 4:
{fprintf(write,"%s","Player4");break;}
}
fprintf(write,"%s-%s",ans,ansnum);
fclose(write);



}//end if
       
if(stage==2)
{
char sentence[100];
fseek(fSt,-2L,SEEK_END);
fscanf(fSt,"%s",sentence);
char FF[10];
char NN[10];
if(strcmp("Round",sentence)==0)
{int h=1;
int flower=0;
int poinS=0;
for(h=1;h<14;h=h+1)
{
if(Spade[h]==1)
{poinS=h;
 Spade[h]=0;
 flower=1;
 break;   
}}
if(poinS==0)
{
for(h=1;h<14;h=h+1)
{
if(Heart[h]==1)
{poinS=h;
 Heart[h]=0;
 flower=2;
 break;
}
}
}
if(poinS==0)
{
for(h=1;h<14;h=h+1)
{
if(Diamond[h]==1)
{poinS=h;
 Diamond[h]=0;
 flower=3;
 break;
}
}
}
if(poinS==0)
{
for(h=1;h<14;h=h+1)
{
if(Club[h]==1)
{poinS=h;
 Club[h]=0;
 flower=4;
 break;
}
}
}

switch (flower)
{
case 1:
{strcpy(FF,"S");}
case 2:
{strcpy(FF,"H");}
case 3:
{strcpy(FF,"D");}
case 4:
{strcpy(FF,"C");}
}

switch (poinS)
{
case 1:
{strcpy(NN,"1");}
case 2:
{strcpy(NN,"2");}
case 3:
{strcpy(NN,"3");}
case 4:
{strcpy(NN,"4");}
case 5:
{strcpy(NN,"5");}
case 6:
{strcpy(NN,"6");}
case 7:
{strcpy(NN,"7");}
case 8:
{strcpy(NN,"8");}
case 9:
{strcpy(NN,"9");}
case 10:
{strcpy(NN,"10");}
case 11:
{strcpy(NN,"11");}
case 12:
{strcpy(NN,"12");}
case 13:
{strcpy(NN,"13");}
}
}
else
{
fseek(fSt,-16L,SEEK_END);
while(fscanf(fSt,"%s",sentence)==1)
{
if(strcmp(sentence,"Round")==0)
break;
}
fscanf(fSt,"%s",sentence);
fscanf(fSt,"%s",sentence);
fscanf(fSt,"%s",sentence);
fscanf(fSt,"%s",sentence);
char *what [2];

split(what,sentence,"-");
int v=0;
int flower2;
int poinS2=0;
if(strcmp(what[0],"S")==0)
{
for(v=1;v<14;v=v+1)
{
if(Spade[v]==1)
{poinS2=v;
 Spade[v]=0;
 flower2=1;
 break;
}}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Heart[v]==1)
{poinS2=v;
 Heart[v]=0;
 flower2=2;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Diamond[v]==1)
{poinS2=v;
 Diamond[v]=0;
 flower2=3;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Club[v]==1)
{poinS2=v;
 Club[v]=0;
 flower2=4;
 break;
}
}
}

}
if(strcmp(what[0],"H")==0)
{
for(v=1;v<14;v=v+1)
{
if(Heart[v]==1)
{poinS2=v;
 Heart[v]=0;
 flower2=1;
 break;
}}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Spade[v]==1)
{poinS2=v;
 Spade[v]=0;
 flower2=2;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Diamond[v]==1)
{poinS2=v;
 Diamond[v]=0;
 flower2=3;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Club[v]==1)
{poinS2=v;
 Club[v]=0;
 flower2=4;
 break;
}
}
}

}

if(strcmp(what[0],"D")==0)
{
for(v=1;v<14;v=v+1)
{
if(Diamond[v]==1)
{poinS2=v;
 Diamond[v]=0;
 flower2=1;
 break;
}}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Spade[v]==1)
{poinS2=v;
 Spade[v]=0;
 flower2=2;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Heart[v]==1)
{poinS2=v;
 Heart[v]=0;
 flower2=3;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Club[v]==1)
{poinS2=v;
 Club[v]=0;
 flower2=4;
 break;
}
}
}

}

if(strcmp(what[0],"C")==0)
{
for(v=1;v<14;v=v+1)
{
if(Club[v]==1)
{poinS2=v;
 Club[v]=0;
 flower2=1;
 break;
}}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Spade[v]==1)
{poinS2=v;
 Spade[v]=0;
 flower2=2;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Diamond[v]==1)
{poinS2=v;
 Diamond[v]=0;
 flower2=3;
 break;
}
}
}
if(poinS2==0)
{
for(v=1;v<14;v=v+1)
{
if(Heart[v]==1)
{poinS2=v;
 Heart[v]=0;
 flower2=4;
 break;
}
}
}

}

switch (flower2)
{
case 1:
{strcpy(FF,"S");}
case 2:
{strcpy(FF,"H");}
case 3:
{strcpy(FF,"D");}
case 4:
{strcpy(FF,"C");}
}

switch (poinS2)
{
case 1:
{strcpy(NN,"1");}
case 2:
{strcpy(NN,"2");}
case 3:
{strcpy(NN,"3");}
case 4:
{strcpy(NN,"4");}
case 5:
{strcpy(NN,"5");}
case 6:
{strcpy(NN,"6");}
case 7:
{strcpy(NN,"7");}
case 8:
{strcpy(NN,"8");}
case 9:
{strcpy(NN,"9");}
case 10:
{strcpy(NN,"10");}
case 11:
{strcpy(NN,"11");}
case 12:
{strcpy(NN,"12");}
case 13:
{strcpy(NN,"13");}
}




}
FILE *GGG;
GGG=fopen("StepLog.txt","a");
fprintf(GGG,"%s-%s",FF,NN);




}//end if
                                             



return 0;
}

