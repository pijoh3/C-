#include "IObject.h"

#include <iostream>

IObject::IObject()
	:m_money(0),
	 m_pRect(nullptr)
{
	std::cout << "iobject ctor" << std::endl;

	std::cout << "m_PRect ctor" << std::endl;
	m_pRect = new RECTD;
	m_pRect->left   = 0;
	m_pRect->top    = 0;
	m_pRect->right  = 0;
	m_pRect->bottom = 0;

}


IObject::~IObject()
{
	std::cout << "iobject dtor" << std::endl;
	delete m_pRect;
	m_pRect = nullptr;
	std::cout << "m_PRect dtor" << std::endl;
}

void IObject::setMoney(int & money)
{
	m_money = money;
	std::cout << "iobject setMoney=" << money << std::endl;
}

void IObject::setRect(RECTD * rect)
{
	//this->setRect(rect);
	//m_pRect = rect;   ->>>�ּ�ó���� �Ȱ��� ���� ����, �ּ� �ȵȰ��� ���� ����
	m_pRect->left = rect->left;
	m_pRect->right = rect->right;
	m_pRect->top = rect->top;
	m_pRect->bottom = rect->bottom;
}

int IObject::GetMoney()
{
	return m_money;
}

RECTD* IObject::GetRect()
{
	return m_pRect;
}
