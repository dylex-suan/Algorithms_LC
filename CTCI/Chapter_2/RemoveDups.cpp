// remove duplicates
// first try: implement with a hash map
#include <iostream>
#include <unordered_map>
#include <string>

class Node {
	private: 
		Node *next = nullptr;
		int data;	
	public:
		Node(int d);
		void addNextNode(int d);
		Node* getCurrNode();
		int getCurrData();
		Node* getNextNode();
};

class LinkedList {
	private: 
		Node *head = nullptr;
	public:
		LinkedList();	
		void addHeadNode(int d);
		Node* getHeadNode();

		// print out the list
		void printOutList();
};

Node::Node(int d) {
	this->next = nullptr;
	this->data = d;	
}

void Node::addNextNode(int d) {
	this->next = new Node(d);
}

Node* Node::getCurrNode() {
	return this;
}

int Node::getCurrData() {
	return this->data;
}

Node* Node::getNextNode() {
	return this->next;
}

LinkedList::LinkedList() {
	this->head = nullptr;	
}

void LinkedList::addHeadNode(int d) {
	this->head = new Node(d);
}

Node* LinkedList::getHeadNode() {
	return this->head;
}

void LinkedList::printOutList() {
	Node* head = this->head;
	while (head != nullptr) {
		std::cout << head->getCurrData();
		if (head->getNextNode() != nullptr) {
			std::cout << " ";
		}
		head = head->getNextNode();
	}

}


int main() {
	std::string str;	
	LinkedList list; // create a linked list
	int num;
	std::cout << "We are going to create a linked list." << std::endl;
	std::cout << "Please enter the number to add OR write END: ";
	std::cin >> str;
	if (str == "END") {
		return 0;
	}
	
	num = std::stoi(str);
	list.addHeadNode(num);	

	std::cout << "Please enter the number to add OR write END: ";
	std::cin >> str;

	Node* tmp = list.getHeadNode();

	while (str != "END") {
		num = std::stoi(str);
		tmp->addNextNode(num);
		tmp = tmp->getNextNode(); 		
		std::cout << "Please enter the number to add OR write END: ";
		std::cin >> str;
	}	
	
	list.printOutList();

	return 0;
}
