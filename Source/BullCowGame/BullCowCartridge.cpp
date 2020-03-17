// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
    GameOver();

    

    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver){
        HiddenWord.Len();
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("YOU HAVE WON!"));
            GameOver();
        }
        else if (Input.Len() == HiddenWord.Len())
        {

        }
        else
        {
            PrintLine(TEXT("Length of word doest not match hidden word of length %i.") , HiddenWord.Len());
        }

        if(Guesses <= 0) GameOver();
        else Guesses--;
    }
}
void UBullCowCartridge::InitGame()
{
    // Initialize Game Variables
    HiddenWord = TEXT("plain");
    Guesses = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull Cow Game."));
    PrintLine(TEXT("You have %i Guesses!"),Guesses);
    PrintLine(TEXT("The Length of the Hidden Word is %i"),HiddenWord.Len());

}

struct BullCowCount
{
    int32 bulls = 0;
    int32 cows = 0;

    BullCowCount(FString Input, FString HiddenWord)
    {
 
    }
};

void UBullCowCartridge::GameOver()
{
    bGameOver = true;
    PrintLine(TEXT("Game Over!\nPress Enter to Play again or ESC to quit game."));
}