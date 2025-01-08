Hello!

Our code works for the most cases involving addition and subtraction. However, there are some cases you need to be aware of.
1: If you just want to input one x, you need to write 1x instead of x.
2: Both equations need () in order to work.
3: The equation cannot only contain one element (ex: 2x^2), since you need either + or - to be added in the stack.
4: First element in either expression cannot be minus, as well as last element in first expression.
5: The , in the postfix output is added so we know if to numbers belong together like 23 or if its supposed to be 2 and 3.

(Most of these issues are fixed if you write both equations on the same expression without parenthesis, and just type 0 on the second expression.)

If these rules are followed, the code should work smoothly, with the time complexity of O(n).