// Lab10GraphsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Lab10GraphsDLL.h"
#include <stdexcept>

Node::Node(int Val, Node* Next) {
	val = Val;
	next = Next;
}

Graph::Graph() {

}

Graph::Graph(int numVertex)
{
	for (int i = 0; i < numVertex; i++)
	{
		Node* temp = new Node(i, nullptr);
		graphPoints.push_back(temp);
	}
}

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

//NOT WORKING
//I WROTE IT BAD
bool Graph::removeEdge(int b, int c) {
	//Check if graph has that edge
	if (!hasEdge(b, c))
	{
		return false;
	}

	//Remove b -> c
	int spot = FindPoint(b);
	Node* temp = graphPoints[spot];
	while (temp->next->val != c)
	{
		temp = temp->next;
	}
	//Make sure that no value is lost from the deletion of the node.
	Node* nodeToRemove = temp->next;
	if (nodeToRemove->next == nullptr)
	{
		temp->next == nullptr;
	}
	else
	{
		temp->next == nodeToRemove->next;
	}

	//Remove c -> b
	spot = FindPoint(c);
	temp = graphPoints[spot];
	while (temp->next->val != b)
	{
		temp = temp->next;
	}
	//Make sure that no value is lost from the deletion of the node.
	nodeToRemove = temp->next;
	if (nodeToRemove->next == nullptr)
	{
		temp->next == nullptr;
	}
	else
	{
		temp->next == nodeToRemove->next;
	}

	return false;
}

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
