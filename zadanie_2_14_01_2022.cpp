#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Punkt
{
	public:
	int x;
	int y;
	
	
	Punkt (int a, int b)
	{
		x = a;
		y = b;
		std::cout<<"Utworzono punkt("<<x<<", "<<y<<").\n";
	}
};

class Prostokat
{
	private:
	Punkt p1; //lewy gorny
	Punkt p2; //prawy dolny
	
	public:
	//1
	Prostokat (int k, int j, int i, int h) : p1(k,j), p2(i,h)
	{
	}
	
	//2
	Prostokat (Punkt t1, Punkt t2) : p1(t1), p2(t2)
	{
	}
	
	//3
	auto info () -> void
	{
		std::cout<<"Wierzcholki prostokata znajduja sie na wspolrzednych:\n";
		std::cout<<"Lewy gorny: ("<<p1.x<<", "<<p1.y<<")\n";
		std::cout<<"Prawy dolny: ("<<p2.x<<", "<<p2.y<<")\n";
	}
	
	//4
	auto pole () -> int
	{
		int answer = (abs(p1.x) + abs(p2.x))*(abs(p1.y) + abs(p2.y));
		return answer;
	}
	
	//5
	auto wewnatrz (Punkt const& p) -> bool
	{
		if (p.x>=p1.x && p.x<=p2.x && p.y<=p1.y && p.y>=p2.y) return true;
		else return false;
	}
	
	auto wewnatrz (int x, int y) -> bool
	{
		if (x>=p1.x && x<=p2.x && y<=p1.y && y>=p2.y) return true;
		else return false;
	}
	
};

auto main() -> int
{
	
	Punkt punkt1(-2,4), punkt2(8,0);
	Prostokat prostokat1(punkt1,punkt2);
	Prostokat prostokat2(-10,10,10,-10);
	std::cout<<"\n";
	
	prostokat1.info();
	prostokat2.info();
	std::cout<<"\n";
	
	int pole1 = prostokat1.pole();
	std::cout<<"Pole 1: "<<pole1<<" \n";
	int pole2 = prostokat2.pole();
	std::cout<<"Pole 2: "<<pole2<<" \n";
	std::cout<<"\n";
	
	Punkt p_new(2,4);
	bool answ1, answ2;
	std::cout<<"Czy punkt ("<<p_new.x<<", "<<p_new.y<<") znajduje sie w prostokacie 1?\n";
	answ1 = prostokat1.wewnatrz(p_new);
	if (answ1) std::cout<<"tak\n";
	else std::cout<<"nie\n";
	std::cout<<"Czy punkt (7, 8) znajduje sie w prostokacie 1?\n";
	answ2 = prostokat1.wewnatrz(7,8);
	if (answ2) std::cout<<"tak\n";
	else std::cout<<"nie\n";
	std::cout<<"\n";
	
	
		return 0;
}
