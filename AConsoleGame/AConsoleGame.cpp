
// includes
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include <Windows.h>
#include "Lizardman.h"


// usings
using namespace std;

#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50







int main()
{
	//Window top left fullscreen
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, 1920, 1080, TRUE);

	Map m;
	
	m.MapSetup(m.map, MAPX, MAPY);



	int playerX = 5;
	int playerY = 5;
	int oldX = 0;
	int oldY = 0;
	m.map[playerY][playerX] = 'M';
	bool run = true;

	for (int y = 0; y < MAPY; y++)
	{
		for (int x = 0; x < MAPX; x++)
		{
			cout << m.map[y][x] << " ";
		}
		cout << endl;
	}
	

	while (run)
	{
		// save old position
		oldY = playerY;
		oldX = playerX;

		switch (_getch())
		{
		case ARROW_UP:
			playerY--;
			break;
		case ARROW_DOWN:
			playerY++;
			break;
		case ARROW_RIGHT:
			playerX++;
			break;
		case ARROW_LEFT:
			playerX--;
			break;
		}

		if (m.map[playerY][playerX] != 'O')
		{
			m.Move(oldX, oldY, playerX, playerY, 'M');
		}
		else // if trying to move into a wall
		{
			playerY = oldY;
			playerX = oldX;
		}
		
		
	}
}