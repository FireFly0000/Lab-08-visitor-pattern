#ifndef __VISITMATHML_HPP__
#define __VISITMATHML_HPP__

#pragma once
#include <string>
#include <string.h> //for to_string()
#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "rand.hpp" 

class VisitMathml: public Visitor {
public:
    VisitMathml(){ };
    void visit_op(Op* node, std::string& res){
	res = res+ "    <cn>" + node->stringify() + "</cn>\n";
    }
    void visit_rand(Rand* node, std::string& res){
	res = res + "  <cn>" + node->stringify() + "</cn>\n";
    }
    
    //=================================================
    void visit_add_begin(Add* node, std::string& res){
	res = res + "  <apply>\n" + "    <plus/>\n";
    }
    void visit_add_middle(Add* node, std::string& res){
	//res = "	<plus/>\n" + res;

    }	
    void visit_add_end(Add* node, std::string& res){
	res = res + "  </apply>\n";
    }
    
    //=================================================

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

    //==================================================
    void visit_div_begin(Div* node, std::string& res){
	res = res + "{\\frac";
    }
    void visit_div_middle(Div* node, std::string& res){res = res + ""; }
    void visit_div_end(Div* node, std::string& res){ res = res + "}"; }
    
    //==================================================
    
    void visit_pow_begin(Pow* node, std::string& res){
	res = res + "({";
    }
    void visit_pow_middle(Pow* node, std::string& res){
	res = res + "^";
    }
    void visit_pow_end(Pow* node, std::string& res){
	res = res + ")}";
    }
};

#endif
