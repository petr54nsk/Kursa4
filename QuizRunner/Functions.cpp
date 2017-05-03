#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
using namespace std;
extern int g;

int Stat(int *, int , int , int);

	int QTest(int *A, int n){
		srand(time(NULL));
		char qw[300], an1[300], an2[300], an3[300], g[200];
		int score=0, M[3]={}, m, q=1,z=0,d=0,col=0,error=0;
		char f;
		FILE *fl;
		
		if(n==0){fl=fopen("Matan.txt","r");}
		if(n==1){fl=fopen("History.txt","r");}
		if(n==2){fl=fopen("Programm.txt","r");}
		
		if(fl==NULL){
				printf("Файл не был открыт.\n");
				system("pause");
				return 0;
		}
		while(!feof(fl)){
			f=fgetc(fl);
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
			printf("Введите ответ:");
			cin>>d;
				while(d!=1 and d!=2 and d!=3){
					printf("Введите ответ:");
					cin>>d;
			}
			if(d==z){
				score++;
				}
				else{
						error++;
						A[error]=i+1;
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
		if(error==0){
		}
			else{
			printf("Вопросы в которых допущена ошибка:");
				for(int i=1;i<error+1;i++){
					printf(" %d",A[i]);
					}
			}
		printf("\n");
		score=0;
		fclose(fl);
		Stat(A,col,error,n);
		system("pause");	
}
	int Stat(int *A,int col, int error, int n){
		   FILE *fl;
   			time_t data;
   			struct tm * timeinfo;
   			char buf[100];
   			time(&data);
   			timeinfo = localtime(&data);
   			strftime(buf,100,"Data:%x Time:%H.%M ",timeinfo);
   			fl=fopen("Statistics.txt","a+");
			   if(fl==NULL){
			   	printf("Файл не открыт.\n");
			   	system("pause");
			   	return 0;
			   }
			   if(g==0){
				fputs(buf,fl);
				g++;
			  }
			  if(n==0){
			  fprintf(fl,"\nМатематика:: ");
			}
			else if(n==1){
			  fprintf(fl,"\nИстория:: ");
			}
			else if(n==2){
			  fprintf(fl,"\nПрограммирование:: ");
			}
			fprintf(fl,"Правильных ответов:%d|Неправильных ответов:%d \nВопросы в которых допущена ошибка:",(col-error),error);
				for(int i=0;i<error;i++){
					fprintf(fl," №:%d",A[i+1]);
				}
			fclose(fl);
}
