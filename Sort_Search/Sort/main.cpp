#include<iostream>
#include"sort.cpp"

int main(){
	int array1[1] = {2};
	int array2[0]; 
	int array[15] = {5,5,1,10,11,6,9,8,7,2,3,4,1,10,9};
	Sort<int> *is;
	is = new Radix_Sort<int>();
	is->sort(array,15);
	int i = 0;
	int * arrayx = array;
	for (i=0;i<15;i++){
		std::cout<<*arrayx<<std::endl;
		arrayx = arrayx+1;
	}
	return 0;
}
