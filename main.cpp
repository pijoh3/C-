#pragma once  // ������ �ߺ� ����

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
} // BOOL���� int�� �ϴ°� ���߿� �ڵ��� ���ϴ�. BOOL�� �ΰ��� ���ۿ� ��ȯ���� ���ϱ� ������
//��ȯ�� �����ڵ带 ���� ������ �ϵ���

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
	std::string strCplus = "�ȳ��ϼ���.\t c++�����Դϴ�.\n";
	strCplus += "���� �ں����Դϴ�."; // �����ڸ� ���� ���ڸ� �߰��ϴ� ���� ������.
	int size = strCplus.find("�ں���"); // ���ڿ��� ã���ش�. ���ڿ����� ���°����
	
									 //string output
	cout << strCplus << endl; // endl�� �ϸ� ���� ���۸� ����ִ� ���ҵ� �Ѵ�.

	//data type & size
	int nA(1);
	unsigned short ushortA = 1;
	long lA(0);
	long long llA(100);
	size_t length = sizeof(nA); // unsigned int�� size_t
	length = sizeof(ushortA);
	length = sizeof(lA);
	length = sizeof(llA);

	//return
	BOOL ret_status = TRUE;

	//type casting
	//static_cast<int> .... (int)
	//dynamic_cast
	//const_cast    ->   const�� �����ְ� ����ȯ�� ���ش�.
	//reinterpret_cast<ClassABC*>((void*)m_pABC)  -> void �������ε� Ŭ������ ��Ī�ϴ� �����ͷ� ��ȯ
	
	float fOrg = 0.126f;
	int nOrg = static_cast<int>(fOrg);

	const float PI = 3.14159f;

	//PI += 3.14159f;

	float* nPI = const_cast<float*>(&PI); // const������ const�� �ƴ� ������ �����ͷ� ������ ������ �����ϱ� ���� const�� �����ְ� �ڿ��͸� �����ְ� �޴´�.

#define proc_Area 0
#define proc_Length 1
#define proc_eRect 2
#define proc_eCircle 3

	//Enum typedef���� enum���� ��� �������� ������ �����ϸ� �������� 
	//�ɺ��� Ȯ���� �� �ִ�.
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
	//define�� ����ϸ� ���ڰ� ���ö����� ���ǰ� �Ǿ��ִ°��� �Դٰ����ؾ��ϴµ� 
	//enum���� ���� ������ ���� �ٷιٷ� ���ǰ� ���� ����� �ð� �ٿ���

	//array
	const int month = 12;
	int Temp[month] = { -10, -5, 0, 5, 10, 20, 30, 40, 20, 10, 5, 3 };
	
	char name[] = "ȫ�浿";

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

	int rnd = std::rand(); // ���� �߻����� seed�� �־�����Ѵ�.
	int rand = rnd % 10;

	//����������
	rand++;
	int kk = 10 + rand++;
	++rand;
	int kk1 = 10*++rand;

	rand--;
	rand--;
	--rand;
	--rand;

	//�񱳿�����
	int comTmp = 10;
	(comTmp > 100) ? comTmp = comTmp : comTmp = 100;

	int comTmpB = 100;
	(comTmp == comTmpB) ? comTmp = comTmp : comTmp = comTmpB;

	//��������

	bool t = !false;
	//unsigned char = BYTE
	BYTE bytAndTmp = (0xAE >> 1) & 0xF0; //����ũ ���� ���� �� A0�� ������ ���� Ȯ���� �� �ִ�.
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
	//vecData.at�� ���� ���� ��Ȯ�� ��ġ �ľǰ��������� �ӵ��� ������.

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
	pp = &pnM;//�������� ������ ���� �����Ϳ���
	//�������� �ּҰ��� ���� �� �ּ� ���󰡸� ���� ���´�.

	int * n_pMM = new int[30];

	delete[] n_pMM; // ���� �޸� �Ҵ�� ����

	//std::vector<int> vecData(100,10);
	int ref_tmp = 100;
	int& refval = ref_tmp;//���۷����� �����Ϳ� �޸� ������ ���ÿ� �ʱ�ȭ�� �ؾ� ��밡��
//�����ʹ� ��Ÿ�� ����. ���۷����� ������ �������� Ȯ��.

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

