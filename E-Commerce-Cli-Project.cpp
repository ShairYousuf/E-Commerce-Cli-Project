#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include <vector>
#include "Sorting.h"
#include "customerhistory.cpp"

using namespace std;
using namespace json;

//variable to keep track of inventory size
int inventory_size;
json_data d;

//CustomerHistory Circular Queue
CustomerHistoryQueue <int, string, string, string> customerHistory(5);

class Item 
{
	public:
		int	Amount_Sold;
		string Category;
		string Date_Of_Expiration;
		int Item_ID;
		string Name;
		float Price;
		int Quantity;

		void AddDataInitial(int Amount_SoldInput, std::string CategoryInput, string Date_Of_ExpirationInput, int Item_IDInput, std::string NameInput, float PriceInput, int QuantityInput)
		{
			Amount_Sold = Amount_SoldInput;
			Category = CategoryInput;
			Date_Of_Expiration = Date_Of_ExpirationInput;
			Item_ID = Item_IDInput;
			Name = NameInput;
			Price = PriceInput;
			Quantity = QuantityInput;
		}
		void AddData(int Amount_SoldInput, std::string CategoryInput, string Date_Of_ExpirationInput, int Item_IDInput, std::string NameInput, float PriceInput, int QuantityInput)
		{
			Amount_Sold = Amount_SoldInput;
			Category = CategoryInput;
			Date_Of_Expiration = Date_Of_ExpirationInput;
			Item_ID = Item_IDInput;
			Name = NameInput;
			Price = PriceInput;
			Quantity = QuantityInput;
		}

		void printItem() {
			cout << endl << this->Item_ID << " | " << this->Name << " | $" << this->Price << " | " << this->Quantity << " | " << this->Category << " | " << this->Amount_Sold << endl;
		}
};

//gloabl Inventory vector for storing Items
vector<Item> Inventory;

//function to add a new item to inventory
void addToInventory(int itemID, string name, float price, string expiryDate, int quantity, string category, int amtSold) {
	Item Temp;
	Temp.AddData(amtSold, category, expiryDate, itemID, name, price, quantity);
	Inventory.push_back(Temp);
	inventory_size++;
	std::string whole = d.stringify();
	for (int count = 0; count < 8; count++)
	{
		whole.erase(whole.size() - 1, 8);
	}
	whole = whole + ",\n        {\n        }\n    ]\n}";
	json_util::writeStr("data.json", whole);
	d = json_util::read("data.json");
}

//function to search by using Item ID of an item
int searchByItemID(int itemID) {
	for (int i = 0; i < Inventory.size(); i++) {
		if (Inventory[i].Item_ID == itemID) {
			return i;
		}
	}
}

// function to delete an item from inventory
void deleteFromInventory(int itemID) {
	Inventory.erase(Inventory.begin() + searchByItemID(itemID));
	inventory_size--;
	std::string whole2 = d.stringify();

	int LastCurlyCloseBracketPos = whole2.find_last_of("}");
	int LastCurlyOpenBracketPos = whole2.find_last_of("{");
	whole2.erase(LastCurlyOpenBracketPos - 10, LastCurlyCloseBracketPos + 1);

	whole2 = whole2 + "\n    ]\n}";
	json_util::writeStr("data.json", whole2);
	d = json_util::read("data.json");
}

//prints items of a specific category
void listByCategory(string category) {
	vector<Item> temp;
	for (int i = 0; i < Inventory.size(); i++) {
		if (Inventory[i].Category == category) {
			temp.push_back(Inventory[i]);
		}
	}
	for (int j = 0; j < temp.size(); j++) {
		temp[j].printItem();
	}
}

//prints items of Item ID
void listByItemID(int itemID) {
    vector<Item> temp;
    for (int i = 0; i < Inventory.size(); i++) {
        if (Inventory[i].Item_ID == itemID) {
            temp.push_back(Inventory[i]);
        }
    }
    for (int j = 0; j < temp.size(); j++) {
        temp[j].printItem();
    }
}

//prints items of a specific name
void listByName(string name) {
    vector<Item> temp;
    for (int i = 0; i < Inventory.size(); i++) {
        if (Inventory[i].Name == name) {
            temp.push_back(Inventory[i]);
        }
    }
    for (int j = 0; j < temp.size(); j++) {
        temp[j].printItem();
    }
}

//updates the quantity of a specific item using Item ID
void updateQuantity(int itemID, int amt) {
	Inventory[searchByItemID(itemID)].Quantity += amt;
}

//helper function to print heading template for list of Inventory
void printHeading() {
	cout << endl << "Item ID | Name | Price | Quantity | Category | Amt Sold" << endl;
}

//prints all items in the Inventory
void printInventory() {
	for (int i = 0; i < Inventory.size(); i++) {
		Inventory[i].printItem();
	}
}


/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// 
///Console Menu
/// 
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int runProgram;
void welcomeMenu();
void mainMenu();
void storeMenu();
void adminMenu();
void storeMenu();
void customerInfo();

//string holding the current customer's ID
string customerID;

//menu that asks for Item ID that customer wants to add to their cart
void addToCart() {
    cout << endl << "--------------------" << endl;
    cout << endl << "     Add to cart    " << endl;
    cout << endl << "--------------------" << endl;

    int input = 0;
    while (input != -1) {
        cout << "Which item would you like to order? Please enter Item ID (Input -1 to go back): ";
        cin >> input;
        if (input != -1) {
            //function to add to cart 
            /// pushToCart(customerID, itemID);
            cout << "**Added to cart Item ID: " << input << " **" << endl;
            cout << "\n" << endl;
        }
    }
    mainMenu();
}

//lists all the inventory in the store
void listAll() {
    cout << endl << "--------------------" << endl;
    cout << endl << "      All Items     " << endl;
    cout << endl << "--------------------" << endl;

    //prints all the items in the inventory
    printHeading();
    printInventory();

    //goes to add cart menu
    addToCart();

}

//allows user to search products by using category
void searchByCategory() {
    cout << endl << "--------------------" << endl;
    cout << endl << " Search by Category  " << endl;
    cout << endl << "--------------------" << endl;

    string category;
    cout << "Which category would you like to search? : ";
    cin >> category;

    //print all the items of that category
    printHeading();
    listByCategory(category);

    //goes to add cart menu
    addToCart();
}

//allows user to search products by using item ID
void searchByItemID() {
    cout << endl << "--------------------" << endl;
    cout << endl << "  Search by Item ID  " << endl;
    cout << endl << "--------------------" << endl;

    int itemID;
    cout << "Please input Item ID to search? : ";
    cin >> itemID;

    //helper function to find and print item of specific ItemID;
    printHeading();
    listByItemID(itemID);

    //goes to add cart menu
    addToCart();
}

//allows user to search products by name
void searchByName() {
    cout << endl << "--------------------" << endl;
    cout << endl << "   Search by Name  " << endl;
    cout << endl << "--------------------" << endl;

    string name;
    cout << "What is the name of the item you would like to search? : ";
    cin >> name;

    //print all the items of that name
    printHeading();
    listByName(name);

    //goes to add cart menu
    addToCart();
}

//function to sort inventory by date
void sortByDate() {
    Sort<double, int, string>* head = new Sort<double, int, string>();
    vector<Item>invtemp = Inventory;
    head->ItemID = invtemp[0].Item_ID;
    head->name = invtemp[0].Name;
    head->price = invtemp[0].Price;
    head->quantity = invtemp[0].Quantity;
    head->priority = invtemp[0].Date_Of_Expiration;
    head->date = invtemp[0].Date_Of_Expiration;
    for (int i = 1; i < invtemp.size(); i++)
    {
        head->pushDate(&head, invtemp[i].Item_ID, invtemp[i].Name, invtemp[i].Price, invtemp[i].Quantity, invtemp[i].Date_Of_Expiration);
    }
    head->printQueue(&head, "date");
    head->ClearQueue(&head);

    //goes to add cart menu
    addToCart();
}

//function to sort inventory by price
void sortByPrice() {
    /// iterate through inventory and then use Sorting.h
    Sort<double, int, int>* head = new Sort<double,int,int>();
    vector<Item>invtemp = Inventory;
    head->ItemID = invtemp[0].Item_ID;
    head->name = invtemp[0].Name;
    head->price = invtemp[0].Price;
    head->quantity = invtemp[0].Quantity;
    head->priority = invtemp[0].Price;
    head->date = invtemp[0].Date_Of_Expiration;
    for (int i = 1; i < invtemp.size(); i++)
    {
        head->push(&head, invtemp[i].Item_ID, invtemp[i].Name, invtemp[i].Price, invtemp[i].Quantity, invtemp[i].Date_Of_Expiration);
    }
    head->printQueue(&head, "price");
    head->ClearQueue(&head);
 
    //goes to add cart menu
    addToCart();
}

void storeMenu() {

    cout << endl << "--------------------" << endl;
    cout << endl << "     Store Menu     " << endl;
    cout << endl << "--------------------" << endl;

    //options for choosing
    cout << " 1. All Items\n";
    cout << " 2. Sort by expiration date\n";
    cout << " 3. Sort by Price \n";
    cout << " 4. Search by Category\n";
    cout << " 5. Search by Item ID \n";
    cout << " 6. Search by Name\n";

    //variable for option
    int opt;
    cout << "Please input the number for accessing the menu. (Input -1 to go back)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        listAll();
        break;
    case 2:
        sortByDate();
        break;
    case 3:
        sortByPrice();
        break;
    case 4:
        searchByCategory();
        break;
    case 5:
        searchByItemID();
        break;
    case 6:
        searchByName();
        break;
    case -1:
        mainMenu();
        break;
    default:
        break;
    }
}

//asks customer what products they want to order and adds it to the cart
void checkOut() {

    /// commences order
    /// reduces quantity from the inventory array and increases amount ordered
    /// put into customer's history
    /// c

}

//clears the cart list
void clearCart() {
    /// 
    /// NEED HELPER function to clear all the items in cart for the customer
    /// 
}

void cartMenu() {
    cout << endl << "------------------" << endl;
    cout << endl << "     Cart Menu    " << endl;
    cout << endl << "------------------" << endl;

    ///
    /// NEED: Shows all the items in the cart of the current customer
    /// 

    //options for choosing
    cout << " 1. Checkout\n";
    cout << " 2. Clear Cart\n";

    //variable for option
    int opt;
    cout << "Please input the number for accessing the menu. (Input -1 to go back)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        checkOut();
        break;
    case 2:
        clearCart();
        break;
    case -1:
        mainMenu();
        break;
    default:
        break;
    }
}

void registerCustomer() {
    cout << endl << "---------------------------" << endl;
    cout << endl << "   Promotion Registration  " << endl;
    cout << endl << "---------------------------" << endl;

    int ID;
    string name, email, phone;

    cout << endl << "Please input your ID: ";
    cin >> ID;

    cout << endl << "Please input your name: ";
    cin >> name;

    cout << endl << "Please input your email: ";
    cin >> email;

    cout << endl << "Please input your phone number: ";
    cin >> phone;

    //adds to the circular queue
    customerHistory.enQueue(ID, name, email, phone);

    cout << "\n" << endl;
    cout << "Following information was collected: " << endl;
    cout << endl << "ID: " << ID << "; Name: " << name << "; Email: " << email << "; Phone: " << phone << endl;
    
    //goes back to customer Info menu
    customerInfo();
}

//lists all the orders 
void pastOrders() {
    cout << endl << "-------------------------" << endl;
    cout << endl << "       Past Orders       " << endl;
    cout << endl << "-------------------------" << endl;

    /// NEED
    /// NEED: Helper function to print contents of history for the customer
    ///  showPastOrders(ID = 123);

}

//shows all the information about the customers
void customerInfo() {

    cout << endl << "-------------------------" << endl;
    cout << endl << "   Customer Information  " << endl;
    cout << endl << "-------------------------" << endl;

    cout << endl << "Current customer: " << customerID << endl;

    //options for choosing
    cout << " 1. Register for promotion\n";
    cout << " 2. Past Orders\n";

    //variable for option
    int opt;
    cout << "Please input the number for accessing the menu. (Input -1 to go back)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        registerCustomer();
        break;
    case 2:
        pastOrders();
        break;
    case -1:
        mainMenu();
        break;
    default:
        break;
    }

}

void mainMenu() {

    cout << endl << "----------------------------" << endl;
    cout << endl << "           Main Menu        " << endl;
    cout << endl << "----------------------------" << endl;

    //options for choosing
    cout << " 1. Store\n";
    cout << " 2. Cart\n";
    cout << " 3. Customer Information \n";

    //variable for option
    int opt;
    cout << "Please input the number for accessing the menu. (Input -1 to go back)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        storeMenu();
        break;
    case 2:
        cartMenu();
        break;
    case 3:
        customerInfo();
        break;
    case -1:
        welcomeMenu();
        break;
    default:
        break;
    }
}

//admin goes to menu to reorder inventory for the store
void reorder() {
    cout << endl << "---------------------" << endl;
    cout << endl << "     Reorder Menu   " << endl;
    cout << endl << "---------------------" << endl;
    string answer;

    //Asking what products to reorder and quantity to reorder
    cout << endl << "Would you like to reorder the top 5 products? (Input Y or N): ";
    cin >> answer;

    if (answer == "Y") {
        ///
        /// function to reorder inventory which basically just adds the quantity to the itemID
        ///
        cout << "*** Reorder Summary: items ordered for Item ID: ***" << endl;
        ///Prints all the items that were reorderd 
    }
    else if (answer == "N") {
        cout << "*** No orders were made ***" << endl;
    }

}

//function prints all the customers in the customer history circular queue
void displayCustomerHistory() {
    cout << endl << "-------------------------" << endl;
    cout << endl << "     Customer History  " << endl;
    cout << endl << "-------------------------" << endl;

    cout << "Following are the customers that registered for the promotion: " << endl;
    customerHistory.displayQueue();
    
    //goes back to admin menu
    adminMenu();
}

//function that asks for information to add about item to inventory
void addNewItemMenu() {
    cout << endl << "-------------------------" << endl;
    cout << endl << "       Add New Item      " << endl;
    cout << endl << "-------------------------" << endl;

    string name, category, expirydate;
    int itemID, quantity;
    float price;

    //addToInventory(123, "Oreo", 2.99, "2022-11-12", 10, "Chocolate", 12);
    
    cout << endl << "Please input Item Id of new item: ";
    cin >> itemID;

    cout << endl << "Please input Name of new item: ";
    cin >> name;

    cout << endl << "Please input Price of new item: ";
    cin >> price;

    cout << endl << "Please input Date of Expiry of new item: ";
    cin >> expirydate;

    cout << endl << "Please input Quanitity of new item: ";
    cin >> quantity;

    cout << endl << "Please input Category of new item: ";
    cin >> category;

    //by default amount sold will be 0
    //amtsold = 0

    //helper function for adding new item:
    addToInventory(itemID, name, price, expirydate, quantity, category, 0);

    cout << "** new item added: " << itemID << " | " << name << " ** ";
    
    // goes back to admin menu
    adminMenu();
}

//function for deleting an exsiting item from the inventory
void deleteItemMenu() {

    cout << endl << "-------------------------" << endl;
    cout << endl << "       Delete Item      " << endl;
    cout << endl << "-------------------------" << endl;

    int itemID;

    cout << endl << "Please input Item ID of new item: ";
    cin >> itemID;

    //helper function to delete item from Inventory
    deleteFromInventory(itemID);

    cout << endl << "** Item ID: " << itemID << " has been deleted successfully **" << endl;
    //goes back to admin menu
    adminMenu();
}

void adminMenu() {
    cout << endl << "-----------------" << endl;
    cout << endl << "    Admin Menu   " << endl;
    cout << endl << "-----------------" << endl;

    //variable for option
    int opt;

    //options for choosing
    cout << " 1. Reorder\n";
    cout << " 2. Customer History\n";
    cout << " 3. Add new Item\n";
    cout << " 4. Delete Item\n";

    cout << endl << "Please input the number for accessing the menu. (Input -1 to go back)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        reorder();
        break;
    case 2:
        displayCustomerHistory();
        break;
    case 3:
        addNewItemMenu();
        break;
    case 4:
        deleteItemMenu();
    case -1:
        welcomeMenu();
        break;
    default:
        break;
    }
}

//page that takes in userID and pass to authenticate admin
void adminLogIn() {
    cout << endl << "-----------------------" << endl;
    cout << endl << "    Admin login page   " << endl;
    cout << endl << "-----------------------" << endl;

    string userId, pass;
    bool valid = false;

    while (valid == false) {
        cout << endl << "Please enter the username and password: " << endl;
        cout << "Username: ";
        cin >> userId;
        cout << "Password: ";
        cin >> pass;

        //checks validity of userId and pass
        if (userId == "admin" && pass == "admin") {
            cout << "You have been authenticated!" << endl;
            //goes to admin menu
            valid = true;
            adminMenu();
        }
        else {
            cout << "Please try again" << endl;
        }
    }
}

void customerLogIn() {
    cout << endl << "---------------------------" << endl;
    cout << endl << "    Customer login page   " << endl;
    cout << endl << "---------------------------" << endl;

    cout << endl << "Please enter your Customer ID: " << endl;
    cout << "Customer ID: ";
    cin >> customerID;
    cout << "\n";

    //goes to main menu of the store
    mainMenu();

}

void welcomeMenu() {
    //variable for option
    int opt;

    cout << endl << "----------------------------" << endl;
    cout << endl << "       Welcome Menu         " << endl;
    cout << endl << "----------------------------" << endl;

    //options for choosing
    cout << " 1. Customer\n";
    cout << " 2. Admin\n";

    cout << "Please input the number for accessing the menu. (Input -1 to exit application)" << endl;
    cout << "Input: ";
    cin >> opt;
    cout << "\n" << endl;

    switch (opt)
    {
    case 1:
        //goes to main menu
        customerLogIn();
        break;
    case 2:
        //goes to admin login page
        adminLogIn();
        break;
    case -1:
        //exits program completely
        //exit(0);
        runProgram = 0;
        break;
    default:
        break;
    }
}

///
/// END CONSOLE MENU
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() 
{
	//The adding and deleting items from inventory and the code to adjust json can be made a helper fucntion if you guys see fit
	//Loop to declare and put all json data into inventory vector always put on top
	d = json_util::read("data.json");

	inventory_size = 7;// this needs to be set according to our test size

	for (int count = 0; count < inventory_size; count++)
	{
		json_num Amount_SoldJson = (d["Inventory"][count]["Amount_Sold"]);
		json_string CategoryJson = (d["Inventory"][count]["Category"]);
		json_string Date_Of_ExpirationJson = (d["Inventory"][count]["Date_Of_Expiration"]);
		json_num Item_IDJson = (d["Inventory"][count]["Item_ID"]);
		json_string NameJson = (d["Inventory"][count]["Name"]);
		json_num PriceJson = (d["Inventory"][count]["Price"]);
		json_num QuantityJson = (d["Inventory"][count]["Quantity"]);

		Item Item1;
		Item1.AddDataInitial(Amount_SoldJson.val(), CategoryJson.val(), Date_Of_ExpirationJson.val(), Item_IDJson.val(), NameJson.val(), PriceJson.val(), QuantityJson.val());
		Inventory.push_back(Item1);
	}
	//Rest of whatever code

	//printHeading();
	//printInventory();
	//listByCategory("Meat");

	//addToInventory(123, "Oreo", 2.99, "2022-11-12", 10, "Chocolate", 12);
	//cout << "Inventory size: " << inventory_size;
	
	//deleteFromInventory(1342);
	//updateQuantity(1234, 100);
	//cout << " ----------------------- ";
	//printHeading();
	//printInventory();

    //running the menu continuously
    
    runProgram = 1;
    while (runProgram) {
        welcomeMenu();
    }
    
    cout << "OUT";

	///code to make inventory to json data
	for (int count = 0; count < inventory_size; count++)
	{
		json_num Amount_SoldJson = Inventory[count].Amount_Sold;
		json_string CategoryJson = Inventory[count].Category;
		json_string Date_Of_ExpirationJson = Inventory[count].Date_Of_Expiration;
		json_num Item_IDJson = Inventory[count].Item_ID;
		json_string NameJson = Inventory[count].Name;
		json_num PriceJson = Inventory[count].Price;
		json_num QuantityJson = Inventory[count].Quantity;


		d["Inventory"][count]["Amount_Sold"] = Amount_SoldJson;
		d["Inventory"][count]["Category"] = CategoryJson;
		d["Inventory"][count]["Date_Of_Expiration"] = Date_Of_ExpirationJson;
		d["Inventory"][count]["Item_ID"] = Item_IDJson;
		d["Inventory"][count]["Name"] = NameJson;
		d["Inventory"][count]["Price"] = PriceJson;
		d["Inventory"][count]["Quantity"] = QuantityJson;
	}

	json_util::write("data.json", d);	

}

