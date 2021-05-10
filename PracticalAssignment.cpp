#include "EAN.h"
#include <list>
#include <fstream>

using namespace std;

void config(list<Bottle>&);
void print_receipt(list<Bottle>&,ofstream);

int main()
{
	string input = "";
	list<Bottle>Bottles = {Bottle("9002490100773","Can of Red Bull, 0,25 litres","0.15")
		,Bottle("6415600501781","Plastic Bottle of Coca-cola, 0,5 litres","0.2")
		,Bottle("5410228141266","Glass Bottle of Stella Artois beer, 0.33 litres","0.1")};
	do
	{
		cin >> input;
		if (input == "0000000000010")
		{
			config(Bottles);
		}
		else
		{
			auto it=find(Bottles.begin(), Bottles.end(), input);
			if (it != Bottles.end())
			{
				(*it).AnotherBottle();
			}
			else
			{
				if(input!= "0000000000001")
				cout << "EAN code not recognized\n";
			}
		}
	} while (input != "0000000000001");

	cout << "-------------\nRecycling finished.\n";
	print_receipt(Bottles, ofstream("receipt.txt"));

	return 0;
}


void config(list<Bottle>&Bottles)
{
	int option;
	string input;
	do
	{
		cout << "1) Add new EAN code\n2) Remove existing EAN code\n3) Save changes and return to normal mode\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> option;
		switch (option)
		{
		case 1:
		{
			string ean, article,price;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter EAN code:";
			cin >> ean;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter article:";
			getline(cin, article);
			cout << "Enter refund price:";
			cin >> price;
			try 
			{
				Bottles.push_back(Bottle(ean, article, price));
			}
			catch (invalid_argument e)
			{
				cout << "Invalid argument\n";
			}
			catch (length_error e)
			{
				cout << e.what()<<endl;
			}
		}
			break;
		case 2:
		{
			cout << "Enter EAN code that should be deleted:";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			cin >> input;
			auto it = find(Bottles.begin(), Bottles.end(), input);
			if (it != Bottles.end())
			{
				Bottles.erase(it);
			}
			else
			{
				cout << "EAN code not recognized\n";
			}
		}
			break;
		case 3:
			break;
		default:
			cout << "Invalid option\n";
			break;
		}
	} while (option != 3);
}


void print_receipt(list<Bottle> &Bottles, ofstream file)
{
	double sum = 0;
	for (Bottle& elem : Bottles)
	{
		file << elem;
		sum += elem.get_count() * elem.get_price();
	}
	cout << "Total amount of refund is " << sum << " euros\n";
	file << "Total: " << sum;
}