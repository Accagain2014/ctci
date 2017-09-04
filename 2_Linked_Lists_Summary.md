Ways to find the middle position of a linked list
----
  - Iterate the list element by element to get the numbers of all elements ;
  - Use fast(jump two elements every time) and slow pointers, when the fast pointer point to the last element, 
  the slow  pointer point to the exact middle element;
  - Use recursive way with recording the now node and the length, move to node->next & length-2 each time until length 
  is less than 2

