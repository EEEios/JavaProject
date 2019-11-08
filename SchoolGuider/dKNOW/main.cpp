#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<list>
#include<string>
#include <stdio.h>
#define KEYDOWN(vk_code) ((::GetKeyState(vk_code)&0x8000)?1:0)
using namespace std;
int listen()
       {
           if(KEYDOWN(VK_RETURN))return 8;
           if(KEYDOWN(0x52))
           return 5;
           if(KEYDOWN(VK_SPACE))
           return 6;
           if(KEYDOWN(VK_ESCAPE))
           return 7;
           if(KEYDOWN(VK_UP)||KEYDOWN(0x57))
           return 1;
           if(KEYDOWN(VK_DOWN)||KEYDOWN(0x53))
           return 4;
           if(KEYDOWN(VK_LEFT)||KEYDOWN(0x41))
           return 2;
           if(KEYDOWN(VK_RIGHT)||KEYDOWN(0x44))
           return 3;
           return 0;
       }
void screen()
{
    string maze[33];int i=0;
    maze[0]="==================================================";
    maze[15]="|================================================|";
    for(i=1;i<15;i++)
    maze[i]="||                                              ||";
    for(int j=0;j<3;j++)
    {
        i++;
    maze[i]="|                                                |";
    i++;
    maze[i]="|        _________________________________       |";
    i++;
    maze[i]="|        |                               |       |";
    i++;
    maze[i]="|        ---------------------------------       |";
    }
    i++;
    maze[i]="==================================================";
    for(i=0;i<33;i++)
        cout<<maze[i]<<endl;
}
int main()
{
    screen();COORD coord;coord.Y=18;coord.X=10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"想打谁打谁";
    coord.Y+=4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"想打谁打谁";
    coord.Y+=4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"想打谁打谁";
    coord.Y=18;coord.X=7;
    int control=0;
           while(control!=8){Sleep(90);control=listen();if(control==7)return 0;

           if(control==1){SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);cout<<"  ";coord.Y-=4;if(coord.Y==14)coord.Y=26;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);cout<<">>";continue;}

           if(control==4){SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);cout<<"  ";coord.Y+=4;if(coord.Y==30)coord.Y=18;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);cout<<">>";continue;}


           }
}
