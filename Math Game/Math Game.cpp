// Math Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;


//enums
enum enLevel{Easy = 1 , Medium, Hard, Mixs};
enum enOperations{Add = 1,Sub,Mult,Div,Mix};
//end


//Rand Function
int RandomNumber(int from,int to) {
		int Random = rand() % (to - from + 1) + from;
	
	return Random;
}
//end


enOperations GetRandomOperation() {

	return (enOperations)RandomNumber(1,4);
}

enLevel GetRandomLevel() {

	return (enLevel)RandomNumber(1, 3);
}
struct result{
	int RightAnswers = 0;
	int WrongAnswers = 0;
	
};

string GetOperationSymbol(enOperations Operation) {
	switch (Operation) {
	case Add:
		return " + ";
	case Sub:
		return " - ";
	case Mult:
		return " x ";
	case Div:
		return " / ";
	default:
		return "Invalid Value";
	}
}
int readHowManyRounds() {
	int rounds = 0;
	do
	{
		cout << "Enter How Many Round You Want Play: ";
		cin >> rounds;
	} while (rounds<1);
	return rounds;
}
enOperations GetPlayerOperationsChoice(short& OperationsChoice) {
	do {
		cout << "\n==============================\n";
		cout << "\tMath Game\n";
		cout << "\n==============================\n";

		cout << "\nChoices: ";
		cout << "\n\n";
		cout << "[1] Add\n";
		cout << "[2] Sub\n";
		cout << "[3] Mult\n";
		cout << "[4] Div\n";
		cout << "[5] Mix\n\n";
		cout << "Choice: ";
		cin >> OperationsChoice;
	} while (OperationsChoice < 1 || OperationsChoice > 5);
	return (enOperations)OperationsChoice;
}


enLevel GetPlayerLevelChoice(short& LevelChoice) {
	do{
		cout << "\n==============================\n";
		cout << "\tMath Game\n";
		cout << "\n==============================\n";

	cout << "\nChoices: ";
	cout << "\n\n";
	cout << "[1] Easy\n";
	cout << "[2] Medium\n";
	cout << "[3] Hard\n";
	cout << "[4] Mix\n\n";
	cout << "Choice: ";
	cin >> LevelChoice;
   } while (LevelChoice < 1 || LevelChoice > 4);
	return (enLevel)LevelChoice;
}
int Levels(short LevelChoice)
{
	switch (LevelChoice)
	{
	case Easy:
		return RandomNumber(1, 12);

	case Medium:
		return RandomNumber(30, 60);

	case Hard:
		return RandomNumber(80, 130);

	case Mixs:
		return Levels(GetRandomLevel());
	}

	return 0;
}
int divF(int& numberOne, int& NumberTwo, int LevelChoice)
{
	NumberTwo = Levels(LevelChoice);

	int Result = RandomNumber(1, 10);

	numberOne = NumberTwo * Result;

	return Result;
}


int GenrateQustions(enOperations& OperationsChoice, enLevel LevelChoice, int& numberOne, int& numberTwo)
{
	if (OperationsChoice == Mix)
	{
		OperationsChoice = GetRandomOperation();
	}

	if (OperationsChoice == Div)
	{
		return divF(numberOne, numberTwo, LevelChoice);
	}

	numberOne = Levels(LevelChoice);
	numberTwo = Levels(LevelChoice);

	switch (OperationsChoice)
	{
	case Add:
		return numberOne + numberTwo;

	case Sub:
		return numberOne - numberTwo;

	case Mult:
		return numberOne * numberTwo;
	}

	return 0;
}



bool PlayRound(enOperations Operations, enLevel Level)
{
	int Result;
	int number1, number2;

	if (Operations == Mix)
	{
		Operations = GetRandomOperation();
	}

	int qustions = GenrateQustions(Operations, Level, number1, number2);

	cout << number1 << GetOperationSymbol(Operations) << number2 << " = ?\n";

	cin >> Result;

	cout << "==============================\n";

	if (Result == qustions)
	{
		system("color 2");
		cout << "\n\tRight Answer\n";
		cout << "\n==============================\n";
		return true;
	}
	else
	{
		system("color 4");
		cout << "==============================\n";
		cout << "\nWrong Answer\n";
		cout << "Right Answer : " << qustions << endl;
		cout << "==============================\n";
		return false;
	}
}
void GameResult(result& re, bool s) {
	
	if (s == true)
		re.RightAnswers++;
	else 
		re.WrongAnswers++;
}
void ResetGameResult(result& re){
	re.RightAnswers = 0;
	re.WrongAnswers = 0;
}
void StartGame() {
	result Gameresult;
	int PlayAgain;
	do {
	int read = readHowManyRounds();

	short OperationsChoice;
	short LevelChoice;
	ResetGameResult(Gameresult);
	enOperations Operations = GetPlayerOperationsChoice(OperationsChoice);
	enLevel Level = GetPlayerLevelChoice(LevelChoice);

	
		for (int i = 0; i < read; i++) {

			cout << "Round [" << i + 1 << "]\n\n";

			bool Result = PlayRound(Operations, Level);

			GameResult(Gameresult, Result);
		}

		cout << "\n==============================\n";
		cout << "\n\tGame Result\n";
		cout << "\n==============================\n";

		cout << "\tStatus\n";

		if (Gameresult.RightAnswers > Gameresult.WrongAnswers)

			cout << "Winner\n";
		else if (Gameresult.RightAnswers == Gameresult.WrongAnswers)
			cout << "Draw\n";
		else {
			cout << "Loser\n";
		}
		cout << "Wins: " << Gameresult.RightAnswers << endl;
		cout << "Loses: " << Gameresult.WrongAnswers << endl;
		cout << "\n==============================\n";
		cout << "\tDo You Play Again?\n\n";
		cout << "[1] Leave \n";
		cout << "[2] Play Again \n";
		cout << "\n==============================\n";
		system("color 07");
		cin >> PlayAgain;
		
	} while (PlayAgain == 2);
}

int main() {
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}