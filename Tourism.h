#pragma once
#include"Graph.h"
class CTourism
{private:
	CGraph m_Graph;
 public:
	 void CreatGraph(void);               //��ȡ�ļ���������������ͼ
	 void GetSpotInfo(void);              //��ѯָ��������Ϣ����ʾ�����ھ���ľ��롣
	 void TravelPath(void);               //��ѯ���ξ��㵼��·��
	 void FindShortPath(void);            //�����������������·��
	 void DesignPath(void);               //��ѯ����ĵ�·�滮ͼ
	 void Fileread1(char*filename, Vex *v, int &n);
	 void Fileread2(char*filename, Edge *e, int &m);






};