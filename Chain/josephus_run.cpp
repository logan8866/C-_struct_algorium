#include"josephus.cpp"
#include"chain.cpp"
#include<iostream>

int main(){

	Josephus<char>* j1 = new Josephus<char>();
	j1->show_circle();
	int k;
	int m;
	std::cout<<"input k: ";
	std::cin>>k;
	std::cout<<"input m: ";
	std::cin>>m;
	j1->josephus_process(k,m);
	j1->show_circle();

}
