#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <chrono>
#include <thread>

//������� ���������� ������������
void CoutPerestanovka(int count)
{
	std::cout << "\x1b[13;9H\x1b[90m���������� ������������:\x1b[0m " << count;
}
//����� � ������
void Time(std::atomic<bool>& stopFlag)
{
	int time = 0;

	std::cout << "\x1b[14;9H\x1b[90m����� - \x1b[0m" << time;
	while (stopFlag)
	{
		//����� ���� stopFlag ������� �� false
		std::cout << "\x1b[14;9H\x1b[90m����� - \x1b[0m" << time;
		if (!stopFlag)
		{
			std::cout << "\x1b[14;9H\x1b[90m����� - \x1b[0m" << time;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		time++;

	}
}
//������� ����������� ����
void Win(int CountPerestonovok)
{
	Sleep(400);
	std::string str = "\x1b[15;9HYou Win!\n\n\t";
	for (char ch : str)
	{
		std::cout << ch;
		Sleep(60);
	}
}
//����
void Menu(int& command1, int& command2, int& command3)
{
	//������� ������� ��� ������ �������
	int Nazhatai_Clavisha;
	//����� �������
	std::string text = "\n\n\t__--=========-@__@-=========--__\n\n\t\t�_�_�_�_�_�_�_�\n\n\t  _-=========-@__@-=========-_\n\n\n\t\x1b[90m������� <\x1b[0m������\x1b[90m> ��� �����������\x1b[0m";
	std::string text2 = "\n\n\t__--=========-@__@-=========--__\n\n\t\t�_�_�_�_�_�_�_�\n\n\t  _-=========-@__@-=========-_";
	system("cls");
	for (char i : text2)
	{
		std::cout << i;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	bool count = true;
	//������� (������� ������� �������)
	while (count)
	{
		for (int i = 39; i < 54; i += 2)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
	int count2 = 1;
	while (count2 < 4)
	{
		if (count2 == 0)
		{
			system("cls");
			exit(0);
		}
		switch (count2)
		{
		case 1:
			//����� ������� ����
			system("cls");
			std::cout << "\n\n\t�������� ������ ����:\n\n";
			std::cout << "\t\x1b[90m<\x1b[0m3 x 3\x1b[90m>\x1b[0m";
			std::cout << "\n\t\x1b[90m  4 x 4\x1b[0m";
			std::cout << "\n\n\x1b[90m\n\t����� {\x1b[0mESC\x1b[90m}\x1b[0m";
			do {
				Nazhatai_Clavisha = _getch();
				if (Nazhatai_Clavisha == 13)
				{
					count2 = 2;
				}
				switch (Nazhatai_Clavisha)
				{
				case 119:
					if (command1 != 1)
					{
						command1--;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ������ ����:\n\n";
						std::cout << "\t\x1b[90m<\x1b[0m3 x 3\x1b[90m>\x1b[0m";
						std::cout << "\n\t\x1b[90m  4 x 4 \x1b[0m";
					}
					break;
				case 115:
					if (command1 != 2)
					{
						command1++;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ������ ����:\n\n";
						std::cout << "\t\x1b[90m  3 x 3 \x1b[0m";
						std::cout << "\n\t\x1b[90m<\x1b[0m4 x 4\x1b[90m>\x1b[0m";
					}
					break;
				case 27:
					count2--;
					Nazhatai_Clavisha = 13;
					command1 = 1;
					command2 = 1;
					command3 = 1;
					break;
				}
			} while (Nazhatai_Clavisha != 13);
			break;
		case 2:
			//����� ��� ������
			system("cls");
			std::cout << "\n\n\t�������� ������:\n\n";
			std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  ������� \x1b[0m";
			std::cout << "\n\n\x1b[90m\n\t<---  {\x1b[0mESC\x1b[90m}\x1b[0m";
			do
			{
				Nazhatai_Clavisha = _getch();
				if (Nazhatai_Clavisha == 13)
				{
					count2 = 3;
				}
				switch (Nazhatai_Clavisha)
				{
				case 119:
					if (command2 != 1)
					{
						command2--;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ������:\n\n";
						std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  ������� \x1b[0m";

					}
					break;
				case 115:
					if (command2 != 2)
					{
						command2++;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ������:\n\n";
						std::cout << "\t\x1b[90m  CPU \x1b[0m\n";
						printf("\t\x1b[90m<\x1b[0m�������\x1b[90m>\x1b[0m");
					}
					break;
				case 27:
					count2--;
					Nazhatai_Clavisha = 13;
					command1 = 1;
					command2 = 1;
					command3 = 1;
					break;
				}

			} while (Nazhatai_Clavisha != 13);

			break;
		case 3:
			//����� ��� ��������� 
			system("cls");
			std::cout << "\n\n\t�������� ����� �������������:\n\n";
			std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  ������ \x1b[0m";
			std::cout << "\n\n\x1b[90m\n\t<---  {\x1b[0mESC\x1b[90m}\x1b[0m";
			do
			{
				Nazhatai_Clavisha = _getch();
				if (Nazhatai_Clavisha == 13)
				{
					count2 = 4;
				}
				switch (Nazhatai_Clavisha)
				{
				case 119:
					if (command3 != 1)
					{
						command3--;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ����� �������������:\n\n";
						std::cout << "\t\x1b[90m<\x1b[0mCPU\x1b[90m>\x1b[0m\n\t\x1b[90m  ������ \x1b[0m";
					}
					break;
				case 115:
					if (command3 != 2)
					{
						command3++;
						printf("\x1b[H");
						std::cout << "\n\n\t�������� ����� �������������:\n\n";
						std::cout << "\t\x1b[90m  CPU \x1b[0m\n\t\x1b[90m<\x1b[0m������\x1b[90m>\x1b[0m";;
					}
					break;
				case 27:
					count2--;
					Nazhatai_Clavisha = 13;
					command1 = 1;
					command2 = 1;
					command3 = 1;
					break;
				}

			} while (Nazhatai_Clavisha != 13);

			break;

		}
	}
	//�������� ������� ����� ������ �������
	system("cls");
}
//���������� ���� ���������� 
void Zapolnenye(std::string(&field)[4][4], int x, int y)
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
void Zapolnenye2(std::string(&field2)[3][3], int x, int y)
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
//��������� ������� ���� ��� ���
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
//��������� ��� �� ����� ������� �� ����� �������� � ������ ��� � ���
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
//������� ���� � �������
void DisplayField(std::string field[4][4])
{
	std::cout << "\x1b[3;9H\x1b[90m+----+----+----+----+\x1b[0m" << std::endl;
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
	std::cout << "\x1b[3;9H\x1b[90m+---+---+---+\x1b[0m" << std::endl;
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
//���������� ���� ������� 
void User_Zaponeney(std::string(&field)[4][4], int& x, int& y)
{
	bool count = true;
	while (count)
	{
		//������� ����
		DisplayField(field);
		std::cout << "\x1b[90m\n\t��� ���������� ������������� ������� <\x1b[0mESC\x1b[90m>\x1b[0m";
		switch (_getch())
		{
		case 119: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y - 1][x]);
				y--;
			}
			break;
		case 115: // ���� ����
			//�������� �� ����� �� �������
			if (y != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y + 1][x]);
				y++;
			}
			break;
		case 100:  //���� �����
			//�������� �� ����� �� �������
			if (x != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x + 1]);
				x++;
			}
			break;
		case 97:// ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x - 1]);
				x--;
			}
			break;
		case 27:
			count = false;
			break;
		}
	}
	field[y][x] = "  ";
	DisplayField(field);
	std::cout << "\n\t������ ������������� ������� ����������!             ";
	Sleep(1000);
	system("cls");
	DisplayField(field);
}
void User_Zaponeney2(std::string(&field2)[3][3], int& x, int& y)
{
	bool count = true;

	while (count)
	{
		DisplayField2(field2);
		std::cout << "\x1b[90m\n\t��� ���������� ������������� ������� <\x1b[0mESC\x1b[90m>\x1b[0m";
		switch (_getch())
		{
		case 119: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
			}
			break;
		case 115: // ���� ����
			//�������� �� ����� �� �������
			if (y != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y + 1][x]);
				y++;
			}
			break;
		case 100:  //���� �����
			//�������� �� ����� �� �������
			if (x != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;
			}
			break;
		case 97:// ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;
			}
			break;
		case 27:
			count = false;
			break;
		}

	}
	field2[y][x] = " ";
	DisplayField2(field2);
	std::cout << "\n\t������ ������������� ������� ����������!                ";
	Sleep(1000);
	system("cls");
	DisplayField2(field2);
}
//Bot ���������
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
//������� ���� (�������)
void User_Game(std::string(&field)[4][4], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField(field))
	{
		switch (_getch())
		{
		case 119: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y - 1][x]);
				y--;
				// ���������� ������������
				CountPerestonovok++;
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 115: // ���� ����
			//�������� �� ����� �� �������
			if (y != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y + 1][x]);
				y++;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 100:  //���� �����
			//�������� �� ����� �� �������
			if (x != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x + 1]);
				x++;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		case 97:// ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x - 1]);
				x--;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField(field);
			}
			break;
		}
		CoutPerestanovka(CountPerestonovok);
	}
}
void User_Game2(std::string(&field2)[3][3], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField2(field2))
	{
		switch (_getch())
		{
		case 119: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
				// ���������� ������������
				CountPerestonovok++;
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 115: // ���� ����
			//�������� �� ����� �� �������
			if (y != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y + 1][x]);
				y++;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 100:  //���� �����
			//�������� �� ����� �� �������
			if (x != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		case 97:// ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;
				// ���������� ������������
				CountPerestonovok++;
				//������� ����
				printf("\x1b[H");
				DisplayField2(field2);
			}
			break;
		}
		CoutPerestanovka(CountPerestonovok);
	}
}
//������� ���� (���)
void Bot_Game(std::string(&field)[4][4], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField(field))
	{
		int RN = rand() % 4 + 1;
		switch (RN)
		{
		case 1: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y - 1][x]);
				y--;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 2: // ���� ����
			//�������� �� ����� �� �������
			if (y != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y + 1][x]);
				y++;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 3:  //���� �����
			//�������� �� ����� �� �������
			if (x != 3)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x + 1]);
				x++;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 4:// ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field[y][x], field[y][x - 1]);
				x--;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		}
		//������� ����
		DisplayField(field);
		CoutPerestanovka(CountPerestonovok);
	}
}
void Bot_Game2(std::string(&field2)[3][3], int& x, int& y, int& CountPerestonovok)
{
	while (!isFinalField2(field2))
	{
		int RN = rand() % 4 + 1;
		switch (RN)
		{
		case 1: // ����� �����
			//�������� �� ����� �� �������
			if (y != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y - 1][x]);
				y--;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 2: // ���� ����
			//�������� �� ����� �� �������
			if (y != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y + 1][x]);
				y++;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 3: //���� �����
			//�������� �� ����� �� �������
			if (x != 2)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x + 1]);
				x++;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		case 4: // ���� ����
			//�������� �� ����� �� �������
			if (x != 0)
			{
				//������ �������� ������ ������
				std::swap(field2[y][x], field2[y][x - 1]);
				x--;
				// ���������� ������������
				CountPerestonovok++;
			}
			break;
		}

		//������� ����
		DisplayField2(field2);
		//������� ����������� ������������
		CoutPerestanovka(CountPerestonovok);
	}
}
//����� ������� (��� ������)
int main()
{
	//������� �������
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(console, &cursorInfo);

	system("chcp 1251");
	srand(time(NULL));

	//���������� ������ ������
	int x = 0, y = 0;
	//���������� ������������
	int CountPerestonovok = 0;
	//������� ������������ ��� ������� ����
	int command1 = 1, command2 = 1, command3 = 1, command4 = 1;
	//���� 3�3 � 4�4
	std::string field[4][4];
	std::string field2[3][3];
	//���� 
	Menu(command1, command2, command3);
	//��� ����� ���������
	switch (command3)
	{
		//BOT ���������
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
		//������� ���������
	case 2:
		switch (command1)
		{
		case 1:
			//3x3
			Zapolnenye2(field2, x, y);
			User_Zaponeney2(field2, x, y);
			break;
		case 2:
			//4x4
			Zapolnenye(field, x, y);
			User_Zaponeney(field, x, y);
			break;
		}
		break;
	}
	//��� ����� ������ 
	switch (command2)
	{
		//�������� <BOT>
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
		//�������� <�������>

	case 2:
		//���� ��� ����������� �������
		std::atomic<bool> stopFlag(true);
		//������ ������ ��� �������
		std::thread TwoThread([&stopFlag]() { Time(stopFlag); });
		CoutPerestanovka(CountPerestonovok);
		switch (command1)
		{
		case 1:
			User_Game2(field2, x, y, CountPerestonovok);
			break;
		case 2:
			User_Game(field, x, y, CountPerestonovok);
			break;
		}
		stopFlag = false;
		TwoThread.join();
	}

	//����� ����������� ����
	Win(CountPerestonovok);
	system("pause");
	exit(0);

	return 0;
}

