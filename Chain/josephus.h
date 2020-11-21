#ifndef C5
#define C5
#include"chain.h"
#endif

template <class T>
class Josephus: public Chain<T>{
	public:
		Josephus():Chain<T>(){
			this->end->next = this->head;
		}
		void show_circle();
		void josephus_process(int k,int m);
		ChainNode<T>* delete_by_relativ_position(ChainNode<T>* cn,int position);
};

