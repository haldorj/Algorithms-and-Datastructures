#pragma once

struct Graph
{
	std::list<Node*> Nodes;
	Graph(){}

	Node* FindNode(char name);
	void InsertNode(char name);
	void InsertEdge(char from_name, char to_name, float distance);
	float mst();
	Path Dijkstra(Node* start, Node* end);
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
	Nodes.push_back(new Node(name)); 
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
float Graph::mst() // Prim
{
	float sum{};
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> apq;
	apq.emplace(0.f, Nodes.front());
	do
	{
		auto edge = apq.top();
		auto node = edge.m_ToNode;
		apq.pop();
		if (!node->m_Visited)
		{
			sum += edge.m_Distance;
			node->m_Visited = true;
			std::cout << edge.m_ToNode->m_Name;
			for (auto& kant : node->m_Edges)
				apq.push(kant);
		}
	} while (!apq.empty());
	return sum;
}
Path Graph::Dijkstra(Node* start, Node* end)
{
	std::priority_queue<Path, std::vector<Path>, std::greater<Path>> APQ;
	std::vector<Node*> visited;
	// setup
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
