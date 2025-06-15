The Election Simulator Program is a C-based application that simulates a simplified election process. It is designed for use in environments with a fixed number of candidates and provides a step-by-step, interactive input and result output system. This version supports exactly 5 candidates, allowing users to input candidate IDs, vote counts, confirm data, and view detailed results and winners.

🎯 Features
Interactive console interface for inputting candidate information

Input validation for:

Unique candidate IDs (single letters only)

Vote counts (between 1 and 1000)

Confirmation selection

Calculation and display of:

Vote percentages (rounded to two decimal places)

Winning candidate(s) including tie handling

Friendly and informative prompts and error messages

Fully structured using struct for each candidate

🧠 Technologies & Concepts
This project utilizes core programming concepts including:

Variables and data types

Loops and conditional statements

Functions for modularity

Structs for candidate data abstraction

Input/output formatting


How It Works
The program greets the user.

User is prompted to enter unique IDs for 5 candidates (single characters).

User enters the number of votes each candidate received.

User confirms or corrects the input.

The program calculates vote percentages and announces the winner(s).

In the case of a tie, all top-scoring candidates are congratulated.

The session ends with a thank you message.

