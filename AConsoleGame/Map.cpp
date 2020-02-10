#include "Map.h"
#include <Windows.h>
#include <iostream>
using namespace std;

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
	SetCursorPosition(oldX * 2, oldY);
	cout << ".";
	SetCursorPosition(newX * 2, newY);
	cout << icon;
	SetCursorPosition(0, 0);

	map[oldY][oldX] = '.';
	map[newY][oldX] = icon;
}

// Create map
void Map::MapSetup(char map[MAPY][MAPX], int mapX, int mapY)
{
	for (int x = 0; x < mapX; x++)
	{
		for (int y = 0; y < mapY; y++)
		{
			map[y][x] = '.';
		}
	}

	for (int x = 0; x < mapX; x++)
	{
		map[0][x] = 'O'; // top edge
		map[mapY - 1][x] = 'O'; // bottom edge
	}
	for (int y = 0; y < mapY; y++)
	{
		map[y][0] = 'O'; // left edge
		map[y][mapX - 1] = 'O'; // right edge
	}
}

Map::Map()
{
}
