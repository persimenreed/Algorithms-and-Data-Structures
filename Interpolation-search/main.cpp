// Group 6: Anders Liavåg Martinsen, Isak Wardenær Rønningen, Per Simen Reed, Preben Birkeland Wassbakk

#include <iostream>
using namespace std;

// Defining arrays from different datatypes
int intArray[] = {1, 2, 5, 7, 8, 10, 13, 15, 18, 19, 20, 23, 27, 28, 29};
float floatArray[] = {1.2, 1.3, 2.0, 2.4, 2.7, 4.6, 6.3, 6.4, 7.3, 7.6, 8};
string stringArray[] = {"ABCD", "ABCDE", "ABCDEF", "ABCDEFG", "ABCDEFGH" };


//function to find asciivalue from a string
int asciiVal(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += int(str[i]);
    }
    return sum;
}

// search function for the float array
bool interpolationSearchFloat(float num, int low, int high) {
    if (low <= high) {
        int estimate = low + ((double) (num - floatArray[low]) / (floatArray[high] - floatArray[low])) * (high - low); // interpolation formula to estimate value

        if (num == floatArray[estimate]) { // Value found if input number is equal to estimate-index
            cout << "found value: " << floatArray[estimate] << endl;
            return true;
        }

        if (num < floatArray[low] || num > floatArray[high]) { // Value will never be found if input number is higher or lower than first and last index in array
            cout << "Value out of scope" << endl;
            return false;
        }

        if (num < floatArray[estimate]) { // If input is less than estimate. If in range, run function again with new high value.
            if (num > floatArray[estimate - 1]) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchFloat(num, low, estimate - 1);
        } else if (num >
                   floatArray[estimate]) { // If input is more than estimate. If in range, run function again with new low value.
            if (num < floatArray[estimate + 1]) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchFloat(num, estimate + 1, high);
        }
    }
}

// search function for the int array
bool interpolationSearchInt(int num, int low, int high) {
    if (low <= high) {
        int estimate = low + ((double) (num - intArray[low]) / (intArray[high] - intArray[low])) * (high - low); // interpolation formula to estimate value

        if (num == intArray[estimate]) { // Value found if input number is equal to estimate-index
            cout << "found value: " << intArray[estimate] << endl;
            return true;
        }

        if (num < intArray[estimate]) {  // Check if input is less than estimate. If in range, run function again with new high value
            if (intArray[estimate - 1] < num) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchInt(num, low, estimate - 1);
        } else if (num > intArray[estimate]) { // If input is more than estimate. If in range, run function again with new low value.
            if (intArray[estimate + 1] > num) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchInt(num, estimate + 1, high);
        }
    }
}

// search function for the string array
bool interpolationSearchString(string input, int low, int high) {
    if (low <= high) {
        // interpolation formula to estimate value. We used ascii value as comparison
        int estimate = low + ((double) (asciiVal(input) - asciiVal(stringArray[low])) / (asciiVal(stringArray[high]) - asciiVal(stringArray[low]))) * (high - low);

        if ((asciiVal(input) == asciiVal(stringArray[estimate]))) { // Value found if ascii value for input is equal to estimate ascii value, and the strings are actually the same.
            if(input.compare(stringArray[estimate])){
                cout << "Value not found" << endl;
                return false;
            }
            cout << "found value: " << stringArray[estimate] << endl;
            return true;
        }

        if (asciiVal(input) < asciiVal(stringArray[low]) || asciiVal(input) > asciiVal(stringArray[high])) { // Value will never be found if input number is higher or lower than first and last index in array
            cout << "Value not of scope" << endl;
            return false;
        }

        if (asciiVal(input) < asciiVal(stringArray[estimate])) { // Check if input is less than estimate. If in range, run function again with new high value
            if (asciiVal(stringArray[estimate - 1]) < asciiVal(input)) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchString(input, low, estimate - 1);
        } else if (asciiVal(input) > asciiVal(stringArray[estimate])) { // If input is more than estimate. If in range, run function again with new low value.
            if (asciiVal(stringArray[estimate + 1]) > asciiVal(input)) { // Check if number is not in range, if so, return false
                cout << "Value not found" << endl;
                return false;
            }
            return interpolationSearchString(input, estimate + 1, high);
        }
    }
}

int main() {

    // input menu
    cout << "press 1 for integers" << endl;
    cout << "press 2 for float" << endl;
    cout << "press 3 for string" << endl;

    float floatNum = 0;
    int choice = 0;
    string inputString;

    // define high and low index range
    int low = 0;
    int highInt = sizeof(intArray) / sizeof(int);
    int highFloat = sizeof(floatArray) / sizeof(float);
    int highString = sizeof(stringArray) / sizeof(string);

    cin >> choice;

    bool strings = false;
    bool integers = false;
    bool floats = false;

    // check for input num
    switch (choice) {
        case 1:
            integers = true;
            break;
        case 2:
            floats = true;
            break;
        case 3:
            strings = true;
            break;
        default:
            cout << "you have to input a valid number" << endl;
            return 0;


    }
    if (integers) {

        // check that array length is longer than 1
        if((sizeof(intArray)/sizeof(int))<2){
            cout << "Array size must be minimum 2" << endl;
            return 0;
        }

        cout << "you have chosen integers" << endl;
        cout << "int array: " << endl;
        for (int i = 0; i < sizeof(intArray) / sizeof(int); i++) {
            cout << intArray[i] << " ";
        }
        cout << endl << "what int do you want to search for?" << endl;
        cin >> choice;
        interpolationSearchInt(choice, low, (highInt - 1)); // run function with int input


    } else if (floats) {

        // check that array length is longer than 1
        if((sizeof(floatArray)/sizeof(int))<2){
            cout << "Array size must be minimum 2" << endl;
            return 0;
        }

        cout << "you have chosen floats" << endl;
        cout << "float array: " << endl;
        for (int i = 0; i < sizeof(floatArray) / sizeof(float); i++) {
            cout << floatArray[i] << " ";
        }
        cout << endl << "what float do you want to search for?" << endl;
        cin >> floatNum;
        interpolationSearchFloat(floatNum, low, (highFloat - 1)); // run function for float search


    } else if (strings) {

        // check that array length is longer than 1
        if((sizeof(stringArray)/sizeof(string))<2){
            cout << "Array size must be minimum 2" << endl;
            return 0;
        }

        cout << "you have chosen strings" << endl;
        cout << "string array: " << endl;
        for (int i = 0; i < sizeof(stringArray) / sizeof(string); i++) {
            cout << stringArray[i] << " ";
        }
        cout << endl << "what string do you want to search for?" << endl;
        cin >> inputString;

        if(inputString.size() < 3){
            cout << "String size must be minimim 3 characters" << endl;
            return 0;
        }

        interpolationSearchString(inputString, low, (highString - 1)); // run function for string search
    }
}