#include"list.h"
#include<cstring>
#include<iostream>

template <class T>
List<T>::List(T* elements){
	int length = sizeof(elements)/sizeof(T);
	this->max_length = length*2;
	this->length = length;
	this->elements = new T[this->max_length];
	memcpy(this->elements,elements,length);
}
template <class T>
List<T>::List(){
	T element;
	int i = 0;
	this->max_length = 512;
	this->length = 0;
	this->elements = new T[this->max_length];
	while(true){
		std::cin >> element;
		if ((int)element==-1){
			break;
		}
		this->elements[i] = element;
		i++;
		this->length++;
	}
}
template <class T>
List<T>::List(List<T>* list){
	this->max_length = list->max_length;
	this->length = list->length;
	memcpy(this->elements,list->elements,this->max_length);
}
template <class T>
List<T>::~List(){
	std::cout<<"release List"<<std::endl;
	delete this->elements;
}
template <class T>
void List<T>::show_all(){
	int i;
	for (i=0;i<this->length;i++){
		std::cout<<"the "<<" nd "<<"T: "<<this->elements[i]<<std::endl;
	}
}
template<class T>
int List<T>::get_length(){
	return this->length;
}
template<class T>
T List<T>::find_by_index(int index){
	int i;
	if (index>this->length){
		return -1;
	}
	if (index==0){
		return this->elements[index];
	}
	for (i=0;i<this->length;i++){
		if (i==index){
			return this->elements[index];
		}
	}
}
template<class T>
int List<T>::find_by_T(T &element){
	int i;
	for (i=0;i<this->length;i++){
		if (this->elements[i]==element){
			return i;
		}
	}
	return -1;
}
template<class T>
void List<T>::insert_by_index(int index,T &element){
	int i;
	if(index>this->length){
		std::cout<<"error index"<<std::endl;
		return;
	}
	for (i=this->length-1;i!=index-1;i--){
		this->elements[i+1] = this->elements[i];
	}
	this->elements[index] = element;
	this->length++;
}
template<class T>
void List<T>::delete_by_index(int index){
	int i;
	for (i=index+1;i<this->length;i++){
		this->elements[i-1] = this->elements[i];
	}
	this->length--;
}


		







