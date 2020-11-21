#include"chain.cpp"
#include<iostream>
using namespace std;
int main(){

	cout<<"-----input and creat-----"<<endl;
	Chain<char>* c1 = new Chain<char>();
	c1->show_all();

	cout<<"-----length-----"<<endl;
	cout<<"length: "<<c1->length<<endl;

	cout<<"-----show all-----"<<endl;
	c1->show_all();

	char element;
	int index;

	cout<<"-----know index find element-----"<<endl;
	cout<<"input index: ";
	cin>>index;
	c1->show_any(index);

	cout<<"-----insert and show all-----"<<endl;
	cout<<"input index: ";
	cin>>index;
	cout<<"inpyt element: ";
	cin>>element;
	ChainNode<char>* cn = new ChainNode<char>(element);
	c1->insert(index,cn);
	c1->show_all();
	cout<<"length: "<<c1->length<<endl;

	cout<<"-----delete------"<<endl;
	cout<<"input index: ";
	cin>>index;
	c1->delete_any(index);
	c1->show_all();
	cout<<"length: "<<c1->length<<endl;

	cout<<"----------"<<endl;
	delete c1;

}
