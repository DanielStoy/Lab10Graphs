#include <iostream>
#include "..///Lab10GraphsDLL/Lab10GraphsDLL.h"

int main()
{
	Graph myGraph;
	myGraph.addEdge(1, 2);
	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 5);
	bool trueboi = myGraph.hasEdge(1, 3);
	bool falseboi = myGraph.hasEdge(1, 10);
	vector<int> getBois = myGraph.inEdges(1);
	vector<int> getBoisReturns = myGraph.outEdges(1);
	cout << myGraph.printMatrix();
}

//Todo's
//Deconstructor - not jakob wardega 
//Remove - jakob wardega
//Main Program	
//Reading in from a file
