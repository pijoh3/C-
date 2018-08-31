#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <functional>
#include <numeric>
#include <algorithm>

namespace KCCI_Class
{
	typedef struct _Score
	{
		//input
		std::string strName = "";
		std::string strClassName = "";
		std::vector<int> vecData;

		//output
		float fScoreAvg = 0.f;
		float fScoreMin = 0.f;
		float fScoreMax = 0.f;
	}Score;

	typedef struct _Rect
	{
		double left = 0.0f;
		double top = 0.0f;
		double right = 0.0f;
		double bottom = 0.0f;
	}RECTD;
}

int main()
{
	KCCI_Class::RECTD *pRectD1 = new KCCI_Class::RECTD;
	KCCI_Class::RECTD *pRectD2 = new KCCI_Class::RECTD;
	pRectD1->left = 10;
	pRectD1->top = 10;
	pRectD1->right = 200;
	pRectD1->bottom = 200;

	//pRectD2 = pRectD1; //��������

	pRectD1->left =   pRectD2->left;
	pRectD1->top =    pRectD2->top;
	pRectD1->right =  pRectD2->right;
	pRectD1->bottom = pRectD2->bottom;

	std::memcpy(pRectD2, pRectD1, sizeof(KCCI_Class::RECTD));

	delete pRectD1; pRectD1 = nullptr;
	delete pRectD2; pRectD2 = nullptr;
	// ���α׷��� �׾���. �������簡 �Ͼ�鼭 �޸��� �����ʹ� ���������ʰ� �ּҸ� �����ذ��� ��.(���з� ī��)
	//���� ���縦 �ϱ� ���ؼ��� ������ ������ ī�Ǹ� ������Ѵ�. Ȥ�� ��ī�Ǹ� ���� �޸� ��ü�� �Ѱܾ� �Ѵ�.

	return 1;















	KCCI_Class::Score kcciScore;
	kcciScore.strName = "�����";
	kcciScore.strClassName = "C++";
/*
	kcciScore.vecData.resize(5, 0);
	kcciScore.vecData[0] = 90;
	kcciScore.vecData[1] = 80;
	kcciScore.vecData[2] = 85;
	kcciScore.vecData[3] = 95;
	kcciScore.vecData[4] = 98;
*/
	kcciScore.vecData.push_back(90);
	kcciScore.vecData.push_back(80);
	kcciScore.vecData.push_back(85);
	kcciScore.vecData.push_back(95);
	kcciScore.vecData.push_back(98);

	//average
	int sum = std::accumulate(kcciScore.vecData.begin(),
							  kcciScore.vecData.end(), 0); //functional ��� �ʿ�
	//kcciScore.fScoreAvg = (sum*1.0f) / kcciScore.vecData.size();
	//1.0�� �����ָ� ���� ĳ���������� �ʾƵ� ����ȯ��
	kcciScore.fScoreAvg = static_cast<float> (sum) / kcciScore.vecData.size();

	//min, max
	auto minmax = std::minmax_element(kcciScore.vecData.begin(), kcciScore.vecData.end());
	// std::pair<int*, int*> minmax

	kcciScore.fScoreMin = *minmax.first;
	kcciScore.fScoreMax = *minmax.second;


	// for���� �������� ���̺귯�� �̿��ؼ� �����ս��� ���̰� �ڵ���̵� ���� �� �ִ�.
	return 1;
}