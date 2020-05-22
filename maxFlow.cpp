
#include "Flow.h"

int main()
{
	stream graph;
	ifstream file;
	file.open("Ten_vertices_7.txt");
	graph.input(file);
	graph.SetVertexCount();
	graph.CreateAdjacencyMatrix();
	graph.printMatrix();
	graph.IsTransport_network();
	graph.getMaxFlow();
	file.close();
}