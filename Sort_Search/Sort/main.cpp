#include<iostream>
#include"sort.cpp"

int main(){
	int array[15] = {1,5,2,4,3,6,9,7,8,10,15,14,11,12,13};
	Sort<int> *is;
	is = new Insertion_Sort<int>();
	is->sort(array,15);
	int i = 0;
	for (i=0;i<15;i++){
		std::cout<<array[i]<<std::endl;
	}
	return 0;
}
