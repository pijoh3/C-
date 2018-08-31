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
	swap(a, b);//utility를 보면 move를 통해 안쓰는 공간을 잘라내기를 통해 활용할 수 있다.
	std::cout << "a=" << a << "b=" << b << std::endl;

	std::swap(a, b);
	std::cout << "a=" << a << "b=" << b << std::endl;
	getchar();
	return 1;
}