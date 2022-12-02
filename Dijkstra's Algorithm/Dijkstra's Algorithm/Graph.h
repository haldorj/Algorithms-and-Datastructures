#pragma once

typedef std::pair<float, Node*> Pair;
const float INF = 100000.f;

struct Graph
{
	std::list<Node*> Nodes;
	Graph(){}

	// Helper functions
	void InsertNode(char name);
	void InsertEdge(char from_name, char to_name, float distance);
	Node* FindNode(char name);

	// Shortest path algorithms
	void Dijkstra(Node* start, Node* end);
	void PrintPath(Node* node);
};

void Graph::InsertNode(char name)
{
	// Adds a new node to the graph/list of nodes
	Nodes.push_back(new Node(name));
}

void Graph::InsertEdge(char from_name, char to_name, float distance)
{
	Node* from = nullptr;
	Node* to = nullptr;
	// Finds the nodes in the list by name
	for (auto node : Nodes)
	{
		if (node->m_Name == from_name)
			from = node;
		else if (node->m_Name == to_name)
			to = node;
	}
	// Insert edge if both "from" and "to" are present
	if (from && to)
		from->InsertEdge({ from, to, distance });
}

Node* Graph::FindNode(char name)
{
	// Return a specific node by searching for its name
	for (auto node : Nodes)
	{
		if(node->m_Name == name)
		{
			return node;
		}
	}
	return nullptr;
}

void Graph::Dijkstra(Node* start, Node* end)
{
	if (start == nullptr || end == nullptr) return;	// Exit function early if start or end is null.

	std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq; // queue holding nodes and corresponding dist from start.
	
	// Set distance from start for all nodes to INF and also as unvisited.
	for (auto node : Nodes)
	{
		node->m_DistanceFromStart = INF;
		node->m_Visited = false;
		node->Prev = nullptr;
		node->Parent = nullptr;
	}

	// Insert start in priority queue and set its distance as 0.
	pq.push(std::make_pair(0, start));
	start->m_DistanceFromStart = 0.f;
	
	while (!pq.empty())
	{
		// Make "Current" the node with the shortest dist from start (always at top of the queue).
		Node* Current = pq.top().second;
		pq.pop();
		// Mark Current as visited
		Current->m_Visited = true;
		
		// For all neighbours of the "current" node.
		for (const auto edge : Current->m_Edges)
		{
			// If not visited
			if (edge.m_ToNode->m_Visited != true)
			{
				auto Next = edge.m_ToNode;
				auto Cost = edge.m_Cost;

				// Update the distance of neighbouring nodes if possible
				// Has to be shorter than its existing value
				if (Next->m_DistanceFromStart > Current->m_DistanceFromStart + Cost )
				{
					Next->m_DistanceFromStart = Current->m_DistanceFromStart + Cost;
					pq.push(std::make_pair(Next->m_DistanceFromStart, Next));
					// Update prev pointer
					Next->Prev = Current;
				}
			}
		}
		std::cout << std::endl;
	}
	
	std::cout << "All node's shortest distance from start: " << std::endl;
	for (auto node : Nodes)
	{
		std::cout << node->m_Name << ", Distance from start: "<< node->m_DistanceFromStart << std::endl;
	}

	std::cout << std::endl;

	PrintPath(end);
}

void Graph::PrintPath(Node* node)
{
	std::cout << "Shortest path: " << std::endl;

	// Traverse list from the end node via previous pointers
	while (node->Prev != nullptr)
	{
		// Assign parent pointers
		node->Prev->Parent = node;
		node = node->Prev;
	}

	// The best path can be printed in the right order

	// Traverse list via parent pointers
	while (node->Parent != nullptr)
	{
		std::cout << node->m_Name << "->";
		node = node->Parent;
	}
	std::cout << node->m_Name << " Total Cost: " << node->m_DistanceFromStart << "." << std::endl;
}