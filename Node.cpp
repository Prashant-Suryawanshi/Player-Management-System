#include "Node.h"

	//Constructer
	template<class T>
	Node<T>::Node(T d){
		this->prev = 0;
		this->data = d;
		this->next = 0;
	}
	
	//Muteters/Setters
	template<class T>
	void Node<T>::setPrev(Node* p){
		this->prev = p;
	}
	template<class T>
	void Node<T>::setData(T d){
		this->data = d;
	}
	template<class T>
	void Node<T>::setNext(Node* n){
		this->next = n;
	}
	
	
	//Inspecters/Accessers/Getters
	template<class T>
	Node<T>* Node<T>::getPrev(){
		return this->prev;
	}
	template<class T>
	T& Node<T>::getData(){
		return this->data;
	}
	template<class T>
	Node<T>* Node<T>::getNext(){
		return this->next;
	}

