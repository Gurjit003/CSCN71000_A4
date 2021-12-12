//CSCN71000 - Assignment #4 - The program is a number guessing game 
//Gurjit Singh - December 8 - 2021 

#pragma once

void displayIncorrectGuesses(int guessCount);
void displayPreviouslyGuessedNumbers(FILE* fp);
void correctNumberMessage(FILE* fp2, int mysteryNumber);
void gameOverMessage(FILE* fp2, int mysteryNumber); 