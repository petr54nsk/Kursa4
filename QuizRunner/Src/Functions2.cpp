#include "Functions.h"
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
extern int g;

clock_t start, end;

RenderWindow Test(sf::VideoMode(1200, 700), "QuizRunner",Style::Titlebar);

int Stat(int *, int , int , int, int);

	int QTest(int *A, int n){

		start=clock();
		srand(time(NULL));
		char qw[300], an1[300], an2[300], an3[300], g[200];
		char f,d;
		int score=0,q=1,z=0,col=0,error=0;
		int m,dI,timeq;
		int M[3]={};
		float timeQ;
		FILE *fl;
		
		Font font;
		font.loadFromFile("arialbd.ttf");
		Texture fonT;
		fonT.loadFromFile("FonT.jpg");
		
		Sprite FonT;
		FonT.setTexture(fonT);
		FonT.setPosition(0,0);
		
		Text TestT;
		
		TextT.setFont(font);
		TextT.setString("NULL");			
		TextT.setCharacterSize(16);
		TextT.setColor(Color::Black);
		TextT.setPosition(492,225);
		
		if(n==0){fl=fopen("../Questions/Matan","r");}
		if(n==1){fl=fopen("../Questions/History","r");}
		if(n==2){fl=fopen("../Questions/Programm","r");}
		
		if(fl==NULL){
				printf("���� �� ��� ������.\n");
				system("pause");
				return 0;
			}
			
		while(Test.isOpen()){
			Event event_0;
			while (Test.pollEvent(event_0));
			if(!Test.hasFocus()){
				Test.requestFocus();
			}
			Test.clear();
			Test.draw(FonT);
			Test.display();
			while(!feof(fl)){
				Event event_1;
				while (Test.pollEvent(event_1));
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
				printf("��� ������ �� ������������ ������� 'Q'.\n");
				printf("������� �����:");
				d=getch();
				if(d=='q'){
					return 0;
				}
					while(d!='1' and d!='2' and d!='3'){
						d=getch();
				}
				dI=0;
				dI=dI*10+d-0x30;
				if(dI==z){
					score++;
					}
					else{
							error++;
							A[error]=i+1;
					}
			}
			end=clock();
			timeQ=((double) end - start) / ((double) CLOCKS_PER_SEC);
			timeq=(int)timeQ;
			system("cls");
			printf("����������� �����:%.1f ������\n",timeQ);
			printf("���������� ������:%d\n",score);
			if(score<((col/2)+1)){
				printf("���� ������ �� ���������� ���� �������� ������.\n");
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
			Stat(A,col,error,n,timeq);
			system("pause");
	}
}
	int Stat(int *A,int col, int error, int n, int timeq){
		   FILE *fl;
   			time_t data;
   			struct tm * timeinfo;
   			char buf[100];
   			time(&data);
   			timeinfo = localtime(&data);
   			strftime(buf,100,"Data:%x Time:%H.%M ",timeinfo);
   			fl=fopen("../Bin/Statistics","a+");
			   if(fl==NULL){
			   	printf("���� �� ������.\n");
			   	system("pause");
			   	return 0;
			   }
			   if(g==0){
				fputs(buf,fl);
				g++;
			  }
			  if(n==0){
			  fprintf(fl,"\n����������:: ");
			}
			else if(n==1){
			  fprintf(fl,"\n�������:: ");
			}
			else if(n==2){
			  fprintf(fl,"\n����������������:: ");
			}
			fprintf(fl,"���������� �������:%d|������������ �������:%d \n������� � ������� �������� ������:",(col-error),error);
				for(int i=0;i<error;i++){
					fprintf(fl," �:%d",A[i+1]);
				}
				fprintf(fl,"\n����� ����������� �� ����: %d ������.",timeq);
			fclose(fl);
}
