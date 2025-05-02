Lab Exercise
Task 1

A greeting card company wants to automate writing custom messages for users.
Requirements:
• Ask the user for the recipient’s name and a short message.
• Open a file named greeting.txt in write mode.
• Write the message in the format:
"Dear [Name],\n[Message]\nBest Regards!"
Expected Behaviour:
File should contain a clean greeting format every time the program runs.

Task 2

Users want to write diary entries from the keyboard that are saved into a file.
Requirements:
• Accept multiple lines of input using getline() until the user enters "exit".
• Save each line into diary.txt.
• Use appropriate stream handling with ofstream.
Expected Behaviour:
File appends each diary entry and closes gracefully.

Task 3
A university wants a tool to record workshop registrations.
Requirements:
• Take user input: name and email.
• Open signup.txt in append mode.
• Write the data as: "Name: <name>, Email: <email>"
• Repeat for multiple users if needed.
Expected Behaviour:
Old data is preserved, and new entries are appended.

Task 4
You are creating a system that logs every startup.
Requirements:
• Use ios::app to append to system_log.txt.
• Log the message: "System started at: [current time]".
• Use <ctime> to fetch the timestamp.
Expected Behaviour:
No log entries are overwritten. Every run adds a new log line.

Task 5

An e-learning app teaches vocabulary by breaking text into words.
Requirements:
• Read a paragraph from story.txt.
• Print each word on a new line.
• Use getline() and istringstream.
Expected Behaviour:
Words appear one-by-one on the console.

Task 6

A security agency wants a tool to scan encrypted messages for signals.
Requirements:
• Read secret.txt character-by-character.
• Count all uppercase letters.
• Ignore spaces and punctuation.
Expected Behaviour:
Print the count of uppercase letters representing signals.

Task 7

You’re building a system to manage student GPA records securely.
Requirements:
• Define a struct Student with char name[50], int id, float gpa.
• Take input for multiple students.
• Use write() to store data in students.dat.
• Read data back using read() and display it.
Expected Behaviour:
Binary file stores and retrieves accurate student data.

Task 8
A blog reader app lets users jump to the middle of an article.
Requirements:
• Open article.txt in read mode.
• Use seekg() to move to the halfway point.
• Print 10 lines from that position.
Expected Behaviour:
Users can preview the middle of the file.

Task 9

A spell-checker wants to fix the first typo “teh” → “the” in a document.
Requirements:
• Open a file draft.txt.
• Search for “teh”.
• Replace it using seekp() and correct it in-place.
Expected Behaviour:
Only the first instance is corrected, and file structure remains intact.

Task 10

A backup program needs to monitor file size after every log entry.
Requirements:
• Accept log messages from the user.
• Append each to backup_log.txt.
• After every write, display the current file size using tellp().
Expected Behaviour:
User sees how much the file grows with each entry.

Task 11

A content management system analyzes files for quality metrics.
Requirements:
• Read article.txt.
• Count:
o Total characters
o Total words
o Total lines
o Number of punctuation marks
• Save results to report.txt.
Expected Behaviour:
report.txt contains all stats in a formatted report.

Task 12

A file debugger tool lets users jump around a file and inspect contents.
Requirements:
• Allow user to input a byte offset.
• Use seekg() to go there.
• Read and display the next 100 characters.
• Show pointer position before and after.
Expected Behaviour:
Program behaves like a mini file explorer/debugger.