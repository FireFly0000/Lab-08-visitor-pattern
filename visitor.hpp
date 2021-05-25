#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <string>

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class Visitor{
    public:
        //virtual ~Visitor() = default;
        //Visitor() = default;
        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node, std::string& res) = 0;
        virtual void visit_rand(Rand* node, std::string& res) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        
	virtual void visit_add_begin(Add* node, std::string& res) = 0;
        virtual void visit_add_middle(Add* node, std::string& res) = 0;
        virtual void visit_add_end(Add* node, std::string& res) = 0;
        
	virtual void visit_sub_begin(Sub* node, std::string& res) = 0;
        virtual void visit_sub_middle(Sub* node, std::string& res) = 0;
        virtual void visit_sub_end(Sub* node, std::string& res) = 0;
        
	virtual void visit_mult_begin(Mult* node, std::string& res) = 0;
        virtual void visit_mult_middle(Mult* node, std::string& res) = 0;
        virtual void visit_mult_end(Mult* node, std::string& res) = 0;
        
	virtual void visit_div_begin(Div* node, std::string& res) = 0;
        virtual void visit_div_middle(Div* node, std::string& res) = 0;
        virtual void visit_div_end(Div* node, std::string& res) = 0;

        virtual void visit_pow_begin(Pow* node, std::string& res) = 0;
        virtual void visit_pow_middle(Pow* node, std::string& res) = 0;
        virtual void visit_pow_end(Pow* node, std::string& res) = 0;
};

#endif //__VISITOR_HPP__
