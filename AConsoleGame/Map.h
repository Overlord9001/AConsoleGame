#pragma once
#include <Windows.h>

#define MAPX 50
#define MAPY 25
#define PLAYER 'P'
#define PLAYERCOLOR 9 // blue
#define GOBLIN 'G'
#define GOBLINCOLOR 10 // green
#define KOBOLD 'K'
#define KOBOLDCOLOR 12 // red
#define LIZARDMAN 'L'
#define LIZARDMANCOLOR 11 // turquoise
#define ORC 'O'
#define ORCCOLOR 14 // yellow
#define BLACKDRAGON 'B'
#define BLACKDRAGONCOLOR 5 // purple
#define TEXTWHITE SetConsoleTextAttribute(hOut, 15) // changes text color to white
#define TEXTPLAYER SetConsoleTextAttribute(hOut, PLAYERCOLOR) // changes text color to blue
#define TEXTGOBLIN SetConsoleTextAttribute(hOut, GOBLINCOLOR) // changes text color to green
#define TEXTKOBOLD SetConsoleTextAttribute(hOut, KOBOLDCOLOR) // changes text color to red
#define TEXTLIZARDMAN SetConsoleTextAttribute(hOut, LIZARDMANCOLOR) // changes text color to turqoise
#define TEXTORC SetConsoleTextAttribute(hOut, ORCCOLOR) // changes text color to yellow
#define TEXTBLACKDRAGON SetConsoleTextAttribute(hOut, BLACKDRAGONCOLOR) // changes text color to purple
#define TEXTRED SetConsoleTextAttribute(hOut, 4) // changes text color to dark red

static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

class Map
{
public:
	char map[MAPY][MAPX];
	static Map* Instance();
	void SetCursorPosition(int x, int y);
	void Move(int oldX, int oldY, int newX, int newY, char icon);
	void MapSetup(int mapX, int mapY);
	void DrawMap();
	int playerX = 5;
	int playerY = 5;
	
	~Map();

private:
	static Map* instance;
	Map();
};

