/*
 ** $Filename: RPolish.h$
 **
 ** Description:Implementation of RPolish.h
 **
 ** By Peilun Zhang, 2015-04-17
 */

#include "RPolish.h"

//using Shunting-yard algorithm from wikipedia;

/*********************************************
 While there are tokens to be read:
 1. Read a token.
 2. If the token is a number, then add it to the output queue.
 3. If the token is an operator, o1, then:
 while there is an operator token, o2, at the top of the operator stack, and either
 o1 is left-associative and its precedence is less than or equal to that of o2, or
 o1 is right associative, and has precedence less than that of o2,
 then pop o2 off the operator stack, onto the output queue;
 push o1 onto the operator stack.
 4. If the token is a left parenthesis, then push it onto the stack.
 5. If the token is a right parenthesis:
 Until the token at the top of the stack is a left parenthesis, pop operators off the stack onto the output queue.
 6.Pop the left parenthesis from the stack, but not onto the output queue.
 7.If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
 8.When there are no more tokens to read:
 While there are still operator tokens in the stack:
 If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
 Pop the operator onto the output queue.
 9.Exit.
 **********************************************/
using namespace plzstd;
RPolish::RPolish(){
    
}
RPolish::RPolish(string exp){
    expression = exp;
}
RPolish::~RPolish(){
    
}
void RPolish::setExp(string exp)
{
    expression = exp;
}
void RPolish::clearStack()
{
    output.clear();
    oprt.clear();
}
bool RPolish::isOperator(char input){
    
    if(input == '+' || input == '-' || input == '/' || input == '*'
       || input == '!' || input == '%' || input == '=' || input == '^') return 1;
    
    return 0;
}
bool RPolish::isLeftAssoc(char input){
    if(input == '+' || input == '-' || input == '/' || input == '*' || input == '%')
    {
        return 1;
    }
    
    return 0;
}
//operator Priority
int RPolish::optPri(char input)
{
    if(input == '!')
        return 5;
    else if(input == '^')
        return 4;
    else if(input == '*' || input == '/' || input == '%')
        return 3;
    else if(input == '+' || input == '-')
        return 2;
    else if(input == '=')
        return 1;
    return 0;
}
void RPolish::change(){
    output.clear();
    oprt.clear();
    change(expression);
}
void RPolish::change(std::string exp){
    for(int i = 0 ; i < exp.length() ; i++ )
    {
        string temp;
        int isNumber = 0;
        if(exp[i] == ' ')
        {
            continue;
        }
        while( (exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.' )
        {
            temp += exp[i++];
            isNumber = 1;
            
        }
        if(temp.empty()){
            output.push(temp);
        }else if(isNumber){
            output.push(temp);
        }
        if (isOperator(exp[i]))
        {
            while (!oprt.empty())
            {
                char theOprt = oprt.top();
                if(isOperator(theOprt)){
                    int flag = 1;
                    if (isOperator(theOprt) &&
                        ( (isLeftAssoc(exp[i]) && (optPri(exp[i]) <= optPri(theOprt)) ) ||
                         (!isLeftAssoc(exp[i]) && (optPri(exp[i]) < optPri(theOprt)))))
                    {
                        
                        flag = 0;
                        string opt(1, oprt.pop());
                        output.push(opt);
                    }else{
                        
                        break;
                    }
                }else{
                    break;
                }
            }
            oprt.push(exp[i]);
        }
        else if(exp[i] == '(')
        {
            oprt.push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            bool PM = 0;
            while(!oprt.empty()){
                char topOP = oprt.top();
                if(topOP == '(')
                {
                    oprt.pop();
                    PM = 1;
                    break;
                }
                else
                {
                    
                    string opt(1, topOP);
                    oprt.pop();
                    output.push(opt);
                }
            }
            if(!PM){
                cout << "Parentheses mismatched" << endl;
                exit(-1);
            }
        }
        
    }
    
    
    while(!oprt.empty()){
        if(oprt.top() == ')' || oprt.top() == '('){
            cout << "Parentheses mismatched" << endl;
            exit(-1);
        }
        char topOPt = oprt.pop();
        string teOPT(1,topOPt);
        output.push(teOPT);
    }
}
