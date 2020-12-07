#include"sort.h"
#include<time.h>
#include<iostream>
#include<random>

template<class T>
int Insertion_Sort<T>::sort(T* array, int length, int time,int time2){
	int i = 0;
	int j = 0;
	T temp;
	this->compare_time[time][time2] = 0;
	this->move_time[time][time2] = 0;
	this->beginn_time[time][time2] = clock();
	for (i=1;i<length;i++){
		temp = array[i];
		for(j=i-1;j>=0;j--){
			this->compare_time[time][time2]++;
			if (temp>=array[j]){
				this->move_time[time][time2]++;
				array[j+1] = temp;
				break;
			}
			else if (temp<array[j]){
				this->move_time[time][time2]++;
				array[j+1] = array[j];
				if (j==0){
					array[0] = temp;
				}
			}
		}
	}
	this->end_time[time][time2] = clock();
	this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;

	return 1;
}


template<class T>
int Shell_Sort<T>::sort(T* array, int length, int time, int time2){
	int abstand = (int)(length/2);
	int i = 0;
	int j = 0;
	int x = 0;
	T temp;
	this->compare_time[time][time2] = 0;
	this->execute_time[time][time2] = 0;
	this->move_time[time][time2] = 0;
	this->beginn_time[time][time2] = clock();
	while(true){
		if (abstand==0){
			this->end_time[time][time2] = clock();
        		this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;
			return 1;
		}
		for (i=0;i<abstand;i++){
			for (j=i+abstand;j<length;j+=abstand){
				temp = array[j];
				for (x=j-abstand;x>=i;x-=abstand){
					this->compare_time[time][time2]++;
					if (temp>=array[x]){
						this->move_time[time][time2]++;
						array[x+abstand] = temp;
						break;
					}
					else if (temp<array[x]){
						this->move_time[time][time2]++;
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
	this->end_time[time][time2] = clock();
	this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;
	return 1;
}

template<class T>
int Merge_Sort<T>::merge(T* array1, T* array2, int length1, int length2, T* target, int begin_index, int time,int time2){
	int i1 = 0;
	int i2 = 0;
	int target_now_index = begin_index;
	while(true){
		if (i1==length1||length1==0){
			for(;i2<length2;i2++){
				this->move_time[time][time2]++;
				target[target_now_index] = array2[i2];
				target_now_index++;
			}
			return 1;
		}
		if (i2==length2||length2==0){
			for(;i1<length1;i1++){
				this->move_time[time][time2]++;
				target[target_now_index] = array1[i1];
				target_now_index++;
			}
			return 1;
		}
		this->compare_time[time][time2]++;
		if (array1[i1]<array2[i2]){
			this->move_time[time][time2]++;
			target[target_now_index] = array1[i1];
			target_now_index++;
			i1++;
		}
		else if (array1[i1]>array2[i2]){
			this->move_time[time][time2]++;
			target[target_now_index] = array2[i2];
			target_now_index++;
			i2++;
		}
		else if (array1[i1]==array2[i2]){
			this->move_time[time][time2]++;
			target[target_now_index] = array1[i1];
			target_now_index++;
			i1++;
			this->move_time[time][time2]++;
			target[target_now_index] = array2[i2];
			target_now_index++;
			i2++;
		}
	}
}


template<class T>
int Merge_Sort<T>::sort(T* array, int length, int time,int time2){
	int abstand = 1;
	T target[length];
	int i = 0;
	T* temp_target = target;
	T* temp_array = array;
	T* temp;
	this->compare_time[time][time2] = 0;
	this->execute_time[time][time2] = 0;
	this->move_time[time][time2] = 0;
	this->beginn_time[time][time2] = clock();
	while(true){
		if (abstand/2>=length){
			break;
		}
		for (i=0;i<length;i+=abstand*2){
			if (length-i<=abstand){
				this->merge(temp_array+i,temp_array,length-i,0,temp_target,i,time,time2);
			}
			else if (length-i<2*abstand){
				this->merge(temp_array+i,temp_array+i+abstand,abstand,length-i-abstand,temp_target,i,time,time2);
			}
			else{
				this->merge(temp_array+i,temp_array+i+abstand,abstand,abstand,temp_target,i,time,time2);
			}
		}
		abstand *=2;
		temp = temp_array;
		temp_array = temp_target;
		temp_target = temp;
	}
	if (temp_target == target){
		this->end_time[time][time2] = clock();
		this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;
		return 1;
	}
	if (temp_target == array){
		for(i=0;i<length;i++){
			this->move_time[time][time2]++;
			array[i] = temp_target[i];
		}
		this->end_time[time][time2] = clock();
		this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;
		return 1;
	}
}


template<class T>
int Count_Sort<T>::sort(T* array, int length, T min, T max, int time,int time2){
	/*
	if (T!=int){
		return -1;
	}
	*/
	int abstand[max-min+1] = {0};
	int i=0;
	this->compare_time[time][time2] = 0;
	this->execute_time[time][time2] = 0;
	this->move_time[time][time2] = 0;
	this->beginn_time[time][time2] = clock();
	for (i=0;i<length;i++){
		abstand[array[i]-min]++;
	}
	int j = 0;
	for (i=0;i<(max-min+1);i++){
		while(abstand[i]!=0){
			this->move_time[time][time2]++;
			array[j] = i+min;
			abstand[i]--;
			j++;
		}
	}
	this->end_time[time][time2] = clock();
	this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;

}


template<class T>
int Count_Sort<T>::sort(T* array, int length, int time,int time2){}


template<class T>
int Radix_Sort<T>::sort(T* array, int length, int time,int time2){
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
	this->compare_time[time][time2] = 0;
	this->execute_time[time][time2] = 0;
	this->move_time[time][time2] = 0;
	this->beginn_time[time][time2] = clock();
	while(true){
		y = 0;
		for (i=0;i<length;i++){
			x = (int)(array[i]%(denominator*10)/denominator);
			this->move_time[time][time2]++;
                	temp[x][temp_count[x]] = array[i];
                	temp_count[x]++;
        	}
		if (temp_count[0] == length){
			y = 0;
                        for (i=0;i<10;i++){
                                for (j=0;j<temp_count[i];j++){
					this->move_time[time][time2]++;
                                        array[y] = temp[i][j];
					y++;
                                }
                        }
			this->end_time[time][time2] = clock();
			this->execute_time[time][time2] = (double)(this->end_time[time][time2]-this->beginn_time[time][time2])/CLOCKS_PER_SEC;
                        return 1;
                }
        	for (i=0;i<10;i++){
                	for (j=0;j<temp_count[i];j++){
				this->move_time[time][time2]++;
                        	array[y] = temp[i][j];
				y++;
                	}
			temp_count[i] = 0;
        	}
		denominator *= 10;
	}
}


template<class T>
int Sort<T>::check(T* array, int length){
	int i = 0;
	for (i=1;i<length;i++){
		if (array[i]<array[i-1]){
			std::cout<<"Sort Error!"<<std::endl;
			return -1;
		}
	}
	return 1;
}


template<class T>
int Sort<T>::run_caculate(){
	int len[5] = {100,200,300,1000,2000};
	int array[5][2000] = {0};
	int i;
	int j;
	int x;
	std::default_random_engine e(clock());
	std::uniform_int_distribution<int>* u;
	/*
	int all_compare_time = 0;
	double all_execute_time = 0;
	int all_move_time = 0;*/
	int part_compare_time = 0;
	double part_execute_time = 0;
	int part_move_time = 0;
	int ck = 0;
	for (i=0;i<5;i++){
		u = new std::uniform_int_distribution<int>(0,len[i]);
		for (x=0;x<10;x++){
			e.seed(clock());
			for (j=0;j<len[i];j++){
				array[i][j] = (*u)(e);
			}
			this->sort(array[i],len[i],i,x);
			ck = this->check(array[i],len[i]);
			if (ck==-1){
				return -1;
			}
			part_compare_time += this->compare_time[i][x];
			part_execute_time += this->execute_time[i][x];
			part_move_time += this->move_time[i][x];
		}
		delete u;
		this->ave_compare_time[i] = part_compare_time/10;
		this->ave_execute_time[i] = (double)(part_execute_time/10);
		this->ave_move_time[i] = part_move_time/10;
		std::cout<<i<<" st "<<"compare time: "<<this->ave_compare_time[i]<<std::endl;
                std::cout<<i<<" st "<<"execute time: "<<this->ave_execute_time[i]<<std::endl;
                std::cout<<i<<" st "<<"move time: "<<this->ave_move_time[i]<<std::endl;

	}

}


template<class T>
int Count_Sort<T>::run_caculate(){
        int len[5] = {100,200,300,1000,2000};
        int array[5][2000] = {0};
        int i;
        int j;
        int x;
        std::default_random_engine e(clock());
        std::uniform_int_distribution<int>* u;
        /*
        int all_compare_time = 0;
        double all_execute_time = 0;
        int all_move_time = 0;*/
        int part_compare_time = 0;
        double part_execute_time = 0;
        int part_move_time = 0;
        int ck = 0;
        for (i=0;i<5;i++){
                u = new std::uniform_int_distribution<int>(0,len[i]);
                for (x=0;x<10;x++){
                        e.seed(clock());
                        for (j=0;j<len[i];j++){
                                array[i][j] = (*u)(e);
                        }
                        this->sort(array[i],len[i],0,len[i],i,x);
                        ck = this->check(array[i],len[i]);
                        if (ck==-1){
                                return -1;
                        }
                        part_compare_time += this->compare_time[i][x];
                        part_execute_time += this->execute_time[i][x];
                        part_move_time += this->move_time[i][x];
                }
                delete u;
                this->ave_compare_time[i] = part_compare_time/10;
                this->ave_execute_time[i] = (double)(part_execute_time/10);
                this->ave_move_time[i] = part_move_time/10;
                std::cout<<i<<" st "<<"compare time: "<<this->ave_compare_time[i]<<std::endl;
                std::cout<<i<<" st "<<"execute time: "<<this->ave_execute_time[i]<<std::endl;
                std::cout<<i<<" st "<<"move time: "<<this->ave_move_time[i]<<std::endl;

        }
}














