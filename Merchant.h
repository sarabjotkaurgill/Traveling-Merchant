#pragma once
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class Merchant
{
private:
	string city;

public:
	string  getCity();
	void showInitialItem(Player& player);
	void purchaseItem(Player& player); //merchant has player buy items from them
	void sellItem(Player& player); //merchant sells item to player

	Merchant();
	~Merchant();
};
