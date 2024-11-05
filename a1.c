//---------------------------------------------------------------------------------------------------------------------
// Program that takes in Candidates Data and just calculates election results!
// Very simple program written in C
//
// Tutor: <not assigned yet>
//
// Milos Dukaric: <12225387>
//---------------------------------------------------------------------------------------------------------------------
//

#include <stdio.h>
#include <ctype.h>

#define NUM_CANDIDATES 5

typedef struct _CandidatesData_ 
{
  char id_;
  int votes_;
} CandidatesData;


//---------------------------------------------
// Function that checks if id is a unique one
//---------------------------------------------

int is_Unique(char id_, CandidatesData candidate[], int count) {
  for (int i = 0; i < count; i++) {
    if (candidate[i].id_ == id_) {
      return 0;
    }
  }
  return 1;
}

//---------------------------------------------
// Function that calculates election results
//---------------------------------------------

void election_Results(CandidatesData candidate[], int count) {
  int total_votes_ = 0;

  for (int i = 0; i < count; i++) {
    total_votes_ += candidate[i].votes_;
  }

  printf("\nThe results of the election are:\n");

  for (int i = 0; i < count; i++) {
    double percentage = total_votes_ > 0 ? ((double)candidate[i].votes_ / total_votes_) * 100 : 0;
    printf(" - Candidate \"%c\": %.2f %% (%d votes).\n", candidate[i].id_, percentage, candidate[i].votes_);
  }
}

//---------------------------------------------
// Function that announces the winner
//---------------------------------------------

void winners_Announcment(CandidatesData candidate[], int count) {
  int max_votes_ = 0;
  int tied_candidates_ = 0;

  for (int i = 0; i < count; i++) {
    if (candidate[i].votes_ > max_votes_) {
      max_votes_ = candidate[i].votes_;
    }
  }

  for (int i = 0; i < count; i++) {
    if (candidate[i].votes_ == max_votes_) {
      tied_candidates_++;
    }
  }

  printf("\nPlease congratulate the winner(s) of the election:\n");

  for (int i = 0; i < count; i++) {
    if (candidate[i].votes_ == max_votes_) {
      printf(" - Candidate \"%c\"!\n", candidate[i].id_);
    }
  }

  if (tied_candidates_ > 1) {
    printf("\nThat's a %d-way tie!\n", tied_candidates_);
  }
}

//---------------------------------------------
// Function to collect candidate IDs
//---------------------------------------------

void input_Candidate_Ids(CandidatesData candidate[]) {
  char input_;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    while (1) {
      printf("\nPlease enter an ID for candidate %d! (single letter only)\n > ", i + 1);
      scanf(" %c", &input_);

      if (isalpha(input_) && is_Unique(input_, candidate, i)) {
        candidate[i].id_ = input_;
        break;
      } else if (!isalpha(input_)) {
        printf("[Error] This input is out of bounds!\n");
      } else {
        printf("[Error] This ID is already in use!\n");
      }
      while (getchar() != '\n'); // Clears the buffer
    }
  }
}

//---------------------------------------------
// Function to collect votes for each candidate
//---------------------------------------------

void input_Candidate_Votes(struct _CandidatesData_ candidate[]) {
  int votes_;
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    while (1) {
      printf("\nPlease enter the amount of votes for candidate \"%c\"! (1 to 1000)\n > ", candidate[i].id_);
      if (scanf("%d", &votes_) == 1 && votes_ >= 1 && votes_ <= 1000) {
        candidate[i].votes_ = votes_;
        break;
      } else {
        printf("[Error] This input is out of bounds!\n");
        while (getchar() != '\n');  // Clears the buffer
      }
    }
  }
}

//---------------------------------------------
// Function to confirm vote input
//---------------------------------------------

int confirm_Input(void) {
  int confirm_;
  while (1) {
    printf("\nAre you sure the input is correct?\n 1. Yes\n 2. No\n > ");
    if (scanf("%d", &confirm_) == 1 && (confirm_ == 1 || confirm_ == 2)) {
      return confirm_ == 1;
    } else {
      printf("[Error] This input is out of bounds!\n");
      while (getchar() != '\n');  // Clears the buffer
    }
  }
}

//---------------------------------------------
// Calling all functions in my main function
//---------------------------------------------

int main(void) {
  printf("Welcome to the Election Simulator Program!\n");

  CandidatesData candidate[NUM_CANDIDATES];

  input_Candidate_Ids(candidate);

  while (1) {
    input_Candidate_Votes(candidate);

    if (confirm_Input()) {
      break;  
    }
  }

  election_Results(candidate, NUM_CANDIDATES);
  winners_Announcment(candidate, NUM_CANDIDATES);

  printf("\nThank you for using the Election Simulator Program!\n");

  return 0;
} 
