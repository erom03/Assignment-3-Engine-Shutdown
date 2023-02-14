#include <stdio.h>

int main() {
    int actions;
    scanf("%d", &actions);

    int initial[actions];
    for (int i = 0; i < actions; i++)
        scanf("%d", &initial[i]);

    int permutations[actions][actions];
    for(int i = 0; i < actions; i++) 
        for(int j = 0; j < actions; j++)
            scanf("%d", &permutations[i][j]);

    int currBest = 0;
    for(int i = 0; i < actions; i++)
        currBest += initial[i];

    return 0;
}