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
class Square : public Shape <T> //наследуемые публичные данные класса родителя остануться публичными  внутри наследника
//если вместо public написать private то публичные методы и поля которые мы унаследуем станут приватными для наследника, 
//а protected при наследовании публично то мы заберем и public и protected родителя и положем себе в protected
{
public:
	Square(T width) : Shape <T> (width, width)//вызываем конструктор из родительского класса в классе наследнике
		, _width(width)//инициализируем аргументом из Square
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
//Variadic Template - Вариабельные шаблоны
	//template<typename ...Args>
	//class MyClass1
	//{
	//	void function(Args...args)//внутри функции  function использование sizeof...(Args) либо sizeof...(args) возвращает размер пачки(структуры)
	//		//( вданном случае они равны, так как пачка параметров функции получается из пачки шаблонов)
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
	//реализовать класс подобный out_of_range
	//конструктор  и метод ват который вернет строку что произошло 
	
//наследование шаблонных классов
	Square<int> s(5);
	std::cout << s.calculatorSquare() <<'\n';//вызываем функцию calculatorSquare Square
	std::cout << s.Shape<int>::calculatorSquare();//вызываем функцию calculatorSquare Shape
	
	MyClass<int, float,std::string> r;
	r.print_all(1, 2.3, "init");
	return 0;
}