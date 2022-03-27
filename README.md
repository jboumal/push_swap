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
our stack a is then sorted.

## Optimisation
The idea of the project is to optimize sorting algorithm to be able to sort the stack with as few instruction as possible.

### Replacing numbers by their index
Replacing numbers by their index allows to iterate on fewer bit of the integer, and to ignore negative numbers case which would increase number of instructions. It is done with a bubble sort.

### Not pushing all stack b to a
Instead of pushing all stack b to a, next numbers to ne pushed to b are instead kept in stack b.
```
for each bit (from lsb to msb):
	for each element of stack a:
		if bit == 0:
			do pb
		else
			do ra
	for each element of stack b:
		if next_bit == 0:
			do rb
		else
			do pa
```

### Sort odd and even indexex
To become more effective, algorithm is started at second lsb. Then, at the end of the program, stacks are equalized and another algorithm sorts odd and even numbers.

```
for each element of stack a / 2
	if reverted_odd_and_even in a and b
		do ss
	elseif reverted_odd_and_even in a
		do sa
	elseif reverted_odd_and_even in b
		do sb
	rr
	rr
```
