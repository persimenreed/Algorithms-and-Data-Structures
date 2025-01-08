The Josephus Problem:
The Josephus Problem is a theoretical problem where the end-goal is to find the last element of a circular list,
with the condition is that you remove every Kth element while looping through the list until there is only one element left.
The number of elements in the list may vary, and so may K, which means that the last element remaining depends on the input.

Analyzis:
When it comes to the time complexity of the eliminateKthPerson() we devide the time complexity in to elements: How many elements in the list (n),
and how many jumps for each elimination (k).
For the number of elements, the time complexity is defined by O(n), where the time increases linearly based on the number of elements in the circular list.
For k, the number of jumps for each elimination, the time complexity is O(n*k), which will also comply as a linearly time complexity.
As a conclusion, the time complexity of the function eliminateKthPerson() is linear, and therefor defined as O(n).

Comparison of the time complexity of the Circular Linked list to alternative approaches:
The time complexity of Circular Linked list was similar to alternative approaches, where the result in the cases we studied
all had linear time complexity (O(n)). The advantages by using Circular Linked List is that the different nodes can be stored at different address spaces,
which makes it easier for large lists. Disadvantage by using Circular Linked List is that every element is larger than in alternative approaches, since the
address of the next (or previous) node has to be saved as well.
