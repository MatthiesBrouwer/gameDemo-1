#ifndef _OBJECTSTORAGE_HPP
#define _OBJECTSTORAGE_HPP
#include "gameObject.hpp"
#include <memory>

template <int N>
class objectStorage {
public:

    objectStorage();
    ~objectStorage(){delete[] store;}

   void add( std::shared_ptr<gameObject> p ){
      if( count < N ){
         store[ count ] = p;
         ++count;
      }
   }

   std::shared_ptr<gameObject> *  begin(){ return store;  }
   std::shared_ptr<gameObject> * end(){ return store + count; }

private:
   std::shared_ptr<gameObject> store[ N ];   
   int count = 0;
};




#endif