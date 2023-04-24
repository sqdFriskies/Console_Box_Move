#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
#define KEY_ARROW_UP 72
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75

void drawBox(HANDLE hStdOut, COORD Pos);
int main()
{
	const int NotUsed = std::system("color 7");
	SetConsoleTitle(L"GARIK MY LOOOOOOOOOOOOOOVE(MARINA LOOOOOVE OF GARIK)"); //заголовок окна
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(hStdOut, &csbiInfo);
	WORD wOldColorAttrs;
	wOldColorAttrs = csbiInfo.wAttributes; // старые атрибуты

	COORD cursorPos = { 3, 4 };
	drawBox(hStdOut, cursorPos);// Печать прямоугольника
	int iKey = 0;


	while (iKey != 27) // Выход по клавише ESC
	{

		if (_kbhit())
		{
			iKey = _getch();
			switch (iKey)
			{
			case 120: //клавиша x
			case 88: //клавиша X
			case 27: // клавиша ESC
				exit(0);//завершение программы
				break;
			case 72: // UP
				system("cls");
				cursorPos.Y -= 1;
				drawBox(hStdOut, cursorPos);
				break;
			case 80: // DOWN
				system("cls");
				cursorPos.Y += 1;
				drawBox(hStdOut, cursorPos);
				break;

			case 75: // LEFT
				system("cls");
				cursorPos.X -= 1;
				drawBox(hStdOut, cursorPos);
				break;
			case 77: // RIGHT
				system("cls");
				cursorPos.X += 1;
				drawBox(hStdOut, cursorPos);
				break;
			}

		}
	}


}

void printStarLine(int len)
{
	for (int j = 0; j < len; j++)
	{
		cout << '*';
	}
}
void drawBox(HANDLE hStdOut, const COORD Pos)
{
	const short int lenBox = 12;
	COORD localPos = Pos;
	for (int i = 0; i < 7; i++)
	{
		SetConsoleCursorPosition(hStdOut, localPos);
		printStarLine(lenBox);
		localPos.Y += 1;
	}

	localPos = Pos;
	localPos.X += 1;
	localPos.Y += 1;
	for (int i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(hStdOut, localPos);
		for (int j = 0; j < 10; j++)
		{
			cout << ' ';
		}
		localPos.Y += 1;
	}

	localPos = Pos;
	localPos.X += 4;
	localPos.Y += 3;
	SetConsoleCursorPosition(hStdOut, localPos);
	cout << "PIPA";

}


