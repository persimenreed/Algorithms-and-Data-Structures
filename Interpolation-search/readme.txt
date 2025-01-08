Hello!

This is our project for the interpolation search. We chose to crate three different functions. However,
the functionality is almost the same in all of them. We did this for simplicity reasons, and it would not change the time complexity overall.
Feel free to edit the arrays as you want. Note that the array must be sorted in order to work. We could easily implement a check to see if the array is sorted,
but it would inpact the time complexity, and we did therefore not implement it, since interpolation search is designed to work with sorted lists.

For the string implementations we used the ascii value for each character to determine the string-value. This had to be done in order to make the formula work.
The time-complexity for the string-search would be worse than the rest of the code, since we had to find the value for each character in the strings that were compared.

A few flaws with the code found by testing:
 - Arrays of size 1 will not work. (Implemented error handling)
 - String input of a single or double character will not work. So string key has to be three characters long or more. (Implemented error handling)
 - Ascii duplicates in array will not work perfectly. If ABC is in list, and user input is BAC, input is rightfully not found in list,
 however, if 'ABC' and 'BAC' is in list, you will not find 'BAC', since it will compare to 'ABC', which is not equal to 'BAC'. This is showcased in the testcases.
