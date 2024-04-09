#pragma once

#include "Player.h"
#include "Fruits.h"
#include "Hedgehog.h"

class Game 
{
	int x = 0;
	bool sound = false;
	bool s = false;
	bool h = false;
	typedef enum {STATUS_START ,STATUS_PLAYING,STATUS_OPTIONS} status_t;
	Player* player = nullptr;
	bool player_initialized = false;
	bool debug_mode = false;
	Fruits* fruit = nullptr;
	Hedgehog* hedgehog = nullptr;
	void createfruit();
	void createHedgehog();
	void checkFruit();
	void checkHedgehog();
	bool checkeatfruit();
	bool checktouchhedgehog();
	bool checkcrashHedgehog();
	bool checkcrashFruit();
	status_t status = STATUS_START;
	
	void updateOptionsScreen();
	void updateStartScreen();
	void updateLevelScreen();
	void drawOptionsScreen();
	void drawStartScreen();
	void drawLevelScreen();
public:
	int score = 0;
	void decrScore() { score = score - 2; }
	void growScore() { score = score + 1; }
	void setScore() { score = 0; }
	int getScore() { return score; }
	void setDebugMode(bool d) { debug_mode = d; }
	bool getDebugMode() const { return debug_mode; }
	void update();
	void draw();
	void init();
	Game();
	~Game();
};
