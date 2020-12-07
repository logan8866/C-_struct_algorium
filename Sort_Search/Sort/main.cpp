#include<iostream>
#include"sort.cpp"
#include<random>

int main(){
	Sort<int>* is = new Insertion_Sort<int>();
	Sort<int>* ss = new Shell_Sort<int>();
	Sort<int>* ms = new Merge_Sort<int>();
	Count_Sort<int>* cs = new Count_Sort<int>();
	Sort<int>* rs = new Radix_Sort<int>();
	std::cout<<"----------Insertion_Sort----------"<<std::endl;
	is->run_caculate();
	std::cout<<"----------Shell_Sort----------"<<std::endl;
	ss->run_caculate();
	std::cout<<"----------Merge_Sort----------"<<std::endl;
	ms->run_caculate();
	std::cout<<"----------Count_Sort----------"<<std::endl;
	cs->run_caculate();
	std::cout<<"----------Radix_Sort----------"<<std::endl;
	rs->run_caculate();
/*
	Sort<int>* ms = new Merge_Sort<int>();
	//int array[8] = {1,3,2,5,6,3,4,3};
	int array[20] = {1,3,2,5,6,3,4,3,2,0,3,11,88,44,66,0,5,1,4,2};
	ms->sort(array,20);
	int i = 0;
	for (i=0;i<20;i++){
		std::cout<<array[i]<<std::endl;
	}
*/
	return 0;
}
