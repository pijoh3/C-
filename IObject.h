#pragma once

typedef struct _Rect
{
	double left = 0.0f;
	double top = 0.0f;
	double right = 0.0f;
	double bottom = 0.0f;
}RECTD;

class IObject
{
private:
	//data member variable
	int m_money = 100000;
	RECTD *m_pRect;

public:
	IObject(); //ctor
	~IObject(); //dtor

	//member function
	//set
	void setMoney(int& money);
	void setRect(RECTD* rect);
	
	//get
	int GetMoney();
	RECTD *GetRect();

};


