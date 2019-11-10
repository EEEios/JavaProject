#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "sstream"
#include "conio.h"
#include "fstream"


#include "schoolmap.h"
#include "user.h"
#include "graph.h"
using namespace std;

pUser users=createList();
//SchoolMap *M=(SchoolMap *)malloc(sizeof(SchoolMap));

int MainLogin(){
    cin.sync();
    int iden;
    do{
        welcome();
    }while((iden=login(users))==-1);
    if(iden==0) return 10;
    else if(iden==1) return 11;
}

void MainRegister(){
    cin.sync();
    welcome();
    userRegister(users);
}

int MainMenu(){
    int flag;
    welcome();
    cout<<"     "<<"��ѡ���ܣ�"<<endl;
    cout<<"     "<<"1.��¼"<<endl;
    cout<<"     "<<"2.ע��"<<endl;
    cout<<"     "<<"==============="<<endl;
    cout<<"     "<<"������ѡ����:";
    cin>>flag;
    switch(flag){
        case 1:
            return MainLogin();
        case 2:
            MainRegister(); return 1;
    }
}

void MainGuider(){
    system("cls");
    printMap();
    queryShortEdge(M);
}

int UserMenu(){
    int flag;
    welcome();
    cout<<"     "<<"��ѡ���ܣ�"<<endl;
    cout<<"     "<<"1.�鿴���о���"<<endl;
    cout<<"     "<<"2.����"<<endl;
    cout<<"     "<<"0.�˳�"<<endl;
    cout<<"     "<<"==============="<<endl;
    cout<<"     "<<"������ѡ����:";
    cin>>flag;
    switch(flag){
        case 1:
            welcome();
            queryAllPos(M);
            system("pause");
            return 1;
        case 2:
            MainGuider(); return 2;
        case 0:
            return 0;
    }
}

int AdminUser(){
    int flag;
    welcome();
    cout<<"     "<<"��ѡ���ܣ�"<<endl;
    cout<<"     "<<"1.�鿴�����û�"<<endl;
    cout<<"     "<<"2.ɾ���û�"<<endl;
    cout<<"     "<<"3.�����û���Ϣ"<<endl;
    cout<<"     "<<"4.�����û�"<<endl;
    cout<<"     "<<"0.�����ϼ��˵�"<<endl;
    cout<<"     "<<"==============="<<endl;
    cout<<"     "<<"������ѡ����:";
    cin>>flag;
    switch(flag){
        case 1:
            welcome();
            queryAllUser(users);
            system("pause");
            return 1;
        case 2:
            welcome();
            userDelete(users);
            system("pause");
            return 2;
        case 3:
            welcome();
            updateUser(users);
            system("pause");
            return 3;
        case 4:
            welcome();
            userRegister(users);
            return 4;
        case 0:
            return 0;
    }
}

int AdminPos(){
    int flag;
    welcome();
    cout<<"     "<<"��ѡ���ܣ�"<<endl;
    cout<<"     "<<"1.�鿴���о���"<<endl;
    cout<<"     "<<"2.��������"<<endl;
    cout<<"     "<<"3.ɾ������"<<endl;
    cout<<"     "<<"0.�����ϼ��˵�"<<endl;
    cout<<"     "<<"==============="<<endl;
    cout<<"     "<<"������ѡ����:";
    cin>>flag;
    switch(flag){
        case 1:
            welcome();
            queryAllPos(M);
            system("pause");
            return 1;
        case 2:
            welcome();
            addPos(M);
            system("pause");
            return 2;
        case 3:
            welcome();
            deletePos(M);
            system("pause");
            return 3;
        case 0:
            return 0;
    }
}

int AdminMenu(){
    int flag;
    welcome();
    cout<<"     "<<"��ѡ���ܣ�"<<endl;
    cout<<"     "<<"1.�鿴���о���"<<endl;
    cout<<"     "<<"2.����"<<endl;
    cout<<"     "<<"3.�����û�"<<endl;
    cout<<"     "<<"4.�����ͼ"<<endl;
    cout<<"     "<<"0.�˳�"<<endl;
    cout<<"     "<<"==============="<<endl;
    cout<<"     "<<"������ѡ����:";
    cin>>flag;
    switch(flag){
        case 1:
            welcome();
            queryAllPos(M);
            system("pause");
            return 1;
        case 2:
            MainGuider(); return 2;
        case 3:
            while(AdminUser()); return 3;
        case 4:
            while(AdminPos()); return 4;
        case 0:
            return 0;
    }
}

void MainEnd(){
    welcome();
    cout<<R"(
    Goodbye.
    )";
    Sleep(1000);
}

void MainWelcome(){
    welcome();
    loading();
}

int main() {

//    init(*M);
//    MainWelcome();
//    int flag;
//    while((flag=MainMenu())==1);
//    if(flag==10)
//        while(UserMenu());
//    if(flag==11)
//        while(AdminMenu());
//    writeFile(users);
//    WriteMapFile(M);
//    MainEnd();
SchoolMap *M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);
    addPos(M);

    addPos(M);
    queryShortEdge(M);
    queryAllPos(M);
}
