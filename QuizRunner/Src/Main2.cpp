#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include "Functions2.cpp"

using namespace sf;
int g = 0;

int menuNum = 0, menuStat = 0, exitS = 0, menuTest = 0, error = 0, col = 0, n = 0, j = 0, w = 0;
int A[31]={};
int k = true;
struct tm * timeinfo;
FILE *test, *fl;
char buf[225];
float x = 230,y = 230;
int main() 
{
	setlocale(LC_ALL,"russian");
///// Создание окна ///////////
	RenderWindow Mwindow(sf::VideoMode(1200, 700), "QuizRunner",Style::Titlebar);
	
///// Работа с текстом ///////////
	Font font;
	font.loadFromFile("./Font/arialbd.ttf");
	
	Color Acolor(152,245,255);
	Color Mcolor(135,206,250);
	Color Scolor(30,144,255);
	
	Text Text1, Text2, Text3, Text1S, Text2S, Text3S, Text_S_Er, TextPrS, TextEx_S, Text1T, Text2T, Text3T, Text4T;
/////// Название кнопок главного меню ......		
	Text1.setFont(font);
	Text1.setString("Тестирование");
	Text1.setCharacterSize(20);
	Text1.setColor(Color::White);
	Text1.setPosition(505,225);
	
	Text2.setFont(font);
	Text2.setString("Статистика");
	Text2.setCharacterSize(20);
	Text2.setColor(Color::White);
	Text2.setPosition(515,325);
	
	Text3.setFont(font);
	Text3.setString("Выход");
	Text3.setCharacterSize(20);
	Text3.setColor(Color::White);
	Text3.setPosition(540,425);
/////// Название кнопок тестов ......		
	Text1T.setFont(font);
	Text1T.setString("Математика");
	Text1T.setCharacterSize(18);
	Text1T.setColor(Color::White);
	Text1T.setPosition(520,225);
	
	Text2T.setFont(font);
	Text2T.setString("История");
	Text2T.setCharacterSize(18);
	Text2T.setColor(Color::White);
	Text2T.setPosition(535,325);
	
	Text3T.setFont(font);
	Text3T.setString("Программирование");
	Text3T.setCharacterSize(15);
	Text3T.setColor(Color::White);
	Text3T.setPosition(500,425);
	
	Text4T.setFont(font);
	Text4T.setString("Назад");
	Text4T.setCharacterSize(20);
	Text4T.setColor(Color::White);
	Text4T.setPosition(540,525);
/////// Название кнопок статистики ......	
	Text_S_Er.setFont(font);
	Text_S_Er.setString("Нечего обнулять.\n     Нажмите Q.");
	Text_S_Er.setCharacterSize(20);
	Text_S_Er.setColor(Mcolor);
	Text_S_Er.setPosition(60,20);
	
	TextPrS.setFont(font);
	TextPrS.setString("NULL");
	TextPrS.setCharacterSize(16);
	TextPrS.setColor(Color::Black);
	TextPrS.setPosition(230,230);
	
	TextEx_S.setFont(font);
	TextEx_S.setString("Для завершения просмотра статистики, нажмите 'Q'.\nДля продолжения просмотра статистики, нажмите 'N'.");
	TextEx_S.setCharacterSize(18);
	TextEx_S.setColor(Scolor);
	TextEx_S.setPosition(230,520);
	
	Text1S.setFont(font);
	Text1S.setString("Просмотр статистики");
	Text1S.setCharacterSize(14);
	Text1S.setColor(Color::White);
	Text1S.setPosition(492,225);
	
	Text2S.setFont(font);
	Text2S.setString("Очистка статистики");
	Text2S.setCharacterSize(15);
	Text2S.setColor(Color::White);
	Text2S.setPosition(495,325);
	
	Text3S.setFont(font);
	Text3S.setString("Назад");
	Text3S.setCharacterSize(20);
	Text3S.setColor(Color::White);
	Text3S.setPosition(540,425);
	
	Image icon;
	
	icon.loadFromFile("./Texture/icon1.png");
	
	Texture fon,button,message,fonS;
	
	message.loadFromFile("./Texture/message.jpg");
	fon.loadFromFile("./Texture/Fon3.jpg");
	fonS.loadFromFile("./Texture/Fon3S.jpg");
	button.loadFromFile("./Texture/Button.png");
	Mwindow.setIcon(32,32,icon.getPixelsPtr());
///// Работа с кнопками и фоном ///////////
	Clock clock;
		
	Sprite Fon, FonS, Button1, Button2, Button3, Button4, Message;
	
	Fon.setTexture(fon);
	Fon.setPosition(0,0);
	
	FonS.setTexture(fonS);
	FonS.setPosition(0,0);
	
	Message.setTexture(message);
	Message.setPosition(0,0);
	
	Button1.setTexture(button);
	Button1.scale(Vector2f(0.3f,0.3f));
	Button1.setPosition(480,200);
	
	Button2.setTexture(button);
	Button2.scale(Vector2f(0.3f,0.3f));
	Button2.setPosition(480,300);
	
	Button3.setTexture(button);
	Button3.scale(Vector2f(0.3f,0.3f));
	Button3.setPosition(480,400);
	
	Button4.setTexture(button);
	Button4.scale(Vector2f(0.3f,0.3f));
	Button4.setPosition(480,500);
///// Запуск окон и обработка событий ///////////
////////////////		
///// Главное меню ///////////		
        while (Mwindow.isOpen()) 
	{ 
		Event event;
		while (Mwindow.pollEvent(event));

		if (IntRect(490, 220, 165, 38).contains(Mouse::getPosition(Mwindow))) { 
			Text1.setColor(Acolor); menuNum = 1; 
			}
		else if (IntRect(490, 320, 165, 38).contains(Mouse::getPosition(Mwindow))){
			Text2.setColor(Acolor); menuNum = 2; 
		}
		else if(IntRect(490, 420, 165, 38).contains(Mouse::getPosition(Mwindow))){
			Text3.setColor(Acolor); menuNum = 3; 
		}
		else {
			Text1.setColor(Color::White);
			Text2.setColor(Color::White);
			Text3.setColor(Color::White);
			menuNum = 0;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
/////////// Запуск ветки тестирования ///////////////////
			if (menuNum == 1){
					clock.restart();
					while(clock.getElapsedTime()!=milliseconds(150));
				while(1){
					Event eventT;
					while (Mwindow.pollEvent(eventT));
					if (IntRect(490, 220, 165, 38).contains(Mouse::getPosition(Mwindow))) { 
						Text1T.setColor(Acolor); menuTest = 1; 
						}
					else if (IntRect(490, 320, 165, 38).contains(Mouse::getPosition(Mwindow))){
						Text2T.setColor(Acolor); menuTest = 2; 
					}
					else if(IntRect(490, 420, 165, 38).contains(Mouse::getPosition(Mwindow))){
						Text3T.setColor(Acolor); menuTest = 3; 
					}
					else if(IntRect(490, 520, 165, 38).contains(Mouse::getPosition(Mwindow))){
						Text4T.setColor(Acolor); menuTest = 4; 
					}
					else {
						Text1T.setColor(Color::White);
						Text2T.setColor(Color::White);
						Text3T.setColor(Color::White);
						Text4T.setColor(Color::White);
						menuTest = 0;
					}
					if (Mouse::isButtonPressed(Mouse::Left)){
						if(menuTest==1){
							error = 0;
							col = 0;
									for(int i=0;i<31;i++){
										A[i]=0;
									}
							n = 0;
							QTest(A,n,Mwindow);
							j = 1;
						}
						if(menuTest==2){
							error = 0;
							col = 0;
									for(int i=0;i<31;i++){
										A[i]=0;
									}
							n = 1;
							QTest(A,n,Mwindow);
							j = 1;
						}
						if(menuTest==3){
							error = 0;
							col = 0;
									for(int i=0;i<31;i++){
										A[i]=0;
									}
							n = 2;
							QTest(A,n,Mwindow);
							j = 1;
						}
						if(menuTest==4){
							clock.restart();
							while(clock.getElapsedTime()!=milliseconds(100));
							Text1.setColor(Color::White);
							Text2.setColor(Color::White);
							Text3.setColor(Color::White);
							break;
						}
					}
					Mwindow.clear();
					Mwindow.draw(Fon);
					Mwindow.draw(Button1);
					Mwindow.draw(Text1T);
					Mwindow.draw(Button2);
					Mwindow.draw(Text2T);
					Mwindow.draw(Button3);
					Mwindow.draw(Text3T);
					Mwindow.draw(Button4);
					Mwindow.draw(Text4T);
					Mwindow.display();	
				}
			}
/////////////// Запуск ветки статистики ///////////	
			if (menuNum == 2){
				clock.restart();
				while(clock.getElapsedTime()!=milliseconds(150));
				Mwindow.clear();
				Text1S.setColor(Color::White);
				Text2S.setColor(Color::White);
				Text3S.setColor(Color::White);
				while(1){
					Event eventS;
					while (Mwindow.pollEvent(eventS));
					if (IntRect(490, 220, 165, 38).contains(Mouse::getPosition(Mwindow))) { 
						Text1S.setColor(Acolor); menuStat = 1; 
						}
					else if (IntRect(490, 320, 165, 38).contains(Mouse::getPosition(Mwindow))){
						Text2S.setColor(Acolor); menuStat = 2; 
					}
					else if(IntRect(490, 420, 165, 38).contains(Mouse::getPosition(Mwindow))){
						Text3S.setColor(Acolor); menuStat = 3; 
					}
					else {
						Text1S.setColor(Color::White);
						Text2S.setColor(Color::White);
						Text3S.setColor(Color::White);
						menuStat = 0;
					}
					if (Mouse::isButtonPressed(Mouse::Left)){
//////////////////////////////// Просмотр статистики ///////////	
						if(menuStat==1){
							fl=fopen("../Bin/Statistics","r");
							exitS=0;
							if(fl==NULL){
								Text_S_Er.setString("Статистики еще нету.\n       Нажмите 'Q'.");
								Text_S_Er.setPosition(40,20);
								RenderWindow S_Er_window(sf::VideoMode(300, 100),"Статистика",Style::Titlebar);
								while(S_Er_window.isOpen()){
									Event eventS_0;
									while (S_Er_window.pollEvent(eventS_0));
										if (Keyboard::isKeyPressed(Keyboard::Q)){
											S_Er_window.close();
										}
										if(!S_Er_window.hasFocus()){
											S_Er_window.requestFocus();
										}
										S_Er_window.clear();
										S_Er_window.draw(Message);
										S_Er_window.draw(Text_S_Er);
										S_Er_window.display();
								}
							}
							else{
								k=true;
								y=230;
								Mwindow.clear();
								Mwindow.draw(FonS);		
								while(k==true){
									Event eventS_Pr_1;
									while (Mwindow.pollEvent(eventS_Pr_1));
									TextPrS.setPosition(x,y);
									while(!feof(fl)){
									Event eventS_Pr_2;
									while (Mwindow.pollEvent(eventS_Pr_2));	
									fgets(buf,80,fl);
										if(!feof(fl)){
											TextPrS.setString(buf);
											TextPrS.setPosition(x,y);
											Mwindow.draw(TextPrS);
											Mwindow.draw(TextEx_S);
											Mwindow.display();
											y+=20;
												if(buf[3]=='='){
													while(1){
														Event eventS_Pr_3;
														while (Mwindow.pollEvent(eventS_Pr_3));
															if(Keyboard::isKeyPressed(Keyboard::Q)){
																k=false;
																exitS=1;
																break;
															}
															if(Keyboard::isKeyPressed(Keyboard::N)){
																clock.restart();
																while(clock.getElapsedTime()!=milliseconds(200));
																Mwindow.clear();
																Mwindow.draw(FonS);
																Mwindow.display();
																y=230;
																break;
															}	
													}
												}
											}
									if(feof(fl) && exitS==0){
											TextPrS.setString("На этом статистика закончена.\n     Нажмите 'N' для выхода.");
											TextPrS.setPosition(470,350);
											Mwindow.clear();
											Mwindow.draw(FonS);
											Mwindow.draw(TextPrS);
											Mwindow.display();
											while(1){
												Event eventS_Pr_3;
												while (Mwindow.pollEvent(eventS_Pr_3));
												if(Keyboard::isKeyPressed(Keyboard::N)){
													break;
													}
											}
											k=false;
											}
									Mwindow.display();
									}
								}
							}
							fclose(fl);
						}
//////////////////////////// Обнуление статистики ///////////	
						else if(menuStat==2){
							if(!(test=fopen("../Bin/Statistics","r"))){
								RenderWindow S_Er_window(sf::VideoMode(300, 100),"Статистика",Style::Titlebar);
								while(S_Er_window.isOpen()){
									Event eventS;
									while (S_Er_window.pollEvent(eventS));
										if (Keyboard::isKeyPressed(Keyboard::Q)){
											S_Er_window.close();
										}
										if(!S_Er_window.hasFocus()){
											S_Er_window.requestFocus();
										}
										S_Er_window.clear();
										S_Er_window.draw(Message);
										S_Er_window.draw(Text_S_Er);
										S_Er_window.display();
								}
							}
							else {
								fl=fopen("../Bin/Statistics","w");
								fclose(fl);
								Text_S_Er.setString("Статистика обнулена.\n       Нажмите Q.");
								Text_S_Er.setPosition(40,20);
								RenderWindow S_Er_window(sf::VideoMode(300, 100),"Статистика",Style::Titlebar);
								while(S_Er_window.isOpen()){
									Event eventCl;
									while (S_Er_window.pollEvent(eventCl));
										if (Keyboard::isKeyPressed(Keyboard::Q)){
											S_Er_window.close();
										}
										if(!S_Er_window.hasFocus()){
											S_Er_window.requestFocus();
										}
										S_Er_window.clear();
										S_Er_window.draw(Message);
										S_Er_window.draw(Text_S_Er);
										S_Er_window.display();
								}
							}
						}
//////////////////////////// Выход из ветки статистики ///////////	
						else if(menuStat==3){
							clock.restart();
							while(clock.getElapsedTime()!=milliseconds(100));
							Text1.setColor(Color::White);
							Text2.setColor(Color::White);
							Text3.setColor(Color::White);
							break;
						}
					}
//////////////////////////// Отрисовка в ветке статистики///////////	
					Mwindow.clear();
					Mwindow.draw(Fon);
					Mwindow.draw(Button1);
					Mwindow.draw(Text1S);
					Mwindow.draw(Button2);
					Mwindow.draw(Text2S);
					Mwindow.draw(Button3);
					Mwindow.draw(Text3S);
					Mwindow.display();
				}
			}
///// Закрытие главного меню ///////////				
			if (menuNum == 3){
				if(j==1){
					fl=fopen("../Bin/Statistics","a+");
					fprintf(fl,"\n===========================================\n");
					fclose(fl);
				}
				Mwindow.close();
			}
		}
///// Отрисовка в главном меню ///////////			
		Mwindow.clear();
		Mwindow.draw(Fon);
		Mwindow.draw(Button1);
		Mwindow.draw(Text1);
		Mwindow.draw(Button2);
		Mwindow.draw(Text2);
		Mwindow.draw(Button3);
		Mwindow.draw(Text3);
		Mwindow.display();
    }
    return 0 ;
}
