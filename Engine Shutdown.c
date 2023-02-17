#include <stdio.h>

int numActions = 0; // keeps track of number of actions user will do
int currBest = 0;   // keeps track of current best temperature reached

void permute(int * used, int * currPerm, int index, int N, int actions[][numActions], int * bestPerm, int * initial);
void calcTemp(int * currPerm, int actions[][numActions], int * bestPerm, int * initial);
void printBest(int * bestPerm);

int main() {
    // Gets the number of actions requested by user
    scanf("%d", &numActions);

    // Gets the initial temperature change values from
    // original permutation (1, 2, 3, ..., N)
    int initial[numActions];
    for(int i = 0; i < numActions; i++)
        scanf("%d", &initial[i]);

    // Stores the temperature changes doing different 
    // actions in different orders causes 
    int actions[numActions][numActions];
    for(int i = 0; i < numActions; i++) 
        for(int j = 0; j < numActions; j++)
            scanf("%d", &actions[i][j]);

    // THIS NEEDS TO BE FIXED
    // Sets the current best temperature to the temp
    // made by initial permutation
    for(int i = 0; i < numActions; i++)
        currBest += initial[i];

    // Stores the best permutation as the default
    // (0, 1, 2, ..., N - 1)
    int bestPerm[numActions];
    for(int i = 0; i < numActions; i++)
        bestPerm[i] = 0;

    // Used in permutation algorithm
    int used[numActions];       // 0 or 1 representing which values have been used
    int currPerm[numActions];   // The array to hold the values in the permutation
    for(int i = 0; i < numActions; i++)
        used[i] = 0;    // initialize used

    permute(used, currPerm, 0, numActions, actions, bestPerm, initial);

    return 0;
}

void permute(int * used, int * currPerm, int index, int N, int actions[][numActions], int * bestPerm, int * initial) {
    // Check if the index is invalid
    if (N == index) {
        calcTemp(currPerm, actions, bestPerm, initial);

        return; // prevent calling recursively
    }
    
    // Alternatively loop over index
    for (int curValue = 0; curValue < N; curValue++)
    {
        // Check if the value is not allowed
        if (used[curValue]) 
            continue; // skip
        
        // Use the value
        used[curValue] = 1;
        currPerm[index] = curValue;
        // Recurse
        permute(used, currPerm, index + 1, N, actions, bestPerm, initial);
    
        // Unuse the value
        used[curValue] = 0;
    } 

    printBest(bestPerm);
}

void calcTemp(int * currPerm, int actions[][numActions], int * bestPerm, int * initial) {
    int currTemp = 0;
    
    // Scroll through current permutation
    for(int i = 0; i < numActions; i++) {
        // Add initial temp change
        currTemp += initial[currPerm[i]];
        // Check vals before it
        for(int j = i - 1; j >= 0; j--) {
            // Adds the changes in temp that the 
            // current permutation results in
            // currPerm[i] represents the number were currently looking at
            // currPerm[j] represents the prior numbers in currPerm
            currTemp += actions[currPerm[i]][currPerm[j]];
        }
    }

    // Check if the current temp is the best one
    // If it is, set best permutation to the current one
}

void printBest(int * bestPerm) {
    for(int i = 0; i < numActions; i++)
        printf("%d ", bestPerm[i]);

    printf("\n");
}