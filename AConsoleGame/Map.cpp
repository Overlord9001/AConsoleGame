#include "Map.h"
#include <Windows.h>
#include <iostream>
using namespace std;

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
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void Map::Move(int oldX, int oldY, int newX, int newY, char icon)
{
	// update the visuals
	SetCursorPosition(oldX * 2, oldY);
	cout << ".";
	SetCursorPosition(newX * 2, newY);
	cout << icon;
	SetCursorPosition(0, 0);

	// update the array
	map[oldY][oldX] = '.';
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
				map[y][x] = 'O';
			}
			else
			{
				map[y][x] = '.';
			}
		}
	}

	//for (int x = 0; x < mapX; x++)
	//{
	//	map[0][x] = 'O'; // top edge
	//	map[mapY - 1][x] = 'O'; // bottom edge
	//}
	//for (int y = 0; y < mapY; y++)
	//{
	//	map[y][0] = 'O'; // left edge
	//	map[y][mapX - 1] = 'O'; // right edge
	//}
}

Map::Map()
{
}
