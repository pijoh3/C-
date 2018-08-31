#pragma once  // 컴파일 중복 방지

#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
typedef int BOOL;
#define TRUE 1;
#define FALSE 0;

typedef unsigned char BYTE;

int func_sum(/*in*/ int a, /*in*/int b, /*out*/int * result)
{
	int error_code = -1;
	*result = a + b;

	return error_code = 1;//1 - success
} // BOOL보다 int로 하는게 나중에 코딩시 편리하다. BOOL은 두가지 경우밖에 반환하지 못하기 때문에
//반환된 에러코드를 통해 점검을 하도록

int func_sum(/*in*/ int a = -100, 
	         /*in*/int b = 0, 
	         /*in*/int c = 1, 
	         /*out*/int * result = nullptr)
{
	int error_code = -1;
	*result = a + b;

	return error_code = 1;//1 - success
}

int main()
{
	int ret = 1;
	std::string strCplus = "안녕하세요.\t c++강좌입니다.\n";
	strCplus += "저는 박병진입니다."; // 연산자를 통해 문자를 추가하는 것이 가능핟.
	int size = strCplus.find("박병진"); // 문자열을 찾아준다. 문자열에서 몇번째인지
	
									 //string output
	cout << strCplus << endl; // endl을 하면 내부 버퍼를 비워주는 역할도 한다.

	//data type & size
	int nA(1);
	unsigned short ushortA = 1;
	long lA(0);
	long long llA(100);
	size_t length = sizeof(nA); // unsigned int가 size_t
	length = sizeof(ushortA);
	length = sizeof(lA);
	length = sizeof(llA);

	//return
	BOOL ret_status = TRUE;

	//type casting
	//static_cast<int> .... (int)
	//dynamic_cast
	//const_cast    ->   const를 날려주고 형변환을 해준다.
	//reinterpret_cast<ClassABC*>((void*)m_pABC)  -> void 포인터인데 클래스를 지칭하는 포인터로 변환
	
	float fOrg = 0.126f;
	int nOrg = static_cast<int>(fOrg);

	const float PI = 3.14159f;

	//PI += 3.14159f;

	float* nPI = const_cast<float*>(&PI); // const변수를 const가 아닌 변수에 포인터로 받을때 오류를 방지하기 위해 const를 날려주고 뒤에것만 날려주고 받는다.

#define proc_Area 0
#define proc_Length 1
#define proc_eRect 2
#define proc_eCircle 3

	//Enum typedef으로 enum으로 묶어서 변수들의 성격을 저장하면 변수들의 
	//심볼을 확인할 수 있다.
	typedef enum {eArea = 0, ELength =1, eRect, eCircle} EGEOMETRY;
	EGEOMETRY geo = eArea;  
	geo = ELength;
	geo = eRect;
	geo = eCircle;

	int condi = 1;
	int result = 0;
		 if (condi == proc_Area)    result = 100;
	else if (condi == proc_Length)  result = 200;
	else if (condi == proc_eRect)   result = 300;
	else if (condi == proc_eCircle) result = 400;
	//define을 사용하면 숫자가 나올때마다 정의가 되어있는곳을 왔다갔다해야하는데 
	//enum으로 묶어 놓으면 옆에 바로바로 정의가 떠서 디버깅 시간 줄여줌

	//array
	const int month = 12;
	int Temp[month] = { -10, -5, 0, 5, 10, 20, 30, 40, 20, 10, 5, 3 };
	
	char name[] = "홍길동";

	cout << name << endl;

	//operator
	int sum = 0;
	int lhs = 100;
	int rhs = 200;
	sum = lhs + rhs;
	sum = lhs - rhs;
	sum = lhs * rhs;
	sum = lhs / rhs;
	sum = lhs % rhs;

	srand(time(NULL));

	int rnd = std::rand(); // 난수 발생위해 seed를 넣어줘야한다.
	int rand = rnd % 10;

	//증감연산자
	rand++;
	int kk = 10 + rand++;
	++rand;
	int kk1 = 10*++rand;

	rand--;
	rand--;
	--rand;
	--rand;

	//비교연산자
	int comTmp = 10;
	(comTmp > 100) ? comTmp = comTmp : comTmp = 100;

	int comTmpB = 100;
	(comTmp == comTmpB) ? comTmp = comTmp : comTmp = comTmpB;

	//논리연산자

	bool t = !false;
	//unsigned char = BYTE
	BYTE bytAndTmp = (0xAE >> 1) & 0xF0; //마스크 쓸때 많이 씀 A0로 나오는 것을 확인할 수 있다.
	BYTE bytORTmp = 0xAE | 0xF0;

	int ssum = 3 || 4;

	//SWITCH...case
	int geo_result = 0;
	switch (geo)
	{
	case eArea: geo_result = 10; break;
	case ELength: geo_result = 20; break;
	case eRect: geo_result = 30; break;
	case eCircle: geo_result = 40; break;
	default:
		break;
	}

	//loop
	//for
	//while
	//do ... while

	for (auto i = 0; i < 100; i++)
		std:cout << i + 10 << std::endl;

	std::vector<int> vecData(100, 10);
	for (auto i = 0; i < static_cast<int>(vecData.size()); i++)
		std:cout << /*vecData.at(i)*/vecData[i] << std::endl;
	//vecData.at을 통해 벡터 정확한 위치 파악가능하지만 속도가 느리다.

	std::vector<int>::iterator iter;
	typedef std::vector<int>::iterator vec_iter;

	for(iter = vecData.begin(); iter != vecData.end(); ++iter)
		std:cout << *iter << std::endl;

	int wh_cnt = 0;
	while (true)
	{
		(wh_cnt > 5) ? std::cout << wh_cnt << std::endl :
			std::cout << wh_cnt*10 << std::endl;

		if (!(wh_cnt > 5))
			wh_cnt++;
		else
			break;
	}

	//pointer and reference
	int nM = 100;
	int *pnM = &nM;

	int ** pp;
	//(int *)* _pp;
	pp = &pnM;//포인터의 포인터 더블 포인터에는
	//포인터의 주소값이 들어가고 그 주소 따라가면 값이 나온다.

	int * n_pMM = new int[30];

	delete[] n_pMM; // 동적 메모리 할당과 해제

	//std::vector<int> vecData(100,10);
	int ref_tmp = 100;
	int& refval = ref_tmp;//레퍼런스는 포인터와 달리 생성과 동시에 초기화를 해야 사용가능
//포인터는 런타임 시점. 레퍼런스는 컴파일 시점에서 확인.

	int lhs_a = 100;
	int rhs_b = 200;
	int rhs_c = -200;
	int result_func = 0;
	int ret_func = func_sum(lhs_a, rhs_b,rhs_c, &result_func);
	std::cout << "sum=" << lhs_a
		<< "+" << rhs_b 
		<< "+" << rhs_c
		<< "=>"
		<< result_func << std::endl;

	getchar();
	return ret;
}

