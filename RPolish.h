/*
 ** $Filename: RPolish.h$
 **
 ** Description:Class that convert infix expression to postfix expression
 **
 ** By Peilun Zhang, 2015-04-17
 */
//
#ifndef calculator_RPolish_h
#define calculator_RPolish_h
#include "Stack.h"
using namespace std;
namespace plzstd {
    class RPolish{
    public:
        RPolish();
        RPolish(string);
        ~RPolish();
        void change();
        void setExp(string);
        void clearStack();
        inline bool isOperator(char);
        inline bool isLeftAssoc(char);
        int optPri(char);
        Stack<char> oprt;//operator stack;
        Stack<string> output;
    private:
        string expression;
        void change(std::string);
    };

    }
#endif
