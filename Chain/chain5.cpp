
#include"chain5.h"

template<class T>
void Chain5<T>::delete_many(int index_start, int index_end){
	ChainNode<T>* cn1 = this->head;
	ChainNode<T>* cn2;
	ChainNode<T>* cn3;
	int i;
	if (index_start==0){
		cn2 = cn1;
		for (i=0;i<this->length;i++){
                	if(i==index_end+1){
                        	break;
                	}
                	else{
                        	cn3 = cn2;
                       		cn2 = cn2->next;
                        	delete cn3;
                	}
        	}
		this->head = cn2;
		return;
	}

	for (i=0;i<this->length;i++){
		if (i==index_start-1){
			break;
		}
		else{
			cn1 = cn1->next;
		}
	}
	cn2 = cn1->next;
	for (i=index_start;i<this->length;i++){
		if(i==index_end+1){
			break;
		}
		else{
			cn3 = cn2;
			cn2 = cn2->next;
			delete cn3;
		}
	}
	cn1->next = cn2;
}
