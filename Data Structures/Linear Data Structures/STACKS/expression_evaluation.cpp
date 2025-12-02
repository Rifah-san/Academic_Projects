#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

const int MAX = 100;
char stack[MAX];
int top = -1;

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void pushChar(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = ch;
}

char popChar() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    return stack[top--];
}

char peekChar() {
    if (top == -1) return '\0';
    return stack[top];
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char ch = infix[i];
        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            pushChar(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar();
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peekChar()) >= precedence(ch)) {
                postfix[j++] = popChar();
            }
            pushChar(ch);
        }
        i++;
    }
    
    while (top != -1) {
        postfix[j++] = popChar();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int valStack[MAX];
    int valTop = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isdigit(ch)) {
            valStack[++valTop] = ch - '0';
        }
        else if (isOperator(ch)) {
            int b = valStack[valTop--];
            int a = valStack[valTop--];
            int result;
            
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = (int)pow(a, b); break;
                default: result = 0;
            }
            
            valStack[++valTop] = result;
        }
    }
    
    return valStack[valTop];
}

int main() {
    char infix[MAX], postfix[MAX];
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    infixToPostfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;
    
    // Evaluate postfix
    char numericExpr[] = "34+2*";
    cout << "\nEvaluating " << numericExpr << ": ";
    cout << evaluatePostfix(numericExpr) << endl;
    
    return 0;
}
