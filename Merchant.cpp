#include "Merchant.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string  Merchant::getCity() {
	return city;
}

//show initial item
void Merchant::showInitialItem(Player& player) {
	string randCity;
	string products[5] = { "Book", "Candy", "Film", "Milk", "Toy" };
	string cities[5] = { "Montreal", "Toronto", "Windsor", "Downtown", "Brampton" };
	const int size = 5;
	int sellingPrice[size];
	int buyingPrice[size];

	srand((unsigned)time(0));

	city = cities[rand() % 5];
	cout << endl << "City Name: " << city << endl << endl;
	cout << "Merchant has " << player.getAmount() << "$." << endl << endl;

	cout << " Products \t Buying Price \t\t Selling Price" << endl;
	for (int i = 0; i < size; i++)
	{
		sellingPrice[i] = (rand() % 100);
		buyingPrice[i] = (rand() % 100) + 10;
		if (buyingPrice[i] < sellingPrice[i])
		{
			buyingPrice[i] = sellingPrice[i];
			sellingPrice[i] = buyingPrice[i];
		}
		cout << i + 1 << " " << products[i] << "\t\t\t" << buyingPrice[i] << "\t\t\t" << sellingPrice[i] << endl;
	}
}

//Player purchases item from merchant
void Merchant::purchaseItem(Player& player)
{
	//Player player;
	int response = 0; //Menu navigation
	string products[5] = { "Book", "Candy", "Film", "Milk", "Toy" };
	string cities[5] = { "Montreal", "Toronto", "Windsor", "Downtown", "Brampton" };
	int sellingPrice[5] = { 32, 5, 14, 7, 20 };
	int buyingPrice[5] = { 36, 8, 31, 12, 30 };

	cout << " Products \t Buying Price \t\t Selling Price" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << " " << products[i] << "\t\t\t" << buyingPrice[i] << "\t\t\t" << sellingPrice[i] << endl;
	}

	//cout << "1: Book - 30$" << endl << "2: Candy - 50$" << endl << "3: Film - 10$" <<endl << "4: Milk - 75$" << endl << "5: Toy - 25$" << endl;

	do
	{
		cin >> response;

		switch (response)
		{
		case 1:
			for (int i = 0; i < 5; i++) {
				if (products[i] == "Book")
				{
					player.addItem("Book", buyingPrice[i]);
				}
			}
			break;

		case 2:
			for (int i = 0; i < 5; i++) {
				if (products[i] == "Candy")
				{
					player.addItem("Candy", buyingPrice[i]);
				}
			}
			break;

		case 3:
			for (int i = 0; i < 5; i++) {
				if (products[i] == "Film")
				{
					player.addItem("Film", buyingPrice[i]);
				}
			}
			break;

		case 4:
			for (int i = 0; i < 5; i++) {
				if (products[i] == "Milk")
				{
					player.addItem("Milk", buyingPrice[i]);
				}
			}
			break;

		case 5:
			for (int i = 0; i < 5; i++) {
				if (products[i] == "Toys")
				{
					player.addItem("Toys", buyingPrice[i]);
				}
			}
			break;

		default:
			cout << "Please enter valid data." << "\n";
			cout << " Products \t Buying Price \t\t Selling Price" << endl;
			for (int i = 0; i < 5; i++) {
				cout << i + 1 << " " << products[i] << "\t\t\t" << buyingPrice[i] << "\t\t\t" << sellingPrice[i] << endl;
			}
			//cout << "1: Book - 30. 2: Candy - 50. 3: Film - 10. 4: Milk - 75. 5: Product - 25." << "\n";
		}
	} while (response > 5 || response < 1);

}

//Merchant sells item to player
void Merchant::sellItem(Player& player)
{
	//Player player;
	int response = 0;
	player.listInventory();
	if (response < player.getNumbOfItems())
	{
		cin >> response;

		switch (response)
		{
		case 1:
			player.sellItem(0, 32);
			break;

		case 2:
			player.sellItem(1, 5);
			break;

		case 3:
			player.sellItem(2, 14);
			break;

		case 4:
			player.sellItem(3, 7);
			break;

		case 5:
			player.sellItem(4, 20);
			break;

		default:
			cout << "Please enter valid data." << "\n";
			player.listInventory();
		}
	}

	else
	{
		cout << "Item doesn't exist.";
	}

}

Merchant::Merchant()
{
}


Merchant::~Merchant()
{
}