// Weronika Szydlik 13c
// Wisielec

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>

//rysunek
auto drawing (int mistakes) -> void
{
	switch (mistakes)
	{
		case 0:
		{
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";


		}break;
		case 1:
		{
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                   \\  \n";

		}break;
		case 2:
		{
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                      \n";
			std::cout<<"                 / \\  \n";

		}break;
		case 3:
		{
			std::cout<<"                      \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 4:
		{
			std::cout<<"         _________    \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 5:
		{
			std::cout<<"         _________    \n";
			std::cout<<"                 \\|   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 6:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 7:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 8:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 9:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"       /|         |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 10:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"       /|\\        |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"                  |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 11:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"       /|\\        |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"       /          |   \n";
			std::cout<<"                 /|\\  \n";

		}break;
		case 12:
		{
			std::cout<<"         _________    \n";
			std::cout<<"        |        \\|   \n";
			std::cout<<"        0         |   \n";
			std::cout<<"       /|\\        |   \n";
			std::cout<<"        |         |   \n";
			std::cout<<"       / \\        |   \n";
			std::cout<<"                 /|\\  \n";


		}break;
		default:
		{

		}break;

	}

}

//wypelnienie wektora slowami z pliku
auto fill (std::vector<std::string>& all_words) -> void
{
	std::ifstream file;
	file.open("words.txt");
	std::string word;

	while (std::getline(file,word))
	{
		all_words.push_back(word);
	}

	file.close();
}

//losowanie slowa z wektora
auto drawing_word (std::vector<std::string> all_words) -> std::string
{
	int l = all_words.size();
	srand(time(NULL));
	int position = rand()%l;

	return all_words[position];
}

//szukanie wprowadzonej litery
auto searching (std::string& temp, int length,  char x) -> bool
{
	bool answer = false;
	for (int i=0;i<length;i++)
	{
		if (temp[i] == x)
		{
			temp[i] = '-';
			answer = true;
		}
	}
		return answer;
}


//sprawdzanie czy haslo zostalo odgadniete
auto is_guessed (std::string word, int length) -> bool
{
	for (int i=0;i<length;i++)
	{
		if (word[i]!='-' && word[i]!=' ') return false;
	}
	return true;
}

//usuwanie odgadnietych hasel
auto del (std::vector<std::string>& all_words, std::string x) -> void
{
	int i=0;
	while (all_words[i] != x) i++;
	
	all_words.erase(all_words.begin()+i);
}

auto main() -> int
{
	//utworzenie wektora ze slowami
	std::vector<std::string> all_words = {};
	fill(all_words);

	//utworzenie zmiennej do przechowywania slowa do odgadniecia
	std::string value;
	
	//utworzenie zmiennej informujacej o wygranej
	bool victory = false;
	
	//utworzenie zmiennej umozliwiajace ponowne zagranie
	std::string again = {"nie"};
	
	//utworzenie zmiennej przechowywujacej ilosc pomylek
	int mistakes = 0;
	
	//losowanie slowa
	value = drawing_word(all_words);
	int vl = value.size();
	std::string temp = value;


	while (!victory)
	{
	std::cout<<"+------------------------+\n";
	std::cout<<"|        WISIELEC        |\n";
	std::cout<<"+------------------------+\n";

	victory=is_guessed(temp,vl);
	
	//rysunek
	drawing(mistakes);

	//odkryte litery
	for (int i=0;i<vl;i++)
		{
			if (temp[i]==' ')
			{
				std::cout<<"  ";
			}
			else
			{
				if (temp[i]=='-') std::cout<<value[i]<<" ";
				else std::cout<<"_ ";
			}
		}
			std::cout<<"\n";

	if(!victory)
		{
			//podawanie liter
			char letter;
			std::cout<<"\nPodaj litere: ";
			std::cin>>letter;

			//szukanie wprowadzonej litery oraz zamiana malych liter na wielkie
			if (islower(letter)) letter = toupper(letter);
			bool find_letter = searching(temp,vl,letter);
			if (!find_letter) mistakes++;

		system("clear");
		}
		else
		{
			//wygrana
			system("clear");
			std::cout<<"WYGRANA! :D \n";
			std::cout<<"Czy chesz zagrac jeszcze raz? (tak/nie) \n";
			std::cin>>again;

			if (again == "tak")
			{
				del(all_words,value);
				
				if (all_words.size() == 0)
				{
					std::cout<<"\nBrawo! Udalo Ci sie odgadnac wszystkie hasla!\n";
					return 0;
				}
				else
				{
					value = drawing_word(all_words);
					temp = value;
					vl = value.size();
					mistakes=0;
					victory=false;
				}
			}
			else return 0;
			}

		if (mistakes == 12)
        {
			//przegrana
            std::cout<<"PRZEGRANA! :( \n";
            std::cout<<"Czy chesz zagrac jeszcze raz? (tak/nie) \n";
            std::cin>>again;

            if (again == "tak")
            {
                value = drawing_word(all_words);
                temp = value;
                vl = value.size();
                mistakes=0;
                victory=false;
            }
            else return 0;
        }

	}

	return 0;
}
