//CSCN71000 - Assignment #4 - The program is a number guessing game 
//Gurjit Singh - December 8 - 2021 

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h> 
#include "Source.h" 
 

#define MINNUMBER 1 
#define MAXNUMBER 1000 
#define MAXGUESSES 6  


int main(void) 
{
	FILE* fp = fopen("previousGames.txt", "r");

	if (fp == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}

	FILE* fp2 = fopen("previousGames.txt", "a");

	if (fp == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}


	int mysteryNumber;
	int guess = 0;
	int guessCount = 0; 
	int guessTrailCount;
	

	printf("Enter a number between %d and %d (inclusive): ", MINNUMBER, MAXNUMBER);
	scanf_s("%d", &mysteryNumber); 

	printf("\n"); 
	displayIncorrectGuesses(guessCount); 


	do {
		// Read previous successfull and unsuccessfull guesses from file 
		displayPreviouslyGuessedNumbers(fp); 
		

		printf("Enter a guess: "); 
		scanf_s("%d", &guess);
		
		guessTrailCount = 0;

		while ('\n' != getchar()) 
		{ 
			++guessTrailCount; 
		};

		if (guessTrailCount == 0)
		{  
			if (guess >= MINNUMBER && guess <= MAXNUMBER)
			{ 
				if (guess < mysteryNumber)
				{
					++guessCount; 
					printf("\nYour guess was too low\n\n"); 
					displayIncorrectGuesses(guessCount); 
				}
				else if (guess > mysteryNumber)
				{
					++guessCount; 
					printf("\nYour guess was too high\n\n"); 
					displayIncorrectGuesses(guessCount); 
				}
				else if (guess == mysteryNumber)
				{
					correctNumberMessage(fp2, mysteryNumber); 
					exit(1); 
				}
			}
			else 
			{ 
				printf("\nInvalid guess entered, please enter a guess in the correct range (between 1 and 1000 inclusive)\n\n"); 
				++guessCount; 
				displayIncorrectGuesses(guessCount); 
			}
		}
		else
		{ 
			printf("\nInvalid guess entered, please enter a number guess\n\n"); 
			++guessCount; 
			displayIncorrectGuesses(guessCount); 
		}
	} while (guessCount != MAXGUESSES);

	if (guessCount == MAXGUESSES)
	{
		gameOverMessage(fp2, mysteryNumber); 
	}


	fclose(fp); 
	fclose(fp2); 


	return 0; 
} 


void displayIncorrectGuesses(int guessCount)
{
	printf("Number of incorrect guesses: %d", guessCount); 
} 


void displayPreviouslyGuessedNumbers(FILE* fp) 
{
	int ch;

	printf("\n"); 

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
	} 
} 


void correctNumberMessage(FILE* fp2, int mysteryNumber)
{
	printf("\nYou have correctly guessed the mystery number!\n");
	fprintf(fp2, "%d: Guessed correctly\n", mysteryNumber);
} 


void gameOverMessage(FILE* fp2, int mysteryNumber)
{
	printf("\nYou have now entered 6 guesses. BYE!\n");
	fprintf(fp2, "%d: X\n", mysteryNumber); 
} 