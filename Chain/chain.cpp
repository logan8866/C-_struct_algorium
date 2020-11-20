#include <stddef.h>
#include"chain.h"
#include<iostream>
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
	this->head = NULL;
	this->end = head;
	this->length = 0;
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
	for (;cn1!=NULL;cn1=cn1->next){
		std::cout<<cn1->element<<" ";
	}
}

template<class T>
int Chain<T>::insert(int index,ChainNode<T>* chainnode){
	int i;
	ChainNode<T>* cn1 = this->head;
	if (index == 0){
		chainnode->next = this->head;
		this->head = chainnode;
	}
	for (i=0;i<this->length;i++){
		if (i==index-1){
			chainnode->next = cn1->next;
			cn1->next = chainnode;
			return 1;	
		}
		else{
			cn1 = cn1->next;
		}
	}
}
			

		


