#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

class Game
{
private:
	/*
	* Window
	*/
	RenderWindow* Window;

	Event e;

	// Window ������ ���� �ʱ�ȭ
	void InitWindowPointer();

	// Window ���� ����
	void InitWindow();

	// ���� ������ Window ����
	void DeleteWindow();

	/*
	* Enemy
	*/
	RectangleShape RectEnemy;
	vector<RectangleShape> RectEnemies;

	// Spawn Value
	float EnemySpawnTime;
	float EnemySpawnTimeMax;
	int EnemyMaxNumber;

	// Init RectEnemy
	void InitRectEnemy();
	
	// Set Spawn Value
	void SetSpawnValue();

	/*
	* Player
	*/

	CircleShape Player;
	
	// Init Player
	void InitPlayer();

public:
	/*
	* ������ & �Ҹ���
	*/  
	Game();
	~Game();

	/*
	* Enemy
	*/
	
	
	// Spawn Enemy
	void SpawnEnemy();

	void UpdateEnemy();

	/*
	* Player
	*/

	void UpdatePlayer();

	/*
	* Collision
	*/
	
	void UpdateCollision();

	void GameOver();

	/*
	* Game Loop
	*/

	// �� const : ��ȯ���� ������� ����
	// �� const : �Ű�����, �Լ� ���� ���� ������� ����
	const bool Running() const;

	void EventHandler();

	void Update();
	
	void Render();
};