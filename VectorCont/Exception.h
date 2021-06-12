#pragma once
#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <iostream>

class Exception
{
public:
	virtual void ShowMessage() = 0;
};

class BadSpaceDimensionException : public Exception
{
public:
	void ShowMessage()
	{
		std::cout << "\nРазмерность пространства некорректна" << std::endl;
	}
};

class BadVectorDimensionException : public Exception
{
public:
	void ShowMessage()
	{
		std::cout << "\nРазмерности векторов не совпадают" << std::endl;
	}
};

class ZeroDivideException : public Exception
{
public:
	void ShowMessage()
	{
		std::cout << "\nДеление на 0" << std::endl;
	}
};

class LimitExceedingException : public Exception
{
public:
	void ShowMessage()
	{
		std::cout << "\nПревышены размеры вектора" << std::endl;
	}
};
#endif // !_EXCEPTION_H