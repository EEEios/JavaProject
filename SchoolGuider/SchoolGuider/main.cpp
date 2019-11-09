#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "string.h"
#include "sstream"
#include "conio.h"
#include "fstream"
#include "schoolmap.h"
#include "user.h"
using namespace std;

int menu(){

}

int main()
{


//    pUser users=createList();
//    cout<<"创建完成"<<endl;
//    int in;
//    int id;
//    while(1){
//        cin>>in;
//        switch(in){
//            case 0: writeFile(users); return 0;
//            case 1: userRegister(users); break;
//            case 2: userDelete(users); break;
//            case 3: queryAllUser(users); break;
//            case 4: updateUser(users); break;
//        }
//    }


    SchoolMap *M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);

    queryShortEdge(M);
}
