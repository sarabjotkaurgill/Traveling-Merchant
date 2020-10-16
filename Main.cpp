#include "Player.h"
#include "Merchant.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cityNames[5] = { "Montreal", "Toronto", "Windsor", "Downtown", "Brampton" };

	Player player; //The player
	Merchant merchant; //The merchnat

	int response; //Menu navigation
	cout << "Greetings " << player.getName() << ". Feel free to browse." << "\n";

	merchant.showInitialItem(player);

	cout << endl << "1: Purchase Items 2: Sell Items 3: List Your Items 4: Show Amount 5: Exit" << "\n";

	do
	{
		cin >> response;

		switch (response)
		{
		case 1:
			merchant.purchaseItem(player);
			break;

		case 2:
			merchant.sellItem(player);
			break;

		case 3:
			player.listInventory();
			break;

		case 4:
			cout << "You have " << player.getAmount() << " amount." << "\n";
			break;

		case 5:
			cout << "Thank you for shopping." << "\n";
			break;

		default:
			cout << "Please enter valid data." << "\n";
			cout << "1: Purchase Items 2: Sell Items 3: List Your Items 4: Show Amount 5: Exit" << "\n";
		}

		cout << "1: Purchase Items 2: Sell Items 3: List Your Items 4: Show Amount 5: Exit" << "\n";

	} while (response != 5);

	return 0;
}