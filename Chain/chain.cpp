#include <stddef.h>
#ifndef C5
#define C5
#include"chain.h"
#endif
#include<iostream>

template<class T>
Chain<T>::~Chain(){
	std::cout<<"release Chain start"<<std::endl;
	ChainNode<T>* cn;
	while(true){
		if (this->head==NULL){
			break;
		}
		cn = this->head->next;
		delete this->head;
		this->head = cn;
	}
	std::cout<<"release Chain end"<<std::endl;
}

template<class T>
ChainNode<T>::~ChainNode(){
	std::cout<<"delete chain"<<std::endl;
	this->next = NULL;
}

template<class T>
ChainNode<T>::ChainNode(const T &element){
	this->element = element;
	this->next = NULL;
}
template<class T>
ChainNode<T>::ChainNode(const T &element,ChainNode<T>* next){
	this->element = element;
	this->next = next;
}
template<class T>
ChainNode<T>::ChainNode(ChainNode<T> *chainnode){
	this->element = chainnode->element;
	this->next = chainnode->next;
}

template<class T>
Chain<T>::Chain(){
	this->length = 0;
	T element;
	std::cin>>element;
	this->head = new ChainNode<T>(element);
	this->end = this->head;
	this->length++;
	while(true){
		std::cin>>element;
		if ((int)element==48){
			break;
		}
		this->end->next = new ChainNode<T>(element);
		this->end = this->end->next;
		this->length++;
	}	
}
template<class T>
Chain<T>::Chain(Chain<T>* chain){
	this->length = chain->length;
	ChainNode<T>* c1;
	ChainNode<T>* c2;
	c1 = new ChainNode<T>(chain->head);
	this->head = c1;
	int i;
	for (i=0;i<this->length-1;i++){
		c2 = new ChainNode<T>(c1->next);
		c1->next = c2;
		c1 = c1->next;
	}
	this->end = c1;
}
template<class T>
int Chain<T>::end_insert(ChainNode<T>* chainnode){
	if (this->head == NULL){
		this->head = chainnode;
		this->end = chainnode;
		this->length++;
		return 1;
	}else{
		this->end->next = chainnode;
		this->end = chainnode;
		this->length++;
		return 1;
	}
	return 0;
}
template<class T>
int Chain<T>::show_all(){
	ChainNode<T>* cn1;
	cn1 = this->head;
	int i = 0;
	for (;cn1!=NULL;cn1=cn1->next){
		std::cout<<"the "<<i<<"nd "<<"T: "<<cn1->element<<std::endl;
		i++;
	}
}

template<class T>
int Chain<T>::insert(int index,ChainNode<T>* chainnode){
	int i;
	ChainNode<T>* cn1 = this->head;
	if (index == 0){
		chainnode->next = this->head;
		this->head = chainnode;
		this->length++;
		return 1;
	}
	if (index == this->length){
		this->end_insert(chainnode);
		return 1;
	}
	for (i=0;i<this->length;i++){
		if (i==index-1){
			chainnode->next = cn1->next;
			cn1->next = chainnode;
			this->length++;
			return 1;	
		}
		else{
			cn1 = cn1->next;
		}
	}
}

template<class T>
int Chain<T>::delete_any(int index){
	ChainNode<T>* cn1 = this->head;
	if (index==0){
		this->head = this->head->next;
		delete cn1;
		this->length--;
		return 1;
	}
	int i;
	if (index==this->length-1){
		for (i=0;i<this->length;i++){
                	if (i==this->length-2){
                        	ChainNode<T>* cn2 = this->end;
				std::cout<<"===="<<cn2->element<<"==="<<std::endl;
                        	cn1->next = NULL;
				this->end = cn1;
				this->length--;
                        	delete cn2;
				return 1;
                	}
                	else{
                        	cn1 = cn1->next;
                	}
        	}
	}	
	for (i=0;i<this->length;i++){
		if (i==index-1){
                	ChainNode<T>* cn2 = cn1->next;
			cn1->next = cn2->next;
			this->length--;
			delete cn2;
			return 1;
                }
                else{
                        cn1 = cn1->next;
                }
        }
}
template<class T>
int Chain<T>::update_any(int index,const T &element){
	int i;
	ChainNode<T>* cn1 = this->head;
	for (i=0;i<this->length;i++){               
                if (i==index){          
                        cn1->element = element;
                        return 1;
                }
                else{                               
                        cn1 = cn1->next;
                }
        }
}
template<class T>
int Chain<T>::show_any(int index){
	int i;
        ChainNode<T>* cn1 = this->head;
        for (i=0;i<this->length;i++){
                if (i==index){
			std::cout << "element: "<<cn1->element<<std::endl;
                        return 1;
                }
                else{
                        cn1 = cn1->next;
                }
	}
}

