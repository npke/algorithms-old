#include <iostream>
#include <graph>
using namespace std;

#define MAX 110000

int tc, n, m, u, v;
int root[MAX], prize[MAX], ranks[MAX], visited[MAX];
vector< vector<int> > graph;

int findset(int v)
{
    if (v == root[v])
        return v;
    return findset(root[v]);
}

void unionset(int u, int v)
{
    u = findset(u);
    v = findset(v);
    
    if (ranks[v] <  ranks[u])
        root[v] = u;
    else if (ranks[u] < ranks[v])
        root[u] = v;
    else 
    {
        root[v] = u;
        ranks[u]++;
    }
}

long long dfs(int source)
{
    long long size = 0;
    stack<int> s;
    s.push(source);
    
    while (!s.empty())
    {
        u = s.top();
        s.pop();
        
        if (visited[u] == 1)
            continue;
        
        for (int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];
            if (visited[v] == 0)
            {
                size += prize[v];
                s.push(v);
            }
        }
    }
    
    return size;
}

int main()
{
    cin >> tc;
    
    while (tc--)
    {
        cin >> n >> m;
        memset(visited, -1, n * sizeof(int));
        
        graph.clear();
        graph.resize(n);
        
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph[--u].push_back(--v);
        }
        
        for (int i = 0; i < n; i++)
            cin >> prize[i];
        
        long long maxSize = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
                continue;
            
            long long tmp = dfs(i);
            if (tmp > maxSize)
                maxSize = tmp;
        }
        
        cout << maxSize << endl;
    }
    return 0;
}