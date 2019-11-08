#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED



#endif // USER_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "conio.h"
#include "fstream"
using namespace std;

/**
 * user�ṹ
 * id���û�id
 * name���û���
 * password:����
 *
 */

typedef struct User{
    int id;
    char name[50];
    char password[50];
    int power;
    struct User *next;
}User,*pUser;

pUser createList()
{
    pUser pHead = (pUser)malloc(sizeof(User));
    pHead->next=NULL;
    FILE *fp = fopen("users.txt","r");
    if(NULL == fp){
        return pHead;
    }
    pUser cur=pHead;
    while(1)
    {
        pUser readBuf = (pUser)malloc(sizeof(User));
        if(4!=fscanf(fp,"%d %s %s %d",&readBuf->id,readBuf->name,readBuf->password,&readBuf->power)){
            free(readBuf);
            break;
        }
        pHead->id=readBuf->id;
        cur->next=readBuf;
        cur=cur->next;
        cur->next = NULL;
    }
    return pHead;
}

void userAdd(pUser users, pUser newUser){
    pUser user=users;
    while(user->next!=NULL){
        user=user->next;
    }
    user->next=newUser;
    newUser->next=NULL;
}

string checkPower(int power){
    if(power==0) return "�ο�\0";
    else if(power==1) return "����Ա\0";
}

void userDelete(pUser users){
    pUser userL=users;
    int userId;
    cout<<"������Ҫɾ�����û��ı�ţ�";
    cin>>userId;
    pUser userR=userL->next;
    pUser buf;
    char flag;
    while(userR->next!=NULL){
        if(userR->id == userId){
            cout<<"���û���ϢΪ��"<<endl;
            cout<<"name: "<<userR->name<<endl;
            cout<<"password: "<<userR->password<<endl;
            cout<<"�û���ݣ�"<<checkPower(userR->power)<<endl;
            do{
                cout<<"�����Ƿ�ɾ��(Y/N):";
                cin>>flag;
                if(flag=='y'||flag=='Y'){
                    userL->next=userR->next;
                    buf=userR;
                    userR=userR->next;
                    free(buf);
                    return;
                }else if(flag=='n'||flag=='N'){
                    return;
                }else{
                    cout<<"�����������������."<<endl;
                }
            }while(1);
        }
    }
    cout<<"�û�������"<<endl;
}

bool checkUserByName(pUser users, char* name){
    pUser user=users->next;
    while(user!=NULL){
        if(strcmp(user->name,name)==0) return false;
        user=user->next;
    }
    return true;
}

void userRegister(pUser users){
    char name[50];
    char password[50],conPassword[50];
    string temp;
    cout<<"�����˺�"<<endl;
    cout<<"�������˺ţ�";
    cin>>name;
    while(!checkUserByName(users,name)){
        cout<<"�û��Ѵ��ڣ������������˺ţ�";
        cin>>name;
    }
    int flag=0;
    //*�Ŵ�������
    do{
        if(flag!=0){
            cout<<"������������벻��ͬ"<<endl;
        }else{
            flag=1;
        }
        cout<<"���������룺";
        int i=0;
        char ch;
        while((ch=_getch())!='\r'){
            if(ch=='\b'&&i>0){
                cout<<"\b \b";
                i--;
            }else if(ch!='\b'){
             password[i++]=ch;
             cout<<"*";
            }
        }
        password[i]='\0';
        cout<<endl;
        cout<<"��ȷ�����룺";
        i=0;
        while((ch=_getch())!='\r'){
            if(ch=='\b'&&i>0){
                cout<<"\b \b";
                i--;
            }else if(ch!='\b'){
             conPassword[i++]=ch;
             cout<<"*";
            }
        }
        conPassword[i]='\0';
        cout<<endl;
    }while(strcmp(password,conPassword));

    pUser newUser = (pUser)malloc(sizeof(User));
    newUser->id=users->id+1;
    newUser->power=0;
    strcpy(newUser->name,name);
    strcpy(newUser->password,password);
    userAdd(users, newUser);
    cout<<"�����ɹ�"<<endl;
}

void queryAllUser(pUser users){
    pUser user=users->next;
    while(user!=NULL){
        cout.setf(ios::left);
        cout<<setw(4)<<user->id<<setw(10) <<user->name<< "  "<<setw(10)<<user->password<<"    "<<checkPower(user->power)<<endl;
        user=user->next;
    }
}

pUser queryUserById(pUser users,int id){
    pUser user=users->next;
    while(user!=NULL){
        if(user->id==id) return user;
        user=user->next;
    }
    return NULL;
}

void updateUser(pUser users){
    int userId;
    pUser user;
    cout<<"������Ҫ�޸ĵ��û��ı�ţ�";
    cin>>userId;
    if((user=queryUserById(users, userId))==NULL){
        cout<<"�û�������"<<endl;
        return;
    }
    pUser buf = (pUser)malloc(sizeof(User));
    buf->id=user->id;
    strcpy(buf->name,user->name);
    strcpy(buf->password,user->password);
    buf->power=user->power;
    cout<<"-------------------"<<endl;
    cout<<"���û���ϢΪ��"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"�û���: "<<user->name<<endl;
    cout<<"����: "<<user->password<<endl;
    cout<<"�û���ݣ�"<<checkPower(user->power)<<endl;
    cout<<"-------------------"<<endl;
    int in;
    cout<<"���޸ĵ����ݣ�"<<endl;
    cout<<"1. �û���"<<endl;
    cout<<"2. ����"<<endl;
    cout<<"3. �û����"<<endl;
    cout<<"(����0Ϊȷ�����벢�˳�,9Ϊ�����޸�)"<<endl;
    while(1){
        cout<<"ѡ��Ҫ�޸ĵ����ݣ�";
        cin>>in;
        switch(in){
            case 0:
                strcpy(user->name,buf->name);
                strcpy(user->password,buf->password);
                user->power=buf->power;
                return;
            case 9:
                free(buf);
                return;
            case 1:
                cout<<"�޸��û���Ϊ��";
                cin>>buf->name;
                break;
            case 2:
                cout<<"�޸�����Ϊ��";
                cin>>buf->password;
                break;
            case 3:
                cout<<"�޸��û����Ϊ��0.�ο� 1.����Ա����";
                cin>>buf->power;
                break;
            default: cout<<"��������������";
        }
    }
}

void writeFile(pUser users){

    pUser user=users->next;
    ofstream userFile("users.txt");
    while(user!=NULL){
        userFile<<user->id<<" "<<user->name<<" "<<user->password<<" "<<user->power<<endl;
        user=user->next;
    }
    userFile.close();
}
