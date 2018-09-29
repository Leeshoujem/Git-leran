#include<iostream>
#include<cstdio>
#include"Graph.h"
#include"Tourism.h"
using namespace std;
void Print(void) {
	cout << "======景区管理系统========" << endl;
	cout << "1.创建景区景点图" << endl;
	cout << "2.查询景点信息" << endl;
	cout << "3.旅游景点导航" << endl;
	cout << "4.搜索最短路径" << endl;
	cout << "5.铺设电路规划" << endl;
	cout << "0.退出" << endl;
	cout << "请输入操作编号(0~5):" << endl;

}
int main(void) {
  int n;
  class  CTourism Ctourism;
  
  Print();
  while (cin>>n)
  {
	  switch (n) {
	  case 1:
		
		  Ctourism.CreatGraph(); break;
	  case 2:
		  Ctourism.GetSpotInfo(); break;
	  case 3:
		  Ctourism.TravelPath(); break;
	  case 4:
		  Ctourism.FindShortPath(); break;
	  case 5:
		  Ctourism.DesignPath(); break;
	  case 0:return 0; break;
	  default:break;
	  }
	
	  Print();

  }


}