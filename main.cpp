#include <iostream>

//#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "add.hpp"

using namespace std;

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

   // Base* three = new Op(3);
   // Base* seven = new Op(7.0);
   Base* four = new Op(4);
   Base* two = new Op(2);
    //Base* mult = new Mult(seven, four);
  
    //Base* add = new Add(three, mult);
    Base* three = new Op(3);
    Base* seven = new Op(7.0);
    Base* mult = new Mult(three, seven);
    Base* Addbaseptr = new Add(mult, four);
    Add* Addptr = dynamic_cast<Add*>(Addbaseptr);
    Addptr->SetNode(Addptr);

    cout << "Addptr has " << Addptr->number_of_children() << " children" << endl;
    cout << "Getting children: " << endl;

    for (int i = 0; i < Addptr->number_of_children(); ++i) {
        cout << Addptr->get_child(i)->evaluate() << endl;
    }

    cout << "Finished getting children" << endl;

    //Base* minus = new Sub(add, two);

    std::cout << Addbaseptr->stringify() << " = " << Addbaseptr->evaluate() << std::endl;



    return 0;
}

