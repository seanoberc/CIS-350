#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return true;
        default:
            return false;
    }
}


class InfixToPostfixConverter {
public:
    string convertToPostfix(string infix);

private:
    int precedence(char c);
};

int InfixToPostfixConverter::precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// convert infix expr. to postfix notation:
string InfixToPostfixConverter::convertToPostfix(string infix) {
    stack<char> cStack;
    string postfix;

    cStack.push('('); // first, push left parens onto stack
    infix += ')'; // then append right parens to end of infix expr.

    // run a loop to process list from left to right:
    for (size_t i = 0; i < infix.length(); ++i) {
        // var `c` will be used to evaluate each element at index "i" within infix
        char c = infix[i];

        // if the stack is empty, just break:
        if (cStack.empty()) {
            break;
        }

        // if the current char is a space, ignore it and continue the loop:
        if (isspace(c)) {
            continue;
        }

        // append char to postfix if it's a digit:
        if (isdigit(c)) {
            // check if current char is a digit
            // so long as it's not the end of the stack AND the next char is a digit:
            while ((i < infix.length()) && (isdigit(infix[i]))) {
                postfix += infix[i];
                i++;
            }

            // after the while loop has been evaluated, add a space after any
            //      char that is not a digit OR the end of the stack was reached:
            postfix += " ";
            i--; // step back one character to prevent the for loop from skipping next token
        } else if (c == '(') {
            cStack.push(c);
        } else if (isOperator(c)) {
            // check whether the char is an operator AND not a digit...
            // if the char is an operator, pop it from the stack and append based on precedence:
            while ((!cStack.empty())
                   && (isOperator(cStack.top()))
                   && (precedence(cStack.top()) >= precedence(c))) {
                // exponentiation is a special case ("right-associative"):
                if ((c == '^') && (cStack.top() == '^')) {
                    break;
                }
                postfix += cStack.top();
                postfix += " ";
                cStack.pop();
            }
            cStack.push(c);
        }
        // if the current char is a right parens, pop operators from the stack until the a left parens is reached:
        else if (c == ')') {
            // while the stack is not empty and the char is not a right parens:
            while ((!cStack.empty())
                   && (cStack.top() != '(')) {
                postfix += cStack.top();
                postfix += " ";
                cStack.pop();
            }
            // after the while loop is evaluated, discard left parens:
            if ((!cStack.empty())
                && (cStack.top() == '(')) {
                cStack.pop();
            }
        }
    }

    // if it exists, trim trailing whitespace:
    if ((!postfix.empty())
        && (postfix.back() == ' ')) {
        postfix.pop_back();
    }

    return postfix;
}


class PostfixEvaluator {
public:
    int evaluatePostfixExpression(string postfix);
};

int PostfixEvaluator::evaluatePostfixExpression(string postfix) {
    stack<int> iStack;
    postfix += ")";
    int i = 0;

    while (postfix[i] != ')') {
        char c = postfix[i];

        if (isspace(c)) {
            // if char is a space, skip and continue...
            i++;
            continue;
        }

        if (isdigit(c)) {
            int num = 0;
            // while it's not the end of the stack AND the next char is a digit:
            while ((i < postfix.length())
                   && (isdigit(postfix[i]))) {
                // converts the postfix element by subtracting the ASCII value of '0'
                //      ['0' = 48 in ASCII]
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            iStack.push(num);
            continue;
        }

        if (isOperator(c)) {
            int secondValue = iStack.top();
            iStack.pop();

            int firstValue = iStack.top();
            iStack.pop();

            switch (c) {
                case '+':
                    iStack.push(firstValue + secondValue);
                    break;
                case '-':
                    iStack.push(firstValue - secondValue);
                    break;
                case '*':
                    iStack.push(firstValue * secondValue);
                    break;
                case '/':
                    iStack.push(firstValue / secondValue);
                    break;
                case '^':
                    iStack.push(static_cast<int>(pow(firstValue, secondValue)));
                    break;
                default:
                    break;
            }
            // then increment past the operator:
            i++;
        }
    }
    // once ')' is found, return the top value of the stack:
    return iStack.top();
}


int main() {
    // create instances of classes:
    InfixToPostfixConverter converter;
    PostfixEvaluator evaluator;
    // string var to store infix:
    string infix;

    cout << "Enter an infix expression: " << endl;
    getline(cin, infix);

    try {
        string postfix = converter.convertToPostfix(infix);
        cout << "Postfix Expression: " << postfix << endl;

        int result = evaluator.evaluatePostfixExpression(postfix);
        cout << "Final Result: " << result << endl;
    } catch (...) {
        // catch-all
        cerr << "An error occurred during calculation." << endl;
    }

    return 0;
}
