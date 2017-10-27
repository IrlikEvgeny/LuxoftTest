#include<iostream>

using namespace std;

class Obstacle
{
private:
	char obstacle = 219;
public:
	Obstacle()
	{
	}
	char generatesTheObstacles1(char** map, int a, int b)
	{
		map[a + 1][b + 1] = ' ';
		map[a + 1][b + 1] = ' ';
		map[a + 1][b + 2] = ' ';
		map[a + 1][b] = ' ';
		map[a + 2][b] = ' ';
		map[a + 2][b + 2] = ' ';
		map[a][b] = ' ';
		map[a][b + 2] = ' ';
		++a;
		map[a + 1][b + 1] = obstacle;
		map[a + 1][b + 2] = obstacle;
		map[a + 1][b] = obstacle;
		map[a + 2][b] = obstacle;
		map[a + 2][b + 2] = obstacle;
		map[a][b] = obstacle;
		map[a][b + 2] = obstacle;
		return **map,a;
	}
	char generatesTheObstacles2(char** map, int a, int b)
	{
		map[a][b] = obstacle;
		map[a][b + 1] = obstacle;
		map[a][b - 1] = obstacle;
		map[a + 1][b - 1] = obstacle;
		map[a + 1][b + 1] = obstacle;
		map[a - 1][b - 1] = obstacle;
		map[a - 1][b + 1] = obstacle;
		return **map;
	}
	char getObstacle()
	{
		return obstacle;
	}
};