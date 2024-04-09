#include "Hedgehog.h"
#include "graphics.h"
#include "config.h"
#include <random>
#include "util.h"
#include "game.h"
#include "player.h"

void Hedgehog::update() {
	{
		if (pos_x < -size) {
			active = false;
		}
	}
}

void Hedgehog::draw()
{
	brush.texture = std::string(ASSET_PATH) + "Hedgehog.png";
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	brush.fill_opacity = 1.0f;

	graphics::Brush br;
	br.outline_opacity = 1.0f;
	br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.2f;
	br.fill_opacity = 0.3f;
	br.gradient = false;
	Disk eat = geteatenfruit();
	if (game.getDebugMode()) {
		graphics::drawDisk(eat.cx, eat.cy, eat.radius, br);
	}
}

void Hedgehog::init()
{
	pos_x = (rand() % (950)) + 10;
	pos_y = (rand() % (400)) + 20;
	size = 35;
	brush.outline_opacity = 0.0f;
}

Hedgehog::Hedgehog(const Game& mysnake)
	:Snake(mysnake)
{
	init();
}

Hedgehog::~Hedgehog()
{

}

Disk Hedgehog::geteatenfruit() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size * 0.45f;
	return disk;
}