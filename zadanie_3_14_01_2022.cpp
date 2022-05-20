#include <iostream>
#include <string>

auto NWD(int a, int b) -> int
{
	while (a!=b)
	{
		if (a>b)
		{
			a-=b;
		}
		else
		{
			b-=a;
		}
	}
	return a;
}

class Wymierne
{
	//1
	private:
	int numerator=1;
	int denominator=1;
	
	//2
	public:
	Wymierne (int p, int q)
	{
		//4
		simplify(p,q);
		numerator = p;
		denominator = q;
		std::cout<<numerator<<"/"<<denominator<<"\n";
	}
	
	Wymierne (int p)
	{
		numerator = p;
		std::cout<<numerator<<"/"<<denominator<<"\n";
	}
	
	//3
	auto simplify(int& p, int& q) -> void
	{
		int nwd = NWD(p,q);
		p = p/nwd;
		q = q/nwd;		
	}
	
	//5
	auto getX() -> int
	{
		return numerator;
	}
	
	auto getY() -> int
	{
		return denominator;
	}
	
	auto show() -> void
	{
		std::cout<<"num = "<<numerator<<", den = "<<denominator<<"\n";
	}
	
	//6
	auto sum(Wymierne x) -> Wymierne
	{
		if (x.denominator != denominator)
		{
			int temp = denominator;
			denominator = denominator * x.denominator;
			numerator = numerator * x.denominator;
			x.denominator = x.denominator * temp;
			x.numerator = x.numerator * temp;
		}
		int num = x.numerator+numerator;
		int den = denominator;
		simplify(num, den);
		Wymierne z (num, den);
		return z;
	}
	
	//7
	auto sum2(Wymierne x) -> void
	{
		if (x.denominator != denominator)
		{
			int temp = denominator;
			denominator = denominator * x.denominator;
			numerator = numerator * x.denominator;
			x.denominator = x.denominator * temp;
			x.numerator = x.numerator * temp;
		}
		int num = x.numerator+numerator;
		int den = denominator;
		simplify(num, den);
		denominator = den;
		numerator = num;
	}
	
	//8
	auto sum(int x) -> Wymierne
	{
		if (1 != denominator)
		{
			x = x*denominator;
		}
		int num = x+numerator;
		int den = denominator;
		simplify(num, den);
		Wymierne z (num, den);
		return z;
	}
	
};


auto main() -> int
{
	Wymierne w1(2,8);
	Wymierne w2(4);
	std::cout<<"\n";
	
	int den1=w1.getY();
	std::cout<<"Denominator w1: "<<den1<<"\n";

	int num2=w2.getX();
	std::cout<<"Numerator w2: "<<num2<<"\n";
	std::cout<<"\n";
	
	std::cout<<"w1: \n";
	w1.show();
	
	std::cout<<"w2: \n";
	w2.show();
	std::cout<<"\n";
	
	Wymierne w3 = w1.sum(w2);
	w3.show();
	std::cout<<"\n";
	
	Wymierne w4(3,4);
	w4.show();
	w4.sum2(w3);
	w4.show();
	std::cout<<"\n";
	
	Wymierne w5 = w4.sum(3);
	Wymierne w6 = w1.sum(1);
	w5.show();
	w6.show();
	
	return 0;
}
