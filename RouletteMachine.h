#include <iostream>
#include <string>

using namespace std;

struct Node {
	string data;
	Node *link;
};

class RouletteMachine {
public:
	RouletteMachine(); //constructor
	void add(string newItem); //inserting new item
	void addLast(string lastItem); //inserting last item
//this has to be different because we will link it back to the first item
	string spinWheel(int power);
private:
	Node *firstItem;
	Node *oneBefore;
	bool isFull;
	bool isEmpty;
};
