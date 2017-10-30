#include<iostream>
#include <vector>

using namespace std;

class Obstacle
{
public:
	void generatesTheObstacles(vector<vector<char>>& map)
	{
		if (a > 20)
		{
			a = 0;
			b = rand() % 20 + 2;
		}
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
		deleteTheObstacles(map);
	}
private:
	char obstacle = 219;
	int a = 1;
	int b = rand() % 20 + 2;
	void deleteTheObstacles(vector<vector<char>>& map)
	{
		if (a == 21){
			map[a + 1][b + 1] = ' ';
			map[a + 1][b + 2] = ' ';
			map[a + 1][b] = ' ';
			map[a + 2][b] = ' ';
			map[a + 2][b + 2] = ' ';
			map[a][b] = ' ';
			map[a][b + 2] = ' ';
		}
	}
};