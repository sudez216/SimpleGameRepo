#include "Game.h"

void Game::InitVariable()
{
	// nullptr : �ּҰ��� ���� ���� -> �ƹ��͵� ����Ű�� �ʴ� ����
	this->Window = nullptr;
}

void Game::InitWindow()
{
	this->VMode.width = 1024;
	this->VMode.height = 768;
	this->Window = new sf::RenderWindow(this->VMode, "Simple Game", sf::Style::Titlebar | sf::Style::Close);
	// sf::VideoMode(1024, 768), => this->VMode
}

Game::Game()
{
	this->InitVariable();
	this->InitWindow();
}

Game::~Game()
{
}

const bool Game::IsCreate()
{
	return this->Window->isOpen();
}

void Game::Update()
{
}

void Game::Render()
{
}
