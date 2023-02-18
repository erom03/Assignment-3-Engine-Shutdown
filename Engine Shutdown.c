#include <stdio.h>

int numActions = 0; // keeps track of number of actions user will do
int bestTemp = 0;   // keeps track of current best temperature reached

void permute(int * used, int * currPerm, int index, int N, int actions[][numActions], int * bestPerm, int * initial);
void calcTemp(int * currPerm, int actions[][numActions], int * bestPerm, int * initial);
void printPerm(int * bestPerm);

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

    printPerm(bestPerm);

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
    
    // Check if the current temp is lower than the best temp
    if(currTemp < bestTemp) {
        // Set best temp to the current temp
        bestTemp = currTemp;
        
        // Set best permutation to current perm
        for(int i = 0; i < numActions; i++)
            bestPerm[i] = currPerm[i];
    }
}

void printPerm(int * bestPerm) {
    for(int i = 0; i < numActions; i++)
        printf("%d ", bestPerm[i] + 1);

    printf("\n");
}