#include "pch.h"
#include "CppUnitTest.h"
#include "..///Lab10GraphsDLL/Lab10GraphsDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsUnitTests
{
	TEST_CLASS(GraphsUnitTests)
	{
	public:
		
		TEST_METHOD(AddEdge)
		{
			Graph myGraph;
			myGraph.addEdge(1, 2);
			Assert::IsTrue(myGraph.hasEdge(1, 2));
		}

		TEST_METHOD(AddmultiEdge) {
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 5);
			myGraph.addEdge(1, 6);
			myGraph.addEdge(15, 45);
			Assert::IsTrue(myGraph.hasEdge(1, 2));
			Assert::IsTrue(myGraph.hasEdge(1, 5));
			Assert::IsTrue(myGraph.hasEdge(1, 6));
			Assert::IsTrue(myGraph.hasEdge(15, 45));
		}

		TEST_METHOD(inEdge) {
			Graph myGraph;
			vector<int> myInts = { 5,6,7 };
			myGraph.addEdge(1, 5);
			myGraph.addEdge(1, 6);
			myGraph.addEdge(1, 7);
			Assert::AreEqual(myInts.at(0), myGraph.inEdges(1).at(0));
			Assert::AreEqual(myInts.at(1), myGraph.inEdges(1).at(1));
			Assert::AreEqual(myInts.at(2), myGraph.inEdges(1).at(2));
		}

		TEST_METHOD(inEdgeFalse) {
			Graph myGraph;
			vector<int> myInts = { 3, 2, 1 };
			myGraph.addEdge(1, 5);
			myGraph.addEdge(1, 6);
			myGraph.addEdge(1, 7);
			Assert::AreNotEqual(myInts.at(0), myGraph.inEdges(1).at(0));
			Assert::AreNotEqual(myInts.at(1), myGraph.inEdges(1).at(1));
			Assert::AreNotEqual(myInts.at(2), myGraph.inEdges(1).at(2));
		}

		TEST_METHOD(Print) {
			Graph myGraph;
			string s = "Connected to 1: 5 \nConnected to 5: 1 \n";
			myGraph.addEdge(1, 5);
			Assert::AreEqual(s, myGraph.printMatrix());
		}
	};
}
