#include <iostream>
//#include "positionList.h"
#include "position.h"

template <typename T>
class Tree
{
public:
   Tree();
   Tree(ifstream& file);

   ~Tree();
   
   int size() const;
   bool empty() const;
   Position<T> root() const;
   std::vector<Position*> positions() const;
   void  PLofTree(Position<T>* pos, std::vector<Position*> result);

   void drawTree();
   void deleteTree();
private:
   Position<T>* root_;
   int size_;
};

template<typename T>
Tree<T>::Tree()
{
   
}

template<typename T>
Tree<T>::~Tree()
{

}

template <typename T>
int Tree<T>::size() const
{
   return size_;
}

template<typename T>
bool Tree<T>::empty() const
{
   return (size_ == 0);
}

template<typename T>
Position<T> Tree<T>::root() const
{
   return root_;
}

template<typename T>
PositionList<T> Tree<T>::positions() const
{
   //Use a recursive function that counts postion from root down
   if(empty())
      return 0;

   std::vector<Position*> result;
   PLofTree(root_, result);  

   return result;
}

template<typename T>
void Tree<T>::PLofTree(Position<T>* pos, PositionList<T>& result)
{
     std::vector<Position*> children = pos.children(); 
     if (children.size()>0)
     {

        Position<T>* temp = children.front();
        while (temp->next != NULL) 
        {         
            return PLofTree(temp, result); 
            result.addFront(temp);
            temp  = temp->next;   
        }
     }
}

template<typename T>
void Tree<T>::drawTree()
{

     std::vector<Position*> result;
     PositionList<T>* children = root_.children();
     if (children.size()>0)
     {

        Position<T>* temp = children.front();
        while (temp->next != NULL)
        {
            std::cout << " ";
            PLofTree(temp, result);
            
            std::cout << (temp->data_);

            temp  = temp->next;
        }
     }

}
/*
template<typename T>
void Tree<T>::deleteTree(Position<T>* node)
{
   PositionList<T>* children = node.children();

   if (children.size()>0 & )
   {
       Position<T>* temp = children.front();
      
        while (temp->next != NULL)
        {
            delete temp->value;
            temp  = temp->next;
            deleteTree(temp);
        }
     }
}*/
