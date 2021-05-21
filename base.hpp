#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
    public:
        virtual ~Base() = default;

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        virtual int number_of_children() = 0;
        virtual Base* get_child(int i) = 0;
};

#endif //__BASE_HPP__
