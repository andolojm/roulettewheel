#include <iostream>
#include <string>
#include "RouletteMachine.h"
#include <random>
#include <functional>
using namespace std;

int getRandInt(int min, int max);

int main(){
	
	cout << endl; //a little spacing never hurt
	
	int randInt = getRandInt(30,50);
	


	RouletteMachine x;
	bool stillAdding = true;
	int count = 0;
	while(stillAdding || count < 2){
		cout << "Enter a player, or GO to spin the wheel:  ";
		string player;
		cin >> player;
		count++;
		if(player == "GO"){
			if(count < 2){
				cout << "Not enough players yet! Keep adding!" << endl;
			} else {
				stillAdding = false;
			}
		} else {
			x.add(player);
		}
	}
	x.addLast("The Empty Space");
	x.spinWheel(randInt);
	return 0;
}

int getRandInt(int min, int max){

	uniform_int_distribution<int> unif(30,50);
	random_device rd;
	mt19937 engine(rd());
	function<unsigned int()> rnd = std::bind(unif, engine);

	int randInt = rnd();

	return randInt;
}
