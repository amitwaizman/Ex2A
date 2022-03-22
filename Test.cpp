

#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

ariel::Notebook notebook;

TEST_CASE("Good input ") {
    CHECK_NOTHROW(notebook.write(8, 1, 5, Direction::Horizontal, "DD"));
    CHECK_NOTHROW(notebook.write(0, 11, 10, Direction::Vertical, "HI"));
    CHECK_NOTHROW(notebook.write(15, 10, 15, Direction::Vertical, "DD"));
    CHECK_NOTHROW(notebook.write(0, 1, 1, Direction::Horizontal, "AMIT"));
    CHECK_NOTHROW(notebook.erase(16, 71, 15, Direction::Vertical, 2));
    CHECK_NOTHROW(notebook.erase(25, 12, 11, Direction::Vertical, 14));
    CHECK_NOTHROW(notebook.erase(11, 0, 1, Direction::Vertical, 12));
    CHECK_NOTHROW(notebook.erase(10, 11, 50, Direction::Vertical, 2));
}

TEST_CASE("Bad input negative") {
        CHECK_THROWS(notebook.write(8,-1,-5,Direction::Horizontal,"DD"));
        CHECK_THROWS(notebook.write(-18,-11,-4,Direction::Vertical,"DSSSD"));
        CHECK_THROWS(notebook.write(-90,-10,88,Direction::Vertical,"AMIT"));
        CHECK_THROWS(notebook.write(-90,-10,88,Direction::Vertical,"AMIT"));
        CHECK_THROWS(notebook.read(8,-1,-5,Direction::Vertical,8));
        CHECK_THROWS(notebook.read(-12,10,-4,Direction::Horizontal,7));
        CHECK_THROWS(notebook.read(-90,-10,88,Direction::Vertical,3));
        CHECK_THROWS(notebook.read(55,100,-4,Direction::Horizontal,8));
        CHECK_THROWS(notebook.erase(55,100,-4,Direction::Vertical,2));
        CHECK_THROWS(notebook.erase(22,99,-8,Direction::Vertical,14));
        CHECK_THROWS(notebook.erase(1,-9,-400,Direction::Vertical,12));
        CHECK_THROWS(notebook.erase(0,1,-4,Direction::Vertical,2));

}

TEST_CASE("Bad input ") {
    //Exceeds 100 characters
    CHECK_THROWS(notebook.write(8,1,112,Direction::Horizontal,"DD"));
    CHECK_THROWS(notebook.write(18,11,404,Direction::Vertical,"HI"));
    CHECK_THROWS(notebook.write(90,10,108,Direction::Vertical,"DD"));
    CHECK_THROWS(notebook.write(55,100,104,Direction::Horizontal,"DSSSD"));
    CHECK_THROWS(notebook.read(8,1,105,Direction::Vertical,8));
    CHECK_THROWS(notebook.read(12,10,114,Direction::Horizontal,7));
    CHECK_THROWS(notebook.read(90,10,188,Direction::Vertical,3));
    CHECK_THROWS(notebook.read(55,100,124,Direction::Horizontal,8));
    CHECK_THROWS(notebook.erase(55,100,114,Direction::Vertical,2));
    CHECK_THROWS(notebook.erase(22,99,108,Direction::Vertical,14));
    CHECK_THROWS(notebook.erase(1,49,400,Direction::Vertical,12));
    CHECK_THROWS(notebook.erase(0,1,100,Direction::Vertical,2));

    CHECK_THROWS(notebook.write(8,1,99,Direction::Horizontal,"amitwaiz"));
    CHECK_THROWS(notebook.write(18,11,95,Direction::Vertical,"HI my name is yovel"));
    CHECK_THROWS(notebook.write(90,10,98,Direction::Vertical,"hello"));

    CHECK_THROWS(notebook.erase(55,100,99,Direction::Vertical,5));
    CHECK_THROWS(notebook.erase(0,0,98,Direction::Vertical,5));
    CHECK_THROWS(notebook.erase(55,1,95,Direction::Vertical,15));

    CHECK_THROWS(notebook.read(12,2,99,Direction::Horizontal,7));
    CHECK_THROWS(notebook.read(8,10,95,Direction::Horizontal,8));
    CHECK_THROWS(notebook.read(0,5,92,Direction::Horizontal,17));


}

