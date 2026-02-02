#include <iostream> 
using namespace std;

int tspRec(int graph[][4], int currentPos, int visitedCount, int cost, bool visited[], int n, int start) 
{ 
    if (visitedCount == n) 
   { 
       if (graph[currentPos][start] != 0) 
       { 
          return cost + graph[currentPos][start];
       } 
     return -1;
   } 
   int minCost = -1;
   for (int city = 0; city < n; city++) 
   {
      if (!visited[city] && graph[currentPos][city] != 0) 
      { 
         visited[city] = true;
          int currentCost = tspRec(graph, city, visitedCount +1, cost + graph[currentPos][city],       visited, n, start);
          if (currentCost != -1 && (minCost == -1 || currentCost < minCost)) 
          { 
              minCost = currentCost;
          } 
         visited[city] = false;
      } 
   } 
 return minCost;
} 
int main() 
{ 
    const int N = 4;
    int graph[4][4];
    cout << "Enter the adjacency matrix (use 0 for no path):" << endl;
    for (int i = 0; i < N; i++)
    {
       for (int j = 0; j < N; j++) 
       {
          cin >> graph[i][j];
       } 
    } 
    bool visited[N] = {false};
    int start_node = 0;
    visited[start_node] = true;
    int result = tspRec(graph, start_node, 1, 0, visited, N, start_node);
    if (result != -1) 
    { 
       cout << "The minimum distance cycle has cost: " << result << endl;
    } 
    else 
    { 
       cout << "No cycle is possible." << endl;
    } 
   return 0;
} 
