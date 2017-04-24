# Project_tree
//Position.h file

#include <iostream>
#include <cstring>
//#include "positionList.h"
#include <vector>

template <typename T>
class Position
{
public:
   Position();
   Position(T value): data_(value){}

   ~Position();

   T& operator* ();
   Position<T> parent() const;
   bool isRoot() const;
private:
   Position<T>* parent_;
   std::vector<Position*> children_;
   T& data_;
};

template<typename T>
Position<T>::Position()
{

}

template<typename T>
Position<T>::~Position()
{

}

template<typename T>
T& Position<T>::operator*()
{
   return data_;
}

template<typename T>
Position<T> Position<T>::parent() const
{
   return parent_;
}

template<typename T>
bool Position<T>::isRoot() const
{
   if(parent_ == NULL)
      return true;
}
                      
