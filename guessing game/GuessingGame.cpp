#include"GuessingGame.h"
#include<iostream>
#include<fstream>


GuessingGame::GuessingGame()
{
	//initializing variables
	guess = 0;
	RandomNumber = 0;
	MaxOfGuesses = 0;
	AmountOfGuesses = 0;
	playAgain = ' ';
	TotalOfWins = 0;
	TotalOfLosses = 0;

}

GuessingGame::~GuessingGame()
{
}

void GuessingGame::playGame()
{
	if (canPlay == true)
	{
		do
		{
			srand(time(0));
			RandomNumber = rand() % 100 + 1;
			MaxOfGuesses = 20;
			AmountOfGuesses = 0;
			std::cout << "You have 20 try to guess the correct number between 0 and 100!" << std::endl;
			std::cout << "Please enter your guess: ";

			std::cin >> guess;
			
			while (guess < 0 || guess > 100)
			{
				std::cout << "Error, please enter a number between 0 and 100, try again!" << std::endl;
				std::cout << "Please enter your guess: ";
				while (true) {
					std::cin >> guess;

				}

			}
			while (guess != RandomNumber && AmountOfGuesses < MaxOfGuesses - 1)
			{
				
					std::cout << "Invalid choice, please try again!" << std::endl;
					std::cout << "Please enter your second guess: ";
					std::cin >> guess;
				}
				if (guess < RandomNumber)
				{
					std::cout << "Your guess is too low!" << std::endl;
				}
				else
				{
					std::cout << "Your guess is too high!" << std::endl;
				}
				
				AmountOfGuesses++;
				std::cout << "You have " << MaxOfGuesses - AmountOfGuesses << " guesses left!" << std::endl;
				std::cout << "Please enter your guess again: ";
				std::cin >> guess;
			}
			
		
			if (guess == randomNumber)
			{
				getMessagesWinlost();
				totalWins++;
				saveAllTimeScores();
			}
			
			else
			{
				getMessagesWinlost();
				std::cout << "The correct number was: " << randomNumber << std::endl;
				totalLosses++;
				saveAllTimeScores();
			}
			int i = 0;
			//while loop to check if the player wants to play again
			while (i == 0) {
				getMessages();

				std::cin >> playAgain;
				if (playAgain == "n")
				{
					std::cout << "You have chosen to quit the game!" << std::endl;
					i = 1;
				}
				else if (playAgain == "y")
				{
					std::cout << "You have chosen to play the game!" << std::endl;
					i = 1;
				}
				else if (playAgain == "EASTEREGG")
				{
					EASTEREGGbool = true;
					EASTEREGG();

				}
				else if (playAgain == "HELP" && EASTEREGGbool == true)
				{
					std::cout << "You have saved me! Thank you! I am free!" << std::endl;
					canPlay = false;
					i = 1;
				}
				else
				{
					std::cout << "Invalid choice, please try again!" << std::endl;
				}

			}

		} while (playAgain == "y");

	}
	else
	{
		std::cout << "You have freed the man in the game it will no longer work you must find a new person to trap in" << std::endl;
		std::cout << " here or you will be trapped forever" << std::endl;
	}
}


//gets the all time scores from a file
void GuessingGame::getAllTimeScores()
{
	std::ifstream inputfile;
	inputfile.open("TotalGamesData.dat");
	inputfile >> totalWins;
	inputfile >> totalLosses;
	inputfile.close();


}
//save the all time scores to a file
void GuessingGame::saveAllTimeScores()
{
	std::ofstream outputfile;
	outputfile.open("TotalGamesData.dat");
	outputfile << totalWins << std::endl;
	outputfile << totalLosses << std::endl;
	outputfile.close();
}
//display the all time scores
void GuessingGame::displayAllTimeScores()
{
	std::cout << "Total Wins: " << TotalOfWins << std::endl;
	std::cout << "Total Losses: " << TotalOfLosses << std::endl;
	std::cout << "Win Percentage: " << (TotalOfWins / (TotalOfWins + TotalOfLosses)) * 100 << "%" << std::endl;
}
//gets the messages for if the player wins or loses
void GuessingGame::getMessagesWinlost()
{
	srand(time(0));
	int RandomMessage = rand() % 10 + 1;
	if (guess == RandomNumber)
	{
		switch (RandomMessage)
		{
		case 1:
			std::cout << "CONGRATS! You did it, you guessed the correct number!" << std::endl;
			break;
		case 2:
			std::cout << "Fantastic ! You have guessed the correct number!" << std::endl;
			break;
		case 3:
			std::cout << "Genius! GOT IT RIGHT !" << std::endl;
			break;
		case 4:
			std::cout << "What a win! correct number indeed!" << std::endl;
			break;
		case 5:
			std::cout << "RIGHT!! No one have done it better! You are a pro!" << std::endl;
			break;
		case 6:
			std::cout << "Ding, ding, ding! We have a winner!" << std::endl;
			break;
		case 7:
			std::cout << "Woohoo! That’s the winning guess right there!" << std::endl;
			break;
		case 8:
			std::cout << "Boom! That’s what we’re talking about!" << std::endl;
			break;
		case 9:
			std::cout << "Winner, winner, number-guessing champion!" << std::endl;
			break;
		case 10:
			std::cout << "Yes! That’s how it’s done, amazing work!" << std::endl;
			break;

		}
	}
	else
	{

		switch (RandomMessage) //switch statement for the random messages
		{
		case 1:
			std::cout << "Close, but no cigar!" << std::endl;
			break;
		case 2:
			std::cout << "Missed it this time, but I believe in you!" << std::endl;
			break;
		case 3:
			std::cout << "Better luck next time! The number’s still hiding!" << std::endl;
			break;
		case 4:
			std::cout << "Nope! The number remains a mystery!" << std::endl;
			break;
		case 5:
			std::cout << "Not even close! The number laughs in your face!" << std::endl;
			break;
		case 6:
			std::cout << "Wrong answer! Better sharpen those guessing skills!" << std::endl;
			break;
		case 7:
			std::cout << "Swing and a miss! The number survives!" << std::endl;
			break;
		case 8:
			std::cout << "Fail! The number stays safe for now!" << std::endl;
			break;
		case 9:
			std::cout << "Absolutely not! That guess was tragic" << std::endl;
			break;
		case 10:
			std::cout << "Big miss! The number remains undefeated!" << std::endl;
		}
	}
}
//gets the messages for if the player wants to play again
void GuessingGame::getMessages()
{
	srand(time(0));
	int randomMessage = rand() % 10 + 1;

	switch (randomMessage)
	{
	case 1:
		std::cout << "Hmm, care to give it another shot?" << std::endl;
		break;
	case 2:
		std::cout << "Not quite—want to take another guess?" << std::endl;
		break;
	case 3:
		std::cout << "Missed it! Shall we go again?" << std::endl;
		break;
	case 4:
		std::cout << "Ready for another round?" << std::endl;
		break;
	case 5:
		std::cout << "Wrong guess! Wanna give it another go?" << std::endl;
		break;
	case 6:
		std::cout << "So close! Feel like trying again?" << std::endl;
		break;
	case 7:
		std::cout << "Oops, not the one! Up for another attempt?" << std::endl;
		break;
	case 8:
		std::cout << "Missed it! What do you say to another round?" << std::endl;
		break;
	case 9:
		std::cout << "Missed it! Feel lucky enough to try again?" << std::endl;
		break;
	case 10:
		std::cout << "Swing and a miss! Ready to strike out again?" << std::endl;
		break;
	}



}


void GuessingGame::resetScores() 
{
	TotalOfWins = 0;
	TotalOfLosses = 0;
	saveAllTimeScores();
}