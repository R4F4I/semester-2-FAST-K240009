# Lab 9 - Object-Oriented Programming Assignments

## Task 01: Vehicle Rental System
**Problem**: A vehicle rental company needs a flexible system to manage cars, bikes, and future vehicle types. The system should handle daily rates and display vehicle details without exposing internal calculations. New vehicle types (e.g., scooters, trucks) should integrate seamlessly.

### Classes and Structure:
- **Abstract Class `Vehicle`**:
  - **Data Members**:
    - `model` (string): Vehicle’s model name.
    - `rate` (double): Daily rental rate.
  - **Member Functions**:
    - `getDailyRate()`: Pure virtual function to return the daily rate.
    - `displayDetails()`: Pure virtual function to show model and rate.
- **Derived Class `Car`**:
  - Inherits `Vehicle`.
  - Overrides `getDailyRate()` and `displayDetails()` for car-specific behavior.
- **Derived Class `Bike`**:
  - Inherits `Vehicle`.
  - Overrides `getDailyRate()` and `displayDetails()` for bike-specific behavior.

### Flow:
1. Create `Car` and `Bike` objects.
2. Use polymorphism to call `displayDetails()` and `getDailyRate()` for each vehicle.

---

## Task 02: Smart Home Devices
**Problem**: A homeowner wants a unified system to control smart lights and thermostats from different brands. The system should allow turning devices on/off, adjusting settings, and checking statuses. Future devices (e.g., smart locks) should integrate seamlessly.

### Classes and Structure:
- **Abstract Class `SmartDevice`**:
  - **Member Functions**:
    - `turnOn()`: Pure virtual function to activate the device.
    - `turnOff()`: Pure virtual function to deactivate the device.
    - `getStatus()`: Pure virtual function to return the device’s current state.
- **Derived Class `LightBulb`**:
  - **Data Members**:
    - `isOn` (bool): Tracks if the light is on/off.
    - `brightness` (int): Brightness level (0-100%).
  - Implements `turnOn()`, `turnOff()`, and `getStatus()` for light control.
- **Derived Class `Thermostat`**:
  - **Data Members**:
    - `isOn` (bool): Tracks if the thermostat is active.
    - `temperature` (double): Current temperature setting.
  - Implements `turnOn()`, `turnOff()`, and `getStatus()` for temperature control.

### Flow:
1. Create `LightBulb` and `Thermostat` objects.
2. Turn devices on/off and display their statuses.

---

## Task 03: Library Management System
**Problem**: A library needs a digital system to securely manage book records (title, author, ISBN). Staff should access book details without modifying records directly. The system should separate public interfaces (e.g., searching books) from internal data handling.

### Classes and Structure:
- **Class `Book`**:
  - **Data Members**:
    - `title`, `author`, `ISBN` (strings): Book metadata.
  - **Member Functions**:
    - Constructor to initialize book details.
    - `getTitle()`, `getAuthor()`, `getISBN()`: Return book properties.
- **Class `Library`** (Optional):
  - **Data Members**:
    - A collection (e.g., array/list) of `Book` objects.
  - **Member Functions**:
    - `addBook()`, `removeBook()`, `searchBook()`: Manage the collection.

### Flow:
1. Define `Book` in header and source files.
2. In `main()`, create a `Book` object and display its metadata.

---

## Task 04: Payment System
**Problem**: An e-commerce platform needs a system to support multiple payment methods (credit cards, digital wallets). The system must validate transactions securely and allow adding new payment options (e.g., cryptocurrency) without rewriting existing code.

### Classes and Structure:
- **Abstract Class `PaymentMethod`**:
  - **Member Function**:
    - `processPayment(double amount)`: Pure virtual function to handle transactions.
- **Derived Class `CreditCard`**:
  - **Data Members**:
    - `cardNumber` (string): Stores the card number.
  - Implements `processPayment()` to validate and process payments.
- **Derived Class `DigitalWallet`**:
  - **Data Members**:
    - `balance` (double): Tracks available funds.
  - Implements `processPayment()` to deduct balance.

### Flow:
1. Create `CreditCard` and `DigitalWallet` objects.
2. Simulate payments and check for success/failure.

---

## Task 05: Fitness App
**Problem**: A fitness app needs to track calories burned during activities like running and cycling. Each activity requires unique calculations (e.g., distance vs. speed). The system should allow adding new activities (e.g., swimming) in the future.

### Classes and Structure:
- **Abstract Class `Activity`**:
  - **Member Function**:
    - `calculateCaloriesBurned()`: Pure virtual function to compute calories.
- **Derived Class `Running`**:
  - **Data Members**:
    - `distance` (double): Distance in kilometers.
    - `time` (double): Duration in minutes.
  - Implements `calculateCaloriesBurned()` for running.
- **Derived Class `Cycling`**:
  - **Data Members**:
    - `speed` (double): Speed in km/h.
    - `time` (double): Duration in hours.
  - Implements `calculateCaloriesBurned()` for cycling.

### Flow:
1. Create `Running` and `Cycling` objects.
2. Display calories burned for each activity.