#include<ctime>

template<class T>
class Search{
	private:
		int compare_time;
		double execute_time;
		clock_t begin_time;
		clock_t end_time;
	public:
		virtual int search(T* array, int length, T &element) = 0;
}

template<class T>
class Binary_Search:public Search{
	int search(T* array, int length, T &element);
}

template<class T>
class Order_Search:public Search{
	int search(T* array, int length, T &element);
}
