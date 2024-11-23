//https://www.rapidtables.com/convert/number/binary-to-decimal.html?x=00
//https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
#include "GameManager.h"
#include <iostream>
#include<cstdlib>

void GameManager::NewRound()
{
	PackedDices = 0;
	CurrentBid = 0;
	InRoundFlags = 0;
	LastBid = 0;
	InRoundFlags = 0;
	CurrentRound++;

	for (int i = 0; i < 7; ++i) {
		//Bit packing till go crazy
		PackedDices |= ((1 + rand() % 6) & 0x3) << i* 0x3;
	}

}

void GameManager::NewGame(unsigned char Difficulty,unsigned char gameSettings)
{

	PackedDices		= 0;
	CurrentBid		= 0;
	Difficulty		= Difficulty;
	LastBid			= 0;
	InRoundFlags	= 0;		
	CurrentRound	= 0;		
	GameSettings	=  gameSettings & 0x3;
}
