#include<iostream>
#include"sort.cpp"

int main(){
	int array1[1] = {2};
	int array2[1] = {1};
	int array[15] = {5,5,1,10,11,6,9,8,7,2,3,4,1,10,9};
	Merge_Sort<int> *is;
	is = new Merge_Sort<int>();
	is->merge(array1,array2,1,1,array,0);
	int i = 0;
	int * arrayx = array;
	for (i=0;i<15;i++){
		std::cout<<*arrayx<<std::endl;
		arrayx = arrayx+1;
	}
	return 0;
}
