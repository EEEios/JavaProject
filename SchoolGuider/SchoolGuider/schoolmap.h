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
    int vn;
    int en;
}SchoolMap;


void init(SchoolMap &M);    //��ʼ��
void createMap(SchoolMap *M);   //������ͼ
int getPosId(SchoolMap &M, string name); //��ȡĿ��λ��id
void queryShortEdge(SchoolMap *M); //��ѯ����֮������·��
void queryAround(SchoolMap *M); //������Χ����

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
 *  �����ʼ��
 *  ������SchoolMap����
 */
void init(SchoolMap &M){

    string visualSchoolMap[]={
        "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",
        "��  �q���������������������r                                                                �q�������������������r     ��",
        "��  |  ��ɽ��   |============================================================== |  ������  |    ��",
        "�� �t�������������������������s   ��                                                         �t�����������������������s    ��",
        "��                  ��                     �q�������������������r                              ��          ��",
        "��                  ��==================== |  ͼ���  |                             ��          ��",
        "��                  ��                    �t�����������������������s                             ��          ��",
        "��                  ��                           ��                                 ��          ��",
        "��                  ��                           ��                                 ��          ��",
        "��                  ��                           ��                                 ��          ��",
        "��                �q�����r                           ��                                 ��          ��",
        "��                | У|                          ��                                 ��          ��",
        "��                | ʷ|                        �q�����������������r                       �q���������������������r    ��",
        "��                | ��|========================|  ����¥ |======================|  ̩ɽ��   |   ��",
        "��               �t���������s                       �t���������������������s                     �t�������������������������s   ��",
        "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������"
    };

    for(int i=0;i<(int)(sizeof(visualSchoolMap)/sizeof(visualSchoolMap[0]));i++){
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
        {1,"̩ɽ��","̩ɽ������"},
        {2,"������","����������"},
        {3,"����¥","��������"},
        {4,"ͼ���","��ũͼ���ܹ�"},
        {5,"Уʷ��","Уʷ������"},
        {6,"��ɽ��","��ɽ������"}
    };

    for(int i=0;i<M.vn;i++){
        M.pos[i].id = pos[i].id;
        M.pos[i].intro=pos[i].intro;
        M.pos[i].name=pos[i].name;
    }

    //Floyedͼ��ʼ��
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
    int pathFinder = startIdx;
    int len=M->FolyedMap[startIdx][endIdx].interalNode.size();
    int n=0,useFlag[len]={0};
    int i,j,nextNode;

    cout<<"����Ϊ��"<<M->FolyedMap[startIdx][endIdx].distance<<endl;
    cout<<"·��Ϊ��";
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
