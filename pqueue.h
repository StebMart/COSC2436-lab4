#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>

using namespace std;

struct node {
	string data;
	int priority;
	node* next = nullptr;
};

class pqueue {
public:


private:
	node* head = nullptr;
};




#endif