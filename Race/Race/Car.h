#include<iostream>

using namespace std;

class Car
{
private:
	char car = 219;
public:
	Car()
	{
	}
	char carCentreLocation(char** map, int x, int y)
	{
		map[y][x] = car;
		return **map;
	}
	char defaultLocation(char** map,int x,int y)
	{
		map[y][x] = car;
		map[y][x + 1] = car;
		map[y][x - 1] = car;
		map[y + 1][x - 1] = car;
		map[y + 1][x + 1] = car;
		map[y - 1][x - 1] = car;
		map[y - 1][x + 1] = car;
		return **map;
	}
};