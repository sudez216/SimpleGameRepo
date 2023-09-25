#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

void SimpleWindow()
{
	// ������ â ����
	RenderWindow Window(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);

	Event e;

	while (Window.isOpen()) // isOpen() : Window open ���� Ȯ�� => true
	{
		// Close ��ư�� Ŭ�� Event ���� => Window CLose
		while (Window.pollEvent(e)) // Event ����
		{
			// Event type ����
			switch (e.type)
			{
			case Event::Closed: // Window close ��ư Ŭ�� �̺�Ʈ ����
				Window.close();
				break;
			}
		}
	}
}