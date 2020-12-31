#include"tree.h"
#include<iostream>

template<class T>
Tree<T>::Tree(){
	this->ltree = NULL;
	this->rtree = NULL;
}

template<class T>
Tree<T>::Tree(const T &data){
	std::cout<<"create"<<std::endl;
	this->data = data;
	this->ltree = NULL;
	this->rtree = NULL;
}

template<class T>
Tree<T>::~Tree(){
	std::cout<<"free"<<std::endl;
}

template<class T>
void create_tree(Tree<T> *&root){
	T tem_data;
	std::cin>>tem_data;
	if (tem_data == '0'){
		return;
	}
	//std::cout<<tem_data<<std::endl;
	root = new Tree<T>(tem_data);
	create_tree(root->ltree);
	create_tree(root->rtree);
}
	
template<class T>
void pre_order(Tree<T>* root){
	if (root==NULL){
		return;
	}
	std::cout<<root->data;
	pre_order(root->ltree);
	pre_order(root->rtree);
}

template<class T>
void middle_order(Tree<T>* root){
	if (root==NULL){
		return;
	}
	middle_order(root->ltree);
	std::cout<<root->data;
	middle_order(root->rtree);
}

template<class T>
void post_order(Tree<T>* root){
	if (root==NULL){
		return;
	}
	post_order(root->ltree);
	post_order(root->rtree);
	std::cout<<root->data;
}

template<class T>
Tree<T>* test(Tree<T> *&t){
	t = new Tree<T>('x');
}



