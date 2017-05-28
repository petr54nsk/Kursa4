#include "Functions.h"
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
extern int g;

clock_t start, end;

int Stat(int *, int , int , int, int);

	int QTest(int *A, int n){
		RenderWindow Test(sf::VideoMode(1200, 700), "QuizRunner",Style::Titlebar);
		start=clock();
		srand(time(NULL));
		char qw[300], an1[300], an2[300], an3[300], g[200];
		char f,d;
		int score=0,q=1,z=0,col=0,error=0;
		int m,dI,timeq;
		int M[3]={};
		float timeQ,y=230;
		FILE *fl;
//////////////////////////////
ContextSettings settings;

settings.antialiasingLevel = 8;
/////////////////////////////
		Color Tcolor(0,191,255);
///////////////////////////////////////////////		
		Font font;
		
		font.loadFromFile("arialbd.ttf");
/////////////////////////////////////////////		
		Texture fonT,message,button;
		
		fonT.loadFromFile("FonT.jpg");
		message.loadFromFile("message.jpg");
		button.loadFromFile("Button2.png");
/////////////////////////////////////////////		
		Sprite FonT,Message,Button1,Button2,Button3;
		
		FonT.setTexture(fonT);
		FonT.setPosition(0,0);
		
		Message.setTexture(message);
		Message.setPosition(0,0);
		
		Button1.setTexture(button);
		Button1.scale(Vector2f(0.2f,0.08f));
		Button1.setPosition(370,330);
	
		Button2.setTexture(button);
		Button2.scale(Vector2f(0.2f,0.08f));
		Button2.setPosition(370,440);
	
		Button3.setTexture(button);
		Button3.scale(Vector2f(0.2f,0.08f));
		Button3.setPosition(370,550);
///////////////////////////////////////////////////////		
		Text TextT,TextA1,TextA2,TextA3,TextEr;
		
		TextT.setFont(font);
		TextT.setString("NULL");			
		TextT.setCharacterSize(20);
		TextT.setColor(Color::Black);
		TextT.setPosition(230,210);
		
		TextA1.setFont(font);
		TextA1.setString("NULL");			
		TextA1.setCharacterSize(20);
		TextA1.setColor(Tcolor);
		TextA1.setPosition(580,y);
		
		TextA2.setFont(font);
		TextA2.setString("NULL");			
		TextA2.setCharacterSize(20);
		TextA2.setColor(Tcolor);
		TextA2.setPosition(580,y);
		
		TextA3.setFont(font);
		TextA3.setString("NULL");			
		TextA3.setCharacterSize(20);
		TextA3.setColor(Tcolor);
		TextA3.setPosition(580,y);
		
		TextEr.setFont(font);
		TextEr.setString("NULL");			
		TextEr.setCharacterSize(20);
		TextEr.setColor(Color::Black);
		TextEr.setPosition(0,0);
		
		if(n==0){fl=fopen("../Questions/Matan","r");}
		if(n==1){fl=fopen("../Questions/History","r");}
		if(n==2){fl=fopen("../Questions/Programm","r");}
		
		if(fl==NULL){
			TextEr.setString("Ошибка в открытии файла.\n             Нажмите 'Q'.");
			TextEr.setPosition(40,20);
			RenderWindow Erwindow(sf::VideoMode(300, 100),"Тестирование",Style::Titlebar);
			while(Erwindow.isOpen()){
				Event eventS_0;
				while (Erwindow.pollEvent(eventS_0));
				if (Keyboard::isKeyPressed(Keyboard::Q)){
					Erwindow.close();
					}
				if(!Erwindow.hasFocus()){
					Erwindow.requestFocus();
					}
				Erwindow.clear();
				Erwindow.draw(Message);		
				Erwindow.draw(TextEr);
		  		Erwindow.display();
								}
				return 0;
			}
			
		while(Test.isOpen()){
			Event event_0;
			while (Test.pollEvent(event_0));
			if(!Test.hasFocus()){
				Test.requestFocus();
			}
			while(!feof(fl)){
				Event event_1;
				while (Test.pollEvent(event_1));
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
			TextT.setString(qw);
			Test.draw(TextT);
			fseek(fl,2,SEEK_CUR);
			fgets(an1,300,fl);
			TextA1.setString(an1);
			fseek(fl,2,SEEK_CUR);
			fgets(an2,300,fl);
			TextA2.setString(an2);
			fseek(fl,2,SEEK_CUR);
			fgets(an3,300,fl);
			TextA3.setString(an3);
			
				while(q!=4){
					Event event_2;
					while (Test.pollEvent(event_2));
					m=rand()%3+1;
					if(m==1){
						if(M[0]==0){
							y+=110;
							TextA1.setPosition(580,y);
							M[0]=1;
							z=q;
							q++;
						}
					}
					else if(m==2){
						if(M[1]==0){
							y+=110;
							TextA2.setPosition(580,y);
							M[1]=1;
							q++;
						}
					}
					else if(m==3){
						if(M[2]==0){
							y+=110;
							TextA3.setPosition(580,y);
							M[2]=1;
							q++;
						}
					}
				}
				for(int k=0;k<3;k++){
					M[k]=0;
				}
				q=1;
				Test.clear();
				Test.draw(FonT);
				Test.draw(Button1);
				Test.draw(Button2);
				Test.draw(Button3);
				Test.draw(TextT);
				Test.draw(TextA1);
				Test.draw(TextA2);
				Test.draw(TextA3);
				Test.display();
				printf("Для выхода из тестирования нажмите 'Q'.\n");
				printf("Введите ответ:");
				d=getch();
				if(d=='q'){
					return 0;
				}
					while(d!='1' and d!='2' and d!='3'){
									Event event_3;
			while (Test.pollEvent(event_3));
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
			printf("Затраченное время:%.1f секунд\n",timeQ);
			printf("Количество баллов:%d\n",score);
			if(score<((col/2)+1)){
				printf("Ваши знания по математике ниже среднего уровня.\n");
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
			Stat(A,col,error,n,timeq);
			system("pause");
			Test.close();
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
				fprintf(fl,"\nВремя потраченное на тест: %d секунд.",timeq);
			fclose(fl);
}
