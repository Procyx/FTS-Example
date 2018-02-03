Matrices Calculator !
===================


Here is a **Matrice Calculator** project built in C99 (*With standard libraries*).
It presents itself as a dialogue between you & the program:

    Welcome in Matrices Calculator!
    	
    What do you want to do?
		- A: Adding two matrices
		- B: Subtracting two matrices
		- C: Multiplying a matrix by a number
		- D: Multiplying two matrices
		- E: Exit

As you can see, it allows you to:

 - *Add/Subtract two matrices*
 - *Multiply one matrix by a number*
 - *Multiply two matrices*

----------


How to use it?
-------------

This program works with *dialogues*. For example, if you want to add two matrices, it will ask you the first **matrix size**:

    Operation: A+B:
    How many lines for 'A' ? (From 1 to 99) 
    2
    
    How many columns for 'A' ? (From 1 to 99) 
    2

Then, it will ask you the **first matrix values**, and print it in the console:

    What values for 'A' ? (From -200 to 200)
    -> Use spaces to separate values (Ex: '23 -45 1').
    1 0 1 0
    
    'A' is a 2x2 matrix:
	| 1 0 |
	| 1 0 |
When *adding or subtracting two matrices*, the program know that the two matrices has the same size, so it will **directly** ask you for **the second matrix values** (Same when multiplying two matrices, the columns count of A will be the lines count of B).

    What values for 'B' ? (From -200 to 200)
    -> Use spaces to separate values (Ex: '23 -45 1').
    0 1 1 0
    
    'B' is a 2x2 matrix:
    	| 0 1 |
    	| 1 0 |

Finally, it will **print the result** and *go back to the main menu* (described previously):

    A+B result:
    	| 1 1 |
    	| 2 0 |


----------

What about the code?
-------------

The code of this project is in the **Matrices** folder in this repository. In this folder you will find:

 - `main.c` / `.h`: This contains *core functions*, like `main_menu(void)` and **all the mathematics functions used for matrices calculations**.
 
 - `io.c` / `.h`: This contains functions used to execute an action that need an user input (For example: `in_matrix(char)` use `in_lines_count(char)` to handle lines count of the input matrix). *These functions also call the others functions of the program to get and print the result.*
 
 - `utils.c` / `map.h`: This contains simple and useful functions like `println(char*)` for example.


----------

License
-------------

This code is under the **GNU General Public License v3.0** you can *use/edit* this code *without ask me* and *without quote me* if you want (More informations in `License` file).
