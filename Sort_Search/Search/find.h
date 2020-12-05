#include<ctime>

template<class T>
class Search{
	public:
		int compare_time;
		double execute_time;
		clock_t begin_time;
		clock_t end_time;
		virtual int search(T* array, int length, const T &element) = 0;
};

template<class T>
class Binary_Search:public Search<T>{
	public:
		int search(T* array, int length, const T &element);
		Binary_Search();
};

template<class T>
class Order_Search:public Search<T>{
	public:
		int search(T* array, int length, const T &element);
		Order_Search();
};
