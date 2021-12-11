//CSCN71000 - Assignment #4 - The program is a number guessing game 
//Gurjit Singh - December 8 - 2021 

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


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

	int ch; 

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
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
	

	printf("\nEnter a number between %d and %d (inclusive): ", MINNUMBER, MAXNUMBER);
	scanf_s("%d", &mysteryNumber); 

	printf("\nNumber of incorrect guesses: %d", guessCount);

	do {
		printf("\nEnter a guess: "); 
		scanf_s("%d", &guess);
		
		guessTrailCount = 0;

		while ('\n' != getchar()) 
		{ 
			++guessTrailCount; 
		};

		if (0 == guessTrailCount) 
		{  
			if (guess >= MINNUMBER && guess <= MAXNUMBER)
			{ 
				if (guess < mysteryNumber)
				{
					++guessCount; 
					printf("\nYour guess was too low\n\n"); 
					printf("Number of incorrect guesses: %d", guessCount); 
				}
				else if (guess > mysteryNumber)
				{
					++guessCount; 
					printf("\nYour guess was too high\n\n"); 
					printf("Number of incorrect guesses: %d", guessCount);
				}
				else if (guess == mysteryNumber)
				{
					printf("\nYou have correctly guessed the mystery number!\n"); 
					fprintf(fp2, "%d: Guessed correctly\n", mysteryNumber); 
					exit(1); 
				}
			}
			else 
			{ 
				printf("\nInvalid guess entered, please enter a guess in the correct range (between 1 and 1000 inclusive)\n\n"); 
				++guessCount; 
				printf("Number of incorrect guesses: %d", guessCount);
			}
		}
		else
		{ 
			printf("\nInvalid guess entered, please enter a number guess\n\n"); 
			++guessCount; 
			printf("Number of incorrect guesses: %d", guessCount);
		}
	} while (guessCount != MAXGUESSES);

	if (guessCount == MAXGUESSES)
	{
		printf("\nYou have now entered 6 guesses. BYE!\n"); 
		fprintf(fp2, "%d: X\n", mysteryNumber); 
	}


	fclose(fp); 
	fclose(fp2); 


	return 0; 
} 