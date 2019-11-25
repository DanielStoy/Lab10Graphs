#include "pch.h"
#include "CppUnitTest.h"
#include "..///Lab10GraphsDLL/Lab10GraphsDLL.h"
#include <functional>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsUnitTests
{
	TEST_CLASS(GraphsUnitTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			Graph myGraph;

			Assert::IsNotNull(&myGraph);
		}

		TEST_METHOD(Constructor_Input)
		{
			Graph myGraph(4);

			string expectedStr = "Connected to 0: \nConnected to 1: \nConnected to 2: \nConnected to 3: \n";
			string givenStr = myGraph.printMatrix();
			Assert::AreEqual(givenStr, expectedStr);
		}

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

		TEST_METHOD(RemoveEdge)
		{
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 3);
			myGraph.addEdge(1, 5);
			Assert::IsTrue(myGraph.hasEdge(1, 2));

			myGraph.removeEdge(1, 2);
			Assert::IsFalse(myGraph.hasEdge(1, 2));
		}

		TEST_METHOD(RemoveEdge_Invalid)
		{
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 3);
			myGraph.addEdge(1, 5);
			
			Assert::IsFalse(myGraph.removeEdge(1, 9));
		}

		TEST_METHOD(HasEdge)
		{
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 3);
			myGraph.addEdge(1, 5);
			Assert::IsTrue(myGraph.hasEdge(1, 2));
		}

		TEST_METHOD(HasEdge_Invalid) {
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 3);
			myGraph.addEdge(1, 5);
			Assert::IsFalse(myGraph.hasEdge(1, 6));
		}

		TEST_METHOD(OutEdge)
		{
			Graph myGraph;
			myGraph.addEdge(1, 2);
			myGraph.addEdge(1, 3);
			myGraph.addEdge(1, 5);

			vector<int> expInts = { 1 };
			vector<int> givenInts = myGraph.outEdges(2);
			Assert::IsTrue(expInts == givenInts);
		}

		TEST_METHOD(OutEdge_Invalid)
		{
			Graph* myGraph = new Graph;
			myGraph->addEdge(1, 2);
			myGraph->addEdge(1, 3);
			myGraph->addEdge(1, 5);

			function<vector<int>(void)> f1 = [myGraph] { return myGraph->outEdges(7); };
			Assert::ExpectException<invalid_argument>(f1);
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

		TEST_METHOD(InEdge_False) {
			Graph myGraph;
			vector<int> myInts = { 3, 2, 1 };
			myGraph.addEdge(1, 5);
			myGraph.addEdge(1, 6);
			myGraph.addEdge(1, 7);
			Assert::AreNotEqual(myInts.at(0), myGraph.inEdges(1).at(0));
			Assert::AreNotEqual(myInts.at(1), myGraph.inEdges(1).at(1));
			Assert::AreNotEqual(myInts.at(2), myGraph.inEdges(1).at(2));
		}

		TEST_METHOD(InEdge_Invalid)
		{
			Graph* myGraph = new Graph;
			myGraph->addEdge(1, 2);
			myGraph->addEdge(1, 3);
			myGraph->addEdge(1, 5);

			function<vector<int>(void)> f1 = [myGraph] { return myGraph->inEdges(7);  };
			Assert::ExpectException<invalid_argument>(f1);
		}

		TEST_METHOD(Print) {
			Graph myGraph;
			string s = "Connected to 1: 5 \nConnected to 5: 1 \n";
			myGraph.addEdge(1, 5);
			Assert::AreEqual(s, myGraph.printMatrix());
		}

		TEST_METHOD(Print_Empty) {
			Graph myGraph;
			string s = "Empty Matrix";

			Assert::AreEqual(s, myGraph.printMatrix());
		}
	};
}
