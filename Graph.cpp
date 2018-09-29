#include "Graph.h"
#include<iostream>
#include<climits>
using namespace std;
void CGraph::DFS(int nVex, bool aVisited[], int & nIndex, int **PATH,int path[],int &l)
{
	/*for (int i = 0; i < 20; i++)
		cout <<"#######"<< endl<<aVisited[i] << "  " << path[i]<<endl;*///�������
	Edge e[50];
	if (IsallVisted(aVisited))
	{
		PATH[l] = new int [nIndex];
		for (int i = 0; i < nIndex; i++)
		{
			
			PATH[l][i] = path[i];
			
		}

		l++;
	}
	else
	{


		aVisited[nVex] = true;//��Ϊ�ѷ���
		path[nIndex++] = nVex;     //���ʶ���nVex
		for (int i = 0; i < FindEdge(nVex, e); i++)
		{
			if (!aVisited[e[i].vex2]||nIndex==m_nVexNum)
			{
				DFS(e[i].vex2, aVisited, nIndex, PATH,path,l);
				aVisited[e[i].vex2] = false;
				path[nIndex--] = -1;

			}
			else
			{
				//cout <<"----"<< aVisited[e[i].vex2] << "  "<<e[i].vex2 << endl;
			}
			
		}
	}
}
void CGraph::Init(void)
{
	m_nVexNum = 0;
	fill(m_AdjMatrix[0], m_AdjMatrix[0]+20*20, 0);//��λ�����ʼ��
	l = 0;
	PATH = new int *[MAX_VERTEX_NUM];
}

int CGraph::InserVex(Vex sVex)
{
	if (m_nVexNum == MAX_VERTEX_NUM)
	{
		cout << "��������";
		return -1;
	}
	m_aVexs[m_nVexNum++] = sVex;
	return 0;
}

int CGraph::InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2<0 || sEdge.vex2>m_nVexNum)
	{
		cout << "�±�Խ��";
		return -1;
	}
	m_AdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_AdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return 0;
}

Vex CGraph::GetVex(int nVex)
{
	return m_aVexs[nVex];
}

int CGraph::FindEdge(int nVex, Edge aEdge[])
{
	int k = 0;

	for(int i = 0;i<m_nVexNum;i++)
		if (m_AdjMatrix[nVex][i] != 0) {
			aEdge[k].vex1 = nVex;
			aEdge[k].vex2 = i;
			aEdge[k].weight = m_AdjMatrix[nVex][i];
			k++;
		
		}
	return k;
}

int CGraph::GetVexnum(void)
{
	return m_nVexNum;
}

void CGraph::DFSTraverse(int nVex)
{
	int nIndex = 0;
	int path[MAX_VERTEX_NUM];
	l = 0; 
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
		path[i] = -1;
	bool aVisited[MAX_VERTEX_NUM] = { false };
	DFS(nVex, aVisited, nIndex, PATH,path,l);

	
}

int CGraph::FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{ 
  bool aVisted[20] = { false };
  int PATHshort = 0;
  int k = 0;
  Dij(nVexStart, nVexEnd, aVisted, PATHshort,aPath,k);
  return PATHshort;
}

int CGraph::FindMinTree(Edge aPath[])
{
	bool aVisted[20] = { false };
	
	int k = 0;
	int length = 0;
	Prim( aPath, k, length);
	return length;
}

bool CGraph::IsallVisted(bool aVisted[])
{for(int i = 0;i<m_nVexNum;i++)
	if(!aVisted[i])
	   return false;
return true;
}

int CGraph::getPathNum()
{
	return l;
}

int ** CGraph::getPath()
{
	return PATH;
}

void CGraph::Dij(int nVexStart, int nVexEnd, bool aVisted[],int &PATHshort,Edge aPath[],int &k)
{
	if (aVisted[nVexEnd])
		return;
	aVisted[nVexStart] = true;
	Edge e[20];
	int Pshort = INT_MAX;
	int t = FindEdge(nVexStart, e);
	int i;
	int tt = INT_MAX;            //��¼ǰһ�ڵ��±�
	int j = 0;                  //��¼��ǰ��̽ڵ��±�
	for (i = 0; i < t; i++)
	{
		if (!aVisted[e[i].vex2])
		{
			if (e[i].weight < Pshort || e[i].vex2 == nVexEnd)
			{
				Pshort = e[i].weight;
				aVisted[e[i].vex2] = true;
				j = i;
				if (tt < 20)
				{
					aVisted[tt] = false;
				}
				tt = e[i].vex2;
			}
			
		}
	}
	aPath[k++] = e[j];
	PATHshort += Pshort;
	Dij(e[j].vex2, nVexEnd, aVisted, PATHshort, aPath, k);
}

void CGraph::Prim( Edge aPath[], int &k, int &length)
{
	int tree[20][20];
	fill(tree[0], tree[0] + 20 * 20, INT_MAX);
	
	for (int i = 0; i < m_nVexNum; i++)
		for (int j = 0; j < m_nVexNum; j++)
			if(m_AdjMatrix[i][j]!=0)
			tree[i][j] = m_AdjMatrix[i][j];        //��ʼ����С������

	bool aVisited[20] = { false };
	aVisited[0] = true;
	int Path[20] = { 0 };
	int cur = 0;                                   //��ǰ�ڵ�
	int t = 0;                                    //��һ���ڵ�
	aPath[0].vex1 = 0;
	int minor;                                    //���·��
	                   
	for (int i = 0; i < m_nVexNum; i++)
		Path[i] =  tree[cur][i];               //��ʼ����ÿ����a�ڽӵĵ�ľ������Path
	for (int i = 1 ; i <m_nVexNum ; i++)
	{
		 minor = INT_MAX;
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (!aVisited[j] && Path[j]< minor)                      //�ҵ�δ���ʵĵ��У����뵱ǰ��С������������С�ĵ�  
			{
				minor = Path[j];
				t = j;
			}
		}
		aVisited[t] = true;
		aPath[k].vex2 = t;
		aPath[k].weight = minor;
		k++;
		length += minor;
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (!aVisited[j] && Path[j]>tree[t][j])         //ִ�и��£��������뵱ǰ��ľ���������͸���
			{
				Path[j] = tree[t][j];
			}
		}
	}
	for (int i = 1; i < k; i++)
		for (int j = 0; j < m_nVexNum; j++)
			if (tree[j][aPath[i].vex2] == aPath[i].weight)
				aPath[i].vex1 = j;
	return;
}

