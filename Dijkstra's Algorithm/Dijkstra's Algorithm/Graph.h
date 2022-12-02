#pragma once

typedef std::pair<float, Node*> Pair;
const float INF = 100000.f;

struct Graph
{
	std::list<Node*> Nodes;
	Graph(){}
	void Dijkstra(Node* start, Node* end);
};

void Graph::Dijkstra(Node* start, Node* end)
{
	if (start == nullptr || end == nullptr) return;	// Exit function early if start or end is null.

	std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;
	
	// Set distance from start for all nodes to INF.
	for (auto node : Nodes)
	{
		node->m_DistanceFromStart = INF;
		node->m_Visited = false;
		node->Prev = nullptr;
		node->Parent = nullptr;
	}

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(std::make_pair(0, start));
	start->m_DistanceFromStart = 0;

	// Mark Start as visited and DistanceFromStart as 0.
	start->m_DistanceFromStart = 0.f;
	start->m_Visited = true;
	
	while (!pq.empty())
	{
		Node* Current = pq.top().second;
		pq.pop();
		
		Current->m_Visited = true;
		// For all neighbours of the "current" node.
		for (const auto edge : Current->m_Edges)
		{
			if (edge.m_ToNode->m_Visited != true)
			{
				auto Next = edge.m_ToNode;
				auto Cost = edge.m_Cost;
				
				if (Next->m_DistanceFromStart > Current->m_DistanceFromStart + Cost )
				{
					Next->m_DistanceFromStart = Current->m_DistanceFromStart + Cost;
					pq.push(std::make_pair(Next->m_DistanceFromStart, Next));
					Next->Prev = Current;
				}
			}
		}
		std::cout << std::endl;
	}
	
	std::cout << "All node's shortest distance from start: " << std::endl;
	for (auto node : Nodes)
	{
		std::cout << node->m_Name << " "<< node->m_DistanceFromStart << std::endl;
	}

	std::cout << std::endl;

	
	std::cout << "Shortest path: " << std::endl;
	Node* Temp = end;
	
	while (Temp->Prev != nullptr)
	{
		Temp->Prev->Parent = Temp;
		Temp = Temp->Prev;
	}

	while (Temp->Parent != nullptr)
	{
		std::cout << Temp->m_Name << " -> ";
		Temp = Temp->Parent;
	}
	std::cout << Temp->m_Name << " Total Cost: " << Temp->m_DistanceFromStart << "." << std::endl;
}