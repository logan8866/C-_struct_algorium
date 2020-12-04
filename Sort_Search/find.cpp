#include"find.h"

template<class T>
int Binary_Search::search(T* array, int length, T &element){
	int upper_limit = length-1;
	int lower_limit = 0;
	int middle_index = 0;
	this->compare_time = 0;
	this->begin_time = clock();
	while(true){
		this->compare_time++
		if ((lower_limit+upper_limit)%2==1){
			middle_index = ((int)((lower_limit+upper_limit)/2))+1;
		}
		else if((lower_limit+upper_limit)%2==0){
			middle_index = (lower_limit+upper_limit)/2;
		}
		if (array[middle_index]==element){
			this->end_time = clock();
			this->execute_time = (double)(this->end_time-this->begin_time)/CLOCKS_PER_SEC;
			return middle_index;
		}
		else if (array[middle_index]>element){
			upper_limit = middle_index-1;
		}
		else{
			lower_limit = middle_index+1
		}
}

template<class T>
int Order_Search::search(T* array, int length, T &element){
	this->compare_time = 0;
	int i = 0;
	this->begin_time = clock();
	for (i=0;i<length;i++){
		this->compare_time++;
		if (element == array[i]){
			this->end_time = clock();
			this->execute_time = (double)(this->end_time-this->begin_time)/CLOCKS_PER_SEC;
			return i;
		}
		else{
			continue;
		}
	}
	return -1;
}


