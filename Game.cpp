#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cctype>
using namespace std;
int level_1() {
	// Declaring variables
	int totalScore, lives, randomIndex;
	string playerGuess, realWord, encryptedWord;

	// secret word list
	string secretWords[10] = {
		"HELLO", "GAME", "MOBILE", "SECRET", "VAULT",
		"HACK", "MONEY", "GOLD", "BANK", "MASTER"
	};

	// Initialize variables
	lives = 3;
	totalScore = 30;
	playerGuess = "";
	randomIndex = rand() % 10;// from 0-9 total it can be 10
	realWord = secretWords[randomIndex];//word to guess
	encryptedWord = "";

	// Encryption | Caesar Cipher |
	for (int i = 0; i < realWord.length(); i++) {
		char letter = realWord[i];

		char shiftedLetter = ((letter - 'A' + 3) % 26) + 'A';//shifting letters forward by 3 places
		encryptedWord += shiftedLetter;
	}

	// Game Play
	cout << "\n";
	cout << "==================================================\n";
	cout << "                  MISSION 01                      \n";
	cout << "                 CAESAR CIPHER                    \n";
	cout << "==================================================\n";
	cout << "\n";

	while (lives > 0) {// it will run until lives become less then 0

		cout << "\nCipher: " << encryptedWord << endl;
		cout << "HINT: Shift each letter backward by 3 places.\n";
		cout << "Enter decrypted Word: ";
		cin >> playerGuess;

		for (int i = 0; i < playerGuess.length(); i++) {
			playerGuess[i] = toupper(playerGuess[i]);// converting all use entered letters to capital
		}

		if (playerGuess == realWord) {
			cout << "\nEXCELLENT: You decrypted the word correctly. Moving to Level 2\n";
			cout << "\n";
			cout << "+------------------------------------------------+\n";
			cout << "|                 AGENT STATUS                   |\n";
			cout << "+------------------------------------------------+\n";
			cout << "|  SCORE : " << totalScore << endl;
			cout << "|  LIVES : " << lives << endl;
			cout << "+------------------------------------------------+\n";
			cout << "\n";
			cout << "**************************************************\n";
			cout << "*              MISSION COMPLETED                 *\n";
			cout << "**************************************************\n";

			break;
		}
		else {
			//if the answers is wrong lives get decreasing
			lives -= 1;
			totalScore -= 10;
			cout << "\n";
			cout << "+------------------------------------------------+\n";
			cout << "|                 AGENT STATUS                   |\n";
			cout << "+------------------------------------------------+\n";
			cout << "| Incorrect!! " << endl;
			cout << "|  SCORE : " << totalScore << endl;
			cout << "|  LIVES : " << lives << endl;
			cout << "+------------------------------------------------+\n";
			cout << "\n";

		}
	}

	return totalScore;
}


int main() {

	srand(time(0));

	string playAgain;

	do {
		//----------------------game interface---------------------------
		cout << "\n";
		cout << "**************************************************\n";
		cout << "*                                                *\n";
		cout << "*              CIPHER  //  BREACH                *\n";
		cout << "*                                                *\n";
		cout << "*          THE ULTIMATE CRYPTO GAME              *\n";
		cout << "*                                                *\n";
		cout << "**************************************************\n";
		cout << "\n";
		cout << "       [ SYSTEM STATUS : ONLINE ]\n";
		cout << "       [ ACCESS LEVEL  : CLASSIFIED ]\n";
		cout << "\n";

		int totalScore = 0;

		totalScore += level_1();
		

		cout << "\nFinal Score: " << totalScore;
		// asking user if he wants to play a game again or not

		cout << "\n       [ PLAY AGAIN? YES / NO ]\n";

		cin >> playAgain;

		for (int i = 0; i < playAgain.length(); i++) {
			playAgain[i] = tolower(playAgain[i]);// converting all user entered letters to lower case
		}

	} while (playAgain == "yes");

	cout << "\n>>> GAME COMPLETED <<<\n";
	cout << ">>> THANKS FOR PLAYING! <<<\n";
	cout << ">>> CONNECTION TERMINATED <<<\n";

	system("pause");
	return 0;
}
