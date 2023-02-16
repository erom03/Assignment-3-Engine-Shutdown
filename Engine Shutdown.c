#include <stdio.h>

int numActions = 0;
int currBest = 0;

void permute(int used[numActions], int actions[][numActions], int perm[numActions], 
             int bestPerm[numActions], int index, int N);

int main() {
    scanf("%d", &numActions);

    int initial[numActions];
    for (int i = 0; i < numActions; i++)
        scanf("%d", &initial[i]);

    int actions[numActions][numActions];
    int used[numActions];
    for(int i = 0; i < numActions; i++) 
        for(int j = 0; j < numActions; j++)
            scanf("%d", &actions[i][j]);

    for(int i = 0; i < numActions; i++)
        currBest += initial[i];

    int bestPerm[numActions];

    permute(used, actions, initial, bestPerm, 0, numActions);

    return 0;
}

void permute(int used[numActions], int actions[][numActions], int perm[numActions], 
             int bestPerm[numActions], int index, int N)
{
    printf("At permute\nIndex: %d\nN: %d\n", index, N);
    // Check if the index is invalid
    if (index == N) {
        printf("\nValid Index\n\n");
        for (int i = 0; i < N; i++) 
           printf("%d ", perm[i] + 1);
        printf("\n");
        return; // prevent calling recursively
    }
    
    printf("Looping over index\n");
    // Alternatively loop over index
    for (int curValue = 0; curValue < N; curValue++)
    {
        // Check if the value is not allowed
        if (used[curValue]) 
            continue; // skip
        
        // Use the value
        used[curValue] = 1;
        perm[index] = curValue;
        // Recurse
        printf("Recursing\n\n");
        permute(used, actions, perm, bestPerm, index + 1, N);
    
        // Unuse the value
        used[curValue] = 0;
    } 
}