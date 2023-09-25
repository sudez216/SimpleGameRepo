#include "Game.h"
 // this->���̴� ���� : class Game �̶�� ��(Game Class �ȿ� �ִ� �ֵ鸸 ������), �Ⱥٿ��� ������ �� �ٿ��� �Ǵ� ���� ����
 // ->�������� .��������


void Game::InitWindowPointer()
{
	this->Window = nullptr;
}

void Game::InitWindow()
{
	//int* a = new int(3);
	this->Window = new RenderWindow(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);

	this->Window->setFramerateLimit(60);
}

void Game::DeleteWindow()
{
	delete this->Window;
}

void Game::InitRectEnemy()
{
	RectEnemy.setSize(Vector2f(50.0f, 50.0f));
	RectEnemy.setFillColor(Color::Red);
	RectEnemy.setPosition(30.0f, 30.0f);
}

void Game::InitPlayer()
{
	this->Player.setRadius(30.0f);
	this->Player.setFillColor(Color::White);
	this->Player.setPosition(this->Window->getSize().x / 2, this->Window->getSize().y / 2);
}

Game::Game()
{
	// Window
	this->InitWindowPointer();
	this->InitWindow();

	// Enemy
	this->InitRectEnemy();
	this->SetSpawnValue();

	// Player
	this->InitPlayer();
}

Game::~Game()
{
	this->DeleteWindow();
}

void Game::SetSpawnValue()
{
	this->EnemySpawnTime = 0.0f;
	this->EnemySpawnTimeMax = 20.0f;
	this->EnemyMaxNumber = 10;
}

void Game::SpawnEnemy()
{
	this->RectEnemy.setPosition(static_cast<float>(rand() % 1024), 0.0f);
	
	this->RectEnemies.push_back(this->RectEnemy);
}

void Game::UpdateEnemy()
{
	// �� �����쿡 ǥ�õǴ� �ִ� ���� ����
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// ���� �����Ǵ� �ð� ����
		if (this->EnemySpawnTime >= this->EnemySpawnTimeMax)
		{
			this->SpawnEnemy();
			this->EnemySpawnTime = 0.0f;
		}
		else
		{
			this->EnemySpawnTimeMax += 1.0f;
		}
	}

	// ������ ���� �����Ǵ� ��� ������
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// ���� ������ ������ �����(y��ǥ�� window�� ũ�⸦ �Ѿ��) ����
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{
			this->RectEnemies.erase(this->RectEnemies.begin() + i);
		}
	}
}

void Game::UpdatePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->Player.move(-5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->Player.move(5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->Player.move(0.0f, -5.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->Player.move(0.0f, 5.0f);
	}

}

void Game::UpdateCollision()
{
	for(int i = 0; i < RectEnemies.size(); i++)
		if (this->Player.getGlobalBounds().intersects(this->RectEnemies[i].getGlobalBounds()))
		{
			this->GameOver();
		}
}

void Game::GameOver()
{
	delete this->Window;
}


const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	// Close ��ư�� Ŭ�� Event ���� => Window CLose
	while (this->Window->pollEvent(e)) // Event ����
	{
		// Event type ����
		switch (e.type)
		{
		case Event::Closed: // Window close ��ư Ŭ�� �̺�Ʈ ����
			this->Window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->UpdateEnemy();

	this->UpdatePlayer();

	this->UpdateCollision();
}

void Game::Render()
{
	// ���� �����ӿ� �׷��� ������ ����
	this->Window->clear();

	// draw object
	// draw Enemy
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->Window->draw(this->RectEnemies[i]);
	}

	// draw player
	this->Window->draw(this->Player);

	// display
	this->Window->display();
}
