# Task 1

You are tasked with creating a set of utility functions for a robotics firmware. To make your code reusable and efficient, you must implement a generic swap function that works for any datatype including `int`, `float`, and `char`. Implement a template function called `swapValues()` that swaps two variables of any type.

### Demonstrate swapping for:
- Two integers
- Two floating-point numbers
- Two characters

### Sample Input/Output:
```
Before swap: a = 5, b = 10
After swap: a = 10, b = 5
Before swap: x = 3.5, y = 7.8
After swap: x = 7.8, y = 3.5
Before swap: ch1 = 'A', ch2 = 'Z'
After swap: ch1 = 'Z', ch2 = 'A'
```

---

# Task 2

You are developing a simple command-line calculator app. Division by zero can cause a crash, so your app must gracefully handle this issue. Write a program that asks the user for two integers and divides them. If the denominator is `0`, throw an exception and catch it to display a meaningful error message.

### Sample Input/Output:
```
Enter numerator: 10
Enter denominator: 0
Error: Division by zero is not allowed!
Enter numerator: 20
Enter denominator: 5
Result: 4
```

---

# Task 3

You are creating a lightweight library for handling key-value storage in an embedded system where performance is critical. A flexible, reusable class for pairs is needed. Design a template class `Pair` that holds two values (of any type). Include a `display()` method to print the values neatly.

### Sample Input/Output:
```
Pair: (5, Hello)
Pair: (3.14, 42)
```

---

# Task 4

You are writing a banking backend where account holders must not withdraw more than their balance. Invalid transactions must be caught and handled properly. Create a `BankAccount` class with:
- A `balance` attribute.
- A `withdraw(amount)` method.
- If withdrawal exceeds balance, throw an `InsufficientFundsException`. Catch and handle the exception gracefully.

### Sample Input/Output:
```
Current Balance: $500
Enter withdrawal amount: $600
Error: Insufficient funds to complete withdrawal!
Current Balance: $500
Enter withdrawal amount: $300
Withdrawal successful! New Balance: $200
```

---

# Task 5

You are building a mini data-analysis tool where you frequently need to find the maximum value across arrays of different datatypes. Create a template function `findMax()` that:
- Takes an array (and its size) of any type.
- Returns the maximum element.

### Test it with:
- Array of integers
- Array of strings

### Sample Input/Output:
```
Array: [10, 20, 5, 30, 25]
Maximum: 30
Array: ["Apple", "Mango", "Banana", "Peach"]
Maximum: Peach
```

---

# Task 6

You are developing a user profile registration system for a healthcare app. You need to validate multiple fields separately and handle errors differently for each field. Use multiple catch blocks to catch each specific exception:
- Validate age (`> 0` and `< 120`)
- Validate salary (`> 0`)
- Validate height (`> 0 cm`)

### Throw specific exceptions:
- `InvalidAgeException`
- `InvalidSalaryException`
- `InvalidHeightException`

### Sample Input/Output:
```
Enter age: 150
InvalidAgeException caught: Age must be between 1 and 119
Enter salary: -5000
InvalidSalaryException caught: Salary must be positive
Enter height: 0
InvalidHeightException caught: Height must be positive
```

---

# Task 7

You are designing a customized array class for a machine learning application where performance and safety are critical. You must prevent accessing invalid indices. Create a template class `SmartArray<T>`:
- Supports dynamic array storage.
- Overloads the `operator[]` to access elements.
- Throws an `OutOfBoundsException` if the index is invalid.

### Test with arrays of `int` and `string`.

### Sample Input/Output:
```
Array size: 5
Enter elements: 1 2 3 4 5
Accessing index 2: 3
Accessing index 5:
OutOfBoundsException caught: Invalid index access attempted!
```