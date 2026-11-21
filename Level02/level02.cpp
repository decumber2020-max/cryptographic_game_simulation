#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std;
int level02()
{
	int totalScore = 30;
	int lives;
	string playerGuess;
	string playingGame;
	//list of secret words
	string secretWord[10] = { "Manifesting","cool","splendid","fire","lovely","iconic","online","classy","sweet","development" };
	//list of keys
	string key[10] = { "creamy","royal","best","effortless","perfect","worth","divine","brillient","breathtaking","magical" };
	do
	{
		lives = 3;
		int randomIndex = rand() % 10;
		string realWorld = secretWord[randomIndex];
		string keys = key[randomIndex];
		string encryptedWord = "";

		// Convert secret word and key to uppercase
		for (int i = 0; i < realWorld.length(); i++)
		{
			realWorld[i] = toupper(realWorld[i]);
		}

		for (int i = 0; i < keys.length(); i++)
		{
			keys[i] = toupper(keys[i]);
		}


		for (int i = 0;i < realWorld.length();i++)
		{
			char letter = realWorld[i];
			char keyLetter = keys[i % keys.length()];

			int plainValue = letter - 'A';
			int keyValue = keyLetter - 'A';

			int encryptedValue = (plainValue + keyValue) % 26;
			char encryptedLetter = encryptedValue + 'A';
			encryptedWord += encryptedLetter;
		}
		cout << "======================================";
		cout << "====WELCOME TO LEVEL 02===============";
		while (lives > 0)
		{
			cout << "Encrypyed message: " << encryptedWord << endl;
			cout << "Secret key: " << keys << endl;
			cout << "HINT:use vigenere ciphere to decode" << endl;
			cout << "Enter decrypted word";
			cin >> playerGuess;
			for (int i = 0;i < playerGuess.length();i++)
			{
				playerGuess[i] = toupper(playerGuess[i]);
			}
			if (playerGuess == realWorld)
			{
				cout << "Excellent you have guessed the word correctly";
				totalScore += 40;
				cout << "Your score is " << totalScore << "Lives" << lives;
				cout << "Moving to level 03";
				break;
			}
			else
			{
				lives--;
				totalScore -= 10;
				cout << "Incorrect answer" << endl;
				cout << "lives remaining" << lives;
				cout << "Your score is" << totalScore;
			}
		}
		if (lives == 0)
		{
			cout << "Mission failed";
		}
		cout << "Do you want to play level 02 again";
		cin >> playingGame;

		for (int i = 0;i < playingGame.length();i++)
		{
			playingGame[i] = tolower(playingGame[i]);
		}
	} while (playingGame == "yes");
		return totalScore;
}
    int main()
	{
     level02();
	return 0;
     }
			

		

	
