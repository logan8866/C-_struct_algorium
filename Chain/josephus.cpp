#include"josephus.h"
#include<iostream>

template <class T>
void Josephus<T>::show_circle(){
	ChainNode<T>* cn = this->head;
	int i = 0;
	while(true){
		if(cn==this->end){
			std::cout<<"the "<<i<<"nd "<<"T: "<<cn->element<<std::endl;
			return;
		}
		std::cout<<"the "<<i<<"nd "<<"T: "<<cn->element<<std::endl;
		i++;
		cn = cn->next;
	}
}

template<class T>
ChainNode<T>* Josephus<T>::delete_by_relativ_position(ChainNode<T>* cn,int position){
	while(true){
		if (position==1){
			if (cn==this->head){
				ChainNode<T>* cn2;
				cn2 = this->head;
				std::cout<<"out: "<<cn2->element<<std::endl;
				this->head = this->head->next;
				this->end->next = this->head;
				delete cn2;
				this->length--;
				return this->head;
			}
			if (cn==this->end){
				ChainNode<T>* cn2 = cn;
				int i;
				std::cout<<"out: "<<cn2->element<<std::endl;
				while(true){
					if (cn2->next==cn){
						break;
					}
					else{
						cn2 = cn2->next;
					}
				}
				cn2->next = cn->next;
				delete cn;
				this->end = cn2;
				this->length--;
				return this->head;
			}
			ChainNode<T>* cn2 = cn;
			std::cout<<"out: "<<cn->element<<std::endl;
			while(true){
				if (cn2->next==cn){
					break;
				}
				else{
					cn2 = cn2->next;
				}
			}
			cn2->next = cn->next;
			delete cn;
			this->length--;
			return cn2->next;


		}
		else{
			cn = cn->next;
			position--;
		}
	}
}


template<class T>
void Josephus<T>::josephus_process(int k, int m){
	int i;
	ChainNode<T>* cn = this->head;
	for (i=0;i<this->length;i++){
		if (i==k-1){
			break;
		}
		else{
			cn = cn->next;
		}
	}
	int r_position;
	if (m>this->length){
		r_position = m%this->length;
		if (r_position==0){
			r_position=this->length;
		}
	}
	else{
		r_position = m;
	}
	cn = this->delete_by_relativ_position(cn,r_position);
	while(true){
		if (this->length==1){
			break;
		}
		if (m>this->length){
			r_position = m%this->length;
			if (r_position==0){
				r_position=this->length;
			}
		}
		else{
			r_position = m;
		}
		cn = this->delete_by_relativ_position(cn,r_position);
	}
}
		


			




