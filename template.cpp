#pragma once

#include <iostream>

template<class T>
void swap(T& lsh, T& rhs)
{
	T tmp(lsh);
	lsh = rhs;
	rhs = tmp;
}

int main()
{
	int a = 10;
	int b = 20;

	std::cout << "a=" << a << "b=" << b << std::endl;
	swap(a, b);//utility�� ���� move�� ���� �Ⱦ��� ������ �߶󳻱⸦ ���� Ȱ���� �� �ִ�.
	std::cout << "a=" << a << "b=" << b << std::endl;

	std::swap(a, b);
	std::cout << "a=" << a << "b=" << b << std::endl;
	getchar();
	return 1;
}