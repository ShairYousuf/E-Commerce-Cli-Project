//ECE 4400 - Project

#include <iostream>
using namespace std;

void welcomeMenu();
void mainMenu();
void storeMenu();
void adminMenu();
void storeMenu();

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
            cout << "**Added to cart Item ID: " << input << " **"<< endl;
            cout << "\n" << endl;
        }
    }
    mainMenu();
}

//lists all the inventory in the store
void listAll() {
    //own menu and sort by price and date of expiry here
    ///
    /// Item ID | Name | Category | Price | Quantity | Amt Sold
    /// 123 | Milk | Dairy | 6.99 | 30 | 20
    /// 567 | Cheese | Dairy | 0.99 | 20 | 10
    /// 
    cout << endl << "--------------------" << endl;
    cout << endl << "      All Items     " << endl;
    cout << endl << "--------------------" << endl;

    cout << "**print of all items**" << endl;
    /// <summary>
    /// helper function example: printAllInventory();
    /// </summary>

    addToCart();
    
}

//allows user to search products by using category
void searchByCategory() {
    cout << endl << "--------------------" << endl;
    cout << endl << "   Category Search  " << endl;
    cout << endl << "--------------------" << endl;

    string category;
    cout << "Which category would you like to search? ";
    cin >> category;

    //print all the items of that category
    // funciton example: printOfCategory(category);

    addToCart();

}

//allows user to search products by using item ID
void searchByItemID() {

}

//allows user to search products by name
void searchByName() {

}

//function to sort inventory by date
void sortByDate() {

}

//function to sort inventory by price
void sortByPrice() {
    ///
    /// iterate through inventory and then use Sorting.cpp
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

    string name, email, phone;
    
    cout << endl << "Please input your name: ";
    cin >> name;

    cout << endl << "Plese input your email: ";
    cin >> email;

    cout << endl << "Please input your phone number: ";
    cin >> phone;

    /// <summary>
    /// NEED: THIS part has to be changed to input the information into customer history data structure
    /// </summary>
    /// 
    cout << "\n" << endl;
    cout << "Following information was collected: " << endl;
    cout << endl << "Name: " << name << "; Email: " << email << "; Phone: " << phone << endl;
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
void customerHistory() {
    cout << endl << "-------------------------" << endl;
    cout << endl << "     Customer History  " << endl;
    cout << endl << "-------------------------" << endl;

    ///helper function to print everything

}

//function that asks for information to add about item to inventory
void addNewItemMenu() {
    cout << endl << "-------------------------" << endl;
    cout << endl << "       Add New Item      " << endl;
    cout << endl << "-------------------------" << endl;

    string name, category, expiryDate;
    int itemID, price, quantity;

    cout << endl << "Please input Item ID of new item: ";
    cin >> itemID;

    cout << endl << "Plese input name of new item: ";
    cin >> name;

    cout << endl << "Please input price of new item: ";
    cin >> price;

    cout << endl << "Please input Date of Expiry of new item: ";
    cin >> expiryDate;

    cout << endl << "Please input Quanitity of new item: ";
    cin >> quantity;

    //by default amount sold will be 0
    //amtSold = 0;

    /// helper function for adding new Item:
    /// addToInventory(itemID, name, price, expiryDate, quantity);
    /// 
    cout << "** New item added: " << itemID << " | " << name << " ** ";

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
    
    ///
    /// helper function: deleteItem(itemID);
    ///

    cout << endl << "** Item ID: " << itemID << " has been deleted successfully **" << endl;
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
        customerHistory();
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
        exit(1);
        break;
    default:
        break;
    }

}
