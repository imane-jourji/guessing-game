/*
	Imane Jourji
	Computer Science Fall 2024
	Due : Monday October 12, 2024 11:59pm
	Lab 4 : Guessing Game
	This lab's goal is to make a number-guessing game in which the computer selects a random number in the range of 0 to 100
*/


#include<iostream>
#include"GuessingGame.h"

int main ()
{
	GuessingGame GuessingGame;
	int choice = 0;

	std::cout << "Welcome to my Number Guessing Game!" << std::endl;

	while (true)
	{
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Display All Time Scores" << std::endl;
		std::cout << "3. Reset Scores" << std::endl;
		std::cout << "4. Exit" << std::endl;
		
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (choice == 1)
		{
			GuessingGame.playGame();
		}
		else if (choice == 2)
		{
			GuessingGame.displayAllTimeScores();
		}
		else if (choice == 3)
		{
			GuessingGame.resetScores();
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}
		
	return 0;
}