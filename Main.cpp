#include<iostream>
#include<cstdio>
#include"Graph.h"
#include"Tourism.h"
using namespace std;
void Print(void) {
	cout << "======��������ϵͳ========" << endl;
	cout << "1.������������ͼ" << endl;
	cout << "2.��ѯ������Ϣ" << endl;
	cout << "3.���ξ��㵼��" << endl;
	cout << "4.�������·��" << endl;
	cout << "5.�����·�滮" << endl;
	cout << "0.�˳�" << endl;
	cout << "������������(0~5):" << endl;

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