#pragma once  //define _IS_THIS_HEADER_INCLUDED(������ �ѹ���)
#define Key_Exit 27
#define Key_Left 'a'
#define Key_RIGHT 'b'
#define ANSI_COLOR_MAGENTA
namespace MUSoeun
{
	void gotoxy(int x, int y)

	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	class MGameLoop
	{
	public:

		bool isGameRunning = false;

		MGameLoop() {}
		~MGameLoop() {}

		void Initialize()
		{
			
			isGameRunning = true;
			gotoxy(0, 10);
			std::cout << "�ʱ�ȭ �Ϸ�" << std::endl;
		}
		void Release()
		{
			gotoxy(0, 10);
			std::cout << "�ý��� ���� �Ϸ�" << std::endl;
		}
		void Update()
		{
			gotoxy(0, 10);
			std::cout << "������Ʈ�� �Ϸ�" << std::endl;

			if (_kbhit())
			{
				keyEvent(_getch());
				
			}
		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << "������ �Ϸ�" << std::endl;
		}
		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}
			Release();
		}
		void keyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
			case 'a':  //-32���� ȭ��ǥŰ
				
				break;
			case 'd':  //-32������ ȭ��ǥŰ
				
				break;
				//27 : esc�̰� ���� ����Ű
				//�ѹ� �������� �Ͻ�����
				//�ι� �������� ���� ����
			case 27:  
				if (isGameRunning) {
					break; 
				}
				else {
					isGameRunning = true;
					std::cout << "Game paused\n";
				}
			}
            else if (key == ' ') { 
	        isGameRunning = !isGameRunning; 
	        if (isGameRunning) {
		     std::cout << "Game paused\n" << std::endl;;
	          }
	      else {
		    std::cout << "Game resumed\n" << std::endl;;
	      }
			}
		}
		if (!isGameRunning) {
			
		}
	}	std::cout << "���� ������ �����Ͻðڽ��ϱ�?" << std::endl;
				break;
			default :
				break;
			}
		}
	};
}