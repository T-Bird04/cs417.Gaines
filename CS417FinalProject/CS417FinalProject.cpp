// CS417FinalProject.cpp 

#include <iostream>
#include "Store.h"
#include "Departments.h"
#include "Customers.h"
#include "Lists.h"
#include "Items.h"

int main()
{
	//Test Store
	Store BargainMart = Store("BargainMart");

	//Test Departments
	//Factory usage based on https://www.geeksforgeeks.org/system-design/factory-method-pattern-c-design-patterns/
	DepartmentFactory* deptFactory;
	deptFactory = new BookFactory();
	std::shared_ptr<Department> deptOne = deptFactory->createDepartment();
	deptFactory = new MusicFactory();
	std::shared_ptr<Department> deptTwo = deptFactory->createDepartment();
	deptFactory = new SoftwareFactory();
	std::shared_ptr<Department> deptThree = deptFactory->createDepartment();
	deptFactory = new VideoFactory();
	std::shared_ptr<Department> deptFour = deptFactory->createDepartment();
	delete deptFactory;

	//Adding Departments to Store
	BargainMart.addDepartment(deptOne);
	BargainMart.addDepartment(deptTwo);
	BargainMart.addDepartment(deptThree);
	BargainMart.addDepartment(deptFour);

	//Test Customers
	Customer customerOne("John Doe", BargainMart.getShoppingCart(), BargainMart.getWishList(), deptOne);
	Customer customerTwo("Jane Doe", BargainMart.getShoppingCart(), BargainMart.getWishList(), deptTwo);
	Customer customerThree("John Smith", BargainMart.getShoppingCart(), BargainMart.getWishList(), deptThree);
	Customer customerFour("Jane Smith", BargainMart.getShoppingCart(), BargainMart.getWishList(), deptThree);

	//Adding Customers to Store
	BargainMart.enter(customerOne);
	BargainMart.enter(customerTwo);
	BargainMart.enter(customerThree);
	BargainMart.enter(customerFour);

	//Test Items
	Item item1("Picture Book", 1123, 1, 9.99);
	Item item2("Science Book", 1321, 1, 14.99);
	Item item3("Vinyl", 2132, 2, 24.99);
	Item item4("Headphones", 2415, 2, 14.99);
	Item item5("McAfee", 3245, 3, 39.99);
	Item item6("Windows 11 Pro", 3234, 3, 199.99);
	Item item7("Blank CDs", 4123, 4, 4.99);
	Item item8("Recorder", 4234, 4, 79.99);

	//Adding Items to Departments
	deptOne->items.push_back(item1);
	deptOne->items.push_back(item2);
	deptTwo->items.push_back(item3);
	deptTwo->items.push_back(item4);
	deptThree->items.push_back(item5);
	deptThree->items.push_back(item6);
	deptFour->items.push_back(item7);
	deptFour->items.push_back(item8);

	//Test Customer add item to cart
	customerOne.cart.addItem(item5);
	//Test Custmer add item to wish list
	customerTwo.wList.addItem(item3);
	//Test Customer leave store
	BargainMart.exit(customerThree);
	//Test customer change department
	customerFour.dept = deptOne;






	//Beginning of nontest code
	bool cont = true, purchase = true;
	int userInput = 0;
	std::string userName = "", desiredItem = "";
	Customer userCustomer(userName, BargainMart.getShoppingCart(), BargainMart.getWishList(), deptOne);//Default User Configuration

	//Enter the Store
	std::cout << "Please enter your name: ";
	std::getline(std::cin, userName);
	std::cout << "Which Department would you like to visit?\n1:Books\n2:Music\n3:Software\n4:Video\n";
	std::cin >> userInput;
	switch (userInput)
	{
	case 1:
		userCustomer.name = userName;
		break;
	case 2:
		userCustomer.name = userName;
		userCustomer.dept = deptTwo;

		break;
	case 3:
		userCustomer.name = userName;
		userCustomer.dept = deptThree;

		break;
	case 4:
		userCustomer.name = userName;
		userCustomer.dept = deptFour;

	}

	do
	{
		std::cout << "What would you like to do?\n1:Buy Items\n2:Change Department\n3:Exit and Checkout\n";
		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
		
			do
			{
				std::cout << "Items: \n";
				for (Item currentItem : userCustomer.dept->getItems())
				{
					std::cout << currentItem.name << std::endl;
				}

				std::cin.ignore();
				std::cout << "Please enter the name of the item you wish to buy: ";
				std::getline(std::cin, desiredItem);

				for (Item currentItem : userCustomer.dept->getItems())
				{
					if (desiredItem == currentItem.name)
					{
						userCustomer.cart.addItem(currentItem);
					}
				}

				std::cout << "What would you like to do?\n1:Buy Another Item\n2:Exit\n";
				std::cin >> userInput;

				switch (userInput)
				{
				case 1:
					break;
				case 2:
					purchase = false;
				}

			} while (purchase);



			break;
		case 2:
			std::cout << "Which Department would you like to visit?\n1:Books\n2:Music\n3:Software\n4:Video\n";
			std::cin >> userInput;
			switch (userInput)
			{
			case 1:
				userCustomer.name = userName;
				userCustomer.dept = deptOne;
				break;
			case 2:
				userCustomer.name = userName;
				userCustomer.dept = deptTwo;

				break;
			case 3:
				userCustomer.name = userName;
				userCustomer.dept = deptThree;

				break;
			case 4:
				userCustomer.name = userName;
				userCustomer.dept = deptFour;

			}

			break;
		case 3:
			double cartCost = 0.00;
			std::vector<Item> tempList = userCustomer.cart.getItems();
			for (Item currentItem : tempList)
			{
				cartCost += currentItem.price;
			}

			std::cout << "Your Total is: " << cartCost << std::endl;
			std::cout << "Have a Nice Day!\n";
			cont = false;
		}



	} while (cont);

}
