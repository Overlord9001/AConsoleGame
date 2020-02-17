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
		SetConsoleTextAttribute(hOut, PLAYERCOLOR); // blue
		break;
	case 'E': // enemy
		SetConsoleTextAttribute(hOut, 4); // deep red
		break;
	case GOBLIN:
		SetConsoleTextAttribute(hOut, GOBLINCOLOR); // green
		break;
	case KOBOLD:
		SetConsoleTextAttribute(hOut, KOBOLDCOLOR); // red
		break;
	case LIZARDMAN:
		SetConsoleTextAttribute(hOut, LIZARDMANCOLOR); // turqoise
		break;
	case ORC:
		SetConsoleTextAttribute(hOut, ORCCOLOR); // yellow
		break;
	case BLACKDRAGON:
		SetConsoleTextAttribute(hOut, BLACKDRAGONCOLOR); // purple
		break;
	}

	// draw the new position 
	SetCursorPosition(newX * 2, newY);
	cout << icon;
	SetCursorPosition(0, 0);

	// set the color back to white
	SetConsoleTextAttribute(hOut, 15);

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
				SetConsoleTextAttribute(hOut, PLAYERCOLOR);
				break;
			case GOBLIN:
				SetConsoleTextAttribute(hOut, GOBLINCOLOR);
				break;
			case KOBOLD:
				SetConsoleTextAttribute(hOut, KOBOLDCOLOR);
				break;
			case LIZARDMAN:
				SetConsoleTextAttribute(hOut, LIZARDMANCOLOR);
				break;
			case ORC:
				SetConsoleTextAttribute(hOut, ORCCOLOR);
				break;
			case BLACKDRAGON:
				SetConsoleTextAttribute(hOut, BLACKDRAGONCOLOR);
				break;
			}
			cout << map[y][x] << " ";

			SetConsoleTextAttribute(hOut, 15); // set color back to white
		}
		cout << "   ";
		switch (y) // write tutorial
		{
		case 0:
			cout << "Move your charater: " << PLAYER << " with the arrowkeys";
			break;
		case 1:
			cout << "Move into an enemy to begin combat";
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
