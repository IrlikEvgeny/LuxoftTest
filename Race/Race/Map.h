#include<iostream>

using namespace std;

class Map
{
private:
	
public:
	Map()
	{
	}
	char load(char** map)
	{
		for (int i = 0; i < 21; ++i) {
			for (int j = 0; j < 21; ++j) {
				map[i][0] = '|';
				map[i][19] = '|';
				map[i][j] = ' ';
			}
		}
		return **map;
	}
	char displaysTheMap(char** map)
	{
		for (int i = 0; i < 21; ++i) {
			for (int j = 0; j < 21; ++j) {
				cout << map[i][j];
				if (j >= 20) {
					cout << endl;
				}
			}
		}
		return **map;
	}
};