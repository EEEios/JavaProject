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
 * position�ṹ
 * id�����
 * name��λ������
 * intro��λ�ý���
 */
typedef struct{
    int id;
    string name;
    string intro;
}position;

/**
 * Folyͼ�ṹ
 * distance��������̾���
 * ineternalNode�����������·�е��ڲ���
 */
typedef struct{
    int distance;
    vector<int>interalNode;
}FloyNode;

/**
 * SchoolMap�ṹ
 * position��λ��
 * edges�����ӱ�
 * pos:������Ϣ
 */
typedef struct{
    position pos[MAX_POS_NUM];
    int Edge[MAX_POS_NUM][MAX_POS_NUM]; //��¼Ȩֵ
    FloyNode FolyedMap[MAX_POS_NUM][MAX_POS_NUM];
    int lastId;
    int vn;
    int en;
}SchoolMap;

/**
 *  ��ʼ��ͼ
 *  ������SchoolMap����
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
    }   //���ñ�ȨֵΪһ���ϴ����
}

/**
 *  �������Ʒ��ؾ���id
 *  ������SchoolMapָ�롢string name
 *  ����ֵ��id
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
 *  ���ݾ������ƴ�ӡ���
 *  ������SchoolMapָ�롢string name
 */
void getPosInfo(SchoolMap *M, string name){
    for(int i=0;i<M->vn;i++){
        if(M->pos[i].name.find(name)!=M->pos[i].name.npos){
            cout<<"�ص��飺";
            cout<<M->pos[i].intro<<endl;
        }
    }
}

/**
 *  ����������������
 *  ������SchoolMapָ�롢int idx
 */
string getPosByIdx(SchoolMap *M, int idx){
    return M->pos[idx].name;
}

/**
 *  ����������·��
 *  ������SchoolMapָ�롢int������startPos����ʼλ�á�endPos������λ�á�midPos���ڲ���
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

/**
 *  ����������·��
 *  ������SchoolMapָ�롢int������startPos����ʼλ�á�endPos������λ�á�midPos���ڲ���
 */
void FloyInit(SchoolMap *M){
    //Floyedͼ��ʼ��
    for(int i=0;i<M->vn;i++){
        for(int j=0;j<M->vn;j++)
            M->FolyedMap[i][j].distance=M->Edge[i][j];
    }
    for(int k=0; k<M->vn; k++){
        for(int i=0; i<M->vn; i++){
            for(int j=0; j<M->vn; j++){
                if(i==k||j==k)
                    continue;
                if(M->FolyedMap[i][k].distance+M->FolyedMap[k][j].distance < M->FolyedMap[i][j].distance){
                        M->FolyedMap[i][j].distance=M->FolyedMap[i][k].distance+M->FolyedMap[k][j].distance;
                        M->FolyedMap[i][j].interalNode.clear();
                        findShortRoute(M,M->FolyedMap[i][j].interalNode,i,j,k);
                }
            }
        }
    }
// ���Դ��룬�����������·�������ڲ���
    for(int i=0;i<M->vn;i++){
        for(int j=0;j<M->vn;j++){
            cout<<M->pos[i].name<<"  "<<M->pos[j].name<<" "<<M->FolyedMap[i][j].distance<<"====";
            for(int k=0;k<M->FolyedMap[i][j].interalNode.size();k++){
                cout<<M->pos[M->FolyedMap[i][j].interalNode[k]].name<<"->";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

/**
 *  ��ӡ��ͼ
 */
void printMap(){
    string visualSchoolMap[]={
        "   ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",
        "   ��  �q���������������������r                                                                �q�������������������r     ��",
        "   ��  |  ��ɽ��   |============================================================== |  ������  |    ��",
        "   �� �t�������������������������s   ��                                                         �t�����������������������s    ��",
        "   ��                  ��                     �q�������������������r                              ��          ��",
        "   ��                  ��==================== |  ͼ���  |                             ��          ��",
        "   ��                  ��                    �t�����������������������s                             ��          ��",
        "   ��                  ��                           ��                                 ��          ��",
        "   ��                  ��                           ��                                 ��          ��",
        "   ��                  ��                           ��                                 ��          ��",
        "   ��                �q�����r                           ��                                 ��          ��",
        "   ��                | У|                          ��                                 ��          ��",
        "   ��                | ʷ|                        �q�����������������r                       �q���������������������r    ��",
        "   ��                | ��|========================|  ����¥ |======================|  ̩ɽ��   |   ��",
        "   ��               �t���������s                       �t���������������������s                     �t�������������������������s   ��",
        "   ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������"
    };

    for(int i=0;i<(int)(sizeof(visualSchoolMap)/sizeof(visualSchoolMap[0]));i++){
        cout<<visualSchoolMap[i]<<endl;
    }
}

/**
 *  �����ʼ��
 *  ������SchoolMap����
 */
void init(SchoolMap &M){
    printMap();
    createMap(M);

    FILE *mapfp = fopen("mapEdge.txt","r");
    if(NULL == mapfp){
        cout<<"     �ļ���ʧ�ܣ����������"<<endl;
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
    FloyInit(&M);
}

/**
 *  ɾ���ڵ�
 *  ������SchoolMap����
 */
void deletePos(SchoolMap *M){
    string name;
    cout<<"     ����Ҫɾ���ľ���ȫ�ƣ�";
    cin>>name;
    M->vn--;
    int id=getPosId(M, name)-1;
    for(int i=0;i<id;i++){
        if(M->Edge[id][i]!=0||M->Edge[id][i]!=65535){
            M->en--;
        }
    }
}

/**
 *  �����ڵ�
 *  ������SchoolMap����
 */
void addPos(SchoolMap *M){
    //������
    string name;
    string intro;
    cout<<endl;
    cout<<"     ���������������ƣ�";
    cin>>name;
    cout<<"     �������������飺";
    cin>>intro;

    int idx=M->vn;
    M->vn++;
    M->lastId++;
    M->pos[idx].id=M->lastId;
    M->pos[idx].name=name;
    M->pos[idx].intro=intro;
    M->Edge[idx][idx]=0;

    //Edge����ǰ��Ԥ����
    for(int i=0;i<idx;i++){
        M->Edge[i][idx]=INF;
        M->Edge[idx][i]=INF;
    }

    //������
    int routeNum,dis;   //dis������
    string des; //des��Ŀ�ĵ�
    cout<<"     ����������·��Ŀ��";
    cin>>routeNum;
    M->en+=routeNum;
    for(int i=0;i<routeNum;i++){
        cout<<"     ����Ŀ�ĵغ;��루�м��ÿո�ָ�����";
        cin>>des>>dis;
        M->Edge[getPosId(M,des)-1][idx]=dis;
        M->Edge[idx][getPosId(M,des)-1]=dis;
    }
    FloyInit(M);
    cout<<"     �����ɹ�"<<endl;
}

/**
 *  ����folyͼ�����̾��룬����·�߽�������
 *  ������SchoolMap����
 */
void queryShortEdge(SchoolMap *M){
    string startPos,endPos;
    int startPosId,endPosId;

    cout<<"���������:";
    cin>>startPos;
    startPosId=getPosId(M, startPos);
    cout<<"�������յ�:";
    cin>>endPos;
    endPosId=getPosId(M, endPos);

    int startIdx = startPosId-1;
    int endIdx = endPosId-1;

    int len=M->FolyedMap[startIdx][endIdx].interalNode.size();
    int n=0,useFlag[len+1]={0}; //+1��ֹ����[0]�Ĵ���
    useFlag[len+1]=1;   //  ��ֹ���һλ���ָ��ţ�����Ϊ��ʹ��״̬
    int i,j,nextNode;

    cout<<"����Ϊ��"<<M->FolyedMap[startIdx][endIdx].distance<<endl;
    cout<<"·��Ϊ��";
    cout<<M->pos[startIdx].name<<"-->";

    int pathFinder = startIdx;  //Ѱ·�ڱ�
    while(n<len){   //���������ڲ���Ѱ·
                        /*��д����*/
            int dis=65535, curPos, use; //����֮��ľ���
            for(i=0;i<len;i++){
                if(useFlag[i]==1)
                    continue; //��ʹ����
                curPos=M->FolyedMap[startIdx][endIdx].interalNode[i];
                if(M->Edge[pathFinder][curPos]==65535||M->Edge[pathFinder][curPos]==0)
                    continue;
                if(M->Edge[pathFinder][curPos]<dis){
                    nextNode=curPos;
                    use=i;
                }
            }
            cout<<M->pos[nextNode].name<<"-->";
            pathFinder=nextNode;
            useFlag[use]=1;
            n++;
    }
    cout<<M->pos[endIdx].name<<endl;
    system("pause");
}


/**
 *  д���ļ���posΪ�����ļ���edgeΪͼ�ļ�
 *  ������SchoolMap����
 */
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
 *  ������о��������
 *  ������SchoolMap����
 */
void queryAllPos(SchoolMap *M){
    cout<<"У����Ҫ�������£�"<<endl;
    cout<<endl;
    cout.setf(ios::left);
    cout << setw(10) <<"��������"<< " "<<"������"<<endl;
    cout<<"---------------------------"<<endl;
    for(int i=0;i<M->vn;i++){
        cout.setf(ios::left);
        cout << setw(10) <<M->pos[i].name << " "<<M->pos[i].intro<<endl;
    }
}
