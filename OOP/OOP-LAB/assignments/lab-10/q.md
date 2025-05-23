# Lab Exercise

## Task 1: Greeting Card Automation

**Requirements:**
- Ask the user for the recipient’s name and a short message.
- Open a file named `greeting.txt` in write mode.
- Write the message in the format:
    ```
    Dear [Name],
    [Message]
    Best Regards!
    ```

**Expected Behaviour:**
- The file should contain a clean greeting format every time the program runs.

---

## Task 2: Diary Entry Writer

**Requirements:**
- Accept multiple lines of input using `getline()` until the user enters `"exit"`.
- Save each line into `diary.txt`.
- Use appropriate stream handling with `ofstream`.

**Expected Behaviour:**
- The file appends each diary entry and closes gracefully.

---

## Task 3: Workshop Registration Tool

**Requirements:**
- Take user input: name and email.
- Open `signup.txt` in append mode.
- Write the data as:
    ```
    Name: <name>, Email: <email>
    ```
- Repeat for multiple users if needed.

**Expected Behaviour:**
- Old data is preserved, and new entries are appended.

---

## Task 4: System Startup Logger

**Requirements:**
- Use `ios::app` to append to `system_log.txt`.
- Log the message:
    ```
    System started at: [current time]
    ```
- Use `<ctime>` to fetch the timestamp.

**Expected Behaviour:**
- No log entries are overwritten. Every run adds a new log line.

---

## Task 5: Vocabulary Builder

**Requirements:**
- Read a paragraph from `story.txt`.
- Print each word on a new line.
- Use `getline()` and `istringstream`.

**Expected Behaviour:**
- Words appear one-by-one on the console.

---

## Task 6: Encrypted Message Scanner

**Requirements:**
- Read `secret.txt` character-by-character.
- Count all uppercase letters.
- Ignore spaces and punctuation.

**Expected Behaviour:**
- Print the count of uppercase letters representing signals.

---

## Task 7: Student GPA Records Manager

**Requirements:**
- Define a struct `Student` with:
    ```cpp
    char name[50];
    int id;
    float gpa;
    ```
- Take input for multiple students.
- Use `write()` to store data in `students.dat`.
- Read data back using `read()` and display it.

**Expected Behaviour:**
- Binary file stores and retrieves accurate student data.

---

## Task 8: Blog Reader Preview

**Requirements:**
- Open `article.txt` in read mode.
- Use `seekg()` to move to the halfway point.
- Print 10 lines from that position.

**Expected Behaviour:**
- Users can preview the middle of the file.

---

## Task 9: Spell Checker

**Requirements:**
- Open a file `draft.txt`.
- Search for `"teh"`.
- Replace it using `seekp()` and correct it in-place.

**Expected Behaviour:**
- Only the first instance is corrected, and the file structure remains intact.

---

## Task 10: Backup Program with File Size Monitoring

**Requirements:**
- Accept log messages from the user.
- Append each to `backup_log.txt`.
- After every write, display the current file size using `tellp()`.

**Expected Behaviour:**
- User sees how much the file grows with each entry.

---

## Task 11: File Quality Metrics Analyzer

**Requirements:**
- Read `article.txt`.
- Count:
    - Total characters
    - Total words
    - Total lines
    - Number of punctuation marks
- Save results to `report.txt`.

**Expected Behaviour:**
- `report.txt` contains all stats in a formatted report.

---

## Task 12: File Debugger Tool

**Requirements:**
- Allow user to input a byte offset.
- Use `seekg()` to go there.
- Read and display the next 100 characters.
- Show pointer position before and after.

**Expected Behaviour:**
- Program behaves like a mini file explorer/debugger.