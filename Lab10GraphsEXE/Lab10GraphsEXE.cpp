#include <iostream>
#include "..///Lab10GraphsDLL/Lab10GraphsDLL.h"
#include <fstream>


int main()
{
	std::ifstream file;
	file.open("..//matrix.txt");
	
	std::string str;
	
	//getline(file, str);

	vector<Node*> myPoints;


	int i = 0;
	Node* temp;
	while (getline(file, str)/*str != ""*/)
	{
		myPoints.push_back(new Node(i, nullptr));
		temp = myPoints[i];
		for (int j = 0; j < size(str); j++)
		{
			if (str[j] == '1')
			{
				temp->next = new Node(j, nullptr);
				temp = temp->next;
			}
			
		}
		i++;
		//getline(file, inputRow);
	}
	file.close();

	
	Graph readInGraph(myPoints);
	cout << readInGraph.printMatrix();

	Graph myGraph;

	int action;
	int p1;
	int p2;
	int vertices;
	vector <int> vals;

	cout << "Input number of vertices:" << endl;
	cin >> vertices;

	while (vertices < 0)
	{
		cout << "Enter a positive number:" << endl;
		cin >> vertices;
	}

	if (vertices > 0)
	{
		Graph myGraph(vertices);
	}
	else if (vertices == 0)
	{
		Graph myGaph();
	}

	cout << "Press 1 to add an edge to graph. \nPress 2 remove an edge from graph. \nPress 3 Find an edge in the graph." << endl;
	cout << "Press 4 Find the out edges of a vertices. \nPress 5 Find the in edges of a vertices. \nPress 6 To Print out Adjacency Matrix." << endl;
	cout << "Press 7 to quit." << endl;
	cin >> action;
	while (action != 7)
	{
		switch (action)
		{
		case 1:
			cout << "INSERTING EDGE BETWEEN TWO POINTS" << endl;
			cout << "Enter first point for edge." << endl;
			cin >> p1;
			cout << "Enter second point for edge." << endl;
			cin >> p2;
			myGraph.addEdge(p1, p2);
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		case 2:
			cout << "REMOVING EDGE BETWEEN TWO POINTS" << endl;
			cout << "Enter first point for edge." << endl;
			cin >> p1;
			cout << "Enter second point for edge." << endl;
			cin >> p2;
			myGraph.removeEdge(p1, p2);
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		case 3:
			cout << "FINDING EDGE BETWEEN TWO POINTS" << endl;
			cout << "Enter first point for edge." << endl;
			cin >> p1;
			cout << "Enter second point for edge." << endl;
			cin >> p2;
			if (myGraph.hasEdge(p1, p2))
				cout << "Edge was found." << endl;

			else
				cout << "Edge not found." << endl;

			cout << "Enter new action." << endl;
			cin >> action;
			break;

		case 4:
			cout << "FINDING OUT EDGE OF A POINT" << endl;
			cout << "Enter point for out edges." << endl;
			cin >> p1;
			vals = myGraph.outEdges(p1);
			cout << "Out edges: ";
			for (int i = 0; i < size(vals); i++) 
			{ 
				cout << vals[i] + " ";
			}
			cout << endl;
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		case 5:
			cout << "FINDING IN EDGE OF A POINT" << endl;
			cout << "Enter point for in edges." << endl;
			cin >> p1;
			vals = myGraph.inEdges(p1);
			cout << "In edges: ";
			for (int i = 0; i < size(vals); i++)
			{				
				cout << vals[i] + " ";
			}
			cout << endl;
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		case 6:
			cout << "PRINTING ADJACENCY MATRIX." << endl;
			cout << myGraph.printMatrix();
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		default:
			cout << "INVALID INPUT" << endl;
			cout << "Enter new action." << endl;
			cin >> action;
			break;

		}
	}
}

//Todo's
//Deconstructor - not jakob wardega 
//Remove - jakob wardega
//Main Program	
//Reading in from a file
