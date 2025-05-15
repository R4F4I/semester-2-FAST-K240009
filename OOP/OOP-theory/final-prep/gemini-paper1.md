# Object-Oriented Programming in C++: Mock Examination

**Total Marks:** 75 (15 marks per question)
**Time Allowed:** 3 Hours

**Instructions:**

  * Attempt all five questions.
  * Each question requires a theoretical discussion, problem analysis, and a C++ solution design.
  * Pay close attention to the assessment criteria outlined for each question.
  * Ensure your C++ code is well-commented and demonstrates a clear understanding of OOP principles.

-----

## Question 1: The Foundation of Reusability and Extensibility (15 Marks)







**Theory (5 Marks):**
Explain the concepts of **Inheritance** and **Polymorphism** in the context of the Object-Oriented Paradigm. Discuss how these two concepts work together to promote code reusability and software extensibility. Provide a real-world analogy to illustrate their combined effect.

**Problem Analysis (5 Marks):**
Consider a system for managing different types of vehicles in a transportation company (e.g., Cars, Trucks, Motorcycles). Each vehicle has common attributes like `model`, `year`, and `fuelType`, and common behaviors like `startEngine()` and `stopEngine()`. However, they also have specific attributes (e.g., `numberOfDoors` for a Car, `cargoCapacity` for a Truck) and behaviors (e.g., `honkHorn()` might produce different sounds, `calculateFuelEfficiency()` might have different formulas).

Identify how you would model this scenario using OOP principles, specifically focusing on how inheritance and polymorphism can be applied to manage the commonalities and variations among vehicle types.

**Solution Design (5 Marks):**
Design a C++ class hierarchy for the vehicle management system described above.

  * Create a base class `Vehicle` with common attributes and virtual functions for common behaviors.
  * Create at least two derived classes (e.g., `Car`, `Truck`) that inherit from `Vehicle`.
  * Override the virtual functions in the derived classes to demonstrate polymorphic behavior.
  * Implement specific attributes and methods for each derived class.
  * Include a small `main` function to demonstrate the creation of different vehicle objects and the polymorphic invocation of their methods.

**(Assessment Criteria for Question 1):**

  * **C-2:** Discuss knowledge of underlying concepts of object-oriented paradigm like abstraction, encapsulation, polymorphism, inheritance etc.
  * **C-4:** Identify real world problems in terms of objects rather than procedure.
  * **C-3:** Illustrate Object-Oriented design artifacts and their mapping to Object-Oriented Programming using C++.



-----

### **Solution 1**







**Theory:**

**Inheritance** is a fundamental OOP mechanism where a new class (derived or child class) acquires the properties (attributes) and behaviors (methods) of an existing class (base or parent class). This promotes code reuse as common functionalities defined in the base class do not need to be rewritten in derived classes. It establishes an "is-a" relationship (e.g., a `Car` *is a* `Vehicle`). Inheritance facilitates the creation of a hierarchy of classes, leading to a more organized and maintainable codebase.

**Polymorphism**, meaning "many forms," allows objects of different classes to be treated as objects of a common superclass. In C++, polymorphism is primarily achieved through virtual functions and late binding (dynamic dispatch). When a virtual function is called through a base class pointer or reference that points to a derived class object, the version of the function in the derived class is executed at runtime. This allows for writing generic code that can operate on objects of various types without knowing their specific type at compile time.

**How they work together for Reusability and Extensibility:**
Inheritance provides the structure for sharing common code. Derived classes inherit the base class's interface and (optionally) its implementation. Polymorphism then allows these derived classes to provide their own specific implementations for the inherited methods. This means you can write code that operates on base class pointers/references, and this code will automatically work with any new classes derived from the base class in the future, without modification. This makes the system highly extensible – new functionalities or variations can be added by simply creating new derived classes. The existing code, which relies on the base class interface, remains unchanged and reusable.

**Real-world Analogy:**
Consider a "PaymentMethod" system.

  * **Inheritance:** You can have a base class `PaymentMethod` with common properties like `amount` and a method `processPayment()`. Then, derived classes like `CreditCardPayment`, `PayPalPayment`, and `BankTransferPayment` can inherit from `PaymentMethod`. They all "are" payment methods.
  * **Polymorphism:** The `processPayment()` method would be virtual. When you process a list of different payment methods, you can call `processPayment()` on each. The system will automatically execute the correct `processPayment()` logic (e.g., contacting a credit card gateway for `CreditCardPayment`, redirecting to PayPal for `PayPalPayment`) based on the actual type of payment object, even if you are iterating through a list of `PaymentMethod*`. If a new payment method, say `CryptoPayment`, is introduced, it can inherit from `PaymentMethod` and implement its own `processPayment()`. The existing payment processing loop doesn't need to change to accommodate this new type, demonstrating extensibility and reusability.

**Problem Analysis:**

The vehicle management system can be modeled using OOP as follows:

1.  **Identify Objects:** The core objects are `Vehicle`, `Car`, `Truck`, and `Motorcycle`.
2.  **Identify Common Attributes/Behaviors (Abstraction & Encapsulation):**
      * Common attributes: `model` (string), `year` (int), `fuelType` (string).
      * Common behaviors: `startEngine()`, `stopEngine()`, `displayDetails()`, `calculateFuelEfficiency()`. These will be part of a base `Vehicle` class. The data members will be encapsulated (e.g., `protected` or `private` with accessors).
3.  **Identify Specific Attributes/Behaviors (Specialization):**
      * `Car`: `numberOfDoors` (int), potentially a specific `honkHorn()` sound.
      * `Truck`: `cargoCapacity` (double), potentially a different `calculateFuelEfficiency()` formula considering load.
      * `Motorcycle`: `hasSideCar` (bool).
4.  **Apply Inheritance ("is-a" relationship):**
      * `Car` *is a* `Vehicle`.
      * `Truck` *is a* `Vehicle`.
      * `Motorcycle` *is a* `Vehicle`.
        This structure allows `Car`, `Truck`, and `Motorcycle` to inherit common features from `Vehicle`.
5.  **Apply Polymorphism:**
      * Behaviors like `displayDetails()` and `calculateFuelEfficiency()` are likely to vary. These should be declared as `virtual` in the `Vehicle` class.
      * Derived classes will `override` these virtual functions to provide their specific implementations.
      * This allows us to treat a collection of different vehicles (e.g., in an array of `Vehicle*`) uniformly, calling `displayDetails()` on each, and the correct version for the specific vehicle type will be executed.
6.  **Data Hiding:** Access to attributes will be controlled, typically using `protected` for attributes intended for use by derived classes and `private` with public getters/setters for others, demonstrating encapsulation.

This approach ensures that common code is centralized in the `Vehicle` class (reusability), and new vehicle types can be easily added by deriving from `Vehicle` without modifying existing code that works with `Vehicle` pointers/references (extensibility).

**Solution Design (C++ Code):**

```cpp
#include <iostream>
#include <string>
#include <vector>

// Base class Vehicle
class Vehicle {
protected:
    std::string model;
    int year;
    std::string fuelType;

public:
    // Constructor
    Vehicle(const std::string& mod, int yr, const std::string& fuel)
        : model(mod), year(yr), fuelType(fuel) {}

    // Virtual destructor (important for base classes with virtual functions)
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called for " << model << std::endl;
    }

    // Common behaviors - some virtual for polymorphic behavior
    virtual void startEngine() const {
        std::cout << model << " engine started." << std::endl;
    }

    virtual void stopEngine() const {
        std::cout << model << " engine stopped." << std::endl;
    }

    // Pure virtual function - makes Vehicle an abstract class if uncommented
    // virtual double calculateFuelEfficiency() const = 0;

    // Virtual function for polymorphism
    virtual void displayDetails() const {
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Fuel Type: " << fuelType << std::endl;
    }

    // Getter for model (example of encapsulation)
    std::string getModel() const { return model; }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(const std::string& mod, int yr, const std::string& fuel, int doors)
        : Vehicle(mod, yr, fuel), numberOfDoors(doors) {}

    ~Car() override {
        std::cout << "Car destructor called for " << model << std::endl;
    }

    void startEngine() const override {
        std::cout << "Car " << model << " engine started with a vroom!" << std::endl;
    }

    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class method
        std::cout << "Number of Doors: " << numberOfDoors << std::endl;
        std::cout << "Car Specific: This is a passenger car." << std::endl;
    }

    void openSunroof() const { // Car specific method
        std::cout << model << " sunroof opened." << std::endl;
    }

    // Override if calculateFuelEfficiency was pure virtual or needs specific logic
    // double calculateFuelEfficiency() const override {
    //     // Car specific calculation
    //     return 25.5; // km/L
    // }
};

// Derived class Truck
class Truck : public Vehicle {
private:
    double cargoCapacity; // in tons

public:
    Truck(const std::string& mod, int yr, const std::string& fuel, double capacity)
        : Vehicle(mod, yr, fuel), cargoCapacity(capacity) {}

    ~Truck() override {
        std::cout << "Truck destructor called for " << model << std::endl;
    }

    void stopEngine() const override {
        std::cout << "Truck " << model << " heavy engine stopping sequence initiated." << std::endl;
    }

    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class method
        std::cout << "Cargo Capacity: " << cargoCapacity << " tons" << std::endl;
        std::cout << "Truck Specific: This is a heavy-duty truck." << std::endl;
    }

    void loadCargo(double amount) { // Truck specific method
        std::cout << amount << " tons of cargo loaded onto " << model << "." << std::endl;
    }

    // Override if calculateFuelEfficiency was pure virtual or needs specific logic
    // double calculateFuelEfficiency() const override {
    //     // Truck specific calculation, possibly considering cargo
    //     return 10.2; // km/L
    // }
};

int main() {
    // Create objects of derived classes
    Car myCar("Toyota Camry", 2023, "Petrol", 4);
    Truck myTruck("Volvo FH16", 2022, "Diesel", 25.5);

    std::cout << "\n--- Direct Object Calls ---" << std::endl;
    myCar.startEngine();
    myCar.displayDetails();
    myCar.openSunroof();
    myCar.stopEngine();

    std::cout << std::endl;
    myTruck.startEngine();
    myTruck.displayDetails();
    myTruck.loadCargo(15.0);
    myTruck.stopEngine();

    std::cout << "\n--- Polymorphic Calls using Base Class Pointers ---" << std::endl;
    // Using a vector of base class pointers to demonstrate polymorphism
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Honda Civic", 2024, "Petrol", 4));
    vehicles.push_back(new Truck("Ford F-150", 2023, "Petrol", 1.5));
    vehicles.push_back(new Car("Tesla Model S", 2023, "Electric", 4));


    for (const auto& vehiclePtr : vehicles) {
        std::cout << "\nProcessing vehicle: " << vehiclePtr->getModel() << std::endl;
        vehiclePtr->startEngine();    // Polymorphic call
        vehiclePtr->displayDetails(); // Polymorphic call
        // vehiclePtr->calculateFuelEfficiency(); // Would work if implemented
        vehiclePtr->stopEngine();     // Polymorphic call

        // To call specific methods, we'd need a downcast (with type checking)
        if (Car* carPtr = dynamic_cast<Car*>(vehiclePtr)) {
            carPtr->openSunroof();
        } else if (Truck* truckPtr = dynamic_cast<Truck*>(vehiclePtr)) {
            truckPtr->loadCargo(0.5); // Example
        }
    }

    std::cout << "\n--- Cleaning up heap-allocated objects ---" << std::endl;
    // Clean up dynamically allocated objects
    for (auto& vehiclePtr : vehicles) {
        delete vehiclePtr; // This will correctly call derived class destructors
    }
    vehicles.clear();

    return 0;
}
```

**Explanation of C++ Solution Design:**

1.  **`Vehicle` Base Class:**

      * `protected` members (`model`, `year`, `fuelType`) are accessible to derived classes. This is a form of encapsulation, allowing controlled access.
      * The constructor initializes these common attributes.
      * A `virtual ~Vehicle()` destructor is crucial. When `delete` is called on a `Vehicle*` pointing to a derived class object, the virtual destructor ensures that the derived class's destructor is called first, followed by the base class's destructor, preventing memory leaks and ensuring proper cleanup.
      * `startEngine()` and `stopEngine()` are `virtual` to allow derived classes to provide specific startup/shutdown sequences if needed. `displayDetails()` is also `virtual` to ensure the specific details of the derived class are shown.
      * The commented-out `virtual double calculateFuelEfficiency() const = 0;` shows how `Vehicle` could be made an abstract class if all vehicles *must* implement this method, forcing derived classes to provide a concrete implementation. For this solution, it's left as a regular virtual function that could be overridden.
      * `getModel()` is a public getter, demonstrating encapsulation by providing controlled access to a private/protected member.

2.  **`Car` and `Truck` Derived Classes:**

      * They use `public Vehicle` to inherit publicly from `Vehicle`.
      * Their constructors call the `Vehicle` constructor using the member initializer list to initialize the base part of the object (`Vehicle(mod, yr, fuel)`).
      * They have their own specific private members (`numberOfDoors` for `Car`, `cargoCapacity` for `Truck`).
      * They `override` the `startEngine()`, `stopEngine()` (for Truck), and `displayDetails()` methods. The `override` keyword is a good practice as it tells the compiler that the function is intended to override a base class virtual function, leading to a compile-time error if no such function exists in the base.
      * `displayDetails()` in derived classes calls `Vehicle::displayDetails()` to reuse the base class functionality for common attributes before printing their specific attributes.
      * They have their own specific methods (`openSunroof()` for `Car`, `loadCargo()` for `Truck`).
      * Their destructors (`~Car() override`, `~Truck() override`) are automatically virtual because the base class destructor is virtual. They print a message to show they are being called.

3.  **`main()` Function (Demonstration):**

      * **Direct Object Calls:** Shows creating objects directly and calling their methods. The appropriate versions (base or derived) are called based on the object's actual type.
      * **Polymorphic Calls:**
          * A `std::vector<Vehicle*>` is used to store pointers to `Vehicle` objects. This vector can hold pointers to `Car` objects, `Truck` objects, or any other future class derived from `Vehicle`.
          * New `Car` and `Truck` objects are created on the heap using `new` and their addresses are stored in the vector.
          * When iterating through the `vehicles` vector, `vehiclePtr->startEngine()`, `vehiclePtr->displayDetails()`, and `vehiclePtr->stopEngine()` are called. Because these functions are `virtual`, the C++ runtime system performs dynamic dispatch: it looks at the actual type of the object `vehiclePtr` is pointing to (e.g., `Car` or `Truck`) and calls the version of the function implemented in that specific derived class. This is polymorphism in action.
          * **Dynamic Casting:** The example briefly shows how `dynamic_cast` can be used to safely downcast a base class pointer to a derived class pointer. This allows calling derived-class-specific methods (`openSunroof`, `loadCargo`) that are not part of the `Vehicle` interface. It's important to check if the cast was successful (i.e., the pointer is not `nullptr`) before using the derived pointer.
      * **Cleanup:** The loop `for (auto& vehiclePtr : vehicles) { delete vehiclePtr; }` correctly deallocates the memory for the objects created with `new`. Because `Vehicle` has a virtual destructor, the correct sequence of destructors (derived then base) is called for each object, preventing resource leaks.

This design effectively uses inheritance to share common code and structure, and polymorphism to allow for varied behavior of specific vehicle types while treating them uniformly through a base class interface, thus promoting reusability and extensibility.

-----



## Question 2: Encapsulation, Data Integrity, and Object Initialization (15 Marks)**





**Theory (5 Marks):**
Define **Encapsulation** and **Data Abstraction** in OOP. Explain the roles of **Access Control (public, private, protected)**, **Constructors (including types like default, parameterized, copy)**, **Destructors**, and **Setters & Getters** in achieving robust encapsulation and managing the lifecycle of objects.

**Problem Analysis (5 Marks):**
Imagine you are designing a `BankAccount` class. A bank account has attributes like `accountNumber` (string, should be unique and immutable after creation), `accountHolderName` (string), `balance` (double, should not be directly modifiable from outside but through deposit/withdraw methods), and `accountType` (e.g., "Savings", "Checking"). The initial deposit amount must be non-negative. The account holder's name can be updated.

Analyze how you would apply encapsulation principles to this `BankAccount` class to ensure data integrity, controlled access, and proper initialization/cleanup. Specifically, discuss the choice of access specifiers for members, the types of constructors needed, and the role of setters/getters.

**Solution Design (5 Marks):**
Implement the `BankAccount` class in C++.

  * Use appropriate access specifiers for all data members and member functions.
  * Implement a parameterized constructor to initialize a new account with an account number, holder name, type, and initial deposit (ensure initial deposit is valid). Consider if a default constructor is meaningful.
  * Implement a copy constructor.
  * Implement a destructor to print a message when an account object is destroyed.
  * Provide public methods `deposit(double amount)`, `withdraw(double amount)`, and `displayAccountInfo()`. Ensure `withdraw` doesn't allow the balance to go below zero (or a predefined overdraft limit).
  * Implement a getter for the balance and a setter for the `accountHolderName`.
  * In `main()`, demonstrate the creation of `BankAccount` objects using different constructors, show the use of setters/getters, and illustrate deposit and withdrawal operations, including handling an invalid initial deposit or withdrawal.

**(Assessment Criteria for Question 2):**

  * **C-2:** Discuss knowledge of underlying concepts of object-oriented paradigm like abstraction, encapsulation, polymorphism, inheritance etc.
  * **C-3:** Illustrate Object-Oriented design artifacts and their mapping to Object-Oriented Programming using C++.
  * **C-4:** Identify real world problems in terms of objects rather than procedure.



-----

### Solution 2





**Theory:**

**Data Abstraction** is the concept of hiding complex implementation details and showing only the essential features of an object or system to the user. It focuses on *what* an object does rather than *how* it does it. In OOP, abstraction is typically achieved by defining a clear public interface (methods) for a class, while the internal workings are hidden.

**Encapsulation** is the mechanism of bundling the data (attributes) and the methods (functions) that operate on that data within a single unit, i.e., a class. It also involves restricting direct access to some of an object's components, which is a key aspect of data hiding. Encapsulation helps in protecting the internal state of an object from unintended external modification, thereby improving data integrity and modularity.

**Roles in Achieving Robust Encapsulation and Object Lifecycle Management:**

1.  **Access Control (public, private, protected):**

      * **`public`:** Members declared as public are accessible from anywhere outside the class, forming the class's interface.
      * **`private`:** Members declared as private are accessible only from within the class itself (by its member functions and friend functions). This is the primary mechanism for data hiding and protecting the internal state.
      * **`protected`:** Members declared as protected are accessible within the class itself and by its derived classes. This is useful in inheritance hierarchies where derived classes need direct access to certain base class members.
        Access control is fundamental to encapsulation, as it dictates what parts of an object are exposed and what parts are hidden.

2.  **Constructors:**
    Constructors are special member functions responsible for initializing an object when it is created. They ensure that an object starts in a valid and consistent state.

      * **Default Constructor:** A constructor that can be called without any arguments. It's often used to create objects with default initial values. The compiler provides an implicit default constructor if no constructors are explicitly defined by the user (unless other constructors are present, in which case one might be needed explicitly).
      * **Parameterized Constructor:** A constructor that accepts one or more arguments to initialize the object's attributes with specific values provided at the time of creation. This allows for flexible object initialization.
      * **Copy Constructor:** A constructor that creates a new object as a copy of an existing object of the same class. It takes a reference to an object of the same class as an argument (usually `const ClassName&`). A compiler-generated copy constructor performs a member-wise copy. For classes with dynamically allocated resources, a user-defined copy constructor is often necessary to perform a deep copy to avoid issues like double deletion or shared mutable state.
        Constructors are the entry point to an object's lifecycle, setting up its initial encapsulated state.

3.  **Destructor:**
    A destructor is a special member function that is automatically called when an object goes out of scope or is explicitly deleted. Its primary purpose is to release any resources (e.g., dynamically allocated memory, file handles, network connections) that the object acquired during its lifetime. A destructor has the same name as the class, preceded by a tilde (`~`), and it takes no arguments and has no return type. Proper resource deallocation in destructors is crucial for preventing resource leaks.

4.  **Setters (Mutators) & Getters (Accessors):**

      * **Getters:** Public member functions used to retrieve the values of private or protected data members. They provide read-only access to the object's state without allowing direct modification.
      * **Setters:** Public member functions used to modify the values of private or protected data members. They provide a controlled way to change an object's state, often including validation logic to ensure that the new value is valid before the modification occurs.
        Setters and getters are key to encapsulation. They allow the class to control how its data is accessed and modified, maintaining data integrity and hiding the internal representation of the data. For instance, a setter can validate input before assigning it to an attribute, or a getter might return a computed value rather than a direct attribute.

Together, these mechanisms allow a class to manage its own data, control access to it, ensure proper initialization and cleanup, and present a clean, abstract interface to the outside world, which are hallmarks of good object-oriented design.

**Problem Analysis (BankAccount Class):**

To apply encapsulation to the `BankAccount` class:

1.  **Data Members and Access Specifiers:**

      * `accountNumber` (string): Should be `private` and ideally `const` or set only once via the constructor to ensure it's immutable after creation.
      * `accountHolderName` (string): Should be `private`.
      * `balance` (double): Should be `private` to prevent direct external modification.
      * `accountType` (string): Should be `private`.

2.  **Constructors:**

      * **Parameterized Constructor:** Essential. It will take `accountNumber`, `accountHolderName`, `accountType`, and an initial `depositAmount`.
          * Inside the constructor, the `initialDepositAmount` must be validated (non-negative). If invalid, an appropriate action should be taken (e.g., set balance to 0 and print a warning, or throw an exception – for this problem, we'll set to 0 and warn).
          * The `accountNumber` should be initialized here.
      * **Default Constructor:** Its utility is questionable for a `BankAccount` as an account typically needs at least an account number and holder name to be meaningful. If provided, it should initialize members to sensible default states (e.g., empty strings, zero balance), but its use might be restricted or discouraged. For this problem, we can omit it or make it private if it's only for internal use, to emphasize that accounts should be properly initialized. Let's decide to implement it with default safe values, though its practical use might be limited.
      * **Copy Constructor:** Necessary if we want to create new `BankAccount` objects as copies of existing ones. It should perform a member-wise copy of all attributes. Since our attributes are simple types (string, double), the default compiler-generated copy constructor would suffice, but implementing it explicitly is good practice for understanding.

3.  **Destructor:**

      * A destructor `~BankAccount()` will be implemented. For this class, since there's no dynamic memory allocation managed directly by the class (STL strings manage their own memory), the destructor's main role here would be illustrative, perhaps printing a message like "BankAccount [accountNumber] closed."

4.  **Setters and Getters:**

      * **Getters:**
          * `getAccountNumber()`: Returns `const std::string&`.
          * `getAccountHolderName()`: Returns `const std::string&`.
          * `getBalance()`: Returns `double`.
          * `getAccountType()`: Returns `const std::string&`.
      * **Setters:**
          * `setAccountHolderName(const std::string& newName)`: Allows updating the account holder's name. It might include validation (e.g., name not empty).
          * No setter for `accountNumber` to enforce its immutability after creation.
          * No direct setter for `balance`; it's modified only via `deposit` and `withdraw`.
          * No setter for `accountType` if it's considered immutable after account creation, or provide one if it can be changed (with validation). For this problem, let's assume it's set at creation and doesn't change.

5.  **Public Member Functions (Interface):**

      * `deposit(double amount)`:
          * Public method.
          * Takes a `double amount` as input.
          * Validates that `amount` is positive. If not, it should reject the deposit (e.g., print an error, return false).
          * If valid, adds the `amount` to the `balance`.
      * `withdraw(double amount)`:
          * Public method.
          * Takes a `double amount` as input.
          * Validates that `amount` is positive.
          * Validates that `amount` does not exceed the current `balance` (or `balance - overdraftLimit`). If insufficient funds, reject withdrawal.
          * If valid, subtracts the `amount` from the `balance`.
      * `displayAccountInfo()`:
          * Public method.
          * Prints all relevant account details (`accountNumber`, `accountHolderName`, `accountType`, `balance`) in a formatted way.

This design ensures:

  * **Data Integrity:** `balance` can only be changed through controlled `deposit` and `withdraw` methods that include validation. `accountNumber` is immutable.
  * **Controlled Access:** Direct access to sensitive data is prevented. Modifications and reads occur through well-defined public interfaces.
  * **Proper Initialization:** Constructors ensure accounts are created in a valid state.
  * **Clean Abstraction:** The user of the `BankAccount` class interacts with it through methods like `deposit`, `withdraw`, `displayAccountInfo`, without needing to know the internal storage details.

**Solution Design (C++ Code):**

```cpp
#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument (optional for error handling)
#include <iomanip>   // For std::fixed and std::setprecision

class BankAccount {
    private:
    // Data Members - encapsulated
    const std::string accountNumber; // Immutable after creation
    std::string accountHolderName;
    double balance;
    std::string accountType;

    // Private helper for validation (optional)
    bool isValidAmount(double amount) const {
        return amount > 0;
    }

public:
    // 1. Parameterized Constructor
    BankAccount(const std::string& accNum, const std::string& holderName,
                const std::string& type, double initialDeposit)
        : accountNumber(accNum), accountHolderName(holderName), accountType(type), balance(0.0) {
            if (accNum.empty()) {
                // In a real system, might throw an exception or assign a unique ID
            std::cerr << "Error: Account number cannot be empty. Account not fully initialized." << std::endl;
            // For simplicity, we proceed, but accountNumber will be empty.
            // A better approach would be to throw std::invalid_argument("Account number cannot be empty");
        }
        if (holderName.empty()) {
            std::cerr << "Warning: Account holder name is empty for account " << accNum << "." << std::endl;
        }
        if (initialDeposit < 0) {
            std::cerr << "Warning: Initial deposit cannot be negative for account " << accountNumber
                      << ". Balance set to 0." << std::endl;
            this->balance = 0.0;
        } else {
            this->balance = initialDeposit;
        }
        std::cout << "BankAccount created for " << accountHolderName
                  << " (Acc: " << accountNumber << ") with initial balance: $"
                  << std::fixed << std::setprecision(2) << this->balance << std::endl;
    }

    // 2. Copy Constructor
    BankAccount(const BankAccount& other)
        : accountNumber(other.accountNumber + "_copy"), // Ensure unique acc num for copy, or handle differently
          accountHolderName(other.accountHolderName),
          balance(other.balance),
          accountType(other.accountType) {
              std::cout << "BankAccount (copy constructor) created for " << accountHolderName
                  << " (Acc: " << accountNumber << ") copied from " << other.accountNumber << std::endl;
        // Note: Making accountNumber const makes true copying complex if accountNumber must be identical.
        // A real system might generate a new unique ID or have specific rules for copying accounts.
        // For this example, we append "_copy" to make it distinct.
        // If accountNumber had to be identical and truly const, a copy might not be meaningful
        // or would require a different design for accountNumber uniqueness.
    }

    // 3. Destructor
    ~BankAccount() {
        std::cout << "BankAccount (Acc: " << accountNumber << ", Holder: " << accountHolderName
                  << ") is being destroyed. Final balance: $"
                  << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    // 4. Public Methods for Operations
    bool deposit(double amount) {
        if (!isValidAmount(amount)) {
            std::cerr << "Error (Acc: " << accountNumber << "): Deposit amount must be positive. Transaction failed." << std::endl;
            return false;
        }
        balance += amount;
        std::cout << "Deposit successful (Acc: " << accountNumber << "): $"
                  << std::fixed << std::setprecision(2) << amount
                  << ". New balance: $" << balance << std::endl;
        return true;
    }

    bool withdraw(double amount) {
        if (!isValidAmount(amount)) {
            std::cerr << "Error (Acc: " << accountNumber << "): Withdrawal amount must be positive. Transaction failed." << std::endl;
            return false;
        }
        if (amount > balance) {
            std::cerr << "Error (Acc: " << accountNumber << "): Insufficient funds. Withdrawal of $"
                      << std::fixed << std::setprecision(2) << amount
                      << " failed. Current balance: $" << balance << std::endl;
            return false;
        }
        balance -= amount;
        std::cout << "Withdrawal successful (Acc: " << accountNumber << "): $"
                  << std::fixed << std::setprecision(2) << amount
                  << ". New balance: $" << balance << std::endl;
        return true;
    }

    void displayAccountInfo() const {
        std::cout << "\n--- Account Information ---" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Type: " << accountType << std::endl;
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    // 5. Getters
    std::string getAccountNumber() const { return accountNumber; }
    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }
    std::string getAccountType() const { return accountType; }

    // 6. Setter for Account Holder Name
    void setAccountHolderName(const std::string& newName) {
        if (newName.empty()) {
            std::cerr << "Warning (Acc: " << accountNumber << "): Account holder name cannot be set to empty. Name not changed." << std::endl;
            return;
        }
        std::cout << "Account holder name for " << accountNumber << " changed from "
                  << accountHolderName << " to " << newName << "." << std::endl;
        this->accountHolderName = newName;
    }
};

// Optional: Default constructor (if deemed necessary)
// BankAccount::BankAccount() : accountNumber("UNDEFINED"), accountHolderName("N/A"), balance(0.0), accountType("Unknown") {
//     std::cout << "Default BankAccount created." << std::endl;
// }


int main() {
    std::cout << std::fixed << std::setprecision(2); // Set precision for currency output

    std::cout << "\n--- Creating Account 1 (Valid Initial Deposit) ---" << std::endl;
    BankAccount acc1("ACC001", "Alice Wonderland", "Savings", 1000.50);
    acc1.displayAccountInfo();

    std::cout << "\n--- Creating Account 2 (Invalid Initial Deposit) ---" << std::endl;
    BankAccount acc2("ACC002", "Bob The Builder", "Checking", -200.00);
    acc2.displayAccountInfo();

    std::cout << "\n--- Operations on Account 1 ---" << std::endl;
    acc1.deposit(500.75);
    acc1.withdraw(200.25);
    acc1.withdraw(2000.00); // Insufficient funds
    acc1.deposit(-50);      // Invalid deposit amount

    std::cout << "\n--- Using Getter and Setter for Account 1 ---" << std::endl;
    std::cout << "Current balance of " << acc1.getAccountNumber() << ": $" << acc1.getBalance() << std::endl;
    acc1.setAccountHolderName("Alice Wonderland-Smith");
    acc1.setAccountHolderName(""); // Attempt to set empty name
    acc1.displayAccountInfo();

    std::cout << "\n--- Creating Account 3 using Copy Constructor (from acc1) ---" << std::endl;
    BankAccount acc3 = acc1; // Calls copy constructor
    // BankAccount acc3(acc1); // Also calls copy constructor
    acc3.displayAccountInfo();
    // Demonstrate independence (modifying acc3 doesn't affect acc1's balance if deep copy elements were involved)
    acc3.deposit(100);
    std::cout << "Acc1 balance after acc3 deposit: $" << acc1.getBalance() << std::endl;
    std::cout << "Acc3 balance after acc3 deposit: $" << acc3.getBalance() << std::endl;


    std::cout << "\n--- Demonstrating Account 2 operations ---" << std::endl;
    acc2.deposit(300);
    acc2.withdraw(50);
    acc2.displayAccountInfo();


    std::cout << "\n--- End of main, objects will be destroyed ---" << std::endl;
    return 0;
}
```

**Explanation of C++ Solution Design:**

1.  **Private Data Members:** `accountNumber`, `accountHolderName`, `balance`, and `accountType` are all `private`.

      * `accountNumber` is `const std::string`, meaning it must be initialized in the constructor's member initializer list and cannot be changed afterwards, ensuring its immutability.
      * This directly enforces data hiding, a core part of encapsulation.

2.  **Parameterized Constructor `BankAccount(...)`:**

      * Initializes all member variables. It uses the member initializer list for `accountNumber` (as it's `const`), `accountHolderName`, `accountType`, and sets an initial `balance`.
      * Includes validation for `accountNumber` (checks if empty) and `initialDeposit` (must be non-negative). Error/warning messages are printed. This ensures objects are created in a valid state.

3.  **Copy Constructor `BankAccount(const BankAccount& other)`:**

      * Explicitly defined to show how copying is handled. It copies all members from the `other` object.
      * For `accountNumber`, which is `const`, copying presents a challenge if true identity is needed or if account numbers must be unique. The example appends `_copy` to the copied account number to make it distinct, highlighting a design consideration for `const` members and object copying. A more robust system might involve generating a new unique ID or disallowing direct copies if account numbers must remain globally unique and unchanged.

4.  **Destructor `~BankAccount()`:**

      * Prints a message upon object destruction. In this class, it doesn't manage dynamically allocated memory directly (as `std::string` handles its own memory), but it illustrates the destructor's role in the object lifecycle.

5.  **Public Member Functions:**

      * `deposit(double amount)`:
          * Checks if the `amount` is positive using the private helper `isValidAmount` (or directly).
          * If valid, it increments the `balance`. Otherwise, it prints an error.
      * `withdraw(double amount)`:
          * Checks if the `amount` is positive and if there are sufficient funds.
          * If valid, it decrements the `balance`. Otherwise, it prints an error.
      * `displayAccountInfo() const`:
          * Prints the account details. Marked `const` because it doesn't modify the object's state.
      * These methods form the public interface, allowing controlled interaction with the `BankAccount` object.

6.  **Getters:**

      * `getAccountNumber() const`, `getAccountHolderName() const`, `getBalance() const`, `getAccountType() const`.
      * All are marked `const` as they don't modify the object's state. They provide read-only access to the private data members.

7.  **Setter `setAccountHolderName(const std::string& newName)`:**

      * Allows modification of the `accountHolderName`.
      * Includes a basic validation (name not empty).
      * There are no setters for `accountNumber` (due to `const`), `balance` (modified via deposit/withdraw), or `accountType` (assumed immutable after creation in this design).

8.  **`main()` Function:**

      * Demonstrates creating `BankAccount` objects using the parameterized constructor, including cases with valid and invalid initial deposits.
      * Shows the use of `deposit`, `withdraw`, and how invalid operations (negative deposit, overdraft) are handled by the class methods.
      * Illustrates the use of `getBalance()` (getter) and `setAccountHolderName()` (setter).
      * Demonstrates the copy constructor (`BankAccount acc3 = acc1;`).
      * As objects `acc1`, `acc2`, and `acc3` go out of scope at the end of `main`, their destructors are automatically called, printing the destruction messages.

This C++ solution effectively uses private members for data hiding, constructors for proper initialization (including validation), a destructor for cleanup illustration, and public methods (including setters and getters) to provide a controlled interface, thereby achieving robust encapsulation and managing the object lifecycle according to OOP principles.



-----


## Question 3: Object Relationships and Advanced Member Management (15 Marks)**

**Theory (5 Marks):**
Explain the **"has-a" relationship (Composition/Aggregation)** in OOP. Differentiate between Composition and Aggregation. Discuss the purpose and usage of **Member Initialization Lists** in constructors, **`const` correctness** (constant data members, constant member functions, constants with pointers), and **static data members and static member functions**.

**Problem Analysis (5 Marks):**
Consider designing a `Course` class and a `Student` class.

  * A `Course` has a `courseCode` (string), `courseName` (string), and a list of `Student` objects enrolled in it. The list of students is integral to the course; if the course is cancelled (destroyed), the record of enrollment for that specific course context might also be considered gone (though student objects themselves might exist independently if they are also part of a global university roster).
  * A `Student` has a `studentId` (string) and `studentName` (string).
  * A `Course` also needs to keep track of the `totalCoursesOffered` across the entire system (a static count).

Analyze how to model the relationship between `Course` and `Student`. Which type of "has-a" relationship is more appropriate for the list of students within a course? How would you use member initialization lists for constructors in both classes? How would `const` correctness be applied? How would `totalCoursesOffered` be implemented?

**Solution Design (5 Marks):**
Implement the `Student` and `Course` classes in C++.

  * **`Student` class:**
      * Attributes: `studentId` (make it `const` after initialization), `studentName`.
      * Constructor using a member initialization list.
      * A `displayStudentInfo() const` method.
  * **`Course` class:**
      * Attributes: `courseCode` (`const`), `courseName`, a `std::vector` to store `Student` objects (or pointers/references, discuss your choice).
      * Static data member `totalCoursesOffered` and a static member function `getTotalCoursesOffered()`.
      * Constructor(s) using member initialization list, incrementing `totalCoursesOffered`.
      * Destructor decrementing `totalCoursesOffered`.
      * Method `addStudent(const Student& student)` to enroll a student.
      * Method `displayCourseInfo() const` to show course details and list enrolled students.
  * In `main()`, create `Student` objects. Create `Course` objects, add students to them, and display course information. Demonstrate the use of static members. Show how `const` correctness is applied.

**(Assessment Criteria for Question 3):**

  * **C-2:** Discuss knowledge of underlying concepts of object-oriented paradigm like abstraction, encapsulation, polymorphism, inheritance etc.
  * **C-3:** Illustrate Object-Oriented design artifacts and their mapping to Object-Oriented Programming using C++.
  * **C-6:** Design and assess small and medium scale C++ / C\# programs using object-oriented programming principles.

-----

### Solution 3

**Theory:**

**"Has-a" Relationship (Composition/Aggregation):**
The "has-a" relationship describes a situation where one class (the whole) contains an instance of another class (the part) as one of its members. This is a way to build complex objects from simpler ones. There are two main types:

1.  **Aggregation:**

      * Represents a "has-a" relationship where the part (contained object) can exist independently of the whole (containing object).
      * The lifetime of the part is not necessarily tied to the lifetime of the whole. If the whole is destroyed, the part may still exist.
      * It's often implemented by the containing class holding a pointer or reference to the contained object.
      * Example: A `Department` *has an* `Professor`. If the `Department` is disbanded, the `Professor` (as a person) might still exist and could join another department.

2.  **Composition:**

      * Represents a stronger "has-a" relationship, often called a "owns-a" relationship.
      * The part (contained object) is an integral part of the whole (containing object).
      * The lifetime of the part is strictly tied to the lifetime of the whole. If the whole is destroyed, the part is also destroyed.
      * It's typically implemented by the containing class having the contained object as a direct member variable (not a pointer/reference to an externally managed object), or by the containing class being solely responsible for creating and destroying the part.
      * Example: A `Car` *has an* `Engine`. The `Engine` is essential to the `Car`, and if the `Car` is scrapped, its specific `Engine` typically goes with it. An `Engine` object wouldn't usually exist meaningfully outside the context of a `Car` (or similar vehicle).

**Member Initialization Lists:**
A member initialization list is used in a constructor to initialize class members directly before the constructor body is executed.

  * **Syntax:** It appears after the constructor's parameter list, preceded by a colon (`:`), with members initialized in a comma-separated list (e.g., `MyClass(int x, int y) : member1(x), member2(y) {}`).
  * **Purpose and Usage:**
    1.  **Initialization vs. Assignment:** It performs initialization, not assignment. For complex objects, initialization is often more efficient than default construction followed by assignment in the constructor body.
    2.  **`const` Members:** `const` data members *must* be initialized in the member initialization list because they cannot be assigned a value after their creation.
    3.  **Reference Members:** Reference members *must* be initialized in the member initialization list as they need to refer to an object from the moment they are created.
    4.  **Base Class Constructors:** When a class inherits from a base class, the base class's constructor can (and often must) be called from the derived class's member initialization list.
    5.  **Members of Class Type without Default Constructor:** If a member is an object of a class that does not have a default constructor, it must be initialized in the member initialization list using one of its available constructors.
    6.  **Order of Initialization:** Members are initialized in the order they are declared in the class, not the order they appear in the initialization list. It's good practice to list them in declaration order to avoid confusion.

**`const` Correctness:**
`const` correctness refers to the practice of using the `const` keyword appropriately to prevent unintended modifications to data, making code safer, more readable, and easier to reason about.

  * **Constant Data Members (`const T member;`):** These members cannot be modified after they are initialized (which must happen in the member initialization list). They represent unchanging properties of an object.
  * **Constant Member Functions (`void func() const;`):** A `const` member function promises not to modify any non-static data members of the object it's called on. `this` pointer inside a `const` member function is a pointer to `const` (e.g., `const MyClass* this`). They can be called on both `const` and non-`const` objects. This is crucial for allowing operations on objects that are intended to be read-only.
  * **Constants with Pointers:**
      * **Pointer to Constant (`const T* ptr;` or `T const* ptr;`):** The data pointed to by `ptr` cannot be modified through `ptr`, but `ptr` itself can be made to point to a different address. `*ptr = value; // ERROR` `ptr = &anotherValue; // OK`
      * **Constant Pointer (`T* const ptr;`):** `ptr` itself cannot be made to point to a different address after initialization, but the data it points to can be modified through `ptr`. `*ptr = value; // OK` `ptr = &anotherValue; // ERROR`
      * **Constant Pointer to Constant (`const T* const ptr;` or `T const* const ptr;`):** Neither `ptr` itself nor the data it points to can be modified through `ptr`. `*ptr = value; // ERROR` `ptr = &anotherValue; // ERROR`

**Static Data Members and Static Member Functions:**

  * **Static Data Members (`static T member;`):**
      * Belong to the class itself, not to any specific object instance. There is only one copy of a static data member shared among all objects of the class.
      * Must be defined (and optionally initialized) outside the class definition, usually in the .cpp file.
      * Can be accessed using the class name and scope resolution operator (`ClassName::staticMember`) or through an object of the class (`object.staticMember`), though the former is preferred to emphasize its class-level nature.
      * Useful for data that is common to all instances, like counters, constants for the class, or shared resources.
  * **Static Member Functions (`static void func();`):**
      * Also belong to the class, not to a specific object instance.
      * They do not have a `this` pointer because they are not associated with a particular object.
      * They can only directly access other static members (data or functions) of the class. They cannot directly access non-static members because non-static members require an object instance.
      * Can be called using the class name and scope resolution operator (`ClassName::staticFunc()`) or through an object (`object.staticFunc()`).
      * Often used as utility functions related to the class but not dependent on a specific object's state, or to access/modify static data members.

**Problem Analysis (Course and Student):**

1.  **Relationship between `Course` and `Student` (List of Students):**

      * A `Course` "has-a" list of `Student`s.
      * The question states: "if the course is cancelled (destroyed), the record of enrollment for that specific course context might also be considered gone (though student objects themselves might exist independently...)."
      * This suggests **Aggregation** is more appropriate for the primary relationship if `Student` objects are managed externally (e.g., by a university roster) and the `Course` merely stores references or pointers to these externally managed `Student` objects. In this case, destroying a `Course` object would not destroy the `Student` objects themselves.
      * However, if the `Course` class is responsible for creating and managing its *own copies* of `Student` information specifically for that course instance (e.g., a snapshot of student details at the time of enrollment, or if `Student` objects are simple data structures primarily relevant to a course), then **Composition** could be argued if `Student` objects are stored directly *by value* within the `Course`'s `std::vector<Student>`. In this case, when the `Course` object is destroyed, the `Student` objects contained within its vector would also be destroyed.
      * **Choice for this problem:** The phrasing "list of `Student` objects enrolled in it" and "if the course is cancelled ... the record of enrollment ... might also be considered gone" leans towards Composition if we interpret "record of enrollment" as the `Student` objects *within that course's list*. Storing `Student` objects by value in `std::vector<Student>` implements Composition well. If students were to be shared across multiple courses without duplication and have independent lifecycles, `std::vector<std::shared_ptr<Student>>` or `std::vector<Student*>` (with careful lifetime management) would indicate Aggregation. For simplicity and to demonstrate composition clearly, let's use `std::vector<Student>` storing actual `Student` objects.

2.  **Member Initialization Lists:**

      * **`Student` class:** `studentId` (being `const`) and `studentName` should be initialized in the constructor's member initialization list.
      * **`Course` class:** `courseCode` (being `const`), `courseName`, and potentially initializing the `std::vector` of students (though `std::vector` has a default constructor, so explicit initialization in the list is not strictly necessary unless a non-default constructor of `vector` is used) should use the member initialization list. The static `totalCoursesOffered` is handled differently (incremented in constructor body, not in initializer list, as it's not an instance member).

3.  **`const` Correctness:**

      * **`Student` class:**
          * `studentId`: `const std::string studentId;` (constant data member).
          * `displayStudentInfo()`: `void displayStudentInfo() const;` (constant member function, as it only reads data).
      * **`Course` class:**
          * `courseCode`: `const std::string courseCode;` (constant data member).
          * `displayCourseInfo()`: `void displayCourseInfo() const;` (constant member function).
          * The `addStudent` method takes `const Student& student` to ensure the passed student object isn't modified by the function and to allow passing temporary `Student` objects or `const Student` objects.

4.  **`totalCoursesOffered` (Static Member):**

      * Declare `static int totalCoursesOffered;` inside the `Course` class definition.
      * Define and initialize it outside the class definition (in the .cpp file): `int Course::totalCoursesOffered = 0;`.
      * Implement `static int getTotalCoursesOffered()` in the `Course` class to access this static member.
      * The `Course` constructor will increment `totalCoursesOffered`.
      * The `Course` destructor will decrement `totalCoursesOffered`.

**Solution Design (C++ Code):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::find_if if checking for duplicate students

// Forward declaration (if Student needed to know about Course in a complex way, not needed here)
// class Course;

class Student {
private:
    const std::string studentId; // Constant data member
    std::string studentName;

public:
    // Constructor using Member Initialization List
    Student(const std::string& id, const std::string& name)
        : studentId(id), studentName(name) {
        if (id.empty() || name.empty()) {
            // In a real system, more robust error handling (e.g., exceptions)
            std::cerr << "Warning: Student ID or Name is empty during creation. Student: " << id << ", " << name << std::endl;
        }
        // std::cout << "Student " << studentName << " (ID: " << studentId << ") created." << std::endl;
    }

    // Copy constructor (default is fine here, but good to be aware)
    Student(const Student& other)
        : studentId(other.studentId), studentName(other.studentName) {
        // std::cout << "Student " << studentName << " (ID: " << studentId << ") copied." << std::endl;
    }

    // Getter for ID (const correct)
    std::string getStudentId() const {
        return studentId;
    }

    // Getter for Name (const correct)
    std::string getStudentName() const {
        return studentName;
    }

    // Constant member function
    void displayStudentInfo() const {
        std::cout << "  - ID: " << studentId << ", Name: " << studentName;
    }

    // Overload equality operator for checking if a student is already enrolled (optional)
    bool operator==(const Student& other) const {
        return studentId == other.studentId;
    }
};

class Course {
private:
    const std::string courseCode; // Constant data member
    std::string courseName;
    std::vector<Student> enrolledStudents; // Composition: Course owns these Student objects

    static int totalCoursesOffered; // Static data member

public:
    // Constructor using Member Initialization List
    Course(const std::string& code, const std::string& name)
        : courseCode(code), courseName(name) { // enrolledStudents is default-initialized
        if (code.empty() || name.empty()) {
             std::cerr << "Warning: Course Code or Name is empty during creation. Course: " << code << ", " << name << std::endl;
        }
        totalCoursesOffered++;
        std::cout << "Course '" << courseName << "' (" << courseCode << ") created. Total courses offered: "
                  << totalCoursesOffered << std::endl;
    }

    // Destructor
    ~Course() {
        totalCoursesOffered--;
        std::cout << "Course '" << courseName << "' (" << courseCode << ") destroyed. Total courses offered: "
                  << totalCoursesOffered << std::endl;
        // enrolledStudents vector and its Student objects will be automatically destroyed here (Composition)
    }

    // Method to add a student (demonstrating const reference)
    // Student object is copied into the vector (composition)
    void addStudent(const Student& student) {
        // Optional: Check if student is already enrolled
        auto it = std::find_if(enrolledStudents.begin(), enrolledStudents.end(),
                               [&](const Student& s) { return s.getStudentId() == student.getStudentId(); });

        if (it == enrolledStudents.end()) {
            enrolledStudents.push_back(student); // Copies the student object
            std::cout << "Student " << student.getStudentName() << " enrolled in " << courseName << "." << std::endl;
        } else {
            std::cout << "Student " << student.getStudentName() << " is already enrolled in " << courseName << "." << std::endl;
        }
    }

    // Constant member function
    void displayCourseInfo() const {
        std::cout << "\n--- Course Details ---" << std::endl;
        std::cout << "Code: " << courseCode << std::endl;
        std::cout << "Name: " << courseName << std::endl;
        std::cout << "Enrolled Students (" << enrolledStudents.size() << "):" << std::endl;
        if (enrolledStudents.empty()) {
            std::cout << "  No students enrolled." << std::endl;
        } else {
            for (const auto& student : enrolledStudents) { // Use const auto& for efficiency
                student.displayStudentInfo();
                std::cout << std::endl;
            }
        }
        std::cout << "----------------------" << std::endl;
    }

    // Constant member function to get course code
    std::string getCourseCode() const {
        return courseCode;
    }
     // Constant member function to get course name
    std::string getCourseName() const {
        return courseName;
    }

    // Static member function
    static int getTotalCoursesOffered() {
        return totalCoursesOffered;
    }
};

// Definition and initialization of the static data member
int Course::totalCoursesOffered = 0;

int main() {
    std::cout << "Initial total courses offered: " << Course::getTotalCoursesOffered() << std::endl;

    // Create Student objects
    Student student1("S1001", "Alice Johnson");
    Student student2("S1002", "Bob Smith");
    const Student student3("S1003", "Carol Williams"); // A const student object

    std::cout << "\n--- Creating Courses ---" << std::endl;
    Course mathCourse("MATH101", "Introduction to Calculus");
    Course csCourse("CS101", "Introduction to Programming");

    std::cout << "\n--- Enrolling Students ---" << std::endl;
    mathCourse.addStudent(student1);
    mathCourse.addStudent(student2);
    mathCourse.addStudent(student1); // Attempt to add duplicate

    csCourse.addStudent(student2);
    csCourse.addStudent(student3); // Adding a const student object

    std::cout << "\n--- Displaying Course Information ---" << std::endl;
    // Calling const member function on non-const object
    mathCourse.displayCourseInfo();
    csCourse.displayCourseInfo();

    // Demonstrate const correctness with a const Course object
    // To do this meaningfully, we'd need a way to initialize a const Course object
    // or a const reference/pointer. Let's use a const reference.
    std::cout << "\n--- Demonstrating Const Correctness with a Const Course Reference ---" << std::endl;
    const Course& constCsCourseRef = csCourse;
    std::cout << "Course Code (via const ref): " << constCsCourseRef.getCourseCode() << std::endl;
    constCsCourseRef.displayCourseInfo(); // OK: displayCourseInfo() is const
    // constCsCourseRef.addStudent(student1); // ERROR: addStudent() is not a const member function

    // Using pointer to const
    const Student* ptrToConstStudent = &student1;
    // ptrToConstStudent->studentName = "Alicia"; // ERROR: cannot modify through pointer to const data
    std::cout << "\nStudent Info via pointer to const student: ";
    ptrToConstStudent->displayStudentInfo(); // OK, displayStudentInfo is const
    std::cout << std::endl;

    // Student ID is const
    // student1.studentId = "S9999"; // ERROR: studentId is const

    std::cout << "\n--- Checking Total Courses Offered ---" << std::endl;
    std::cout << "Current total courses offered (via static method): " << Course::getTotalCoursesOffered() << std::endl;
    {
        Course tempCourse("TEMP101", "Temporary Course");
        std::cout << "Total courses after temp course: " << Course::getTotalCoursesOffered() << std::endl;
        tempCourse.displayCourseInfo();
    } // tempCourse goes out of scope here, destructor called
    std::cout << "Total courses after temp course destroyed: " << Course::getTotalCoursesOffered() << std::endl;

    std::cout << "\n--- End of main ---" << std::endl;
    // mathCourse and csCourse will be destroyed here
    return 0;
}
```

**Explanation of C++ Solution Design:**

1.  **`Student` Class:**

      * `studentId` is declared as `const std::string`, ensuring it cannot be changed after initialization.
      * The constructor `Student(const std::string& id, const std::string& name) : studentId(id), studentName(name)` uses a **member initialization list** to initialize `studentId` (mandatory for `const` members) and `studentName`.
      * `displayStudentInfo() const` is a **constant member function**, promising not to modify the `Student` object. This allows it to be called on `const Student` objects (like `student3` or via `constCsCourseRef` later).
      * `getStudentId() const` and `getStudentName() const` are provided as `const` accessors.
      * An `operator==` is overloaded to facilitate checking for duplicate students before adding them to a course, comparing based on `studentId`.

2.  **`Course` Class:**

      * `courseCode` is `const std::string`, initialized in the member initialization list.
      * `enrolledStudents` is a `std::vector<Student>`. This represents **Composition**: the `Course` object *owns* the `Student` objects in this list. When a `Course` object is destroyed, its `enrolledStudents` vector is destroyed, and consequently, all `Student` objects stored within it are also destroyed. This fulfills the "record of enrollment ... gone" aspect.
      * `static int totalCoursesOffered;` declares a **static data member**. It's shared among all `Course` objects.
      * `int Course::totalCoursesOffered = 0;` is the **definition and initialization** of the static data member outside the class.
      * The constructor `Course(...) : courseCode(code), courseName(name)` uses a member initialization list. It increments `totalCoursesOffered` in its body.
      * The destructor `~Course()` decrements `totalCoursesOffered`.
      * `addStudent(const Student& student)` takes a `const Student&` to accept students efficiently (avoids an unnecessary copy if the student already exists and is passed by value) and to ensure the passed `student` object isn't modified by this function. Inside, `enrolledStudents.push_back(student)` creates a *copy* of the student object and stores it in the vector (demonstrating the "owns-a" aspect for the objects within the list).
      * `displayCourseInfo() const` is a **constant member function**. It iterates through `enrolledStudents` and calls `student.displayStudentInfo()`.
      * `static int getTotalCoursesOffered()` is a **static member function** that returns the value of `totalCoursesOffered`. It can be called using `Course::getTotalCoursesOffered()`.

3.  **`main()` Function:**

      * Demonstrates the creation of `Student` objects, including a `const Student student3`.
      * Shows the creation of `Course` objects. The constructor messages illustrate the `totalCoursesOffered` static member being updated.
      * Students are added to courses. The `addStudent` method handles attempts to add duplicate students.
      * `displayCourseInfo()` is called on `Course` objects.
      * **Const Correctness Demonstration:**
          * A `const Course& constCsCourseRef = csCourse;` is created.
          * `constCsCourseRef.displayCourseInfo()` can be called because `displayCourseInfo` is a `const` member function.
          * An attempt to call `constCsCourseRef.addStudent(student1);` would result in a compile-time error because `addStudent` is not `const` and cannot be called on a `const` object/reference.
          * Accessing `studentId` (a `const` member of `Student`) shows it cannot be reassigned.
          * Using a `const Student* ptrToConstStudent` demonstrates that data pointed to cannot be changed via this pointer, but `const` methods can be called.
      * The static method `Course::getTotalCoursesOffered()` is used to retrieve the count of courses.
      * A block scope with `tempCourse` is used to show the destructor being called and `totalCoursesOffered` being decremented when `tempCourse` goes out of scope.
      * At the end of `main`, `mathCourse` and `csCourse` are destroyed, and their destructors further update `totalCoursesOffered`.

This solution models the "has-a" relationship (Composition for students within a course), correctly uses member initialization lists, applies `const` correctness to data members and member functions, and implements static members for class-level data and functionality.

-----

## Question 4: Advanced Polymorphism and Interface Design (15 Marks)**

**Theory (5 Marks):**
Explain **Function Overriding** and **Function Overloading** in C++. What are their key differences and purposes? Define an **Abstract Class** and an **Interface** (in the C++ context, often achieved using abstract classes with only pure virtual functions). Discuss the role of **Virtual Functions** and **Pure Virtual Functions** in achieving runtime polymorphism and defining contracts. What is the **Diamond Problem** in multiple inheritance, and how can **Virtual Inheritance** be used to solve it?

**Problem Analysis (5 Marks):**
Imagine an application for a graphics editor that supports different shapes (e.g., `Circle`, `Rectangle`, `Triangle`). All shapes must have methods to `draw()` themselves on a canvas and calculate their `area()`. However, the drawing logic and area calculation formula are unique to each shape type. The system should be able to manage a collection of different shapes and invoke these operations polymorphically. Furthermore, some shapes might also need a common capability, say `Serializable`, which dictates they must provide `serialize()` and `deserialize()` methods for saving and loading.

Analyze how you would design this system using abstract classes/interfaces, virtual functions, and potentially multiple inheritance to incorporate the `Serializable` capability. How would you ensure that concrete shape classes implement the necessary methods? Discuss potential issues if a shape inherits from multiple base classes that might share a common ancestor (hypothetically, if `Drawable` and `Serializable` both inherited from a `PersistentObject` base).

**Solution Design (5 Marks):**

1.  Design an abstract base class `Shape` with pure virtual functions `draw() const` and `calculateArea() const`.
2.  Design an "interface" (an abstract class with only pure virtual functions) called `ISerializable` with pure virtual functions `serialize(std::ostream& os) const` and `deserialize(std::istream& is)`.
3.  Implement concrete classes `Circle` and `Rectangle`.
      * `Circle` should inherit from `Shape` and `ISerializable`. It will have a `radius`.
      * `Rectangle` should inherit from `Shape` and `ISerializable`. It will have `width` and `height`.
      * Implement all inherited pure virtual functions in `Circle` and `Rectangle`.
      * `Circle` and `Rectangle` should also have appropriate constructors.
4.  In `main()`:
      * Create a `std::vector` of `Shape*`. Add instances of `Circle` and `Rectangle` to this vector.
      * Iterate through the vector and polymorphically call `draw()` and `calculateArea()` for each shape.
      * Demonstrate the use of `serialize()` and `deserialize()` for at least one shape object, perhaps by "saving" to a `std::stringstream` and then "loading" into a new object (or resetting an existing one).
      * Briefly discuss (in comments or output) how virtual inheritance would be used if `Shape` and `ISerializable` had a common problematic ancestor (though not fully implementing the diamond problem solution unless necessary to illustrate the point).

**(Assessment Criteria for Question 4):**

  * **C-2:** Discuss knowledge of underlying concepts of object-oriented paradigm like abstraction, encapsulation, polymorphism, inheritance etc.
  * **C-3:** Illustrate Object-Oriented design artifacts and their mapping to Object-Oriented Programming using C++.
  * **C-6:** Design and assess small and medium scale C++ / C\# programs using object-oriented programming principles.

-----

### Solution 4

**Theory:**

**Function Overloading:**

  * **Definition:** Function overloading allows multiple functions in the same scope to have the same name but different parameter lists (i.e., different number of arguments, different types of arguments, or different order of argument types).
  * **Purpose:** To provide multiple ways to perform a similar operation with different inputs, improving code readability and convenience. The compiler resolves which overloaded function to call at compile-time based on the arguments provided in the function call (static or compile-time polymorphism).
  * **Key Aspect:** Same function name, different signatures (parameter list). Return type alone is not sufficient to overload a function.

**Function Overriding (Method Overriding):**

  * **Definition:** Function overriding occurs in the context of inheritance. A derived class provides a specific implementation for a member function that is already defined in its base class. For overriding to achieve runtime polymorphism, the base class function must be declared `virtual`, and the derived class function must have the exact same signature (name, parameter types, const-ness) and a compatible return type.
  * **Purpose:** To allow derived classes to provide specialized behavior for inherited methods while maintaining a common interface defined by the base class. This is the core mechanism for runtime polymorphism.
  * **Key Aspect:** Same function signature in base and derived class, base function is `virtual`. The decision of which function version to call is made at runtime based on the actual type of the object (dynamic or runtime polymorphism).

**Differences and Purposes Summary:**
| Feature          | Function Overloading                      | Function Overriding                        |
| :--------------- | :---------------------------------------- | :----------------------------------------- |
| **Context** | Same scope (often same class)             | Base and Derived classes (Inheritance)     |
| **Signature** | Same name, **different** parameter list   | Same name, **same** parameter list       |
| **`virtual` Keyword** | Not applicable                            | Base function usually `virtual`            |
| **Polymorphism** | Compile-time (Static)                     | Runtime (Dynamic)                          |
| **Purpose** | Convenience, multiple ways to do an action | Specialization, polymorphic behavior      |

**Abstract Class:**

  * An abstract class is a class that cannot be instantiated on its own. It is designed to be a base class from which other classes can inherit.
  * It contains at least one **pure virtual function**.
  * **Purpose:** To define a common interface (a contract) for its derived classes. It can also provide common implementations (non-pure virtual functions or regular member functions and data members) that derived classes can inherit and use or override.

**Interface (in C++ context):**

  * C++ does not have a dedicated `interface` keyword like Java or C\#.
  * An interface is typically implemented as an abstract class that contains *only* pure virtual functions (and possibly static constants). It has no data members (unless static const) and no implemented member functions.
  * **Purpose:** To define a strict contract that concrete classes must adhere to by implementing all its pure virtual functions. It specifies *what* a class can do, without dictating *how*. This enables complete decoupling between the interface and its implementations.

**Virtual Functions:**

  * A member function declared with the `virtual` keyword in a base class.
  * **Purpose:** To indicate that the function can be overridden by derived classes and to enable runtime polymorphism. When a virtual function is called through a base class pointer or reference, the actual function executed is determined at runtime based on the dynamic type of the object being pointed or referred to.

**Pure Virtual Functions:**

  * A virtual function that is declared by assigning `= 0` in its declaration in the base class (e.g., `virtual void func() = 0;`).
  * **Purpose:**
    1.  Makes the class containing it an abstract class (cannot be instantiated).
    2.  Forces derived classes to provide a concrete implementation for this function if they want to be instantiable. If a derived class does not override all pure virtual functions from its base, it also becomes abstract.
    3.  Defines a mandatory part of the interface for all concrete derived classes.

**Diamond Problem in Multiple Inheritance:**

  * **Problem:** Occurs when a class (D) inherits from two or more classes (B and C), and both of these intermediate base classes (B and C) themselves inherit from a common grandparent class (A).
    ```
        A
       / \
      B   C
       \ /
        D
    ```
    Without virtual inheritance, class D would inherit two separate instances of the members of class A (one through B and one through C). This leads to ambiguity when accessing members of A from D (e.g., `d_obj.a_member` would be ambiguous: which `a_member`? The one from B's A or C's A?). It also leads to redundant storage.

**Virtual Inheritance:**

  * **Solution:** Virtual inheritance ensures that only one copy of the common base class (A) is inherited by the most derived class (D), regardless of how many inheritance paths exist from D back to A.
  * **Mechanism:** When B and C inherit from A, they do so using the `virtual` keyword:
    `class B : virtual public A { ... };`
    `class C : virtual public A { ... };`
    `class D : public B, public C { ... };`
  * Now, class D will contain only one subobject of A. The initialization of the virtual base class (A) becomes the responsibility of the most derived class (D) in the hierarchy.
  * **Purpose:** To resolve the ambiguity and redundancy caused by the diamond problem in multiple inheritance scenarios.

**Problem Analysis (Graphics Editor):**

1.  **Core Abstraction (`Shape`):**

      * An abstract class `Shape` is appropriate. All shapes share common behaviors (`draw()`, `calculateArea()`) but implement them differently.
      * `draw() const` and `calculateArea() const` should be pure virtual functions in `Shape` to enforce implementation by concrete shape classes (e.g., `Circle`, `Rectangle`).
      * This class will serve as the base for polymorphic operations on a collection of shapes.

2.  **`ISerializable` Interface:**

      * This defines a contract for objects that can be saved and loaded.
      * It should be an abstract class with pure virtual functions: `serialize(std::ostream& os) const` and `deserialize(std::istream& is)`.
      * Classes like `Circle` and `Rectangle` will multiply inherit from `Shape` and `ISerializable`.

3.  **Concrete Shapes (`Circle`, `Rectangle`):**

      * `Circle` will inherit `public Shape` and `public ISerializable`. It will store a `radius`. It must implement `draw()`, `calculateArea()`, `serialize()`, and `deserialize()`.
      * `Rectangle` will inherit `public Shape` and `public ISerializable`. It will store `width` and `height`. It must implement `draw()`, `calculateArea()`, `serialize()`, and `deserialize()`.
      * Constructors will initialize their specific attributes.

4.  **Polymorphism:**

      * A `std::vector<Shape*>` can hold pointers to `Circle`, `Rectangle`, and other future `Shape`-derived objects.
      * Iterating through this vector and calling `ptr->draw()` or `ptr->calculateArea()` will invoke the correct version for the actual object type at runtime.
      * To use `serialize` or `deserialize`, we would need to cast the `Shape*` to an `ISerializable*` (e.g., using `dynamic_cast`) if we are operating on the shape collection, or call it directly if we have an object of a concrete type.

5.  **Multiple Inheritance and Potential Diamond Problem:**

      * In this design, `Shape` and `ISerializable` are independent base classes.
        ```
           Shape   ISerializable
             \       /
              \     /
               Circle
        ```
      * There is no common ancestor between `Shape` and `ISerializable` *in this specific design*, so the diamond problem does not directly arise here from `Circle` inheriting from both.
      * **Hypothetical Scenario for Diamond Problem:** If, for instance, both `Shape` and `ISerializable` were to inherit from a common base class, say `PersistentObject`:
        ```
              PersistentObject
                 /       \
            Shape     ISerializable
                 \       /
                  \     /
                   Circle
        ```
        Then, `Circle` would get two copies of `PersistentObject`'s members. To solve this, `Shape` and `ISerializable` would need to inherit virtually from `PersistentObject`:
        `class Shape : virtual public PersistentObject { ... };`
        `class ISerializable : virtual public PersistentObject { ... };`
        `class Circle : public Shape, public ISerializable { ... };`
        This ensures `Circle` has only one `PersistentObject` subobject. The solution design will briefly mention this concept.

6.  **Ensuring Method Implementation:**

      * Pure virtual functions in `Shape` (`draw`, `calculateArea`) and `ISerializable` (`serialize`, `deserialize`) make `Shape` and `ISerializable` abstract.
      * Any concrete class like `Circle` or `Rectangle` *must* provide implementations for all these pure virtual functions to be instantiable. The compiler will enforce this.

This approach ensures a flexible and extensible system where new shapes can be added by inheriting from `Shape` (and `ISerializable` if needed) and implementing the required methods.

**Solution Design (C++ Code):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI (may need _USE_MATH_DEFINES on Windows) and pow
#include <sstream> // For std::stringstream
#include <iomanip> // For std::fixed, std::setprecision

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- ISerializable Interface ---
class ISerializable {
public:
    virtual ~ISerializable() {} // Important for interfaces too!

    // Pure virtual functions for serialization contract
    virtual void serialize(std::ostream& os) const = 0;
    virtual void deserialize(std::istream& is) = 0; // Not const, modifies object
};

// --- Shape Abstract Base Class ---
class Shape {
public:
    virtual ~Shape() { // Good practice for base classes
        // std::cout << "Shape destructor called." << std::endl;
    }

    // Pure virtual functions for shape contract
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual std::string getName() const = 0; // Added for better output
};


// --- Concrete Circle Class ---
class Circle : public Shape, public ISerializable {
private:
    double radius;
    std::string name;

public:
    Circle(double r = 0.0) : radius(r), name("Circle") {
        if (r < 0) {
            std::cerr << "Warning: Circle radius cannot be negative. Setting to 0." << std::endl;
            radius = 0;
        }
        // std::cout << "Circle created with radius " << radius << std::endl;
    }

    ~Circle() override {
        // std::cout << "Circle destructor (radius " << radius << ")" << std::endl;
    }

    // Override Shape pure virtual functions
    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << "." << std::endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    std::string getName() const override {
        return name;
    }

    // Override ISerializable pure virtual functions
    void serialize(std::ostream& os) const override {
        // Simple serialization: type, radius
        os << "Circle\n" << radius << "\n";
        // std::cout << "Circle serialized: radius " << radius << std::endl;
    }

    void deserialize(std::istream& is) override {
        // Simple deserialization: expects type and radius
        // (Type could be used for factory pattern, but here we assume it's already a Circle object)
        std::string typeName;
        // is >> typeName; // If type was checked from stream
        is >> this->radius;
        if (is.fail() || radius < 0) {
            std::cerr << "Error during Circle deserialization or invalid radius. Resetting to 0." << std::endl;
            radius = 0;
            is.clear(); // Clear error flags
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of the line
        }
        // std::cout << "Circle deserialized: new radius " << radius << std::endl;
    }

    // Getter for radius (for testing deserialization)
    double getRadius() const { return radius; }
};


// --- Concrete Rectangle Class ---
class Rectangle : public Shape, public ISerializable {
private:
    double width;
    double height;
    std::string name;

public:
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h), name("Rectangle") {
        if (w < 0 || h < 0) {
            std::cerr << "Warning: Rectangle dimensions cannot be negative. Setting to 0." << std::endl;
            width = (w < 0) ? 0 : w;
            height = (h < 0) ? 0 : h;
        }
        // std::cout << "Rectangle created with width " << width << " and height " << height << std::endl;
    }

     ~Rectangle() override {
        // std::cout << "Rectangle destructor (w:" << width << ", h:" << height << ")" << std::endl;
    }

    // Override Shape pure virtual functions
    void draw() const override {
        std::cout << "Drawing a Rectangle with width " << width << " and height " << height << "." << std::endl;
    }

    double calculateArea() const override {
        return width * height;
    }

     std::string getName() const override {
        return name;
    }

    // Override ISerializable pure virtual functions
    void serialize(std::ostream& os) const override {
        // Simple serialization: type, width, height
        os << "Rectangle\n" << width << "\n" << height << "\n";
        // std::cout << "Rectangle serialized: " << width << "x" << height << std::endl;
    }

    void deserialize(std::istream& is) override {
        // Simple deserialization
        // std::string typeName;
        // is >> typeName;
        is >> this->width >> this->height;
        if (is.fail() || width < 0 || height < 0) {
            std::cerr << "Error during Rectangle deserialization or invalid dimensions. Resetting to 0x0." << std::endl;
            width = 0; height = 0;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // std::cout << "Rectangle deserialized: new " << width << "x" << height << std::endl;
    }

    // Getters for testing deserialization
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// --- Function Overloading Example (Independent of Shape hierarchy) ---
void printValue(int i) {
    std::cout << "Overloaded printValue (int): " << i << std::endl;
}

void printValue(double d) {
    std::cout << "Overloaded printValue (double): " << d << std::endl;
}

void printValue(const std::string& s) {
    std::cout << "Overloaded printValue (string): " << s << std::endl;
}


int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "--- Function Overloading Demonstration ---" << std::endl;
    printValue(10);
    printValue(3.14);
    printValue("Hello OOP");

    std::cout << "\n--- Shape Polymorphism and ISerializable Demonstration ---" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "\n--- Iterating and calling virtual functions (draw, calculateArea) ---" << std::endl;
    for (const auto& shapePtr : shapes) {
        std::cout << "\nProcessing a " << shapePtr->getName() << ":" << std::endl;
        shapePtr->draw(); // Polymorphic call (Function Overriding in action)
        std::cout << "Area: " << shapePtr->calculateArea() << std::endl; // Polymorphic call

        // Demonstrate ISerializable (needs a cast)
        ISerializable* serializableObj = dynamic_cast<ISerializable*>(shapePtr);
        if (serializableObj) {
            std::stringstream ss;
            std::cout << "Attempting to serialize " << shapePtr->getName() << "..." << std::endl;
            serializableObj->serialize(ss);
            std::cout << shapePtr->getName() << " serialized data: " << ss.str(); // Show the string stream content

            // Demonstrate deserialization (into a new or existing object of the correct type)
            // For simplicity, let's try to deserialize back into the same object type
            // (In a real app, you'd often create a new object based on type info from stream)
            std::cout << "Attempting to deserialize " << shapePtr->getName() << " from its own serialized data..." << std::endl;
            // Create a new istringstream from the serialized data
            std::istringstream iss(ss.str());
            std::string typeNameFromStream; // Read and discard the type name for this simple deserialize
            iss >> typeNameFromStream;
            
            serializableObj->deserialize(iss); // Deserialize the rest of the data

            std::cout << shapePtr->getName() << " after deserialization:" << std::endl;
            shapePtr->draw(); // Show its state
        } else {
            std::cout << shapePtr->getName() << " is not ISerializable." << std::endl;
        }
    }

    // Example: Serialize a specific Circle and deserialize into a new one
    std::cout << "\n--- Specific Serialization/Deserialization Example ---" << std::endl;
    Circle originalCircle(7.5);
    std::stringstream specific_ss;
    std::cout << "Original Circle: ";
    originalCircle.draw();

    ISerializable* originalSerializableCircle = &originalCircle; // Get ISerializable interface
    originalSerializableCircle->serialize(specific_ss);
    std::cout << "Serialized Original Circle: " << specific_ss.str();

    Circle loadedCircle; // Create a new default circle
    ISerializable* loadedSerializableCircle = &loadedCircle;

    std::istringstream specific_iss(specific_ss.str());
    std::string typeName;
    specific_iss >> typeName; // Consume the "Circle" type string

    loadedSerializableCircle->deserialize(specific_iss);
    std::cout << "Loaded Circle after deserialization: ";
    loadedCircle.draw();
    std::cout << "Loaded Circle radius: " << loadedCircle.getRadius() << std::endl;


    std::cout << "\n--- Discussing Diamond Problem and Virtual Inheritance (Conceptual) ---" << std::endl;
    std::cout << "If 'Shape' and 'ISerializable' both inherited from a common base class, e.g., 'PersistentObject',\n";
    std::cout << "a class like 'Circle' inheriting from both 'Shape' and 'ISerializable' would get two copies\n";
    std::cout << "of 'PersistentObject' members. This is the Diamond Problem.\n";
    std::cout << "To solve this, 'Shape' and 'ISerializable' would inherit 'virtually' from 'PersistentObject':\n";
    std::cout << "  class Shape : virtual public PersistentObject { /* ... */ };\n";
    std::cout << "  class ISerializable : virtual public PersistentObject { /* ... */ };\n";
    std::cout << "This ensures 'Circle' gets only one instance of 'PersistentObject'.\n";
    std::cout << "In our current design, Shape and ISerializable are independent, so this issue doesn't arise directly.\n";


    std::cout << "\n--- Cleaning up heap-allocated Shape objects ---" << std::endl;
    for (auto& shapePtr : shapes) {
        delete shapePtr; // Virtual destructors in Shape and ISerializable ensure proper cleanup
    }
    shapes.clear();

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}

```

**Explanation of C++ Solution Design:**

1.  **Function Overloading (`printValue`):**

      * Three distinct `printValue` functions are provided, each taking a different parameter type (`int`, `double`, `const std::string&`).
      * In `main`, calls to `printValue` with different argument types demonstrate how the compiler selects the correct overload at compile-time.

2.  **`ISerializable` Interface:**

      * Declared as a class with a `virtual ~ISerializable()` (good practice for any class intended as a base, especially if objects might be deleted via a pointer to this type).
      * Contains two **pure virtual functions**: `serialize(std::ostream& os) const = 0` and `deserialize(std::istream& is) = 0`.
      * This makes `ISerializable` an abstract class acting as an interface. Any concrete class implementing this interface *must* provide definitions for these two methods.
      * `deserialize` is not `const` because it's intended to modify the object's state by reading from the stream.

3.  **`Shape` Abstract Base Class:**

      * Has a `virtual ~Shape()` for proper cleanup when derived objects are deleted via a `Shape*`.
      * Contains **pure virtual functions**: `draw() const = 0`, `calculateArea() const = 0`, and `getName() const = 0`.
      * This makes `Shape` an abstract class. Concrete shapes must implement these.
      * `getName()` is added for more descriptive output.

4.  **`Circle` and `Rectangle` Concrete Classes:**

      * Both classes inherit publicly from `Shape` and `ISerializable` (multiple inheritance):
        `class Circle : public Shape, public ISerializable`
        `class Rectangle : public Shape, public ISerializable`
      * **Constructors:** Initialize their specific geometric properties (`radius` for `Circle`, `width` and `height` for `Rectangle`). They include basic validation for non-negative dimensions.
      * **Function Overriding:** They `override` all the pure virtual functions inherited from `Shape` (`draw`, `calculateArea`, `getName`) and `ISerializable` (`serialize`, `deserialize`). The `override` keyword is used for clarity and compiler checks.
          * `draw()`: Prints a message specific to the shape.
          * `calculateArea()`: Implements the correct area formula.
          * `serialize()`: Writes the object's type and data to an `std::ostream`. The format is simple (e.g., "Circle\\nradius\_value\\n").
          * `deserialize()`: Reads data from an `std::istream` to set the object's state. It includes basic error checking.
      * **Destructors:** `~Circle() override` and `~Rectangle() override` are provided. They are implicitly virtual because the base class destructors are virtual.

5.  **`main()` Function:**

      * **Polymorphism with `Shape*`:**
          * A `std::vector<Shape*> shapes` stores pointers to dynamically allocated `Circle` and `Rectangle` objects.
          * When iterating through the vector, `shapePtr->draw()` and `shapePtr->calculateArea()` are called. Due to **virtual functions** and **function overriding**, the correct version of these methods for the actual object type (`Circle` or `Rectangle`) is executed at runtime. This demonstrates runtime polymorphism.
      * **Using `ISerializable`:**
          * `dynamic_cast<ISerializable*>(shapePtr)` is used to safely cast a `Shape*` to an `ISerializable*`. This is necessary because the `shapes` vector is of type `Shape*`, and `Shape` itself does not have `serialize`/`deserialize` methods.
          * If the cast is successful, `serialize()` is called to write the object's state to a `std::stringstream`.
          * `deserialize()` is then demonstrated by reading from this `stringstream` back into the (or a new) object. A simple type string is read and discarded in the deserialize demo within the loop; a more robust solution might use a factory based on this type string.
      * **Specific Serialization/Deserialization:** A separate example shows serializing a `Circle` object and then deserializing its data into a new `Circle` object, demonstrating how state can be transferred.
      * **Discussion of Diamond Problem:** Comments in `main` explain what the diamond problem is and how `virtual inheritance` would be the solution if `Shape` and `ISerializable` had a common, problematic ancestor. Since they don't in this design, virtual inheritance isn't actively used but is discussed as required.
      * **Cleanup:** Dynamically allocated `Shape` objects are deleted using `delete shapePtr;`. The virtual destructors in `Shape` (and implicitly through multiple inheritance, from `ISerializable` if it had complex cleanup) ensure that the correct derived class destructors (`~Circle`, `~Rectangle`) are called, preventing memory leaks.

This solution effectively demonstrates function overriding for runtime polymorphism via the `Shape` hierarchy, function overloading with `printValue`, the use of abstract classes (`Shape`) and interfaces (`ISerializable`) with pure virtual functions to define contracts, and multiple inheritance. It also correctly addresses the theory of the diamond problem and virtual inheritance.

-----

## Question 5: Generic Programming, Exception Handling, and Advanced OOP Constructs (15 Marks)**

**Theory (5 Marks):**
Explain the concept of **Generics (Templates)** in C++. How do function templates and class templates promote code reusability for different data types? Introduce **Exception Handling** in C++ (try, catch, throw). What are its benefits in creating robust applications? Briefly discuss the **`this` pointer**, **inline functions**, and **arrays of objects**.

**Problem Analysis (5 Marks):**
You need to create a generic `StorageBox` class that can store a single item of any data type. This box should have a way to set the item, get the item, and check if it's empty. Additionally, when trying to get an item from an empty box, an exception should be thrown. You also want a generic utility function `isEqualTo` that can compare two items of any type for equality. Consider how the `this` pointer would be implicitly used within the `StorageBox` methods. How might `inline` be relevant for simple getter/setter methods in `StorageBox`? How would an array of `StorageBox<int>` objects be declared and used?

**Solution Design (5 Marks):**

1.  Implement a **class template** `StorageBox<T>`.
      * It should have a private data member of type `T` to store the item and a boolean flag to indicate if it's full.
      * A default constructor that initializes the box as empty.
      * A `setItem(const T& item)` method. This method should use the `this` pointer implicitly to refer to member variables.
      * A `T getItem() const` method. This method should throw a custom exception (e.g., `EmptyBoxException`) if the box is empty. Mark this (and `setItem`, `isEmpty`) as potentially `inline` if appropriate.
      * An `isEmpty() const` method.
2.  Define a custom exception class `EmptyBoxException` inheriting from `std::exception`.
3.  Implement a **function template** `isEqualTo<T>(const T& a, const T& b)` that returns `true` if `a` and `b` are equal, `false` otherwise (relies on `operator==` for type `T`).
4.  In `main()`:
      * Demonstrate the `isEqualTo` function template with different data types (e.g., `int`, `double`, `std::string`).
      * Create instances of `StorageBox` for different types (e.g., `StorageBox<int>`, `StorageBox<std::string>`).
      * Demonstrate `setItem`, `getItem`, and `isEmpty` methods.
      * Use a `try-catch` block to handle the `EmptyBoxException` when attempting to get an item from an empty `StorageBox`.
      * Declare and briefly demonstrate an array of `StorageBox<int>` objects.
      * Include comments explaining where the `this` pointer is implicitly used and the rationale for potentially inlining simple methods.

**(Assessment Criteria for Question 5):**

  * **C-2:** Discuss knowledge of underlying concepts of object-oriented paradigm like abstraction, encapsulation, polymorphism, inheritance etc.
  * **C-3:** Illustrate Object-Oriented design artifacts and their mapping to Object-Oriented Programming using C++.
  * **C-6:** Synthesize programs using Generic Programming and exception handling.

-----

### Solution 5:

**Theory:**

**Generics (Templates) in C++:**
Generics, implemented in C++ through **templates**, allow programmers to write generic algorithms and data structures that can operate on different data types without being rewritten for each type. This promotes code reusability and type safety.

  * **Function Templates:** Define a blueprint for creating a family of functions. The compiler generates a specific version of the function when it's called with a particular data type.

      * Syntax: `template <typename T> T max(T a, T b) { return (a > b) ? a : b; }`
      * `typename T` (or `class T`) declares `T` as a placeholder for a data type.

  * **Class Templates:** Define a blueprint for creating a family of classes. An instance of a class template is created by specifying the data type(s) for its template parameters.

      * Syntax: `template <typename T> class Stack { T* data; /* ... */ public: void push(T val); T pop(); };`
      * To use: `Stack<int> intStack; Stack<std::string> stringStack;`

**Benefits of Templates:**

  * **Code Reusability:** Write code once, use it for many types.
  * **Type Safety:** Type checking is performed at compile-time, reducing runtime errors.
  * **Efficiency:** Often results in more efficient code than alternatives like void pointers, as type information is available to the compiler for optimization.

**Exception Handling in C++ (try, catch, throw):**
Exception handling is a mechanism to deal with runtime errors or exceptional situations in a structured and controlled manner, allowing a program to recover from errors or terminate gracefully.

  * **`throw`:** When an exceptional situation occurs, code can `throw` an exception object. This object can be of any type, but typically, it's an object of a class derived from `std::exception`.
  * **`try`:** A `try` block encloses a section of code where exceptions might occur.
  * **`catch`:** A `try` block is followed by one or more `catch` blocks. Each `catch` block specifies the type of exception it can handle. If an exception is thrown in the `try` block, the program looks for a matching `catch` block.
      * Syntax: `catch (const ExceptionType& e) { /* handle e */ }`
      * `catch(...)` can catch any type of exception.

**Benefits of Exception Handling:**

  * **Separation of Error Handling Code:** Keeps error handling logic separate from the main program logic, improving readability.
  * **Robustness:** Allows programs to handle errors gracefully without crashing, potentially recovering or cleaning up resources before termination.
  * **Propagation of Errors:** Exceptions can propagate up the call stack until a suitable handler is found, allowing errors to be handled at an appropriate level.
  * **Object-Oriented Error Reporting:** Custom exception classes can carry detailed information about the error.

**`this` Pointer:**

  * In C++, `this` is a keyword that represents a pointer to the object for which a non-static member function is called.
  * It's an implicit parameter to all non-static member functions.
  * **Purpose:**
    1.  To distinguish between member variables and local variables/parameters with the same name (e.g., `this->member = member;`).
    2.  To return a reference or pointer to the current object from a member function (e.g., for enabling chained calls: `obj.setX(10).setY(20);`).
    3.  To pass the current object to another function.
  * The type of `this` in a member function of class `X` is `X*`. In a `const` member function, its type is `const X*`.

**Inline Functions:**

  * The `inline` keyword is a *request* to the compiler to replace the call to a function with the actual code of the function itself at the call site (textual substitution).
  * **Purpose:** To reduce the overhead of function calls (stack frame setup, jumping, etc.) for small, frequently called functions.
  * **Considerations:**
      * It's only a suggestion; the compiler can ignore it.
      * Overuse of inlining for large functions can increase code size (code bloat), potentially harming performance due to cache misses.
      * Functions defined entirely within a class definition are implicitly considered for inlining.
      * Good candidates for inlining are usually very short functions like simple getters, setters, or forwarding functions.

**Arrays of Objects:**

  * An array of objects is a collection of instances of the same class, stored contiguously in memory.
  * **Declaration:** `ClassName arrayName[size];`
  * **Initialization:**
      * If the class has a default constructor, objects in the array are default-initialized.
      * Objects can be initialized using an initializer list if the class constructor(s) allow: `MyClass arr[2] = { MyClass(1), MyClass(2) };` or `MyClass arr[] = { MyClass(1), MyClass(2) };`
  * **Access:** Individual objects are accessed using array indexing: `arrayName[i].memberFunction();`
  * Each element in the array is a separate object with its own data members.

**Problem Analysis (StorageBox, isEqualTo, Exception):**

1.  **`StorageBox<T>` Class Template:**

      * **Genericity:** It needs to store an item of *any* type `T`. This clearly calls for a class template `template <typename T> class StorageBox`.
      * **State:**
          * `T item_`: To store the actual item.
          * `bool isFull_`: To track if the box contains an item.
      * **Constructor:** A default constructor will initialize `isFull_` to `false`.
      * **`setItem(const T& item)`:**
          * Takes an item of type `T`.
          * Sets `item_ = item;` and `isFull_ = true;`.
          * `this->item_ = item;` and `this->isFull_ = true;` explicitly show `this` pointer usage, though it's often implicit if there's no naming conflict.
          * This is a simple setter, a candidate for `inline`.
      * **`T getItem() const`:**
          * If `isFull_` is `false` (or `!isEmpty()`), it should throw `EmptyBoxException`.
          * Otherwise, it returns `item_`.
          * `const` because it doesn't modify the box's state (if not empty).
          * This is a simple getter (with a check), a candidate for `inline`.
      * **`isEmpty() const`:**
          * Returns `!isFull_`.
          * `const` because it doesn't modify state.
          * A very simple getter, strong candidate for `inline`.

2.  **`EmptyBoxException` Custom Exception:**

      * Should inherit from `std::exception` to be compatible with standard exception handling mechanisms.
      * Override the `what() const noexcept` method to provide a custom error message.

3.  **`isEqualTo<T>(const T& a, const T& b)` Function Template:**

      * **Genericity:** Must compare two items of *any* type `T`. This requires a function template `template <typename T> bool isEqualTo(...)`.
      * **Mechanism:** It will use `operator==` for the given type `T`. This means type `T` must have `operator==` defined for it to work correctly.

4.  **`this` Pointer in `StorageBox`:**

      * When `setItem` uses `item_ = item;`, it's implicitly `this->item_ = item;`.
      * When `getItem` returns `item_`, it's implicitly `this->item_`.
      * When `isEmpty` uses `isFull_`, it's implicitly `this->isFull_`.

5.  **`inline` Relevance for `StorageBox`:**

      * `setItem`, `getItem` (especially the non-throwing part), and `isEmpty` are short and simple. Marking them `inline` (or defining them within the class template definition, which makes them implicitly inline candidates) could reduce function call overhead.

6.  **Array of `StorageBox<int>`:**

      * Declaration: `StorageBox<int> intBoxes[5];`
      * Usage: Each `intBoxes[i]` is a `StorageBox<int>` object. We can call `setItem`, `getItem` on each.
          * `intBoxes[0].setItem(100);`
          * `int val = intBoxes[0].getItem();`
          * If `intBoxes[1]` is empty, `intBoxes[1].getItem()` would throw.

This analysis covers the requirements using templates for generics, custom exceptions for error handling, and considers the roles of `this` and `inline`.

**Solution Design (C++ Code):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // For std::exception

// --- 2. Custom Exception Class ---
class EmptyBoxException : public std::exception {
public:
    // Override what() to provide a custom error message
    const char* what() const noexcept override {
        return "EmptyBoxException: Attempted to get an item from an empty StorageBox.";
    }
};

// --- 1. Class Template StorageBox<T> ---
template <typename T>
class StorageBox {
private:
    T item_;         // Data member of type T
    bool isFull_;    // Flag to indicate if the box has an item

public:
    // Default constructor: initializes the box as empty
    StorageBox() : isFull_(false) {
        // item_ is default-initialized for type T if T has a default constructor.
        // For fundamental types, it's uninitialized unless explicitly done.
        // std::cout << "StorageBox created (empty)." << std::endl;
    }

    // setItem: places an item into the box
    // Potentially inline (if defined outside class, use 'inline' keyword,
    // but often defined inside class template for implicit inlining)
    void setItem(const T& item) {
        // 'this->' is implicit here if there are no name clashes.
        // this->item_ = item;
        // this->isFull_ = true;
        item_ = item;   // Implicit this->item_
        isFull_ = true; // Implicit this->isFull_
        // std::cout << "Item set in StorageBox." << std::endl;
    }

    // getItem: retrieves the item from the box
    // Throws EmptyBoxException if the box is empty
    // Potentially inline
    T getItem() const {
        if (!isFull_) { // or !this->isFull_
            throw EmptyBoxException();
        }
        return item_; // Implicit this->item_
    }

    // isEmpty: checks if the box is empty
    // Potentially inline
    bool isEmpty() const {
        return !isFull_; // Implicit !this->isFull_
    }

    // clear: makes the box empty again
    void clear() {
        isFull_ = false;
        // For non-trivial T, might need to reset item_ to a default state
        // or let T's destructor be called if item_ was dynamically managed by StorageBox (not the case here)
        // e.g. if T was T* item_ = new T(...); then delete item_; item_ = nullptr;
        // but here item_ is an object of type T, so it just becomes unused.
        // If T requires explicit cleanup beyond its destructor, StorageBox would be more complex.
    }
};

// --- 3. Function Template isEqualTo<T> ---
template <typename T>
bool isEqualTo(const T& a, const T& b) {
    // Relies on operator== being defined for type T
    return a == b;
}

// Example of a class that might not have a default == or needs custom logic
class ComplexNumber {
public:
    double real, imag;
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    // Custom operator== for ComplexNumber
    bool operator==(const ComplexNumber& other) const {
        return real == other.real && imag == other.imag;
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
        os << "(" << cn.real << (cn.imag >= 0 ? "+" : "") << cn.imag << "i)";
        return os;
    }
};


int main() {
    std::cout << "--- 3. isEqualTo Function Template Demonstration ---" << std::endl;
    std::cout << "isEqualTo(10, 10): " << (isEqualTo(10, 10) ? "true" : "false") << std::endl;
    std::cout << "isEqualTo(10, 20): " << (isEqualTo(10, 20) ? "true" : "false") << std::endl;
    std::cout << "isEqualTo(3.14, 3.14): " << (isEqualTo(3.14, 3.14) ? "true" : "false") << std::endl;
    std::cout << "isEqualTo(std::string(\"hello\"), std::string(\"hello\")): "
              << (isEqualTo(std::string("hello"), std::string("hello")) ? "true" : "false") << std::endl;
    std::cout << "isEqualTo(std::string(\"hello\"), std::string(\"world\")): "
              << (isEqualTo(std::string("hello"), std::string("world")) ? "true" : "false") << std::endl;

    ComplexNumber c1(1, 2), c2(1, 2), c3(2, 3);
    std::cout << "isEqualTo(c1, c2): " << (isEqualTo(c1, c2) ? "true" : "false") << " where c1=" << c1 << ", c2=" << c2 << std::endl;
    std::cout << "isEqualTo(c1, c3): " << (isEqualTo(c1, c3) ? "true" : "false") << " where c1=" << c1 << ", c3=" << c3 << std::endl;


    std::cout << "\n--- 1. & 2. StorageBox Class Template and Exception Handling ---" << std::endl;

    // StorageBox for int
    StorageBox<int> intBox;
    std::cout << "intBox is empty? " << (intBox.isEmpty() ? "true" : "false") << std::endl;
    try {
        std::cout << "Attempting to get item from empty intBox..." << std::endl;
        intBox.getItem();
    } catch (const EmptyBoxException& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) { // General fallback
        std::cerr << "Caught std::exception: " << e.what() << std::endl;
    }

    intBox.setItem(123);
    std::cout << "intBox is empty after setItem? " << (intBox.isEmpty() ? "true" : "false") << std::endl;
    try {
        std::cout << "Item in intBox: " << intBox.getItem() << std::endl;
    } catch (const EmptyBoxException& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    intBox.clear();
    std::cout << "intBox is empty after clear? " << (intBox.isEmpty() ? "true" : "false") << std::endl;


    // StorageBox for std::string
    StorageBox<std::string> stringBox;
    stringBox.setItem("Hello Templates!");
    try {
        std::cout << "Item in stringBox: " << stringBox.getItem() << std::endl;
    } catch (const EmptyBoxException& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    // StorageBox for ComplexNumber
    StorageBox<ComplexNumber> complexBox;
    complexBox.setItem(ComplexNumber(5, -2));
    try {
        std::cout << "Item in complexBox: " << complexBox.getItem() << std::endl;
    } catch (const EmptyBoxException& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- `this` pointer and `inline` discussion ---" << std::endl;
    std::cout << "In StorageBox methods like setItem(item), 'item_ = item;' is implicitly 'this->item_ = item'." << std::endl;
    std::cout << "Simple methods like isEmpty(), setItem(), getItem() are good candidates for inlining." << std::endl;
    std::cout << "If defined inside the class template definition, they are implicitly candidates for inlining." << std::endl;


    std::cout << "\n--- Array of StorageBox<int> Objects ---" << std::endl;
    const int ARRAY_SIZE = 3;
    StorageBox<int> intBoxes[ARRAY_SIZE]; // Array of 3 StorageBox<int> objects, default constructed (empty)

    intBoxes[0].setItem(10);
    intBoxes[1].setItem(20);
    // intBoxes[2] remains empty

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Box " << i << ": ";
        if (!intBoxes[i].isEmpty()) {
            try {
                std::cout << "Item = " << intBoxes[i].getItem();
            } catch (const EmptyBoxException& e) {
                // Should not happen if !isEmpty() is true, but good practice
                std::cerr << "Error: " << e.what();
            }
        } else {
            std::cout << "is empty.";
        }
        std::cout << std::endl;
    }

    try {
        std::cout << "Attempting to get item from intBoxes[2] (empty)..." << std::endl;
        std::cout << "Item from intBoxes[2]: " << intBoxes[2].getItem() << std::endl;
    } catch (const EmptyBoxException& e) {
        std::cerr << "Caught Exception for intBoxes[2]: " << e.what() << std::endl;
    }

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}
```

**Explanation of C++ Solution Design:**

1.  **`EmptyBoxException` Class:**

      * Inherits publicly from `std::exception`.
      * Overrides the `what() const noexcept` method to return a specific error message string. This is standard practice for custom exceptions.

2.  **`StorageBox<T>` Class Template:**

      * `template <typename T>` makes it a class template, allowing `T` to be any type.
      * **Private Members:**
          * `T item_`: Stores the item of type `T`.
          * `bool isFull_`: A flag indicating whether the box contains an item.
      * **Default Constructor `StorageBox()`:** Initializes `isFull_` to `false`. `item_` will be default-constructed for type `T` if `T` has a default constructor; otherwise, its state is undefined for fundamental types until `setItem` is called.
      * **`setItem(const T& item)`:**
          * Assigns the passed `item` to the internal `item_` and sets `isFull_` to `true`.
          * **`this` pointer:** Assignments like `item_ = item;` are implicitly `this->item_ = item;`. The `this` pointer refers to the current `StorageBox` object on which `setItem` is called.
          * **`inline`:** As this is a simple assignment function, it's a good candidate for inlining. Since it's defined within the class template definition, it's an implicit candidate for inlining by the compiler.
      * **`T getItem() const`:**
          * Checks `isFull_`. If `false`, it `throw EmptyBoxException();`.
          * Otherwise, it returns `item_`.
          * Marked `const` because it doesn't (and shouldn't) modify the `StorageBox`'s state when returning an item.
          * **`this` pointer:** Accessing `isFull_` and `item_` is implicitly `this->isFull_` and `this->item_`.
          * **`inline`:** Also a candidate for inlining.
      * **`isEmpty() const`:**
          * Returns `!isFull_`.
          * `const` and a strong candidate for `inline`.
      * **`clear()`:** Resets `isFull_` to `false`, effectively emptying the box.

3.  **`isEqualTo<T>(const T& a, const T& b)` Function Template:**

      * `template <typename T>` makes it a function template.
      * It takes two `const` references of type `T` and returns `true` if `a == b`, relying on the `operator==` being defined for whatever type `T` is instantiated with.

4.  **`ComplexNumber` Class:**

      * Added as an example of a user-defined type to be used with `StorageBox` and `isEqualTo`.
      * It overloads `operator==` so that `isEqualTo<ComplexNumber>` works correctly.
      * It also overloads `operator<<` for easy printing.

5.  **`main()` Function:**

      * **`isEqualTo` Demonstration:** Calls `isEqualTo` with `int`, `double`, `std::string`, and `ComplexNumber` to show its generic nature.
      * **`StorageBox` Instantiation:** Creates `StorageBox<int>`, `StorageBox<std::string>`, and `StorageBox<ComplexNumber>`, demonstrating the class template's versatility.
      * **Method Demonstration:** Calls `setItem`, `getItem`, and `isEmpty` on these boxes.
      * **Exception Handling:**
          * A `try-catch` block is used specifically when calling `getItem()` on a potentially empty `intBox`.
          * The `catch (const EmptyBoxException& e)` block catches the specific custom exception.
          * A more general `catch (const std::exception& e)` is shown as a fallback, though `EmptyBoxException` is more specific.
      * **`this` Pointer and `inline` Discussion:** Comments in `main` reiterate how the `this` pointer is implicitly used within `StorageBox` methods and why its simple methods are good candidates for inlining.
      * **Array of Objects `StorageBox<int> intBoxes[ARRAY_SIZE];`:**
          * Declares an array of `StorageBox<int>` objects. Each object in the array is default-constructed (empty).
          * Items are set in some elements of the array.
          * A loop iterates through the array, checking `isEmpty()` and calling `getItem()` (within a try-catch for the potentially empty last element).
          * A specific `try-catch` block demonstrates handling `EmptyBoxException` when accessing an intentionally empty box in the array.

This solution effectively synthesizes generic programming using class and function templates with robust error management via custom exception handling. It also correctly explains and demonstrates the roles of the `this` pointer, potential `inline` usage, and arrays of template objects.