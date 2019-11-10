#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#endif // GRAPH_H_INCLUDED
#include "windows.h"
#include "time.h"
#include "list"
#include "bits/stdc++.h"
#define KEYDOWN(vk_code) ((::GetKeyState(vk_code)&0x8000)?1:0)

int listen() {
    if(KEYDOWN(VK_UP))
        return 1;
    if(KEYDOWN(VK_DOWN))
        return 2;
    if(KEYDOWN(VK_LEFT))
        return 3;
    if(KEYDOWN(VK_RIGHT))
        return 4;
    if(KEYDOWN(VK_RETURN))
        return 5;   //回车
    if(KEYDOWN(VK_SPACE))
        return 6;   //空格
    if(KEYDOWN(VK_ESCAPE))
        return 7;   //esc
    return 0;
}

void welcome(){
    system("cls");
    cout<<R"(
            _____                          _____         _      _
           /  ___|                        |  __ \       (_)    | |
           \ `--.   ___   __ _  _   _     | |  \/ _   _  _   __| |  ___  _ __
            `--. \ / __| / _` || | | |    | | __ | | | || | / _` | / _ \| '__|
           /\__/ /| (__ | (_| || |_| |    | |_\ \| |_| || || (_| ||  __/| |
           \____/  \___| \__,_| \__,_|     \____/ \__,_||_| \__,_| \___||_|      )";
    cout<<endl;
    cout<<endl;
}

int loginOrRegister(){
    COORD coord;
    coord.Y=9;
    coord.X=11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"登录";
    coord.Y+=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"注册";
    coord.Y=9;
    coord.X=9;

    int control=0;
    while(control!=5) {
        Sleep(100);
        control=listen();
        if(control==7)
            return 0;
        if(control==1) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            cout<<"  ";
            coord.Y-=2;
            if(coord.Y<9)
                coord.Y=11;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            cout<<">>";
            continue;
        }

        if(control==2) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            cout<<"  ";
            coord.Y+=2;
            if(coord.Y>11)
                coord.Y=9;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            cout<<">>";
            continue;
        }
    }
    return coord.Y%9/2;
}

void loading(){
    cout<<endl;
    cout<<"     Loading";
    for(int i=0;i<4;i++){
        cout<<'.';
        Sleep(1000);
    }
}

//void screen() {
//    cout<<R"(==================================================
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//||                                              ||
//|================================================|
//|                                                |
//|        -------------------------               |
//|        |                       |               |
//|        -------------------------               |
//|                                                |
//|        -------------------------               |
//|        |                       |               |
//|        -------------------------               |
//|                                                |
//|        -------------------------               |
//|        |                       |               |
//|        -------------------------               |
//==================================================)"<<endl;
//}



//int menu(){
//    system("cls");
//    screen();   //打印界面
//    COORD coord;
//    coord.Y=18;
//    coord.X=10;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//    cout<<"用户操作";
//    coord.Y+=4;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//    cout<<"2";
//    coord.Y+=4;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//    cout<<"3";
//    coord.Y=14;
//    coord.X=7;
//
//    int control=0;
//    while(control!=5) {
//        Sleep(80);
//        control=listen();
//        if(control==7)
//            return 0;
//        if(control==1) {
//            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//            cout<<"  ";
//            coord.Y-=4;
//            if(coord.Y<=14)
//                coord.Y=26;
//            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//            cout<<">>";
//            continue;
//        }
//
//        if(control==2) {
//            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//            cout<<"  ";
//            coord.Y+=4;
//            if(coord.Y>=30)
//                coord.Y=18;
//            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//            cout<<">>";
//            continue;
//        }
//    }
//    return coord.Y%18/4;
//}
