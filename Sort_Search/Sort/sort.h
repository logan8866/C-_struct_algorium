#include<ctime>

template<class T>
class Sort{
	public:
		long compare_time[5][10];
		double execute_time[5][10];
		clock_t beginn_time[5][10];
		clock_t end_time[5][10];
		long move_time[5][10];

		double ave_compare_time[5];
		double ave_execute_time[5];
		double ave_move_time[5];

		virtual int sort(T* array, int length, int time = 0,int time2 = 0) = 0;
		int check(T* array, int length);
		int run_caculate();
};

template<class T>
class Insertion_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0, int time2 = 0);
};


template<class T>
class Shell_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0, int time2 = 0);
};

template<class T>
class Merge_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0,int time2 = 0);
		int merge(T* array1,T* array2, int length1, int length2, T* target, int begin_index, int time,int time2);
};

template<class T>
class Count_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, T min, T max, int time = 0,int time2=0);
		int sort(T* array, int length, int time = 0,int time2 = 0);
		int run_caculate(); 
};


template<class T>
class Radix_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0,int time2 = 0);
};


