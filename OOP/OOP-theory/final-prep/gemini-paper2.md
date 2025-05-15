# National University of Emerging Technologies, Metropolis Campus
## Spring – 2024, School of Innovative Computing
### Final Examination



---

## Question 1: Multiple Choice Questions (Total 15 Marks: 5 questions x Marks each)

1. Which of the following best describes the primary purpose of a constructor in object-oriented programming?
    1.  To destroy an object when it is no longer needed.
	2.  ==To initialize an object's state when it is created.==
    3.  To provide a way to copy an object.
    4.  To define the public interface of a class.

2. In the context of `inheritance`, if Class B inherits from Class A, and Class C inherits from Class B, which class's members are directly accessible to Class C (assuming appropriate access specifiers)?
    1.  Only Class C's own members.
    2.  Class C's and Class B's members.
    3.  ==Class C's, Class B's, and Class A's members.==
    4.  Only Class A's members.

```
A -> B -> C
```

3. What is the term for the ability of an object to take on many forms, often implemented using virtual functions and inheritance?
    1.  Encapsulation
    2.  Abstraction
    3.  ==Polymorphism==
    4.  Aggregation

4. Which statement is TRUE regarding abstract classes?
    1.  An abstract class cannot have any concrete methods.
    2.  You can create direct instances (objects) of an abstract class.
    3.  ==An abstract class must contain at least one pure virtual function (or its equivalent).==
    4.  Abstract classes cannot be used as base classes.

5. What is the primary benefit of using exception handling in a program?
    1.  To make the program run faster.
    2.  To reduce the amount of code needed.
    3.  ==To allow the program to gracefully handle runtime errors without crashing.==
    4.  To ensure that all functions return a value.

---

## Question 2: OOP Concepts (Total 20 Marks)

1.  Define `Encapsulation` and explain its importance in object-oriented design. Provide a simple real-world analogy. (6 Marks)

- encapsulation refers to the act of hiding some methods away from the user, 
- mostly done in the form of classes, where some methods and data members are only accessible via the class object
- importance: 
	- data hiding
	- prevents unintended modifications
- analogy
	- car's engine, internal workings are hidden
	- but methods of interacting (accelerator) are exposed


2.  Differentiate between `Method Overloading` and `Method Overriding`. Provide a concise C++ or Java code snippet to illustrate each. (8 Marks)

- overloading:
	- multiple methods of same name in same class, with different arguments

```C++
class A{
	void print();
	void print(int x);
};
```

- overriding
	- method in base class being redefined in derived class in behavior
	- method prototype must rename same

```cpp
class A{
	void print (int x){
	// print
	}
};

class B:A{
	void print (int x) override {
	// print
	}
};

```


3.  What is a `static` member (variable or method) in a class? How does its lifecycle and accessibility differ from non-static members? (6 Marks)

- a data member that belongs to the class rather than to an object
- lifecycle: exists for the entire duration of the program, 
	- initialized when class is loaded
- Accessibility: can be called directly using class name
```cpp
class A{
static int member;
};

A::member = 0;

```



---

## Question 3: Inheritance and Polymorphism (Total 20 Marks)

1.  Explain the `diamond problem` in multiple inheritance. How can it be resolved in languages like C++? (5 Marks)

- [[the diamond problem]]  occurs when class inherits from two such classes that both inherit from a common class
```
	A
   / \
  B   C
   \ /
    D
```

- this leads to duplication, in class D, as compiler is confused which path of inheritance should be applied to class `D`

- to resolve this, the two intermediate classes `B` and `C` are declared virtual classes
- [[virtual inheritance]]

```cpp
class A{};

class B: virtual public A{};
class C: virtual public A{};

class D: public B,public C{};

```


2.  Consider a base class `Shape` with a virtual function `calculateArea()`. Design and implement (in C++ or Java) two derived classes: `Circle` (attributes: `radius`) and `Rectangle` (attributes: `length`, `width`).
	- Implement the `calculateArea()` method appropriately in each derived class.
	-  Write a small main program or function that demonstrates polymorphism by creating an array or list of `Shape` pointers/references, adding instances of `Circle` and `Rectangle` to it, and then iterating through the collection to call `calculateArea()` for each shape. (15 Marks)
- 

``` cpp
class Shape{

public:
	virtual float calculateArea() = 0;

};

class Circle : public Shape{
private:
	float radius;
public:
	virtual float calculateArea(){}

};

class Rectangle : public Shape{
private:
	float length, width;
public:
	virtual float calculateArea(){}

};

int main(){

	Shape s[10];
	for (int i = 0; i<5;i++){
		s[i]= new Circle(6);
		s[i+1]= new Rectangle(4,6);
	}

	for (int i = 0; i<10;i++){
		cout << s[i]->calculateArea() << endl;
	}
	

	return 0;
}


```


---

## Question 4: Exception Handling and File I/O (Total 15 Marks)

1.  What is the purpose of the `try-catch-finally` block structure in exception handling (or its equivalent in C++)? Explain the role of each block. (5 Marks)

- the try block encapsulates  error causing code, that might throw exception
- catch block handles the exception thrown by the try block



2.  Write a C++ or Java program segment that attempts to open a file named `config.txt` for reading.
    * If the file does not exist, it should catch the appropriate exception and print a user-friendly message like `Configuration file not found. Using default settings.`
    * If the file exists and is opened successfully, it should print `Configuration file loaded successfully.`
    * Ensure that any resources (like file streams) are properly closed, whether an exception occurs or not. (10 Marks)

-

```cpp

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    // ofstream is for output/read
    ofstream file;
    try{
        file.open("config.txt");
        if (!file)
            throw runtime_error("Configuration file not found");
    cout << "File loaded successfully" << endl;
    } catch (runtime_error& e){
        cout << "eror" <<endl;
    }
    file.close();
    return 0;
}

```



---

## Question 5: Class Design and Templates/Generics (Total 15 Marks)

A.  What are templates (in C++) or generics (in Java/C#)? Why are they useful in programming? (5 Marks)

- allows you to define classes and function, that can work with different data types
- usefulness: code reusability, reduced duplication

B.  Design a generic class `Pair<T1, T2>` that can store two objects of potentially different types.
- The class should have a constructor to initialize the pair of objects.
- It should have methods `getFirst()` and `getSecond()` to retrieve the objects.
- Provide a short example of how to use this `Pair` class with, for instance, an Integer and a String. (10 Marks)

```c++

#include <iostream>

using namespace std;

template <class T1, class T2>
class Pair{
    T1 t1;
    T2 t2;

    Pair(T1 f, T2 s) : t1(f), t2(s){}

    T1 getFirst const(){return t1;}
    T2 getSecond const(){return t2;}
}

int main(){
    string s = "HelloWorld";
    float f = 2f;
    Pair p(s,f);
    cout << p.getFirst() <<endl;
    cout << p.getSecond() <<endl;
    // or
    Pair<string,float> p("helo",0.2f);
    float f = p.getSecond();
    string s = p.getFirst(); 
}

```


---

## Question 6: Advanced OOP Scenario (Total 15 Marks)

You are tasked with designing a system for a simple digital library. The library can have different types of media: `Book` and `Magazine`. All media items have a `title` (string) and a `yearOfPublication` (int). `Book` items also have an `author` (string) and `isbn` (string). `Magazine` items also have an `issueNumber` (int) and `editor` (string).
All media items should have a method `displayDetails()` that prints all relevant information about the item.

1.  Design the class hierarchy using inheritance. Identify a suitable base class (e.g., `MediaItem`) and the derived classes. Clearly show the attributes and methods for each class. (7 Marks)
2.  Implement the `displayDetails()` method in each class to demonstrate polymorphism. The base class version might be virtual or abstract. (5 Marks)
3.  Briefly explain how you would manage a collection of different media items (e.g., in a list or array) and call `displayDetails()` for each item in that collection. (3 Marks)


``` cpp

#include <iostream>

using namespace std;



class Media
{
public:
    string title;
    int yearOfPublication;
    virtual void displayDetails(){
        cout << title << endl;
        cout << yearOfPublication << endl;
    }
};


class Book : public Media
{
public:
    string author, ISBN;
    void displayDetails() override {
        Media::displayDetails();
        std::cout << author << std::endl;
        std::cout << ISBN << std::endl;
    }

};


class Magazine : public Media
{
public:
    string editor;
    int issueNumber;
    void displayDetails() override {
        Media::displayDetails();
        std::cout << editor << std::endl;
        std::cout << issueNumber << std::endl;
    }
};



int main(){

    


    return 0;
}


```


----

# answers

## Question 1: Multiple Choice Questions

  * b. To initialize an object's state when it is created.
  * c. Class C's, Class B's, and Class A's members.
  * c. Polymorphism
  * c. An abstract class must contain at least one pure virtual function (or its equivalent).
  * c. To allow the program to gracefully handle runtime errors without crashing.

## Question 2: OOP Concepts

  * **A. Encapsulation:**
      * Bundling data (attributes) and methods that operate on the data within a single unit (class).
      * Importance: Data hiding, controlled access, modularity, prevents unintended modifications.
      * Analogy: A car's engine – internal workings are hidden, you interact through defined interfaces (accelerator, steering).
  * **B. Method Overloading vs. Overriding:**
      * **Overloading:** Multiple methods in the same class with the same name but different parameters (number, types, order). Compiler chooses the correct one based on arguments.
        ```cpp
        // C++ Overloading
        void print(int x);
        void print(double x);
        ```
        ```java
        // Java Overloading
        void print(int x) {}
        void print(double x) {}
        ```
      * **Overriding:** Subclass provides a specific implementation for a method already defined in its superclass. Same name and parameters. Used for runtime polymorphism.
        ```cpp
        // C++ Overriding
        class Base { virtual void display() {} };
        class Derived : public Base { void display() override {} };
        ```
        ```java
        // Java Overriding
        class Base { void display() {} }
        class Derived extends Base { @Override void display() {} }
        ```
  * **C. Static Members:**
      * Belong to the class itself, not individual objects. Only one copy exists, shared by all instances.
      * **Lifecycle:** Exist for the entire duration of the program. Initialized when the class is loaded.
      * **Accessibility:** Can be accessed directly using the class name (e.g., `ClassName::staticVar` or `ClassName.staticMethod()`) or through an object of the class. Non-static members require an object instance.

## Question 3: Inheritance and Polymorphism

  * **A. Diamond Problem:**
      * Occurs in multiple inheritance when a class inherits from two classes that have a common ancestor. If the common ancestor has a method that is not overridden in the intermediate classes, it becomes ambiguous which version the inheriting class should use.
      * **Resolution in C++:** Virtual inheritance. Declaring the inheritance from the common ancestor as `virtual` ensures that only one shared base class subobject is created, resolving the ambiguity.
  * **B. Shape Hierarchy and Polymorphism:**
      * **Base Class (Shape):**
        ```cpp
        // C++
        class Shape {
        public:
            virtual double calculateArea() = 0; // Pure virtual function
        };
        ```
        ```java
        // Java
        abstract class Shape {
            abstract double calculateArea();
        }
        ```
      * **Derived Class (Circle):**
        ```cpp
        // C++
        class Circle : public Shape {
        private:
            double radius;
        public:
            Circle(double r) : radius(r) {}
            double calculateArea() override { return 3.14159 * radius * radius; }
        };
        ```
        ```java
        // Java
        class Circle extends Shape {
            private double radius;
            public Circle(double radius) { this.radius = radius; }
            @Override
            double calculateArea() { return Math.PI * radius * radius; }
        }
        ```
      * **Derived Class (Rectangle):**
        ```cpp
        // C++
        class Rectangle : public Shape {
        private:
            double length;
            double width;
        public:
            Rectangle(double l, double w) : length(l), width(w) {}
            double calculateArea() override { return length * width; }
        };
        ```
        ```java
        // Java
        class Rectangle extends Shape {
            private double length;
            private double width;
            public Rectangle(double length, double width) { this.length = length; this.width = width; }
            @Override
            double calculateArea() { return length * width; }
        }
        ```
      * **Polymorphism Demonstration:**
        ```cpp
        // C++
        #include <iostream>
        #include <vector>
        int main() {
            std::vector<Shape*> shapes;
            shapes.push_back(new Circle(5.0));
            shapes.push_back(new Rectangle(4.0, 6.0));
            for (Shape* s : shapes) {
                std::cout << "Area: " << s->calculateArea() << std::endl;
            }
            // Remember to deallocate memory in a real application
            return 0;
        }
        ```
        ```java
        // Java
        import java.util.ArrayList;
        import java.util.List;
        public class Main {
            public static void main(String[] args) {
                List<Shape> shapes = new ArrayList<>();
                shapes.add(new Circle(5.0));
                shapes.add(new Rectangle(4.0, 6.0));
                for (Shape s : shapes) {
                    System.out.println("Area: " + s.calculateArea());
                }
            }
        }
        ```

## Question 4: Exception Handling and File I/O

  * **A. try-catch-finally Block:**
      * **`try` block:** Encloses the code that might throw an exception.
      * **`catch` block:** Handles a specific type of exception that occurred in the `try` block. Multiple `catch` blocks can handle different exception types.
      * **`finally` block:** Contains code that is always executed, regardless of whether an exception was thrown or caught. Used for cleanup operations (e.g., closing files).
  * **B. File I/O with Exception Handling:**
    ```cpp
    // C++
    #include <iostream>
    #include <fstream>
    int main() {
        std::ifstream configFile("config.txt");
        try {
            if (!configFile.is_open()) {
                throw std::runtime_error("Could not open file");
            }
            std::cout << "Configuration file loaded successfully." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Configuration file not found. Using default settings." << std::endl;
        }
        configFile.close(); // Ensure file is closed
        return 0;
    }
    ```
    ```java
    // Java
    import java.io.File;
    import java.io.FileReader;
    import java.io.IOException;
    public class FileHandler {
        public static void main(String[] args) {
            FileReader fileReader = null;
            try {
                File configFile = new File("config.txt");
                fileReader = new FileReader(configFile);
                System.out.println("Configuration file loaded successfully.");
            } catch (IOException e) {
                System.out.println("Configuration file not found. Using default settings.");
            } finally {
                if (fileReader != null) {
                    try {
                        fileReader.close();
                    } catch (IOException e) {
                        e.printStackTrace(); // Handle potential close exception
                    }
                }
            }
        }
    }
    ```

## Question 5: Class Design and Templates/Generics

  * **A. Templates/Generics:**
      * Allow you to define classes and functions that can work with different data types without specifying the type at the time of definition. Type is specified when the class or function is instantiated or called.
      * **Usefulness:** Code reusability, type safety (at compile time for generics), reduced code duplication.
  * **B. Generic `Pair` Class:**
    ```cpp
    // C++
    template <typename T1, typename T2>
    class Pair {
    private:
        T1 first;
        T2 second;
    public:
        Pair(T1 f, T2 s) : first(f), second(s) {}
        T1 getFirst() const { return first; }
        T2 getSecond() const { return second; }
    };
    // Example Usage
    Pair<int, std::string> myPair(10, "hello");
    int num = myPair.getFirst();
    std::string str = myPair.getSecond();
    ```
    ```java
    // Java
    public class Pair<T1, T2> {
        private T1 first;
        private T2 second;
        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
        public T1 getFirst() { return first; }
        public T2 getSecond() { return second; }
        public static void main(String[] args) {
            Pair<Integer, String> myPair = new Pair<>(10, "hello");
            Integer num = myPair.getFirst();
            String str = myPair.getSecond();
        }
    }
    ```

## Question 6: Advanced OOP Scenario

  * **A. Class Hierarchy:**
      * **Base Class: `MediaItem`**
          * Attributes: `title` (string), `yearOfPublication` (int)
          * Methods: `displayDetails()` (virtual or abstract)
      * **Derived Class: `Book` (inherits from `MediaItem`)**
          * Additional Attributes: `author` (string), `isbn` (string)
          * Overrides: `displayDetails()`
      * **Derived Class: `Magazine` (inherits from `MediaItem`)**
          * Additional Attributes: `issueNumber` (int), `editor` (string)
          * Overrides: `displayDetails()`
  * **B. `displayDetails()` Implementation:**

    ```cpp
    // C++ (Illustrative)
    class MediaItem {
    public:
        std::string title;
        int yearOfPublication;
        virtual void displayDetails() {
            std::cout << "Title: " << title << ", Year: " << yearOfPublication;
        }
    };
    class Book : public MediaItem {
    public:
        std::string author;
        std::string isbn;
        void displayDetails() override {
            MediaItem::displayDetails();
            std::cout << ", Author: " << author << ", ISBN: " << isbn << std::endl;
        }
    };
    class Magazine : public MediaItem {
    public:
        int issueNumber;
        std::string editor;
        void displayDetails() override {
            MediaItem::displayDetails();
            std::cout << ", Issue: " << issueNumber << ", Editor: " << editor << std::endl;
        }
    };
    ```
    ```java
    // Java (Illustrative)
    class MediaItem {
        String title;
        int yearOfPublication;
        public void displayDetails() {
            System.out.print("Title: " + title + ", Year: " + yearOfPublication);
        }
    }
    class Book extends MediaItem {
        String author;
        String isbn;
        @Override
        public void displayDetails() {
            super.displayDetails();
            System.out.println(", Author: " + author + ", ISBN: " + isbn);
        }
    }
    class Magazine extends MediaItem {
        int issueNumber;
        String editor;
        @Override
        public void displayDetails() {
            super.displayDetails();
            System.out.println(", Issue: " + issueNumber + ", Editor: " + editor);
        }
    }
    ```

  * **C. Managing a Collection and Calling `displayDetails()`:**
      * Create a collection (e.g., a list or array) that can hold pointers or references to the base class (`MediaItem*` in C++, `List<MediaItem>` in Java).
      * Add instances of `Book` and `Magazine` to this collection. Due to polymorphism, when you iterate through the collection and call the `displayDetails()` method on each element, the correct overridden version in the derived class will be executed.

Let me know if you'd like a bit more detail on any of these points\!
