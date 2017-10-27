#include<iostream>

using namespace std;

class Moves
{
private:
	char obstacle = 219; char car = 219;
public:
	Moves()
	{
	}
	char movesLeft(char** map, int x, int y)
	{
		map[y][x] = ' ';
		map[y][x + 1] = ' ';
		map[y][x - 1] = ' ';
		map[y + 1][x - 1] = ' ';
		map[y + 1][x + 1] = ' ';
		map[y - 1][x - 1] = ' ';
		map[y - 1][x + 1] = ' ';
		x -= 3;
		map[y][x] = car;
		map[y][x + 1] = car;
		map[y][x - 1] = car;
		map[y + 1][x - 1] = car;
		map[y + 1][x + 1] = car;
		map[y - 1][x - 1] = car;
		map[y - 1][x + 1] = car;
		return **map,x;
	}
	char movesRight(char** map, int x, int y)
	{
		map[y][x] = ' ';
		map[y][x + 1] = ' ';
		map[y][x - 1] = ' ';
		map[y + 1][x - 1] = ' ';
		map[y + 1][x + 1] = ' ';
		map[y - 1][x - 1] = ' ';
		map[y - 1][x + 1] = ' ';
		x += 3;
		map[y][x] = 'X';
		map[y][x + 1] = '|';
		map[y][x - 1] = '|';
		map[y + 1][x - 1] = 'o';
		map[y + 1][x + 1] = 'o';
		map[y - 1][x - 1] = 'o';
		map[y - 1][x + 1] = 'o';
		return **map,x;
	}
	int crash()
	{
		cout << "\n\nYou crashed!\n" << endl;
		cin.get();
		return 0;
	}
};