#include"tree.cpp"

int main(){
	Tree<char>* t1,*t2;
	//t1 = test(t2);
	//std::cout<<t2->data;
	create_tree(t1);
	//if (t1==NULL){
		//std::cout<<"NULL"<<std::endl;
	//}
	std::cout<<"-------this is pre order-------"<<std::endl;
	pre_order(t1);
	std::cout<<std::endl;
	std::cout<<"-------this is middle order-------"<<std::endl;
	middle_order(t1);
	std::cout<<std::endl;
	std::cout<<"-------this is post order-------"<<std::endl;
	post_order(t1);
	std::cout<<std::endl;
}
