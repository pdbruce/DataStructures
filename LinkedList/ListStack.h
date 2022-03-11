#pragma once
#include "List.h"

template <class T>
class ListStack{

 private:
  List<T> stack;

 public:
  ListStack();
  ~ListStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  void print(string name){
    stack.print(name);
  }

};

template <class T>
ListStack<T>::ListStack(){
  List<T> stack;
}

template <class T>
ListStack<T>::~ListStack(){
  while(!stack.empty()){
    stack.removeStart();
  }
}

template <class T>
int ListStack<T>::size(){
  return stack.size();
}

template <class T>
bool ListStack<T>::empty(){
  if(stack.empty()){
    return true;
  }
  else{
    return false;
  }
}

template <class T>
void ListStack<T>::push(T value){
  stack.insertStart(value);
}

template <class T>
T ListStack<T>::pop(){
  T returnValue = stack.getFirst();
  stack.removeStart();
  return returnValue;
}
