#pragma once
#include "Snake.h"
#include "graphics.h"

class Fruits : public Snake,public COllidable
{
	float pos_x,pos_y;
	float size;
	graphics::Brush brush;
	bool active = true;
public:
	void update() override;
	void draw() override;
	void init()override;
	bool isActive() { return active; }
	Fruits(const class Game& mysnake);
	~Fruits();
	Disk geteatenfruit() const override;
};