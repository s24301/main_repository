#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//additional
auto print (std::vector<int> vec) -> void
{
	for (auto elem : vec) std::cout<<elem<<" ";
}

auto print_s (std::vector<std::string> vec) -> void
{
	for (auto elem : vec) std::cout<<elem<<" ";
}

//zad_1
auto average_of (std::vector<int> vec) -> double
{
	double avg = 0;
	int dl = vec.size();
	for (int i=0;i<dl;i++) avg += vec[i];
	return avg/dl;
}

//zad_2
auto palindromes (std::string word) -> bool
{
	int i = 0;
	int j = word.size()-1;
	
	while (i!=j)
	{
		if (word[i]!=word[j]) return false;
		i++;
		j--;
	}
	
	return true;
}

auto filter_palindromes(std::vector<std::string> vec) -> std::vector<std::string>
{
	int dl = vec.size();
	std::vector<std::string> p = {};
	
	for (int i=0;i<dl;i++)
	{
		bool answer = palindromes(vec[i]);
		if (answer) p.push_back(vec[i]);
	}
	return p;
}

//zad_3
auto dot_product(std::vector<double> vec1, std::vector<double> vec2) -> double
{
	double il = 0;
	int dl = vec1.size();
	
	if (vec1.size()==vec2.size())
	{
		for (int i=0;i<dl;i++)
		{
			il = il + vec1[i]*vec2[i];
		}
	}
	
	return il;
}

//zad_4
struct student
{
	std::string name;
	std::string surname;
	std::vector<float> grades;
	
	student (std::string n, std::string s, std::vector<float> g)
	{
		name = n;
		surname = s;
		grades = g;
	}
};

auto average_of_ (std::vector<float> vec) -> double
{
	double avg = 0;
	int dl = vec.size();
	for (int i=0;i<dl;i++) avg += vec[i];
	return avg/dl;
}

//zad_5
auto split(std::string str) -> std::vector<std::string>
{
	int dl = str.size(), i=0;
	std::vector<std::string> answer = {};
	std::string sent={};
	
	while (i<dl)
	{
		sent={};
		if (str[i]!= ' ')
		{
			while (str[i]!=' ' && i<dl)
			{
				sent+=str[i];
				i++;
			}
		
//spr	answer.push_back("+");
		answer.push_back(sent);
		}
		i++;
	}
	
	return answer;
}

//zad_6
auto get_best_student(std::vector<student> students) -> student
{
	int dl = students.size();
	double max = average_of_(students[0].grades);
	int max_avg = 0;
	
	for (int i=0;i<dl;i++)
	{
		if (average_of_(students[i].grades)>max)
		{
			max = average_of_(students[i].grades);
			max_avg = i;
		}
	}
	
	return students[max_avg];
}

//zad_7
struct group
{
	std::string name;
	std::vector<student> members;	
	
};

auto add_student (group& x, student stud) -> void
{
	(x.members).push_back(stud);
}

auto members_of_the_group (group x) -> void
{
	int dl = (x.members).size();
	std::vector<student> tem = x.members;
	std::cout<<"Group name: "<<x.name<<"\n";
	std::cout<<"Students: \n";
	for (int i=0;i<dl;i++)
	{
		std::cout<<tem[i].name<<" "<<tem[i].surname<<"\n";
	}
	std::cout<<"\n";
}

//zad_8
auto sort(std::vector<float>& x) -> void
{
    int dl = x.size();
	for (int i=0;i<dl;i++)
	{
		for (int j=0;j<dl-1;j++)
		{
			if (x[j]>x[j+1]) std::swap(x[j],x[j+1]);
		}
	}
}

auto bubble_sort (std::vector<float>& x) -> void
{
	int dl = x.size();
	bool changes = true;
	
	for (int i=0;i<dl && changes;i++)
	{
		changes = false;
		for (int j=0;i<dl-1;j++)
		{
			if (x[j]>x[j+1])
			{
				std::swap(x[j],x[j+1]);
				changes = true;
			}
		}
	}
}

auto mediana (std::vector<float> x) -> double
{
	sort(x);
	int dl = x.size();
	int div_by_2 = dl/2;
	double m;
	
	if (dl%2==0) 
	{
		m = (x[div_by_2]+x[(div_by_2)+1])/2;
	}
	else m = x[div_by_2];
	
	return m;
}

auto best_groups_name (std::vector<group> grp) -> group
{
	int dl = grp.size();
	double max = 0;
	int k = 0;
	double med;
	
	for (int i=0;i<dl;i++)
	{
		group g = grp[i];
		std::vector<float> group_grades={};
		int dl_m = (g.members).size();
		
		for (int j=0;j<dl_m;j++)
		{
			int dl_g = (g.members[j].grades).size();
			for (int n=0; n<dl_g;n++)
			{
				float mark = g.members[j].grades[n];
				group_grades.push_back(mark);
			}
		}
		med = mediana(group_grades);
		if (med>max)
		{
			max = med;
			k = i;
		}
		
	}
	return grp[k];
}

//zad_9

auto if_contains (int a, std::vector<int> b, int length)
{
	for (int i=0;i<length;i++)
	{
		if (a == b[i]) return true;
	}
	
	return false;
}

auto contains_all (std::vector<int> a, std::vector<int> b) -> bool
{
	int dl1 = a.size();
	int dl2 = b.size();
	
	for (int i=0;i<dl1;i++)
	{
		for (int j=0;j<dl2;j++)
		{
			if(if_contains(a[i],b,dl2)==false) return false;
		}
	}
	
	return true;
}

//zad_10

auto location (std::string x, std::string abc) -> int
{
	int n = abc.size();
	for (int i=0;i<n;i++)
	{
		if (abc[i]==x[0]) return i;
	}
	return -1;
}

auto range (std::vector<std::string> str, std::string abc) -> std::vector<std::string>
{
	int dl1 = str.size();
	std::string x,y;
	int n=0;
	std::vector<std::string> answer={};
	std::string line={};
	
for (int i=0;i<dl1;i++)
{
		if(str[i]!="stop")
		{			
			x = str[i][0];
			int j=1;
			while (str[i][j]==' ') j++;
			y = str[i][j];
		
		
		if (x == y)
		{
			answer.push_back(x);
		}
		else
		{
		if (x<y)
		{
			line = {};
			n = location(x,abc);
			while (abc[n]!=y[0])
			{
				line += abc[n];
				n++;
			}
			line += abc[n];
			answer.push_back(line);
		}
		else
		{
			line = {};
			n = location(y,abc);
			while (abc[n]!=x[0])
			{
				line += abc[n];
				n++;
			}
			line += abc[n];
			answer.push_back(line);
		}
	}
	}
}
	return answer;
}

//================================================================================

auto main() -> int
{
	//zad1
	std::cout<<"=====Zadanie 1=====\n";
	std::vector<int> vec = {2,4,5,6,2,7,8};
	double avg = average_of(vec);
	std::cout<<"Srednia liczb {";
	print(vec);
	std::cout<<"} wynosi: "<<avg<<"\n";
	std::cout<<"\n";
	
	//zad2
	std::cout<<"=====Zadanie 2=====\n";
	std::vector<std::string> vec_s = {"kajak", "kot", "pies", "zakaz", "radar", "kok", "oko", "palindrom"};
	std::vector<std::string> vec_pal = filter_palindromes(vec_s);
	std::cout<<"Palindromy: ";
	print_s(vec_pal);
	std::cout<<"\n";
	
	//zad3
	std::cout<<"=====Zadanie 3=====\n";
	int n,k;
	std::vector<double> vec1 = {};
	std::vector<double> vec2 = {};
	std::cout<<"Podaj wielkosc wektorow: ";
	std::cin>>n;
	for (int i=0;i<n;i++)
	{
		std::cout<<"Podaj wartosc vec1: ";
		std::cin>>k;
		vec1.push_back(k);
		std::cout<<"Podaj wartosc vec2: ";
		std::cin>>k;
		vec2.push_back(k);
	}
	double product = dot_product(vec1,vec2);
	std::cout<<"Iloczyn skalarny jest rowny: "<<product<<"\n";
	std::cout<<"\n";
	
	//zad4
	std::cout<<"=====Zadanie 4=====\n";
	std::vector<float> g1 = {4, 5, 4.5, 3, 4, 4};
	student stud1 = {"Anna", "Kowalska",g1};
	double avg_stud = average_of_(stud1.grades);
	std::cout<<"Srednia ocen "<<stud1.name<<" "<<stud1.surname<<" wynosi: "<<avg_stud<<"\n";
	std::cout<<"\n";
	
	//zad5
	std::cout<<"=====Zadanie 5=====\n";
	std::string sentence = {};
	std::cout<<"Podaj zdanie: ";
	std::cin.ignore();
	std::getline(std::cin,sentence);
//spr 		std::cout<<sentence<<"\n";
	std::vector<std::string> output = split(sentence);
	print_s(output);
	std::cout<<"\n";
	
	//zad6
	std::cout<<"=====Zadanie 6=====\n";
	std::vector<student> students ={};
	student stud2 = {"Tomasz", "Nowak", {3, 5, 3, 4}};
	student stud3 = {"Maria", "Kowal", {5, 5, 4, 4.5}};
	student stud4 = {"Agnieszka", "Nowakowska", {4, 4, 5, 4}};
	students.push_back(stud1);
	students.push_back(stud2);
	students.push_back(stud3);
	students.push_back(stud4);
	student max = get_best_student(students);
	std::cout<<"Student z najwyzsza srednia to: "<<max.name<<" "<<max.surname<<"\n";	
	std::cout<<"\n";
	
	//zad7
	std::cout<<"=====Zadanie 7=====\n";
	group gr1 = {"Grupa 1", {stud2, stud4}};
	members_of_the_group (gr1);
	add_student (gr1,stud1);
	members_of_the_group (gr1);
	std::cout<<"\n";
	
	//zad8
	std::cout<<"=====Zadanie 8=====\n";
	group gr2 = {"Grupa 2", {stud1, stud3}};
	group gr3 = {"Grupa 3", {stud1,stud2,stud3,stud4}};
	std::vector<group> all_groups = {gr1,gr2,gr3};
//spr	for (auto elem : all_groups) std::cout<<elem.name<<" ";
	group best = best_groups_name(all_groups);
	std::cout<<"Najlepsza grupa: "<<best.name<<"\n";
	std::cout<<"\n";
	
	//zad9
	std::cout<<"=====Zadanie 9=====\n";
	std::vector<int> a1 = {2,3,4,5,8,4};
	std::vector<int> b1 = {0,1,2,3,4,5,6,7,8,9};
	std::cout<<"Czy wektor: {";
	print(a1);
	std::cout<<"} zawiera sie w wektorze: {";
	print(b1);
	std::cout<<"}?\n";
	bool odp = contains_all(a1,b1);
	if (odp) std::cout<<"Tak.";
	else std::cout<<"Nie.";
	std::cout<<"\n";
	
	//zad10
	std::cout<<"=====Zadanie 10=====\n";
	std::string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
	std::vector<std::string> pairs = {};
	std::cout<<"Podaj pary liter: ";
	for (std::string pair={}; std::getline(std::cin,pair) && pair!="stop"; pairs.push_back(pair))
	{
//		std::cout<<pair<<"\n";
		std::cout<<"Podaj pary liter: ";
	}
	std::cin.ignore();
	
// spr	pairs = {"a b", "b a", "a z", "x x", "stop"};
	std::vector<std::string> r = range(pairs,alphabet);
	print_s (r);
	std::cout<<"\n";
	
	return 0;
}
