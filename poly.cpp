#pragma once

#include <iostream>

class Geometry
{
	int m_nx;
	int m_ny;
public:
	Geometry(){};
	Geometry(int x, int y) : m_nx(x), m_ny(y)
	{
		std::cout << "Geometry::ctro" << std::endl;
	}
	virtual ~Geometry()
	{
		std::cout << "Geometry::dtro" << std::endl;
	}

	virtual void Draw() { std::cout << "Geometry::Draw" << std::endl; };
};

class Triangle : public Geometry
{
	int m_nx1, m_nx2, m_ny1, m_ny2;
public:
	Triangle(int x, int y, int x1, int x2, int y1, int y2) 
	: Geometry(x,y), m_nx1(x1), m_nx2(x2), m_ny1(y1), m_ny2(y2) 
	{
		std::cout << "Triangle::ctro" << std::endl;
	}
	~Triangle() 
	{
		std::cout << "Triangle::dtro" << std::endl;
	}
	void Draw() { std::cout << "Triangle::Draw" << std::endl; };
};

class Rectangle : public Geometry
{
	int m_nwidth, m_nheight;
public:
	Rectangle(int x, int y, int width, int height)
	: Geometry(x,y), m_nwidth(width), m_nheight(height)
	{
		std::cout << "Rectangle::ctro" << std::endl;
	}
	~Rectangle()
	{
		std::cout << "Rectangle::dtro" << std::endl;
	}
	void Draw() { std::cout << "Rectangle::Draw" << std::endl; };
};

class Circle : public Geometry
{
	int m_radius;
public:
	Circle(int x, int y, int radius)
	: Geometry(x, y), m_radius(radius)
	{
		std::cout << "Circle::ctro" << std::endl;
	}
	~Circle()
	{
		std::cout << "Circle::dtro" << std::endl;
	}

	void Draw() { std::cout << "Circle::Draw" << std::endl; };
};

void DrawShape(Geometry* shape)
{
	shape->Draw();
}//파생클래스에 대한 정보없이도 접근이 가능하다. 나중에 많이 쓰인다.

int main()
{
	//Triangle tri(10, 20, 11, 21, 12, 22);
	//Rectangle rect(20, 30, 100, 200);
	//Circle cir(30, 40, 300);

	//typedef enum{ETRIANGLE, ERECTANGLE, ECIRCLE, ETYPE_MAX} EGEO_TYPE;
	//const int type_size = 3;

	///*
	//Geometry* _Geos[type_size] = { nullptr, };
	//
	//_Geos[ETRIANGLE] = &tri;
	//_Geos[ERECTANGLE] = &rect;
	//_Geos[ECIRCLE] = &cir;
	//*/
	//
	//Geometry * _Geos[type_size] = { &tri, &rect, &cir}; // 주석보다 이것이 편하다.

	//for (int i = ETRIANGLE; i < ETYPE_MAX; i++)
	//	_Geos[i]->Draw();

	//getchar();
	
	Triangle* tri = new Triangle(10, 20, 11, 21, 12, 22);
	Rectangle* rect = new Rectangle(20, 30, 100, 200);
	Circle* cir = new Circle(30, 40, 300);

	typedef enum { ETRIANGLE, ERECTANGLE, ECIRCLE, ETYPE_MAX } EGEO_TYPE;
	const int type_size = 3;

	/*
	Geometry* _Geos[type_size] = { nullptr, };

	_Geos[ETRIANGLE] = &tri;
	_Geos[ERECTANGLE] = &rect;
	_Geos[ECIRCLE] = &cir;
	*/

	//Geometry * _Geos[type_size] = { tri, rect, cir }; // 주석보다 이것이 편하다.

	//for (int i = ETRIANGLE; i < ETYPE_MAX; i++)
	//	_Geos[i]->Draw();

	DrawShape(tri);
	DrawShape(rect);
	DrawShape(cir);//파생클래스에 대한 정보가 없어도 포인터로 접근이 가능하다.(virtual사용하면)

	delete tri;
	delete rect;
	delete cir;
	//Geos는 무엇을 지워야하는지 가르키지 않으므로 지울려면 부모클래스의 소멸자에 virtual를 줘야 함
	getchar();
	return 1;
}