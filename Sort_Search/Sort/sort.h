#include<ctime>

template<class T>
class Sort{
	public:
		long compare_time[10];
		double execute_time[10];
		clock_t beginn_time[10];
		clock_t end_time[10];
		long move_time[10];

		long ave_compare_time;
		double ave_execute_time;
		long ave_move_time;

		virtual int sort(T* array, int length, int time = 0) = 0;
		int check(T* array, int length);
		int run_caculate();
};

template<class T>
class Insertion_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0);
};


template<class T>
class Shell_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0);
};

template<class T>
class Merge_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0);
		int merge(T* array1,T* array2, int length1, int length2, T* target, int begin_index);
};

template<class T>
class Count_Sort:public Sort<T> {
	public:
		int sort(T* array, int length, int time = 0);
};


