#include<iostream>

using namespace std;

class Map
{
private:
	char map[25][25];
public:
	Map()
	{
	}
	void load()
	{
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 20; ++j) {
				map[i][0] = '|';
				map[i][18] = '|';
				map[i][j] = ' ';
			}
		}
	}

};