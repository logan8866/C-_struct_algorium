#include"sort.h"

template<class T>
int Insertion_Sort<T>::sort(T* array, int length, int time){
	int i = 0;
	int j = 0;
	T temp;
	this->compare_time[time] = 0;
	this->move_time[time] = 0;
	this->beginn_time[time] = clock();
	for (i=1;i<length;i++){
		temp = array[i];
		for(j=i-1;j>=0;j--){
			this->compare_time[time]++;
			if (temp>=array[j]){
				array[j+1] = temp;
				break;
			}
			else if (temp<array[j]){
				this->move_time[time]++;
				array[j+1] = array[j];
			}
		}
	}
	this->beginn_time[time] = clock();
	this->execute_time[time] = (double)(this->beginn_time[time]-this->end_time[time])/CLOCKS_PER_SEC;

	return 1;
}

