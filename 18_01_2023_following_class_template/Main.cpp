#include <iostream>
#include <string>
template<typename T>
class Shape
{
public:
	Shape(T width, T heigth) : _width(width), _heigth(heigth) { std::cout << "Constructor Shape()" << std::endl;}
	T calculatorSquare()
	{
		return  _width * _heigth;
	}
	private:
	T _width = 0;
	T _heigth = 0;
};
template<typename T>
class Square : public Shape <T> //����������� ��������� ������ ������ �������� ���������� ����������  ������ ����������
//���� ������ public �������� private �� ��������� ������ � ���� ������� �� ���������� ������ ���������� ��� ����������, 
//� protected ��� ������������ �������� �� �� ������� � public � protected �������� � ������� ���� � protected
{
public:
	Square(T width) : Shape <T> (width, width)//�������� ����������� �� ������������� ������ � ������ ����������
		, _width(width)//�������������� ���������� �� Square
	{
		std::cout << "Constructor Square()" << std::endl;
	}

	T calculatorSquare()
	{
		return  _width * _width;
	}
private:
	T _width;
};
//Variadic Template - ������������ �������
	//template<typename ...Args>
	//class MyClass1
	//{
	//	void function(Args...args)//������ �������  function ������������� sizeof...(Args) ���� sizeof...(args) ���������� ������ �����(���������)
	//		//( ������� ������ ��� �����, ��� ��� ����� ���������� ������� ���������� �� ����� ��������)
	//	{
	//	
	//	
	//	}
	//};
//template<typename ...T>
//auto summ_all(T...args)
//{
//	return (args + ...);//(  args4 + ( args3 + (args1 + args2)))
//	//(...args + ) (((args1 + args2) + args3) + args4)
//}
template<typename ...T>
class MyClass
{
public:
	void print_all(T...args)
	{
		std::cout << sizeof...(args) << std::endl;
		(std::cout << ... << args) << std::endl;
	}
};
int main ()
{
	setlocale(LC_ALL, "Russian");
	//����������� ����� �������� out_of_range
	//�����������  � ����� ��� ������� ������ ������ ��� ��������� 
	
//������������ ��������� �������
	Square<int> s(5);
	std::cout << s.calculatorSquare() <<'\n';//�������� ������� calculatorSquare Square
	std::cout << s.Shape<int>::calculatorSquare();//�������� ������� calculatorSquare Shape
	
	MyClass<int, float,std::string> r;
	r.print_all(1, 2.3, "init");
	return 0;
}