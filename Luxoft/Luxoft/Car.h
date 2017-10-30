#include<iostream>
#include <vector>

using namespace std;

class Car
{
public:
	void carCentreLocation(vector<vector<char>>& map)
	{
		map[carX][carY] = car;
	}
	void defaultLocation(vector<vector<char>>& map)
	{
		map[carX][carY] = car;
		map[carX][carY + 1] = car;
		map[carX][carY - 1] = car;
		map[carX + 1][carY - 1] = car;
		map[carX + 1][carY + 1] = car;
		map[carX - 1][carY - 1] = car;
		map[carX - 1][carY + 1] = car;
	}
	bool movesLeft(vector<vector<char>>& map)
	{
		if (map[carX][carY - 3] == obstacle)
		{
			return 0;
		}
		else if (map[carX][carY - 3] != '|') {
			map[carX][carY] = ' ';
			map[carX][carY + 1] = ' ';
			map[carX][carY - 1] = ' ';
			map[carX + 1][carY - 1] = ' ';
			map[carX + 1][carY + 1] = ' ';
			map[carX - 1][carY - 1] = ' ';
			map[carX - 1][carY + 1] = ' ';
			carY -= 3;
			map[carX][carY] = car;
			map[carX][carY + 1] = car;
			map[carX][carY - 1] = car;
			map[carX + 1][carY - 1] = car;
			map[carX + 1][carY + 1] = car;
			map[carX - 1][carY - 1] = car;
			map[carX - 1][carY + 1] = car;
			return 1;
		}
	}
	bool movesRight(vector<vector<char>>& map)
	{
		if (map[carX][carY + 3] == obstacle)
		{
			return 0;
		}
		else if (map[carX][carY + 3] != '|') {
			map[carX][carY] = ' ';
			map[carX][carY + 1] = ' ';
			map[carX][carY - 1] = ' ';
			map[carX + 1][carY - 1] = ' ';
			map[carX + 1][carY + 1] = ' ';
			map[carX - 1][carY - 1] = ' ';
			map[carX - 1][carY + 1] = ' ';
			carY += 3;
			map[carX][carY] = car;
			map[carX][carY + 1] = car;
			map[carX][carY - 1] = car;
			map[carX + 1][carY - 1] = car;
			map[carX + 1][carY + 1] = car;
			map[carX - 1][carY - 1] = car;
			map[carX - 1][carY + 1] = car;
			return 1;
		}
	}
	bool breakUpCar(vector<vector<char>>& map){
		if (map[carX - 2][carY] == obstacle || map[carX - 2][carY - 1] == obstacle || map[carX - 2][carY + 1] == obstacle)
		{

			return 0;
		}
		return 1;
	}
private:
	char car = 219;
	char obstacle = 219;
	int carX = 21;
	int carY = 12;
};