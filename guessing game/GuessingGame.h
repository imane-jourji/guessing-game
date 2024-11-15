#include <iostream>
#ifndef GuessingGame_H
#define GuessingGame_H

class GuessingGame
{
public:
	GuessingGame();
	~GuessingGame();
	void playGame();
	void getAllTimeScores();
	void saveAllTimeScores();
	void displayAllTimeScores();
	void getMessagesWinlost();
	void getMessages();
	void resetScores();

private:
	bool canPlay = true;
	int guess = 0;
	int RandomNumber = 0;
	int MaxOfGuesses = 0;
	int AmountOfGuesses = 0;
	std::string playAgain = " ";
	float TotalOfWins = 0;
	float TotalOfLosses = 0;
	bool EASTEREGGbool = false;
};


#endif  //!GuessingGame_H
