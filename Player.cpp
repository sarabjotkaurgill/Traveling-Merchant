#include "Player.h"
#include <string>
#include <ctime>

//Get the players name
string Player::getName()
{
	return name;
}

//Add item to players inventory
string Player::addItem(string item, int itemPrice)
{
	//Is players inventory not full?
	if (isInventoryFull())
	{
		cout << "Inventory is full." << " Merchant caught" << " Amount deducted";
		string cities[5] = { "Montreal", "Toronto", "Windsor", "Downtown", "Brampton" };
		srand((unsigned)time(0));
		string city = cities[rand() % 5];
		cout << endl << "City Name: " << city << endl << endl;

			cout << "The total amount the Merchant has: " << amount << "$";
			amount -= 100;
			int tempAmount = amount - 100;
			if (tempAmount > amount)
			{
				amount = tempAmount;
				cout << "You do not have enough amount to pay fine. You loose Game";
			}
	}

	else
	{
		//Can player afford item?
		if (amount >= itemPrice)
		{
			amount -= itemPrice;
			numbOfItems++;
			cout << "You have purchased " << item << "." << "\n";
			inventory.push_back(item); //Add item to inventory
			return item;
		}

		//If player cant afford item 
		else
		{
			cout << "You cannot afford this item." << "\n";
		}
	}
}

void Player::sellItem(int itemNum, int itemPrice)
{
	char response;
	cout << "Are you sure you want to sell: " << inventory[itemNum] << "? 'y' - Yes. 'n' - No." << "\n";
	cin >> response;

	switch (response)
	{
	case 'y':
		numbOfItems++;
		amount += itemPrice;
		inventory.erase(inventory.begin() + itemNum);
		break;

	case 'n':
		cout << "That is ok." << "\n";
		break;

	default:
		cout << "Please enter correct data." << "\n";
	}
}

//Check to see if players inventory is full
bool Player::isInventoryFull()
{
	//If players inventory isnt full
	if (numbOfItems < maxNumbItems)
	{
		return false;
	}

	//If players inventory is full
	else
	{
		return true;
	}
}

//Return size of players inventory
int Player::inventoryCapacity()
{
	return inventory.size();
}

//Get the players amount
int Player::getAmount()
{
	return amount;
}

//List the players inventory
void Player::listInventory()
{
	int itemNumb = 0; //item number in menu

	for (int i = 0; i < inventory.size(); i++)
	{
		itemNumb++;
		cout << itemNumb << ": " << inventory[i] << "\n";
	}

	 //If inventory is empty
	if (inventory.empty())
	{
		cout << "Inventory is empty" << "\n";
	}

}

int Player::getNumbOfItems()
{
	return numbOfItems;
}

Player::Player()
{
}


Player::~Player()
{
}