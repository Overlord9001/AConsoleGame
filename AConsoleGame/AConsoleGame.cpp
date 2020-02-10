
// includes
#include <iostream>
#include <conio.h>
#include <Windows.h>

// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50

void MapSetup(char map[], int mapX, int mapY)
{
	
}

//Taken from the net https://stackoverflow.com/questions/34842526/update-console-without-flickering-c
void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}


int main()
{
	int const mapX = 50;
	int const mapY = 25;
	char map[mapY][mapX];
	
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

	int playerX = 5;
	int playerY = 5;
	int oldX = 0;
	int oldY = 0;
	map[playerY][playerX] = 'M';
	bool run = true;

	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			cout << map[y][x] << "";
		}
		cout << endl;
	}
	

	while (run)
	{
		oldY = playerY;
		oldX = playerX;

		switch (_getch())
		{
		case ARROW_UP:
			setCursorPosition(playerX, playerY);
			cout << ".";
			playerY--;
			break;
		case ARROW_DOWN:
			setCursorPosition(playerX, playerY);
			cout << ".";
			playerY++;
			break;
		case ARROW_RIGHT:
			setCursorPosition(playerX, playerY);
			cout << ".";
			playerX++;
			break;
		case ARROW_LEFT:
			setCursorPosition(playerX, playerY);
			cout << ".";
			playerX--;
			break;
		}
		setCursorPosition(playerX, playerY);
		cout << "M";
		setCursorPosition(0, 0);

		map[oldY][oldX] = '.';
		map[playerY][playerX] = 'M';
		
	}
}