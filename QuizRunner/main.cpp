#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(){
int col;
char ch,k=true,f;
char qw[50], an1[30], an2[30], an3[30], anT[30],d[20],g[1];
setlocale(LC_ALL, "Russian");
while (k==true){
system("cls");
printf("1. Начать тестирование\n");
printf("2. Unit-Tests\n");
printf("3. Выход из программы\n");
cout<<"Ваш выбор: ";
cin>>ch;
	if(ch!='1' and ch!='2' and ch!='3'){
		while(ch!='1' and ch!='2' and ch!='3'){
			system("cls");
			printf("1. Начать тестирование\n");
			printf("2. Unit-Tests\n");
			printf("3. Выход из программы\n");
			cout<<"Ваш выбор: ";
			cin>>ch;
		}
	}
switch(ch) {
case '1':
	system("cls");
	FILE *fl;
	fl=fopen("Q.txt","r");
	while((f=fgetc(fl))!=EOF){
		if(f=='№'){
			g[0]=fgetc(fl);
			printf("%s\n",g);
			col=atoi(g);
			printf("%d",col);
		}
	}
	system("pause");
	fseek(fl,0,SEEK_SET);
	for(int i=0;i<2;i++){
	fgets(qw,50,fl);
		if(qw[1]=='/'){
		fgets(qw,50,fl);	
		}
	printf("%s",qw);
	fgets(an1,50,fl);
	printf("%s",an1);
	fgets(an2,50,fl);
	printf("%s",an2);
	fgets(an3,50,fl);
	printf("%s",an3);
	fgets(anT,50,fl);
	printf("%s\n",anT);
	cin>>d;
	if(d[0]==anT[6]){
		printf("YES!\n");
		}
	}
	fclose(fl);
	system("pause");
   break;
   
case '2':
   break;
   
case '3':
	k=false;
   break;
   
default:
	printf("Твой выбор еще не сделан..\n");
 	 }
	}
system ("PAUSE");
}
