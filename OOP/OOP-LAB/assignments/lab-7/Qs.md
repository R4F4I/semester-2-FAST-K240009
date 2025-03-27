## Task 02
Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various geometric shapes. The system is structured around a `Shape` class, which includes data members such as `position`, `color`, and an optional `borderThickness`. It provides functions like:

- `draw()` for rendering.
- `calculateArea()` for area measurement.
- `calculatePerimeter()` for perimeter computation.

### Derived Classes:
- **Circle**: Includes `radius` and `center position`.
- **Rectangle**: Includes `width`, `height`, and `top-left corner position`.
- **Triangle** and **Polygon**: Introduce their own properties.

Each derived class overrides `draw()`, `calculateArea()`, and `calculatePerimeter()` to handle their respective geometries.

---

## Task 03
Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies with real-time conversion capabilities. This system is built on a base class called `Currency`, which contains core data members such as:

- `amount`
- `currencyCode`
- `currencySymbol`
- An optional `exchangeRate`

### Functions:
- `convertToBase()`: Converts the amount into a common base currency.
- `convertTo(targetCurrency)`: Converts between currencies.
- `displayCurrency()`: Showcases currency details.

### Derived Classes:
- **Dollar**
- **Euro**
- **Rupee**

These classes extend the foundation by introducing currency-specific details and overriding `convertToBase()` and `displayCurrency()` to reflect exchange rates and regional currency formats dynamically.

---

## Task 04
Imagine designing a digital management system for a large university that seamlessly integrates academic and administrative operations. At the heart of this system is a `Person` class that stores universal data members such as:

- `name`
- `id`
- `address`
- `phoneNumber`
- `email`

### Functions:
- `displayInfo()`: Shows personal details.
- `updateInfo()`: Modifies personal details.

### Derived Classes:
- **Student**: Includes `coursesEnrolled`, `GPA`, and `enrollmentYear`. Modifies `displayInfo()` to show academic records.
- **Professor**: Includes `department`, `coursesTaught`, and `salary`. Updates `displayInfo()` to display faculty-specific details.
- **Staff**: Maintains `department`, `position`, and `salary`. Tailors `displayInfo()` to reflect administrative roles.

### Additional Class:
- **Course**: Attributes include:
  - `courseId`
  - `courseName`
  - `credits`
  - `instructor`
  - `schedule`

Functions:
- `registerStudent(student)`
- `calculateGrades()`

This ensures an interactive system where function overrides enable dynamic role-based management.

---

## Task 05
Visualize a digital multimedia library management system designed to catalog and circulate a diverse range of media items, including books, DVDs, CDs, and magazines. The `Media` class serves as the base, encapsulating core data members such as:

- `title`
- `publicationDate`
- `uniqueID`
- `publisher`

### Functions:
- `displayInfo()`: Outputs media details.
- `checkOut()`: Processes lending.
- `returnItem()`: Handles returns.

### Derived Classes:
- **Book**: Includes `author`, `ISBN`, and `numberOfPages`. Modifies `displayInfo()` for books.
- **DVD**: Incorporates `director`, `duration`, and `rating`. Updates `displayInfo()` for movie details.
- **CD**: Includes `artist`, `numberOfTracks`, and `genre`. Adapts `displayInfo()` for music albums.
- **Magazine**: Adds magazine-specific attributes.

### Additional Features:
The system supports function overloading for searching media by different attributes (e.g., `title`, `author`, or `publication year`).