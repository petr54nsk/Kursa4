#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include "Functions.cpp"
int g=0;
using namespace std;
//=============================
int main(){
srand(time(NULL));
FILE *fl;
int A[31]={},error=0,col=0,n=0,j=0,w=0;
char ch,k0=true,k1=true,k2=true,buf[225];
struct tm * timeinfo;
setlocale(LC_ALL, "Russian");
while (k0==true){
system("cls");
printf("1. ������ ������������\n");
printf("2. Unit-Tests\n");
printf("3. ����������\n");
printf("4. ����� �� ���������\n");
cout<<"��� �����: ";
ch=getch();

switch(ch) {
case '1':
		k1=true;
		system("cls");
		while (k1==true){
			system("cls");
			printf("1. ����������\n");
			printf("2. �������\n");
			printf("3. ����������������\n");
			printf("4. ����� �� ������������\n");
			cout<<"��� �����: ";
			ch=getch();
			
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
					j=1;
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
					j=1;
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
					j=1;
					break;
					
				case '4':
					k1=false;
					break;
					
				default:
					system("cls");
					printf("���� ����� ��� �� ������...\n");
					system("pause");
					break;
			}
		}
 
case '2':
   break;
   
case '3':
		k2=true;
		while(k2==true){
			system("cls");
			printf("1. �������� ����������.\n");
			printf("2. ������� ����������.\n");
			printf("3. ��������� �����.\n");
			cout<<"��� �����: ";
			ch=getch();	
				switch(ch){
					case '1':
							system("cls");
							fl=fopen("./Bin/Statistics","r");
							if(fl==NULL){
								printf("������ ���������� ��� ����.\n");
								system("pause");
								break;
							}
							while(!feof(fl)){
								fgets(buf,220,fl);
								if(!feof(fl)){
									printf("%s",buf);
										if(buf[3]=='='){
											printf("��� ������ ������� 'Q'.\n��� ����������� ������� ������� 'N'.");
											w=0;
											while(1){
											ch=getch();
												if(ch=='q'){
														w=1;
														break;
													}
												if(ch=='n'){
													break;
												}
											}
											if(w==1){
												break;
											}
											system("cls");
										}
								}
								if(feof(fl)){
										system("pause");
										}
							}
							fclose(fl);
						   break;
						   
					case '2':
							remove("./Bin/Statistics");
							system("cls");
							printf("���������� ��������.\n");
							system("pause");
							break;
							
					case '3':
							k2=false;
							break;
							
					default: 
							system("cls");
							printf("����� �����....\n");
							system("pause");
							break;
						}
				}
			break;
case '4':
	k0=false;
	if(j==1){
		fl=fopen("./Bin/Statistics","a+");
		fprintf(fl,"\n===========================================\n");
		fclose(fl);
		}
   break;
   
default:
	system("cls");
	printf("���� ����� ��� �� ������..\n");
	system("pause");
	break;
 	   }
	}
}
