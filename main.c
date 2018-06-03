#include "functii.h"
//adjacency matrix
int adjMatrix[MAX][MAX];
int visitedB[MAX];
int main()
{

    int i, j, x, cC,meth;
    int n;
    for(i = 0; i<MAX; i++) // set adjacency {
        for(j = 0; j<MAX; j++) // matrix to 0
            adjMatrix[i][j] = 0;
    //set rand() function and declare n and adjmatrix with random numbers
    time_t t;
    srand((unsigned) time(&t));
    n = rand()%100;
    for(i = 0; i<n; i++)
        addVertex(i);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            adjMatrix[i][j]=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(j==i)
                continue;
            x=rand() % 10 + 1;
            if(x%2==1 && adjMatrix[i][j]==0)
            {
                adjMatrix[i][j]=1;
                adjMatrix[j][i]=1;
            }
        }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",adjMatrix[i][j]);
        printf("\n");
    }
    printf("Alegeti metoda de parcurgere a grafului:\nApasa 1 pentru metoda de parcurgere BFS;\nApasa 2 pentru metoda de parcurgere DFS;\n");
    scanf("%d",&meth);
    if(meth == 1){
        printf("\nOrdinea in care sunt parcurse varfurile folosind BFS este: ");
    cC=breadthFirstSearch();
    if(cC==n-1)
        printf("\nGraful este conex\n");
    else printf("\nGraful nu este conex\n");
    system("pause");}
    //DFS
    else{
        int sw=1;
        for(i=0; i<n; i++)
            visitedB[i]=0;
        printf("\nOrdinea in care sunt parcurse varfurile folosind DFS este: ");
        DFS(0,n);
        for(i=0; i<n; i++)
            if(visitedB[i]==0)
            {
                sw=0;
                break;
            }
        if(sw)
            printf("\nGraful este conex\n");
        else printf("\nGraful nu este conex\n");
        system("pause");
    }
    return 0;
}
