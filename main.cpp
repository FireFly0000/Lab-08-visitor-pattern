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
    Op* Op1 = dynamic_cast<Op*>(four);
    Op1->SetNode(Op1);
    Base* two = new Op(2);
    Op* Op2 = dynamic_cast<Op*>(two);
    Op2->SetNode(Op2);
    Base* three = new Op(3);
    Op* Op3 = dynamic_cast<Op*>(three);
    Op3->SetNode(Op3);
    Base* seven = new Op(7.0);
    Op* Op7 = dynamic_cast<Op*>(seven);
    Op7->SetNode(Op7);
    Base* add = new Add(three, four);
    Add* Addptr2 = dynamic_cast<Add*>(add);
    Addptr2->SetNode(Addptr2);
    Base* add2 = new Add(add, two);
    Add* Addptr3 = dynamic_cast<Add*>(add2);
    Addptr2->SetNode(Addptr3);
    Base* sub = new Sub(add2, seven);
    Sub* subptr = dynamic_cast<Sub*>(sub);
    subptr->SetNode(subptr);
   // Base* mult = new Mult(add, seven);
    Base* Addbaseptr = new Add(add, seven);
    Add* Addptr = dynamic_cast<Add*>(Addbaseptr);  // get rid of this line, use visitor pattern instead(?)
    Addptr->SetNode(Addptr); // get rid of SetNode(), use visitor pattern instead(?)

    Iterator Additerator(Addbaseptr);
    
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

    /*for (int i = 0; i < Addptr->number_of_children(); ++i) {
        cout << Addptr->get_child(i)->evaluate() << endl;
    }*/

    cout << "Finished getting children" << endl;

    cout << "Printing in LaTeX Format: " << endl;
    stringstream os;
    
   /* Addbaseptr->accept(LaTeXVisitor, 0);
    Addbaseptr->accept(LaTeXVisitor, 1);
    Addbaseptr->accept(LaTeXVisitor, 2);*/
    
   cout << LaTeXVisitorptr->PrintLaTeX(Addbaseptr) << endl;


    //Base* minus = new Sub(add, two);


   cout << "Printing in normal format: " << endl;
    std::cout << Addbaseptr->stringify() << " = " << Addbaseptr->evaluate() << std::endl;



    return 0;
}

