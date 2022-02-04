# C PROGRAMMING

###### tags: `C PROGRAMMING`
## :pushpin: **Contents**
- [x] :mag:What is C Programming Language ?
- [x] :european_castle:History of C Language
- [x] :key:Key Applications
- [x] :wrench:How C Programming Language Works?
- [x] :memo:Syntax
- [x] :deciduous_tree:Operators
- [x] :floppy_disk:Memory management
- [x] :golf: References


:rocket: 

---
## :mag: What is C Programming Language ?

According to [Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language)), C is a general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system. By design, C provides constructs that map efficiently to typical machine instructions. It is a structured programming language that is machine-independent and extensively used to write various applications, Operating Systems like Windows, and many other complex programs like Oracle database, Git, Python interpreter, and more.

---
## :european_castle:  History of C Language 

C is an imperative language designed to compile relatively straightforwardly, which provides low-level memory access. With the gradual increase in the program's popularity, the vocabulary and its compiler have become available on various platforms, from embedded microcontrollers to supercomputers.

Several features have been included in the C language with the introduction of the K&R C language (a new edition of C published in 1978 by Brian Kernighan and Denis Ritchie).

* C is a general-purpose, high-level language that was originally developed by Dennis M.Ritchie and Ken Thompson to develop the UNIX operating system at AT&T Bell Labs.
* C was originally first implemented on the DEC PDP-11 computer in 1972 and was developed in assembly language.
* The language was named “C” because its features were derived from “B”, which according to Ken Thompson was a stripped-down version of the type less BCPL programming language.
* In 1977, Oracle database development started, and in 1983 its code was rewritten from assembly to C. It became one in all the foremost widespread databases within the world.
* In 1989 the American National Standards Institute (ANSI) committe published a standard for C (generally called “ANSI C”)

**Timeline of language development**

| Yead | C Standard | 
| -------- | -------- | 
| 1972     | Birth     | 
| 1977     | Oracle database     | 
| 1978     | K&R C     | 
| 1989/1990     | ANSI C and ISO C     | 
| 1999     | [C99](https://en.wikipedia.org/wiki/C99)     | 
| 2011     | [C11](https://en.wikipedia.org/wiki/C11_(C_standard_revision))     | 
| 2017     | [Text](https://en.wikipedia.org/wiki/C17_(C_standard_revision))     | 
| To be announced     | [C2x](https://en.wikipedia.org/wiki/C2x)     | 



> :bulb: The "hello, world" example, which appeared in the first edition of K&R, has become the model for an introductory program in most programming textbooks.



| ![](https://i.imgur.com/yZ0YEkT.jpg) |   ![](https://i.imgur.com/a925In9.png)|
| ------------------------------------ | --- |
|            "Hello, World!" program by [Brian Kernighan](https://en.wikipedia.org/wiki/Brian_Kernighan) (1978)                          |   (Compiler) Original Version |


 
---

## :key: Key Applications 

1. As a middle-level language, C combines the features of both high-level and low-level languages. C  can be used for low-level programming, such as scripting for drivers and kernels. It also supports functions of high-level programming languages, such as scripting for software applications, etc.
2. It is used for developing browsers and their extensions. Google’s Chromium is built using ‘C’ programming language.
3. ‘C’ language is widely used in embedded systems.
4. C language has a rich library which provides a number of built-in functions. It also offers dynamic memory allocation.
5. C is a general-purpose programming language and can efficiently work on enterprise applications, games, graphics, and applications requiring calculations, etc.
6. C is highly portable and is used for scripting system applications which form a major part of Windows, UNIX, and Linux operating system.





---

## :wrench: How C Programming Language Works?

C is a compiled programming language. This means that we need to convert our source files (human-readable text files) into object files (which can be understood by the machine: microcontroller, computer/laptop).


![](https://i.imgur.com/NGh0OEJ.png)


Developing software using the C programming language involves several tasks/phases. To successfully create an application/program, we need to have an editor, a compiler, a linker, and a loader. Most of the IDE (e.g., Code Blocks, Eclipse, Geany, etc.) for C programming provide all these necessary tools.

The process of developing an application in C is described in the picture below:

![](https://i.imgur.com/CqRshCw.png)



* **Editing**: Editing or writing source code containing all the instructions that need to be executed by the machine in a text format (understandable by humans) is the first step of developing an application by a plain text editor (Notepad etc.) or the editor provided by the **IDE** (Integrated development environment). The source code must be in C language syntax and saved as a .c file.
* **Compiling**: If we want to use a simple text editor for the source code, we need to install a **C compiler**. The compilation task contains the initial phase, which is known as preprocessing. A preprocessor invoked by the compiler executes the preprocessing. The preprocessor goes over the source for all the lines starting with the `#` (hash) key called compiler directives.

    One of the compiler's directives includes external functions from our source code. The **preprocessor** removes all the compiler directives from the source code but remembers what additional files need to be included later in the process. A temporary file will be created at the end of the preprocessing, which is not visible to the user.

    After the preprocessing, the compiler converts our source file into an *object* file. The object file is also named machine code. It can be interpreted by the computer's Central Processing Unit or microcontroller.
    
    The object file is ready, but some undefined references are missing. These vague references are pieces of code that must be retrieved from another place. In our case, the undefined reference is the `printf()` function. We know where to get the code for this function because the compiler directive specified it (`#include<stdio.h>`).

    `stdio.h` is a *header* file (extension `.h`) which includes the declaration of `printf()` function. We can specify where to find the definition of the `printf()` function by including the header file.
* **Linking**: Both Object files and ***Static library*** files for the external functions are needed. The *static library* files (`.lib`) contain the definition of the external functions used in our source file. In our particular case, the static library file will have the machine code of the `printf()` function.

    A ***linker*** performs the linking. It will search all the object files and replace all the undefined references with the referenced machine code within the library files. We will have an **executable file** at the end of the linking process (e.g., `.exe` for Windows applications, `.hex` for microcontrollers).

* **Loading**: A ***loader*** performs that loading the program file into the computer’s memory. Usually, the link will include the loader in the executable file. When we run the executable, it will trigger the loader, which will load the program into the memory and begin the execution.

## :memo:Syntax

### Character set
Tthe basic C reference character set includes the following:
* Lowercase and uppercase letters of ISO Basic Latin Alphabet: `a`–`z` `A`–`Z`
* Decimal digits: `0`–`9`
* Graphic characters: `! " # % & ' ( ) * + , - . / : ; < = > ? [ \ ] ^ _ { | } ~`
* [Whitespace character](https://en.wikipedia.org/wiki/Whitespace_character)

 


### Keywords
Keywords are predefined, reserved words used in programming with special meanings to the compiler. Keywords are part of the syntax, and they cannot be used as an identifier. 
```c
int rabbit;
```
Here, `int` is a keyword that indicates `rabbit` which is a variable of type integer. Here is the list of keywords allowed in ANSI C.

![](https://i.imgur.com/hZGitEl.png)




---
## :deciduous_tree: Operators 

### Arithmetic Operators

An arithmetic operator performs mathematical operations on numerical values such as addition, subtraction, multiplication, division, etc.



| Operator | Description | 
| -------- | -------- | 
| +     | addition or unary plus     |
| -     | subtraction or unary minus     | 
| *     | multiplication     |
| /     | Divides numerator by de-numerator.|
| %     | Modulus Operator and remainder of after an integer division.|

### Logical Operators
An expression containing logical operator returns either 0 or 1 depending upon whether expression results true or false. Logical operators are commonly used in decission making in C programming.

| Operator | Description | Example |
| -------- | -------- | -------- |
| &&     | Logical AND operator. If both the operands are non-zero, the condition becomes true(1).     | If c = 5 and d = 2 then, expression ((c==5) && (d>5)) equals to 0.     |
| ll     | Called OR Operator, If any of the two operands are non-zero, the condition becomes true (1).     | If c = 5 and d = 2 then, expression ((c==5) || (d>5)) equals to 1.     |
| !     | It is called Logical NOT Operator. It is used to reverse the logical state of its operand. If a condition is true (1), the Logical NOT operator will make it false (0).     | If c = 5 then, expression !(c==5) equals to 0.     |



### Assignment Operators

An assignment operator is used for assigning a value to a variable.


| Operator | Meaning | Example |
| -------- | -------- | -------- |
| =     | The most common and simple assignment operator. Assigns values from right side operands to left side operand     | x = y     |
| +=     | It adds the right operand to the left operand and assign the result to the left operand.     | x = x+y     |
| -=     | It subtracts the right operand from the left operand and assigns the result to the left operand.     | x = x-y     |
| *=   | It multiplies the right operand with the left operand and assigns the result to the left operand.     | x = x*y     |
| /=     | It divides the left operand with the right operand and assigns the result to the left operand.     | x = x/y     |
| %=     | It takes modulus using two operands and assigns the result to the left operand.     | x = x%y     |


### Relational Operators


| Operator | Description |
| -------- | -------- | 
| ==     | If the values of two operands are equal or not. If yes, then the condition becomes true.     | 
| !=     | Checking that if the values of two operands are equal or not. If the values are not equal, then the condition becomes true.     | 
| >     | Suppose the value of the left operand is greater than the value of the right operand. If yes, then the condition becomes true.    | 
| <     | Let's say the value of the left operand is less than the value of the right operand. If yes, then the condition becomes true.     | 
| >=     | If the value of the left operand is greater than or equal to the value of the right operand. If yes, then the condition becomes true.     | 
| <=    | Checks if the value of the left operand is less than or equal to the value of the right operand. If no, then the condition becomes false.     |

### Bitwise Operators

During computation, mathematical operations are converted to bit-level, making processing faster and saving power. They are used in C programming to perform bit-level operations.



| Operator | Description |
| -------- | -------- |
|    &      |    Bitwise AND      |
|    l      |     Bitwise OR     |
|    ^     |    Bitwise exclusive OR      |
|    ~     |    Bitwise complement      |
|    <<      |    Shift left      |
|     >>	     |   Shift right       |


> :bulb: Bitwise operator perform bit-by-bit operation. The truth tables for the operators.


| p   | q   | p & q | p l q | p ^ q |
| --- | --- | ----- | ----- | ----- |
| 0   | 0   | 0     | 0     | 0     |
| 0   | 1   | 0     | 1     | 1     |
| 1   | 1   | 1     | 1     | 0     |
| 1   | 0   | 0     | 1     | 1     |

### Misc Operators



| Operator | Description | Example |
| -------- | -------- | -------- |
|     sizeof()     |   Gives the size of a variable.       |        sizeof(int) = 4  |
|      &    |  (Ampersand) Returns adress of the variable. In other words, the answer of "where is the variable stored?"        |   &x; gives the actual address of the variable.       |
|     *     |   Pointer to a variable.       |    *c;      |
| ? :     | 	Conditional Expression.     | If Condition is true ? then value X : otherwise value Y     |

---

 

## :floppy_disk:Memory management
One of the essential functions of a programming language is to provide facilities for managing memory and the objects stored in memory. C provides three distinct ways to allocate memory for objects:
1. Static memory allocation
2. Dynamic memory allocation
3. Automatic memory allocation

### Static Memory Allocation

In Static Memory Allocation, the memory for your data is allocated when the program starts. The size is fixed when the program is created. It applies to global variables file scope variables and is qualified with statically defined inside functions. Each static or global variable defines one block of space of a fixed size. The area is allocated once your program starts (part of the exec operation) and is never freed. This memory allocation is set and cannot be changed, i.e., increased or decreased after allocation. Example as following for static memory allocation:

```c
    int b; 
    int c[10]; 
    char x;  
```
### Dynamic Memory Allocation

The concept of dynamic memory allocation in c language allows users to allocate memory at runtime. Dynamic memory allocation is possible by four functions already defined in stdlib.h header file.

- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

#### `malloc()`
The name "malloc" stands for *memory allocation*.

The `malloc()` function reserves a block of memory of the specified number of bytes. It gives a pointer of void which can be casted into pointers of any form.

**Syntax**

```c
pointer = (castType*) malloc(size);
```

#### `calloc()`
The `calloc()` function allocates multiple blocks of requested memory. It initializes all bytes to zero. It returns `NULL` if memory is not sufficient.

##### **Syntax**

```c
pointer = (castType*) calloc(number, byte-size)  
```

#### `realloc()`

If the dynamically allocated memory is insufficient or more than required, we can change the size of previously allocated memory using the `realloc()` function.


#####  **Syntax**

```c
pointer = realloc(pointer, newsize)  
```

#### `free()`
Dynamically allocated memory created with either `calloc()` or `malloc()` is not freed independently. You must explicitly use `free()` to release the space.

##### **Syntax**

```c
free(pointer);  
```


### Automatic Memory Allocation

Automatic allocation happens when you declare an automatic variable, such as a function argument or a local variable. An automatic variable is allocated when the compound statement containing the declaration is entered and freed when that compound statement is exited.

---

## :golf:References 


C (programming language). (2001, November 10). Wikipedia, the free encyclopedia. Retrieved February 4, 2022, from https://en.wikipedia.org/wiki/C_(programming_language)


Kernighan, Brian W.; Ritchie, Dennis M. (February 1978). The C Programming Language (1st ed.). Englewood Cliffs, NJ: Prentice Hall. ISBN 978-0-13-110163-0.

Fruderica (December 13, 2020). "History of C". The cppreference.com. Archived from the original on October 24, 2020. Retrieved October 24, 2020.


Moore. (2021, July 26). Benefits of C / C++ over other programming languages. Invensis Technologies. https://www.invensis.net/blog/benefits-of-c-c-plus-plus-over-other-programming-languages/?utm_source=invensis-blog&utm_campaign=blog-post&utm_medium=content-link&utm_term=applications-of-c-c-plus-plus-in-the-real-world


X-engineer. (2022). How C programming works. x-engineer.org. https://x-engineer.org/c-programming-works/

C if...else statement. (n.d.). Programiz: Learn to Code for Free. https://www.programiz.com/c-programming/c-if-else-statement

Tutorialspoint. (n.d.). C - Operators. Biggest Online Tutorials Library. https://www.tutorialspoint.com/cprogramming/c_operators.htm
