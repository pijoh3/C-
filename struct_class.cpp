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

	//pRectD2 = pRectD1; //얕은복사

	pRectD1->left =   pRectD2->left;
	pRectD1->top =    pRectD2->top;
	pRectD1->right =  pRectD2->right;
	pRectD1->bottom = pRectD2->bottom;

	std::memcpy(pRectD2, pRectD1, sizeof(KCCI_Class::RECTD));

	delete pRectD1; pRectD1 = nullptr;
	delete pRectD2; pRectD2 = nullptr;
	// 프로그램이 죽엇다. 얕은복사가 일어나면서 메모리의 데이터는 복사하지않고 주소만 복사해가는 꼴.(스왈로 카피)
	//깊은 복사를 하기 위해서는 각각의 정보를 카피를 해줘야한다. 혹은 맥카피를 통해 메모리 자체를 넘겨야 한다.

	return 1;















	KCCI_Class::Score kcciScore;
	kcciScore.strName = "용건이";
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
							  kcciScore.vecData.end(), 0); //functional 헤더 필요
	//kcciScore.fScoreAvg = (sum*1.0f) / kcciScore.vecData.size();
	//1.0을 곱해주면 굳이 캐스팅해주지 않아도 형변환됨
	kcciScore.fScoreAvg = static_cast<float> (sum) / kcciScore.vecData.size();

	//min, max
	auto minmax = std::minmax_element(kcciScore.vecData.begin(), kcciScore.vecData.end());
	// std::pair<int*, int*> minmax

	kcciScore.fScoreMin = *minmax.first;
	kcciScore.fScoreMax = *minmax.second;


	// for문을 돌릴것을 라이브러리 이용해서 퍼포먼스도 높이고 코드길이도 줄일 수 있다.
	return 1;
}