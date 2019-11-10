#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#endif // USER_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "iostream"
#include "string"
#include "string.h"
#include "sstream"
#include "conio.h"
#include <stdexcept>
#include <limits>
#include "fstream"
using namespace std;

/**
 * user结构
 * id：用户id
 * name：用户名
 * password:密码
 *
 */
typedef struct User{
    int id;
    char name[50];
    char password[50];
    int power;
    struct User *next;
}User,*pUser;

/**
 * 从文件读取并生成用户单链表
 * 返回：头指针
 */
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

/**
 * 输入密码并用*处理密码显示文本
 * 参数：密码字符串指针
 */
void inputPassword(char* password){
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
}

/**
 * 添加用户
 * 参数：users：用户链表指针、newUser：要添加的用户
 */
void userAdd(pUser users, pUser newUser){
    pUser user=users;
    while(user->next!=NULL){
        user=user->next;
    }
    user->next=newUser;
    newUser->next=NULL;
}

/**
 * 检查用户权限是否为管理员
 * 参数：newUser：用户
 * 返回：管理员返回true，非管理员为false
 */
bool checkAdmin(pUser user){
    if(user->power==1) return true;
    else return false;
}

/**
 * 输入要删除的用户Id，并删除
 * 参数：users：用户链表
 */
pUser checkUserByName(pUser users, char* name){
    pUser user=users->next;
    while(user!=NULL){
        if(strcmp(user->name,name)==0) return user;
        user=user->next;
    }
    return NULL;
}

/**
 * 登录并检查是否成功
 * 参数：users：用户链表
 * 返回：密码错误，用户不存在返回false；
 *       登录成功返回true；
 */
int login(pUser users){
    cout<<"";
    char name[50],password[50];
    pUser buf = (pUser)malloc(sizeof(User));
    cout<<"请输入账号：";
    cin>>name;
    cout<<"请输入密码：";
    inputPassword(password);
    if(!(buf=checkUserByName(users, name))){
        cout<<endl<<"用户不存在"<<endl;
        system("pause");
        return -1;
    }
    if(strcmp(buf->password, password)!=0){
        cout<<endl<<"密码错误"<<endl;
        system("pause");
        return -1;
    }
    system("cls");
    if(buf->power==0)
        cout<<endl<<"登录成功。欢迎你，"<<buf->name<<endl;
    else if(buf->power==1)
        cout<<endl<<"登录成功。正在进入后台..."<<endl;
    Sleep(500);
    return buf->power;
}

/**
 * 返回用户权限对应的身份
 * 参数：power：user结构中的权限值
 * 返回：身份字符串
 */
string checkPower(int power){
    if(power==0) return "游客\0";
    else if(power==1) return "管理员\0";
}

/**
 * 输入要删除的用户Id，并删除
 * 参数：users：用户链表
 */
void userDelete(pUser users){
    pUser userL=users;
    pUser userR=userL->next;
    pUser buf=(pUser)malloc(sizeof(User));
    string user;
    cout<<"请输入要删除的用户的用户名：";
    cin>>user;
    char flag;
    while(userR->next!=NULL){
        if(userR->name == user){
            cout<<"该用户信息为："<<endl;
            cout<<"name: "<<userR->name<<endl;
            cout<<"password: "<<userR->password<<endl;
            cout<<"用户身份："<<checkPower(userR->power)<<endl;
            do{
                cout<<"请问是否删除(Y/N):";
                cin>>flag;
                if(flag=='y'||flag=='Y'){
                    userL->next=userR->next;
                    buf=userR;
                    userR=userR->next;
                    free(buf);
                    cout<<"________________"<<user<<endl;
                    cout<<"已删除用户"<<user<<endl;
                    return;
                }else if(flag=='n'||flag=='N'){
                    return;
                }else{
                    cout<<"输入错误，请重新输入."<<endl;
                }
            }while(1);
        }
        userL=userR;
        userR=userR->next;
    }
    cout<<"用户不存在"<<endl;
}

/**
 * 用户注册，并添加入链表
 * 参数：users：用户链表
 */
void userRegister(pUser users){
    char name[50];
    char password[50],conPassword[50];
    string temp;
    cout<<"创建账号"<<endl;
    cout<<"-------------------"<<endl;
    do{
        cout<<"请输入账号：";
        cin>>name;
        if(checkUserByName(users,name)!=NULL){
            char flag;
            while(1){
                cout<<"账号已存在！是否创建其他账号（Y/N）：";
                cin>>flag;
                if(flag=='n'||flag=='N'){
                    return;
                }
                if(flag=='y'||flag=='Y') break;
                else cout<<"输入错误"<<endl;
            }
        }
    }while(checkUserByName(users,name)!=NULL);
    int flag=0;
    //*号处理密码
    do{
        if(flag!=0){
            cout<<"两次输入的密码不相同"<<endl;
        }else{
            flag=1;
        }
        cout<<"请输入密码：";
        inputPassword(password);
        cout<<endl;
        cout<<"请确认密码：";
        inputPassword(conPassword);
        cout<<endl;
    }while(strcmp(password,conPassword));

    pUser newUser = (pUser)malloc(sizeof(User));
    newUser->id=users->id+1;
    newUser->power=0;
    strcpy(newUser->name,name);
    strcpy(newUser->password,password);
    userAdd(users, newUser);
    cout<<"注册成功"<<endl;
    system("pause");
}

/**
 * 返回所有用户
 * 参数：users：用户链表
 */
void queryAllUser(pUser users){
    pUser user=users->next;
    while(user!=NULL){
        cout.setf(ios::left);
        cout<<setw(4)<<user->id<<setw(10) <<user->name<< "  "<<setw(10)<<user->password<<"    "<<checkPower(user->power)<<endl;
        user=user->next;
    }
}

/**
 * 根据用户名返回用户
 * 参数：users：用户链表，Name：用户名
 * 返回：成功返回Name对应用户，否则返回NULL
 */
pUser queryUserByName(pUser users,string Name){
    pUser user=users->next;
    while(user!=NULL){
        if(user->name==Name) return user;
        user=user->next;
    }
    return NULL;
}

/**
 * 输入id，并更新用户信息
 * 参数：users：用户链表
 */
void updateUser(pUser users){
    string userName;
    pUser user;
    cout<<"请输入要修改的用户的用户名：";
    cin>>userName;

    if((user=queryUserByName(users, userName))==NULL){
        cout<<"用户不存在"<<endl;
        return;
    }
    pUser buf = (pUser)malloc(sizeof(User));
    buf->id=user->id;
    strcpy(buf->name,user->name);
    strcpy(buf->password,user->password);
    buf->power=user->power;
    cout<<"-------------------"<<endl;
    cout<<"该用户信息为："<<endl;
    cout<<"-------------------"<<endl;
    cout<<"用户名: "<<user->name<<endl;
    cout<<"密码: "<<user->password<<endl;
    cout<<"用户身份："<<checkPower(user->power)<<endl;
    cout<<"-------------------"<<endl;
    int in;
    cout<<"可修改的内容："<<endl;
    cout<<"1. 用户名"<<endl;
    cout<<"2. 密码"<<endl;
    cout<<"3. 用户身份"<<endl;
    cout<<"(输入0为确认输入并退出,9为放弃修改)"<<endl;
    cout<<"-------------------"<<endl;
    while(1){
        cout<<"选择要修改的内容：";
        cin>>in;
        switch(in){
            case 0:
                strcpy(user->name,buf->name);
                strcpy(user->password,buf->password);
                user->power=buf->power;
                cout<<"修改成功"<<endl;
                return;
            case 9:
                free(buf);
                return;
            case 1:
                cout<<"修改用户名为：";
                cin>>buf->name;
                if(queryUserByName(users,buf->name)!=NULL){
                    cout<<"====该用户已存在===="<<endl;
                    break;
                }
                break;
            case 2:
                cout<<"修改密码为：";
                cin>>buf->password;
                break;
            case 3:
                cout<<"修改用户身份为（0.游客 1.管理员）：";
                cin>>buf->power;
                break;
            default: cout<<"输入有误，请重新";
        }
    }
}

/**
 * 将单链表写入文件做持久化保存
 * 参数：users：用户链表
 */
void writeFile(pUser users){

    pUser user=users->next;
    ofstream userFile("users.txt");
    while(user!=NULL){
        userFile<<user->id<<" "<<user->name<<" "<<user->password<<" "<<user->power<<endl;
        user=user->next;
    }
    userFile.close();
}
