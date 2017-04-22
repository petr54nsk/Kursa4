#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;
int matan();
int main(){
char ch,k0=true,k1=true;
setlocale(LC_ALL, "Russian");
while (k0==true){
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
		while (k1==true){
			system("cls");
			printf("1. Математика\n");
			printf("2. История\n");
			printf("3. Выход из тестирования\n");
			cout<<"Ваш выбор: ";
			cin>>ch;
				if(ch!='1' and ch!='2' and ch!='3'){
					while(ch!='1' and ch!='2' and ch!='3'){
						system("cls");
						printf("1. Математика\n");
						printf("2. История\n");
						printf("3. Выход из тестирования\n");
						cout<<"Ваш выбор: ";
						cin>>ch;
						}
					}
		switch(ch) {
				case '1':
					system("cls");
					matan();
					break;
				case '2':
					break;
				case '3':
					k1=false;
					break;
				default:
					break;
			}
		}
   break;
   
case '2':
   break;
   
case '3':
	k0=false;
   break;
   
default:
	printf("Твой выбор еще не сделан..\n");
 	 }
	}
system ("PAUSE");
}

int matan(){
	char qw[300], an1[300], an2[300], an3[300], anT[30],d[20],g[200];
	int col=0,score=0,A[30],error=0,er=0;
	char f;
	FILE *fl;
	fl=fopen("Matan.txt","r");
	while((f=fgetc(fl))!=EOF){
		if(f=='№'){
		col++;
		}
	}
	fseek(fl,0,SEEK_SET);
	for(int i=0;i<col;i++){
	fgets(qw,300,fl);
		if(qw[1]=='#'){
		fgets(qw,300,fl);	
		}
		system("cls");
	printf("%s",qw);
	fgets(an1,300,fl);
	printf("%s",an1);
	fgets(an2,300,fl);
	printf("%s",an2);
	fgets(an3,300,fl);
	printf("%s",an3);
	fgets(anT,300,fl);
	printf("Введите ответ:");
	cin>>d[0];
		while(d[0]!='1' and d[0]!='2' and d[0]!='3'){
		printf("Введите ответ:");
		cin>>d[0];
	}
	if(d[0]==anT[6]){
		score++;
		}
		else{
					A[er]=i+1;
					error++;
					er++;
		}
	}
	system("cls");
	printf("Количество баллов:%d\n",score);
	if(score<(col/2)){
		printf("Ваши знания по математике ниже среднего.\n");
	}
	else if (score>(col/2) && score<col-(col/4)){
		printf("Ваши знания по математике среднего уровня.\n");
	}
	else{
		printf("Ваши знания по математике высокого уровня.\n");
	}
	printf("Вопросы в которых допущена ошибка:");
	for(int i=0; i<error;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
	score=0;
	fclose(fl);
	system("pause");	
}
