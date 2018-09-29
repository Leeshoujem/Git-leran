#include<fstream>
#include<iostream>
#include "Tourism.h"
using namespace std;
void CTourism::CreatGraph(void)
{
	m_Graph.Init();
	Vex v[20];
	Edge e[20];
	int n = 0;
	int m = 0;
	char filename1[] = "C://Users//dell//Desktop//Vex.txt";
	char filename2[] = "C://Users//dell//Desktop//Edge.txt";
	Fileread1(filename1,v,n);
	for (int i = 0; i < n; i++)
		m_Graph.InserVex(v[i]);
	/*for (int i = 0; i < m_Graph.GetVexnum(); i++)
		cout << m_Graph.GetVex(i).num << " " << m_Graph.GetVex(i).name << " " << m_Graph.GetVex(i).desc << endl;*///输出测试
	Fileread2(filename2, e, m);
	for (int i = 0; i < m; i++)
		m_Graph.InsertEdge(e[i]);

	/*for (int i = 0; i < m; i++)
		cout << e[i].vex1 << "  " << e[i].vex2 << "  " << e[i].weight << endl;*///输出测试
}

void CTourism::GetSpotInfo(void)
{
	cout << "--------查询景点信息----------" << endl;
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
		cout << m_Graph.GetVex(i).num << "--" << m_Graph.GetVex(i).name << endl;
	int n;
	cout << "请输入你想要查询的景点编号:";
	cin >> n;
	cout << m_Graph.GetVex(n).name << endl;
	cout << m_Graph.GetVex(n).desc << endl;
	Edge e[50];
	int k = 0;
	cout << "----------周边景区-------------"<<endl;
	k = m_Graph.FindEdge(n, e);
	for (int i = 0; i < k; i++) {
		cout << m_Graph.GetVex(e[i].vex1).name << "->" << m_Graph.GetVex(e[i].vex2).name << "       " << e[i].weight << "m" << endl;
	
	}
}

void CTourism::TravelPath(void)
{
	int **PATH;
	int n;
	cout << "请输入起始点编号：";
	cin >> n;
	m_Graph.DFSTraverse(n);
	cout << "导游路线为:" << endl;
	PATH = m_Graph.getPath();
	int k = m_Graph.getPathNum();
	if (PATH != NULL)
		for(int i =0;i<k;i++)
	    {
			cout << "路线" << i+1 << ":";
			for (int j = 0; j < m_Graph.GetVexnum(); j++)
			{
				cout << m_Graph.GetVex(PATH[i][j]).name;
				if (j< m_Graph.GetVexnum()-1)
					cout << "->";
			}
			cout << endl;
		}
	
}

void CTourism::FindShortPath(void)
{
	cout << "--------搜索最短路径----------" << endl;
	for (int i = 0; i < m_Graph.GetVexnum(); i++)
		cout << m_Graph.GetVex(i).num << "--" << m_Graph.GetVex(i).name << endl;
	int start;
	int end;
	cout << "请输入起点的编号：";
	cin >> start;
	cout << "请输入终点的编号：";
	cin >> end;
	Edge e[MAX_VERTEX_NUM];
	int length = m_Graph.FindShortPath(start, end, e);
	int i;
	cout << "最短路径为：";
	for (i = 0; e[i].vex2 != end; i++)
		cout << m_Graph.GetVex(e[i].vex1).name << "->";
	if (e[0].vex2 == end)
		cout << m_Graph.GetVex(e[0].vex1).name << "->";
	cout << m_Graph.GetVex(e[i].vex2).name << endl;
	cout << "最短距离为："<<length<<endl;



}

void CTourism::DesignPath(void)
{
	Edge Path[20];
	int length = m_Graph.FindMinTree(Path);
	cout << "------铺设电路规划------" << endl;
	cout << "在以下两个景点间铺设电路：" << endl;
	for (int i = 0; i < m_Graph.GetVexnum()-1; i++)
		cout << m_Graph.GetVex(Path[i].vex1).name << " -> " << m_Graph.GetVex(Path[i].vex2).name << "   " << Path[i].weight << endl;
	cout << "铺设电路总长度:" << length << endl;

}

void CTourism::Fileread1(char* filename,Vex *v,int &n)
{
	
	ifstream in(filename, ios::in);
	if (!in.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> v[i].num;
		in >> v[i].name;
		in >> v[i].desc;
	}
	in.close();
}

void CTourism::Fileread2(char * filename, Edge * e, int & m)
{

	ifstream in(filename, ios::in);
	if (!in.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	int i = 0;
	while(!in.eof())
	{
		in >> e[i].vex1;
		in >> e[i].vex2;
		in >> e[i].weight;
		i++;
	}
	m = i;
	in.close();

}
