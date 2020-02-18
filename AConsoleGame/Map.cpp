#include "Map.h"
#include <Windows.h>
#include <iostream>
using namespace std;


static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
Map* Map::instance = 0; // set the instance pointer to null 

Map * Map::Instance()
{
	if (instance == nullptr)
		instance = new Map;
	return instance;

}

// Taken from the net https://stackoverflow.com/questions/34842526/update-console-without-flickering-c
// Used to update screen without flicker
void Map::SetCursorPosition(int x, int y)
{
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

// update the visuals when a character moves
void Map::Move(int oldX, int oldY, int newX, int newY, char icon)
{
	// set the old pos to empty
	SetCursorPosition(oldX * 2, oldY); // *2 because of the spacing between when drawing
	cout << " ";

	// choose a correct color
	switch (icon)
	{
	case PLAYER: // player
		TEXTPLAYER; // blue
		break;
	case 'E': // enemy
		SetConsoleTextAttribute(hOut, 4); // deep red
		break;
	case GOBLIN:
		TEXTGOBLIN; // green
		break;
	case KOBOLD:
		TEXTKOBOLD; // red
		break;
	case LIZARDMAN:
		TEXTLIZARDMAN; // turqoise
		break;
	case ORC:
		TEXTORC; // yellow
		break;
	case BLACKDRAGON:
		TEXTBLACKDRAGON; // purple
		break;
	}

	// draw the new position 
	SetCursorPosition(newX * 2, newY);
	cout << icon;
	SetCursorPosition(0, 0);

	// set the color back to white
	TEXTWHITE;

	// update the array
	map[oldY][oldX] = ' ';
	map[newY][newX] = icon;
}

// Create map
void Map::MapSetup(int mapX, int mapY)
{
	for (int x = 0; x < mapX; x++)
	{
		for (int y = 0; y < mapY; y++)
		{
			if (x == 0 || x == mapX - 1 || y == 0 || y == mapY - 1)
			{
				map[y][x] = '#';
			}
			else
			{
				map[y][x] = ' ';
			}
		} 
	}
}

// draw the map
void Map::DrawMap()
{
	for (int y = 0; y < MAPY; y++)
	{
		for (int x = 0; x < MAPX; x++)
		{
			switch (map[y][x]) // draw with the correct color
			{
			case PLAYER:
				TEXTPLAYER;
				break;
			case GOBLIN:
				TEXTGOBLIN;
				break;
			case KOBOLD:
				TEXTKOBOLD;
				break;
			case LIZARDMAN:
				TEXTLIZARDMAN;
				break;
			case ORC:
				TEXTORC;
				break;
			case BLACKDRAGON:
				TEXTBLACKDRAGON;
				break;
			}
			cout << map[y][x] << " ";

			TEXTWHITE; // set color back to white
		}
		cout << "   ";
		switch (y) // write tutorial
		{
		case 0:
			cout << "Move your character: ";
			TEXTPLAYER;
			cout << PLAYER;
			TEXTWHITE;
			cout << " with the arrowkeys";
			break;
		case 1:
			cout << "Move into an enemy to begin combat";
			break;
		case 2:
			cout << "Press M to mute/unmute the music.";
			break;
		case 3:
			cout << "Press P to to stop/restart the music.";
			break;
		case 4:
			TEXTGOBLIN;
			cout << GOBLIN;
			TEXTWHITE;
			cout << " is a goblin";
			break;
		case 5:
			TEXTORC;
			cout << ORC;
			TEXTWHITE;
			cout << " is an orc";
			break;
		case 6:
			TEXTLIZARDMAN;
			cout << LIZARDMAN;
			TEXTWHITE;
			cout << " is a lizardman";
			break;
		case 7:
			TEXTKOBOLD;
			cout << KOBOLD;
			TEXTWHITE;
			cout << " is a kobold";
			break;
		case 8:
			TEXTBLACKDRAGON;
			cout << BLACKDRAGON;
			TEXTWHITE;
			cout << " is a blackdragon";
			break;
		}

		cout << endl;
	}
}

Map::~Map()
{
}

Map::Map()
{
}
