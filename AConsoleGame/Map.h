#pragma once

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
#define TEXTWHITE SetConsoleTextAttribute(hOut, 15)
#define TEXTPLAYER SetConsoleTextAttribute(hOut, PLAYERCOLOR)
#define TEXTGOBLIN SetConsoleTextAttribute(hOut, GOBLINCOLOR)
#define TEXTKOBOLD SetConsoleTextAttribute(hOut, KOBOLDCOLOR)
#define TEXTLIZARDMAN SetConsoleTextAttribute(hOut, LIZARDMANCOLOR)
#define TEXTORC SetConsoleTextAttribute(hOut, ORCCOLOR)
#define TEXTBLACKDRAGON SetConsoleTextAttribute(hOut, BLACKDRAGONCOLOR)


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

