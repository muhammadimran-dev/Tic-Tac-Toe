#include <iostream>
using namespace std;
void diplayGameBoard(char gameBoard[][3])
{
	system("cls");
	for (int i = 0; i < 3; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			if (gameBoard[i][j] == 'A' || gameBoard[i][j] == 'B')
				cout << gameBoard[i][j];
			else
				cout << (int)(gameBoard[i][j] - '0');
			cout << "\t";
		}
		cout << "\n";
	}

}
void inputUserA(char gameBoard[][3])
{
	int location;
	cin >> location;
	while (gameBoard[location / 3][location % 3] == 'A' || gameBoard[location / 3][location % 3] == 'B')
	{
		cout << "\nEnter again, location is already occupied : ";
		cin >> location;
	}
	gameBoard[location / 3][location % 3] = 'A';
}
void inputUserB(char gameBoard[][3])
{
	int location;
	cin >> location;
	while (gameBoard[location / 3][location % 3] == 'A' || gameBoard[location / 3][location % 3] == 'B')
	{
		cout << "\nEnter again, location is already occupied : ";
		cin >> location;
	}
	gameBoard[location / 3][location % 3] = 'B';
}
bool isAWinner(char gameBoard[][3])
{
	bool flag1 = false, flag2 = false, flag3 = false;
	int i = 0;
	while (i < 3 && flag1 == false)
	{
		int j = 0;
		flag1 = true;
		while (j < 3 && flag1)
		{
			if (gameBoard[i][j] == 'A')
				flag1 = true;
			else
				flag1 = false;
			j = j + 1;
		}
		i = i + 1;
	}
	int k = 0;
	while (k < 3 && flag1 == false)
	{
		int j = 0;
		flag1 = true;
		while (j < 3 && flag1)
		{
			if (gameBoard[j][k] == 'A')
				flag1 = true;
			else
				flag1 = false;
			j = j + 1;
		}
		k = k + 1;
	}
	if ((gameBoard[0][0] == 'A' && gameBoard[1][1] == 'A' && gameBoard[2][2] == 'A') || (gameBoard[0][2] == 'A' && gameBoard[1][1] == 'A' && gameBoard[2][0] == 'A'))
		flag3 = true;
	if (flag1 || flag2 || flag3)
		return true;
	else
		return false;

}
bool isBWinner(char gameBoard[][3])
{
	bool flag1 = false, flag2 = false, flag3 = false;
	int i = 0;
	while (i < 3 && flag1 == false)
	{
		int j = 0;
		flag1 = true;
		while (j < 3 && flag1)
		{
			if (gameBoard[i][j] == 'B')
				flag1 = true;
			else
				flag1 = false;
			j = j + 1;
		}
		i = i + 1;
	}
	int k = 0;
	while (k < 3 && flag1 == false)
	{
		int j = 0;
		flag1 = true;
		while (j < 3 && flag1)
		{
			if (gameBoard[j][k] == 'B')
				flag1 = true;
			else
				flag1 = false;
			j = j + 1;
		}
		k = k + 1;
	}
	if ((gameBoard[0][0] == 'B' && gameBoard[1][1] == 'B' && gameBoard[2][2] == 'B') || (gameBoard[0][2] == 'B' && gameBoard[1][1] == 'B' && gameBoard[2][0] == 'B'))
		flag3 = true;
	if (flag1 || flag2 || flag3)
		return true;
	else
		return false;

}
void ticTacToe()
{
	char gameBoard[3][3] = { '0','1','2','3','4','5','6','7','8' };
	int counter = 0;
	while (counter < 5)
	{
		diplayGameBoard(gameBoard);
		cout << "\nUser A, Enter location number : ";
		inputUserA(gameBoard);
		if (isAWinner(gameBoard))
		{
			diplayGameBoard(gameBoard);
			cout << "\nUser A is Winner!\n";
			exit(0);
		}
		if (counter != 4)
		{
			diplayGameBoard(gameBoard);
			cout << "\nUser B, Enter location number : ";
			inputUserB(gameBoard);
			if (isBWinner(gameBoard))
			{
				diplayGameBoard(gameBoard);
				cout << "\nUser B is Winner!\n";
				exit(0);
			}

		}
		counter = counter + 1;
	}
	if (counter == 5)
		cout << "Game Tie...";

}