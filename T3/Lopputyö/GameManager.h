/**
*  _____                                                                                                                   _____
* ( ___ )                                                                                                                 ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ################################################################################################################# |   |
*  |   | ###██████╗##█████╗#███╗###███╗███████╗███╗###███╗#█████╗#███╗###██╗#█████╗##██████╗#███████╗██████╗####██╗##██╗## |   |
*  |   | ##██╔════╝#██╔══██╗████╗#████║██╔════╝████╗#████║██╔══██╗████╗##██║██╔══██╗██╔════╝#██╔════╝██╔══██╗###██║##██║## |   |
*  |   | ##██║##███╗███████║██╔████╔██║█████╗##██╔████╔██║███████║██╔██╗#██║███████║██║##███╗█████╗##██████╔╝###███████║## |   |
*  |   | ##██║###██║██╔══██║██║╚██╔╝██║██╔══╝##██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║###██║██╔══╝##██╔══██╗###██╔══██║## |   |
*  |   | ##╚██████╔╝██║##██║██║#╚═╝#██║███████╗██║#╚═╝#██║██║##██║██║#╚████║██║##██║╚██████╔╝███████╗██║##██║██╗██║##██║## |   |
*  |   | ###╚═════╝#╚═╝##╚═╝╚═╝#####╚═╝╚══════╝╚═╝#####╚═╝╚═╝##╚═╝╚═╝##╚═══╝╚═╝##╚═╝#╚═════╝#╚══════╝╚═╝##╚═╝╚═╝╚═╝##╚═╝## |   |
*  |   | ################################################################################################################# |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                                                                                                 (_____)
* 
* 
* I am lazy guy so we go this way and also in my head that's pretty good dont ya think?
* 
*/
#pragma once
#pragma pack(1)
#ifndef __GAME_H__

//NOTE: Defines
#define __GAME_H__

//	GameManager Flags

//		ROUND TURN INFO

#define ROUND_TURN_PLAYER 0x0 
#define ROUND_TURN_DEALER 0x1 

//		GAME SETTINGS

#define GAME_SETTINGS_DIFFICULTY_EASY 0x0
#define GAME_SETTINGS_DIFFICULTY_HARD 0x1
#define GAME_SETTINGS_DIFFICULTY_DEATH_NOTE 0x2
#define GAME_SETTINGS_DIFFICULTY_MEDIUM 0x3

//		GAMEMODE

#define GAMEMODE_CHEATS 0x0
#define GAMEMODE_SURVIVAL 0x1
#define GAMEMODE_ARCADE 0x2
#define GAMEMODE_NOMERCY 0x3

//NOTE: Typedefs 
//GameManager
typedef struct GameManager {
public:
	int PackedDices : 24;
	int CurrentBid : 6;

	int  Difficulty : 2;
	unsigned char LastBid : 6;
private:
	unsigned char InRoundFlags : 2;
	unsigned char CurrentRound : 5;
	unsigned char GameSettings : 2;

	
	/// <summary>
	/// Called when Starting new Round and (Re)Initialzes data for playing another round
	/// </summary>
	/// <param name="flags"></param>
	void NewRound();
	
	/// <summary>
	/// Initializes the the GameManager for new Game NOTE: this does not initialize new round instead 
	/// it resets everything 
	/// </summary>
	/// <param name="gameSettings"></param>
	void NewGame(unsigned char difficulty,unsigned char gameSettings);
} Struct;
#endif // !__GAME_H__
