# push_swap
Sort data using two stacks and a limited set of instructions

## Compile and execute
Compile with `make` and execute with `./push_swap *list_of_integers*`

## Algorithm
The algorithm is an adaptation of Radix Sort.  
Base idea is pretty simple (posive numbers only):  
```
for each bit (from lsb to msb):
	for each element of stack a:
		if bit == 0:
			do pb
		else
			do ra
	for each element of stack b:
		do pa
```
then our stack a is sorted.
