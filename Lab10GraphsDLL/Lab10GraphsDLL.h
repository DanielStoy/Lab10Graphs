#ifdef LAB10GRAPHSDLL_EXPORTS
#define LAB10GRAPHSDLL_API __declspec(dllexport)
#else
#define LAB10GRAPHSDLL_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
using namespace std;
class LAB10GRAPHSDLL_API Node {
public:
	Node(int Val, Node* Next);
	int val;								//Represents a point
	Node* next;								//The next pointer represents an edge between two points
};

class LAB10GRAPHSDLL_API Graph {
private:
	vector<Node*> graphPoints;
	int FindPoint(int val);
public:
	Graph();								// constructor
	Graph(int num);							// constructor 
	Graph(vector<Node * > points);
	Graph ReadTxtFile();						// Reads "Matrix.txt"
	bool addEdge(int b, int c);				// Adds the edge (b,c) to E
	bool removeEdge(int b, int c);			// Removes the edge (b,c) from E
	bool hasEdge(int b, int c);				// Checks if (b,c) spans E
	vector<int> outEdges(int b);			// given b, Returns a set of cs for bRc that spans E
	vector<int> inEdges(int c);				// given c, Returns a set of bs for bRc that spans E
	string printMatrix();					// columns : bs rows: all cs for bRc
	~Graph();								// Deconstructor
};
