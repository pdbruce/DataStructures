#pragma once
#include "List.h"

template <class T>
class ListQueue{

 private:
  List<T> queue;

 public:
  ListQueue();
  ~ListQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  void print(string name){
    queue.print(name);
  }

};

template <class T>
ListQueue<T>::ListQueue(){
  List<T> queue;
}

template <class T>
ListQueue<T>::~ListQueue(){
  while(!queue.empty()){
    queue.removeStart();
  }
}

template <class T>
int ListQueue<T>::size(){
  return queue.size();
}

template <class T>
bool ListQueue<T>::empty(){
  if(queue.empty()){
    return true;
  }
  else{
    return false;
  }
}

template <class T>
void ListQueue<T>::enqueue(T value){
  queue.insertEnd(value);
}

template <class T>
T ListQueue<T>::dequeue(){
  T returnValue = queue.getFirst();
  queue.removeStart();
  return returnValue;
}
