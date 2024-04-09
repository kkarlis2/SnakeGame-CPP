#pragma once
#include "util.h"
class COllidable
{
public:
	virtual Disk geteatenfruit() const = 0;
};

class Snake
{	
protected:
	const class Game& game;
public:
	Snake(const class Game& mysnake);
	virtual void update()=0;
	virtual void draw()=0;
	virtual void init()=0;
};