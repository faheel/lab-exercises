#include <iostream>
#include <vector>

using namespace std;

const int MaxNodes = 10;

struct Edge
{
	char source, dest;
	int weight;
};

void printAdjMatrix(int adjMatrix[][MaxNodes], int numNodes)
{
	int i, j;

	cout << "Adjacency matrix:\n  ";
	for (i = 0; i < numNodes; i++)
		cout << char('a' + i) << " ";

	for (i = 0; i < numNodes; i++)
	{
		cout << "\n" << char('a' + i) << " ";
		for (j = 0; j < numNodes; j++)
			cout << adjMatrix[i][j] << " ";
	}
	cout << "\n";
}

int main()
{
	Edge edge;

	vector <char> nodes;
	vector <Edge> edges;
	vector <Edge> MST;
	
	int adjMatrix[MaxNodes][MaxNodes];
	int numNodes, numEdges, i, j, source, dest, weight;

	cout << "Enter the number of nodes (max " << MaxNodes << ") : ";
	cin >> numNodes;

	for (i = 0; i < numNodes; i++)
		nodes.push_back(char('a' + i));

	cout << "Enter the number of edges : ";
	cin >> numEdges;

	cout << "Enter the edges (source, dest, weight) :\n";
	for (i = 0; i < numEdges; i++)
	{
		cin >> edge.source;
		cin >> edge.dest;
		cin >> edge.weight;

		edges.push_back(edge);
	}

	for (i = 0; i < numNodes; i++)
		for (j = 0; j < numNodes; j++)
			adjMatrix[i][j] = 0;

	for (i = 0; i < numEdges; i++)
	{
		source = edges[i].source - 'a';
		dest = edges[i].dest - 'a';
		weight = edges[i].weight;
		adjMatrix[source][dest] = adjMatrix[dest][source] = weight;
	}

	printAdjMatrix(adjMatrix, numNodes);

	int cost, minWeight, minIndex;
	
	cost = minWeight = 0;
	for (i = 0; i < numNodes-1; i++)
	{
		minWeight = 1E9;
		minIndex = -1;
		for (j = 0; j < numNodes; j++)
			if (adjMatrix[i][j] != 0)
			{
				if (adjMatrix[i][j] < minWeight)
				{
					minWeight = adjMatrix[i][j];
					minIndex = j;
				}
			}
		if (minIndex != -1)
		{
			adjMatrix[minIndex][i] = 0;
			edge.source = char('a' + i);
			edge.dest = char('a' + minIndex);
			edge.weight = minWeight;

			MST.push_back(edge);
			cost += minWeight;
		}
	}

	cout << "\nMinimum spanning tree:\n";
	for (i = 0; i < MST.size(); i++)
	{
		cout << MST[i].source << " - " << MST[i].weight << " - " << MST[i].dest << "\n";
	}

	cout << "\nCost of MST : " << cost << "\n";

	return 0;
}