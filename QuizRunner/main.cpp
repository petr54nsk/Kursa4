#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;
//=============================
int matan();
//===========================
int main(){
srand(time(NULL));
char ch,k0=true,k1=true;
setlocale(LC_ALL, "Russian");
while (k0==true){
system("cls");
printf("1. ������ ������������\n");
printf("2. Unit-Tests\n");
printf("3. ����� �� ���������\n");
cout<<"��� �����: ";
cin>>ch;
	if(ch!='1' and ch!='2' and ch!='3'){
		while(ch!='1' and ch!='2' and ch!='3'){
			system("cls");
			printf("1. ������ ������������\n");
			printf("2. Unit-Tests\n");
			printf("3. ����� �� ���������\n");
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
	printf("���� ����� ��� �� ������..\n");
 	 }
	}
system ("PAUSE");
}

int matan(){
	srand(time(NULL));
	char qw[300], an1[300], an2[300], an3[300], g[200];
	int col=0, score=0, error=0, M[3]={}, A[31], m, q=1,z=0,d=0;
	char f;
	FILE *fl;
	fl=fopen("Matan.txt","r");
	if(fl!=NULL){
		printf("���� ������� ������.\n");
		system("pause");
	}
		else{
			printf("���� �� ��� ������.\n");
			system("pause");
			return 0;
		}
	while(!feof(fl)){
		f=fgetc(fl);
		if(f=='�'){
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
	fseek(fl,2,SEEK_CUR);
	fgets(an1,300,fl);
	fseek(fl,2,SEEK_CUR);
	fgets(an2,300,fl);
	fseek(fl,2,SEEK_CUR);
	fgets(an3,300,fl);
		while(q!=4){
			m=rand()%3+1;
			if(m==1){
				if(M[0]==0){
					printf("%i.%s",q,an1);
					M[0]=1;
					z=q;
					q++;
				}
			}
			else if(m==2){
				if(M[1]==0){
					printf("%i.%s",q,an2);
					M[1]=1;
					q++;
				}
			}
			else if(m==3){
				if(M[2]==0){
					printf("%i.%s",q,an3);
					M[2]=1;
					q++;
				}
			}
		}
		for(int k=0;k<3;k++){
			M[k]=0;
		}
		q=1;
		printf("������� �����:");
		cin>>d;
			while(d!=1 and d!=2 and d!=3){
				printf("������� �����:");
				cin>>d;
		}
		if(d==z){
			score++;
			}
			else{
					error++;
					A[error]=i+1;
			}
			printf("Element:%d\n Error: %d",error,A[error]);
			system("pause");
	}
	system("cls");
	printf("���������� ������:%d\n",score);
	if(score<(col/2)){
		printf("���� ������ �� ���������� ���� ��������.\n");
	}
		else if (score>(col/2) && score<col-(col/4)){
			printf("���� ������ �� ���������� �������� ������.\n");
		}
			else{
				printf("���� ������ �� ���������� �������� ������.\n");
			}
	if(error==0){
	}
		else{
		printf("������� � ������� �������� ������:");
			for(int i=1;i<error+1;i++){
				printf(" %d",A[i]);
				}
		}
	printf("\n");
	score=0;
	fclose(fl);
	system("pause");	
}
