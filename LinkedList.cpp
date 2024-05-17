#include <iostream>

// Part 1: Implementing the initial Node class
class Node {
public:
	Node(int iData) : m_iData(iData), mp_nodeNext(nullptr) { }
	~Node() { }
public:
	int m_iData;
	Node* mp_nodeNext;

public:
	static void displayList(Node* p_nodeHead)
	{
		Node* p_node = p_nodeHead;
		while (p_node != nullptr) {
			std::cout << p_node->m_iData << " ";
			p_node = p_node->mp_nodeNext;
		}
		std::cout << std::endl;
	}
};

int main()
{
	// Allocate three node objects within heap memory for int.
	Node* p_node1 = new Node(10);
	Node* p_node2 = new Node(20);
	Node* p_node3 = new Node(30);

	Node* p_nodeHead = p_node1;
	p_node1->mp_nodeNext = p_node2;
	p_node2->mp_nodeNext = p_node3;
	p_node3->mp_nodeNext = nullptr;

	Node::displayList(p_nodeHead);

	// Clean up allocated memory for int nodes
	delete p_node1;
	delete p_node2;
	delete p_node3;

	// Part 2: Implementing the template version of the Node class
	{
		// Template Node class
		template <typename T>
		class NodeT {
		public:
			NodeT(T data) : m_data(data), mp_nodeNext(nullptr) { }
			~NodeT() { }
		public:
			T m_data;
			NodeT* mp_nodeNext;

		public:
			static void displayList(NodeT* p_nodeHead)
			{
				NodeT* p_node = p_nodeHead;
				while (p_node != nullptr) {
					std::cout << p_node->m_data << " ";
					p_node = p_node->mp_nodeNext;
				}
				std::cout << std::endl;
			}
		};

		// Allocate three node objects within heap memory for int.
		NodeT<int>* p_node1_int = new NodeT<int>(10);
		NodeT<int>* p_node2_int = new NodeT<int>(20);
		NodeT<int>* p_node3_int = new NodeT<int>(30);

		NodeT<int>* p_nodeHead_int = p_node1_int;
		p_node1_int->mp_nodeNext = p_node2_int;
		p_node2_int->mp_nodeNext = p_node3_int;
		p_node3_int->mp_nodeNext = nullptr;

		NodeT<int>::displayList(p_nodeHead_int);

		// Clean up allocated memory for int nodes
		delete p_node1_int;
		delete p_node2_int;
		delete p_node3_int;

		// Allocate three node objects within heap memory for double.
		NodeT<double>* p_node1_double = new NodeT<double>(10.1);
		NodeT<double>* p_node2_double = new NodeT<double>(20.2);
		NodeT<double>* p_node3_double = new NodeT<double>(30.3);

		NodeT<double>* p_nodeHead_double = p_node1_double;
		p_node1_double->mp_nodeNext = p_node2_double;
		p_node2_double->mp_nodeNext = p_node3_double;
		p_node3_double->mp_nodeNext = nullptr;

		NodeT<double>::displayList(p_nodeHead_double);

		// Clean up allocated memory for double nodes
		delete p_node1_double;
		delete p_node2_double;
		delete p_node3_double;
	}

	return 0;
}
