# Lab 8 - Object-Oriented Programming Assignments

## 1. Distance Calculation
Create two C++ classes, `Speed` (in km/h) and `Time` (in hours), to calculate distance using the formula:  
**Distance = Speed × Time**.  

### Goal:
Write a `calculateDistance()` function to compute the distance using private members of both classes. Instantiate objects in `main()` and display the result.

---

## 2. Cricket Strike Rate Calculation
Create two C++ classes, `Runs` and `BallsFaced`, to calculate a batsman's strike rate using the formula:  
**Strike Rate = (Runs / Balls Faced) × 100**.  

### Goal:
Write a `calculateStrikeRate()` function to compute the strike rate using private members of both classes. Instantiate objects in `main()` and display the result.

---

## 3. Complex Number Operations
Create a `ComplexNumber` class to perform the following operations using operator overloading:
1. **Addition (+)**: Add two complex numbers.
2. **Subtraction (-)**: Subtract two complex numbers.
3. **Multiplication (*)**: Multiply two complex numbers.
4. **Equality Check (==)**: Check if two complex numbers are equal.

### Goal:
Implement the above operations and test them in `main()`.

---

## 4. Traffic System Simulation
Create a `TrafficSystem` class to simulate traffic scenarios using operator overloading:
1. **Addition (+)**: Add cars to a road.
2. **Subtraction (-)**: Remove cars from a road.
3. **Multiplication (*)**: Double the delay time.
4. **Equality (==)**: Check if two roads have the same number of cars.

### Goal:
Implement the above operations and test them in `main()`.

---

## 5. Student and Teacher Interaction
Create a `Student` class to store a student's name and grades. Use a `Teacher` class as a friend to modify grades. Add a `calculateAverageGrade()` function to compute the average grade.

### Goal:
Simulate grade updates in `main()`:
1. Display the student's grades.
2. Update a grade using the `Teacher` class.
3. Recalculate and display the average grade.