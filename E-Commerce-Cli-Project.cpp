#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include <vector>
using namespace std;
using namespace json;

//variable to keep track of inventory size
int inventory_size;
json_data d;


class Item 
{
	public:
		int	Amount_Sold;
		string Category;
		//made time variable into a string
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
			cout << endl << this->Item_ID << " | " << this->Name << " | " << this->Price << " | " << this->Quantity << " | " << this->Category << " | " << this->Amount_Sold << endl;
		}
};

vector<Item> Inventory;

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

int searchByItemID(int itemID) {
	for (int i = 0; i < Inventory.size(); i++) {
		if (Inventory[i].Item_ID == itemID) {
			return i;
		}
	}
}

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

void searchByCategory(string category) {
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


void printHeading() {
	cout << endl << "Item ID | Name | Price | Quantity | Category | Amt Sold" << endl;
}

void printInventory() {
	for (int i = 0; i < Inventory.size(); i++) {
		Inventory[i].printItem();
	}
}


int main() 
{
	//The adding and deleting items from inventory and the code to adjust json can be made a helper fucntion if you guys see fit
	//Loop to declare and put all json data into inventory vector always put on top
	d = json_util::read("data.json");

	inventory_size = 5;// this needs to be set according to our test size

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

	printHeading();
	//printInventory();
	//searchByCategory("Meat");

	//addToInventory(123, "Oreo", 2.99, "2022-11-12", 10, "Chocolate", 12);
	
	//deleteFromInventory(1342);

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

