#include <iostream>
#include <fstream>
#include <string>
#include "pqueue.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));

	/*ifstream input("input1.txt");
	ofstream output("output.txt");*/
	
	string line, action, p;
	int priority = -1, i;
	pqueue queue;

	// reading lines from file and adding all valid imputs into priority queue
	while (getline(input, line)) {
		action = p = "";
		i = 0;
		while (line[i] != '(' && i < line.length()) {
			action += line[i];
			i++;
		}
		if (i < line.length())
			i++;
		while (line[i] != ')' && i < line.length()) {
			p += line[i];
			i++;
		}
		if (action != "")
			action.pop_back();
		if (p != "")
			priority = stoi(p);

		if (action == "open the door")
			queue.enqueue(action, priority);
		else if (action == "close the door")
			queue.enqueue(action, priority);
		else if (action == "unlock the door")
			queue.enqueue(action, priority);
		else if (action == "lock the door")
			queue.enqueue(action, priority);
	}
	//queue.printall(); // printing for testing
	// reading all of the items from priority queue;
	bool open = true, locked = false;
	string instruction = "";

	while (queue.peek() != " ") {
		instruction = queue.pop();
		if (instruction == "open the door") {
			if (locked == false)
				open = true;
		}
		else if (instruction == "close the door") {
			if (locked == false)
				open = false;
		}
		else if (instruction == "unlock the door") {
			locked = false;
		}
		else if (instruction == "lock the door") {
			locked = true;
		}
	}

	if (open == true)
		output << "the door is open";
	else if (open == false)
		output << "the door is closed";

	input.close();
	output.close();

	return 0;
}