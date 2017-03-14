#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define DELETED -1
#define WHITE 0
#define GREY 1
#define BLACK 2
#define RED 3
#define BLUE 4
#define MAX_INT 2147483647

//  The structure, describing the roads/trails 
struct Route {
	int color;
	unsigned int to, length;
	//  Constructor by destination, length and color of edge
	Route(unsigned int to, unsigned int length, int color) {
		this->to = to;
		this->color = color;
		this->length = length;
	}
};

//Function implements ordinary Dijkstra's algorithm (for all edges of the same color)
//As a result, an array of distances filled with the minimum distance to each vertex
void djikstra(vector<Route>* graph, int* distancesInColoredGraph, unsigned int quantityOfAllVertices, int finishVertex, int color) {
	int vertexWithMinDist = -1;
	bool* passed = new bool[quantityOfAllVertices];
	fill(passed, passed + quantityOfAllVertices, false);
	fill(distancesInColoredGraph, distancesInColoredGraph + quantityOfAllVertices, MAX_INT);
	distancesInColoredGraph[finishVertex] = 0;
	for (unsigned int indexOfCurrentVertex = 0; vertexWithMinDist == -1 || indexOfCurrentVertex < quantityOfAllVertices && distancesInColoredGraph[vertexWithMinDist] != MAX_INT; indexOfCurrentVertex++) {
		vertexWithMinDist = -1;
		for (unsigned int indexOfVertex = 0; indexOfVertex < quantityOfAllVertices; indexOfVertex++) {
			if (!passed[indexOfVertex] && (vertexWithMinDist == -1 || distancesInColoredGraph[indexOfVertex] < distancesInColoredGraph[vertexWithMinDist])) {
				vertexWithMinDist = indexOfVertex;
			}
		}
		passed[vertexWithMinDist] = true;
		for (unsigned int adjacentVertex = 0; adjacentVertex < graph[vertexWithMinDist].size(); adjacentVertex++) {
			if (graph[vertexWithMinDist][adjacentVertex].color == color
				&& graph[vertexWithMinDist][adjacentVertex].length + distancesInColoredGraph[vertexWithMinDist] < distancesInColoredGraph[graph[vertexWithMinDist][adjacentVertex].to]) {
				distancesInColoredGraph[graph[vertexWithMinDist][adjacentVertex].to] = graph[vertexWithMinDist][adjacentVertex].length + distancesInColoredGraph[vertexWithMinDist];
			}
		}
	}
}

//  Function indicates the edges we don't need as deleted (because we can't pass them)
void simplify(vector<Route>* graph, int* distance, unsigned int quantityOfAllVertices, int color) {
	//  Note as DELETED routes in which the minimum distance to finish vertex increases, cause we can't walk them on the strength of problem's condition
	for (unsigned int indexOfCurrentVertex = 0; indexOfCurrentVertex < quantityOfAllVertices; indexOfCurrentVertex++) {
		for (unsigned int adjacentVertex = 0; adjacentVertex < graph[indexOfCurrentVertex].size(); adjacentVertex++) {
			if (graph[indexOfCurrentVertex][adjacentVertex].color == color
				&& distance[indexOfCurrentVertex] <= distance[graph[indexOfCurrentVertex][adjacentVertex].to]) {
				graph[indexOfCurrentVertex][adjacentVertex].color = DELETED;
			}
		}
	}
}

//  Function determines whether you can go in cycle by the edges of alternating colors 
bool cyclicDFS(vector<Route>* graph, int* passedInRedGraph, int* passedInBlueGraph, int currentVertex, int color) {
	bool answer = false;
	//  Note processing vertex
	if (color == RED) passedInRedGraph[currentVertex] = GREY;
	else passedInBlueGraph[currentVertex] = GREY;
	//Implement ordinary checking on cycle, by coloring graph
	//Treat until we don't determine it is acyclic or try to color vertex that is already colored
	//We should take into account the fact, that each time we alternate the color of the edges
	for (unsigned int adjacentVertex = 0; adjacentVertex < graph[currentVertex].size() && !answer; adjacentVertex++) {
		if (graph[currentVertex][adjacentVertex].color == color) {
			if (color == BLUE && passedInRedGraph[graph[currentVertex][adjacentVertex].to] == GREY
				|| color == RED && passedInBlueGraph[graph[currentVertex][adjacentVertex].to] == GREY) {
				answer = true;
			}
			if (color == RED && passedInBlueGraph[graph[currentVertex][adjacentVertex].to] == WHITE) {
				if (cyclicDFS(graph, passedInRedGraph, passedInBlueGraph, graph[currentVertex][adjacentVertex].to, BLUE)) {
					answer = true;
				}
			}
			else if (passedInRedGraph[graph[currentVertex][adjacentVertex].to] == WHITE) {
				if (cyclicDFS(graph, passedInRedGraph, passedInBlueGraph, graph[currentVertex][adjacentVertex].to, RED)) {
					answer = true;
				}
			}
		}
	}
	//  Note processed vertex
	if (color == RED) passedInRedGraph[currentVertex] = BLACK;
	else passedInBlueGraph[currentVertex] = BLACK;
	return answer;
}

//  Function determines whether there is a suitable cycle in the graph
bool isCyclic(vector<Route>* graph, unsigned int quantityOfAllVertices, int currentVertex) {
	int* passedInRedGraph = new int[quantityOfAllVertices];
	int* passedInBlueGraph = new int[quantityOfAllVertices];
	fill(passedInRedGraph, passedInRedGraph + quantityOfAllVertices, WHITE);
	fill(passedInBlueGraph, passedInBlueGraph + quantityOfAllVertices, WHITE);
	return cyclicDFS(graph, passedInRedGraph, passedInBlueGraph, currentVertex, RED);
}

//  Function determines the longest path in the graph by the edges of alternating colors, by finding and memorizing the maximum path to each of the vertices
int maxDistDFS(vector<Route>* graph, int* maxDistancesInRedGraph, int* maxDistancesInBlueGraph, int currentVertex, int color) {
	//  Return the length of the path from the current vertex, if it's found already
	if (color == RED && maxDistancesInRedGraph[currentVertex] != -1) return maxDistancesInRedGraph[currentVertex];
	if (color == BLUE && maxDistancesInBlueGraph[currentVertex] != -1) return maxDistancesInBlueGraph[currentVertex];
	int maxDistance = -1;   //  Initially, we consider the longest path by any negative number
	for (unsigned int adjacentVertex = 0; adjacentVertex < graph[currentVertex].size(); adjacentVertex++) {
		//Recursively find the longest path to the finish vertex
		//We should take into account the fact, that each time we alternate the color of the edges
		if (graph[currentVertex][adjacentVertex].color == color) {
			int currentMaxDistance = maxDistDFS(graph, maxDistancesInRedGraph, maxDistancesInBlueGraph, graph[currentVertex][adjacentVertex].to,
				color == RED ? BLUE : RED) + graph[currentVertex][adjacentVertex].length;
			maxDistance = max(maxDistance, currentMaxDistance);
		}
	}
	//  Remember the results received in the process of bypassing for later use
	if (color == RED) maxDistancesInRedGraph[currentVertex] = maxDistance;
	else maxDistancesInBlueGraph[currentVertex] = maxDistance;
	return maxDistance;
}

//  Function returns the longest path in the graph from the start vertex to the finish
int getMaxDist(vector<Route>* graph, unsigned int quantityOfAllVertices, int startVertex, int finishVertex) {
	int* maxDistancesInRedGraph = new int[quantityOfAllVertices];
	int* maxDistancesInBlueGraph = new int[quantityOfAllVertices];
	fill(maxDistancesInRedGraph, maxDistancesInRedGraph + quantityOfAllVertices, -1);
	fill(maxDistancesInBlueGraph, maxDistancesInBlueGraph + quantityOfAllVertices, -1);
	maxDistancesInRedGraph[finishVertex] = 0;
	maxDistancesInBlueGraph[finishVertex] = 0;
	return maxDistDFS(graph, maxDistancesInRedGraph, maxDistancesInBlueGraph, startVertex, RED);
}

int main() {
	ios::sync_with_stdio(false);
	unsigned int quantityOfAllVertices, quantityOfVertices, startVertex, finishVertex, from, to, length;
	cin >> quantityOfAllVertices >> startVertex >> finishVertex;
	startVertex--; finishVertex--;  //  Shift numbering
	vector<Route>* graph = new vector<Route>[quantityOfAllVertices];    // Stores graph as array of routes for each vertex
	cin >> quantityOfVertices;
	while (quantityOfVertices--) {
		cin >> from >> to >> length;
		from--; to--;   //  Shift numbering
		if (from != to) {   //  Don't read cycles
							// Initially, all roads are bidirectional, add symmetrically
			graph[from].push_back(Route(to, length, RED));
			graph[to].push_back(Route(from, length, RED));
		}
	}
	cin >> quantityOfVertices;
	while (quantityOfVertices--) {
		cin >> from >> to >> length;
		from--; to--;
		if (from != to) {
			graph[from].push_back(Route(to, length, BLUE));
			graph[to].push_back(Route(from, length, BLUE));
		}
	}
	int* distancesInRedGraph = new int[quantityOfAllVertices];  //  Shortest distances from each vertex to the final by red edges
	int* distancesInBlueGraph = new int[quantityOfAllVertices]; //  Shortest distances from each vertex to the final by blue edges
	djikstra(graph, distancesInRedGraph, quantityOfAllVertices, finishVertex, RED);     //  Find and remember the shortest path by the red edges
	djikstra(graph, distancesInBlueGraph, quantityOfAllVertices, finishVertex, BLUE);   //  Find and remember the shortest path by the blue edges
	simplify(graph, distancesInRedGraph, quantityOfAllVertices, RED);   //  Note red edges which we can't pass, so that later they don't take into account
	simplify(graph, distancesInBlueGraph, quantityOfAllVertices, BLUE); //  Note blue edges which we can't pass, so that later they don't take into account
	cout << (isCyclic(graph, quantityOfAllVertices, startVertex) ? -1 : getMaxDist(graph, quantityOfAllVertices, startVertex, finishVertex)) << endl;
	return 0;
}
