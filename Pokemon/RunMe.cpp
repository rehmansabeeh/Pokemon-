#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT: // Ctrl+C
		break;
	case CTRL_BREAK_EVENT: // Ctrl+Break
		break;
	case CTRL_CLOSE_EVENT: // Closing the console window
		system("taskkill /im wscript.exe /F");
		break;
	case CTRL_LOGOFF_EVENT: // User logs off. Passed only to services!
		break;
	case CTRL_SHUTDOWN_EVENT: // System is shutting down. Passed only to services!
		break;
	}

	// Return TRUE if handled this message, further handler functions won't be called.
	// Return FALSE to pass this message to further handlers until default handler calls ExitProcess().
	return FALSE;
}

void Rect(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Draw(int j, int i,int R, int G, int B, char orientation, int pixelSize)
{
	int x = 0, y = 0;
	if (orientation == 'F')
	{
		x = 700 + (j * pixelSize); // + 5 pixels for each i and j
		y = 10 + (i * pixelSize);
	}
	else
	{
		x = 100 + (j * pixelSize); // + 5 pixels for each i and j
		y = 100 + (i * pixelSize);
	}

	Rect(x, y, x + pixelSize, y + pixelSize, R, G, B, R, G, B); // Draw a 5 by 5 pixel
}
void Pikachu(char side)
{
	char word[5];
	char pixel[50][50];
	int i = 0, j = 0;
	int pSize = 5;
	Sleep(50); // To avoid rendering  issues
	ifstream pikachu;
	if (side == 'F')
	{
		pikachu.open("Sprites/PikachuF.txt");
		pSize = 4;
	}
	else if (side == 'B')
	{
		pikachu.open("Sprites/PikachuB.txt");
		pSize = 5;
	}

		if (!pikachu.is_open())
		{
			cout << "Unable to open file.";
			_getch();
			exit(EXIT_FAILURE);
		}

		pikachu >> word;
		while (pikachu.good())
		{
			//		cout << word[0];
			//		if(word[0] != '\n')
			pixel[i][j] = word[0];
			//		cout << endl << pixelF[i][j] << endl;
			j++;
			//Implement for loop gmkr
			if (j % 50 == 0)
			{
				i++;
				j = 0;
			}
			//		cout << i << " " << j << endl;
			pikachu >> word;
		}

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				switch (pixel[i][j])
				{
				case 'B':
					Draw(j, i, 70, 70, 70, side, pSize);
					break;
				case 'W':
					Draw(j, i, 255, 255, 255, side, pSize);
					break;
				case 'S':
					Draw(j, i, 162, 73, 7, side, pSize);
					break;
				case 'Y':
					Draw(j, i, 223, 194, 12, side, pSize);
					break;
				case 'E':
					Draw(j, i, 208, 141, 24, side, pSize);
					break;
				case 'R':
					Draw(j, i, 234, 16, 14, side, pSize);
					break;
				default:
					break;
				}
			}
		}
}
void Torchic(char side)
{
	char word[5];
	char pixel[50][50];
	int i = 0, j = 0;
	int pSize = 5;
	Sleep(50); // To avoid rendering  issues
	ifstream Torchic;
	if (side == 'F')
	{
		pSize = 5;
		Torchic.open("Sprites/TorchicF.txt");
	}
	else if (side == 'B')
	{
		pSize = 6;
		Torchic.open("Sprites/TorchicB.txt");
	}
		if (!Torchic.is_open())
		{
			cout << "Unable to open file.";
			_getch();
			exit(EXIT_FAILURE);
		}

		Torchic >> word;
		while (Torchic.good())
		{
			//		cout << word[0];
			//		if(word[0] != '\n')
			pixel[i][j] = word[0];
			//		cout << endl << pixelF[i][j] << endl;
			j++;

			if (j % 50 == 0)
			{
				i++;
				j = 0;
			}
			//		cout << i << " " << j << endl;
			Torchic >> word;
		}

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				switch (pixel[i][j])
				{
				case 'B':
					Draw(j, i, 70, 70, 70, side, pSize);
					break;
				case 'W':
					Draw(j, i, 255, 255, 255, side, pSize);
					break;
				case 'S':
					Draw(j, i, 179, 145, 38, side, pSize);
					break;
				case 'Y':
					Draw(j, i, 236, 189, 51, side, pSize);
					break;
				case 'O':
					Draw(j, i, 249, 135, 46, side, pSize);
					break;
				case 'L':
					Draw(j, i, 242, 153, 83, side, pSize);
					break;
				default:
					break;
				}
			}
		}
}
void Totodile(char side)
{
	char word[5];
	char pixel[50][50];
	int i = 0, j = 0;
	int pSize = 5;
	Sleep(50); // To avoid rendering  issues
	ifstream Totodile;
	if (side == 'F')
	{
		pSize = 5;
		Totodile.open("Sprites/TotodileF.txt");
	}
	else if (side == 'B')
	{
		pSize = 6;
		Totodile.open("Sprites/TotodileB.txt");
	}
		if (!Totodile.is_open())
		{
			cout << "Unable to open file.";
			_getch();
			exit(EXIT_FAILURE);
		}

		Totodile >> word;
		while (Totodile.good())
		{
			//		cout << word[0];
			//		if(word[0] != '\n')
			pixel[i][j] = word[0];
			//		cout << endl << pixelF[i][j] << endl;
			j++;

			if (j % 50 == 0)
			{
				i++;
				j = 0;
			}
			//		cout << i << " " << j << endl;
			Totodile >> word;
		}

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				switch (pixel[i][j])
				{
				case 'B':
					Draw(j, i, 70, 70, 70, side, pSize);
					break;
				case 'W':
					Draw(j, i, 255, 255, 255, side, pSize);
					break;
				case 'E':
					Draw(j, i, 106, 105, 48, side, pSize);
					break;
				case 'Y':
					Draw(j, i, 186, 187, 83, side, pSize);
					break;
				case 'R':
					Draw(j, i, 196, 18, 18, side, pSize);
					break;
				case 'M':
					Draw(j, i, 131, 11, 10, side, pSize);
					break;
				case 'P':
					Draw(j, i, 218, 64, 62, side, pSize);
					break;
				case 'C':
					Draw(j, i, 81, 130, 171, side, pSize);
					break;
				case 'D':
					Draw(j, i, 50, 82, 107, side, pSize);
					break;
				case 'L':
					Draw(j, i, 109, 171, 220, side, pSize);
					break;
				default:
					break;
				}
			}
		}
}
void Menu(int &hp1, int &hp2, char &mode, int &player, string name1, string name2, int ch1, int ch2, int ai[8][3], string item[2][4], char key, bool &skip, int counter[4])
{
	//hp, mode, player are passed by reference to manage turns and menu output.
	//MODE:        'C' = Mode options, 'A' = attack options,'I' = item options.
	skip = false; bool miss = false;
	string option1 = "option1", option2 = "option2",
		option3 = "option3", option4 = "option4", heading = "heading", name = name1,
		//To be used in attack mode.
		pkmn1 = "pikachu", pkmn2 = "torchic", pkmn = pkmn1;
	int pp1 = 0, pp2 = 0, pp3 = 0, pp4 = 0, dmg = 0;
	char s1 = 'B', s2 = 'F', // Pokemon orientation controllers.
		printM; // Print mode ( for different layouts).
//Determine pokemon for each player.
	switch (ch1)
	{
	case 1:
		pkmn1 = "pikachu";
		break;
	case 2:
		pkmn1 = "torchic";
		break;
	case 3:
		pkmn1 = "totodile";
		break;
	default:
		pkmn1 = "pikachu";
		break;
	}
	switch (ch2)
	{
	case 1:
		pkmn2 = "pikachu";
		break;
	case 2:
		pkmn2 = "torchic";
		break;
	case 3:
		pkmn2 = "totodile";
		break;
	default:
		pkmn2 = "torchic";
		break;
	}
	//Determine player variables:
	if (player == 2)
	{
		s1 = 'F'; s2 = 'B';
		name = name2;
		pkmn = pkmn2;
	}
	else
	{
		s1 = 'B'; s2 = 'F';
		name = name1;
		pkmn = pkmn1;
	}

	//Menu Modes:
	if (mode == 'C')
	{
		printM = 'C';
		if (key > '2')
		{
			heading = "Choose your action:";
			option1 = "Attack         "; option2 = "Use items";
			option3 = "               "; option4 = "";
		}
		else if (key == '1')
		{
			mode = 'A';
			key = '0';
		}
		else if (key == '2')
		{
			mode = 'I';
			key = '0';
		}
	}
	if (mode == 'I')
	{
		printM = 'I';
		heading = "Pick an item:";
		int temp = (key - '0') - 1; // use integer from key value to check for empty item.
		if ((key < '5' && key > '0') && item[player - 1][temp] == "EMPTY          ")
		{
			key = '0';
		}
		option1 = item[player - 1][0];	option2 = item[player - 1][1];
		option3 = item[player - 1][2];	option4 = item[player - 1][3];

		switch (key)
		{
		case '1':
			item[player - 1][0] = "EMPTY          ";
			dmg = 100;
			break;
		case '2':
			item[player - 1][1] = "EMPTY          ";
			dmg = 300;
			break;
		case '3':
			if (s1 == 'B')
			{
				ai[0][1] += 5;
				ai[1][1] += 15;
				ai[2][1] += 10;
				ai[3][1] += 20;
				counter[0] = 4;
			}
			else if (s2 == 'B')
			{
				ai[4][1] += 5;
				ai[5][1] += 15;
				ai[6][1] += 10;
				ai[7][1] += 20;
				counter[1] = 4;
			}
			item[player - 1][2] = "EMPTY          ";
			break;
		case '4':
			if (s1 == 'B')
			{
				ai[0][0] += 20;
				ai[1][0] += 20;
				ai[2][0] += 20;
				ai[3][0] += 20;
				counter[2] = 4;
			}
			else if (s2 == 'B')
			{
				ai[4][0] += 20;
				ai[5][0] += 20;
				ai[6][0] += 20;
				ai[7][0] += 20;
				counter[3] = 4;
			}
			item[player - 1][3] = "EMPTY          ";
			break;
		case '5':
			player = (player % 2) + 1; // Keep same player.
			break;
		default:
			mode = 'I';
			player = (player % 2) + 1; // Keep same player.
			skip = true;
			//DO NOTHING CASE
			break;
		}
		if (key != '0')
		{
			mode = 'C';
			key = '5';
		}
		skip = !skip;
		player = (player % 2) + 1; // Change turn.
		if (s1 == 'B')
		{
			if (hp1 + dmg <= 500)
			{
				hp1 += dmg;
			}
			else
				hp1 = 500;
		}
		else
		{
			if (hp2 + dmg <= 500)
			{
				hp2 += dmg;
			}
			else
				hp2 = 500;
		}
	}
	if (mode == 'A')
	{
		printM = 'A';
		heading = "Order an attack:";
		int kInt = (key - '0') - 1, // use integer from key value.
			row = 4 * (player - 1), // Decide which row set of array to use (first four for player 1).
			temp = kInt + row;
		if ((key < '5' && key > '0') && ai[temp][2] == 0)
		{
			key = '0';
		}

		if (pkmn == "pikachu")
		{
			option1 = "Quick Attack x"; option2 = "Slam         x";
			option3 = "Thunder Bolt x"; option4 = "Thunder      x";
		}
		else if (pkmn == "torchic")
		{
			option1 = "Aerial Ace   x"; option2 = "Slash        x";
			option3 = "Ember        x"; option4 = "Overheat     x";
		}
		else if (pkmn == "totodile")
		{
			option1 = "Chip Away    x"; option2 = "Water Gun    x";
			option3 = "Scratch      x"; option4 = "Blizzard     x";
		}
		int rnd = rand() % 100;


		switch (key)
		{
		case '1':
			//Attack1
			ai[temp][2]--; // -1 for pp.
			if (rnd < ai[temp][1])
			{
				dmg = ai[temp][0];
			}
			else
				miss = true;
			break;
		case '2':
			//Attack2
			ai[temp][2]--; // -1 for pp.
			if (rnd < ai[temp][1])
			{
				dmg = ai[temp][0];
			}
			else
				miss = true;
			break;
		case '3':
			//Attack3
			ai[temp][2]--; // -1 for pp.
			if (rnd < ai[temp][1])
			{
				dmg = ai[temp][0];
			}
			else
				miss = true;
			break;
		case '4':
			//Attack4
			ai[temp][2]--; // -1 for pp.
			if (rnd < ai[temp][1])
			{
				dmg = ai[temp][0];
			}
			else
				miss = true;
			break;
		case '5':
			player = (player % 2) + 1; // Keep same player.
			break;
		default:
			mode = 'A';
			player = (player % 2) + 1; // Keep same player.
			skip = true;
			//DO NOTHING CASE
			break;
		}
		if (key != '0')
		{
			mode = 'C';
			key = '5';
		}
		skip = !skip;
		player = (player % 2) + 1; // Change turn.
		pp1 = ai[0 + row][2];
		pp2 = ai[1 + row][2];
		pp3 = ai[2 + row][2];
		pp4 = ai[3 + row][2];
		if (s1 == 'B')
		{
			hp2 -= dmg;
			if (counter[0] != 0)
			{
				counter[0]--;
				if (counter[0] == 0)
				{
					ai[0][1] -= 5;
					ai[1][1] -= 15;
					ai[2][1] -= 10;
					ai[3][1] -= 20;
				}
			}
			if (counter[2] != 0)
			{
				counter[2]--;
				if (counter[2] == 0)
				{
					ai[0][0] -= 20;
					ai[1][0] -= 20;
					ai[2][0] -= 20;
					ai[3][0] -= 20;
				}
			}
		}
		else if (s2 == 'B')
		{
			hp1 -= dmg;
			if (counter[1] != 0)
			{
				counter[1]--;
				if (counter[1] == 0)
				{
					ai[4][1] -= 5;
					ai[5][1] -= 15;
					ai[6][1] -= 10;
					ai[7][1] -= 20;
				}
			}
			if (counter[3] != 0)
			{
				counter[3]--;
				if (counter[3] == 0)
				{
					ai[4][0] -= 20;
					ai[5][0] -= 20;
					ai[6][0] -= 20;
					ai[7][0] -= 20;
				}
			}
		}
		if (hp1 < 0)
			hp1 = 0;
		else if (hp2 < 0)
			hp2 = 0;
	}

	for (int i = 0; i < 17; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < 70; i++)
	{
		cout << " ";
	}
	cout << "HP: "; if (s1 == 'F') cout << hp1 << endl; else cout << hp2 << endl;
	for (int i = 0; i < 70; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		cout << "_";
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
		cout << "|";
		if (i == 0)
			cout << name << ":";
		else if (i == 1)
			cout << heading;
		// For Choice and item mode
		else if (i == 4 && printM != 'A')
		{
			cout << "   1)" << option1 << "\t2)" << option2;
		}
		else if (i == 8 && printM == 'I')
		{
			cout << "   3)" << option3 << "\t4)" << option4;
		}
		//For attack mode
		else if (i == 4 && printM == 'A')
		{
			cout << "   1)" << option1 << pp1 << "\t2)" << option2 << pp2;
		}
		else if (i == 8 && printM == 'A')
		{
			cout << "   3)" << option3 << pp3 << "\t4)" << option4 << pp4;
		}


		cout << endl;
	}
	cout << "\tHP: "; if (s1 == 'B') cout << hp1 << endl; else cout << hp2 << endl;
	if (miss == false)
	{
		if (mode == 'I')
			cout << "Which item will you use? (Press 5 to go back)";
		else if (mode == 'A')
			cout << "Order an attack: (Press 5 to go back)";
		else
			cout << "Choose your action: ";
	}
//Drawing pixels:
	switch (ch1) //Pokemon Printer (placed in a switch because a specific function needs to be called in each iteration of the loop)
	{
	case 1:
		Pikachu(s1);
		break;
	case 2:
		Torchic(s1);
		break;
	case 3:
		Totodile(s1);
		break;
	default:
		Pikachu(s1);
		break;
	}
	switch (ch2) // Pokemon Printer
	{
	case 1:
		Pikachu(s2);
		break;
	case 2:
		Torchic(s2);
		break;
	case 3:
		Totodile(s2);
		break;
	default:
		Torchic(s2);
		break;
	}

	int x1 = (3.0/5) * hp1, x2 = (3.0 / 5) * hp2;

	if (s1 == 'B' && hp1 > 0 && hp2 > 0)
	{
		Rect(100, 420, 100 + x1, 430, 0, 180, 0, 0, 180, 0); // HP bar P1
		Sleep(10);
		Rect(575, 260, 575 + x2, 270, 0, 180, 0, 0, 180, 0); // HP bar P2
		Sleep(10);
		Rect(100 + x1, 420, 400, 430, 0, 180, 0, 180, 0, 0); // damage bar P1
		Sleep(10);
		Rect(575 + x2, 260, 875, 270, 0, 180, 0, 180, 0, 0); // damage bar P2
	}/*
	if (s1 == 'B')
	{
		Rect(100, 420, 100 + x1, 430, 0, 180, 0, 0, 180, 0); // HP bar P1
		Sleep(10);
		x2 = (3.0 / 5) * (hp2 + dmg);
		Rect(575, 260, 575 + x2, 270, 0, 180, 0, 0, 180, 0); // HP bar P2
		Sleep(10);
		for (int i = 575 + x2; i > 575 + ((3.0 / 5) * hp2); i-= 2)
		{	
			Rect(i, 260, 875, 270, 0, 180, 0, 180, 0, 0); // damage bar P2
			Sleep(50);
		}
		Rect(100 + x1, 420, 400, 430, 0, 180, 0, 180, 0, 0); // damage bar P1
	}*/

	else if(s1 == 'F' && hp1 > 0 && hp2 > 0)
	{
		Rect(100, 420, 100 + x2, 430, 0, 180, 0, 0, 180, 0); // HP bar P2
		Sleep(10);
		Rect(575, 260, 575 + x1, 270, 0, 180, 0, 0, 180, 0); // HP bar P1
		Sleep(10);
		Rect(100 + x2, 420, 400, 430, 0, 180, 0, 180, 0, 0); // damage bar P2
		Sleep(10);
		Rect(575 + x1, 260, 875, 270, 0, 180, 0, 180, 0, 0); // damage bar P1
	}
	/*
	else if (s1 == 'F')
	{
		Rect(100, 420, 100 + x2, 430, 0, 180, 0, 0, 180, 0); // HP bar P2
		Sleep(10);
		x1 = (3.0 / 5) * (hp1 + dmg);
		Rect(575, 260, 575 + x1, 270, 0, 180, 0, 0, 180, 0); // HP bar P1
		Sleep(10);
		for (int i = 575 + x1; i > 575 + ((3.0 / 5) * hp1); i -= 2)
		{
			Rect(i, 260, 875, 270, 0, 180, 0, 180, 0, 0); // damage bar P1
			Sleep(50);
		}
		Rect(100 + x2, 420, 400, 430, 0, 180, 0, 180, 0, 0); // damage bar P2
	}*/

	if (miss == true)
	{
		cout << "Attack missed!"; _getch();
	}
}

int main()
{
	SetConsoleCtrlHandler(console_ctrl_handler, TRUE); //Event Handler for killing music task upon exit from CLOSE button.
	system("start /min sound.vbs"); // Start music vb script file (not using additional libraries)
	system("cls"); // Clear once to avoid startup printing errors.
	string name1 = "", name2 = "";
	int ch1 = 1, ch2 = 2, // Pokemon Choices
		ai[8][3] = { { 30,95,15 },{ 80,60,10 },{ 50,85,5 },{ 100,30,5 },{ 30,95,15 },{ 80,60,10 },{ 50,85,5 },{ 100,30,5 } },//Attack damage, accuracy, pp (power points / number of attacks)
		counter[4] = { 0,0,0,0 }; //accuracy++, damage++ counter for 4 moves - for p1 and p2.{a1,a2,d1,d2}
	string item[2][4] = { {"Potion      ","Hyper Potion","Accuracy++  ","Damage++    " },
						   {"Potion      ","Hyper Potion","Accuracy++  ","Damage++    " } }; // items for each player
//variables for menu 
	bool loop = true, skip = false;
	int player = 1;
	int hp1 = 500, hp2 = 500;
	char mode = 'C', key = '5';
//Game Instructions Screen

	cout << "\n\n\t\t\t\t\t" << "POKEMON BATTLE SIMULATOR" << endl << endl << "\t\t\t\t\t" << "      Insturctions:" << endl << endl
		<< "\tAfter entering player names, Player 1 is randomly choosen (first turn advantage)." << endl
		<< "\tTurns will switch whenever a player uses an attack or item." << endl
		<< "\tEach player gets 3 pokemon to choose from. There will be no type or pokemon choice advantage. :(" << endl
		<< "\tEach Pokemon has 4 moves of varying damage and accuracy. Attack with highest damage has lowest accuracy." << endl
		<< "\tThe status for menu mode and missed attacks will be shown at the bottom left. " << endl
		<< "\tPlayer name will be shown at the top left of the menu (right side of the screen)." << endl << endl
		<< "\tEach player gets 4 items and each item can be used once:" << endl
		<< "\t\tPotion restores 100 HP.\t\t\tHyper Potion restores 300 HP." << endl << endl
		<< "\t\tAccuracy++ will increase accuracy of all attacks for 4 successive attack turns." << endl
		<< "\t\tDamage++ will increase damage of all attacks for 4 successive attack turns." << endl
		<< "\n\n\t\tMake up your strategy wisely and you may become the true Pokemon Champion!" << endl << endl << endl << endl << endl
		<< "\t\t\tPress any key twice to confirm for both players. Good luck!";
	_getch(); _getch();
	system("cls");

//Player information screen
	cout << "Enter name of first player: "; cin >> name1;
	cout << "Enter name of second player: "; cin >> name2;
	srand(time(0)); // Randomly choosing which player will take first turn.
	if (rand() % 2 == 1)
	{
		string temp = name1;
		name1 = name2;
		name2 = temp;
	}

	cout << "\nPlayer 1 (left) will be " << name1 << endl;
	cout << "Player 2 (right) will be " << name2 << endl;
	cout << "\n\n1) Pikachu  2)Torchic  3)Totodile\n" << "Choose a pokemon, trainer " << name1 << ": ";
	do
	{
		cin >> ch1;
	} while (ch1 > 3 || ch1 < 1);
	cout << "\n\n1) Pikachu  2)Torchic  3)Totodile\n" << "Choose a pokemon, trainer " << name2 << ": ";
	do
	{
		cin >> ch2;
	} while (ch2 > 3 || ch2 < 1);
	system("cls");
	do
	{
		Menu(hp1, hp2, mode, player, name1, name2, ch1, ch2, ai, item, key, skip, counter);
		if (!skip)
		{
			do
			{
				key = _getch();
			} while (key > '5' || key < '1');
		}
		else
		{
			key = '5';
			if (player == 1)
			{
				if(counter[0] != 0)
				counter[0]++;
				if (counter[2] != 0)
				counter[2]++;
			}
			else
			{
				if (counter[1] != 0)
				counter[1]++;
				if (counter[3] != 0)
				counter[3]++;
			}
		}
		system("cls");
	} while (hp1 > 0 && hp2 > 0);
	if (hp1 == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t" << name2 << " is the true Pokemon champion!";

	}
	else
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t" << name1 << " is the true Pokemon champion!";
	}
	_getch();

	system("taskkill /im wscript.exe /F"); // Stop Music
	return 0;
}
