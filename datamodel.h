//header file
#include<bits/stdc++.h>
using namespace std;

// i will initialize 3 classes product,item,cart
//forward declaration
class Item;
class Cart;
class Product{
	int id;
	string name;
	int price;
	public:
		Product(){
			
		}
		Product(int id,string name,int price){
			this->id = id;
			this->name = name;
			this->price = price;
		}
		string getDisplayName(){
			return name + " : Rs " + to_string(price) + "\n";
		}
		string getSortName(){
			return name.substr(0,1);
		}
		friend class Item;
		friend class Cart;
};

class Item{
	Product product;
	int quantity;
	public:
		Item(){
			
		}
		Item(Product p , int q):product(p),quantity(q){}
		int getItemPrice(){
			return product.price * quantity;
		}
		string getItemInfo(){
			return to_string(quantity) + " X " + product.name + " =  Rs. " + to_string(product.price * quantity) + "\n";
		}
		friend class Cart;
	
};

class Cart{
	unordered_map<int,Item> items;
	public:
		void addProduct(Product product){
			if(items.count(product.id) == 0){
			Item newItem(product,1);
			items[product.id] = newItem;}
			else{
				items[product.id].quantity+=1;
			}
		}
		int getTotal(){
			int to_amount = 0;
			for(auto itemPair : items){
				auto item = itemPair.second;
				to_amount += item.getItemPrice();
			}
			return to_amount;
		}
		string viewCart(){
			if(items.empty()){
				return "Cart is empty\n";
			}
			string itemizedList;
			int cart_total = getTotal();
			for(auto itemPair : items){
				auto item = itemPair.second;
				itemizedList.append(item.getItemInfo());
				
			}
			return itemizedList + "\n Total Amound : Rs. "+to_string(cart_total) + '\n';
		}
		bool isEmpty(){
			return items.empty();
		}
};