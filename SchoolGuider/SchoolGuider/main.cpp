#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "string.h"
#include "vector"

#define MAX_POS_NUM 50
#define INFINITY 65535
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
    int vn;
    int en;
}SchoolMap;


/**
 *用户端功能:
 *  1.查询两点之间的最短距离；
 *  2.查询周围景点；
 *  3.查询停车场使用情况；
 *管理端功能：
 *  1.包含用户端功能
 *  2.增删景点节点
 *  3.查询停车场使用情况；
 */
void init(SchoolMap &M);
void createMap(SchoolMap *M);   //创建地图
int getPosId(SchoolMap &M, string name); //获取目标位置id
void getPosInfo(SchoolMap &M, string name); //获取目标位置简介
void queryShortEdge(SchoolMap *M); //查询两地之间的最短路线
void queryAround(SchoolMap *M); //搜索周围景点
void addPos(SchoolMap *M);
void deletePost(SchoolMap *M);

/**
 *  初始化图
 *  参数：SchoolMap引用
 */
void createMap(SchoolMap &M){
    int i,j;
    for (i = 0; i < MAX_POS_NUM; i++)
    {
        for (int j = 0; j < MAX_POS_NUM; j++)
        {
            if(i==j) M.Edge[i][j] = 0;
            else M.Edge[i][j] = INFINITY;
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

void findShortRoute(SchoolMap *M, vector<int> &route, int startPos, int endPos, int midPos){
    if(startPos==endPos) return;
        route.push_back(midPos);
    if(!M->FolyedMap[startPos][midPos].interalNode.empty()){
        midPos=M->FolyedMap[startPos][midPos].interalNode[0];
        findShortRoute(M, route,startPos, midPos, midPos);
    }
    if(!M->FolyedMap[midPos][endPos].interalNode.empty()){
        midPos=M->FolyedMap[midPos][endPos].interalNode[0];
        findShortRoute(M, route, midPos, endPos, midPos);
    }

}

/**
 *  程序初始化
 *  参数：SchoolMap引用
 */
void init(SchoolMap &M){

    string visualSchoolMap[]={
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓",
        "┃  ╭──────────╮                                                                ╭─────────╮     ┃",
        "┃  |  华山区   |============================================================== |  启林区  |    ┃",
        "┃ ╰────────────╯   ‖                                                          ╰──────────╯    ┃",
        "┃                  ‖                     ╭─────────╮                              ‖          ┃",
        "┃                  ‖==================== |  图书馆  |                             ‖          ┃",
        "┃                  ‖                    ╰───────────╯                             ‖          ┃",
        "┃                  ‖                       ‖                                   ‖          ┃",
        "┃                  ‖                       ‖                                   ‖          ┃",
        "┃                  ‖                       ‖                                   ‖          ┃",
        "┃                ╭────╮                    ‖                           ‖          ┃",
        "┃                | 校|                    ‖                          ‖          ┃",
        "┃                | 史|                       ╭────────╮                       ╭──────────╮    ┃",
        "┃                | 馆|========================|  行政楼 |======================|  泰山区   |   ┃",
        "┃                ╰────╯                      ╰──────────╯                         ╰────────────╯   ┃",
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
    };
    for(int i=0;i<sizeof(visualSchoolMap)/sizeof(visualSchoolMap[0]);i++){
        cout<<visualSchoolMap[i]<<endl;
    }


    createMap(M);

    M.vn = 6;
    M.en = 8;

    M.Edge[0][1]=800;
    M.Edge[0][2]=2000;
    M.Edge[2][3]=400;
    M.Edge[2][4]=200;
    M.Edge[5][1]=3500;
    M.Edge[5][3]=1000;
    M.Edge[5][4]=600;

    M.Edge[1][0]=800;
    M.Edge[2][0]=2000;
    M.Edge[3][2]=400;
    M.Edge[4][2]=200;
    M.Edge[1][5]=3500;
    M.Edge[3][5]=1000;
    M.Edge[4][5]=600;

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
        M.pos[i].intro=pos[i].intro;
        M.pos[i].name=pos[i].name;
    }

    for(int i=0;i<M.vn;i++){
        cout<<getPosByIdx(&M,i)<<"  ";
        for(int j=0;j<M.vn;j++)
            printf("%10d",M.Edge[i][j]);
        cout<<endl;
    }

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

//            cout<<"====="<<k<<"====="<<endl;
//            for(int i=0;i<M.vn;i++){
//                cout<<getPosByIdx(&M,i)<<"  ";
//                for(int j=0;j<M.vn;j++)
//                    printf("%10d",M.FolyedMap[i][j].distance);
//                cout<<endl;
//            }
    }



//    SchoolMap *G=&M;
//    vector<int>::iterator node;
//    for(int i=0;i<M.vn;i++)
//        for(int j=0;j<M.vn;j++){
//            if(M.FolyedMap[i][j].interalNode.size()==0) continue;
//            cout<<M.pos[i].name<<"  "<<M.pos[j].name<<"   ";
//            for(node=M.FolyedMap[i][j].interalNode.begin();
//                node!=M.FolyedMap[i][j].interalNode.end();node++)
//                {
//                    cout<<getPosByIdx(G, *node)<<" ";
//                }
//            cout<<endl;
//        }

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

    cout<<"距离为：";
    cout<<M->FolyedMap[startPosId-1][endPosId-1].distance;
    cout<<"路线为：";
    int len=M->FolyedMap[startPosId-1][endPosId-1].interalNode.size();

    for(int i=0;i<len;i++){
        int id = M->FolyedMap[startPosId-1][endPosId-1].interalNode[i];
        cout<<getPosByIdx(M,id)<<" ";
    }
}

//入口

int main()
{
    SchoolMap *M;
    M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);

//    string name;
//    cout<<"请输入要查询的地址：";
//    cin>>name;
//    getPosInfo( M, name);
//    cout<<getPosId(M, name)<<endl;

    queryShortEdge(M);
}
