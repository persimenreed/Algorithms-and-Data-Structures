// Group 9: Anders Liavåg Martinsen, Isak Wardenær Rønningen, Per Simen Reed, Preben Birkeland Wassbakk
#include <iostream>

using namespace std;

void prefix(int *prefix, string pattern) { // Creating a prefix table to make the search easier

    prefix[0] = 0;
    int i = 0;
    int j = 1;
    while (j < pattern.size()) { // while not at end of pattern
        if (pattern[i] == pattern[j]) { // Compare the pattern. If compares, increment i and j, and update prefix table
            i++;
            prefix[j] = i;
            j++;

        } else { // If not equal
            if (i == 0) { // Not equal, and i = 0, update the prefix table with 0. Increment j to check next index
                prefix[j] = 0;
                j++;
            } else // Not equal and not 0, set i to 0 to reset comparison.
                i = 0;
        }
    }
}

void KMP(string txt, string pattern) { // Function that search string for the inputted pattern
    int txtLen = txt.size(); // get length of inputted text
    int patternLen = pattern.size(); // get length of inputted pattern

    int prefixTable[patternLen]; // declare prefix-array
    prefix(prefixTable, pattern); // initialize prefix-array

    // printing the prefix-array. Optional, but helps when it comes to testing
    cout << "Longest Prefix Suffix Array: ";
    for (int i = 0; i < patternLen; i++) {
        cout << prefixTable[i] << " ";
    }
    cout << endl;

    // initializing i to represent index to text, j to represent index to pattern
    int i = 0;
    int j = 0;

    while ((txtLen - i) >= (patternLen - j)) { // loop through all text, to find occurrances of pattern
        if (pattern[j] == txt[i]) { // compare the indexes, and increment if equal
            i++;
            j++;
        }

        if (j == patternLen) { // if j at end of pattern, we have found a substring in the text
            cout << "Pattern found between index: " << i - j << " and " << i - 1 << endl;
            j = prefixTable[j - 1]; // We update j, using the prefix-array that was created, to avoid unnecessary comparisons in the text.
        }

        if (pattern[j] != txt[i]) { // if the indexes are the same, the text index increments by one if j is at the start of pattern.
            if (j == 0)
                i++;
            else
                j = prefixTable[j - 1]; // If j not at start, we resort the prefix-array to get the j to the correct index.
        }
    }
}

int main() {
    string txt;
    string patt;

    cout << "Input text: " << endl; // User input to get a text
    getline(cin, txt);

    cout << "Input pattern: " << endl; // User input to get a pattern
    getline(cin, patt);

    cout << "Text is: " << txt << endl; // Implemented for user friendliness :)
    cout << "Pattern is: " << patt << endl;

    KMP(txt, patt); // Start the search algorithm
    return 0;
}