#pragma once

#define MAPX 50
#define MAPY 25

class Map
{
public:
	char map[MAPY][MAPX];
	void SetCursorPosition(int x, int y);
	void Move(int oldX, int oldY, int newX, int newY, char icon);
	void MapSetup(char map[MAPY][MAPX], int mapX, int mapY);
	Map();
};

