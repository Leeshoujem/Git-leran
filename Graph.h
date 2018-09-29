#pragma once
#define MAX_VERTEX_NUM 20


struct Vex {

	int num;
	char name[20];
	char desc[1024];
};
struct Edge {

	int vex1;
	int vex2;
	int weight;

};
typedef struct Path {
	int vexs[20];  //����һ��·��
	Path *next;    //��һ��·��

}*PathList;

class CGraph {
private:
	int m_AdjMatrix[20][20];
	Vex m_aVexs[20];
	int m_nVexNum;
	int **PATH;
	int l;
	void DFS(int nVex, bool aVisted[], int &nIndex, int **PATH,int path[],int &l); //���������������ͼ

public:
	void Init(void);
	int InserVex(Vex sVex);
	int InsertEdge(Edge sEdge);
	Vex GetVex(int nVex);                   //��ѯָ���ڵ���Ϣ
	int FindEdge(int nVex, Edge aEdge[]);   //��ѯ��ָ�����������ıߣ�
	int GetVexnum(void);                   //��ȡ��ǰ����
	void DFSTraverse(int nVex);      //��ȡ�����Ľ��
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);  //�������������·��
	int FindMinTree(Edge aPath[]);              //������С������
	bool IsallVisted(bool aVisted[]);
	int getPathNum();
	int **getPath();
	void  Dij(int nVexStart, int nVexEnd,bool aVisted[],int &PATHshort,Edge aPath[],int &k);
	void Prim( Edge aPath[], int &k, int &length);
};