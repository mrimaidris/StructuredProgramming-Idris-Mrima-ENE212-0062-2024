 1. Normal Variable vs Pointer

     A. Normal Variable

What it stores
A normal variable stores an actual value (e.g., an integer, character, float).

int x = 10;

 `x` stores the value `10`.

How memory is accessed
 Memory is accessed directly using the variable name `x`.

How values are read

```c
printf("%d", x);   // reads value 10
```

How values are modified

x = 20;            // changes value stored in x


    B. Pointer

What it stores
A pointer stores a memory addressof another variable.
int x = 10;
int *p = &x;

`p` stores the address of `x`, not the value `10`.

How memory is accessed
 Memory is accessed indirectly through the pointer using dereferencing (`*`).

How values are read**

```c
printf("%d", *p);   // reads value at address stored in p → 10
```

  How values are modified

```c
*p = 30;            // modifies x through the pointer
```

Now `x` becomes `30`.



2. Variable Declaration & Definition vs Pointer Declaration & Definition

 A. Variable Declaration and Definition

```c
int x;
```

 Declaration: tells compiler that `x` is an integer.
 Definition: memory is allocated.

```c
x = 5;
```

 Assigns a value to the already defined variable.

OR combined:

```c
int x = 5;
```



 B. Pointer Declaration and Definition

```c
int *p;
```

 Declares a pointer named `p`
 Tells compiler: `p` will store the address of an `int`

```c
int x = 10;
p = &x;
```

 `&` (address-of operator) gets the memory address of `x`
 Pointer is now defined with a valid address



 Role of `&` Operator

 `&` means “address of”

```c
&x   // gives address of x
```


 Role of `*` Operator (Two Meanings)

i. During declaration → pointer declaration

```c
int *p;   // p is a pointer to int
```

ii. During usage → dereferencing

```c
*p = 20;  // access value at address stored in p
```


 
 
 
 3. Dereferencing a Pointer

 Meaning of Dereferencing

 Dereferencing means accessing the value stored at the memory address held by a pointer.
 Done using the `*` operator.


Example: Accessing a Value Using a Pointer

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("Value of x: %d\n", x);
    printf("Value via pointer: %d\n", *p);

    return 0;
}
```

  Explanation

 `p` → stores address of `x`
 `*p` → accesses value at that address (`10`)


 Modifying a Value Using Dereferencing

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    *p = 50;   // modify value of x through pointer

    printf("New value of x: %d\n", x);

    return 0;
}
```

What happens

  `*p = 50` changes the value stored at the address of `x`
  `x` becomes `50`



4. Scenarios Where Pointers Are Preferred Over Normal Variables

Pointers are preferred when direct memory access, efficiency, or shared data manipulation is required.

    Scenario 1: Modifying Variables Inside Functions

Normal variables cannot change the original data in another function. Pointers allow this.

 Example: swapping two numbers

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

Why pointers?

 Allows modification of original variables
 Avoids returning multiple values


     Scenario 2: Dynamic Memory Allocation

Normal variables have fixed size at compile time. Pointers allow memory to be allocated at runtime.

 Example: dynamic array

```c
int *arr;
arr = (int *)malloc(5 * sizeof(int));
```

Why pointers?

Memory size decided during program execution
Efficient memory usage


    Scenario 3: Working with Arrays and Strings

Arrays decay into pointers when passed to functions.

 Example:

```c
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
```

Why pointers?

Avoids copying large data
Faster performance




5. Limitations and Risks of Using Pointers

Despite their power, pointers introduce complexity and risks.

     A. Dangling Pointers

Pointer points to memory that has been freed.

```c
int *p = malloc(sizeof(int));
free(p);
// p is now dangling
```

Risk: Undefined behavior, crashes.

     B. Null Pointer Dereferencing

Using a pointer that does not point to valid memory.

```c
int *p = NULL;
*p = 10;   // ERROR
```

     C. Memory Leaks

Forgetting to free dynamically allocated memory.

```c
int *p = malloc(sizeof(int));
// no free(p);
```

Risk: Program consumes more memory over time.

    D. Difficult Debugging

Pointer bugs are hard to trace
Incorrect dereferencing can corrupt memory





6. Call by Value vs Call by Reference

     A. Call by Value

A copy of the variable is passed to the function
Changes do not affect the original variable

Example

```c
void change(int x) {
    x = 20;
}

int main() {
    int a = 10;
    change(a);
    printf("%d", a);   // Output: 10
}
```

How data is passed

    Value of `a` is copied into `x`

    
     B. Call by Reference (Using Pointers in C)

Address of the variable is passed
Changes affect the original variable

    Example

```c
void change(int *x) {
    *x = 20;
}

int main() {
    int a = 10;
    change(&a);
    printf("%d", a);   // Output: 20
}
```

How data is passed

Address of `a` is passed using `&`
Function accesses value via `*`



7. Practical Scenarios
     a. When Call by Value Is Preferred

i. Data should not be modified

```c
int square(int x) {
    return x * x;
}
```

ii. Small data types (int, char, float)

 Copying cost is negligible

iii. Safer and easier debugging

 Prevents accidental changes


     b. When Call by Reference Is Preferred

i. Need to modify original data

```c
void updateBalance(int *balance) {
    *balance += 100;
}
```

ii. Large data structures

```c
void process(struct Student *s);
```

 Avoids copying large structs

iii. Returning multiple values

```c
void calc(int a, int b, int *sum, int *product);
```

