#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>

using namespace std;

struct node {
	string data;
	int priority;
	node* next = nullptr;
	node(string d, int p) { data = d; priority = p; }
};

class pqueue {
public:
	pqueue() { head = nullptr; }
	void enqueue(string data, int priority);
	void printall();
	string peek();
	string pop();
private:
	node* head = nullptr;
};

void pqueue::enqueue(string data, int priority) {
	node* temp = new node(data, priority);

	if (head == nullptr)
		head = temp;
	else if (priority < head->priority) {
		temp->next = head;
		head = temp;
	}
	else {
		node* cu = head;
		node* prev = nullptr;
		while (cu != nullptr && priority >= cu->priority) {
			prev = cu;
			cu = cu->next;
		}
		if (prev != nullptr) {
			temp->next = prev->next;
			prev->next = temp;
		}
		
	}
}

string pqueue::pop() {
	if (head == nullptr)
		return "";
	string data;
	node* temp = head;
	data = head->data;
	head = head->next;
	delete temp;
	return data;
}

string pqueue::peek() {
	if (head == nullptr)
		return " ";
	return head->data;
}

void pqueue::printall() {
	node* cu = head;
	cout << "printing..." << endl;
	while (cu != nullptr) {
		cout << cu->priority << ":" << cu->data << endl;
		cu = cu->next;
	}
	cout << endl;

}



#endif