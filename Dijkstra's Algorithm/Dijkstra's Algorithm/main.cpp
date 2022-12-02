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
	
	Node* nodeA = new Node('A');
	Node* nodeB = new Node('B');
	Node* nodeC = new Node('C');
	Node* nodeD = new Node('D');
	Node* nodeE = new Node('E');
	
	graph.Nodes.push_back(nodeA);
	graph.Nodes.push_back(nodeB);
	graph.Nodes.push_back(nodeC);
	graph.Nodes.push_back(nodeD);
	graph.Nodes.push_back(nodeE);

	Edge* edgeAB = new Edge{nodeA, nodeB, 1.f};
	Edge* edgeAC = new Edge{nodeA, nodeC, 2.f};
	Edge* edgeBC = new Edge{nodeB, nodeC, 2.f};
	Edge* edgeCD = new Edge{nodeC, nodeD, 3.f};
	Edge* edgeDE = new Edge{nodeD, nodeE, 1.f};
	Edge* edgeAE = new Edge{nodeA, nodeE, 5.f};
	Edge* edgeCE = new Edge{nodeC, nodeE, 4.f};

	nodeA->InsertEdge(*edgeAB);
	nodeA->InsertEdge(*edgeAC);
	nodeB->InsertEdge(*edgeBC);
	nodeC->InsertEdge(*edgeCD);
	nodeD->InsertEdge(*edgeDE);
	nodeA->InsertEdge(*edgeAE);
	nodeC->InsertEdge(*edgeCE);

	graph.Dijkstra(nodeA, nodeD);
	
	std::cout << std::endl;

}