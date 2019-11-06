#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "string.h"
#define MAX_POS_NUM 50
#define INFINITY 65535
using namespace std;

/**
 * position结构
 * id：编号
 * name：位置名字
 * intro：位置介绍
 */
typedef struct{
    int id;
    char name[100];
    char intro[200];
}position;

/**
 * SchoolMap结构
 * position：位置
 * edges：连接边
 * pos:景点信息
 */
typedef struct{
    position pos[MAX_POS_NUM];
    int Edge[MAX_POS_NUM][MAX_POS_NUM]; //记录权值
    int vn;
    int en;
}SchoolMap;

void init(SchoolMap &M);
void createMap(SchoolMap *M);   //创建地图
void getPos(SchoolMap *G, int v);   //获得对应地图简介
void ToDestination(SchoolMap *G, int v, int w);     //获取最短路径

void createMap(SchoolMap &M){
    M.vn = 6;
    M.en = 8;

    int i,j;

    for (i = 0; i < MAX_POS_NUM; i++)
    {
        for (int j = 0; j < MAX_POS_NUM; j++)
        {
            M.Edge[i][j] = INFINITY;
        }
    }   //设置边权值为一个较大的数
}

void init(SchoolMap &M){

    string visualSchoolMap[]={
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓",
        "┃  ╭──────────╮                                                                ╭─────────╮     ┃",
        "┃  |  华山区   |============================================================== |  启林区  |    ┃",
        "┃ ╰────────────╯   ‖                                                          ╰──────────╯    ┃",
        "┃                  ‖                     ╭─────────╮                              ‖          ┃",
        "┃                  ‖==================== |  图书馆  |                             ‖          ┃",
        "┃                  ‖                    ╰───────────╯                             ‖          ┃",
        "┃                ╭──╮                         ‖                                   ‖          ┃",
        "┃                | 校|========================‖                                   ‖          ┃",
        "┃                | 史|                        ‖                                   ‖          ┃",
        "┃                | 馆|                     ╭────────╮                              ‖          ┃",
        "┃               ╰────╯                     |  行政楼 |                             ‖          ┃",
        "┃                  ‖                     ╰──────────╯                         ╭──────────╮    ┃",
        "┃                  ‖===========================‖=============================|  泰山区   |   ┃",
        "┃                                                                             ╰────────────╯   ┃",
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
    };

    for(int i=0;i<sizeof(visualSchoolMap)/sizeof(visualSchoolMap[0]);i++){
        cout<<visualSchoolMap[i]<<endl;
    }

    createMap(M);

    M.Edge[0][1]=800;
    M.Edge[0][2]=2000;
    M.Edge[0][4]=2200;
    M.Edge[2][3]=400;
    M.Edge[2][4]=900;
    M.Edge[5][1]=3500;
    M.Edge[5][3]=1000;
    M.Edge[5][4]=600;
    M.Edge[1][0]=800;
    M.Edge[2][0]=2000;
    M.Edge[4][0]=2200;
    M.Edge[3][2]=400;
    M.Edge[4][2]=900;
    M.Edge[1][5]=3500;
    M.Edge[3][5]=1000;
    M.Edge[4][5]=600;

    for(int i=0;i<M.vn;i++){
        for(int j=0;j<M.vn;j++)
            printf("%10d",M.Edge[i][j]);
        printf("\n");
    }


    position pos[M.vn]={
        {1,"泰山区","泰山宿舍区"},
        {2,"启林区","启林宿舍区"},
        {3,"行政楼","行政区域"},
        {4,"图书馆","华农图书总馆"},
        {5,"校史馆","校史景点区"},
        {6,"华山区","华山宿舍区"}
    };

    for(int i=0;i<M.vn;i++){
        M.pos[i].id = pos[i].id;
        strcpy(M.pos[i].intro,pos[i].intro);
        strcpy(M.pos[i].name,pos[i].name);
    }

    for(int i=0;i<M.vn;i++){
        cout<<M.pos[i].name<<endl;
        cout<<M.pos[i].intro<<endl;
    }

}

int getPosId(SchoolMap *M, string name){
    for(int i=0;i<vn;i++){
        if(M->pos[i])
    }
}

int main()
{
    SchoolMap *M;
    M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);

}
