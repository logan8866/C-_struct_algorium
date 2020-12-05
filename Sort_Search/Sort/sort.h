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

