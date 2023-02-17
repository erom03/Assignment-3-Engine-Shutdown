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

    // Sets the current best temperature to the temp
    // made by initial permutation
    for(int i = 0; i < numActions; i++)
        currBest += initial[i];

    // Stores the best permutation as the default
    // (0, 1, 2, ..., N - 1)
    int bestPerm[numActions];
    for(int i = 0; i < numActions; i++)
        bestPerm[i] = i;

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
        // First value has initial value
        if(i == 0)
            currTemp += initial[currPerm[0]];   // This adds the initial temp change of first element in current permutation

        // For subsequent values
    }
}

void printBest(int * bestPerm) {
    for(int i = 0; i < numActions; i++)
        printf("%d ", bestPerm[i]);

    printf("\n");
}