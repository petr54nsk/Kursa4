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
FILE *fl;
int A[31]={},error=0,col=0,n=0;
char ch,k0=true,k1=true;
struct tm * timeinfo;
setlocale(LC_ALL, "Russian");
while (k0==true){
system("cls");
printf("1. Начать тестирование\n");
printf("2. Unit-Tests\n");
printf("3. Статистика\n");
printf("4. Выход из программы\n");
cout<<"Ваш выбор: ";
cin>>ch;

switch(ch) {
case '1':
		k1=true;
		system("cls");
		while (k1==true){
			system("cls");
			printf("1. Математика\n");
			printf("2. История\n");
			printf("3. Программирование\n");
			printf("4. Выход из тестирования\n");
			cout<<"Ваш выбор: ";
			cin>>ch;
			
		switch(ch) {
				case '1':
					system("cls");
					error=0;
					col=0;
						for(int i=0; i<31;i++){
							A[i]=0;
						}
						n=0;
					QTest(A,n);
					break;
					
				case '2':
					system("cls");
					error=0;
					col=0;
						for(int i=0; i<31;i++){
							A[i]=0;
						}
						n=1;
					QTest(A,n);
					break;
					
				case '3':
					system("cls");
					error=0;
					col=0;
						for(int i=0; i<31;i++){
							A[i]=0;
						}
						n=2;
					QTest(A,n);
					break;
					
				case '4':
					k1=false;
					fl=fopen("Statistics.txt","a+");
					fprintf(fl,"\n===========================================\n");
					fclose(fl);
					break;
					
				default:
					system("cls");
					printf("Твой выбор еще не сделан...\n");
					system("pause");
					break;
			}
		}
   break;
   
case '2':
   break;
   
case '3':
   break;
   
case '4':
	k0=false;
   break;
   
default:
	system("cls");
	printf("Твой выбор еще не сделан..\n");
	system("pause");
 	 }
	}
system ("PAUSE");
}
