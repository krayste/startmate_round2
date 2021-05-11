Hi! My name is Steve and this is my implementation for a linked list that 
supports:
- addFirst
- addLast
- removeFirst
- removeLast
- getFirst
- getLast
- showList
I've implemented a doubly-linked list for future expandabiility, and a 
linked list struct containing a tail node for O(1) retrievals of both the 
first and last elements. I've also written some basic tests, however for 
stricter testing in future I would use a testing framework like CMocka.

To run the tests, please type in the terminal:
make            (to compile) 
./tests         (to run the tests!)