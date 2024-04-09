#pragma once
#include "Snake.h"
#include "config.h"
#include <vector>
class Player : public Snake,public COllidable
{
public:
	float speed = 2.0f;
	float pos_x=CANVAS_WIDTH/2, pos_y=CANVAS_HEIGHT/2;
	float pos_x1, pos_y1,pos_x2,pos_y2;
	bool gameover = false;
	bool space = false;
	int sp = 0;
	int i = 0;
	bool a = false;
	bool w = false;
	bool s = false;
	bool d = false;
	bool a1, d1, w1, s1;
	bool a2, d2, w2, s2, press1 = false, press2 = false, press3 = false, press4 = false;
	bool active = false;
	int j = 0;
	int extra = 0;
	std::vector < int > position_x = { 0 };
	std::vector < int > position_y = { 0 };
	std::vector < int > position_x1 = { 0 };
	std::vector < int > position_y1 = { 0 };
public:
	Player(const class Game& mysnake);
	void update() override;
	void draw() override;
	void draw1();
	void init() override;
	void restart();
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	Disk geteatenfruit() const override;
	Disk Hedgehogcrash() const;
};