#include <iostream>
#include <string>
#include <map>
#include <limits.h>


#define INF INT_MAX
#define MAX 110

int n, m, q;
int u, v, w;
string uStr, vStr;
map<string, int> stationIndices;
int graph[MAX][MAX];

void floydWarshall()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; i++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        graph[u][v] = INF;
    
    for (int i = 0; i < n; i++)
    {
        cin >> uStr;
        stationIndices[uStr] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> uStr >> vStr >> w;
        u = stationIndices[uStr];
        v = stationIndices[vStr];
        
        graph[u][v] = w;
    }
    
    floydWarshall();
    
    cin >> q;
    while (q--)
    {
        cin >> uStr >> vStr;
        cout << graph[stationIndices[uStr]][stationIndices[vStr]] << endl;
    }
    
    return 0;
}