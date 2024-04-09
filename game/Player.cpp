#include "Player.h"
#include "graphics.h"
#include "game.h"
#include <vector>



Player::Player(const Game& mysnake)
	: Snake(mysnake)
{
}

void Player::update()
{
	if (i == 1&&!gameover) {
		pos_x -= speed;
		if (w == false && s == false) {
			for (int k = 1; k <= extra; k++) {
				position_x[k] -= speed;
				position_x[0] = pos_x;
			}

		}
		else if (w) {
			for (int k = 1; k <= extra; k++) {
				if (position_y[k-1] - position_y[k] < 0) {
					if (k >= 3 && position_x[k-1]-position_x[k]<0&&d2) {
						for (int y = 1; y <= extra; y++) {
							position_x[y] = position_x[y - 1] + 30;
						}
					}
					position_y[k] -= speed;
					position_y[0] = pos_y;
				}

				else {
					position_x[k] -= speed;
					position_x[0] = pos_x;
					if (k == extra) {
						w = false;
						w1 = false;
						w2 = false;
					}
				}
			}
		}
		else if (s) {
			for (int k = 1; k <= extra; k++) {
				if (position_y[k-1] - position_y[k] > 0) {
					if (k >= 3 && position_x[k - 1] - position_x[k] < 0&&d2) {
						for (int y = 1; y <= extra; y++) {
							position_x[y] = position_x[y - 1] + 30;
						}
					}
					position_y[k] += speed;
					position_y[0] = pos_y;
				}
				else {
					position_x[k] -= speed;
					position_x[0] = pos_x;
					if (k == extra) {
						s = false;
						s1 = false;
						s2 = false;
					}
				}
			}
		}
	}
	if (i == 2&&!gameover) {
		pos_x = pos_x+ speed;

		if (w == false && s == false) {
			for (int k = 1; k <= extra; k++) {
				position_x[k] += speed;
				position_x[0] = pos_x;
			}
		}
		else if (w) {
			for (int k = 1; k <= extra; k++) {
				if (position_y[k - 1] - position_y[k] < 0) {
					if (k >= extra/2 && position_x[k - 1] - position_x[k] > 0&&a2) {
						for (int y = 1; y <= extra; y++) {
							position_x[y] = position_x[y - 1] - 30;
						}
					}
					position_y[k] = position_y[k]- speed;;
					position_y[0] = pos_y;
				}
				else {
					position_x[k] = position_x[k] + speed;;
					position_x[0] = pos_x;
					if (k == extra) {
						w = false;
						w1 = false;
						w2 = false;
					}

				}
			}
		}
		else if (s) {
			for (int k = 1; k <= extra; k++) {
				if (position_y[k - 1] - position_y[k] > 0) {
					if (k >= extra / 2 && position_x[k - 1] - position_x[k] > 0&&a2) {
						for (int y = 1; y <= extra; y++) {
							position_x[y] = position_x[y - 1] - 30;
						}
					}
					position_y[k] += speed;;
					position_y[0] = pos_y;

				}
				else {
					position_x[k] = position_x[k]+ speed;
					position_x[0] = pos_x;
					if (k == extra) {
						s = false;
						s1 = false;
						s2 = false;
					}
				}
			}
		}
	}
	if (i == 3&& !gameover) {
		pos_y -= speed;
		if (a == false && d == false) {
			for (int k = 1; k <= extra; k++) {
				position_y[k] -= speed;
				position_y[0] = pos_y;
			}
		}
		else if (a) {
			for (int k = 1; k <= extra; k++) {
				if (position_x[k - 1] - position_x[k] < 0) {
					if (k >= extra / 2 && position_y[k - 1] - position_y[k] < 0&&s2) {
						for (int y = 1; y <= extra; y++) {
							position_y[y] = position_y[y - 1] + 30;
						}
					}
					position_x[k] -= speed;
					position_x[0] = pos_x;
				}
				else {
					position_y[k] -= speed;
					position_y[0] = pos_y;
					if (k == extra) {
						a = false;
						a1 = false;
						a2 = false;
					}
				}
			}
		}
		else if (d) {
			for (int k = 1; k <= extra; k++) {
				if (position_x[k-1] - position_x[k] > 0) {
					if (k >= extra / 2 && position_y[k - 1] - position_y[k] < 0&&s2) {
						for (int y = 1; y <= extra; y++) {
							position_y[y] = position_y[y - 1] + 30;
						}
					}
					position_x[k] += speed;
					position_x[0]=pos_x;
				}
				else {
					position_y[k] -= speed;
					position_y[0] = pos_y;
					if (k == extra) {
						d = false;
						d1 = false;
						d2 = false;
					}

				}
			}
		}
		
	}
	if (i == 4 && !gameover){
		pos_y += speed;
		
		if (a == false && d == false) {
			for (int k = 1; k <= extra; k++) {
				position_y[k] += speed;
				position_y[0] = pos_y;
			}
		}
		else if (a) {
			for (int k = 1; k <= extra; k++) {
				if (position_x[k-1] - position_x[k] < 0) {
					if (k >= extra / 2 && position_y[k - 1] - position_y[k] > 0&&w2) {
						for (int y = 1; y <= extra; y++) {
							position_y[y] = position_y[y - 1] - 30;
						}
					}
					position_x[k] -= speed;
					position_x[0] = pos_x;
				}
				else {
					position_y[k] =position_y[k]+ speed;;
					position_y[0] = pos_y;
					if (k == extra) {
						a = false;
						a1 = false;
						a2 = false;
					}
				}
			}
		}
		else if (d) {
			for (int k = 1; k <= extra; k++) {
				if (position_x[k-1] - position_x[k] >0) {
					if (k >= extra / 2 && position_y[k - 1] - position_y[k] > 0&&w2) {
						for (int y = 1; y <= extra; y++) {
							position_y[y] = position_y[y - 1] - 30;
						}
					}
					position_x[k] += speed;
					position_x[0] = pos_x;
				}
				else {
					position_y[k] += speed;
					position_y[0] = pos_y;
					if (k == extra) {
						d = false;
						d1 = false;
						d2 = false;
					}
				}
			}
		}
	}

	
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		if (i == 4) {
			s1 = true;
		}
		if (i == 3) {
			w1 = true;
		}

		if ((i == 3||i==4)&&a1) {
			a1 = false;
		}
		if (d1) {
			d2 = true;
		}
		if (i == 4 && w1 && w2) {
			w1 = false;
			w2 = false;
		}
		else if (i == 3 && s1 && s2) {
			s1 = false;
			s2 = false;
		}
		if (i != 2)
		{
			i = 1;
			a = true;
			
		}
		
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		if (i == 4) {
			s1 = true;
		}
		if (i == 3) {
			w1 = true;
		}
		if ((i == 3 || i == 4) && d1) {
			d1 = false;
		}
		if (a1) {
			a2 = true;
		}
		if (i == 4 && w1 && w2) {
			w1 = false;
			w2 = false;
		}
		else if (i == 3 && s1 && s2) {
			s1 = false;
			s2 = false;
		}
		if (i != 1)
		{
			i = 2;
			d = true;
		}
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		if (s1) {
			s2 = true;
		}
		if ((i == 1 || i == 2) && w1) {
			w1 = false;
		}
		if (i == 1) {
			a1 = true;
		}
		if (i == 2) {
			d1 = true;
		}
		if (i == 2&&a2&&a1) {
			a2 = false;
			a1 = false;
		}
		else if (i == 1 && d2 && d1) {
			d1 = false;
			d2 = false;
		}
		if (i != 4) {
			i = 3;
			w = true;
		}
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		if ((i == 1 || i == 2) && s1) {
			s1 = false;
		}
		if (w1) {
			w2 = true;
		}
		if (i == 1) {
			a1 = true;
		}
		if (i == 2) {
			d1 = true;
		}
		if (i == 2&&a2&&a1) {
			a2 = false;
			a1 = false;
		}
		else if (i == 1 && d2 && d1) {
			d1 = false;
			d2 = false;
		}
		if (i == 1 || i == 2) {
			i = 4;
			s = true;
		}
	}

	if (press1 == false && press2==false && press3==false && press4==false) {
		if (space && i == 1) {
			press1 = true;
		}
		else if (space && i == 2) {
			press2 = true;
		}
		else if (space && i == 3) {
			press3 = true;
		}
		else if (space && i == 4) {
			press4 = true;
		}
	}

	if (press1) {
		position_x1[0] -= speed + 2;
		sp++;
		if (sp == 100) {
			press1 = false;
			space = false;
			sp = 0;
		}

	}
	else if (press2) {
		position_x1[0] += speed + 2;
		sp++;
		if (sp == 100) {
			press2 = false;
			space = false;
			sp = 0;
		}
	}
	else if (press3) {
		position_y1[0] -= speed + 2;
		sp++;
		if (sp == 100) {
			press3 = false;
			space = false;
			sp = 0;
		}
	}
	else if (press4) {
		position_y1[0] += speed + 2;
		sp++;
		if (sp == 100) {
			press4 = false;
			space = false;
			sp = 0;
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		if (space) {
			sp = 99;
		}
		space = true;
		if (i == 1) {
			position_x1[0] = pos_x-25;
			position_y1[0] = pos_y;
		}
		else if (i == 2) {
			position_x1[0] = pos_x + 25;
			position_y1[0] = pos_y;
		}
		else if (i == 3) {
			position_x1[0] = pos_x;
			position_y1[0] = pos_y-25;
		}
		else if (i == 4) {
			position_x1[0] = pos_x;
			position_y1[0] = pos_y +25;
		}
	}
	if (pos_x < 20) {
		gameover = true;
	}
	if (pos_x > CANVAS_WIDTH-20) {
		gameover = true;
	}
	if (pos_y < 20) {
		gameover = true;
	}
	if (pos_y > CANVAS_HEIGHT-20) {
		gameover = true;
	}
	for (int k = 2; k <= extra; k++) {
		if (pos_x - position_x[k]==0&&pos_y-position_y[k]==0) {
			gameover = true;
		}
	}


}


void Player::draw()
{
	float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10);

	graphics::Brush br;


	//br.texture = std::string(ASSET_PATH) + "snake2.png";
	br.outline_opacity = 0.0f;

	if (i == 1) {
		graphics::setOrientation(0.f);
	}
	if (i == 2) {
		graphics::setOrientation(180.f);
	}
	if (i == 3) {
		graphics::setOrientation(-90.f);
	}if (i == 4) {
		graphics::setOrientation(90.f);
	}


	br.texture = "";

	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.1f;

	br.fill_secondary_color[0] = 1.f;
	br.fill_secondary_color[1] = 0.5f;
	br.fill_secondary_color[2] = 0.1f;
	br.fill_opacity = 1.0f;
	br.fill_secondary_opacity = 1.0f;
	br.gradient = true;
	br.texture = std::string(ASSET_PATH) + "snake3.png";
	graphics::drawRect(pos_x, pos_y,40,40, br);

	br.texture = std::string(ASSET_PATH) + "snake15.png";

	
	graphics::setOrientation(0.f);
	
	

	

	if (!w && !a && !s && !d) {
		position_x[0] = pos_x;
		position_y[0] = pos_y;
	}
	else {
		active = true;
	}
	for (int k = 1; k <= extra; k++) {
		graphics::drawDisk(position_x[k], position_y[k], 20, br);
	}

	if (space&&(press1||press2||press3||press4)) {
		br.texture = "";
		if (press1 || press2) {
			graphics::drawRect(position_x1[0], position_y1[0], 25, 3, br);
		}
		else if (press3 || press4) {
			graphics::drawRect(position_x1[0], position_y1[0], 3, 25, br);
		}
		
	}
	
	if (game.getDebugMode()) {
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.2f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Disk eat = geteatenfruit();
		graphics::drawDisk(eat.cx, eat.cy, eat.radius, br);
	}
}





void Player::init()
{
	position_x[0] = pos_x;
	position_y[0] = pos_y;

		if (i == 1 && w) {
			if (extra == 0) {
				position_x.push_back(position_x[extra] + 30);
				position_y.push_back(position_y[extra]);
			}
			else {
				position_x.push_back(position_x[extra]);
				position_y.push_back(position_y[extra] + 30);
			}
			
			extra++;
		}
		else if (i == 1 && s) {
			position_x.push_back(position_x[extra]);
			position_y.push_back(position_y[extra] -30);
			extra++;
		}
		else if (i == 1&&!w&&!s) {
			position_x.push_back(position_x[extra]+30);
			position_y.push_back(position_y[extra]);
			extra++;
		}
		else if (i == 2 && w) {
			if (extra == 0) {
				position_x.push_back(position_x[extra] - 30);
				position_y.push_back(position_y[extra]);
			}
			else {
				position_x.push_back(position_x[extra]);
				position_y.push_back(position_y[extra] + 30);
			}
			extra++;
			
		}
		else if (i == 2 && s) {
			position_x.push_back(position_x[extra]);
			position_y.push_back(position_y[extra] -30);
			extra++;
		}
		else if (i == 2&&!w&&!s) {
			position_x.push_back(position_x[extra]-30);
			position_y.push_back(position_y[extra]);
			extra++;
		}
		else if (i == 3 && a) {
			if (extra == 0) {
				position_x.push_back(position_x[extra]);
				position_y.push_back(position_y[extra] + 30);
			}
			else {
				position_x.push_back(position_x[extra] + 30);
				position_y.push_back(position_y[extra]);
			}
			extra++;
		}
		else if (i == 3 && d) {
			position_x.push_back(position_x[extra] - 30);
			position_y.push_back(position_y[extra]);
			extra++;
		}
		else if (i == 3&&!a&&!d) {
			position_x.push_back(position_x[extra]);
			position_y.push_back(position_y[extra]+30);
			extra++;
		}
		else if (i == 4 && a) {
			if (extra == 0) {
				position_x.push_back(position_x[extra]);
				position_y.push_back(position_y[extra] - 30);
			}
			else {
				position_x.push_back(position_x[extra] + 30);
				position_y.push_back(position_y[extra]);
			}
			extra++;
		}
		else if (i == 4 && d) {
			position_x.push_back(position_x[extra] - 30);
			position_y.push_back(position_y[extra]);
			extra++;
		}
		else if (i == 4&&!a&&!d) {
			position_x.push_back(position_x[extra]);
			position_y.push_back(position_y[extra]-30);
			extra++;
		}
		
}

void Player::restart()
{
	gameover = false;
	pos_x = CANVAS_WIDTH / 2;
	pos_y = CANVAS_HEIGHT / 2;
	position_x = { 0 };
	position_y = { 0 };
	i = 0;
	extra = 0;
}

Disk Player::geteatenfruit() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 20.0f;
	return disk;
}

Disk Player::Hedgehogcrash() const
{
	Disk disk;
	disk.cx = position_x1[0];
	disk.cy = position_y1[0];
	disk.radius = 10.0f;
	return disk;
}
