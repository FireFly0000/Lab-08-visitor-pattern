#ifndef __VISITLATEX_HPP__
#define __VISITLATEX_HPP__
#pragma once
#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "rand.hpp"
#include <iostream>
#include <string>
#include <sstream>

class VisitLatex : public Visitor {
protected:
    std::stringstream os;
    Base* _baseptr;
    Visitor* _ptr;

public:
    VisitLatex()
    {
        _ptr = nullptr;
        _baseptr = nullptr;
    };
    ~VisitLatex() { os.clear(); };
    void setPtr(Visitor* ptr) { _ptr = ptr; };
    // Nodes with no children are visited only once (index = 0)
    void visit_op(Op* node) {
        if (node->getRead() == false)
        {
            os << "{" << node->evaluate() << "}";
            node->setRead(true);
        }
    }
    void visit_rand(Rand* node) {
        if (node->getRead() == false)
        {
            os << "{" << node->evaluate() << "}";
            node->setRead(true);
        }
    }
    std::string PrintLaTeX(Base* ptr)
    {
        Iterator it(ptr);
        _baseptr = ptr;

        os << "$";
        
        
        //while (!it.is_done()) //it.current_index() < ptr->number_of_children()
        //{
            //if (it.current_node()->getRead() == false) {
            ptr->accept(_ptr, it.current_index());
            ptr->accept(_ptr, it.current_index()+1);
            ptr->accept(_ptr, it.current_index()+2);
            //ptr->accept(_ptr, it.current_index()+2);
            //it.current_node()->setRead(true);

            //it.next();
        //}
            //os << "{" << ptr->get_child(it.current_index()) << "}";
            //it.next();
        os << "$" << std::endl;
        return os.str();
    }
    // Nodes with two children are visited three times.
    // index = 0 -> begin
    // index = 1 -> middle
    // index = 2 -> end

    void visit_add_begin(Add* node)
    {
        bool closepar = false;
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {
            
            if (it.current_node()->number_of_children() == 0)
            {
                os << "{" << it.current_node()->stringify() << "}";
              
            }
            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                
                //leftop->accept(_ptr, it.current_index());
                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
        }
        os << ")";
        //int i = 0;
        //os << "{" << node->get_child(0)->stringify() << "}";
         
    }
    void visit_add_middle(Add* node) {
      
        //if (node->getRead() == false)
        {
            os << "+";
        }
    }
    void visit_add_end(Add* node) {
        //if (node->getRead() == false)
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        os << "(";
        while (it.is_done() == false)
        {
            if (it.current_node()->number_of_children() == 0)
            {
                os << "{" << it.current_node()->stringify() << "}";
            }
            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                // add checks to see if its division, mult, or pow and replace symbols with \cdot, ^, and \frac{numerator}{denominator}
                //rightop->accept(_ptr, it.current_index());
                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
        }

        //int i = 0;
        //os << "{" << node->get_child(0)->stringify() << "}";
        os << ")";
        os << "}";
    }
    void visit_sub_begin(Sub* node) {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {

            if (it.current_node()->number_of_children() == 0)
            {
                os << "{" << it.current_node()->stringify() << "}";

            }
            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());
                
                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
        }
        os << ")";
    }
    void visit_sub_middle(Sub* node) {
        os << "-";
    }
    void visit_sub_end(Sub* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        os << "(";
        while (it.is_done() == false)
        {
            if (it.current_node()->number_of_children() == 0)
            {
                os << "{" << it.current_node()->stringify() << "}";
            }
            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                // add checks to see if its division, mult, or pow and replace symbols with \cdot, ^, and \frac{numerator}{denominator}

                //rightop->accept(_ptr, it.current_index());
                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
        }

        //int i = 0;
        //os << "{" << node->get_child(0)->stringify() << "}";
        os << ")";
        os << "}";
    }
    void visit_mult_begin(Mult* node) {}
    void visit_mult_middle(Mult* node) {}
    void visit_mult_end(Mult* node) {}
    void visit_div_begin(Div* node) {}
    void visit_div_middle(Div* node) {}
    void visit_div_end(Div* node) {}
    void visit_pow_begin(Pow* node) {}
    void visit_pow_middle(Pow* node) {}
    void visit_pow_end(Pow* node) {}
};

#endif //__VISITLATEX_HPP__
