#pragma once

#include <iostream>

//#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "add.hpp"
#include "iterator.hpp"
#include "VisitorLaTeX.hpp"

using namespace std;

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Visitor* LaTeXVisitor = new VisitLatex();
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* seven = new Op(7.0);
    Base* mult = new Mult(four, two);
    Base* Divbaseptr = new Div(mult, two);
    Div* Addptr = dynamic_cast<Div*>(Divbaseptr);  // get rid of this line, use visitor pattern instead(?)
    Addptr->SetNode(Addptr); // get rid of SetNode(), use visitor pattern instead(?)

    Iterator Additerator(Divbaseptr);
    
    VisitLatex* LaTeXVisitorptr = dynamic_cast<VisitLatex*>(LaTeXVisitor); // making a ptr to derived class
    LaTeXVisitorptr->setPtr(LaTeXVisitor);



    cout << "Addptr has " << Addptr->number_of_children() << " children" << endl;
    cout << "Getting children: " << endl;

    while (Additerator.is_done() == false)
    {
        if (Additerator.current_node()->number_of_children() == 0)
        {
            cout << "i: " << Additerator.current_index() << endl << "node: " << Additerator.current_node()->stringify() << endl << endl;
        }
        else if (Additerator.current_node()->number_of_children() == 2 && Additerator.current_index() == 1)
        {
            cout << "i: " << Additerator.current_index() << endl << "node: " << Additerator.current_node()->stringify() << endl << endl;
        }
        Additerator.next();
    }

    cout << "Finished getting children" << endl;

    cout << "Printing in LaTeX Format: " << endl;
    stringstream os;
    
   cout << LaTeXVisitorptr->PrintLaTeX(Divbaseptr) << endl;


   cout << "Printing in normal format: " << endl;
    std::cout << Divbaseptr->stringify() << " = " << Divbaseptr->evaluate() << std::endl;



    return 0;
}

