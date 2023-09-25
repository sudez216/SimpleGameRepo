# SFML ���̺귯�� ��ġ

## https://www.sfml-dev.org/download/sfml/2.6.0/

## �ٿ�ε�

- C++ 17 : 2022 / 32��Ʈ

## ���� ����

```
- SimpleGame - External		 - include
			 - SimpleGame	 - lib
			 - SimleGame.sln
```

 - SFML > includ ��ü ����/���� => SimpleGame > External > include
 - SFML > lib ��ü ����/���� => SimpleGame > External > lib
 - SFML > bin ��ü ����/���� => SimpleGame > SimpleGame
	
 # VS 2022 ȯ�� ����

 - VS 2022 ������ ��� ���� > x64���� x86
 - Solution Explorer > SimpleGame �̸��� ��Ŭ�� > Drop Down Menu(��Ŭ��) > Properties
 - ��� ���� ����
	- Configuration > All Configuration
	- Platform > Win32
 - C/C++ > General > Aditional include Directories
 	 - SFML���� �����ؿ� ����/������ �ִ� ��ġ(����)�� ����
	 - $(SolutionDir) : ���� ������Ʈ ���� ǥ�� �Է�	 - ���� �Է� ���� : $(SolutionDir)\External\include

 - Linker > General > Additional Library Directories
	 - SFML���� �����ؿ� ����/������ �ִ� ��ġ(����)�� ����
	 - ���� �Է� ���� : $(SolutionDir)\External\lib
		
 - Linker > Input > Additional Dependancies
	 - Configuration > Release ī�װ��� ����

 ```
  sfml-system.lib
  sfml-graphics.lib
  sfml-window.lib
  sfml-audio.lib
  sfml-network.lib
 ```

 - Linker > Input > Additional Dependancies
	- Configuration > Debug

 # Event

 ## Event ����

 - ���, ��Ȳ�� ��ȭ
 - Interface�� �����ؼ� ����� ��Ȳ�� ��ȭ
 - Ű����, ���콺�� ����� ��Ȳ�� ��ȭ
	 - Ű���� �̺�Ʈ : Ű �Է�
	 - ���콺 �̺�Ʈ : ���콺 Ŭ��( Press / Release ), �� ��ũ��, ���� Ŭ��, ������
 - ��ġ ��ũ�� : ��ġ, ��������, ��ġ
 - �ε�
	
 ## Event Handling

 - Event Delegate : �������� �̺�Ʈ�� ����
 - Event Listenig : �̺�Ʈ ����
 - Event Handle : ������ �̺�Ʈ�� ���ؼ� ������ ����
 

 # Game Loop

 # SimpleGame ������Ʈ�� ������ Game Ŭ����

 - ������ ���������� Control�ϴ� Ŭ����
 - Enemy ����
 - Player ����
	
 