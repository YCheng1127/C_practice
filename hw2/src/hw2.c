#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct mrlist{//儲存資料的單位
int ID;
char type;
int price;
int day;
int yield;
struct mrlist *nextfrog;//只像自己這種單位的POINTER
};

void printlist(struct mrlist (*first))//印出清單
{
if(first==NULL){
printf("空的\n");
}
else{
printf("清單: \n");
while(first!=NULL){
printf("%d %c %d %d %d\n",(*first).ID,(*first).type,(*first).price,(*first).day,(*first).yield);
first=(*first).nextfrog;
}
}
}


//插入數值
void insert(struct mrlist **first, int I, char ty, int pri, int da, int yiel)
{
struct mrlist *curfrog;
struct mrlist *prefrog;
struct mrlist *newfrog;

newfrog=malloc(sizeof(struct mrlist));
if(newfrog!=NULL){
(*newfrog).ID=I;
(*newfrog).type=ty;
(*newfrog).price=pri;
(*newfrog).day=da;
(*newfrog).yield=yiel;
(*newfrog).nextfrog=NULL;

prefrog=NULL;
curfrog=*first;
while(curfrog!=NULL&&(*curfrog).nextfrog!=NULL)
{prefrog=curfrog;
curfrog=(*curfrog).nextfrog;}

if(prefrog==NULL&&curfrog==NULL)
{(*newfrog).nextfrog=*first;
*first=newfrog;
}
else{
(*curfrog).nextfrog=newfrog;
}
}
else{
printf("無法新增資料，記憶體不足");

}
}
//數數看有幾個作物的函示
int count(struct mrlist **start)
{
int num=0;
if(*start==NULL)
return 0;
else if(*start!=NULL&&(**start).nextfrog==NULL)
return 1;
else if(*start!=NULL&&(**start).nextfrog!=NULL)
num=num=1;
num=num+count(&((**start).nextfrog));
return num;
}
//以收成天數從小到大排列
void Daystbsort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).day>(*cnfrog).day)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}
//以售價從小到大排列
void Pricestbsort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).price>(*cnfrog).price)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}

//油產量從小到大排列
void Yieldstbsort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).yield>(*cnfrog).yield)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}
//由代號從小到大排列
void IDstbsort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).ID>(*cnfrog).ID)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}
//由種類從大到小排列
void Tystbsort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).type>(*cnfrog).type)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}

//由收成天數由大到小排列
void Daybtssort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).day<(*cnfrog).day)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}
//由售價從大到小排列
void Pricebtssort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).price<(*cnfrog).price)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}

//由產量由大到小排列
void Yieldbtssort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).yield<(*cnfrog).yield)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}

//由代號從大到小排列
void IDbtssort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).ID<(*cnfrog).ID)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}
//由種類由大到小排列
void Tybtssort(struct mrlist **first)
{
struct mrlist *cpfrog;
struct mrlist *curfrog;
struct mrlist *cnfrog;
struct mrlist *blank;

blank=malloc(sizeof(struct mrlist));
int i;
int j;
int round=0;
round=count(&(*first));

for(i=1;i<round;i=i+1)
{
curfrog=*first;
cnfrog=(*curfrog).nextfrog;
cpfrog=blank;
cpfrog=blank;
for(j=1;j<round;j=j+1)
{
if((*curfrog).type<(*cnfrog).type)
{
(*cpfrog).nextfrog=cnfrog;
(*curfrog).nextfrog=(*cnfrog).nextfrog;
(*cnfrog).nextfrog=curfrog;

if(j==1)
{*first=cnfrog;}
cpfrog=cnfrog;
cnfrog=(*curfrog).nextfrog;
}
else
{
cpfrog=curfrog;
curfrog=cnfrog;
cnfrog=(*cnfrog).nextfrog;}
}
}
free(blank);
}

//檢查是否在清單中有此作物
int Dcheck(struct mrlist **start, int I, char ty, int pri,int da,int yiel)
{
int a=0;
if(*start==NULL)
return 0;
else
{
if((**start).ID==I&&(**start).type==ty&&(**start).price==pri&&(**start).day==da&&(**start).yield==yiel)
return 1;
else
{
if((**start).nextfrog!=NULL)
{a=a+check(&((**start).nextfrog),I,ty,pri,da,yiel);
return a;}
else
return 0;
}
}
}

//檢查清單中是否有此代號
int check(struct mrlist **start, int I)
{
int a=0;
if(*start==NULL)
return 0;
else
{
if((**start).ID==I)
return 1;
else 
{
if((**start).nextfrog!=NULL)
{a=a+check(&((**start).nextfrog),I);
return a;}
else
return 0;
}
}
}
//清空清單
void clear(struct mrlist **start)
{
struct mrlist *boxfrog;
if((**start).nextfrog==NULL)
{boxfrog=*start;
*start=NULL;
free(boxfrog);
}
else
{clear(&(**start).nextfrog);
boxfrog=*start;
*start=NULL;
free(boxfrog);
}
}
//推薦作物
void recommend(struct mrlist **first, char T, int D)
{int Bignum=0;
int profit;
struct mrlist *curfrog;
struct mrlist *catch;
int time;
curfrog=*first;
catch=*first;
if(*first==NULL)
printf("沒有可推薦的作物\n");
else
{
while(curfrog!=NULL)
{
if((*curfrog).type==T)
{
time=D/((*curfrog).day);
profit=time*((*curfrog).price)*((*curfrog).yield);
if(Bignum<=profit)
Bignum=profit;
}
if((*curfrog).nextfrog!=NULL);
curfrog=(*curfrog).nextfrog;
}
if(Bignum==0)
printf("沒有在條件下可獲利的作物");
else
{

while(catch!=NULL)
{
time=D/((*catch).day);
profit=time*((*catch).price)*((*catch).yield);
if(profit==Bignum&&((*catch).type==T))
{
printf("栽種天數:%d 收成天數:%d 可收成次數:%d\n",D,(*catch).day,time);
if((*catch).type=='F')
printf("代碼:%d 類型:水果 售價:%d 收成天數:%d 產量:%d\n",(*catch).ID,(*catch).price,(*catch).day,(*catch).yield);
if((*catch).type=='B')
printf("代碼:%d 類型:花卉 售價:%d 收成天數:%d 產量:%d\n",(*catch).ID,(*catch).price,(*catch).day,(*catch).yield);
if((*catch).type=='V')
printf("代碼:%d 類型:蔬菜 售價:%d 收成天數:%d 產量:%d\n",(*catch).ID,(*catch).price,(*catch).day,(*catch).yield);
}
if((*catch).nextfrog!=NULL);
catch=(*catch).nextfrog;
}
}
}
}
//檢查輸入的資料示芣符合格式
int checkinput()
{
char hs;
int N=1;
while(((hs=getchar())!='\n')&&hs!=EOF)
N=0;

return N;
}
//刪除資料
void delete(struct mrlist **first, int I, char ty, int pri, int da, int yiel)
{
struct mrlist *prefrog;
struct mrlist *curfrog;
struct mrlist *boxfrog;
if(*first!=NULL)
{//printf("%d %c %d %d %d\n",(**first).ID,(**first).type,(**first).price,(**first).day,(**first).yield);
if((I==(**first).ID)&&(ty==(**first).type)&&(pri==(**first).price)&&(da==(**first).day)&&(yiel==(**first).yield))
{
boxfrog=*first;
*first=(**first).nextfrog;
free(boxfrog);
return 1;
}
else
{
prefrog=*first;
curfrog=(**first).nextfrog;
int button=0;
if((I==(*curfrog).ID)&&(ty==(*curfrog).type)&&(pri==(*curfrog).price)&&(da==(*curfrog).day)&&(yiel==(*curfrog).yield))
button=1;
while(curfrog!=NULL&&button==0)
{prefrog=curfrog;
curfrog=(*curfrog).nextfrog;
if((I==(*curfrog).ID)&&(ty==(*curfrog).type)&&(pri==(*curfrog).price)&&(da==(*curfrog).day)&&(yiel==(*curfrog).yield))
button=1;
}
if(curfrog!=NULL)
{
boxfrog=curfrog;
(*prefrog).nextfrog=(*curfrog).nextfrog;
free(boxfrog);
return 1;
}
else
return 0;
}
}
else
return 0;
}




int main(void)
{
struct mrlist *firlistfrog;
firlistfrog=NULL;
int size=100;
int over=0;//跳出程式所需的變數
char sortway;//儲存使用者輸入的分類分示
char sorttype;//儲存使用者輸入的分類種類
int pass=0;
char AA[size];
int UID=0;//儲存使用者輸入的代號
char Utype=0;//儲存使用者輸入的職種類
int Uprice=0;//儲存使用者輸入的售價
int Uday=0;//儲存使用者輸入的收成天數
int Uyield=0;//儲存使用者輸入的產量
int mistake=0;//監察輸入資料格式正確所需的變數
int store;
//測試用
//insert(&firlistfrog,1,'B',1,1,1);
//delete(&firlistfrog,1,'B',1,1,1);
//insert(&firlistfrog,1,'B',2,3,4);
//insert(&firlistfrog,2,'B',3,4,5);
//insert(&firlistfrog,3,'B',4,5,6);
//insert(&firlistfrog,4,'B',5,6,7);
//insert(&firlistfrog,5,'B',6,7,8);
//insert(&firlistfrog,6,'B',7,8,1);
//insert(&firlistfrog,7,'B',8,1,2);
//insert(&firlistfrog,8,'B',1,2,3);
//printlist(firlistfrog);
//IDbtssort(&firlistfrog);
//printlist(firlistfrog);
//Tybtssort(&firlistfrog);
//printlist(firlistfrog);
//Pricebtssort(&firlistfrog);
//printlist(firlistfrog);
//Daybtssort(&firlistfrog);
//printlist(firlistfrog);
//Yieldbtssort(&firlistfrog);
//printlist(firlistfrog);
//recommend(&firlistfrog,'B',100);
//clear(&firlistfrog);
//printlist(firlistfrog);


do{
printf("歡迎使用作物清單管理系統~\n");

printf("請輸入功能編號:");


do
{
scanf("%s",AA);
if((strcmp(AA,"1")==0)||(strcmp(AA,"2")==0)||(strcmp(AA,"3")==0)||(strcmp(AA,"4")==0)||(strcmp(AA,"5")==0)||(strcmp(AA,"6")==0))
pass=1;
else
printf("請重新輸入正確的指令:");
}while(pass==0);
store=atoi(AA);

switch(store)
{
case 2:
{
do{
printf("新增作物\n");
printf("請輸入指令(A:新增作物 B:回到主選單):");
char sww[size];
pass=0;
do
{
scanf("%s",sww);
if((strcmp(sww,"A"))==0||(strcmp(sww,"B")==0))
pass=1;
else
printf("請輸入正確指令:");
}while(pass==0);

if(strcmp(sww,"B")==0)
break;
else
{
printf("請輸入欲新增作物的資訊(example:1-d-1-1-1):");

do
{
mistake=0;
scanf("%d-%c-%d-%d-%d",&UID,&Utype,&Uprice,&Uday,&Uyield);
mistake=checkinput();
if(mistake==0)
printf("請輸入正確格式:");
if(mistake==1)
{if(Utype!='B'&&Utype!='F'&&Utype!='V')
{printf("請輸入正確格式:");
mistake=0;}
else if(check(&firlistfrog,UID)!=0)
{printf("此作物已經存在清單中，請重新輸入:");
mistake=0;}
}

}while(mistake==0);

insert(&firlistfrog,UID,Utype,Uprice,Uday,Uyield);
printlist(firlistfrog);
}}while(1==1);
break;}

case 1:
{do{
printlist(firlistfrog);
printf("檢視清單\n");
printf("請輸入指令(A:改變排列方式 B:回到主選單):");
char sww[size];
fflush(stdin);
pass=0;
do
{
scanf("%s",sww);
if((strcmp(sww,"A"))==0||(strcmp(sww,"B")==0))
pass=1;
else
printf("請輸入正確指令:");
}while(pass==0);

if(strcmp(sww,"B")==0)
break;
else
{
printf("請輸入排列方式(example: P-I):");
sorttype='\0';sortway='\0';mistake=0;;
do
{
scanf("%c-%c",&sorttype,&sortway);
mistake=checkinput();
}while(mistake==0);

if(sortway=='I')
{
switch(sorttype)
{
case 'N':
{IDstbsort(&firlistfrog);break;}
case 'T':
{Tystbsort(&firlistfrog);break;}
case 'P':
{Pricestbsort(&firlistfrog);break;}
case 'D':
{Daystbsort(&firlistfrog);break;}
case 'Y':
{Yieldstbsort(&firlistfrog);break;}
}
}
else if(sortway=='D')
{
switch(sorttype)
{
case 'N':
{IDbtssort(&firlistfrog);break;}
case 'T':
{Tybtssort(&firlistfrog);break;}
case 'P':
{Pricebtssort(&firlistfrog);break;}
case 'D':
{Daybtssort(&firlistfrog);break;}
case 'Y':
{Yieldbtssort(&firlistfrog);break;}
}
}
printlist(firlistfrog);
}}while(1==1);
break;
}
case 3:
{do{
printf("刪除作物\n");
printf("請輸入指令(A:刪除作物 B:回到主選單):");
char sww[size];
pass=0;
do
{
scanf("%s",sww);
if((strcmp(sww,"A"))==0||(strcmp(sww,"B")==0))
pass=1;
else
printf("請輸入正確指令:");
}while(pass==0);
if(strcmp(sww,"B")==0)
break;
else
{
printf("請輸入欲刪除作物的資訊(example:1-d-1-1-1):");
do
{
mistake=0;
scanf("%d-%c-%d-%d-%d",&UID,&Utype,&Uprice,&Uday,&Uyield);
mistake=checkinput();
if(mistake==0)
printf("請輸入正確格式:");
if(mistake==1)
{if(Utype!='B'&&Utype!='F'&&Utype!='V')
{printf("請輸入正確格式:");
mistake=0;}
else if((Dcheck(&firlistfrog,UID,Utype,Uprice,Uday,Uyield))==0)
{printf("此作物不存在清單中，請重新輸入:");
mistake=0;}
}
}while(mistake==0);}
delete(&firlistfrog,UID,Utype,Uprice,Uday,Uyield);

}while(1==1);

}

case 4:
{
clear(&firlistfrog);
break;
}
case 5:
{
do{
printf("推薦作物\n");
printf("請輸入指令(A:輸入需求 B:回到主選單):");
char sww[size];
pass=0;
do
{
scanf("%s",sww);
if((strcmp(sww,"A"))==0||(strcmp(sww,"B")==0))
pass=1;
else
printf("請輸入正確指令:");
}while(pass==0);

if(strcmp(sww,"B")==0)
break;
else
{
printf("請輸入需求(example: F-8):");

do
{
mistake=0;
scanf("%c-%d",&Utype,&Uday);
mistake=checkinput();
if(mistake==0)
printf("請輸入正確格式:");
if(mistake==1)
{if(Utype!='B'&&Utype!='F'&&Utype!='V')
{printf("請輸入正確格式:");
mistake=0;}
}

}while(mistake==0);

recommend(&firlistfrog,Utype,Uday);
}}while(1==1);
}
case 6:
{over=1;
break;}

}}while(over==0);
}

