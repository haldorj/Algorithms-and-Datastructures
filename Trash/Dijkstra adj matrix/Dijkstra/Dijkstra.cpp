#include <iostream>

int V;
int source;
int cost[100][100];
int dist[100];
int parent[100];
bool visited[100] = {false};
int INF = 999;

void init()
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        dist[i] = INF;

    }
    dist[source] = 0;
}

int getNearestNode()
{
    int minvalue = INF;
    int minnode = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void dijkstra()
{
    for (int i = 0; i < V; i++)
    {
        int  nearest = getNearestNode();
        visited[nearest] = true;
        for (int adj = 0; adj < V; adj++)
        {
            // check for adjacent nodes
            if (cost[nearest][adj] != INF &&
            dist[adj] > (dist[nearest] + cost[nearest][adj]))
            {
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void display()
{
    std::cout << "Node: \t\t\t "<< "Cost:  \t\t\t" << "Path:  \t\t" << std::endl;
    for(int i =0 ;i < V ;i++){
        std::cout << i << " \t\t\t" << dist[i] << " \t\t\t";
        
        std::cout << i << "    ";
        int parnode = parent[i];
        
        while (parnode != source)
        {
            std::cout << "<--" << parnode << "    ";
            parnode = parent[parnode];
        }
        std::cout << std::endl;
    } 
}

int main()
{
    std::cout << "Number of verticies: " << std::endl;
    std::cin >> V;

    std::cout << "Enter adj matrix: " << std::endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            std::cin >> cost[i][j];
        }
    }

    std::cout << "Source node: "<< std::endl;
    std::cin >> source;
    init();
    dijkstra();
    display();
    
    return 0;
}

/*
0   4   999 999 999 999 999 999 999
4   0   8   999 999 999 999 8   999
999 8   0   7   999 4   999 999 2
999 999 7   0   9   14  999 999 999
999 999 999 9   0   10  999 999 999
999 999 4   14  10  0   2   999 999
999 999 999 999 999 2   0   1   6
999 11  999 999 999 999 1   0   7
999 999 2   999 999 999 6   7   0
*/