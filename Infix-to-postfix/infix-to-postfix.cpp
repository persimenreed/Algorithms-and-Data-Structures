// Group 19: Anders Liavåg Martinsen, Isak Wardenær Rønningen, Per Simen Reed, Preben Birkeland Wassbakk
#include <iostream>
using namespace std;

//implemented Stack using array
class InfixStack {
    int size = 100;
    int top = -1;
    char stack[100];
public:
    void Infixpush(int value) {
        if (InfixisFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = value;
    }
    bool InfixisFull() {
        if (top == (size - 1))
            return true;
        else
            return false;
    }
    bool InfixisEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }
    void Infixpeek() {
        if (InfixisEmpty()) {
            cout << "Stack is underflow" << endl;
            return;
        }
        for (int i = top; i > -1; i--) {
            cout << stack[i] << endl;
        }
    }
    void Infixpop() {
        if (InfixisEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        stack[top--];
    }
    int InfixtopStack() {
        if (InfixisEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return stack[top];
    }
};

//Assigning a value to the operators to decide priority
int Infixpriority(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

//Function to convert Infix input to Postfix
void postfix_convertion(string s, InfixStack &temp, string postfixString[]) {
    char result[500];
    int resultIndex = 0;
    char prevChar = ' ';


    //Looping through the input character by character.
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        //Checking if input is number or charachter then adding it to results
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex] = c;
            resultIndex++;
        } //If input is ( push it to temp stack
        else if (c == '(')
            temp.Infixpush('(');
        //If input is ) pop from stack temp and add to result until ( is reached
        else if (c == ')') {
            result[resultIndex] = ','; // Added to separate inputs for better handling
            resultIndex++;
            while (temp.InfixtopStack() != '(') {
                result[resultIndex] = temp.InfixtopStack();
                temp.Infixpop();
                resultIndex++;
            }
            temp.Infixpop();
        } else {
            // Checking if two operators are entered after each-other, if then input is invalid and returns Fail
            if (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/' || prevChar == '^') {
                cout << "Fail" << endl;
                return;
            }
            //Adds operator to results.
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                result[resultIndex] = ','; // Added to separate inputs for better handling
                resultIndex++;
            }

            // Pop operators from stack temp and add to result based on value
            while (!temp.InfixisEmpty() && Infixpriority(s[i]) <= Infixpriority(temp.InfixtopStack())) {
                result[resultIndex] = temp.InfixtopStack();
                temp.Infixpop();
                resultIndex++;
                result[resultIndex] = ','; // Added to separate inputs for better handling
                resultIndex++;
            }
            temp.Infixpush(c);
        }
        prevChar = c; // Updating prevChar to the current character
    }

    // Pop the remaining operators from stack temp and add to result
    while (!temp.InfixisEmpty()) {
        result[resultIndex] = ','; // Added to separate inputs for better handling
        resultIndex++;
        result[resultIndex] = temp.InfixtopStack();
        temp.Infixpop();
        resultIndex++;
    }

    result[resultIndex] = '\0';

        string test = "";

    // Split the result into individual strings using commas, so we know if its 23 or 2 and 3 then store it in 'postfixString' array
        int y = 0;
        for (int i = 0; i < resultIndex; i++) {
            if (result[i] != ',') {
                test = test+ result[i];
            } else {
                postfixString[y] = test;
                test = "";
                y++;
            }
        }
        postfixString[y] = test;
        cout << result << endl;

}