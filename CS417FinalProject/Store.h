#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Departments.h"
#include "Customers.h"
#include "Lists.h"

class Store
{
private:
	//Attributes
	std::string name;
	std::vector<std::shared_ptr<Department>> departmentsList;
	std::vector<Customer> customersList;

public:
	//Constructor
	Store(std::string input1)
	{
		name = input1;
	}
	//Methods
	void enter(Customer cust)
	{
		customersList.push_back(cust);
	}
	void exit(Customer cust)
	{
		customersList.erase(std::remove(customersList.begin(), customersList.end(), cust), customersList.end());
	}
	ShoppingCart getShoppingCart()
	{
		return ShoppingCart();
	}
	WishList getWishList()
	{
		return WishList();
	}
	std::vector<Customer> getCustomers()
	{
		return customersList;
	}
	std::vector<std::shared_ptr<Department>> getDepartments()
	{
		return departmentsList;
	}
	void addDepartment(std::shared_ptr<Department> dept)
	{
		departmentsList.push_back(dept);
	}
};
