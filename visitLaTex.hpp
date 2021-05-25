#ifndef __VISITLATEX_HPP__
#define __VISITLATEX_HPP__

#pragma once
#include <string>
#include <string.h> //for to_string()
#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "rand.hpp" 

class VisitLatex: public Visitor {
public:
    VisitLatex(){ };
    // Nodes with no children are visited only once (index = 0)
    void visit_op(Op* node, std::string& res){
	res = res + "{" + node->stringify() + "}";
    }
    void visit_rand(Rand* node, std::string& res){
	res = res + "{" + node->stringify() + "}";
    }
    // Nodes with two children are visited three times.
    // index = 0 -> begin
    // index = 1 -> middle
    // index = 2 -> end
    
    void visit_add_begin(Add* node, std::string& res){
	res = res + "{(";
    }
    void visit_add_middle(Add* node, std::string& res){
	res = res + "+";
    }	
    void visit_add_end(Add* node, std::string& res){
	res = res + ")}";
    }
    //void visit_sub_begin(Sub* node);
    //void visit_sub_middle(Sub* node);
    //void visit_sub_end(Sub* node);
    //void visit_mult_begin(Mult* node);
    //void visit_mult_middle(Mult* node);
    //void visit_mult_end(Mult* node);
    //void visit_div_begin(Div* node);
    //void visit_div_middle(Div* node);
    //void visit_div_end(Div* node);
    //void visit_pow_begin(Pow* node);
    //void visit_pow_middle(Pow* node);
    //void visit_pow_end(Pow* node);
};

#endif //__VISITLATEX_HPP__
