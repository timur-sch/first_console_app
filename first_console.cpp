#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int tries = 6;
char *word_1 = new char[30]();
char *word_2 = new char[30]();
int bulls = 0;
int cows = 0;
void compare();
void beginning_input();
void input();
void checkwon();
void playagain();
bool ending = false;
int wordlength = 0;
string var_playagain = "";


int main() {
	
	beginning_input();
	
	do 
	{
		input();
		compare();
		checkwon();
	} while (ending == false);
	
 
	

system("pause");
}


void compare() 
{

	if (strlen(word_1) == strlen(word_2))
	{

		for (int x = 0; x <= wordlength - 1; x++) {
			
			{

				if (word_1[x] == word_2[x])
				{
					

						bulls = bulls + 1;
				

					
				}

				else
				{
					for (int i = 0; i <= wordlength - 1; i++)

						if (word_1[i] == word_2[x])
						{

							cows = cows + 1;


						}


				}


			}

		}



		cout << "You've guessed " << bulls << " bulls and " << cows << " cows." << endl;
		tries = tries - 1;
	}
	else
	{

		cout << "Wrong word length." << endl;
		input();
		

	}


	
	
	
}

void beginning_input()
{

	cout << "Type in the word for player2 to guess:" << endl;
	cin >> word_1;
	string wort1string = string(word_1);

	if (all_of(wort1string.begin(), wort1string.end(), islower))
	{
	
	cout << "GAME START" << endl;
	cout << "The word is " << strlen(word_1) << " letters long." << endl;

	wordlength = strlen(word_1);
	}	
	else {

		cout << "No capital letters!" << endl;
		beginning_input();

	}

}

void input() 
{
	cout << "You have " << tries << " tries left." << endl;
	cout << "Type in your guess:" << endl;
	cout << string(1, '\n');
	cin >> word_2;
	cout << "Your input: " << word_2 << endl;




}

void checkwon() 
{
	if (bulls == strlen(word_1)) {
		
		cout << "You Won!" << endl;
		playagain();
	}
	else if (tries <= 0)
	{
		cout << "You have no tries left, you lost." << endl;
		playagain();
		

	}

	
		
		
	bulls = 0;
	cows = 0;
}

void playagain() 
{
	cout << "Play again with the same word (Y), Play again with a different word (D), or close the game (N)." << endl;
	cin >> var_playagain;

	if (var_playagain == "Y" || var_playagain == "y") {

		tries = 6;

	}

	else if (var_playagain == "D" || var_playagain == "d") {

		
		beginning_input();
		tries = 6;
	}

	else if (var_playagain == "N" || var_playagain == "n") {

		ending = true;

	}

	else {

		cout << "Wrong input." << endl;
		playagain();

	}

}


