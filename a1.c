#include <stdio.h>
#include <ctype.h>

struct CandidatesIDs {
    char id;
    int votes;
};


int is_unique(char id, struct CandidatesIDs candidate[], int count) {
    for (int i = 0; i < count; i++) {
        if (candidate[i].id == id) {
            return 0;
        }
    }
    return 1;
}


void election_results(struct CandidatesIDs candidate[], int count) {
    int total_votes = 0;

 
    for (int i = 0; i < count; i++) {
        total_votes += candidate[i].votes;
    }

    printf("\nThe results of the election are:\n");

    
    for (int i = 0; i < count; i++) {
        double percentage = ((double)candidate[i].votes / total_votes) * 100;
        printf(" - Candidate \"%c\": %.2f %% (%d votes).\n", candidate[i].id, percentage, candidate[i].votes);
    }
}


void winners(struct CandidatesIDs candidate[], int count) {
    int max_votes = 0;
    int tied_candidates = 0;

  
    for (int i = 0; i < count; i++) {
        if (candidate[i].votes > max_votes) {
            max_votes = candidate[i].votes;
        }
    }

 
    for (int i = 0; i < count; i++) {
        if (candidate[i].votes == max_votes) {
            tied_candidates++;
        }
    }

    printf("\nPlease congratulate the winner(s) of the election:\n");

    
    for (int i = 0; i < count; i++) {
        if (candidate[i].votes == max_votes) {
            printf(" - Candidate \"%c\"!\n", candidate[i].id);
        }
    }

    
    if (tied_candidates > 1) {
        printf("\nThat's a %d-way tie!\n", tied_candidates);
    }
}

int main(void) {
    printf("Welcome to the Election Simulator Program!\n");

    struct CandidatesIDs candidate[5];
    char input;

    
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("\nPlease enter an ID for candidate %d! (single letter only)\n > ", i + 1);
            scanf(" %c", &input);
            while (getchar() != '\n');

            if (isalpha(input)) {
                if (is_unique(input, candidate, i)) {
                    candidate[i].id = input;
                    break;
                } else {
                    printf("[Error] This ID is already in use!\n");
                }
            } else {
                printf("[Error] This input is out of bounds!\n");
            }
        }
    }

    
    while (1) {
        for (int i = 0; i < 5; i++) {
            int votes;
            while (1) {
                printf("\nPlease enter the amount of votes for candidate \"%c\"! (1 to 1000)\n > ", candidate[i].id);
                if (scanf("%d", &votes) != 1) {
                    printf("[Error] This input is out of bounds!\n");
                    while (getchar() != '\n');  
                    continue;
                }

                if (votes >= 1 && votes <= 1000) {
                    candidate[i].votes = votes;
                    break;
                } else {
                    printf("[Error] This input is out of bounds!\n");
                }
            }
        }

        int confirm;
        printf("\nAre you sure the input is correct?\n 1. Yes\n 2. No\n > ");

        if (scanf("%d", &confirm) != 1) {
            printf("[Error] This input is out of bounds!\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (confirm == 1) {
            break;
        } else if (confirm == 2) {
            continue;
        } else {
            printf("[Error] This input is out of bounds!\n");
            while (getchar() != '\n'); 
            continue;
        }
    }

    
    election_results(candidate, 5);
    winners(candidate, 5);

    printf("\nThank you for using the Election Simulator Program!\n");

    return 0;
}
