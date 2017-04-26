#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include "Functions.cpp"

using namespace std;
//=============================
int main(){
srand(time(NULL));
int A[31]={},error=0,col=0;
char ch,k0=true,k1=true;
struct tm * timeinfo;
char buf[100];
setlocale(LC_ALL, "Russian");
while (k0==true){
system("cls");
printf("1. Начать тестирование\n");
printf("2. Unit-Tests\n");
printf("3. Статистика\n");
printf("4. Выход из программы\n");
cout<<"Ваш выбор: ";
cin>>ch;
	if(ch!='1' and ch!='2' and ch!='3' and ch!='4'){
		while(ch!='1' and ch!='2' and ch!='3' and ch!='4'){
			system("cls");
			printf("1. Начать тестирование\n");
			printf("2. Unit-Tests\n");
			printf("3. Статистика\n");
			printf("4. Выход из программы\n");
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
					error=0;
					col=0;
						for(int i=0; i<31;i++){
							A[i]=0;
						}
					matan(A,&error,&col);
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
   FILE *fl;//наЧАЛО функции
   time_t data;
   struct tm * timeinfo;
   char buf[100];
   time(&data);
   timeinfo = localtime(&data);
   strftime(buf,100,"Data:%x Time:%I:%M%p. ",timeinfo);
   fl=fopen("Statistics.txt","a+");
	   if(fl==NULL){
	   	printf("Файл не открыт.\n");
	   	break;
	   }
		else{
			printf("Файл открыт успешно.\n");
		}
		fputs(buf,fl);
		fprintf(fl,"\nМатематика:: Правильных ответов:%d Неправильных ответов:%d \nВопросы в которых допущена ошибка:",(col-error),error);
		for(int i=0;i<error;i++){
			fprintf(fl," №:%d",A[i+1]);
		}
		fprintf(fl,"\n===========================================\n");
		system("pause");
		fclose(fl);// Конец функции
   break;
   
case '4':
	k0=false;
   break;
   
default:
	printf("Твой выбор еще не сделан..\n");
 	 }
	}
system ("PAUSE");
}
