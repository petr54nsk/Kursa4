#include "Functions.h"
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
extern int g;

clock_t start, end;

int Stat(int *, int , int , int, int);

	int QTest(int *A, int n, RenderWindow &Test){
		start=clock();
		srand(time(NULL));
		char qw[300], an1[300], an2[300], an3[300], buf[200],bufT[200];
		char f;
		int score=0,q=1,z=0,col=0,error=0,TestAn=0;
		int m,timeq,poz1,poz2;
		int M[3]={};
		int trigger;
		float timeQ,y=230,x=590;
		FILE *fl;
//////////////////////////////
		Clock clockT;
/////////////////////////////
		Color Tcolor(255,127,36);
///////////////////////////////////////////////		
		Font font;
		
		font.loadFromFile("./Font/arialbd.ttf");
/////////////////////////////////////////////		
		Texture fonT,message,button,fonT2;
		
		fonT.loadFromFile("./Texture/FonT.jpg");
		fonT2.loadFromFile("./Texture/Fon3S.jpg");
		message.loadFromFile("./Texture/message.jpg");
		button.loadFromFile("./Texture/Button2.png");
		button.setSmooth(true);
/////////////////////////////////////////////		
		Sprite FonT,Message,Button1,Button2,Button3,FonT2;
		
		FonT.setTexture(fonT);
		FonT.setPosition(0,0);
		
		FonT2.setTexture(fonT2);
		FonT2.setPosition(0,0);
		
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
		Text TextT,TextA1,TextA2,TextA3,TextEr,TextT_T,TextT_S,TextT_E,TextT_0,TextT_1;
		
		TextT.setFont(font);
		TextT.setString("NULL");			
		TextT.setCharacterSize(20);
		TextT.setColor(Color::Black);
		TextT.setPosition(210,210);
		
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
		
		TextT_E.setFont(font);		
		TextT_E.setCharacterSize(18);
		TextT_E.setColor(Color::Black);
		
		TextT_T.setFont(font);		
		TextT_T.setCharacterSize(18);
		TextT_T.setColor(Color::Black);
		
		TextT_S.setFont(font);		
		TextT_S.setCharacterSize(20);
		TextT_S.setColor(Color::Black);
		
		TextT_0.setFont(font);		
		TextT_0.setCharacterSize(16);
		TextT_0.setColor(Color::Black);
		TextT_0.setPosition(210,210);
		
		TextT_1.setFont(font);		
		TextT_1.setCharacterSize(16);
		TextT_1.setColor(Color::Black);
		TextT_1.setPosition(210,230);
		
		if(n==0){fl=fopen("../Questions/Matan","r");}
		if(n==1){fl=fopen("../Questions/History","r");}
		if(n==2){fl=fopen("../Questions/Programm","r");}
		
			if(n!=0){
				TextA1.setPosition(400,y);
				TextA2.setPosition(400,y);
				TextA3.setPosition(400,y);
				TextA1.setCharacterSize(17);
				TextA2.setCharacterSize(17);
				TextA3.setCharacterSize(17);
			}
	
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
			
		while(1){
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
				TextT.setCharacterSize(20);
				poz1=ftell(fl);
				fgets(qw,200,fl);
				if(qw[1]=='#'){
					poz1=ftell(fl);
					fgets(qw,200,fl);
				}
				if((strlen(qw) > 60) && (strlen(qw) < 90)){
					TextT.setCharacterSize(16);
					TextT.setString(qw);
				}
				else if((strlen(qw) > 60) && (strlen(qw) > 90)){
					trigger=true;
					poz2=ftell(fl);
					fseek(fl,-((poz2-poz1)+2),SEEK_CUR);
					fgets(qw,200,fl);
					fgets(qw,70,fl);
					TextT_0.setString(qw);
					fgets(qw,100,fl);
					TextT_1.setString(qw);
				}
				else{
				TextT.setString(qw);
			}
			fseek(fl,2,SEEK_CUR);
			fgets(an1,300,fl);
			TextA1.setString(an1);
			fseek(fl,2,SEEK_CUR);
			fgets(an2,300,fl);
			TextA2.setString(an2);
			fseek(fl,2,SEEK_CUR);
			fgets(an3,300,fl);
			TextA3.setString(an3);
			
			if((strlen(an1) > 44) && (strlen(an1) < 60)){
				TextA1.setCharacterSize(13);
			}
				else if(strlen(an1) > 60){
					TextA1.setCharacterSize(11);
				}
				
			if((strlen(an2) > 44) && (strlen(an2) < 60)){
				TextA2.setCharacterSize(13);
			}
				else if(strlen(an2) > 60){
					TextA2.setCharacterSize(11);
				}
				
			if((strlen(an3) > 44) && (strlen(an3) < 60)){
				TextA3.setCharacterSize(13);
			}
				else if(strlen(an3) > 60){
					TextA3.setCharacterSize(10);
				}
				
				while(q!=4){
					Event event_2;
					while (Test.pollEvent(event_2));
					m=rand()%3+1;
					if(m==1){
						if(M[0]==0){
							y+=110;
							if(n==0){
								TextA1.setPosition(580,y);	
							}
							else{
								TextA1.setPosition(400,y);
							}
							M[0]=1;
							z=q;
							q++;
						}
					}
					else if(m==2){
						if(M[1]==0){
							y+=110;
							if(n==0){
								TextA2.setPosition(580,y);	
							}
							else{
								TextA2.setPosition(400,y);
							}
							M[1]=1;
							q++;
						}
					}
					else if(m==3){
						if(M[2]==0){
							y+=110;
							if(n==0){
								TextA3.setPosition(580,y);	
							}
							else{
								TextA3.setPosition(400,y);
							}
							M[2]=1;
							q++;
						}
					}
				}
				for(int k=0;k<3;k++){
					M[k]=0;
				}
				while(1){
					Event event_3;
					while (Test.pollEvent(event_3));
			
					if (IntRect(375, 330, 468, 38).contains(Mouse::getPosition(Test))) { 
						Button1.setColor(Color::Cyan); TestAn = 1; 
						}
					else if (IntRect(375, 440, 468, 38).contains(Mouse::getPosition(Test))){
						Button2.setColor(Color::Cyan); TestAn = 2; 
					}
					else if(IntRect(375, 550, 468, 38).contains(Mouse::getPosition(Test))){
						Button3.setColor(Color::Cyan); TestAn = 3;  
					}
					else {
						Button1.setColor(Color::White);
						Button2.setColor(Color::White);
						Button3.setColor(Color::White);
						TestAn = 0;
					}
					if (Mouse::isButtonPressed(Mouse::Left) && (TestAn==1 || TestAn==2 || TestAn==3)){
						clockT.restart();
						while(clockT.getElapsedTime()!=milliseconds(150));
						y=230;
						q=1;
						break;
					}
					Test.clear();
					Test.draw(FonT);
					Test.draw(Button1);
					Test.draw(Button2);
					Test.draw(Button3);
					if(trigger==true){
						Test.draw(TextT_0);
						Test.draw(TextT_1);
					}
					else{
						Test.draw(TextT);
					}
					Test.draw(TextA1);
					Test.draw(TextA2);
					Test.draw(TextA3);
					Test.display();
				}
				TextA1.setCharacterSize(17);
				TextA2.setCharacterSize(17);
				TextA3.setCharacterSize(17);
				trigger=false;
				if(TestAn==z){
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
			snprintf(buf,10,"%.1f",timeQ);
			TextT_T.setString(buf);
			if(score<((col/2)+1)){
				TextT_S.setString("Ваши знания по математике ниже среднего уровня.");
			}
				else if (score>(col/2) && score<col-(col/4)){
					TextT_S.setString("Ваши знания по математике среднего уровня.");
				}
					else{
						TextT_S.setString("Ваши знания по математике высокого уровня.");
					}
			if(error==0){
				TextT_E.setString("Ошибок нету.");
			}
			score=0;
			fclose(fl);
			Stat(A,col,error,n,timeq);
			TextT_E.setPosition(240,280);
			TextT_S.setPosition(240,220);
			TextT.setString("Для завершения нажмите 'Q'.");
			TextT.setCharacterSize(20);
			TextT.setPosition(460,530);
			while(1){
				Event event_4;
				while (Test.pollEvent(event_4));
				Test.clear();
				Test.draw(FonT2);
				TextT_T.setString("Затраченное время:");
				TextT_T.setPosition(240,250);
				Test.draw(TextT_T);
				TextT_T.setString(buf);
				TextT_T.setPosition(440,250);
				Test.draw(TextT_T);
				TextT_T.setString("секунд(ы).");
				TextT_T.setPosition(480,250);
				Test.draw(TextT_T);
				Test.draw(TextT_S);
				if(error!=0){
					TextT_E.setString("Вопросы в которых допущена ошибка:");
				}
				Test.draw(TextT_E);	
				if(error!=0){
					for(int i=1;i<error+1;i++){
						if(A[i]>=10){
							x+=30;
						}
						else{
							x+=20;
						}
						snprintf(bufT,10,"%d",A[i]);
						TextT_E.setString(bufT);
						TextT_E.setPosition(x,280);
						Test.draw(TextT_E);
					}
				}
				TextT_E.setPosition(240,280);
				x=590;		
				Test.draw(TextT);
		  		Test.display();
			  		if(Keyboard::isKeyPressed(Keyboard::Q)){
			  			break;
					  }
				}
			break;
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
			   		Color Tcolor(0,191,255);
			   		Font font;
			   		font.loadFromFile("./Font/arialbd.ttf");
			   		Text TextEr;
			   		TextEr.setFont(font);
			   		TextEr.setCharacterSize(18);
			   		TextEr.setColor(Tcolor);
			   		Texture message;
			   		message.loadFromFile("./Texture/message.jpg");
			   		Sprite Message;
			   		Message.setTexture(message);
					TextEr.setString("Ошибка в открытии файла.\n             Нажмите 'Q'.");
					TextEr.setPosition(40,20);
					RenderWindow Erwindow(sf::VideoMode(300, 100),"Статистика",Style::Titlebar);
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
