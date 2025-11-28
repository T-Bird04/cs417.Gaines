#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Customers.h"
#include "Items.h"

//Factory Method Design Pattern

//Abstract Product
class Department
{
public:
	std::string name;
	std::vector<Item> items;
	std::vector<Customer> customers;
	std::vector<Customer> observers;
	int departmentID;
	virtual ~Department() {}
	virtual void enter(Customer cust) = 0;
	virtual void exit(Customer cust) = 0;
	virtual std::vector<Customer> getCustomers() = 0;
	virtual std::vector<Item> getItems() = 0;
	virtual void addObserver(Customer cust) = 0;
};


//Abstract Creator
class DepartmentFactory
{
public:
	virtual ~DepartmentFactory() {};
	virtual std::shared_ptr<Department> createDepartment() = 0;
};


//Concrete Products
class Books : public Department
{
public:
	Books() 
	{
	name = "Books";
	departmentID = 1;
	}
	void enter(Customer cust) override
	{
		customers.push_back(cust);
	}

	void exit(Customer cust) override
	{
		customers.erase(std::remove(customers.begin(), customers.end(), cust), customers.end());
	}

	std::vector<Customer> getCustomers() override
	{
		return customers;
	}

	std::vector<Item> getItems() override
	{
		return items;
	}

	void addObserver(Customer cust) override
	{
		observers.push_back(cust);
	}
};

class Music : public Department
{
public:
	Music()
	{
		name = "Music";
		departmentID = 2;
	}

	void enter(Customer cust) override
	{
		customers.push_back(cust);
	}

	void exit(Customer cust) override
	{
		customers.erase(std::remove(customers.begin(), customers.end(), cust), customers.end());
	}

	std::vector<Customer> getCustomers() override
	{
		return customers;
	}

	std::vector<Item> getItems() override
	{
		return items;
	}

	void addObserver(Customer cust) override
	{
		observers.push_back(cust);
	}
};

class Software : public Department
{
public:
	Software()
	{
		name = "Software";
		departmentID = 3;
	}

	void enter(Customer cust) override
	{
		customers.push_back(cust);
	}

	void exit(Customer cust) override
	{
		customers.erase(std::remove(customers.begin(), customers.end(), cust), customers.end());
	}

	std::vector<Customer> getCustomers() override
	{
		return customers;
	}

	std::vector<Item> getItems() override
	{
		return items;
	}

	void addObserver(Customer cust) override
	{
		observers.push_back(cust);
	}
};

class Video : public Department
{
public:
	Video()
	{
		name = "Video";
		departmentID = 4;
	}

	void enter(Customer cust) override
	{
		customers.push_back(cust);
	}

	void exit(Customer cust) override
	{
		customers.erase(std::remove(customers.begin(), customers.end(), cust), customers.end());
	}

	std::vector<Customer> getCustomers() override
	{
		return customers;
	}

	std::vector<Item> getItems() override
	{
		return items;
	}

	void addObserver(Customer cust) override
	{
		observers.push_back(cust);
	}
};


//Concrete Creators
class BookFactory : public DepartmentFactory
{
public:
	std::shared_ptr<Department> createDepartment() override
	{
		return std::make_shared<Books>();
	}
};

class MusicFactory : public DepartmentFactory
{
public:
	std::shared_ptr<Department> createDepartment() override
	{
		return std::make_shared<Music>();
	}
};

class SoftwareFactory : public DepartmentFactory
{
public:
	std::shared_ptr<Department> createDepartment() override
	{
		return std::make_shared<Software>();
	}
};

class VideoFactory : public DepartmentFactory
{
public:
	std::shared_ptr<Department> createDepartment() override
	{
		return std::make_shared<Video>();
	}
};