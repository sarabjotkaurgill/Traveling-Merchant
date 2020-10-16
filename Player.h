#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
	const int maxNumbItems = 5; //Maximum number of items that inventory can store

	int amount = 150, //Amount the player has
		numbOfItems = 0; //Number of con-current items player holds
	vector<string> inventory; //Players inventory
	string name = "ABC"; //Players name

public:
	string getName(); //Get the players name
	string addItem(string item, int itemPrice); // Add item to players inventory
	void sellItem(int itemNum, int itemPrice); //Sell item 
	bool isInventoryFull(); //Check to see if players inventory is full
	int inventoryCapacity(); //Get capacity of inventory
	int getAmount(); //Get players money
	void listInventory();
	int getNumbOfItems();

	Player();
	~Player();
};
