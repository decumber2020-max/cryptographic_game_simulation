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
    cout << "                  LEVEL 01                      \n";
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
        if (lives == 0) {
            cout << "\n";
            cout << "**************************************************\n";
            cout << "*                  GAME OVER                     *\n";
            cout << "**************************************************\n";
            break;
        }
    }

    return totalScore;
}

int level_3(int totalScore) {
    cin.ignore();
    totalScore += 30;
    int lives = 3;

    // Original secret messages
    string secretMessages[4] = {
        "ATTACK AT MIDNIGHT",
        "TRUST NO ONE",
        "FIND THE TRAITOR",
        "THE AGENT IS COMPROMISED"
    };

    // Mathematical encryption keys
    int a[4] = { 3, 5, 7, 9 };
    int b[4] = { 5, 7, 11, 4 };

    string encryptedMessage, reversedMessage;
    string playerGuess;

    cout << "\n================================";
    cout << "\n|       LEVEL 3: DOUBLE AGENT   |";
    cout << "\n================================\n";

    cout << "\n+--------------------------------+";
    cout << "\n| Intercepted Messages: 04       |";
    cout << "\n| Encryption Layers: 02          |";
    cout << "\n| Lives Remaining: " << lives << "           |";
    cout << "\n+--------------------------------+";
    cout << "\nDecrypt to gain access...\n";

    cout << "\n\nTwo encryption layers were used:";
    cout << "\n1. Reverse cipher";
    cout << "\n2. Mathematical cipher";

    for (int i = 0; i < 4; i++) {

        encryptedMessage = "";

        // First layer: Reverse the original message
        reversedMessage = "";
        int y = (secretMessages[i].length());

        for (int j = y - 1; j >= 0; j--) {
            reversedMessage += secretMessages[i][j];
        }
        // Second layer: Mathematical encryption
        for (int j = 0; j < reversedMessage.length(); j++) {

            char ch = reversedMessage[j];

            if (isalpha(ch)) {//if ch is a letter of alphabet

                int x = ch - 'A';//ch is converted to number(A=0,B=1,C=2...)

                int encrypted = (a[i] * x + b[i]) % 26;

                encryptedMessage += char(encrypted + 'A');//added as a alphabet letter
            }
            //executes for blank spaces
            else {
                encryptedMessage += ch;//to preserve spaces in message which are not charachter
            }
        }

        bool solved = false;

        cout << "\n\n --------------------------------";
        cout << "\n|           MISSION " << i + 1 << "           |";
        cout << "\n --------------------------------\n";

        cout << "\n| Encrypted message: " << encryptedMessage << " |";

        

        cout << "\n\nFormula: E(x) = (ax + b) mod 26";
        cout << "\nMultiplication key: " << a[i];
        cout << "\nAddition key: " << b[i];


        while (!solved && lives > 0) {

            cout << "\nEnter decrypted message: ";
            getline(cin, playerGuess);

            // Convert answer to uppercase
            for (int j = 0; j < playerGuess.length(); j++) {
                playerGuess[j] = toupper(playerGuess[j]);
            }

            if (playerGuess == secretMessages[i]) {

                cout << "\nCorrect! Message decrypted.";
                solved = true;

            }
            else {

                lives--;
                totalScore -= 10;

                cout << "\nIncorrect!";
                cout << "\nOne life lost.";
                cout << "\nRemaining lives: " << lives;
                cout << "\nCurrent score: " << totalScore;

                if (lives == 0) {

                    cout << "\n\n================================";
                    cout << "\n             GAME OVER";
                    cout << "\n================================";

                    break;
                }
            }
        }

        if (lives == 0) {
            break;
        }
    }

    if (lives > 0) {

        cout << "\n**************************************************\n";
        cout << "*              LEVEL 3 COMPLETED                 *\n";
        cout << "**************************************************\n";
    }
    cout << "\n";
    cout << "+------------------------------------------------+\n";
    cout << "|                 AGENT STATUS                   |\n";
    cout << "+------------------------------------------------+\n";
    cout << "|  FINAL SCORE : " << totalScore << endl;
    cout << "|  REMAINING LIVES : " << lives << endl;
    cout << "+------------------------------------------------+\n";
    cout << "\n";

    return totalScore;
}


int main() {

    srand(static_cast<unsigned int>(time(0)));

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
        if (totalScore > 0) {
            totalScore = level_3(totalScore);
        }  

        cout << "\nFinal Score: " << totalScore;

        // asking user if he wants to play again or not
        cout << "\n       [ PLAY AGAIN? YES / NO ]\n";

        cin >> playAgain;

        for (int i = 0; i < playAgain.length(); i++) {
            playAgain[i] = tolower(playAgain[i]);
        }

    } while (playAgain == "yes");

    cout << "\n>>> GAME COMPLETED <<<\n";
    cout << ">>> THANKS FOR PLAYING! <<<\n";
    cout << ">>> CONNECTION TERMINATED <<<\n";

    system("pause");
    return 0;
}