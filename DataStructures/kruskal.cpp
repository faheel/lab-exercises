#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MaxNodes = 10;

struct Node
{
	char parent;
	int rank;
};

struct Edge
{
	char node1, node2;
	int weight;
};

bool byWeight(Edge e1, Edge e2)
{
	return e1.weight <= e2.weight;
}

int main()
{
	Node node;
	Edge edge;

	vector <Node> nodes;
	vector <Edge> edges;
	vector <Edge> MST;

	int numNodes, numEdges, i;

	cout << "Enter the number of nodes (max " << MaxNodes << ") : ";
	cin >> numNodes;

	for (i = 0; i < numNodes; i++)
	{
		node.parent = char('a' + i);
		node.rank = 0;
		
		nodes.push_back(node);
	}

	cout << "Enter the number of edges : ";
	cin >> numEdges;

	cout << "Enter the edges (node1, node2, weight) :\n";
	for (i = 0; i < numEdges; i++)
	{
		cin >> edge.node1;
		cin >> edge.node2;
		cin >> edge.weight;

		edges.push_back(edge);
	}

	sort(edges.begin(), edges.end(), byWeight);

	// TODO: complete it!

	return 0;
}
