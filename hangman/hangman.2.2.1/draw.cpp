#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };

void renderGame(const string& guessedWord, const string& badGuesses)
{
	clearScreen();
	int badGuessCount = badGuesses.length();
	cout << FIGURE[badGuessCount] << endl;
	cout << "Secret word: " << guessedWord << endl;
	if (badGuessCount > 0) {
		cout << "You've made " << badGuessCount << " wrong ";
		cout << (badGuessCount == 1 ? "guess" : "guesses");
		cout << ": " << badGuesses << endl;
	}
}

const string DANCING_MAN[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    };

const string HANG_MAN[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      \n"
    "   |   /|\\    \n"
    "   |   / \\    \n"
    "   |        \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    "   ------------+     \n"
    "   |      \\         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n"
    };

void displayFinalResult(bool won, const string& word) {
    string result = won ? "Congratulations! You win!" : "You lost.";
    const string * images = won ? DANCING_MAN : HANG_MAN;
    int size = (won ? sizeof(DANCING_MAN) : sizeof(HANG_MAN)) / sizeof(string);

    int i = 0;
    while (true) {
        clearScreen();
        cout << result << " The correct word is " << word << endl;
        cout << images[i++ % size];
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
