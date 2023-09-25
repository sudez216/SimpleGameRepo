#include "Game.h"
 // this->붙이는 이유 : class Game 이라는 말(Game Class 안에 있는 애들만 붙이자), 안붙여도 되지만 꼭 붙여야 되는 때도 있음
 // ->동적생성 .정적생성


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
	// 한 윈도우에 표시되는 최대 개수 제한
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// 적이 생성되는 시간 간격
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

	// 여러개 적을 생성되는 즉시 움직임
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// 적이 윈도우 밖으로 벗어나면(y좌표가 window의 크기를 넘어가면) 삭제
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
	// Close 버튼을 클릭 Event 감지 => Window CLose
	while (this->Window->pollEvent(e)) // Event 감지
	{
		// Event type 구분
		switch (e.type)
		{
		case Event::Closed: // Window close 버튼 클릭 이벤트 종류
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
	// 이전 프레임에 그려진 내용을 지움
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
