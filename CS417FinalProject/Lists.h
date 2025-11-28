#pragma once
#include <string>
#include <vector>
#include "Items.h"

class List
{
public:
	std::vector<Item> items;

	virtual void addItem(Item item) = 0;
	virtual void removeItem(Item item) = 0;
	virtual std::vector<Item> getItems() = 0;
};

class ShoppingCart : public List
{
public:
	void addItem(Item item)
	{
		items.push_back(item);
	}

	void removeItem(Item item)
	{
		//From Google AI Overview on how to remove specific values from a vector
		items.erase(std::remove(items.begin(), items.end(), item), items.end());
	}

	std::vector<Item> getItems()
	{
		return items;
	}
};

class WishList : public List
{
public:
	void addItem(Item item)
	{
		items.push_back(item);
	}

	void removeItem(Item item)
	{
		//From Google AI Overview on how to remove specific values from a vector
		items.erase(std::remove(items.begin(), items.end(), item), items.end());
	}

	std::vector<Item> getItems()
	{
		return items;
	}
};