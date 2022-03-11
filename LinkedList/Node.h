#pragma once

template <class T>
class List;

template <class T>
class Node{

 friend class List<T>;

 private:
  T value;
  Node * next;

public:
 Node(T v){
   value = v;
   next = nullptr;
 }

};
