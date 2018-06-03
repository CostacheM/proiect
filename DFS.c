#include "functii.h"
int visitedB[MAX];
//adjacency matrix
int adjMatrix[MAX][MAX];
void DFS(int i,int n)
{
    int j;
    printf("%d ",i);
    visitedB[i]=1;

    for(j=0; j<n; j++)
        if(!visitedB[j]&&adjMatrix[i][j]==1)
            DFS(j,n);
}
