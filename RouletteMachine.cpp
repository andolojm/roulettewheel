#include <iostream>
#include "RouletteMachine.h"
#include <unistd.h>
using namespace std;
//so we don't have to use std::name for everything

RouletteMachine::RouletteMachine(){
	firstItem = NULL;
	oneBefore = NULL;
	isFull = false;
	isEmpty = true;	
}
void RouletteMachine::add(string newItem){
	if(!isFull){
		Node *newNode;
		newNode = new Node;
		newNode->data = newItem;
		newNode->link = oneBefore;
		if(isEmpty){
			firstItem = newNode;
			oneBefore = newNode;
			isEmpty = false;
		} else {
			oneBefore = newNode;
		}
		cout << "Created new player: " << newItem << endl;
	} else {
		cout << "List is full, please stop adding" << endl;
	}
}
void RouletteMachine::addLast(string lastItem){
	if(!isEmpty && !isFull){
		Node *newNode;
		newNode = new Node;
		newNode->data = lastItem;
		newNode->link = oneBefore;
		oneBefore = newNode;
		firstItem->link = newNode;
		isFull = true;	
		cout << "Created new player: " << lastItem << endl << endl;
	} else {
		cout << "Please enter one or more items before adding the last one." << endl;
	}
}
string RouletteMachine::spinWheel(int power){
	cout << "The roulette wheel starts spinning!" << endl;
	Node *current;
	current = oneBefore;
	string winner = current->data;
	if(firstItem != NULL){
		for(int i = 0;i < power;i++){
			current = current->link;
			cout << winner << "'s name spins past." << endl;	
			winner = current->data;
			sleep(1);
		}
	sleep(2);
	cout << endl << "The wheel stops on " << winner << ". Congrats!" << endl << endl;
	}
	return winner;
}
