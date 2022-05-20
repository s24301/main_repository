#include <iostream>
#include <string>

auto pierwsze (int p, int k) -> void
{
	std::string str = {};
	
	for (int i=p;i<k;i++)
	{
		int il = 0;
		for (int j=2;j<=i;j++)
		{
			if (i%j==0) il++;
		}
		
		if (il == 1)
		{
			std::cout<<i<<" ";
			str = str+std::to_string(i)+" ";
		}
		
	}
	std::cout<<"\n";
	std::cout<<str<<"\n";
}

auto dane (std::string imie, double waga, int wzrost) -> void
{
	 std::cout<<"Imie: "<<imie<<std::endl;
	 std::cout<<"\n";
	 std::cout<<"Waga: "<<waga<<" kg\n";
	 std::cout<<"\n";
	 std::cout<<"Wzrost: "<<wzrost<<" cm"<<std::endl;
}

auto imiona (std::string p, std::string d) -> void
{
	if (p.size() > d.size()) std::cout<<"Pierwsze imie jest dluzsze od drugiego!\n";
	else
	{
		if (p.size() < d.size()) std::cout<<"Drugie imie jest dluzsze od pierwszego...\n";
		else std::cout<<"Imiona sa rownej dlugosci.\n";
	}
}

auto is_divisible (int a, int b) -> bool
{
	if (a%b==0) return true;
	else return false;
}

auto is_even(int x) -> bool
{
	if (is_divisible(x,2)) return true;
	else return false;
}

auto count_chars(std::string str, char z) -> int
{
	int il=0;
	int dl = str.size();
	for (int i=0;i<dl;i++)
	{
		if (str[i]==z) il++;
	}
	return il;
}

auto display(std::string str, int n) -> void
{
	int i = 0;
	int dl = str.size()-1;
	while (i<=dl)
	{
		std::cout<<str[i];
		i+=n;
	}
}

auto is_palindrome(std::string str) -> bool
{
	int dl = str.size()-1;
	for (int i=0;i<=dl/2;i++)
	{
		if (str[i] != str[dl-i]) return false; 
	}
	return true;
}

auto box_print (std::string tab[]) -> void
{
	int max = tab[0].size();
	
	for (int i=0;i<5;i++) 
	{
		int dl = tab[i].size();
		if (dl>max) max = dl;
	}
	
	for (int i=0;i<max+4;i++) std::cout<<"*";
	std::cout<<"\n";
	
	for (int i=0;i<5;i++)
	{
		std::cout<<"* ";
		std::cout<<tab[i];
		int dl = tab[i].size();
		if (dl<max)
		{
			for (int j=dl;j<max;j++) std::cout<<" ";
		}
		std::cout<<" *";
		std::cout<<"\n";
	}
	
	for (int i=0;i<max+4;i++) std::cout<<"*";
	std::cout<<"\n";
	
}

auto main() -> int
{
	//zad 1
	std::cout<<"______ZADANIE 1________\n";
	pierwsze(2,20);
	std::cout<<"\n";
	
	//zad 2
	std::cout<<"______ZADANIE 2________\n";
	dane("Weronika", 50, 160);
	std::cout<<"\n";
	
	//zad 3
	std::cout<<"______ZADANIE 3________\n";
	std::string p, d;
	std::cout<<"Prosze wprowadzic pierwsze imie: ";
	std::cin>>p;
	std::cout<<"Prosze wprowadzic drugie imie: ";
	std::cin>>d;
	imiona(p,d);
	std::cout<<"\n";
	
	//zad 4
	std::cout<<"______ZADANIE 4________\n";
	std::string name;
	int f=0, m=0;
	for (int i=0;i<5;i++) 
	{
		std::cout<<"Podaj imie do sprawdzenia: ";
		std::cin>>name;
		
		if (name[name.size()-1]=='a') f++;
		else m++;
	}
	std::cout<<"Ilosc imion zenskich: "<<f<<"\n";
	std::cout<<"Ilosc imion meskich: "<<m<<"\n";
	std::cout<<"\n";
	
	//zad 5
	std::cout<<"______ZADANIE 5________\n";
	int x=0;
	std::cout<<"Podaj liczbe do sprawdzenia: ";
	std::cin>>x;
	bool odp1 = is_even(x);
	if (odp1) std::cout<<x<<" jest parzysta.\n";
	else std::cout<<x<<" jest nieparzysta.\n";
	std::cout<<"\n";
	
	//zad 6
	std::cout<<"______ZADANIE 6________\n";
	std::cout<<"Podaj liczbe do sprawdzenia: ";
	std::cin>>x;
	bool odp2 = is_even(x);
	if (odp2) std::cout<<x<<" jest parzysta.\n";
	else std::cout<<x<<" jest nieparzysta.\n";
	std::cout<<"\n";
	
	//zad 7
	std::cout<<"______ZADANIE 7________\n";
	std::string napis;
	char znak;
	std::cout<<"Podaj string: ";
	std::cin>>napis;
	std::cout<<"Podaj znak: ";
	std::cin>>znak;
	int ile = count_chars(napis,znak);
	std::cout<<"Ilosc wystapien znaku "<<znak<<" w stringu "<<napis<<" to: "<<ile<<".\n";	
	std::cout<<"\n";
	
	//zad 8
	std::cout<<"______ZADANIE 8________\n";
	display("ABCDEFGHIJKLMNOPQRSTUVWXYZ",4);
	std::cout<<"\n";
	
	//zad 9
	std::cout<<"______ZADANIE 9________\n";
	bool palindrom = is_palindrome("kajak");
	if (palindrom) std::cout<<"Jest palindromem.\n";
	else std::cout<<"Nie jest palindromem.\n";
	
	palindrom = is_palindrome("abcdefg");
	if (palindrom) std::cout<<"Jest palindromem.\n";
	else std::cout<<"Nie jest palindromem.\n";
	std::cout<<"\n";
	
	//zad 10
	std::cout<<"______ZADANIE 10________\n";
	std::string box[5] = {"Hello", "World", "in", "a", "frame"};
	box_print(box);
	std::cout<<"\n";	
	
	return 0;
}
