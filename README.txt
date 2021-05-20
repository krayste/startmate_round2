Hi! My name is Steve and this is my implementation for a linked list that 
supports:
- reverse       (in O(n) time)
- add_first     (returns the added node)
- add_last      (returns the added node)
- remove_first
- remove_last
- get_first
- get_last
- show_list
In keeping with the Linux Kernel/GNU Coding standards, I've changed the 
function names to be lower_snake_case().

I've implemented a singly-linked list as required, and a linked list struct 
containing a tail node for O(1) retrievals of both the first and last elements. 
I've also written some basic tests, however for stricter testing in future I 
would use a testing framework like CMocka.

To run the tests, please type in the terminal:
make            (to compile) 
./tests         (to run the tests!)