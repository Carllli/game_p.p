#pragma once  //define _IS_THIS_HEADER_INCLUDED(컴파일 한번만)
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
			std::cout << "초기화 완료" << std::endl;
		}
		void Release()
		{
			gotoxy(0, 10);
			std::cout << "시스템 해제 완료" << std::endl;
		}
		void Update()
		{
			gotoxy(0, 10);
			std::cout << "업데이트중 완료" << std::endl;

			if (_kbhit())
			{
				keyEvent(_getch());
				
			}
		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << "렌더링 완료" << std::endl;
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
			case 'a':  //-32왼쪽 화살표키
				
				break;
			case 'd':  //-32오른쪽 화살표키
				
				break;
				//27 : esc이고 게임 종료키
				//한번 눌렀을때 일시정지
				//두번 눌렀을때 게임 종료
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
	}	std::cout << "정말 게임을 종료하시겠습니까?" << std::endl;
				break;
			default :
				break;
			}
		}
	};
}