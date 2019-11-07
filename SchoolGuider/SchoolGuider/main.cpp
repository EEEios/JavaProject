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

int getPosId(SchoolMap *M, string name){
    for(int i=0;i<M->vn;i++){
        if(M->pos[i].name.find(name)!=M->pos[i].name.npos){
            return i+1;
        }
    }
    return -1;
}

void getPosInfo(SchoolMap *M, string name){
    for(int i=0;i<M->vn;i++){
        if(M->pos[i].name.find(name)!=M->pos[i].name.npos){
            cout<<"�ص��飺";
            cout<<M->pos[i].intro<<endl;
        }
    }
}

string getPosById(SchoolMap *M, int id){
    return M->pos[id-1].name;
}

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
        for(int j=0;j<M.vn;j++)
            printf("%10d",M.Edge[i][j]);
        cout<<endl;
    }
    //Floyedͼ��ʼ��
    for(int i=0;i<M.vn;i++){
        for(int j=0;j<M.vn;j++)
            M.FolyedMap[i][j].distance=M.Edge[i][j];
    }

    vector<int>::iterator temp1,temp2,temp3;
    for(int k=0; k<M.vn; k++)
        for(int i=0; i<M.vn; i++)
            for(int j=0; j<M.vn; j++)
                if(M.FolyedMap[i][k].distance+M.FolyedMap[k][j].distance < M.FolyedMap[i][j].distance){
                    M.FolyedMap[i][j].distance=M.FolyedMap[i][k].distance+M.FolyedMap[k][j].distance;
                    M.FolyedMap[i][j].interalNode.push_back(k);

//                    temp3 = M.FolyedMap[i][j].interalNode.end();
//                    temp1 = M.FolyedMap[i][k].interalNode.begin();
//                    temp2 = M.FolyedMap[i][k].interalNode.end();
//                    M.FolyedMap[i][j].interalNode.insert(temp3,temp1,temp2);
//                    temp1 = M.FolyedMap[k][j].interalNode.begin();
//                    temp2 = M.FolyedMap[k][j].interalNode.end();
//                    M.FolyedMap[i][j].interalNode.insert(temp3,temp1,temp2);
                }

    SchoolMap *G=&M;
    for(int i=0;i<M.vn;i++)
        for(int j=0;j<M.vn;j++){

        cout<<getPosById(G, i);
//        <<"  "<<getPosById(G, j)<<"    ";
        cout<<"okok";
            for(int k=0;i<M.FolyedMap[i][j].interalNode.size();k++)
                cout<<getPosById(G, k)<<"  ";
            cout<<endl;
        }

//    for(int i=0;i<M.vn;i++){
//        for(int j=0;j<M.vn;j++)
//            printf("%10d",M.FolyedMap[i][j]);
//        cout<<endl;
//    }
//    SchoolMap *G=&M;
//    vector<int>::iterator node;
//    for(int i=0;i<M.vn;i++)
//        for(int j=0;j<M.vn;j++)
//            for(node=M.FolyedMap[i][j].interalNode.begin();
//                node!=M.FolyedMap[i][j].interalNode.end();node++)
//                {
//                    cout<<getPosById(G, *node)<<" "<<endl;
//                }

}

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
    cout<<"�����ĵ�Ϊ��";
    int len=M->FolyedMap[startPosId-1][endPosId-1].interalNode.size();

    for(int i=0;i<len;i++){
        int id = M->FolyedMap[startPosId-1][endPosId-1].interalNode[i];
        cout<<getPosById(M,id)<<" ";
    }
}

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

//    queryShortEdge(M);
}
