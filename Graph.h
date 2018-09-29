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
	int vexs[20];  //保存一条路径
	Path *next;    //下一条路径

}*PathList;

class CGraph {
private:
	int m_AdjMatrix[20][20];
	Vex m_aVexs[20];
	int m_nVexNum;
	int **PATH;
	int l;
	void DFS(int nVex, bool aVisted[], int &nIndex, int **PATH,int path[],int &l); //深度优先搜索遍历图

public:
	void Init(void);
	int InserVex(Vex sVex);
	int InsertEdge(Edge sEdge);
	Vex GetVex(int nVex);                   //查询指定节点信息
	int FindEdge(int nVex, Edge aEdge[]);   //查询与指定顶点相连的边；
	int GetVexnum(void);                   //获取当前顶数
	void DFSTraverse(int nVex);      //获取遍历的结果
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);  //搜索两点间的最短路径
	int FindMinTree(Edge aPath[]);              //构造最小生成树
	bool IsallVisted(bool aVisted[]);
	int getPathNum();
	int **getPath();
	void  Dij(int nVexStart, int nVexEnd,bool aVisted[],int &PATHshort,Edge aPath[],int &k);
	void Prim( Edge aPath[], int &k, int &length);
};