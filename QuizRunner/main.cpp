#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(){
char ch,k=true;
//setlocale(LC_ALL, "Russian");
while (k==true){
system("cls");
printf("1. ������ ������������\n");
printf("2. Unit-Tests\n");
printf("3. ����� �� ���������\n");
//cout<<"��� �����: ";
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
   break;
   
case '2':
   break;
   
case '3':
	k=false;
   break;
   
default:
	printf("���� ����� ��� �� ������..\n");
 	 }
	}
system ("PAUSE");
}
