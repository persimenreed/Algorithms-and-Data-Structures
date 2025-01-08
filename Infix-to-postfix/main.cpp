// Group 19: Anders Liavåg Martinsen, Isak Wardenær Rønningen, Per Simen Reed, Preben Birkeland Wassbakk
#include <iostream>
#include "infix-to-postfix.cpp"

using namespace std;

//implemented stack using array
class Stack {
    int size = 10;
    int top = -1;
    string stack[10];
public:
    void push(basic_string<char> value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = value;
    }

    bool isFull() {
        if (top == (size - 1))
            return true;
        else
            return false;
    }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        stack[top--];
    }

    string topStack() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return stack[top];
    }
};


Stack stackPostfix;

//check if a string is an operator
int isOperator(const std::string &myElement) {
    if (myElement == "-" || myElement == "+" || myElement == "*" || myElement == "/" || myElement == "^")
        return true;
    else
        return false;
}

//checking for 'x' in a given string
bool checkForX(const std::string &searchString) {
    for (int i = 0; i < searchString.length(); i++) {
        if (searchString[i] == 'x') {
            return true;
        }
    }
    return false;
}





int main() {

    InfixStack temp;
    string infix1;
    string infix2;
    string postfixString[100]; // Define postfixString here

    cout << "Enter the first infix expression: ";
    cin >> infix1;
    cout << "Enter the second infix expression: ";
    cin >> infix2;

    bool foundHat1 = false;
    bool foundHat2 = false;

    for (int i = 0; infix1[i] != '\0'; i++) {
        if (infix1[i] == '^') {
            foundHat1 = true;
        }
    }
    for (int i = 0; infix2[i] != '\0' ; i++) {
        if (infix2[i] == '^') {
            foundHat2 = true;
        }
    }


    string equation;
    if(foundHat1 && foundHat2){
        equation = infix1+infix2;
    }else
        equation = infix1+"+"+infix2;

    cout << "the equation you put in: "<< infix1 << " + " << infix2 << endl;
    postfix_convertion(equation, temp, postfixString);





    //finding the size for the coeffiecient array:
    /*
   when finding the right size for the coeffient array, we check for any ^ and if we find it we check for the highest power of x, the highest power
    of x (+1 to account for noraml numbers) has to be the limit for the coefficient array. But when no ^ is found we have to see if we find any x
    and then the coefficient array at least has to be the length of 2. if neither x nor ^ are found it has to be the length of 1. this long and complicated
    check would be shortened if we had used x^1 and x^0 for just x and normal numbers.
   */

    int coeffArraySize, highestPower = 0;
    bool foundpower = false;
    bool foundx = false;

    for (int i = 0; postfixString[i] != "\0" ; i++) {
        if (postfixString[i] == "^") {
            if (highestPower < stoi(postfixString[i - 1])) {
                highestPower = stoi(postfixString[i - 1]);
                foundpower = true;
            }
        }else if(checkForX(postfixString[i]))
            foundx = true;
    }

    if(foundpower)
        coeffArraySize = highestPower + 1;
    else if(foundx)
        coeffArraySize = 2;
    else
        coeffArraySize = 1;

    cout << "coefficient array size: " << coeffArraySize << endl;

    int coefficientArray[coeffArraySize];
    for (int i = 0; i < coeffArraySize; i++) {
        coefficientArray[i] = 0;
    }











    /*evaluating/simplifying the expression, this is somewhat chaotic but it works for our purpose it would - like the calculation of size for the coefficient array - would
    have been a lot simpler to both read the code and to code, if we did x^1 and x^0 for x and standalone numbers

     */
    int operand1, operand2;
    bool done = false;
    int i = 0;

    while (!done) {
        if (!isOperator(postfixString[i])) { //if not an operator we push to stack
            stackPostfix.push(postfixString[i]);

        } else {

            if (postfixString[i] == "^") { //if we find a ^ in the sequence we pop two elements for the stack this is the power and the coefficient for the x
                operand2 = std::stoi(stackPostfix.topStack());
                stackPostfix.pop();
                operand1 = std::stoi(stackPostfix.topStack());
                stackPostfix.pop();

                //we then check for - or + in the character after the ^, no matter if + or - we still put the coefficient into the coefficient array,
                //with the index being the coefficient
                //if we find a + or - after the hat we jump over the + or - for the next loop, however if we dont, we let the + or - be evaluated in the next loop
                if (postfixString[i + 1] == "-") {
                    coefficientArray[operand2] -= operand1;
                    if(stackPostfix.isEmpty())
                        i++;
                }else if(postfixString[i + 1] == "+"){
                    coefficientArray[operand2] += operand1;
                    if(stackPostfix.isEmpty())
                        i++;
                }
                else {
                    coefficientArray[operand2] += operand1;
                }

            } else if("+" || "-") { //if we find a pluss or minus without having found a ^ right before, we know that it is a x^1 or x^0
                if (checkForX(stackPostfix.topStack())) { //we check for x to see if x^1 or x^0
                    operand2 = std::stoi(stackPostfix.topStack());
                    stackPostfix.pop();
                    if (postfixString[i] == "-") // if x^1 we insert the coefficient at index 1 in the coefficient array (index 1 is for x^1), firstly we check if sign is - or +
                        coefficientArray[1] -= operand2;
                    else {
                        coefficientArray[1] += operand2;
                    }
                } else { //if x^0 we insert the coefficient at index 0 in the coeffiecient array (index 0 is for  x^0), firstly we check if sign is - or +
                    operand2 = std::stoi(stackPostfix.topStack());
                    stackPostfix.pop();
                    if (postfixString[i] == "-")
                        coefficientArray[0] -= operand2;
                    else {
                        coefficientArray[0] += operand2;
                    }
                }

            }

        }

        i++; //increment i manually since it a while loop

        //if we reached the end of the string we break, this has to be here because the postfixString is not always the correct size so
        //we got stack overflow warning if we didnt break it when i finished, this also prevents junk to enter the algorithm
        if(postfixString[i] == "\0") {
            if (stackPostfix.isEmpty())
                break;
            else{
                if(checkForX(stackPostfix.topStack())){
                    coefficientArray[1] += stoi(stackPostfix.topStack());
                    break;
                }else{
                    coefficientArray[0] += stoi(stackPostfix.topStack());
                    break;

                }
            }
        }


    }



    //print output in the infix format
    for (int j = coeffArraySize-1; j >= 0; j--) {
        if (!coefficientArray[j] == 0) {

            if (j == 0) {
                if (j == coeffArraySize+1)
                    cout << to_string(coefficientArray[j]);
                else if(coefficientArray[j] < 0)
                    cout << " " << to_string(coefficientArray[j]);
                else
                    cout << " + " << to_string(coefficientArray[j]);
            } else if (j == 1) {
                if(j == coeffArraySize-1)
                    cout << to_string(coefficientArray[j]) << "x";
                else if(coefficientArray[j]<0)
                    cout << " " << to_string(coefficientArray[j]) << "x";
                else
                    cout << " + " <<to_string(coefficientArray[j]) << "x";
            } else if (j > 1) {
                if(j == coeffArraySize-1)
                    cout <<to_string(coefficientArray[j]) << "x^" << to_string(j);
                else if(coefficientArray[j]<0)
                    cout << " " <<to_string(coefficientArray[j]) << "x^" << to_string(j);
                else
                    cout << " + " <<to_string(coefficientArray[j]) << "x^" << to_string(j);
            }
        }
    }
    cout << endl;

    return 0;
}