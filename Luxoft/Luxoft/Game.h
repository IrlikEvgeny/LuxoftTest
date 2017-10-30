#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Map.h"
#include "Obstacle.h"
#include "Car.h"

using namespace std;

class Game
{
public:
	void startGame()
	{
		map.resize(25);
		for (int i = 0; i < map.size(); i++)
		{
			map[i].resize(25);
		}
		maps.loadMap(map);
		car.carCentreLocation(map);
		do
		{
			cout<<"Speed:" <<200-speed<<"|";
			cout << "Metrs:" << metrs << "|";
			++metrs;
			clearscreen();
			maps.displaysTheMap(map);
			obstacle.generatesTheObstacles(map);
			car.defaultLocation(map);
			if (GetAsyncKeyState(VK_LEFT)) 
			{
				loop=car.movesLeft(map);
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				loop=car.movesRight(map);
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (speed > speedChange)
				{
					speed -= speedChange;
				}
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (speed < speedChange*19)
				{
					speed += speedChange;
				}
			}
			if (GetAsyncKeyState(13))
			{
				for (;;){
					Sleep(100);
					if (GetAsyncKeyState(13)){
						break;
					}
				}
			}
			if (GetAsyncKeyState(27))
			{
				break;
			}
			loop=car.breakUpCar(map);
			Sleep(speed);
		} while (loop);
		cout<< endl;
		cout << "Game over" << endl;
	}
private:
	vector<vector<char>> map;
	Map maps;
	Obstacle obstacle;
	Car car;
	bool loop=true;
	int speed = 100;
	int speedChange = 10;
	int metrs = 0;
	void clearscreen()
	{
		HANDLE hOut;
		COORD Position;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	} 
};