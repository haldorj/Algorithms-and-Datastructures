#pragma once

struct Graph
{
	std::list<Node*> Nodes;
	Graph(){}

	Node* FindNode(char name);
	void InsertNode(char name);
	void InsertNodeAStar(char name, float h_cost);
	void InsertEdge(char from_name, char to_name, float distance);
	void CalculateHCost(Node* start, Node* end);
	Path Dijkstra(Node* start, Node* end);
	Path AStar(Node* start, Node* end);
};

Node* Graph::FindNode(char name)
{
	for (auto node : Nodes)
	{
		if(node->m_Name == name)
		{
			return node;
		}
	}
	return nullptr;
}

void Graph::InsertNode(char name)
{
	Nodes.push_back(new Node(name, 0)); 
}

void Graph::InsertNodeAStar(char name, float h_cost) 
{
	Nodes.push_back(new Node(name, h_cost)); 
}

void Graph::InsertEdge(char from_name, char to_name, float distance)
{
	Node* from = nullptr;
	Node* to = nullptr;
	for (auto node : Nodes)
	{
		if (node->m_Name == from_name)
			from = node;
		else if (node->m_Name == to_name)
			to = node;
	}
	if (from && to)
		from->InsertEdge({ distance, to });
}

void Graph::CalculateHCost(Node* start, Node* end)
{
	end->H_Cost = 0;
}

Path Graph::Dijkstra(Node* start, Node* end)
{
	// Ascending priority queue
	std::priority_queue<Path, std::vector<Path>, std::greater<Path>> APQ;
	// Vector storing visited nodes
	std::vector<Node*> visited;
	
	// Set distance to start to 0
	Edge StartEdge{ 0.f, start };
	// Push the 
	Path StartPath;
	StartPath.m_edges.push_back(StartEdge);
	APQ.push(StartPath);
	
	Path ShortestPath;
	while (!APQ.empty())
	{
		// Gets the node traveled to, "Current", on the shortest path.
		Node* Current = APQ.top().GetLastNode();
		if (Current == end)
		{
			ShortestPath = APQ.top();
			break;
		}
		Path TempPath = APQ.top();
		
		// Visit shortest node from start & delete from queue.
		APQ.pop();
		Current->m_Visited = true;

		// Add visited node to array of visited nodes.
		visited.push_back(Current);

		// For all neighbours of the "current" node.
		for (auto& edge : Current->m_Edges)
		{
			// If a neighbour is not visited.
			if (!edge.m_ToNode->m_Visited)
			{
				// Push_back the path onto the queue. The shortest neighbour from start will be the "Current" node.
				Path newPath = TempPath;
				newPath.m_edges.push_back(edge);
				newPath.Print();
				APQ.push(newPath);
			}
		}
		std::cout << std::endl;
	}
	// End was found (or APQ was empty)

	// Reset all nodes back to unvisited
	for (auto node : visited)
	 	node->m_Visited = false;

	
	std::cout << "Shortest path: ";
	for (auto& edge : ShortestPath.m_edges)
		std::cout << edge.m_ToNode->m_Name;
	std::cout << " (" << ShortestPath << ")" << std::endl;
	
	return ShortestPath;
}

Path Graph::AStar(Node* start, Node* end)
{
	std::priority_queue<Path, std::vector<Path>, std::greater<Path>> APQ;
	std::vector<Node*> visited;
	Edge StartEdge{ 0.f, start };
	Path StartPath;
	StartPath.m_edges.push_back(StartEdge);
	APQ.push(StartPath);
	Path ShortestPath;
	
	while (!APQ.empty())
	{
		Node* tempNode = APQ.top().GetLastNode();
		if (tempNode == end)
		{
			ShortestPath = APQ.top();
			break;
		}
		Path TempPath = APQ.top();
		APQ.pop();
		tempNode->m_Visited = true;
		visited.push_back(tempNode);
		for (auto& edge : tempNode->m_Edges)
		{
			if (!edge.m_ToNode->m_Visited)
			{
				Path newPath = TempPath;
				newPath.m_edges.push_back(edge);
				newPath.Print();
				APQ.push(newPath);
			}
		}
		std::cout << std::endl;
	}

	for (auto node : visited)
		node->m_Visited = false;

	std::cout << "Shortest path: ";
	for (auto& edge : ShortestPath.m_edges)
		std::cout << edge.m_ToNode->m_Name;
	std::cout << " (" << ShortestPath << ")" << std::endl;

	return ShortestPath;
}
