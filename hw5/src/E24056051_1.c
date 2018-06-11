#include<stdio.h>
#include<string.h>
void chB(int *mylF,int *mylN,int Club2[], int Diamond2[],int Heart2[],int Spade2[],int Flower);
void judgeflower(int *Ss,int *Sc,int status[],int totalpoint,int Spadepoint,int Heartpoint,int Diamondpoint,int Clubpoint,int Spade[],int Heart[],int Diamond[],int Club[]);
void choose(int *myF,int Sc,int Hc,int Dc,int Cc,int status[]);/*選出自己最好的花色*/
void chS(int *mylF,int *mylN,int Club2[], int Diamond2[],int Heart2[],int Spade2[],int Flower);
int main(int argc, char *argv[]){

int Spade[14]={0};
int Heart[14]={0};
int Diamond[14]={0};
int Club[14]={0};

/*讀取手牌*/
FILE *fB;

char hand [100];
char *tokenPtr;
char *box[13];
fB=fopen(argv[1],"r");

while(fscanf(fB,"%s",hand)==1)
  {
  if(strncmp("Hand",hand,4)==0)
  break;
  }
fscanf(fB,"%s",hand);
tokenPtr=strtok(hand,",");

/*儲存手牌資料到陣列*/
int i=0;
while(tokenPtr!=NULL)
{
box[i]=tokenPtr;
i++;
tokenPtr=strtok(NULL,",");
}

int i2=0;
for(i2=0;i2<i;i2++)
{
char F[5];
int N=0;
tokenPtr=strtok(box[i2],"-");
strcpy(F,tokenPtr);

tokenPtr=strtok(NULL,"-");
N=atoi(tokenPtr);

if(strcmp(F,"S")==0)
Spade[N]=1;
if(strcmp(F,"H")==0)
Heart[N]=1;
if(strcmp(F,"D")==0)
Diamond[N]=1;
if(strcmp(F,"C")==0)
Club[N]=1;


printf("%s-%d\n",F,N);
}

int k=1;
for(k=1;k<14;k++)
{
printf("%d\n",Spade[k]);
}

/*判斷自己是第幾個玩家*/
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


/*判斷階段*/
char str [100];
int stage;/*儲存目前是1叫牌還是2出牌*/
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

if(stage==1)
{
int status[4]={0};
int r=1;
for(r=1;r<14;r++)
{
status[0]=Spade[r]+status[0];
status[1]=Heart[r]+status[1];
status[2]=Diamond[r]+status[2];
status[3]=Club[r]+status[3];
}

int Spadepoint=Spade[1]*4+Spade[11]+Spade[12]*2+Spade[13]*3;
int Heartpoint=Heart[1]*4+Heart[11]+Heart[12]*2+Heart[13]*3;
int Diamondpoint=Diamond[1]*4+Diamond[11]+Diamond[12]*2+Diamond[13]*3;
int Clubpoint=Club[1]*4+Club[11]+Club[12]*2+Club[13]*3;
int totalpoint=Spadepoint+Heartpoint+Diamondpoint+Clubpoint;
printf("%d-%d-%d-%d\n",Spadepoint,Heartpoint,Diamondpoint,Clubpoint);
printf("%d",totalpoint);

int Sc=0;
int Ss=0;
int Hc=0;
int Hs=0;
int Dc=0;
int Ds=0;
int Cc=0;
int Cs=0;

judgeflower(&Ss,&Sc,status,totalpoint,Spadepoint,Heartpoint,Diamondpoint,Clubpoint,Spade,Heart,Diamond,Club);
judgeflower(&Hs,&Hc,status,totalpoint,Heartpoint,Spadepoint,Diamondpoint,Clubpoint,Heart,Spade,Diamond,Club);
judgeflower(&Ds,&Dc,status,totalpoint,Diamondpoint,Heartpoint,Spadepoint,Clubpoint,Diamond,Heart,Spade,Club);
judgeflower(&Cs,&Cc,status,totalpoint,Clubpoint,Heartpoint,Diamondpoint,Spadepoint,Club,Heart,Diamond,Spade);

int NTc=0;
if(totalpoint>20)
NTc=2;

printf("\n\n%d",Sc);
printf("\n%d",Ss);
printf("\n\n%d",Hc);
printf("\n%d",Hs);
printf("\n\n%d",Dc);
printf("\n%d",Ds);
printf("\n\n%d",Cc);
printf("\n%d",Cs);
/*儲存玩家喊過的花色*/
int player[4][5]={0};
int partner=0;;
switch(name)
{
case 1:
{
partner=3;break;
}
case 2:
{
partner=4;break;
}
case 3:
{
partner=1;break;
}
case 4:
{
partner=2;break;
}

}
char take[30];
FILE *fSt;
fSt=fopen(argv[2],"r");
while(fscanf(fSt,"%s",take)==1)
  {
    if(strcmp(take,"call")==0)
    break;
  }
if(fscanf(fSt,"%s",take)==1)
{
int w=0;
while(fscanf(fSt,"%s",take)==1)
  {
    if(strcmp(take,"call")==0)
    {
         char *getr;
         int line=0;
         int tf=1;
         w=(w+1)%4;
        if(w==0)
        w=4;
     fscanf(fSt,"%s",take);
         if(strcmp(take,"pass")!=0){
     getr=strtok(take,"-");
         if(strcmp(getr,"C")==0)
         tf=1;
     else if(strcmp(getr,"D")==0)
     tf=2;
     else if(strcmp(getr,"H")==0)
     tf=3;
     else if(strcmp(getr,"S")==0)
     tf=4;
     else if(strcmp(getr,"NT")==0)
         tf=5;
     getr=strtok(NULL,"-");
     line=atoi(getr);
         player[w-1][tf-1]=line;
         }
    }
  }
}/*自己不是第一個玩家*/

int x1=0;
for(x1=0;x1<5;x1=x1+1)
{
printf("%d",player[0][x1]);
}
for(x1=0;x1<5;x1=x1+1)
{
printf("%d",player[1][x1]);
}
for(x1=0;x1<5;x1=x1+1)
{
printf("%d",player[2][x1]);
}
for(x1=0;x1<5;x1=x1+1)
{
printf("%d",player[3][x1]);
}


/*找最大的出過的喊牌*/
int myF=0;/*要喊的花色*/
int myN=0;/*要喊得數字*/
int BF=0;
int BN=0;
int BP=0;
/*檢查自己是不是要第一個喊牌*/
int zelo=0;
int fi=0;
int fj=0;
for(fi=0;fi<4;fi=fi+1)
{
  for(fj=0;fj<5;fj++)
  {
    zelo=zelo+player[fi][fj];
  }
}
if(zelo!=0)
{
int zi=0;
int zj=0;
BN=player[zi][zj];
for(zi=0;zi<4;zi=zi+1)
{
 for(zj=0;zj<5;zj++)
 {
         if(player[zi][zj]>BN)
         BN=player[zi][zj];
 }
}
int col=-1;
for(zi=0;zi<4;zi=zi+1)
{
 for(zj=0;zj<5;zj++)
 {
         if(BN==player[zi][zj])
         {
          if(col<zj)
      col=zj;
         }
 }
}
if(player[0][col]==BN)
BP=1;
else if(player[1][col]==BN)
BP=2;
else if(player[2][col]==BN)
BP=3;
else if(player[3][col]==BN)
BP=4;

switch(col)
{
case 0:/*梅花*/
{BF=1;
break;
}
case 1:/*菱形*/
{BF=2;
break;
}
case 2:/*紅心*/
{BF=3;
break;
}
case 3:/*黑桃*/
{BF=4;
break;
}
case 4:/*無王*/
{BF=4;
break;
}
}
}
printf("\n\n%d-%d-%d\n\n",BF,BN,BP);

/*扣除敵人花色*/
int gj=0;
for(gj=0;gj<5;gj=gj+1)
{
 if(player[name+1-1][gj]>0)
 {
  switch(gj)
  {
   case 0:
   {
        Cc=-1;break;
   }
   case 1:
   {
        Dc=-1;break;
   }
   case 2:
   {
        Hc=-1;break;
   }
   case 3:
   {
        Sc=-1;break;
   }
   case 4:
   {
         NTc=-1;break;
   }
  }
 }
 if(player[((name+3)%4)-1][gj]>0)
 {
  switch(gj)
  {
   case 0:
   {
        Cc=-1;break;
   }
   case 1:
   {
        Dc=-1;break;
   }
   case 2:
   {
        Hc=-1;break;
   }
   case 3:
   {
        Sc=-1;break;
   }
   case 4:
   {
         NTc=-1;break;
   }
  }
 }
}
printf("%d-%d-%d",zelo,name,BP);
printf("partner=%d\n",partner);
if(zelo==0)/*還沒人喊過牌==>喊自己最好的花色*/
{
choose(&myF,Sc,Hc,Dc,Cc,status);
myN=1;
}
else
{
if(partner!=BP&&name!=BP)/*敵人喊的*/
{
int ej=0;
for(ej=0;ej<5;ej++)
{
if(player[partner-1][ej]>0)
{switch(ej)
{
case 0:
{
if(Cs==1&&player[partner-1][ej]<3&&player[partner][ej]+1>BN)
{myF=1;myN=player[partner-1][ej]+1;}
break;
}
case 1:
{
if(Ds==1&&player[partner-1][ej]<3&&player[partner][ej]+1>BN)
{myF=2;myN=player[partner-1][ej]+1;}
else if(Ds==1&&player[partner-1][ej]<3&&player[partner][ej]+1==BN&&ej+1>BF)
{myF=2;myN=player[partner-1][ej];}
        break;
}
case 2:
{
if(Hs==1&&player[partner-1][ej]<3&&player[partner][ej]+1>BN)
{myF=3;myN=player[partner-1][ej]+1;}
else if(Hs==1&&player[partner-1][ej]<3&&player[partner][ej]+1==BN&&ej+1>BF)
{myF=3;myN=player[partner-1][ej];}
        break;
}
case 3:
{
if(Ss==1&&player[partner-1][ej]<3&&player[partner][ej]+1>BN)
{myF=4;myN=player[partner-1][ej]+1;}
else if(Ss==1&&player[partner-1][ej]<3&&player[partner][ej]+1==BN&&ej+1>BF)
{myF=4;myN=player[partner-1][ej];}
        break;
}

}
}/*endif*/
}
if(myF==0&&myN==0)
choose(&myF,Sc,Hc,Dc,Cc,status);
switch(myF)
{
case 1:
{
if(Cc>BN)
myN=BN+1;break;
}
case 2:
{
if(Dc>BN)
{
if(BF>2)
myN=BN+1;
else if(BF<2)
myN=BN;
}
else if(Dc==BN&&BF<2)
myN=BN;
break;
}
case 3:
{
if(Hc>BN)
{
if(BF>3)
myN=BN+1;
else if(BF<3)
myN=BN;
}
else if(Hc==BN&&BF<3)
myN=BN;
break;
}
case 4:
{
if(Sc>BN)
{
if(BF>4)
myN=BN+1;
else if(BF<4)
myN=BN;
}
else if(Sc==BN&&BF<4)
myN=BN;
break;
}
}
}
else if(name==BP)/*我喊的*/
{
myF=0;myN=0;
}
else if(partner==BP)/*隊友喊的*/
{printf("hahaha");
switch(BF)
{
case 1:
{
if(Cs==1)
{myF=BF;myN=BN+1;}
else
{myF=0;myN=0;}break;
}
case 2:
{
if(Ds==1)
{myF=BF;myN=BN+1;}
else
{myF=0;myN=0;}break;
}
case 3:
{
if(Hs==1)
{myF=BF;myN=BN+1;}
else
{myF=0;myN=0;}break;
}
case 4:
{
if(Ss==1)
{myF=BF;myN=BN+1;}
else
{myF=0;myN=0;}break;
}
printf("LLL%d\n",Ss);
}
if(myF==0&&myN==0)
choose(&myF,Sc,Hc,Dc,Cc,status);
switch(myF)
{
case 1:
{
if(Cc>BN)
myN=BN+1;break;
}
case 2:
{
if(Dc>BN)
{
if(BF>2)
myN=BN+1;
else if(BF<2)
myN=BN;
}
else if(Dc==BN&&BF<2)
myN=BN;
break;
}
case 3:
{
if(Hc>BN)
{
if(BF>3)
myN=BN+1;
else if(BF<3)
myN=BN;
}
else if(Hc==BN&&BF<3)
myN=BN;
break;
}
case 4:
{
if(Sc>BN)
{
if(BF>4)
myN=BN+1;
else if(BF<4)
myN=BN;
}
else if(Sc==BN&&BF<4)
myN=BN;
break;
}
}

}
}

if(myF>5||myN>7)
{myF=0;myN=0;}
if(myN<BN)
{myN=0;myF=0;}
else if(myN==BN)
{
if(myF<=BF)
{myN=0;myF=0;}
}
int x=0;
for(x=0;x<5;x=x+1)
{
printf("%d",player[0][x]);
}
for(x=0;x<5;x=x+1)
{
printf("%d",player[1][x]);
}
for(x=0;x<5;x=x+1)
{
printf("%d",player[2][x]);
}
for(x=0;x<5;x=x+1)
{
printf("%d",player[3][x]);
}

printf("\n%d-%d",myF,myN);

char CC=0;
switch(myF)
{
case 1:
{
CC='C';break;
}
case 2:
{
CC='D';break;
}
case 3:
{
CC='H';break;
}
case 4:
{
CC='S';break;
}
}
FILE *write;
write=fopen(argv[2],"a");
fprintf(write,"Player%d ",name);
fprintf(write,"call ");
if(myF==0||myN==0)
fprintf(write,"pass\n");
else if(myF<5)
fprintf(write,"%c-%d\n",CC,myN);
else if(myF==5)
fprintf(write,"NT-%d\n",myN);
}/*end if喊牌*/

/*出牌*/
if(stage==2)
{
int declarer=0;
char *info;	
FILE *Board;
Board=fopen(argv[1],"r");
while(fscanf(Board,"%s",info)==1)	
{
if(strcmp(info,"Declarer")==0)
break;	
}/*end while*/	
fscanf(Board,"%s",info);
if(strcmp(info,"Player1")==0)
declarer=1;	
else if(strcmp(info,"Player2")==0)
declarer=2;
else if(strcmp(info,"Player3")==0)
declarer=3;
else if(strcmp(info,"Player4")==0)
declarer=4;/*讀取喊牌者*/

fseek(Board,0L,SEEK_SET);
while(fscanf(Board,"%s",info)==1)
{	
if(strcmp(info,"Contract")==0)break;	
}
fscanf(Board,"%s",info);

printf("\n\n\nopopop\n%d-%s",declarer,info);
int kingFlower=0;
char *king;
king=strtok(info,"-");
printf("%s",king);
if(strcmp(king,"S")==0)
   kingFlower=4;
else if(strcmp(king,"H")==0)
   kingFlower=3;
else if(strcmp(king,"D")==0)
   kingFlower=2;
else if(strcmp(king,"C")==0)
   kingFlower=1;
else if(strcmp(king,"NT")==0)
   kingFlower=5;
printf("%d",kingFlower);
int round=0;
fseek(Board,0L,SEEK_SET);
while(fscanf(Board,"%s",info)==1)
{
if(strcmp(info,"Round")==0)break;	
}
fscanf(Board,"%s",info);
round=atoi(info);
printf("\n\n%d",round);
FILE *Step;
Step=fopen(argv[2],"r");
/*判斷自己是第幾個出牌*/
while(fscanf(Step,"%s",info)==1)
{
if(strcmp(info,"Round")==0)	
{
 int pop=0;	
 fscanf(Step,"%s",info);
 pop=atoi(info);
 if(pop==round)
 break;	 
}
}/*endwhile*/
int myturn=0;
int BF1=0;
char *hhptr;
while(fscanf(Step,"%s",info)==1)
{if(myturn==1)
{
fscanf(Step,"%s",info);
hhptr=strtok(info,"-"); printf("cf=%s",hhptr);
 if(strcmp(hhptr,"S")==0)
 BF1=4;
 else if(strcmp(hhptr,"H")==0)
 BF1=3;
 else if(strcmp(hhptr,"D")==0)
 BF1=2;
 else if(strcmp(hhptr,"C")==0)
 BF1=1;


}
 if(strcmp(info,"play")==0)myturn=myturn+1;	
}


myturn=myturn+1;
printf("myturn=%d",myturn);
/*判斷自己是第幾個出牌*/
/*儲存這局以錢出過的牌數
 * int gcard[4][13];
 * fseek(Step,0L,SEEK_SET);
 * while(fscanf(Step,"%s",info)==1)
 * {
 * if(strcmp(info,"Round")==0)
 * break;	
 * }	
 * fscanf(Step,"%s",info);
 * while(fscanf(Step,"%s",info)==1)
 * {int jn=0;
 *  int jF=0;
 *   int jM=0;
 *   if(strcmp(info,"Player1")==0)	
 *   {jn=1;
 *    fscanf(Step,"%s",info);
 *     fscanf(Step,"%s",info);
 *      char *LP;
 *       LP=strtok(info,"-");
 *        if(strcmp(LP,"S")==0)
 *         jF=4;
 *          else if(strcmp(LP,"H")==0)
 *           jF=3;
 *            else if(strcmp(LP,"D")==0)
 *             jF=2;
 *              else if(strcmp(LP,"C")==0)
 *               jF=1;
 *                LP=strtok(NULL,"-");
 *                 jM=atoi(LP);
 *                  jM=jM-2;
 *                   if(jM==-1)
 *                    jM=12;
 *                     gcard[jF-1][jM]=jn;
 *                      
 *                      }
 *                      else if(strcmp(info,"Player2")==0)
 *                      {jn=2;
 *                       fscanf(Step,"%s",info);
 *                        fscanf(Step,"%s",info);
 *                         char *LP;
 *                          LP=strtok(info,"-");
 *                           if(strcmp(LP,"S")==0)
 *                            jF=4;
 *                             else if(strcmp(LP,"H")==0)
 *                              jF=3;
 *                               else if(strcmp(LP,"D")==0)
 *                                jF=2;
 *                                 else if(strcmp(LP,"C")==0)
 *                                  jF=1;
 *                                   LP=strtok(NULL,"-");
 *                                    jM=atoi(LP);
 *                                     jM=jM-2;
 *                                      if(jM==-1)
 *                                       jM=12;
 *                                        gcard[jF-1][jM]=jn;	
 *                                        }	
 *                                        else if(strcmp(info,"Player3")==0)
 *                                        {jn=3;
 *                                         fscanf(Step,"%s",info);
 *                                          fscanf(Step,"%s",info);
 *                                           char *LP;
 *                                            LP=strtok(info,"-");
 *                                             if(strcmp(LP,"S")==0)
 *                                              jF=4;
 *                                               else if(strcmp(LP,"H")==0)
 *                                                jF=3;
 *                                                 else if(strcmp(LP,"D")==0)
 *                                                  jF=2;
 *                                                   else if(strcmp(LP,"C")==0)
 *                                                    jF=1;
 *                                                     LP=strtok(NULL,"-");
 *                                                      jM=atoi(LP);
 *                                                       jM=jM-2;
 *                                                        if(jM==-1)
 *                                                         jM=12;
 *                                                          gcard[jF-1][jM]=jn;	
 *                                                          }
 *                                                          else if(strcmp(info,"Player4")==0)
 *                                                          {jn=4;
 *                                                           fscanf(Step,"%s",info);
 *                                                            fscanf(Step,"%s",info);
 *                                                             char *LP;
 *                                                              LP=strtok(info,"-");
 *                                                               if(strcmp(LP,"S")==0)
 *                                                                jF=4;
 *                                                                 else if(strcmp(LP,"H")==0)
 *                                                                  jF=3;
 *                                                                   else if(strcmp(LP,"D")==0)
 *                                                                    jF=2;
 *                                                                     else if(strcmp(LP,"C")==0)
 *                                                                      jF=1;
 *                                                                       LP=strtok(NULL,"-");
 *                                                                        jM=atoi(LP);
 *                                                                         jM=jM-2;
 *                                                                          if(jM==-1)
 *                                                                           jM=12;
 *                                                                            gcard[jF-1][jM]=jn;		
 *                                                                            }	
 *                                                                            	
 *                                                                            	}
 *                                                                            	儲存這局以錢出過的牌數失敗*/
int status2[4]={0};
/*儲存自己的手牌*/

fseek(Board,0L,SEEK_SET);
int Spade2[14]={0};
int Heart2[14]={0};
int Diamond2[14]={0};
int Club2[14]={0};
char hand2 [100];
char *tokenPtr2;
char *box2[13];
fB=fopen(argv[1],"r");

while(fscanf(Board,"%s",hand2)==1)
  {
  if(strncmp("Hand",hand2,4)==0)
  break;
  }
fscanf(Board,"%s",hand2);
tokenPtr2=strtok(hand2,",");

/*儲存手牌資料到陣列*/
int i2=0;
while(tokenPtr2!=NULL)
{
box[i2]=tokenPtr2;
i2++;
tokenPtr2=strtok(NULL,",");
}

int i22=0;
for(i22=0;i22<i2;i22++)
{
char F2[5];
int N2=0;
tokenPtr2=strtok(box[i22],"-");
strcpy(F2,tokenPtr2);

tokenPtr2=strtok(NULL,"-");
N2=atoi(tokenPtr2);

if(strcmp(F2,"S")==0)
Spade2[N2]=1;
if(strcmp(F2,"H")==0)
Heart2[N2]=1;
if(strcmp(F2,"D")==0)
Diamond2[N2]=1;
if(strcmp(F2,"C")==0)
Club2[N2]=1;


printf("%s-%d\n",F2,N2);
}

int k=1;
for(k=1;k<14;k++)
{
printf("%d\n",Spade2[k]);
}



		
/*儲存自己的手牌*/
int bbi=0;
status2[0]=Club2[1]+Club2[2]+Club2[3]+Club2[4]+Club2[5]+Club2[6]+Club2[7]+Club2[8]+Club2[9]+Club2[10]+Club2[11]+Club2[12]+Club2[13];
status2[1]=Diamond2[1]+Diamond2[2]+Diamond2[3]+Diamond2[4]+Diamond2[5]+Diamond2[6]+Diamond2[7]+Diamond2[8]+Diamond2[9]+Diamond2[10]+Diamond2[11]+Diamond2[12]+Diamond2[13];
status2[2]=Heart2[1]+Heart2[2]+Heart2[3]+Heart2[4]+Heart2[5]+Heart2[6]+Heart2[7]+Heart2[8]+Heart2[9]+Heart2[10]+Heart2[11]+Heart2[12]+Heart2[13];
status2[3]=Spade2[1]+Spade2[2]+Spade2[3]+Spade2[4]+Spade2[5]+Spade2[6]+Spade2[7]+Spade2[8]+Spade2[9]+Spade2[10]+Spade2[11]+Spade2[12]+Spade2[13];		
printf("OOOOO%d-%d-%d-%d",status2[0],status2[1],status2[2],status2[3]);

printf("fuck11");
int mylF=0;
int mylN=0;
/*出牌*/

printf("ffff");
int wu[4][13]={0};
if(Club2[1]==1)wu[0][12]=1;
if(Club2[2]==1)wu[0][0]=1;
if(Club2[3]==1)wu[0][1]=1;
if(Club2[4]==1)wu[0][2]=1;
if(Club2[5]==1)wu[0][3]=1;
if(Club2[6]==1)wu[0][4]=1;
if(Club2[7]==1)wu[0][5]=1;
if(Club2[8]==1)wu[0][6]=1;
if(Club2[9]==1)wu[0][7]=1;
if(Club2[10]==1)wu[0][8]=1;
if(Club2[11]==1)wu[0][9]=1;
if(Club2[12]==1)wu[0][10]=1;
if(Club2[13]==1)wu[0][11]=1;

if(Diamond2[1]==1)wu[1][12]=1;
if(Diamond2[2]==1)wu[1][0]=1;
if(Diamond2[3]==1)wu[1][1]=1;
if(Diamond2[4]==1)wu[1][2]=1;
if(Diamond2[5]==1)wu[1][3]=1;
if(Diamond2[6]==1)wu[1][4]=1;
if(Diamond2[7]==1)wu[1][5]=1;
if(Diamond2[8]==1)wu[1][6]=1;
if(Diamond2[9]==1)wu[1][7]=1;
if(Diamond2[10]==1)wu[1][8]=1;
if(Diamond2[11]==1)wu[1][9]=1;
if(Diamond2[12]==1)wu[1][10]=1;
if(Diamond2[13]==1)wu[1][11]=1;

if(Heart2[1]==1)wu[2][12]=1;
if(Heart2[2]==1)wu[2][0]=1;
if(Heart2[3]==1)wu[2][1]=1;
if(Heart2[4]==1)wu[2][2]=1;
if(Heart2[5]==1)wu[2][3]=1;
if(Heart2[6]==1)wu[2][4]=1;
if(Heart2[7]==1)wu[2][5]=1;
if(Heart2[8]==1)wu[2][6]=1;
if(Heart2[9]==1)wu[2][7]=1;
if(Heart2[10]==1)wu[2][8]=1;
if(Heart2[11]==1)wu[2][9]=1;
if(Heart2[12]==1)wu[2][10]=1;
if(Heart2[13]==1)wu[2][11]=1;

if(Spade2[1]==1)wu[3][12]=1;
if(Spade2[2]==1)wu[3][0]=1;
if(Spade2[3]==1)wu[3][1]=1;
if(Spade2[4]==1)wu[3][2]=1;
if(Spade2[5]==1)wu[3][3]=1;
if(Spade2[6]==1)wu[3][4]=1;
if(Spade2[7]==1)wu[3][5]=1;
if(Spade2[8]==1)wu[3][6]=1;
if(Spade2[9]==1)wu[3][7]=1;
if(Spade2[10]==1)wu[3][8]=1;
if(Spade2[11]==1)wu[3][9]=1;
if(Spade2[12]==1)wu[3][10]=1;
if(Spade2[13]==1)wu[3][11]=1;
printf("IAM%d",BF1);

if(myturn==1)
{
if(declarer==name)
{
 if(status2[kingFlower]>2)
 chB(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,kingFlower);
 else 
 { if(status2[3]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,4);
   if(status2[2]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,3);
   if(status2[1]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,2);
   if(status2[0]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,1);
  if(mylF==0)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,kingFlower);
 } 
}
else 
{
  if(status2[3]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,4);
   if(status2[2]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,3);
   if(status2[1]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,2);
   if(status2[0]!=0&&mylF!=kingFlower)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,1);
  if(mylF==0)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,kingFlower);
}
	
}/*endmyturn=1*/
else if(myturn==2||myturn==3||myturn==4)
{
  if(status2[BF1-1]==0)/*無指定花色*/
 { 
  if(status2[kingFlower-1]==0)/*無王牌花色*/
  {
  printf("無王無止");
  if(status2[3]!=0)   
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,4);
   if(status2[2]!=0)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,3);
   if(status2[1]!=0)
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,2);
   if(status2[0]!=0)	     
  chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,1);
  }	
   else if(status2[kingFlower-1]!=0)/*有王牌花色*/
   {
   printf("有王無只");chS(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,kingFlower);
		
   }   
  } 	  
 else if(status2[BF1-1]!=0)/*有指定花色*/
 {printf("有指");
  chB(&mylF,&mylN,Club2,Diamond2,Heart2,Spade2,BF1);
 }
}/*endmyturn=2*/	

printf("gggg");
/*出牌*/
/*寫牌*/
char TT=0;
if(mylF==1)
TT='C';
else if(mylF==2)
TT='D';
else if(mylF==3)
TT='H';
else if(mylF==4)
TT='S';
FILE *writ;
writ=fopen(argv[2],"a");
fprintf(writ,"Player%d ",name);
fprintf(writ,"play ");
fprintf(writ,"%c-%d\n",TT,mylN);



}/*end if出牌*/
return 0;
}


void judgeflower(int *Ss,int *Sc,int status[],int totalpoint,int Spadepoint,int Heartpoint,int Diamondpoint,int Clubpoint,int Spade[],int Heart[],int Diamond[],int Club[])
{
if(Spadepoint<4&&status[0]>=5)
*Ss=1;
else
*Ss=-1;
switch(Spadepoint)
{
case 4:
{
if(status[0]>=3)
*Ss=1;
if(status[0]>=5&&totalpoint>=8)
*Sc=1;
else if(status[0]>=5&&totalpoint>=14)
*Sc=2;
break;
}

case 5:
{
if(status[0]>=3)
*Ss=1;
if(status[0]>=5&&totalpoint>=8)
*Sc=1;
else if(status[0]>=5&&totalpoint>=14)
*Sc=2;
break;
}

case 6:
{
if(status[0]>=3)
*Ss=1;
if(Spade[13]==1)/*KQJ*/
{switch(status[0])
{
case 4:
{
if(totalpoint>14)
*Sc=1;break;
}
case 5:
{
if(totalpoint>14)
*Sc=2;break;
}
case 6:
{
if(totalpoint>14)
*Sc=2;break;
}
case 7:
{
if(totalpoint>14)
*Sc=3;break;
}
case 8:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>7)
*Sc=7;break;
}
case 9:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>7)
*Sc=7;break;
}
case 10:
{
*Sc=4;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>7)
*Sc=7;break;
}
case 11:
{
*Sc=5;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>7)
*Sc=7;break;
}
case 12:
{
*Sc=6;
int OA=Heart[1]+Diamond[1]+Club[1];
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;
break;
}
case 13:
{
*Sc=7;break;
}
}/*endswitch*/
}/*end if*/
if(Spade[1]==1)
{
switch(status[0])
{
case 5:
{
if(totalpoint>14)
*Sc=1;break;
}
case 6:
{
if(totalpoint>14)
*Sc=1;break;
}
case 7:
{
if(totalpoint>14)
*Sc=1;break;
}
case 8:
{
if(totalpoint>14)
*Sc=3;break;
}
case 9:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>6)
*Sc=6;break;
}
case 10:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 11:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}


}/*endswitch*/
}/*endif*/

break;
}/*endcase6*/

case 7:
{
if(status[0]>=3)
*Ss=1;
switch(status[0])
{
case 4:
{
if(totalpoint>14)
*Sc=1;break;
}
case 5:
{
if(totalpoint>13)
*Sc=2;break;
}
case 6:
{
if(totalpoint>13)
*Sc=2;break;
}
case 7:
{
if(totalpoint>13)
*Sc=2;break;
}
case 8:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(OA>0)
*Sc=*Sc-1;
if(*Sc>7)
*Sc=7;break;
}
case 9:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 10:
{
*Sc=4;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 11:
{
*Sc=5;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 12:
{
*Sc=6;
int OA=Heart[1]+Diamond[1]+Club[1];
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;
break;
}
case 13:
{
*Sc=7;break;
}

}
break;
}
case 8:
{
*Ss=1;
switch(status[0])
{
case 4:
{
if(totalpoint>14)
*Sc=1;break;
}
case 5:
{
if(totalpoint>13)
*Sc=2;break;
}
case 6:
{
if(totalpoint>13)
*Sc=2;break;
}
case 7:
{
if(totalpoint>13)
*Sc=3;break;
}
case 8:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA-1;
if(*Sc>7)
*Sc=7;break;
}
case 9:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 10:
{
*Sc=4;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 11:
{
*Sc=5;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 12:
{
*Sc=6;
int OA=Heart[1]+Diamond[1]+Club[1];
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;
break;
}
case 13:
{
*Sc=7;break;
}

}
break;
}/*endcase*/

case 9:
{
*Ss=1;
switch(status[0])
{
case 4:
{
if(totalpoint>14)
*Sc=2;
else
*Sc=1;break;
}
case 5:
{
if(totalpoint>12)
*Sc=2;
else
*Sc=1;break;
}
case 6:
{
if(totalpoint>12)
*Sc=2;
else
*Sc=1;break;
}
case 7:
{
if(totalpoint==9)
*Sc=3;
else if(totalpoint>9&&totalpoint<14)
*Sc=3;
else if(totalpoint>13)
*Sc=3;break;
}
case 8:
{
if(totalpoint==9)
*Sc=3;
else if(totalpoint>10&&totalpoint<14)
*Sc=4;
else if(totalpoint>14)
*Sc=4;break;
}
case 9:
{
*Sc=3;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 10:
{
*Sc=4;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
if(status[1]>=3)
OA=Heart[12]+OA;
if(status[2]>=3)
OA=Diamond[12]+OA;
if(status[3]>=3)
OA=Club[12]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 11:
{
*Sc=5;
int OA=Heart[1]+Diamond[1]+Club[1];
if(status[1]>=2)
OA=Heart[13]+OA;
if(status[2]>=2)
OA=Diamond[13]+OA;
if(status[3]>=2)
OA=Club[13]+OA;
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 12:
{
*Sc=6;
int OA=Heart[1]+Diamond[1]+Club[1];
*Sc=*Sc+OA;
if(*Sc>7)
*Sc=7;break;
}
case 13:
{
*Sc=7;break;
}
}break;
}

case 10:
{
*Ss=1;
*Sc=1;
switch(status[0])
{
case 4:
{
if(totalpoint>12)
*Sc=2;break;
}
case 5:
{
if(totalpoint>11&&totalpoint<15)
*Sc=2;
else if(totalpoint>14)
*Sc=3;break;
}
case 6:
{
*Sc=2;
if(totalpoint>12)
*Sc=3;break;
}
case 7:
{
*Sc=3;break;
}
case 8:
{
*Sc=4;break;
}
case 9:
{
*Sc=4;break;
}
case 10:
{
*Sc=5;break;
}
case 11:
{
*Sc=6;break;
}
case 12:
{
*Sc=6;break;
}
case 13:
{
*Sc=7;break;
}

}/*en*Sswitch*/
}/*endcase*/
break;
}/*endswitch*/

}/*Spade牌判斷*/
void choose(int *myF,int Sc,int Hc,int Dc,int Cc,int status[])/*選出自己最好的花色*/
{
if(Sc>Hc)
*myF=4;
else if(Sc=Hc)
{
if(status[0]>status[1])
*myF=4;
else if(status[0]==status[1])
*myF=3;
else if(status[0]<status[1])
*myF=3;
}
switch(*myF)
{
case 4:
{
if(Sc>Dc)
*myF=4;
else if(Sc=Dc)
{
if(status[0]>status[2])
*myF=4;
else if(status[0]==status[2])
*myF=2;
else if(status[0]<status[2])
*myF=2;
}
break;
}
case 3:
{
if(Hc>Dc)
*myF=3;
else if(Hc=Dc)
{
if(status[1]>status[2])
*myF=3;
else if(status[1]==status[2])
*myF=2;
else if(status[1]<status[2])
*myF=2;
}
break;
}
}
switch(*myF)
{
case 4:
{
if(Sc>Cc)
*myF=4;
else if(Sc=Cc)
{
if(status[0]>status[3])
*myF=4;
else if(status[0]==status[3])
*myF=1;
else if(status[0]<status[3])
*myF=1;
}
break;
}
case 3:
{
if(Hc>Cc)
*myF=3;
else if(Hc==Cc)
{
if(status[1]>status[3])
*myF=3;
else if(status[1]==status[3])
*myF=1;
else if(status[1]<status[3])
*myF=1;
}
break;
}
case 2:
{
if(Dc>Cc)
*myF=2;
else if(Dc==Cc)
{
if(status[2]>status[3])
*myF=2;
else if(status[2]==status[3])
*myF=1;
else if(status[2]<status[3])
*myF=1;
}
break;
}
}

if(Sc<=0&&Hc<=0&&Dc<=0&&Cc<=0)
*myF=0;
}

void chB (int *mylF,int *mylN,int Club2[],int Diamond2[],int Heart2[],int Spade2[],int Flower)
{
switch(Flower)	
{
case 1:
{
*mylF=1;	
if(Club2[1]==1)	
{*mylN=1;break;}	
if(Club2[13]==1)	
{*mylN=13;break;}
if(Club2[12]==1)	
{*mylN=12;break;}
if(Club2[11]==1)	
{*mylN=11;break;}
if(Club2[10]==1)	
{*mylN=10;break;}
if(Club2[9]==1)	
{*mylN=9;break;}
if(Club2[8]==1)	
{*mylN=8;break;}
if(Club2[7]==1)	
{*mylN=7;break;}
if(Club2[6]==1)	
{*mylN=6;break;}	
if(Club2[5]==1)	
{*mylN=5;break;}	
if(Club2[4]==1)	
{*mylN=4;break;}	
if(Club2[3]==1)	
{*mylN=3;break;}	
if(Club2[2]==1)	
{*mylN=2;break;}break;		
}
case 2:
{
*mylF=2;	
if(Diamond2[1]==1)	
{*mylN=1;break;}	
if(Diamond2[13]==1)	
{*mylN=13;break;}
if(Diamond2[12]==1)	
{*mylN=12;break;}
if(Diamond2[11]==1)	
{*mylN=11;break;}
if(Diamond2[10]==1)	
{*mylN=10;break;}
if(Diamond2[9]==1)	
{*mylN=9;break;}
if(Diamond2[8]==1)	
{*mylN=8;break;}
if(Diamond2[7]==1)	
{*mylN=7;break;}
if(Diamond2[6]==1)	
{*mylN=6;break;}	
if(Diamond2[5]==1)	
{*mylN=5;break;}	
if(Diamond2[4]==1)	
{*mylN=4;break;}	
if(Diamond2[3]==1)	
{*mylN=3;break;}	
if(Diamond2[2]==1)	
{*mylN=2;break;}break;		
}
case 3:
{
*mylF=3;	
if(Heart2[1]==1)	
{*mylN=1;break;}	
if(Heart2[13]==1)	
{*mylN=13;break;}
if(Heart2[12]==1)	
{*mylN=12;break;}
if(Heart2[11]==1)	
{*mylN=11;break;}
if(Heart2[10]==1)	
{*mylN=10;break;}
if(Heart2[9]==1)	
{*mylN=9;break;}
if(Heart2[8]==1)	
{*mylN=8;break;}
if(Heart2[7]==1)	
{*mylN=7;break;}
if(Heart2[6]==1)	
{*mylN=6;break;}	
if(Heart2[5]==1)	
{*mylN=5;break;}	
if(Heart2[4]==1)	
{*mylN=4;break;}	
if(Heart2[3]==1)	
{*mylN=3;break;}	
if(Heart2[2]==1)	
{*mylN=2;break;}break;		
}
case 4:
{
*mylF=4;	
if(Spade2[1]==1)	
{*mylN=1;break;}	
if(Spade2[13]==1)	
{*mylN=13;break;}
if(Spade2[12]==1)	
{*mylN=12;break;}
if(Spade2[11]==1)	
{*mylN=11;break;}
if(Spade2[10]==1)	
{*mylN=10;break;}
if(Spade2[9]==1)	
{*mylN=9;break;}
if(Spade2[8]==1)	
{*mylN=8;break;}
if(Spade2[7]==1)	
{*mylN=7;break;}
if(Spade2[6]==1)	
{*mylN=6;break;}	
if(Spade2[5]==1)	
{*mylN=5;break;}	
if(Spade2[4]==1)	
{*mylN=4;break;}	
if(Spade2[3]==1)	
{*mylN=3;break;}	
if(Spade2[2]==1)	
{*mylN=2;break;}break;		
}	
}/*endswitch*/	
}

void chS(int *mylF,int *mylN,int Club2[],int Diamond2[],int Heart2[],int Spade2[],int Flower)
{
switch(Flower)	
{
case 1:
{
*mylF=1;	
if(Club2[2]==1)	
{*mylN=2;break;}	
if(Club2[3]==1)	
{*mylN=3;break;}
if(Club2[4]==1)	
{*mylN=4;break;}
if(Club2[5]==1)	
{*mylN=5;break;}
if(Club2[6]==1)	
{*mylN=6;break;}
if(Club2[7]==1)	
{*mylN=7;break;}
if(Club2[8]==1)	
{*mylN=8;break;}
if(Club2[9]==1)	
{*mylN=9;break;}
if(Club2[10]==1)	
{*mylN=10;break;}	
if(Club2[11]==1)	
{*mylN=11;break;}	
if(Club2[12]==1)	
{*mylN=12;break;}	
if(Club2[13]==1)	
{*mylN=13;break;}	
if(Club2[1]==1)	
{*mylN=1;break;}break;		
}
case 2:
{
*mylF=2;	
if(Diamond2[2]==1)	
{*mylN=2;break;}	
if(Diamond2[3]==1)	
{*mylN=3;break;}
if(Diamond2[4]==1)	
{*mylN=4;break;}
if(Diamond2[5]==1)	
{*mylN=5;break;}
if(Diamond2[6]==1)	
{*mylN=6;break;}
if(Diamond2[7]==1)	
{*mylN=7;break;}
if(Diamond2[8]==1)	
{*mylN=8;break;}
if(Diamond2[9]==1)	
{*mylN=9;break;}
if(Diamond2[10]==1)	
{*mylN=10;break;}	
if(Diamond2[11]==1)	
{*mylN=11;break;}	
if(Diamond2[12]==1)	
{*mylN=12;break;}	
if(Diamond2[13]==1)	
{*mylN=13;break;}	
if(Diamond2[1]==1)	
{*mylN=1;break;}break;		
}
case 3:
{
*mylF=3;	
if(Heart2[2]==1)	
{*mylN=2;break;}	
if(Heart2[3]==1)	
{*mylN=3;break;}
if(Heart2[4]==1)	
{*mylN=4;break;}
if(Heart2[5]==1)	
{*mylN=5;break;}
if(Heart2[6]==1)	
{*mylN=6;break;}
if(Heart2[7]==1)	
{*mylN=7;break;}
if(Heart2[8]==1)	
{*mylN=8;break;}
if(Heart2[9]==1)	
{*mylN=9;break;}
if(Heart2[10]==1)	
{*mylN=10;break;}	
if(Heart2[11]==1)	
{*mylN=11;break;}	
if(Heart2[12]==1)	
{*mylN=12;break;}	
if(Heart2[13]==1)	
{*mylN=13;break;}	
if(Heart2[1]==1)	
{*mylN=1;break;}break;		
}
case 4:
{
*mylF=4;	
if(Spade2[2]==1)	
{*mylN=2;break;}	
if(Spade2[3]==1)	
{*mylN=3;break;}
if(Spade2[4]==1)	
{*mylN=4;break;}
if(Spade2[5]==1)	
{*mylN=5;break;}
if(Spade2[6]==1)	
{*mylN=6;break;}
if(Spade2[7]==1)	
{*mylN=7;break;}
if(Spade2[8]==1)	
{*mylN=8;break;}
if(Spade2[9]==1)	
{*mylN=9;break;}
if(Spade2[10]==1)	
{*mylN=10;break;}	
if(Spade2[11]==1)	
{*mylN=11;break;}	
if(Spade2[12]==1)	
{*mylN=12;break;}	
if(Spade2[13]==1)	
{*mylN=13;break;}	
if(Spade2[1]==1)	
{*mylN=1;break;}break;		
}	
}/*endswitch*/			
}

