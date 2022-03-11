#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
int mySize;
template <class T>
class List{

 private:
  Node<T> * start;
 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

};

template <class T>
List<T>::List(){
	start = nullptr;
	mySize = 0;
}

template <class T>
List<T>::~List(){
	if(!empty()){
		Node <T> * currentNode = start;
		Node <T> * temp;
		while(currentNode->next != nullptr){
			temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
		}
	}
	else{

	}
}

template <class T>
int List<T>::size(){
	return mySize;
}

template <class T>
bool List<T>::empty(){
	if(start == nullptr){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
void List<T>::insertStart(T value){
	if(empty()){
		Node <T> * newNode = new Node<T>(value);
		start= newNode;
	}
	else{
		Node <T> * newNode = new Node<T>(value);
		newNode->next = start;
		start = newNode;
	}
	mySize++;
}

template <class T>
void List<T>::insertEnd(T value){
	if(empty()){
		Node<T> * newNode = new Node<T>(value);
		start = newNode;
		mySize++;
	}
	else{
		Node<T> * currentNode = start;
		while(currentNode->next != nullptr){
			currentNode = currentNode->next;

		}
		Node<T> * newNode = new Node<T>(value);
		currentNode->next = newNode;
		mySize++;
	}
}

template <class T>
void List<T>::insertAt(T value, int j){
	Node<T> * temp;
	if(j == 0){
		Node<T> * newNode = new Node<T>(value);
		newNode->next = start;
		start = newNode;
		mySize++;
	}
	else if(j == (mySize - 1)){
		Node<T> * currentNode = start;
		while(currentNode->next != nullptr){
			currentNode = currentNode->next;
		}
		Node<T> * newNode = new Node<T>(value);
		currentNode->next = newNode;
		mySize++;
	}
	else{
		Node<T> * currentNode = start;
		for(int i = 0; i < j; i++){
			temp = currentNode;
			currentNode = currentNode->next;
		}
		Node<T> * newNode = new Node<T>(value);
		temp->next = newNode;
		newNode->next = currentNode;
		mySize++;
	}
}

template <class T>
void List<T>::removeStart(){
	Node<T> * temp = start;
	start = start->next;
	delete temp;
	mySize--;
}

template <class T>
void List<T>::removeEnd(){
	Node<T> * currentNode = start;
	Node<T> * temp;
	while(currentNode->next != nullptr){
		temp = currentNode;
		currentNode = currentNode->next;
	}
	delete currentNode;
	temp->next = nullptr;
	mySize--;
}

template <class T>
void List<T>::removeAt(int j){
	Node<T> * currentNode = start;
	Node<T> * temp;
	if(j== 0){
		temp = start;
		start = start->next;
		delete temp;
	}
	else if(j == (mySize-1)){
		while(currentNode->next != nullptr){
			temp = currentNode;
			currentNode = currentNode->next;
		}
		temp->next = nullptr;
		delete currentNode;
		mySize--;
	}
	else{
		for(int i = 0; i < j; i++){
			temp = currentNode;
			currentNode = currentNode->next;
		}
		temp->next = currentNode->next;
		delete currentNode;
		mySize--;
	}
}

template <class T>
T List<T>::getFirst(){
	return start->value;
}

template <class T>
T List<T>::getLast(){
	Node<T> * currentNode = start;
	while(currentNode->next != nullptr){
		currentNode = currentNode->next;
	}
	return currentNode->value;
}

template <class T>
T List<T>::getAt(int j){
	Node<T> * currentNode = start;
	for(int i = 0; i < j; i++){
		currentNode = currentNode->next;
	}
	return currentNode->value; 
}

template <class T>
int List<T>::find(T key){
	int position = 0;
	Node<T> * currentNode = start;
	bool found = false;
	while((currentNode->next != nullptr) && (!found)){
		if(currentNode->value == key){
			found = true;
		}
		else{
			currentNode = currentNode->next;
			position++;
		}
	}
	if(found == true){
		return position;
	}
	else{
		return -1;
	} 
}
