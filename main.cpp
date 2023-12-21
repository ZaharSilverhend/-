#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <chrono>


void Menu(int& command1, int& command2, int& command3)
{
	//Нажатая клавиша для выбора режимов
	int Nazhatai_Clavisha;
	//Текст главная
	std::string text = "\n\n\t__--=========-@__@-=========--__\n\n\t\tп_я_т_н_а_ш_к_и\n\n\t  _-=========-@__@-=========-_\n\n\n\tНажмите <ПРОБЕЛ> для продолжения";
	std::string text2 = "\n\n\t__--=========-@__@-=========--__\n\n\t\tп_я_т_н_а_ш_к_и\n\n\t  _-=========-@__@-=========-_";
	system("cls");
	for (char i : text2)
	{
		std::cout << i;
		Sleep(1);
	}
	bool count = true;
	//Главная (ожидает нажатия клавиши)
	while (count)
	{
		for (int i = 39; i < 54; i += 2)
		{
			Sleep(100);
			text[i] -= 32;
			printf("\x1b[H");
			std::cout << text;
			text[i] += 32;
			if (_kbhit())
			{
				int ch = _getch();
				if (ch == 32)
				{
					count = false;
					break;
				}
			}
		}
	}
	//Выбор размера поля
	system("cls");
	std::cout << "\n\n\tВыберите размер поля:\n\n";
	printf("\t\x1b[90m<\x1b[0m3 x 3\x1b[90m>\x1b[0m");
	std::cout << "\n\t\x1b[90m  4 x 4\x1b[0m";
	do {
		Nazhatai_Clavisha = _getch();
		switch (Nazhatai_Clavisha)
		{
		case 119:
			if (command1 != 1)
			{
				command1--;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите размер поля:\n\n";
				std::cout << "\t\x1b[90m<\x1b[0m3 x 3\x1b[90m>\x1b[0m";
				std::cout << "\n\t\x1b[90m  4 x 4 \x1b[0m";
			}
			break;
		case 115:
			if (command1 != 2)
			{
				command1++;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите размер поля:\n\n";
				std::cout << "\t\x1b[90m  3 x 3 \x1b[0m";
				std::cout << "\n\t\x1b[90m<\x1b[0m4 x 4\x1b[90m>\x1b[0m";
			}
			break;
		}
	} while (Nazhatai_Clavisha != 13);

	//Выбор кто играет
	system("cls");
	std::cout << "\n\n\tВыберите игрока:\n\n";
	std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  Человек \x1b[0m";
	do
	{
		Nazhatai_Clavisha = _getch();
		switch (Nazhatai_Clavisha)
		{
		case 119:
			if (command2 != 1)
			{
				command2--;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите игрока:\n\n";
				std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  Человек \x1b[0m";

			}
			break;
		case 115:
			if (command2 != 2)
			{
				command2++;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите игрока:\n\n";
				std::cout << "\t\x1b[90m  CPU \x1b[0m\n";
				printf("\t\x1b[90m<\x1b[0mЧеловек\x1b[90m>\x1b[0m");
			}
			break;
		}

	} while (Nazhatai_Clavisha != 13);

	//Выбор кто заполняет 
	system("cls");
	std::cout << "\n\n\tВыберите способ перемешки:\n\n";
	std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  Ручная \x1b[0m";
	do
	{
		Nazhatai_Clavisha = _getch();
		switch (Nazhatai_Clavisha)
		{
		case 119:
			if (command3 != 1)
			{
				command3--;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите способ перемешки:\n\n";
				std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  Ручная \x1b[0m";
			}
			break;
		case 115:
			if (command3 != 2)
			{
				command3++;
				printf("\x1b[H");
				std::cout << "\n\n\tВыберите способ перемешки:\n\n";
				std::cout << "\t\x1b[90m  CPU \x1b[0m\n\t\x1b[90m<\x1b[0mРучная\x1b[90m>\x1b[0m";;
			}
			break;
		}

	} while (Nazhatai_Clavisha != 13);

	//Очишение консоли после выбора режимов
	system("cls");
}
//Подсчет результатов игры
void Win(int CountPerestonovok, const std::chrono::time_point<std::chrono::steady_clock>& start, const std::chrono::time_point<std::chrono::steady_clock>& finish)
{
	Sleep(400);
	std::string str = "\n\tYou Win!";
	for (char ch : str)
	{
		std::cout << ch;
		Sleep(60);
	}
	Sleep(140);
	std::cout << "\n\t\x1b[90mКоличество совершенных перестоновок:\x1b[0m " << CountPerestonovok << std::endl;
	std::chrono::seconds duration_sec = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
	std::chrono::minutes duration_min = std::chrono::duration_cast<std::chrono::minutes>(finish - start);
	std::chrono::hours duration_hour = std::chrono::duration_cast<std::chrono::hours>(finish - start);

	if (duration_sec.count() < 60)
	{
		std::cout << "\t\x1b[90mВремя игры:\x1b[0m " << duration_sec.count() << " сек" << std::endl << std::endl << std::endl;
	}
	else if (duration_min.count() < 60)
	{
		std::cout << "\t\x1b[90mВремя игры:\x1b[0m " << duration_min.count() << " мин" << std::endl << std::endl << std::endl;
	}
	else
	{
		std::cout << "\t\x1b[90mВремя игры:\x1b[0m " << duration_hour.count() << " час" << std::endl << std::endl << std::endl;
	}
}
//Заполнение поля изначально 
void zapolnenye(std::string(&field)[4][4], int x, int y)
{
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			field[i][j] = std::to_string(k);
			k++;
		}
	x = 0;
	y = 0;
	field[y][x] = "  ";
}
void zapolnenye2(std::string(&field2)[3][3], int x, int y)
{
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			field2[i][j] = std::to_string(k);
			k++;
		}
	x = 0;
	y = 0;
	field2[y][x] = " ";
}
//Проверяем собрано поле или нет
bool isFinalField(std::string field[4][4])
{
	std::string Final[4][4] =
	{
		{"  ", "1", "2", "3"},
		{"4", "5", "6", "7"},
		{"8", "9", "10", "11"},
		{"12", "13", "14", "15"}
	};
	bool count = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] != Final[i][j])
			{
				count = false;
				break;
			}
		}
	}
	return count;
}
bool isFinalField2(std::string field2[3][3])
{
	std::string Final[3][3] =
	{
		{" ", "1", "2"},
		{"3", "4", "5" },
		{"6", "7", "8" }
	};
	bool count = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (field2[i][j] != Final[i][j])
			{
				return count = false;
			}
		}
	}
	return count;
}
//Проверяем нет ли чмсла которое мы хотим добавить в массив уже в нем
bool Proverca(int count, std::string arr[4][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (std::to_string(count) == arr[i][j])
			{
				return true;
				break;
			}
	return false;
}
bool Proverca2(int count, std::string arr[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (std::to_string(count) == arr[i][j])
				return true;
	return false;
}
//Выводим поля в консоль
void DisplayField(std::string field[4][4])
{
	std::cout << "\n\n\t\x1b[90m+----+----+----+----+\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t\x1b[90m|\x1b[0m ";
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j].length() > 1)
			{
				std::cout << field[i][j] << " \x1b[90m|\x1b[0m ";
			}
			else
			{
				std::cout << field[i][j] << "  \x1b[90m|\x1b[0m ";
			}
		}
		std::cout << std::endl << "\t\x1b[90m+----+----+----+----+\x1b[0m" << std::endl;
	}
}
void DisplayField2(std::string field2[3][3])
{
	std::cout << "\n\n\t\x1b[90m+---+---+---+\x1b[0m" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\t\x1b[90m|\x1b[0m ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << field2[i][j] << " \x1b[90m|\x1b[0m ";
		}
		std::cout << std::endl << "\t\x1b[90m+---+---+---+\x1b[0m" << std::endl;
	}
}
//Заполнение поля игроком 
void User_Zaponeney(std::string(&field)[4][4], int& x, int& y)
{
	bool count = true;
	DisplayField(field);
	while (count)
	{
		switch (_getch())
		{
		case 119: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y - 1][x]);
				y--;
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 115: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y + 1][x]);
				y++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 100:  //Ключ право
			//Проверка на выход за пределы
			if (x != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x + 1]);
				x++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 97:// Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x - 1]);
				x--;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 27:
			count = false;
			break;
		}
	}
	field[y][x] = "  ";
	system("cls");
	DisplayField(field);
	std::cout << "\n\tРучное заполнение успешно завершенно!";
	Sleep(1000);
	system("cls");
	DisplayField(field);
}
void User_Zaponeney2(std::string(&field2)[3][3], int& x, int& y)
{
	bool count = true;
	DisplayField2(field2);
	while (count)
	{
		switch (_getch())
		{
		case 119: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 115: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y + 1][x]);
				y++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 100:  //Ключ право
			//Проверка на выход за пределы
			if (x != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 97:// Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 27:
			count = false;
			break;
		}
	}
	field2[y][x] = " ";
	system("cls");
	DisplayField2(field2);
	std::cout << "\n\tРучное заполнение успешно завершенно!";
	Sleep(1000);
	system("cls");
	DisplayField2(field2);
}
//Bot заполняет
void Rundom_Zapolnenie(std::string(&field)[4][4], int& x, int& y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int RundNum = rand() % 16;
			while (Proverca(RundNum, field))
			{
				RundNum = rand() % 16;
			}

			field[i][j] = std::to_string(RundNum);
			if (RundNum == 0)
			{
				y = i;
				x = j;
			}
		}
	}
	field[y][x] = "  ";
	DisplayField(field);
}
void Rundom_Zapolnenie2(std::string(&field2)[3][3], int& x, int& y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int RundNum = rand() % 9;
			while (Proverca2(RundNum, field2))
			{
				RundNum = rand() % 9;
			}
			field2[i][j] = std::to_string(RundNum);
			if (RundNum == 0)
			{
				y = i;
				x = j;
			}
		}
	}
	field2[y][x] = " ";
	DisplayField2(field2);
}
//Процесс игры (Человек)
void User_Game(std::string(&field)[4][4], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField(field))
	{
		switch (_getch())
		{
		case 119: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y - 1][x]);
				y--;
				// Увеличение перестановок
				CountPerestonovok++;
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 115: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y + 1][x]);
				y++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 100:  //Ключ право
			//Проверка на выход за пределы
			if (x != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x + 1]);
				x++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 97:// Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x - 1]);
				x--;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		}
	}
}
void User_Game2(std::string(&field2)[3][3], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField2(field2))
	{
		switch (_getch())
		{
		case 119: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
				// Увеличение перестановок
				CountPerestonovok++;
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 115: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y + 1][x]);
				y++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 100:  //Ключ право
			//Проверка на выход за пределы
			if (x != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 97:// Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		}
	}
}
//Процесс игры (Бот)
void Bot_Game(std::string(&field)[4][4], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField(field))
	{
		int RN = rand() % 4 + 1;
		switch (RN)
		{
		case 1: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y - 1][x]);
				y--;
				// Увеличение перестановок
				CountPerestonovok++;
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 2: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y + 1][x]);
				y++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 3:  //Ключ право
			//Проверка на выход за пределы
			if (x != 3)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x + 1]);
				x++;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 4:// Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field[y][x], field[y][x - 1]);
				x--;
				// Увеличение перестановок
				CountPerestonovok++;
				//Выводим поле
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		}
	}
}
void Bot_Game2(std::string(&field2)[3][3], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField2(field2))
	{
		int RN = rand() % 4 + 1;

		switch (RN)
		{
		case 1: // Ключь вверх
			//Проверка на выход за пределы
			if (y != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
				// Увеличение перестановок
				CountPerestonovok++;

				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 2: // Ключ вниз
			//Проверка на выход за пределы
			if (y != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y + 1][x]);

				y++;

				// Увеличение перестановок
				CountPerestonovok++;

				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 3: //Ключ право
			//Проверка на выход за пределы
			if (x != 2)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;

				// Увеличение перестановок
				CountPerestonovok++;

				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 4: // Ключ лево
			//Проверка на выход за пределы
			if (x != 0)
			{
				//Делаем смещение пустой ячейки
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;

				// Увеличение перестановок
				CountPerestonovok++;

				//Выводим поле
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		}
	}
}

int main()
{
	//Скрытие курсора
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(console, &cursorInfo);

	system("chcp 1251");
	srand(time(NULL));

	//Координаты пустой клетки
	int x = 0, y = 0;
	//Количество перестановок
	int CountPerestonovok = 0;
	//Команды пользователя для режимов игры
	int command1 = 1, command2 = 1, command3 = 1, command4 = 1;
	//Поля 3х3 и 4х4
	std::string field[4][4];
	std::string field2[3][3];
	//Меню 
	Menu(command1, command2, command3);
	//Кто будет заполнять
	switch (command3)
	{
		//BOT заполняет
	case 1:
		switch (command1)
		{
		case 1:
			//3x3
			Rundom_Zapolnenie2(field2, x, y);
			break;
		case 2:
			//4x4
			Rundom_Zapolnenie(field, x, y);
			break;
		}
		break;
		//Человек заполняет
	case 2:
		switch (command1)
		{
		case 1:
			//3x3
			zapolnenye2(field2, x, y);
			User_Zaponeney2(field2, x, y);
			break;
		case 2:
			//4x4
			zapolnenye(field, x, y);
			User_Zaponeney(field, x, y);
			break;
		}
		break;
	}
	//Записываю время начала ишры
	auto start = std::chrono::steady_clock::now();
	auto finish = std::chrono::steady_clock::now();
	//Кто будет играть 
	switch (command2)
	{
		//Собирает <BOT>
	case 1:
		switch (command1)
		{
		case 1:
			Bot_Game2(field2, x, y, CountPerestonovok);
			break;
		case 2:
			Bot_Game(field, x, y, CountPerestonovok);
			break;
		}
		//Собирает <Человек>
	case 2:
		switch (command1)
		{
		case 1:
			User_Game2(field2, x, y, CountPerestonovok);
			break;
		case 2:
			User_Game(field, x, y, CountPerestonovok);
			break;
		}
	}
	//Записываем время окончания сборки
	finish = std::chrono::steady_clock::now();
	//Вывод результатов игры
	Win(CountPerestonovok, start, finish);
	system("pause");
	exit(0);

	return 0;
}


