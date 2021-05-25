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
      
            os << "{" << node->evaluate() << "}";
        
    }
    void visit_rand(Rand* node) {
       
            os << "{" << node->evaluate() << "}";
        
    }
    std::string PrintLaTeX(Base* ptr)
    {
        Iterator it(ptr);
        _baseptr = ptr;

        os << "$";

        //while (!it.is_done()) //it.current_index() < ptr->number_of_children()
        //{
            //if (it.current_node()->getRead() == false) {
            ptr->accept(_ptr, it.current_index()); // begin
            ptr->accept(_ptr, it.current_index()+1); // middle
            ptr->accept(_ptr, it.current_index()+2); // end

        os << "$" << std::endl;
        return os.str();
    }


    void visit_add_begin(Add* node)
    {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        Iterator next(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {



            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    
                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
           // next.next();
        }
        os << ")";
         
    }
    void visit_add_middle(Add* node) {
      
        //if (node->getRead() == false)
        {
            os << "+";
        }
    }
    void visit_add_end(Add* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        Iterator next(rightop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {



            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                

                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
           // next.next();
        }
        os << ")";
        os << "}";
    }
    void visit_sub_begin(Sub* node) {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        Iterator next(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {


            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    

                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << ")";
    }
    void visit_sub_middle(Sub* node) {
        os << "-";
    }
    void visit_sub_end(Sub* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        Iterator next(rightop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {

            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                   

                    os << "\\frac";
                   // os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << ")";
        os << "}";
    }
    void visit_mult_begin(Mult* node)
    {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        Iterator next(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {

            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                   

                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << ")";
    }
    void visit_mult_middle(Mult* node) {
        os << "\\cdot";
    }
    void visit_mult_end(Mult* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        Iterator next(rightop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {

            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                 
                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << ")";
        os << "}";
    }
    void visit_div_begin(Div* node) {
        os << "{"<< "\\frac";
    }
    void visit_div_middle(Div* node) {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        Iterator next(leftop);
        os << "{";
        while (it.is_done() == false)
        {


            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    os.str().pop_back();
                    os.str().pop_back();
                    os.str().pop_back();

                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
    }
    void visit_div_end(Div* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        Iterator next(rightop);
        os << "{";
        while (it.is_done() == false)
        {

            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    os.str().pop_back();
                    os.str().pop_back();
                    os.str().pop_back();
                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << "}";
    }
    void visit_pow_begin(Pow* node) {
        Base* leftop = node->get_child(0);
        Iterator it(leftop);
        Iterator next(leftop);
        os << "{";
        os << "(";
        while (it.is_done() == false)
        {


            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    os.str().pop_back();
                    os.str().pop_back();
                    os.str().pop_back();

                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
    }
    void visit_pow_middle(Pow* node) {
        os << "^";
    }
    void visit_pow_end(Pow* node) {
        Base* rightop = node->get_child(1);
        Iterator it(rightop);
        Iterator next(rightop);
        os << "{";
        while (it.is_done() == false)
        {



            if (it.current_node()->number_of_children() == 0) {
                os << "{" << it.current_node()->stringify() << "}";
            }

            else if (it.current_node()->number_of_children() == 2 && it.current_index() == 1) {
                //leftop->accept(_ptr, it.current_index());

                if (it.current_node()->stringify().find("+") != std::string::npos)
                {
                    os << "+";
                }
                else if (it.current_node()->stringify().find("*") != std::string::npos)
                {
                    os << "\\cdot";
                }
                else if (it.current_node()->stringify().find("/") != std::string::npos) {

                    int numindex = os.str().find_last_of("{");
                    std::string num = os.str().substr(numindex, os.str().find_last_of("}"));
                    os.str().pop_back();
                    os.str().pop_back();
                    os.str().pop_back();
                    os << "\\frac";
                    //os << num;
                }
                else if (it.current_node()->stringify().find("**") != std::string::npos) {
                    os << "^";
                }
                else //(it.current_node()->stringify() == "-")
                {
                    os << "-";
                }
            }
            it.next();
            //next.next();
        }
        os << ")";
        os << "}";
    }
};

#endif //__VISITLATEX_HPP__
