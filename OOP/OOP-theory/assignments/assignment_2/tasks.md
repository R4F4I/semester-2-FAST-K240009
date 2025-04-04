# Scenario # 2: Haunted House Simulation Game

### Overview:
Simulate a Haunted House-based game where users can:
- Create multiple Haunted Houses with ghosts of their choice.
- Run simulations to evaluate visitor experience and scares.

### Entities Involved:
1. **HauntedHouse**:
   - Attributes: Name, multiple ghosts.
   - Ensure runtime polymorphism.

2. **Ghost**:
   - Superclass for all types of ghosts.
   - Attributes:
     - Name of the worker playing the ghost.
     - Scare level (RNG 1-10).
   - Functions:
     - Perform haunting.
     - Operator overloading:
       - `<<` operator: Display ghost information.
       - `+` operator: Upgrade a ghost (combine two ghosts into one with combined scare levels).

3. **Types of Ghosts**:
   - **Poltergeists**: Move objects.
   - **Banshees**: Scream loudly.
   - **ShadowGhosts**: Whisper creepily.
   - **Hybrid Ghosts**:
     - Example: ShadowPoltergeist (combines actions of ShadowGhost and Poltergeist).

4. **Visitor**:
   - Attributes:
     - Name.
     - Bravery level (1-10):
       - 1-4: Cowardly.
       - 5-7: Average.
       - 8-10: Fearless.
   - Behavior:
     - Ghosts haunt visitors.
     - Reactions depend on scare level vs bravery range:
       - Scare level < bravery range: Visitor laughs or taunts the ghost.
       - Scare level > bravery range: Visitor screams or runs away.
       - Scare level ≈ bravery range: Visitor gets a shaky voice.
     - **Important**: Check if scare level lies within bravery range (do not compare numbers directly).

### Main Method:
- Create 2-3 Haunted Houses with multiple ghosts of each type.
- Create an array of Visitors (group of friends visiting the Haunted House):
  - Ensure at least one visitor of each bravery level.
- Implement a global friend function `Visit`:
  - Accepts Visitors array and a Haunted House.
  - Simulates the visit for each Haunted House.

---

# Scenario # 3: Ramzan Box Delivery System

### Overview:
A futuristic AI-driven delivery company, **RamzanBox**, specializes in delivering food and supplies during Ramzan using:
- Autonomous drones.
- Time-traveling delivery ships.
- High-speed ground pods.

### System Features:
1. **Vehicle Class**:
   - Base class for all delivery vehicles.
   - Attributes:
     - Unique vehicle ID.
     - Static variable: Total number of active deliveries.
   - Functions:
     - Calculate optimal delivery route.
     - Determine estimated delivery time.

2. **Specialized Vehicles**:
   - **RamzanDrone**:
     - Small, fast, airborne.
     - Optimized for iftar meal deliveries.
   - **RamzanTimeShip**:
     - Ensures historical accuracy for time-sensitive deliveries.
   - **RamzanHyperPod**:
     - High-speed underground transport for bulk deliveries.

3. **AI Decision-Making System**:
   - Each vehicle follows a unique movement strategy:
     - **RamzanDrone**: Calculates aerial routes.
     - **RamzanTimeShip**: Verifies historical consistency.
     - **RamzanHyperPod**: Navigates underground tunnels.
   - Override a general movement function for unique operational logic.

4. **Operator Control Panel**:
   - Issue delivery commands:
     - `command("Deliver", packageID);`
     - `command("Deliver", packageID, urgencyLevel);`
   - Interpretation of "urgent" varies by vehicle:
     - **RamzanTimeShip**: Treats as historically sensitive.
     - **RamzanDrone**: Activates high-speed mode for timely iftar delivery.

5. **AI Conflict Resolution System**:
   - Resolves disagreements between AI systems on delivery priority.
   - Features:
     - Friend function: Access private attributes to compare vehicles.
     - Overloaded `==` operator: Compare vehicles based on speed, capacity, and energy efficiency.

---

# Scenario # 4: University Lab Management System

### Overview:
A system to manage different types of users in a university lab:
- **Students**: Access tools and complete assignments.
- **Teaching Assistants (TAs)**: Monitor students and assist in labs.
- **Professors**: Assign projects and manage research.

### Permissions:
- **STUDENT**: Submit assignments.
- **TA**: View projects, manage students.
- **PROFESSOR**: Assign projects, full lab access.

### Global Functions:
1. **Password Hashing**:
   - Formula: `hash = 5381`
   - Calculation: `hash * 33 + c` (where `c` is a single character).

2. **Authentication**:
   - `authenticateAndPerformAction(User* user, string action)`:
     - Authenticates the user.
     - Performs actions based on user roles and permissions.

### Class Structure:
1. **User Class**:
   - Attributes:
     - Name, ID, list of permissions, email, hashed password.
   - Functions:
     - Parameterized constructor: Set attributes and hash passwords.
     - `authenticate`: Authenticate based on password.
     - `display`: Display user information.
     - `accessLab`: Check permissions and provide lab access.

2. **Student Class** (Derived from User):
   - Overrides `display` function.
   - Attributes:
     - List of assignments (status: 0 = not submitted, 1 = submitted).
   - Functions:
     - Submit assignments and update status.

3. **TA Class** (Derived from Student):
   - Overrides `display` function.
   - Attributes:
     - List of assigned students (max: 10).
     - List of projects (max: 2).
   - Functions:
     - View/start projects.
     - Assign/manage students (permission-based).

4. **Professor Class** (Derived from User):
   - Overrides `display` function.
   - Functions:
     - Work with TAs on projects (max: 2 projects per TA).

### Implementation:
- Create objects for all classes.
- Call `display` and `authenticate` functions as needed.