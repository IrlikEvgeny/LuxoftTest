#include<iostream>
#include <vector>

using namespace std;

class Map
{
public:
	void loadMap(vector<vector<char>>& map)
	{
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
			{
				map[i][j] = ' ';
				if (j==0||j==24)
				{
					map[i][j] = '|';
				}
			}
		}
	}
	void displaysTheMap(vector<vector<char>>& map)
	{
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
private:
};