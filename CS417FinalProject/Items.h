#pragma once

#include <string>

class Item
{
public:
	std::string name;
	int itemID;
	int departmentID;
	double price;

	Item(std::string input1, int input2, int input3, double input4)
	{
		name = input1;
		itemID = input2;
		departmentID = input3;
		price = input4;
	}
	//From ChatGPT debugging
	bool operator==(const Item& other) const
	{
		return itemID == other.itemID;
	}

};