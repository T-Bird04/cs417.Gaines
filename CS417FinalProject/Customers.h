#pragma once
#include <string>
#include "Lists.h"

class Department;


class Customer
{
public:
	std::string name;
	ShoppingCart cart;
	WishList wList;
	std::shared_ptr<Department> dept;

	Customer(std::string input1, ShoppingCart input2, WishList input3, std::shared_ptr<Department> input4)
	{
		name = input1;
		cart = input2;
		wList = input3;
		dept = input4;
	}
	//From ChatGPT debugging
	bool operator==(const Customer& other) const
	{
		return name == other.name;
	}

};