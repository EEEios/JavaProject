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


/**
 *�û��˹���:
 *  1.��ѯ����֮�����̾��룻
 *  2.��ѯ��Χ���㣻
 *  3.��ѯͣ����ʹ�������
 *����˹��ܣ�
 *  1.�����û��˹���
 *  2.��ɾ����ڵ�
 *  3.��ѯͣ����ʹ�������
 */
void init(SchoolMap &M);
void createMap(SchoolMap *M);   //������ͼ
int getPosId(SchoolMap &M, string name); //��ȡĿ��λ��id
void getPosInfo(SchoolMap &M, string name); //��ȡĿ��λ�ü��
void queryShortEdge(SchoolMap *M); //��ѯ����֮������·��
void queryAround(SchoolMap *M); //������Χ����
void addPos(SchoolMap *M);
void deletePost(SchoolMap *M);

/**
 *  ��ʼ��ͼ
 *  ������SchoolMap����
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
 *  �����ʼ��
 *  ������SchoolMap����
 */
void init(SchoolMap &M){

    string visualSchoolMap[]={
        "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",
        "��  �q���������������������r                                                                �q�������������������r     ��",
        "��  |  ��ɽ��   |============================================================== |  ������  |    ��",
        "�� �t�������������������������s   ��                                                          �t���������������������s    ��",
        "��                  ��                     �q�������������������r                              ��          ��",
        "��                  ��==================== |  ͼ���  |                             ��          ��",
        "��                  ��                    �t�����������������������s                             ��          ��",
        "��                  ��                       ��                                   ��          ��",
        "��                  ��                       ��                                   ��          ��",
        "��                  ��                       ��                                   ��          ��",
        "��                �q���������r                    ��                           ��          ��",
        "��                | У|                    ��                          ��          ��",
        "��                | ʷ|                       �q�����������������r                       �q���������������������r    ��",
        "��                | ��|========================|  ����¥ |======================|  ̩ɽ��   |   ��",
        "��                �t���������s                      �t���������������������s                         �t�������������������������s   ��",
        "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������"
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

    for(int i=0;i<M.vn;i++){
        cout<<getPosByIdx(&M,i)<<"  ";
        for(int j=0;j<M.vn;j++)
            printf("%10d",M.Edge[i][j]);
        cout<<endl;
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

    cout<<"����Ϊ��";
    cout<<M->FolyedMap[startPosId-1][endPosId-1].distance;
    cout<<"·��Ϊ��";
    int len=M->FolyedMap[startPosId-1][endPosId-1].interalNode.size();

    for(int i=0;i<len;i++){
        int id = M->FolyedMap[startPosId-1][endPosId-1].interalNode[i];
        cout<<getPosByIdx(M,id)<<" ";
    }
}

//���

int main()
{
    SchoolMap *M;
    M=(SchoolMap *)malloc(sizeof(SchoolMap));
    init(*M);

//    string name;
//    cout<<"������Ҫ��ѯ�ĵ�ַ��";
//    cin>>name;
//    getPosInfo( M, name);
//    cout<<getPosId(M, name)<<endl;

    queryShortEdge(M);
}
