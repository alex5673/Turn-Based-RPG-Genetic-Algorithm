// TurnBasedRPGGA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <iosfwd>

#include "Player.h"
#include "Enemy.h"
#include "GeneticAlgorithm.h"
#include "HandMadeAI.h"
#include "RandomAI.h"

using namespace std;

int main()
{
	Player player = Player(50, 30, 40, 20, 10, 20, 20, 20, 20, 3000, 150, 60, 35, 25);
	Enemy enemy = Enemy(60, 40, 35, 15, 40, 10, 10, 10, 10, 8000, 200, 60, 20, 20);

	GeneticAlgorithm ga = GeneticAlgorithm(enemy, player);
	// run GA 100 times
	vector<int> gaIterations;
	for (int i = 0; i < 100; i++) {
		gaIterations.push_back(ga.Run());
	}
	int sum = 0;
	int averageTurns = 0;
	vector<int>::iterator iter = begin(gaIterations);
	for(iter; iter != end(gaIterations); iter++)
	{
		int num = *iter;
		sum += num;
		averageTurns = sum / gaIterations.size();
	}
	ofstream file1 = ofstream();
	file1.open("GA.txt");
	file1 << "AI using GA average number of turns to reduce player's HP to 0 over 100 iterations = " << averageTurns << '\n';
	file1.close();

	RandomAI random = RandomAI(enemy, player);
	// run random AI 100 times
	vector<int> randomIterations;
	for (int i = 0; i < 100; i++) {
		randomIterations.push_back(random.Run());
	}
	sum = 0;
	averageTurns = 0;
	vector<int>::iterator iter2 = begin(randomIterations);
	for (iter2; iter2 != end(randomIterations); iter2++)
	{
		int num = *iter2;
		sum += num;
		averageTurns = sum / randomIterations.size();
	}
	ofstream file2 = ofstream();
	file2.open("RandomAI.txt");
	file2 << "RandomAI average number of turns to reduce player's HP to 0 over 100 iterations = " << averageTurns << '\n';
	file2.close();

	// run hand made AI once because it will always return same result based on the current player stats - hand crafted to be what I think is the best
	HandMadeAI handMade = HandMadeAI(enemy, player);
	ofstream file3 = ofstream();
	file3.open("HandMadeAI.txt");
	file3 << "Number of turns it takes for my hand made AI to reduce player's HP to 0 = " << handMade.Run() << '\n';
	file3.close();

    return 0;
}

