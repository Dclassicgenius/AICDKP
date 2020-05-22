#include "pch.h"
#include "CppUnitTest.h"
#include "../maxFlow/Flow.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace maxFlowTest
{
	TEST_CLASS(maxFlowTest)
	{
	public:
		Assert assert;
		TEST_METHOD(Input_)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text1.txt");
			matrix.input(file);
			assert.AreEqual(matrix.get_file_size(), 8);
			file.close();
		}

		TEST_METHOD(Input_InvalidGraph)
		{
			stream* matrix;
			matrix = new stream();
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\invalid_graph.txt");
			matrix->input(file);
			matrix->SetVertexCount();
			auto  funPtr = [matrix] {matrix->CreateAdjacencyMatrix(); };
			Assert::ExpectException<std::out_of_range>(funPtr);
			file.close();
		}

		TEST_METHOD(Test_with_negative_input)
		{
			stream* matrix;
			matrix = new stream();
			auto  funPtr = [matrix] {
				ifstream file;
				file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\negative_weight.txt");
				matrix->input(file); };
			Assert::ExpectException<std::out_of_range>(funPtr);
		}

		TEST_METHOD(_Input_no_flow_from_S_to_T)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\no_flow.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.IsTrue(matrix.IsTransport_network());
			file.close();
		}
		
		TEST_METHOD(TestSetVertexCount_1)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text1.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			assert.AreEqual(matrix.get_number_of_vertex(), 6);
		}

		TEST_METHOD(TestSetVertexCount_2)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text2.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			assert.AreEqual(matrix.get_number_of_vertex(), 7);
		}

		TEST_METHOD(IsTransportNetwork_1)
		{
			//normal transport graph 
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text2.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.IsTrue(matrix.IsTransport_network());
		}

		TEST_METHOD(IsTransportNetwork_2)
		{
			//graph with 2 end vertexes
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text3.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.IsFalse(matrix.IsTransport_network());
		}

		TEST_METHOD(IsTransportNetwork_3)
		{
			//graph with a cycle
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\cycle_graph.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			Assert::IsFalse(matrix.IsTransport_network());
		}
		TEST_METHOD(CreateAdjencyMatrix_)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text2.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
		}

		TEST_METHOD(getMaxFlow_1)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text1.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 5);
		}

		TEST_METHOD(getMaxFlow_2)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text2.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 7);
		}


		TEST_METHOD(getMaxFlow_3)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Text4.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 7);
		}

		TEST_METHOD(getMaxFlow_4)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\text5.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 10);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_1)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_1.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 21);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_2)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_2.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 26);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_3)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_3.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 28);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_4)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_4.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 14);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_5)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_5.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 18);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_6)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_6.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 50);
		}

		TEST_METHOD(getMaxFlow_Ten_vertices_7)
		{
			stream matrix;
			ifstream file;
			file.open("C:\\Users\\DCLASSICGENIUS\\source\\repos\\maxFlow\\maxFlowTest\\Ten_vertices_7.txt");
			matrix.input(file);
			matrix.SetVertexCount();
			matrix.CreateAdjacencyMatrix();
			assert.AreEqual(matrix.getMaxFlow(), 95);
		}
	};
}
