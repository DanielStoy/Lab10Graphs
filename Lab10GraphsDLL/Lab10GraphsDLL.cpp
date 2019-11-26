// Lab10GraphsDLL.cpp : Defines the exported functions for the DLL.
//

//#include "..//TxtFileHolder/"
#include "framework.h"
#include "Lab10GraphsDLL.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//Custom Node constructor
Node::Node(int Val, Node* Next) {
	val = Val;
	next = Next;
}

//Default Graph constructor
Graph::Graph() {

}

//Custom Graph constructor that initializes points
Graph::Graph(int numVertex)
{
	for (int i = 0; i < numVertex; i++)
	{
		Node* temp = new Node(i, nullptr);
		graphPoints.push_back(temp);
	}
}

Graph::Graph(vector<Node*> points)
{
	graphPoints = points;
}

//Destroyies every linked list in the vectors
Graph::~Graph() {
	for (int i = graphPoints.size() - 1; i >= 0; i--)
	{
		Node* temp = graphPoints[i];

		if (temp->next == nullptr)
		{

		}
		else 
		{
			while (temp->next != NULL)
			{
				Node* prv = temp;
				temp = temp->next;
				delete prv;
			}
		}
		delete temp;
	}
	
	graphPoints.empty();
}

//Reads the adjacency matrix from "Matrix.txt"
Graph Graph::ReadTxtFile()
{
	Graph myGraph;

	std::ifstream file;
	file.open("..//matrix.txt");

	std::string inputRow;
	int i = 0;
	Node* temp;
	getline(file, inputRow);
	while (inputRow != "")
	{
		myGraph.graphPoints.push_back(new Node(i, nullptr));
		temp = myGraph.graphPoints[i];
		for (int j = 0; j < inputRow.length(); j++)
		{
			if (inputRow[j] == '1')
			{
				temp->next = new Node(j, nullptr);
				temp = temp->next;
			}
			i++;
		}
		getline(file, inputRow);
	}
	file.close();

	return myGraph;
}
//Finds the location in graphPoints of the specified value
int Graph::FindPoint(int val) {
	for (int i = 0; i < graphPoints.size(); i++) {
		if (graphPoints[i]->val == val) {
			return i;
		}
	}
	return -1;
}

//3 cases, either we don't have anything, we have the value in our list, if so we need to add a new stop
//Or we don't have the value in our list, in which case we need to add it
bool Graph::addEdge(int b, int c) {
	if (graphPoints.size() == 0) {
		graphPoints.push_back(new Node(b, new Node(c, NULL)));
		graphPoints.push_back(new Node(c, new Node(b, NULL)));
	}
	else {
		int spot = FindPoint(b);
		if (spot != -1) {
			Node* Temp = graphPoints[spot];
			while (Temp->next != NULL) {
				Temp = Temp->next;
			}
			Temp->next = new Node(c, NULL);
		}
		else {
			graphPoints.push_back(new Node(b, new Node(c, NULL)));
		}
		spot = FindPoint(c);
		if (spot != -1) {
			Node* Temp2 = graphPoints[spot];
			while (Temp2->next != NULL) {
				Temp2 = Temp2->next;
			}
			Temp2->next = new Node(b, NULL);
		}
		else {
			graphPoints.push_back(new Node(c, new Node(b, NULL)));
		}
	}
	return false;
}

//Method to remove an edge
//Does not remove a point from the graph
bool Graph::removeEdge(int b, int c) {
	//Check if graph has that edge
	//Else exit the code with an error
	if (!hasEdge(b, c))
	{
		return false;
	}

	//Remove b -> c
	int spot = FindPoint(b);
	Node* temp = graphPoints.at(spot);
	while (temp->next->val != c)
	{
		temp = temp->next;
	}
	//Make sure that no value is lost from the deletion of the node.
	Node* nodeToRemove = temp->next;

	temp->next = nodeToRemove->next;
	delete nodeToRemove;
	
	//Remove c -> b
	spot = FindPoint(c);
	temp = graphPoints[spot];
	while (temp->next->val != b)
	{
		temp = temp->next;
	}
	//Make sure that no value is lost from the deletion of the node.
	nodeToRemove = temp->next;
	temp->next = nodeToRemove->next;
	delete nodeToRemove;

	return false;
}

//Checks if the graph has an edge
bool Graph::hasEdge(int b, int c) {
	int spot = FindPoint(b);
	if (spot != -1) {
		Node* Temp = graphPoints[spot];
		while (Temp->next != NULL) {
			if (Temp->next->val == c) {
				return true;
			}
			Temp = Temp->next;
		}
	}
	return false;
}

//Fast boi
//Returns which points go into a specified point
vector<int> Graph::inEdges(int c) {
	vector<int> vals;
	int spot = FindPoint(c);
	if (spot == -1)
	{
		throw invalid_argument("val");
	}
	Node* Temp = graphPoints[spot];
	while (Temp->next != NULL) {
		vals.push_back(Temp->next->val);
		Temp = Temp->next;
	}
	return vals;
}

//May also be able to do inedges method here since all points are connected and none are just one way
//But this is probably the logic that they're looking for
//
//Returns a list of points that have an edge shared with the specified point
vector<int> Graph::outEdges(int b) {
	if (FindPoint(b) == -1)
	{
		throw invalid_argument("val");
	}
	vector<int> vals;
	vector<int> connectors;
	for (int i = 0; i < graphPoints.size(); i++) {
		connectors = inEdges(graphPoints[i]->val);
		for (int j = 0; j < connectors.size();j++) {
			if (connectors[j] == b) {
				vals.push_back(graphPoints[i]->val);
			}
		}
	}

	return vals;
}

//Prints out the Graph in its matrix form
string Graph::printMatrix() {
	if (graphPoints.size() == 0)
	{
		return "Empty Matrix\n";
	}
	string s;
	Node* Temp;
	for (int i = 0; i < graphPoints.size(); i++) {
		Node* Temp = graphPoints[i];
		s += "Connected to " + to_string(Temp->val) + ": ";
		while (Temp->next != NULL) {
			s += to_string(Temp->next->val) + " ";
			Temp = Temp->next;
		}
		s += "\n";
	}
	return s;
}
