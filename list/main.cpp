#include"list.cpp"
#include<iostream>

int main(){
	std::cout<<"-----input and show all-----"<<std::endl;
	List<int> *l1 = new List<int>();
	l1->show_all();

	std::cout<<"-----get length-----"<<std::endl;
	int length;
	length = l1->get_length();
	std::cout<<"length: "<<length<<std::endl;

	int element;
	int index;

	std::cout<<"-----know index find element-----"<<std::endl;
	std::cout<<"input index: ";
	std::cin>>index;
	element = l1->find_by_index(index);
	std::cout<<"find_by_index: "<<element<<std::endl;

	std::cout<<"-----know element find index-----"<<std::endl;
	std::cout<<"input element: ";
	std::cin>>element;
	index = l1->find_by_T(element);
	std::cout<<"find_by_T: "<<index<<std::endl;

	std::cout<<"-----insert and show all-----"<<std::endl;
	std::cout<<"input inserted element: ";
	std::cin>>element;
	std::cout<<"input inserted index: ";
	std::cin>>index;
	l1->insert_by_index(index,element);
	l1->show_all();
	
	std::cout<<"-----delete-----"<<std::endl;
	std::cout<<"input deleted index: ";
        std::cin>>index;
	l1->delete_by_index(index);
	l1->show_all();
	
	std::cout<<"----------"<<std::endl;
	delete l1;

}
