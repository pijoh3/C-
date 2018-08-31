#pragma once

#include "IObject.h"
#include <iostream>


int main()
{
	IObject obj;

	int giveMoney = 999999999;
	obj.setMoney(giveMoney);

	std::cout << "Current=" << obj.GetMoney() << std::endl;
	
	IObject * pObj = new IObject; // Ŭ������ ���� �Ҵ��� �����ϴ�.
	pObj->setMoney(giveMoney);

	std::cout << "Current=" << obj.GetMoney() << std::endl;

	RECTD rt;
	rt.left = 100;
	rt.top = 100;
	rt.right = 200;
	rt.bottom = 200;

	pObj->setRect(&rt);
	
	std::cout << "Left=" 
		<< pObj->GetRect()->left 
		<< std::endl;
	std::cout << "Top=" 
		<< pObj->GetRect()->top 
		<< std::endl;
	std::cout << "Right=" 
		<< pObj->GetRect()->right 
		<< std::endl;
	std::cout << "Bottom=" 
		<< pObj->GetRect()->bottom 
		<< std::endl;

	delete pObj;
	pObj = nullptr;

	getchar();
	return 1;
}