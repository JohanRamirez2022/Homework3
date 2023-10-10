#include <iostream>
#include <string>

#include "linkedstack.h"
#include "arrayStack.h"

using namespace std;

int main(){
    string ops;
    LinkedStack<char> stack;
    LinkedStack<int> stack2;


    string postfix;
    char pIn = '(';
    char pOut = ')';

    string answer;
    cout << "Enter an expression:";
    getline(cin >> std::ws, answer);
        // Generates Postfix expression
        for (string::size_type ch = 0; ch < answer.size(); ch++) {
            if (answer[ch] == '%' || answer[ch] == '/' || answer[ch] == '*' || answer[ch] == '+' || answer[ch] == '-'){
                ops += answer[ch];
            }
            else if (isdigit(answer[ch])){
                stack.push(answer[ch]);
            }
            else if (answer[ch] == pOut){
                stack.push(ops.back());
                ops.pop_back();
            }
            
            }
        //pushes remaining operations onto stack once end of expression is reached
        stack.push(ops.back());

        //Reverses the order of the stack 
        while (!stack.isEmpty()){
            char element = stack.peek();
            stack.pop();

            if(isdigit(element)){
                int val = element - '0';
                stack2.push(val);
            }
            else{
                stack2.push(element);
                cerr << "skipping character \t";
            }
        }

    return 0;
}
