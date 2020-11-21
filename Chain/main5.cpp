#include"chain5.cpp"
#include"chain.cpp"
#include<iostream>

int main(){

	std::cout<<"-----input and show all-----"<<std::endl;
	Chain5<char>* c51 = new Chain5<char>();
	c51->show_all();
	
	std::cout<<"-----delete many------"<<std::endl;
	int index_start;
	int index_end;
	std::cout<<"input index_start: ";
	std::cin>>index_start;
	std::cout<<"input index_end: ";
	std::cin>>index_end;
	c51->delete_many(index_start,index_end);
	c51->show_all();

	std::cout<<"----------"<<std::endl;
	delete c51;
}

