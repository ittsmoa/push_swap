# push_swap

## Project Description
**push_swap** is a sorting algorithm project developed as part of the **42 curriculum**.  
The objective of this project is to sort a list of integers using two stacks (**a** and **b**) and a limited set of allowed operations, while producing the smallest possible number of instructions.

This project focuses on algorithmic thinking, optimization, and data structure manipulation under strict constraints.

---

## Project Objectives
- Understand and apply sorting algorithms under operation constraints  
- Learn how to manipulate stacks efficiently  
- Optimize the number of operations produced by the algorithm  
- Handle input validation and edge cases correctly  
- Improve problem-solving and algorithm design skills  

---

## Algorithm Overview
The implemented solution is based on **indexing** and **chunking** techniques.

### Indexing
Instead of working with the original integer values, each number is:
- Sorted in a temporary array
- Replaced by its index in the sorted order  

This transformation normalizes the data into a range from `0` to `n - 1`, which simplifies comparisons and algorithm logic.

Example:
Input: 42 -3 17
Sorted: -3 17 42
Indexed: 2 0 1


---

### Chunking Algorithm
The chunking algorithm divides the indexed stack into smaller groups (**chunks**) and processes them sequentially.

Main idea:
- Split the stack into fixed-size chunks  
- Push elements belonging to the current chunk from stack **a** to stack **b**  
- Rotate stacks to minimize operations  
- Push elements back from **b** to **a** in the correct order  

Chunking significantly reduces the total number of operations for large input sizes.

---

## Allowed Operations
The following operations are implemented:

### Swap
- `sa` : Swap the first two elements of stack **a**  
- `sb` : Swap the first two elements of stack **b**  
- `ss` : Perform `sa` and `sb` simultaneously  

### Push
- `pa` : Push the top element from stack **b** to stack **a**  
- `pb` : Push the top element from stack **a** to stack **b**  

### Rotate
- `ra` : Rotate stack **a** upwards  
- `rb` : Rotate stack **b** upwards  
- `rr` : Perform `ra` and `rb` simultaneously  

### Reverse Rotate
- `rra` : Rotate stack **a** downwards  
- `rrb` : Rotate stack **b** downwards  
- `rrr` : Perform `rra` and `rrb` simultaneously  

---

## Project Files
The project is organized into the following files:

- `push_swap.c` : Program entry point and main logic  
- `stack_utils.c` : Stack creation and utility functions  
- `swap.c` : Swap operations  
- `push.c` : Push operations  
- `rotate.c` : Rotate operations  
- `reverse_rotate.c` : Reverse rotate operations  
- `algorithm.c` : Chunking and indexing algorithm logic  
- `indexing.c` : Index assignment logic  
- `utils.c` : Input validation and helper functions  

---

## Compilation
The project is compiled using a Makefile.

Available commands:
- `make` : Compile the program  
- `make clean` : Remove object files  
- `make fclean` : Remove object files and the executable  
- `make re` : Recompile the project  

The executable file generated is:
