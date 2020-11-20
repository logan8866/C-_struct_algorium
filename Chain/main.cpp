#include"chain.cpp"
#include<iostream>
using namespace std;
int main(){
	ChainNode<int>* cn1 = new ChainNode<int>(200,NULL);
	ChainNode<int>* cn2 = new ChainNode<int>(100);
	ChainNode<int>* cn3 = new ChainNode<int>(cn1);
	cn1->element = 300;
	cout << cn1->element << cn3->element;
	Chain<int>* c1 = new Chain<int>();
	c1->end_insert(cn1);
	c1->end_insert(cn2);
	c1->end_insert(cn3);
	cout << "------------";
	c1->show_all();
	cout<<"===========";
	Chain<int>* c2 = new Chain<int>(c1);
	c2->show_all();
	ChainNode<int>* cn4 = new ChainNode<int>(500);
	c2->insert(0,cn4);
	cout << "+++";
	c2->show_all();
}
