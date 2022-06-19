#include<bits/stdc++.h>
#include "datamodel.h"
using namespace std;
vector<Product> allProduct = {
	Product(1,"apple",26),
	Product(3,"mango",16),
	Product(2,"guava",36),
	Product(5,"banana",56),
	Product(4,"staberry",36),
	Product(6,"pineapple",20),
};
Product* chooseProduct(){
	//display list of product
	string ProductList;
	cout<<"Available products : "<<endl;
	for(auto product : allProduct){
		ProductList.append(product.getDisplayName());
	}
	cout<<ProductList<<endl;
	cout<<"-----------------------------------------"<<endl;
	string choice;
	cin>>choice;
	for(int i = 0; i < allProduct.size(); i++){
		if(allProduct[i].getSortName() == choice){
			return &allProduct[i];
		}
	}
	cout<<"Product not found!"<<endl;
	return NULL;

}
bool checkout(Cart &cart){
	if(cart.isEmpty())
	return false;
	int total = cart.getTotal();
	cout<<"Pay in Cash : "<<total<<endl;
	int paid;
	cin>>paid;
	if(paid >= total){
	cout<<"Change "<<paid - total<<endl;
	cout<<"Thankd you for shopping!";
	return true;
	}
	else{
		cout<<"Not enough cash!";
		return false;
	}
}
int main(){
	char action;
	Cart cart;
//	Item item;
	while(true){
		cout<<"Select an option : (a)dd item , (v)iew cart , (c)heckout ";
		cin>>action;
		if(action == 'a'){
			Product *product = chooseProduct();
			if(product != NULL){
				cout<<"Added to the Cart "<<product->getDisplayName()<<endl;
				//todo:
				cart.addProduct(*product);
				
			}
			
			//todo : add to cart
			//view all item + choose product + add to cart
		}
		else if(action == 'v'){
			cout<<"-----------------------"<<endl;
			cout<<cart.viewCart();
			cout<<"------------------------"<<endl;
			//todo : view cart
		}
		else if(action == 'c'){
			//todo : checkout
//			cart.viewCart();
			if(checkout(cart)){
				break;
			}
		}
	}
	
	
}