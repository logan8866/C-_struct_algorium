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
		if (i1==length1||length1==0){
			for(;i2<length2;i2++){
				target[target_now_index] = array2[i2];
				target_now_index++;
			}
			return 1;
		}
		if (i2==length2||length2==0){
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
	T target[length];
	int i = 0;
	T* temp_target = target;
	T* temp_array = array;
	T* temp;
	while(true){
		if (abstand>=length){
			break;
		}
		for (i=0;i<length;i+=abstand*2){
			if (length-i<=abstand){
				this->merge(temp_array+i,temp_array,length-i,0,temp_target,i);
			}
			else if (length-i<2*abstand){
				this->merge(temp_array+i,temp_array+i+abstand,abstand,length-i-abstand,temp_target,i);
			}
			else{
				this->merge(temp_array+i,temp_array+i+abstand,abstand,abstand,temp_target,i);
			}
		}
		abstand *=2;
		temp = temp_array;
		temp_array = temp_target;
		temp_target = temp;
	}
	if (temp_target == target){
		return 1;
	}
	if (temp_target == array){
		for(i=0;i<length;i++){
			array[i] = temp_target[i];
		}
		return 1;
	}
}


template<class T>
int Count_Sort<T>::sort(T* array, int length, T min, T max, int time){
	/*
	if (T!=int){
		return -1;
	}
	*/
	int abstand[max-min+1] = {0};
	int i=0;
	for (i=0;i<length;i++){
		abstand[array[i]-min]++;
	}
	int j = 0;
	for (i=0;i<(max-min+1);i++){
		while(abstand[i]!=0){
			array[j] = i+min;
			abstand[i]--;
			j++;
		}
	}
}


template<class T>
int Count_Sort<T>::sort(T* array, int length, int time){}


template<class T>
int Radix_Sort<T>::sort(T* array, int length, int time){
	int temp[10][length];
	int temp_count[10] = {0};
	int denominator = 1;
	int i = 0;
	/*
	for (i=0;i<length;i++){
		temp[array[i]%10][temp_count[array[i]%10]] = array[i];
		temp_count[array[i]%10]++;
	}
	int j = 0;
	for (i=0;i<10;i++){
		for (;temp_count[i]!=0;temp_count[i]--){
			array[j] = temp[i][temp_count[i]];
		}
	}
	*/
	int x;
	int j;
	int y = 0;
	while(true){
		y = 0;
		for (i=0;i<length;i++){
			x = (int)(array[i]%(denominator*10)/denominator);
                	temp[x][temp_count[x]] = array[i];
                	temp_count[x]++;
        	}
		if (temp_count[0] == length){
			y = 0;
                        for (i=0;i<10;i++){
                                for (j=0;j<temp_count[i];j++){
                                        array[y] = temp[i][j];
					y++;
                                }
                        }
                        return 1;
                }
        	for (i=0;i<10;i++){
                	for (j=0;j<temp_count[i];j++){
                        	array[y] = temp[i][j];
				y++;
                	}
			temp_count[i] = 0;
        	}
		denominator *= 10;
	}
}

		
















