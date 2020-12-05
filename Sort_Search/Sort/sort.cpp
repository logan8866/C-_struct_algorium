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
				if (j==0){
					array[0] = temp;
				}
			}
		}
	}
	this->end_time[time] = clock();
	this->execute_time[time] = (double)(this->beginn_time[time]-this->end_time[time])/CLOCKS_PER_SEC;

	return 1;
}


template<class T>
int Shell_Sort<T>::sort(T* array, int length, int time){
	int abstand = (int)(length/2);
	int i = 0;
	int j = 0;
	int x = 0;
	T temp;
	this->compare_time[time] = 0;
	this->execute_time[time] = 0;
	this->move_time[time] = 0;
	this->beginn_time[time] = clock();
	while(true){
		if (abstand==0){
			return 1;
		}
		for (i=0;i<abstand;i++){
			for (j=i+abstand;j<length;j+=abstand){
				temp = array[j];
				for (x=j-abstand;x>=i;x-=abstand){
					this->compare_time[time]++;
					if (temp>=array[x]){
						array[x+abstand] = temp;
						break;
					}
					else if (temp<array[x]){
						this->move_time[time]++;
						array[x+abstand] = array[x];
						if (x==i){
							array[i] = temp;
						}
					}
				}
			}
		}
		abstand = (int)(abstand/2);
	}
	this->end_time[time] = clock();
	this->execute_time[time] = (double)(this->beginn_time[time]-this->end_time[time])/CLOCKS_PER_SEC;
	return 1;
}

template<class T>
int Merge_Sort<T>::merge(T* array1, T* array2, int length1, int length2, T* target, int begin_index){
	int i1 = 0;
	int i2 = 0;
	int target_now_index = begin_index;
	while(true){
		if (i1==length1){
			for(;i2<length2;i2++){
				target[target_now_index] = array2[i2];
				target_now_index++;
			}
			return 1;
		}
		if (i2==length2){
			for(;i1<length1;i1++){
				target[target_now_index] = array1[i1];
				target_now_index++;
			}
			return 1;
		}
		if (array1[i1]<array2[i2]){
			target[target_now_index] = array1[i1];
			target_now_index++;
			i1++;
		}
		else if (array1[i1]>array2[i2]){
			target[target_now_index] = array2[i2];
			target_now_index++;
			i2++;
		}
		else if (array1[i1]==array2[i2]){
			target[target_now_index] = array1[i1];
			target_now_index++;
			i1++;
			target[target_now_index] = array2[i2];
			target_now_index++;
			i2++;
		}
	}
}


template<class T>
int Merge_Sort<T>::sort(T* array, int length, int time){
	int abstand = 1;
	int target[length];
	int i = 0;
	int *temp_target = target;
	int *temp_array = array;
	while(true){
		for (i=0;i<length;i+=)
		this->merge(

