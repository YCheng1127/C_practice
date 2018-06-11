#include<stdio.h>
int main(void)
{
printf("歡迎使用Pizza點餐系統!\n");
int hereortogo;//儲存內用外帶的變數
int hereortogotry;//檢查內用外帶的變數是否輸入正確
int jump2;
printf("請輸入用餐方式編號==> 1.內用  2.外帶 :");
do{
scanf("%d",&hereortogo);//輸入內用或外帶
if(hereortogo==1||hereortogo==2)//檢查是否為1或0
hereortogotry=1;//輸入正確時將值改為1，才能跳出迴圈
else
printf("請輸入數值1或0:");
}while(hereortogotry!=1);//當沒有輸入正確時，不跳出迴圈
if(hereortogo==1)//顯示內用或外帶的結果
{printf("內用\n");}
else
{printf("外帶\n");}

int pizzamoney=0;//儲存pizza的錢

int pizzatype;//儲存pizza的種類的變數
int pizzatypetry;//檢查pizza種類是否輸入正確的變數

int ingredient;//儲存配料的種類的變數
int ingredienttry;//檢查配料種類是否輸入正確的變數
int ingredientmoney=0;//儲存配料的錢


int cheese=5;//儲存配料數量的變數
int sausage=5;
int octopus=5;
int pineapple=5;
int seaweed=5;

printf("\n");

do{
printf("以下是所有Pizza口味 :\n");
printf("編號:   1           2         3        4        5\n");
printf("      夏威夷   巧克力香蕉   蔬食   瑪格麗特   總匯\n");
printf("      NT 450     NT 380    NT 350   NT 380   NT 500\n");
printf("請輸入Pizza口味: ");

do{//獲得格式正確的pizza種類變數
pizzatypetry=0;//將檢查pizza格式是否輸入正確的變數歸零
scanf("%d",&pizzatype);
if(pizzatype==1||pizzatype==2||pizzatype==3||pizzatype==3||pizzatype==4||pizzatype==5)
pizzatypetry=1;//如果輸入正確，將pizzatype設為1，代表輸入格式正確
else
printf("請輸入數值1~5的整數: ");
}while(pizzatypetry!=1);//輸入格式正確，跳出迴圈

switch(pizzatype){//執行後續動作，將pizza種類對應的金錢加到pizzamoney
case 1:
pizzamoney=pizzamoney+450;
break;
case 2:
pizzamoney=pizzamoney+380;
break;
case 3:
pizzamoney=pizzamoney+380;
break;
case 4:
pizzamoney=pizzamoney+350;
break;
case 5:
pizzamoney=pizzamoney+500;
break;
}

printf("\n");

int jump=0;//判斷是否繼續加點配料所需的變數
do
{jump=0;
printf("\n");
printf("以下所有配料: \n");
printf("編號:    0         1      2     3      4      5\n");
printf("      不加配料   起司   香腸   章魚   鳳梨   海苔\n");
printf("                 NT 30  NT 35  NT 40  NT 20  NT 10\n");
printf("庫存:             %d       %d      %d      %d      %d\n",cheese,sausage,octopus,pineapple,seaweed);
printf("請選擇欲加點的pizza配料0~5: ");

do{
ingredienttry=0;//判斷輸入的指令是否可被執行所需的變數
int checknumber=0;//用來標示輸入的指令的情況 1.代表配料不足  2.代表蔬食pizza不可大配肉類配料
scanf("%d",&ingredient);
if(0==ingredient||ingredient==5||ingredient==1||ingredient==2||ingredient==3||ingredient==4)//如果指令格式正確，繼續檢查是否可被執行
{
switch(ingredient)//檢查所輸入的配料的情況
{
case 1: 
if(cheese==0)
checknumber=1;
break;
case 2:
if(sausage==0)
checknumber=1;
if(pizzatype==3)
checknumber=2;
break;
case 3:
if(octopus==0)
checknumber=1;
if(pizzatype==3)
checknumber=2;
break;
case 4:
if(pineapple==0)
checknumber=1;
break;
case 5:
if(seaweed==0)
checknumber=1;
break;
}
if(checknumber==0)//如果配料可供給，將ingredienttry改為1，才能退出迴圈
ingredienttry=1;
else if(checknumber==1)//1代表配料不足
printf("配料份量不足!請重新選擇其他配料: ");
else if(checknumber==2)//2代表不可搭配肉類
printf("蔬食Pizza不可搭配肉類!請重新選擇其他配料: ");
}
else//如果指令格式不正確，說明原因
printf("請重新輸入編號0~5: ");
}while(ingredienttry!=1);


switch(ingredient){//執行正確配料指令
case 0:
jump=1;//將jump改為1，代表不再加點配料
printf("不選擇配料\n");
printf("\n");
break;
case 1:
ingredientmoney=ingredientmoney+30;
cheese=cheese-1;
printf("加點起司配料一份\n");
break;
case 2:
ingredientmoney=ingredientmoney+35;
sausage=sausage-1;
printf("加點香腸配料一份\n");
break;
case 3:
ingredientmoney=ingredientmoney+40;
octopus=octopus-1;
printf("加點章魚配料一份\n");
break;
case 4:
ingredientmoney=ingredientmoney+20;
pineapple=pineapple-1;
printf("加點鳳梨配料一份\n");
break;
case 5:
ingredientmoney=ingredientmoney+10;
seaweed=seaweed-1;
printf("加點海苔配料一份\n");
break;
}

int addornot;
int addornottry;
if(jump!=1){//如果jump沒被修改成1，繼續問要不要加點
printf("是否加點配料? 1是 2否: ");

do
{
addornottry=0;
scanf("%d",&addornot);
if(addornot==1||addornot==2)
addornottry=1;
else
printf("請輸入正確數值1(是)或2(否): ");
}while(addornottry==0);

if(addornot==1)
{printf("繼續加點\n");
printf("\n");}
else if(addornot==2)
{printf("停止加點\n");
printf("\n");
jump=1;//代表不再加點
}
}
}while(jump==0);//當jump沒被修改，代表還想加點
jump2=0;//將判斷是否加點pizza=的變數歸零
int pizzamoreornot;//儲存是否加點pizza的變數
int pizzamoreornottry;//判斷是是否加點pizza的變數輸入是否正確的變數
printf("是否再加點PIZZA?: ");
do{
pizzamoreornottry=0;
scanf("%d",&pizzamoreornot);
if(pizzamoreornot==1||pizzamoreornot==2)
pizzamoreornottry=1;
else
printf("請輸入1(是)或2(否): ");

}while(pizzamoreornottry==0);//輸入格式不正確時

if(pizzamoreornot==2)//當不要加點pizza時，修改變數jump2
{jump2=1;
printf("不再加點Pizza\n\n");}
else
printf("繼續加點\n\n");
}while(jump2==0);//還要加點pizza時
int sum;
sum=ingredientmoney+pizzamoney;
if(sum>1000)
{sum=sum*0.9;
printf("消費總金額大於1000，享九折優惠!\n");

}
printf("總金額是:%d\n",sum);
}



