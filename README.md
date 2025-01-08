# Algorithms-and-Data-Structures
Projects during the course IKT203, where several algorithms were implemented.

## Circular Linked List
A circular linked list was implemented to solve the Josephus Problem. The Josephus Problem is a theoretical problem where the end-goal is to find the last element of a circular list, 
with the condition is that you remove every Kth element while looping through the list until there is only one element left.
The number of elements in the list may vary, and so may K, which means that the last element remaining depends on the input.

## KMP algorithm
The Knuth-Morris-Pratt (KMP) algorithm is used to search for patterns(substrings) within a text.    |
![KMP](https://github.com/user-attachments/assets/7f1ae35e-e059-46d2-87cd-88197101ee95)

## Infix to postfix 
This project was to solve polynomial equations by converting them from infix notation to postfix notation, before evaluating the result.    
![infix-to-outfix](https://github.com/user-attachments/assets/08135e43-6a72-4039-b92d-60ba5a88703b)

## Interpolation search
Interpolation Search is a searching algorithm used to find an element's position in a sorted array of values. Interpolation Search estimates the likely position of the target element based on its value. It works by calculating a probe position within the array, typically using a linear interpolation formula. This implementation will work on both integers, floats and strings.
![interpolation](https://github.com/user-attachments/assets/9b1d4154-4bba-48a8-9e9f-f22ff07e14fc)

## Heap data structure
This program is a task scheduling system using a priority queue based on a heap data structure.

## Floyd-Warshall algorithm
This program computes the shortest paths between all pairs of routers in a network after entering the adjacency matrix.
![Floyd-warshall](https://github.com/user-attachments/assets/841e4d38-d1b9-4860-8abe-574a3ccaa83e)
![floyd-2](https://github.com/user-attachments/assets/8be29bce-0729-4a54-8f20-46fe27c72311)    
The screenshot show output for a given adjacency matrix. The top part of the output simulates the input. The second part of the output show the shortest paths after the matrix has gone through the Floyd-Warshall algorithm, where new paths has been found. The last part of the output show the routing table for each of the routers, which in this screenshot, only the routing tables for the first 4 routers in the network is shown, because the remaining routers are not accessable, similar to the result for Routing Table 4.
