#pragma once
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <iostream>
#include <ctype.h> // isdigit()
#include <cstring> //for strlen()
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

class Factory
{
private:
	Base* root = nullptr;
	bool neg(const char* input[], int i){
    		if( input[i][0] == '-'){
        		return true;
    		}
    		else return false;
	}
	bool not_1_decimal(const char* input[], int i){
    		int c = 0;
    		for(int j =0; j<strlen(input[i]); j++){
        		if(input[i][j] == '.'){
            			c++;
        		}
    		}
    		if(c >1){
        		return true;
    		}
    		else return false;
	}
	bool is_double(const char* input[], int i){
                if(!is_sub(input,i)){
                        for(int j =0; j<strlen(input[i]); j++){
                                if(!isdigit(input[i][j]) && j == 0 && !neg(input,i) ){
                                        return false;
                                }
                                if((j>0 && j<strlen(input[i])) && !isdigit(input[i][j]) && input[i][j] != '.' ){
                                        return false;
                                }
                                if(not_1_decimal(input,i)){
                                    return false;
                                }
                                if(j == strlen(input[i])-1 && input[i][j] =='.'){
                                    return false;
                                }
                        }
                        return true;
                }
                return false;
        }
	bool is_plus(const char* input[], int i){
		if(input[i][0] == '+' && strlen(input[i]) == 1){
			return true;
		}
		else return false;
	}
	bool is_sub(const char* input[], int i){
                if(input[i][0] == '-' && strlen(input[i]) == 1){
                        return true;
                }
                else return false;
        }
        bool is_mult(const char* input[], int i){
                if(input[i][0] == '*' && strlen(input[i]) == 1){
                        return true;
                }
                else return false;
        }
        bool is_div(const char* input[], int i){
                if(input[i][0] == '/' && strlen(input[i]) == 1){
                        return true;
                }
                else return false;
        }
	bool is_pow(const char* input[], int i){
                if(input[i][0] == '*' && strlen(input[i]) == 2 && input[i][1] == '*'){
                        return true;
                }
                else return false;
        }




			
public:
	~Factory(){
		delete root;
	}
	Base* parse(const char* input[], int length){
		int i = 0;
		//Base* root = nullptr;
		Base* lop = nullptr;
		Base* rop = nullptr;
		while(i<length){
			if(is_double(input,i)){
				lop = new Op(std::stod(input[i++]));
			}
			if (is_plus(input, i)) {
        			i++;
				if(is_double(input,i)){
					root = new Add(lop, new Op(std::stod(input[i])));
        				lop = root;
				}
				else{
					std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
					return nullptr;
				}
			}
			if (is_sub(input, i)) {
				i++;
				if(is_double(input,i)){
        				root = new Sub(lop, new Op(std::stod(input[i])));
        				lop = root;
				}
				else{
					std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
                                        return nullptr;
                                }

			}
			if (is_div(input,i)) {
        			i++;
				if(is_double(input,i)){
					root = new Div(lop, new Op(std::stod(input[i])));
        				lop = root;
				}
				else{
                                        std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
                                        return nullptr;
                                }
			}
			if (is_mult(input,i)) {
                		i++;
				if(is_double(input,i)){
					root = new Mult(lop, new Op(std::stod(input[i])));
                			lop = root;
				}
				else{
                                       	std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
                                        return nullptr;
                                }

        		}
        		if(is_pow(input,i)){
                		i++;
				if(is_double(input, i)){
					root = new Pow(lop, new Op(std::stod(input[i])));
                			lop = root;
        			}
				else{
                                        std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
                                        return nullptr;
                                }

			}
			if(!is_double(input,i) && !is_plus(input,i) && !is_sub(input, i) && !is_mult(input,i) && !is_div(input,i) && !is_pow(input,i)){
        			std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
        			return nullptr;
			}
			++i;
		}
		return root;


	}
};

#endif // 
