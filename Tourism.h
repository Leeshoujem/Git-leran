#pragma once
#include"Graph.h"
class CTourism
{private:
	CGraph m_Graph;
 public:
	 void CreatGraph(void);               //读取文件，创建景区景点图
	 void GetSpotInfo(void);              //查询指定景点信息，显示到相邻景点的距离。
	 void TravelPath(void);               //查询旅游景点导航路线
	 void FindShortPath(void);            //搜索两个景点间的最短路径
	 void DesignPath(void);               //查询铺设的电路规划图
	 void Fileread1(char*filename, Vex *v, int &n);
	 void Fileread2(char*filename, Edge *e, int &m);






};