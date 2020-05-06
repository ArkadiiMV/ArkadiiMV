//CS50 Problem Set 3, 2020: Plurality
//Author: ArkadiiMV
// Only bool vote(string name) and void print_winner(void) functions by me
//The rest is distribution code kindly provided by CS50 staff for this problem
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // checking if the candidate is on the list
    // looking for the name in the candidates array

    for (int i = 0; i < candidate_count; i++) 
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // if the candidate is on the ballot - grant the vote and return true
            candidates[i].votes++;
            // just to make sure the votes are counted with due didligence :-))
            // printf("Printing result: candidate %s has %i vote(s)\n", candidates[i].name, candidates[i].votes);
            return true;
        }
    }
    // if the candidate is not on the ballot (imposter detected??) return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //And now the State Election Commission is going to announce a winner (or more)
    // First and foremost we need to find out the max number of votes given to a candidate during the ballot
    int max_votes_given = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes_given)
        {
            max_votes_given = candidates[i].votes;
        }
    }
    
  
    // Now that we have the max number of votes we loop through candidates array
    // and print out all the names that have this big number of votes. 
    // printf("Max number of votes is %i\n", max_votes_given);  
    
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes_given)
        {
            //and the Oscar goes to ...
            printf("%s\n", candidates[i].name); 
            
        }
    }
    
    return;
}

