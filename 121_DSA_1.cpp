#include <iostream>
using namespace std;

class Inftopost {
public:
    char stack[100];
    char top;

    Inftopost() {
        top = -1;
    }

    void push(char c) {
        if (top < 99) {
            top++;
            stack[top] = c;
            
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return '\0'; 
    }

    char topelement() {
        if (top >= 0) {
            return stack[top];
        }
        return '\0'; 
    }

    int isempty() {
        return top == -1;
    }

    int isoperator(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return 1;
        }
        return 0;
    }

    int isoperand(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return 1;
        }
        return 0;
    }

    int precedence(char op) {
        if (op == '+' || op == '-'){
            return 1;
        } 
        else if (op == '*' || op == '/'){
            return 2;
        }
        return 0;
    }

    void convertITP(char infix[], char postfix[]) {
        int j = 0;

        for (int i = 0; infix[i] != '\0'; i++) {
            char c = infix[i];

            if (isoperand(c) == 1) {
                postfix[j] = c;
                j++;
            } 
            
            else if (c == '(') {
                push(c);
            } 
            
            else if (c == ')') {
                while(!isempty() && topelement() != '(') {
                    postfix[j] = pop();
                    j++;
                }
                pop(); 
            }
            
            else if (isoperator(c) == 1) {
                while (!isempty() && precedence(topelement()) >= precedence(c)) {
                    postfix[j] = pop();
                    j++;
                }
                push(c);
            }
        }

        while(!isempty()) {
            postfix[j] = pop();
            j++;
        }
        postfix[j] = '\0';
         
    }

    void printpost(char postfix[]) {
        cout << "Postfix is: " << postfix << endl;
    }

};

int main() {
    Inftopost ob;
    char postfix[100], infix[100];

    cout << "Enter Infix: ";
    cin >> infix;

    ob.convertITP(infix, postfix);
    ob.printpost(postfix);

    return 0;
}
