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
    
    //===============================================
    void visit_sub_begin(Sub* node, std::string& res){
	res = res + "{(";
    }
    void visit_sub_middle(Sub* node, std::string& res){
	res = res + "-";
    }
    void visit_sub_end(Sub* node, std::string& res){
	res = res + ")}";
    }
    
    //================================================
    void visit_mult_begin(Mult* node, std::string& res){
	res = res + "{(";
    }
    void visit_mult_middle(Mult* node, std::string& res){
	res = res + "\\cdot";
    }
    void visit_mult_end(Mult* node, std::string& res){
	res = res + ")}";
    }

    //==============================================
    void visit_div_begin(Div* node, std::string& res){
	res = res + "{\\frac";
    }
    void visit_div_middle(Div* node, std::string& res){res = res + ""; }
    void visit_div_end(Div* node, std::string& res){ res = res + "}"; }
    
    //==============================================
    void visit_pow_begin(Pow* node, std::string& res){
	res = res + "({";
    }
    void visit_pow_middle(Pow* node, std::string& res){
	res = res + "^";
    }
    void visit_pow_end(Pow* node, std::string& res){
	res = res + ")}";
    }
    std::string PrintLaTeX(Base* ptr) {
        VisitLatex* v = new VisitLatex();
        std::string res;
        for (Iterator it(ptr); !it.is_done(); it.next()) {
            it.current_node()->accept(v, it.current_index(), res);
        }
        res = "$" + res + "$";
        return res;
    }
};

#endif //__VISITLATEX_HPP__
