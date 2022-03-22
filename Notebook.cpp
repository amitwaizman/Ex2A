
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>


using namespace std;
namespace ariel {
    void Notebook:: write(int  page,int  row, int  column,Direction dir, string const& str){
    }

    string Notebook:: read(int  page,int  row,int   column, Direction dir,int   len) {
        return "";
    }

    void Notebook::erase(int  page,int  row, int  column, Direction dir, int  len) {
    }
    void Notebook::show(int page) {
    }
}
