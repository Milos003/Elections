# Assignment 1 - Election Simulator Program

## Introduction

In Assignment 1 (A1) of the ESP practicals (KU), you will implement a program that simulates an election. There are 
always **5 candidates** and the program should automatically calculate the winner(s).

This document describes the structure of the assignment and the expected functionality of the program.

## Learning Goals

Variables, Data Types, Functions, Conditional Statements (If - Else), Loops, Structs

## Specification

There are some general specifications that must be followed for every assignment in this course. A list of these and which point deductions
may result from violating them can be found here:
[Assessment of Assignments - Deductions](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3?pvs=4#e3203e50b1fc4ba787bdbf5fb46262ae)

Additionally, the following specification must be followed for this assignment (A1) as well:
- **Attention:** Each candidate must be represented as a struct. If the candidates are not represented as structs, this will result in a deduction of **up to -25 %**.

## Grading

Assignment 1 is worth **12 points**.

Information on how your assignment submission will be assessed can be found here: [Assessment of Assignments](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3).
Please read this carefully as it also contains guidelines on what your final code should look like (Coding Standard, Style Guide).

Here you can find an overview of how your total grade for the KU will be calculated: [Procedure and Grading](https://www.notion.so/coding-tugraz/Procedure-and-Grading-59975fee4a9c4047867772cd20caf73d)

## Submission

- Deliverables: `a1.c`
- Push to your repository
- **Deadline: 06.11.2024 23:59 (Austrian time)**

## Weekly Exercises

There are **Weekly Exercises** associated with this assignment. These exercises are provided on the 
[onlineGDB](https://www.onlinegdb.com/) website.
These are simple exercises meant to help you practice before starting the assignment, and **must** be solved at least 
partially to avoid deductions. Take a look at our [Guide for onlineGDB](https://www.notion.so/coding-tugraz/Guide-for-onlineGDB-c8a3d7e6b5d24b569a6f85593c0c9d75) for information on how to 
register and solve the exercises. 

**Please pay close attention to the instructions about choosing a username!** If you 
do not use the correct username, we won't be able to identify your solutions.  

- **Attention**: It is mandatory to correctly solve at least 50 % of the exercises tagged with [A1] before the A1 
 deadline. Otherwise, you will receive a **point deduction of -25 % on A1**.

## Assignment Description

This program implements a simplified election simulator. There are always 5 candidates that can be voted for. The user has to choose an ID for each candidate, input the number of votes each candidate received, and confirm the input. Afterwards,
the program will calculate the percentage of votes for each candidate, and congratulate the candidate(s) with the most votes.

### General Notes

The notes given in this section are important for the entire assignment description.

- `\n` shouldn't be printed as two separate characters, instead they represent the newline character.
- Note that leading and trailing spaces in the text fields are not visible. You can make them visible by 
  selecting the text field.
- Words in angle brackets (like `<NUMBER>`) should be replaced by calculated or given data. They are *not* part of the output itself! For a better understanding you can look at the [example outputs](#example-outputs).
- In the testcases of this assignment, when a character is expected only characters will be tested. When an integer is expected, only integers will be tested. However, it is possible that values outside the specified valid ranges may occur.
- <code>&nbsp;>&nbsp;</code> (command prompt, always printed with a leading and trailing space) in the output indicates that the program waits for a user input at this point. Execution should only continue after the user has ended the input with `ENTER`.
- If the user's input is invalid, the corresponding error message should be printed. After this, the question 
  (including any newlines and options) and the command prompt are printed again, and the user can make a new input. 
  This process is repeated as long as the input is invalid.

## Program Sequence

### Welcome

When starting the program the following message should be printed in order to welcome the user: 

```
Welcome to the Election Simulator Program!\n
```

### Candidate Number

Internally each candidate is assigned a number. There are always 5 candidates and the numbering starts with candidate `1`.
This order is important as it determines in what order the IDs are assigned, the votes are put in, the results are shown and the winners are displayed.

### User Input: Candidate ID

As the next step the user chooses an ID for each candidate in order of their candidate number. Valid inputs are single letters (`a-z`, `A-Z`).

```
\n
Please enter an ID for candidate <NUMBER>! (single letter only)\n
 > 
```

`<NUMBER>` should be replaced by the current candidate number `1-5`.

If the ID has already been used, the following error message should be printed:

```
[Error] This ID is already in use!\n
```
> **Attention:** Upper case and lower case letters do not count as the same letter.

If the user's input is not a letter (`a-z`, `A-Z`), the following error message should be printed:

```
[Error] This input is out of bounds!\n
```

> **Hint:** Only inputs consisting of single characters will be tested.

After the corresponding error message, the question (including all newlines) and the command prompt is printed again and the user can make a new input. This process is repeated as long as the input is invalid.

### User Input: Candidate Votes

After choosing IDs for each candidate, the user has to input how many votes each candidate received in order of their candidate number. Valid inputs are integers bigger or equal to `1` and smaller or equal to `1000`.

```
\n
Please enter the amount of votes for candidate "<ID>"! (1 to 1000)\n
 > 
```

`<ID>` should be replaced by the candidate's ID.

If the user's input is outside the specified valid integer range, the following error message should be printed:

```
[Error] This input is out of bounds!\n
```

After the error message, the question (including all newlines) and the command prompt is printed again and the user can make a new input. This process is repeated as long as the input is invalid.


### User Input: Confirmation

In order to set the inputs to valid, the user's confirmation is needed. Valid inputs are `1` or `2`.

```
\n
Are you sure the input is correct?\n
 1. Yes\n
 2. No\n
 > 
```

If the input is `2`, the program should prompt for the number of votes for each candidate again as described in [User Input: Candidate Votes](#user-input-candidate-votes) and continue from there.
If the input is `1`, the program should continue on to [Election Results](#election-results).

If the user's input is not `1` or `2`, the following error message should be printed:

```
[Error] This input is out of bounds!\n
```

After the error message, the question (including all newlines and the options) and the command prompt is printed again and the user can make a new input. This process is repeated as long as the input is invalid.


### Election Results

After acquiring all the votes and ensuring they are valid, the program should then calculate the results of the election.

```
\n
The results of the election are:\n
 - Candidate "<C1_ID>": <C1_PERCENTAGE> % (<C1_VOTES> votes).\n
 - Candidate "<C2_ID>": <C2_PERCENTAGE> % (<C2_VOTES> votes).\n
 - Candidate "<C3_ID>": <C3_PERCENTAGE> % (<C3_VOTES> votes).\n
 - Candidate "<C4_ID>": <C4_PERCENTAGE> % (<C4_VOTES> votes).\n
 - Candidate "<C5_ID>": <C5_PERCENTAGE> % (<C5_VOTES> votes).\n
```

The candidates should be printed in order of their candidate number.
```<CX_ID>``` should replaced by the candidate's ID. ```<CX_VOTES>``` should be replaced by the candidate's number of votes.
```<CX_PERCENTAGE>``` should be replaced by percentage of votes in relation to the total number of votes.
All percentages should be printed with two decimal places.

> **Hint**: `printf` takes care of the rounding for you.

### Announcement of Winners

Now it's time to congratulate the winner(s). If there is a tie, every candidate that received the highest number of votes should be printed in order of their candidate number.

```
\n
Please congratulate the winner(s) of the election:\n
 - Candidate "<WX_ID>"!\n
<...>
```

```<WX_ID>``` should be replaced by the candidate's ID. ```<...>``` is a placeholder for additional lines if there are multiple winners.

If ```2``` or ```more``` candidates received the highest number of votes the program should output a corresponding message.

```
\n
That's a <NUMBER_OF_TIED_CANDIDATES>-way tie!\n
```

```<NUMBER_OF_TIED_CANDIDATES>``` should be replaced by the amount of candidates that are tied as an integer.

### Finish

Finally the program should print the following message:

```
\n
Thank you for using the Election Simulator Program!\n
```

In the end the program terminates with return value `0`.

## Example Outputs

<details>
<summary><h3>Example Output 1</h3></summary>

```
Welcome to the Election Simulator Program!

Please enter an ID for candidate 1! (single letter only)
 > a

Please enter an ID for candidate 2! (single letter only)
 > b

Please enter an ID for candidate 3! (single letter only)
 > c

Please enter an ID for candidate 4! (single letter only)
 > d

Please enter an ID for candidate 5! (single letter only)
 > e

Please enter the amount of votes for candidate "a"! (1 to 1000)
 > 1

Please enter the amount of votes for candidate "b"! (1 to 1000)
 > 2

Please enter the amount of votes for candidate "c"! (1 to 1000)
 > 3

Please enter the amount of votes for candidate "d"! (1 to 1000)
 > 4

Please enter the amount of votes for candidate "e"! (1 to 1000)
 > 5

Are you sure the input is correct?
 1. Yes
 2. No
 > 1

The results of the election are:
 - Candidate "a": 6.67 % (1 votes).
 - Candidate "b": 13.33 % (2 votes).
 - Candidate "c": 20.00 % (3 votes).
 - Candidate "d": 26.67 % (4 votes).
 - Candidate "e": 33.33 % (5 votes).

Please congratulate the winner(s) of the election:
Candidate "e"!

Thank you for using the Election Simulator Program!
```
</details>

<details>
<summary><h3>Example Output 2</h3></summary>

```
Welcome to the Election Simulator Program!

Please enter an ID for candidate 1! (single letter only)
 > A

Please enter an ID for candidate 2! (single letter only)
 > A
[Error] This ID is already in use!

Please enter an ID for candidate 2! (single letter only)
 > B

Please enter an ID for candidate 3! (single letter only)
 > C

Please enter an ID for candidate 4! (single letter only)
 > D

Please enter an ID for candidate 5! (single letter only)
 > E

Please enter the amount of votes for candidate "A"! (1 to 1000)
 > 175

Please enter the amount of votes for candidate "B"! (1 to 1000)
 > 120

Please enter the amount of votes for candidate "C"! (1 to 1000)
 > 150

Please enter the amount of votes for candidate "D"! (1 to 1000)
 > 175

Please enter the amount of votes for candidate "E"! (1 to 1000)
 > 100

Are you sure the input is correct?
 1. Yes
 2. No
 > 1

The results of the election are:
 - Candidate "A": 24.31 % (175 votes).
 - Candidate "B": 16.67 % (120 votes).
 - Candidate "C": 20.83 % (150 votes).
 - Candidate "D": 24.31 % (175 votes).
 - Candidate "E": 13.89 % (100 votes).

Please congratulate the winner(s) of the election:
 - Candidate "A"!
 - Candidate "D"!

That's a 2-way tie!

Thank you for using the Election Simulator Program!
```

</details>
