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

 - Solution Explorer > Drop Down Menu(��Ŭ��) > Properties
 - ��� ���� ����
	- Configuration > All Configuration
	- Platform > Win32
 - C/C++ > General > Aditional include Directories
 	 - SFML���� �����ؿ� ����/������ �ִ� ��ġ(����)�� ����
	 - $(SolutionDir) : ���� ������Ʈ ����

 - Linker > General > Additional Library Directories
	 - SFML���� �����ؿ� ����/������ �ִ� ��ġ(����)�� ����

 - Linker > Input > Additional Dependancies
	 - Configuration > Release

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

 - Event Delegate
 - Event Listenig
 
