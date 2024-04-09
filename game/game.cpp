#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Player.h"






void Game::createfruit()
{
	if (!fruit) {
		s = true;
		fruit = new Fruits(*this);
	}
}

void Game::createHedgehog()
{
	if (!hedgehog && getScore() >= 2) {
		h = true;
		hedgehog = new Hedgehog(*this);
	}
}

void Game::checkHedgehog() {
	if (hedgehog && !hedgehog->isActive()) {
		delete hedgehog;
		hedgehog = nullptr;
	}
}
void Game::checkFruit()
{
	if (fruit && !fruit->isActive())
	{
		delete fruit;
		fruit = nullptr;
	}
}

bool Game::checkeatfruit()
{
	if (!player || !fruit)
	{
		return false;
	}

	Disk d1 = player-> geteatenfruit();
	Disk d2 = fruit-> geteatenfruit();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;


	if (sqrt(dx * dx + dy * dy) <d1.radius+d2.radius)
	{
		return true;
	}
	else {
		return false;
	}
}



bool Game::checktouchhedgehog()
{
	if (!player || !hedgehog)
	{
		return false;
	}

	Disk d1 = player->geteatenfruit();
	Disk d2 = hedgehog->geteatenfruit();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;


	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Game::checkcrashHedgehog()
{
	if (!player || !hedgehog)
	{
		return false;
	}

	Disk d1 = hedgehog->geteatenfruit();
	Disk d2 = player->Hedgehogcrash();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;


	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		return true;
	}
	else {
		return false;
	}
}
bool Game::checkcrashFruit()
{
	if (!player || !fruit)
	{
		return false;
	}
	Disk d1 = fruit->geteatenfruit();
	Disk d2 = player->Hedgehogcrash();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;


	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		return true;
	}
	else {
		return false;
	}
}

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		status = STATUS_PLAYING;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_O)) {
		status = STATUS_OPTIONS;
	}
}

void Game::updateOptionsScreen() {
	if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {
		status = STATUS_START;
	}
}
void Game::updateLevelScreen()
{
	if (!player_initialized)
	{
		player = new Player(*this);
		player_initialized = true;
	}
	if (player)
	{
		player->update();

	}
	checkFruit();
	createfruit();

	if (fruit) {
		fruit->update();
	}
	checkHedgehog();
	createHedgehog();

	if (hedgehog) {
		hedgehog->update();
	}

	if (checktouchhedgehog()) {
		player->gameover = true;
	}
	if (checkeatfruit())
	{
		delete fruit;
		fruit = nullptr;
		graphics::playSound(std::string(ASSET_PATH) + "AppleCrunch!.mp3", 0.5f, false);
		growScore();
		x++;
	}
	if (checkcrashHedgehog()) {
		
		graphics::playSound(std::string(ASSET_PATH) + "Hedgehog.mp3", 0.5f, false);
		delete hedgehog;
		hedgehog = nullptr;
	}
	
	if (checkcrashFruit()) {
		delete fruit;
		fruit = nullptr;
		graphics::playSound(std::string(ASSET_PATH) + "wrong_hit.mp3", 0.5f, false);
		decrScore();
		fruit = new Fruits(*this);
	}
}

void Game::drawStartScreen()
{
	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(CANVAS_WIDTH/2-180, CANVAS_HEIGHT/2+150, 30, info, br);
	char info1[40];
	sprintf_s(info1, "For options press o");
	graphics::drawText(CANVAS_WIDTH/2-480 , CANVAS_HEIGHT/4-90 , 30, info1, br);
	br.texture = std::string(ASSET_PATH) + "opening.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void Game::drawOptionsScreen() {
	graphics::Brush br;
	char infoo[40];
	sprintf_s(infoo, "TO RETURN PRESS BACKSPACE");
	graphics::drawText(CANVAS_WIDTH / 8+450 , CANVAS_HEIGHT / 8-37, 30, infoo, br);
	char infob[200];
	sprintf_s(infob, "A FEW WORDS...");
	graphics::drawText(CANVAS_WIDTH / 4 - 195, CANVAS_HEIGHT / 4 + 138, 30, infob, br);
	char info[360];
	sprintf_s(info, "My classmate and I made the snake game.  ");
	graphics::drawText(CANVAS_WIDTH / 4 - 245, CANVAS_HEIGHT / 4 + 150, 15, info, br);
	char info1[200];
	sprintf_s(info1, "It is a little different from the classic game of the same name.");
	graphics::drawText(CANVAS_WIDTH / 4 - 245, CANVAS_HEIGHT / 4 + 162, 15, info1, br);
	char info2[200];
	sprintf_s(info2, "Specifically, our snake can throw poison from its mouth so that it can kill its natural enemy, the hedgehog.");
	graphics::drawText(CANVAS_WIDTH / 4 - 245, CANVAS_HEIGHT / 4 + 174, 15, info2, br);
	char info3[200];
	sprintf_s(info3, "If the snake touch the hedgehog then it dies.");
	graphics::drawText(CANVAS_WIDTH / 4 - 245, CANVAS_HEIGHT / 4 + 186, 15, info3, br);
	char info4[200];
	sprintf_s(info4, "Also, if instead of the hedgehog, the poison hits an apple then it loses 2 points from its total score.");
	graphics::drawText(CANVAS_WIDTH / 4 - 245, CANVAS_HEIGHT / 4 + 198, 15, info4, br);
	br.texture = std::string(ASSET_PATH) + "game_options.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	br.texture = std::string(ASSET_PATH) + "snake_options.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 4+550, CANVAS_HEIGHT / 4+280, CANVAS_WIDTH / 4, CANVAS_HEIGHT / 4, br);
	br.texture = std::string(ASSET_PATH) + "snakes.png";
	graphics::drawRect(CANVAS_WIDTH / 4 , CANVAS_HEIGHT / 4 +280, CANVAS_WIDTH / 4, CANVAS_HEIGHT / 4, br);
	br.texture = std::string(ASSET_PATH) + "buttons.png";
	graphics::drawRect(CANVAS_WIDTH / 4+550, CANVAS_HEIGHT / 4 , CANVAS_WIDTH / 8, CANVAS_HEIGHT / 8, br);
	char info5[50];
	sprintf_s(info5, "You are playing with : ");
	graphics::drawText(CANVAS_WIDTH / 4 +180, CANVAS_HEIGHT / 4+20, 35, info5, br);
	br.texture = std::string(ASSET_PATH) + "Space_button.png";
	graphics::drawRect(CANVAS_WIDTH / 4 + 599, CANVAS_HEIGHT / 4+70, CANVAS_WIDTH / 8+60, CANVAS_HEIGHT / 8-20, br);
	char info6[50];
	sprintf_s(info6, "You are throwing poison with : ");
	graphics::drawText(CANVAS_WIDTH / 4 + 140, CANVAS_HEIGHT / 4 + 75, 35, info6, br);
	char info7[10];
	sprintf_s(info7, "CREATORS");
	graphics::drawText(CANVAS_WIDTH / 2-50, CANVAS_HEIGHT / 4 + 260, 20,info7, br);
	char infon1[30];
	sprintf_s(infon1, "KARLIS KONSTANTINOS-3190077");
	graphics::drawText(CANVAS_WIDTH / 2-100, CANVAS_HEIGHT / 4 + 280, 20, infon1, br);
	char infon2[30];
	sprintf_s(infon2, "KARAGIANNIS GEWRGIOS-3190074");
	graphics::drawText(CANVAS_WIDTH / 2-100, CANVAS_HEIGHT / 4 + 300, 20, infon2, br);
	br.texture = std::string(ASSET_PATH) + "hedgehog_options.png";
	graphics::drawRect(CANVAS_WIDTH / 4-50 , CANVAS_HEIGHT / 4+15 , CANVAS_WIDTH / 8 , CANVAS_HEIGHT / 8, br);
}
void Game::drawLevelScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "place1.png";
	br.outline_opacity = 0.0f;

	//draw background 
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	//draw player
	if (player)
	{
		player->draw();
		if (player->gameover) {
			if (!sound) {
				graphics::playSound(std::string(ASSET_PATH) + "gameover.mp3", 1.0f, false);
				sound = true;
			}
			graphics::Brush br1;
			br1.texture = std::string(ASSET_PATH) + "gameover2.png";
			br1.outline_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH / 4, CANVAS_WIDTH / 4, br1);
			char info[40];
			sprintf_s(info, "Press ENTER to restart");
			graphics::drawText(CANVAS_WIDTH / 2 - 120, CANVAS_HEIGHT / 2 - 130, 30, info, br);
			char info1[40];
			sprintf_s(info1, "Press Esc to escape the game");
			graphics::drawText(CANVAS_WIDTH / 2 - 130, CANVAS_HEIGHT / 2 + 150, 30, info1, br);
			if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
				setScore();
				sound = false;
				delete hedgehog;
				hedgehog = nullptr;
				player->restart();
			}
			else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) {
				exit(0);
			}
		}
	}
	
	if (fruit)
	{
		fruit->draw();
	}

	if (hedgehog) {
		hedgehog->draw();
	}

	//UI/Info player
	if (player)
	{
		char info[40];
		sprintf_s(info, "Score : %i", getScore());
		graphics::drawText(30, 30, 40, info, br);
		if (s) {
			player->init();
			s = false;
		}
	}
}


void Game::update()
{	
	if (status == STATUS_START) {
		updateStartScreen();
	}
	else if(status==STATUS_PLAYING) {
		updateLevelScreen();
	}
	else if(status==STATUS_OPTIONS) {
		updateOptionsScreen();
	}
}

void Game::draw()
{
	if (status == STATUS_START) {
		drawStartScreen();
	}
	else if(status==STATUS_PLAYING)
	{
		drawLevelScreen();
	}
	else if(status==STATUS_OPTIONS) {
		drawOptionsScreen();
	}
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "Theroar.otf");
	graphics::playMusic(std::string(ASSET_PATH) + "JungleSounds.mp3",0.5f,true,4000);
}

Game::Game()
{
}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
