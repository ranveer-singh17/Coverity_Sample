#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;



const int MAX_BAD_GUESSES = 7;

string chooseWord()
{
	int randomIndex = rand() % WORD_COUNT;
	return WORD_LIST[randomIndex];
}

char readAGuess()
{
	char c;
	cin >> c;
	return c;
}

bool contain(char guess, const string& word)
{
	return word.find_first_of(guess) != string::npos;
}

void renderGame(string guessedWord, int badGuessCount)
{
	cout << guessedWord <<endl;
	cout << "Number of wrong guess: " << badGuessCount << endl;
}

void update(string& guessedWord, char& guess, const string& word)
{
	int i;
	for(i = word.length(); i >= 0; i--)
	{
		if(word[i] == guess)
		{
			guessedWord[i] = guess;
		}
	}
}

void hangman()
{
	string word = chooseWord();
	string guessedWord = string(word.length(), '-');
	int badGuessCount = 0;
	do
	{
		renderGame(guessedWord, badGuessCount);
		char guess = readAGuess();
		if(contain(guess, word))
		{
			update(guessedWord, guess, word);
		}
		else badGuessCount++;
	}while(badGuessCount < MAX_BAD_GUESSES && guessedWord != word);
	renderGame(guessedWord, badGuessCount);
	if(badGuessCount != MAX_BAD_GUESSES) cout << "Congratulation! You Win!!!" << endl;
	else cout << "You lose!!!!! The correct word is:" << word << endl;
}

void askIfPlayAgain(char& c)
{
	cout << "Do you want to play again? (Y/N)" << endl;
	cin >> c;
}

int main()
{
	srand(time(0));
	char c;
	do
	{
		hangman();
		askIfPlayAgain(c);
	}while(c == 'y' || c == 'Y');
	return 0;
}
