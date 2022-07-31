#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include <vector>
using namespace json;
int inventory_size;
class Item 
{
	public:
		int	Amount_Sold;
		std::string Category;
		//need a time variable, time needs to be converted from iso 8601 to c++ string, and then back to iso 8602 
		int Item_ID;
		std::string Name;
		float Price;
		int Quantity;

		void AddDataInitial(int Amount_SoldInput, std::string CategoryInput, int Item_IDInput, std::string NameInput, float PriceInput, int QuantityInput)
		{
			Amount_Sold = Amount_SoldInput;
			Category = CategoryInput;
			Item_ID = Item_IDInput;
			Name = NameInput;
			Price = PriceInput;
			Quantity = QuantityInput;
		}
		void AddData(int Amount_SoldInput, std::string CategoryInput, int Item_IDInput, std::string NameInput, float PriceInput, int QuantityInput)
		{
			Amount_Sold = Amount_SoldInput;
			Category = CategoryInput;
			Item_ID = Item_IDInput;
			Name = NameInput;
			Price = PriceInput;
			Quantity = QuantityInput;
		}
};
int main() 
{
	//The adding and deleting items from inventory and the code to adjust json can be made a helper fucntion if you guys see fit
	//Loop to declare and put all json data into inventory vector always put on top
	std::vector<Item> Inventory;
	json_data d = json_util::read("data.json");
	inventory_size = 4;// this needs to be set according to our test size
	for (int count = 0; count < inventory_size; count++)
	{
		json_num Amount_SoldJson = (d["Inventory"][count]["Amount_Sold"]);
		json_string CategoryJson = (d["Inventory"][count]["Category"]);
		json_num Item_IDJson = (d["Inventory"][count]["Item_ID"]);
		json_string NameJson = (d["Inventory"][count]["Name"]);
		json_num PriceJson = (d["Inventory"][count]["Price"]);
		json_num QuantityJson = (d["Inventory"][count]["Quantity"]);

		Item Item1;
		Item1.AddDataInitial(Amount_SoldJson.val(), CategoryJson.val(), Item_IDJson.val(), NameJson.val(), PriceJson.val(), QuantityJson.val());
		Inventory.push_back(Item1);
		
	}
	//Rest of whatever code



	///
	///this section needed whenever any new data is added to the inventory test code shown
	Item Item2;
	Item2.AddData(98, "Meat", 12222, "BIG MEAT", 69.99, 420);
	Inventory.push_back(Item2);
	///essential
	inventory_size++;
	std::string whole = d.stringify();
	for (int count = 0; count < 8; count++)
	{
		whole.erase(whole.size() - 1, 8);
	}
	whole = whole + ",\n        {\n        }\n    ]\n}";
	json_util::writeStr("data.json",whole);
	d = json_util::read("data.json");
	///


	///Example of deleting item from inventory
	Inventory.erase(Inventory.begin()+1, Inventory.begin() + 2);
	inventory_size--;
	
	///essential everytime item from inventory is deleted
	std::string whole2 = d.stringify();

	int LastCurlyCloseBracketPos = whole2.find_last_of("}");
	int LastCurlyOpenBracketPos = whole2.find_last_of("{");
	whole2.erase(LastCurlyOpenBracketPos-10, LastCurlyCloseBracketPos+1);

	whole2 = whole2 + "\n    ]\n}";
	json_util::writeStr("data.json", whole2);
	d = json_util::read("data.json");
	Inventory.pop_back();
	inventory_size--;
	///

	

	///code to make inventory to json data
	for (int count = 0; count < inventory_size; count++)
	{
		json_num Amount_SoldJson = Inventory[count].Amount_Sold;
		json_string CategoryJson = Inventory[count].Category;
		json_num Item_IDJson = Inventory[count].Item_ID;
		json_string NameJson = Inventory[count].Name;
		json_num PriceJson = Inventory[count].Price;
		json_num QuantityJson = Inventory[count].Quantity;


		d["Inventory"][count]["Amount_Sold"] = Amount_SoldJson;
		d["Inventory"][count]["Category"] = CategoryJson;
		d["Inventory"][count]["Item_ID"] = Item_IDJson;
		d["Inventory"][count]["Name"] = NameJson;
		d["Inventory"][count]["Price"] = PriceJson;
		d["Inventory"][count]["Quantity"] = QuantityJson;
	}

	json_util::write("data.json", d);	

}

