#ifndef SCHOOLMAP_H_INCLUDED
#define SCHOOLMAP_H_INCLUDED

#endif // SCHOOLMAP_H_INCLUDED

#include "stdio.h"
#include "iomanip"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "string.h"
#include "vector"
#define MAX_POS_NUM 50
#define INF 65535
using namespace std;
using std::vector;

/**
 * position结构
 * id：编号
 * name：位置名字
 * intro：位置介绍
 */
typedef struct{
    int id;
    string name;
    string intro;
}position;

/**
 * Foly图结构
 * distance：两点最短距离
 * ineternalNode：两点最短线路中的内部点
 */
typedef struct{
    int distance;
    vector<int>interalNode;
}FloyNode;

/**
 * SchoolMap结构
 * position：位置
 * edges：连接边
 * pos:景点信息
 */
typedef struct{
    position pos[MAX_POS_NUM];
    int Edge[MAX_POS_NUM][MAX_POS_NUM]; //记录权值
    FloyNode FolyedMap[MAX_POS_NUM][MAX_POS_NUM];
    int lastId;
    int vn;
    int en;
}SchoolMap;


void init(SchoolMap &M);    //初始化
void createMap(SchoolMap *M);   //创建地图
int getPosId(SchoolMap &M, string name); //获取目标位置id
void queryShortEdge(SchoolMap *M); //查询两地之间的最短路线
void queryAround(SchoolMap *M); //搜索周围景点

/**
 *  初始化图
 *  参数：SchoolMap引用
 */
void createMap(SchoolMap &M){
    int i,j;
    for (i = 0; i < MAX_POS_NUM; i++)
    {
        for (j = 0; j < MAX_POS_NUM; j++)
        {
            if(i==j) M.Edge[i][j] = 0;
            else M.Edge[i][j] = INF;
        }
    }   //设置边权值为一个较大的数
}

/**
 *  根据名称返回景点id
 *  参数：SchoolMap指针、string name
 *  返回值：id
 */
int getPosId(SchoolMap *M, string name){
    for(int i=0;i<M->vn;i++){
        if(M->pos[i].name.find(name)!=M->pos[i].name.npos){
            return i+1;
        }
    }
    return -1;
}

/**
 *  根据景点名称打印简介
 *  参数：SchoolMap指针、string name
 */
void getPosInfo(SchoolMap *M, string name){
    for(int i=0;i<M->vn;i++){
        if(M->pos[i].name.find(name)!=M->pos[i].name.npos){
            cout<<"地点简介：";
            cout<<M->pos[i].intro<<endl;
        }
    }
}

/**
 *  根据索引返回名称
 *  参数：SchoolMap指针、int idx
 */
string getPosByIdx(SchoolMap *M, int idx){
    return M->pos[idx].name;
}

/**
 *  获得两点最短路径
 *  参数：SchoolMap指针、int容器、startPos：起始位置、endPos：结束位置、midPos：内部点
 */
void findShortRoute(SchoolMap *M, vector<int> &route, int startPos, int endPos, int midPos){
    if(startPos==endPos) return;
    int nextMidPos;
    route.push_back(midPos);
    if(!M->FolyedMap[startPos][midPos].interalNode.empty()){
        nextMidPos=M->FolyedMap[startPos][midPos].interalNode[0];
        findShortRoute(M, route,startPos, midPos, nextMidPos);
    }
    if(!M->FolyedMap[midPos][endPos].interalNode.empty()){
        nextMidPos=M->FolyedMap[midPos][endPos].interalNode[0];
        findShortRoute(M, route, midPos, endPos, nextMidPos);
    }
}

void printMap(){
    string visualSchoolMap[]={
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓",
        "┃  ╭──────────╮                                                                ╭─────────╮     ┃",
        "┃  |  华山区   |============================================================== |  启林区  |    ┃",
        "┃ ╰────────────╯   ‖                                                         ╰───────────╯    ┃",
        "┃                  ‖                     ╭─────────╮                              ‖          ┃",
        "┃                  ‖==================== |  图书馆  |                             ‖          ┃",
        "┃                  ‖                    ╰───────────╯                             ‖          ┃",
        "┃                  ‖                           ‖                                 ‖          ┃",
        "┃                  ‖                           ‖                                 ‖          ┃",
        "┃                  ‖                           ‖                                 ‖          ┃",
        "┃                ╭──╮                           ‖                                 ‖          ┃",
        "┃                | 校|                          ‖                                 ‖          ┃",
        "┃                | 史|                        ╭────────╮                       ╭──────────╮    ┃",
        "┃                | 馆|========================|  行政楼 |======================|  泰山区   |   ┃",
        "┃               ╰────╯                       ╰──────────╯                     ╰────────────╯   ┃",
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
    };

    for(int i=0;i<(int)(sizeof(visualSchoolMap)/sizeof(visualSchoolMap[0]));i++){
        cout<<visualSchoolMap[i]<<endl;
    }
}

/**
 *  程序初始化
 *  参数：SchoolMap引用
 */
void init(SchoolMap &M){
    printMap();
    createMap(M);

    FILE *mapfp = fopen("mapEdge.txt","r");
    if(NULL == mapfp){
        cout<<"文件打开失败，请重启软件"<<endl;
        return;
    }
    fscanf(mapfp,"%d %d",&M.vn,&M.en);
    for(int i=0;i<M.vn;i++)
        for(int j=0;j<M.vn;j++)
            fscanf(mapfp,"%d",&M.Edge[i][j]);
    fclose(mapfp);

    FILE *posfp = fopen("pos.txt","r");
    char name[100];
    char intro[200];
    for(int i=0;i<M.vn;i++){
        fscanf(posfp,"%d %s %s",&M.pos[i].id,name,intro);
        M.pos[i].name=name;
        M.pos[i].intro=intro;
        M.lastId=M.pos[i].id;
    }
    fclose(posfp);

    //Floyed图初始化
    for(int i=0;i<M.vn;i++){
        for(int j=0;j<M.vn;j++)
            M.FolyedMap[i][j].distance=M.Edge[i][j];
    }

    for(int k=0; k<M.vn; k++){
        for(int i=0; i<M.vn; i++){
            for(int j=0; j<M.vn; j++){
                if(i==k||j==k)
                    continue;
                if(M.FolyedMap[i][k].distance+M.FolyedMap[k][j].distance < M.FolyedMap[i][j].distance){
                        M.FolyedMap[i][j].distance=M.FolyedMap[i][k].distance+M.FolyedMap[k][j].distance;
                        M.FolyedMap[i][j].interalNode.clear();
                        findShortRoute(&M,M.FolyedMap[i][j].interalNode,i,j,k);
                }
            }
        }
    }
}


void addPos(SchoolMap *M){
    //建立点
    string name;
    string intro;
    cout<<"输入新增景点名称：";
    cin>>name;
    cout<<"输入新增景点简介：";
    cin>>intro;

    int idx=M->vn;
    M->vn++;
    M->lastId++;
    M->pos[idx].id=M->lastId;
    M->pos[idx].name=name;
    M->pos[idx].intro=intro;
    M->Edge[idx][idx]=0;

    //Edge增加前的预处理
    for(int i=0;i<idx;i++){
        M->Edge[i][idx]=INF;
        M->Edge[idx][i]=INF;
    }

    //建立边
    int routeNum,dis;   //dis：距离
    string des; //des：目的地
    cout<<"输入新增道路数目：";
    cin>>routeNum;
    M->en+=routeNum;
    for(int i=0;i<routeNum;i++){
        cout<<"输入目的地和距离（中间用空格分隔）：";
        cin>>des>>dis;
        M->Edge[getPosId(M,des)-1][idx]=dis;
        M->Edge[idx][getPosId(M,des)-1]=dis;
    }

    cout<<"操作成功"<<endl;
//    for(int i=0;i<M->vn;i++){
//        for(int j=0;j<M->vn;j++){
//            cout<<M->Edge[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}

/**
 *  根据foly图获得最短距离，并对路线进行排序
 *  参数：SchoolMap引用
 */
void queryShortEdge(SchoolMap *M){
    string startPos,endPos;
    int startPosId,endPosId;

    cout<<"请输入起点:";
    cin>>startPos;
    startPosId=getPosId(M, startPos);
    cout<<"请输入终点:";
    cin>>endPos;
    endPosId=getPosId(M, endPos);

    int startIdx = startPosId-1;
    int endIdx = endPosId-1;
    int pathFinder = startIdx;
    int len=M->FolyedMap[startIdx][endIdx].interalNode.size();
    int n=0,useFlag[len+1]={0};
    int i,j,nextNode;

    cout<<"距离为："<<M->FolyedMap[startIdx][endIdx].distance<<endl;
    cout<<"路线为：";
    cout<<M->pos[startIdx].name<<"-->";
    while(n<len){
        for(i=0;i<M->vn;i++){
            int distance = M->Edge[pathFinder][i];
            if(distance==65535||distance==0) continue;
            for(j=0;j<len;j++){
                nextNode=M->FolyedMap[startIdx][endIdx].interalNode[j];
                if(i==nextNode){
                    useFlag[j]=1;
                    n++;
                    break;
                }
            }
            if(useFlag[j]==1){
                cout<<M->pos[nextNode].name<<"-->";
                pathFinder = nextNode;
                break;
            }
        }
    }
    cout<<M->pos[endIdx].name<<endl;
}

void WriteMapFile(SchoolMap *M){
    ofstream mapFile("mapEdge.txt");
    mapFile<<M->vn<<" "<<M->en<<endl;
    for(int i=0;i<M->vn;i++){
        for(int j=0;j<M->vn;j++){
            mapFile<<M->Edge[i][j]<<" ";
        }
        mapFile<<endl;
    }
    mapFile.close();

    ofstream posFile("pos.txt");
    for(int i=0;i<M->vn;i++){
        posFile<<M->pos[i].id<<" "<<M->pos[i].name<<" "<<M->pos[i].intro<<endl;;
    }

    posFile.close();
}

/**
 *  输出所有景点和其简介
 *  参数：SchoolMap引用
 */
void queryAllPos(SchoolMap *M){
    cout<<"校内主要景点如下："<<endl;
    cout<<endl;
    cout.setf(ios::left);
    cout << setw(10) <<"景点名称"<< " "<<"景点简介"<<endl;
    cout<<"---------------------------"<<endl;
    for(int i=0;i<M->vn;i++){
        cout.setf(ios::left);
        cout << setw(10) <<M->pos[i].name << " "<<M->pos[i].intro<<endl;
    }
}
