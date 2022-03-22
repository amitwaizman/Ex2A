

#ifndef NOTEBOOK_A_NOTEBOOKE_H
#define NOTEBOOK_A_NOTEBOOKE_H


#include <iostream>
#include <string>
#include "Direction.hpp"

using namespace std;
namespace ariel{
    class Notebook{
        int line_len=100;

    public:
      void  write( int page,  int row,int column,Direction dir, string const& str);
      static  string read( int page, int row,int column,Direction dir,int len);
      void  erase( int page,int row,int column,Direction dir,int len);
      void  show( int  page);

    };


};


#endif //NOTEBOOK_A_NOTEBOOKE_H
