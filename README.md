# 19 push_swap
Sort data using two stacks and a limited set of instructions

## Compile and execute
Compile with `make` and execute with `./push_swap *list_of_integers*`

## Algorithm
The algorithm is an adaptation of radix sort.  
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

### Simple algorithm for less than 5 elements stacks
Another simpler algortihm is used for less than 5 elements stacks

### Replacing numbers by their index
Replacing numbers by their index allows to iterate on fewer bit of the integer, and to ignore negative numbers case which would otherwise increase number of instructions. It is done with a bubble sort.

### Not pushing all stack b to a
Instead of pushing all stack b to a, next numbers to be pushed to b are instead kept in stack b.
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

### Sort odd and even indexes
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

### Performance
100 elements stacks are sorted in ~850 operations.  
500 elements stacks are sorted in ~5480 operations.  
