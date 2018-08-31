#pragma once

#include <iostream>
#include <string>

class Date {
	//private:
	int m_Year = 0;
	int m_Month = 0;
	int m_Day = 0;

public:
	Date() {};
	~Date() {};
	void SetDate(int yy = 2018, int mm = 8, int dd = 28)
	{
		if (!(yy >= 2000 && yy < 3000))
		{ 
			std::cout << yy << "������ ������ϴ�." << std::endl;
			return;
		}
		m_Year = yy; m_Month = mm; m_Day = dd;
	}
	int  getYear(void) { return m_Year; };
	int  getMonth() { return m_Month; };
	int  getDay(){ return m_Day; };

};
class Employee
{
	//string - str
	//int - n
	//double - db or d
	//point - p      ->�̷��� ������ִ°� ����
	std::string m_strName;
	std::string m_strAddress;
	std::string m_strTelNo;
	Date	    m_JoinDate;

	// int m_int_cout;
	// int m_int_step_count;

	// int m_nCount;
	// int m_nStepCount;    
	//-> ������� �����ڵ� ������ ���� �� �����(���������� �������ҽ� ��θ��� �ʿ�)

public:
	Employee() //default ctor
	{
		std::cout << "Employee ctor()" << std::endl;
	}
	Employee(std::string name, std::string address, std::string telno, Date joindate)
		: m_strName(name)
		, m_strAddress(address)
		, m_strTelNo(telno)
		, m_JoinDate(joindate)
	{
		std::cout << "Employee ctor()" << std::endl;

		m_strName;
		m_strAddress;
		m_strTelNo;
		m_JoinDate;

	}
	~Employee()
	{
		std::cout << "Employee dtor()" << std::endl;
	}
	void DisplayEmployee()
	{
		std::cout << m_strName << "\t"
			<< m_strAddress << "\t"
			<< m_strTelNo << "\t"
			<< m_JoinDate.getYear() << "\t" 
			<< m_JoinDate.getMonth() << "\t"
			<< m_JoinDate.getDay() << "\t"
			<< std::endl;
	}

	//double payCheck();
	double payCheck()
	{
		std::cout << "Employee::payCheck()" << "1000" << std::endl;
		return 0.0f;
	}
};

class RegularEmployee : public Employee
{
	double m_dSalary = 0.0f;
public:
	RegularEmployee()
	{
		std::cout << "RegularEmployee ctor()" << std::endl;
	}
	RegularEmployee(std::string name, std::string address, std::string telno, Date joindate)
		: Employee(name, address, telno, joindate)
		, m_dSalary(0.0f)  //��ӹ����� �ڽ�Ŭ������ �ʱ�ȭ ���ִ� �� �߿�!!!!
	{
		std::cout << "RegularEmployee ctor()" << std::endl;
	}
	~RegularEmployee()
	{
		std::cout << "RegularEmployee dtor()" << std::endl;
	}

	double payCheck()
	{
		std::cout << "RegularEmployee::payCheck()" << "2000" << std::endl;
		return 0.0f;
	}
};

class SpecialEmployee : public Employee
{
	double m_dSalary = 0.0f;
public:
	SpecialEmployee(std::string name, std::string address, std::string telno, Date joindate)
		: Employee(name, address, telno, joindate)
		, m_dSalary(0.0f)  
	{
		std::cout << "SpecialEmployee ctor()" << std::endl;
	}
	~SpecialEmployee()
	{
		std::cout << "SpecialEmployee dtor()" << std::endl;
	}

	double payCheck()
	{
		std::cout << "SpecialEmployee::payCheck()" << "3000" << std::endl;
		return 0.0f;
	}
};
int main()
{
	Date joinDate;
	joinDate.SetDate(2018, 8, 28);

	RegularEmployee *rEmp = new RegularEmployee("ȫ�浿", "ȭ��", "011-234-4567",joinDate);
	rEmp->DisplayEmployee();
	rEmp->payCheck();

	SpecialEmployee *sEmp = new SpecialEmployee("ȫ�浿", "ȭ��", "011-234-4567", joinDate);
	sEmp->DisplayEmployee();
	sEmp->payCheck();

	Employee* emp = sEmp; //upcasting? ���� ���ε�
	emp->payCheck();

	delete rEmp;
	delete sEmp;
	//Derived derived;
	//Derived *pDerived = new Derived;
	//Base * pBase = pDerived;
	getchar();
	return 1;
}

//��� ������ ����.
