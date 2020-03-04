// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    UE_LOG(LogTemp, Warning, TEXT("Your message"));
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cow Game."));
    PrintLine(TEXT("You have 5 Guesses!"));

    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    HiddenWord.Len();
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("YOU HAVE WON!"));
    }
    else if (Input.Len() == HiddenWord.Len())
    {

    }
    else
    {

    }
}
void UBullCowCartridge::InitGame()
{
    // Initialize Game Variables
    HiddenWord = TEXT("plain");
    Guesses = 5;

}

struct BullCowCount
{
    int32 bulls = 0;
    int32 cows = 0;

    BullCowCount()
    {

    }
};