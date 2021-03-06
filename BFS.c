#include "functii.h"
//adjacency matrix
int adjMatrix[MAX][MAX];
struct Vertex
{
    int label;
    bool visited;
};
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
//vertex count
int vertexCount = 0;
int conectCount = 0;
//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];
void insert(int data)
{
    queue[++rear] = data;
    queueItemCount++;
}

int removeData()
{
    queueItemCount--;
    return queue[front++];
}

bool isQueueEmpty()
{
    return queueItemCount == 0;
}
//add vertex to the vertex list
void addVertex(int label)
{
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

//BFS function

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%d ",lstVertices[vertexIndex]->label);
}
//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex)
{
    int i;

    for(i = 0; i<vertexCount; i++)
    {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
            return i;
    }

    return -1;
}

int breadthFirstSearch()
{
    int i;

    //mark first node as visited
    lstVertices[0]->visited = true;

    //display the vertex
    displayVertex(0);
    //insert vertex index in queue
    insert(0);
    int unvisitedVertex;

    while(!isQueueEmpty())
    {
        //get the unvisited vertex of vertex which is at front of the queue
        int tempVertex = removeData();

        //no adjacent vertex found
        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
        {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            conectCount++;
            insert(unvisitedVertex);
        }

    }

    //queue is empty, search is complete, reset the visited flag
    for(i = 0; i<vertexCount; i++)
    {
        lstVertices[i]->visited = false;
    }
    return conectCount;
}
