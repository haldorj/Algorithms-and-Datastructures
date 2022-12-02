#include <iostream>
#include <queue>
#include <vector>
#include <list>

#include "Node.h"
#include "Edge.h"
#include "Path.h"
#include "Graph.h"

/*// Graphs:

// In graphs nodes are called vertices (plural of vertex).
// Vertices that are connected are called adjacent vertices.
// The edges of a graph are often represented by something known as an adjacency matrix or an adjacency list.
// The nodes of a graph can be unweighted or weighted.

// Dijkstra's Algorithm:

// 1. Mark all vertices in the graph as unvisited.
// 2. Mark the source vertex as 0 and the rest as infinity.
// 3. We consider the source vertex as the current vertex.
// 4. Calculate the path of all the adjacent vertices by adding the weight of the edge
//    (line connecting vertices) in the current vertex.
// 5. If the new path length is shorter than the previous path length then replace it otherwise ignore it.
// 6. Mark the current vertex as visited after visiting the neighbor vertex of the current vertex.
// 7. Select the vertex with the smallest path length as the new current vertex.
// 8. Go back to step 4.
// 9. Repeat this process until all the vertex are marked as visited. */


int main()
{
	Graph graph;

	graph.InsertNode('A');
	graph.InsertNode('B');
	graph.InsertNode('C');
	graph.InsertNode('D');
	graph.InsertNode('E');
	graph.InsertNode('F');

	graph.InsertEdge('A', 'B', 2.f);
	graph.InsertEdge('A', 'C', 4.f);
	graph.InsertEdge('B', 'C', 1.f);
	graph.InsertEdge('B', 'D', 7.f);
	graph.InsertEdge('C', 'E', 3.f);
	graph.InsertEdge('E', 'D', 2.f);
	graph.InsertEdge('D', 'F', 1.f);
	graph.InsertEdge('E', 'F', 5.f);
	
	graph.Dijkstra(graph.FindNode('A'), graph.FindNode('F'));
	
	std::cout << std::endl;

}