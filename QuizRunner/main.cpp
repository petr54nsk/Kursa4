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
printf("1. ������ ������������\n");
printf("2. Unit-Tests\n");
printf("3. ����������\n");
printf("4. ����� �� ���������\n");
cout<<"��� �����: ";
cin>>ch;
	if(ch!='1' and ch!='2' and ch!='3' and ch!='4'){
		while(ch!='1' and ch!='2' and ch!='3' and ch!='4'){
			system("cls");
			printf("1. ������ ������������\n");
			printf("2. Unit-Tests\n");
			printf("3. ����������\n");
			printf("4. ����� �� ���������\n");
			cout<<"��� �����: ";
			cin>>ch;
		}
	}
switch(ch) {
case '1':
		system("cls");
		while (k1==true){
			system("cls");
			printf("1. ����������\n");
			printf("2. �������\n");
			printf("3. ����� �� ������������\n");
			cout<<"��� �����: ";
			cin>>ch;
				if(ch!='1' and ch!='2' and ch!='3'){
					while(ch!='1' and ch!='2' and ch!='3'){
						system("cls");
						printf("1. ����������\n");
						printf("2. �������\n");
						printf("3. ����� �� ������������\n");
						cout<<"��� �����: ";
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
   FILE *fl;//������ �������
   time_t data;
   struct tm * timeinfo;
   char buf[100];
   time(&data);
   timeinfo = localtime(&data);
   strftime(buf,100,"Data:%x Time:%I:%M%p. ",timeinfo);
   fl=fopen("Statistics.txt","a+");
	   if(fl==NULL){
	   	printf("���� �� ������.\n");
	   	break;
	   }
		else{
			printf("���� ������ �������.\n");
		}
		fputs(buf,fl);
		fprintf(fl,"\n����������:: ���������� �������:%d ������������ �������:%d \n������� � ������� �������� ������:",(col-error),error);
		for(int i=0;i<error;i++){
			fprintf(fl," �:%d",A[i+1]);
		}
		fprintf(fl,"\n===========================================\n");
		system("pause");
		fclose(fl);// ����� �������
   break;
   
case '4':
	k0=false;
   break;
   
default:
	printf("���� ����� ��� �� ������..\n");
 	 }
	}
system ("PAUSE");
}
