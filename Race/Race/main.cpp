#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <ctime>
#include "Map.h"
#include "Car.h"
#include "Obstacle.h"
#include "Moves.h"
using namespace std;

void clearscreen();

int main(int argc, char*argv[])
{
	
	Map maps;
	Car cars;
	Obstacle obstacles;
	Moves moves;
	char** map;
	map = new char*[25];
	for (int i = 0; i < 25; i++)
	{
		map[i] = new char[25];
	}
	**map = maps.load(map);
	
	int ggg = 0;
	int st = 0;
	int start = 0;
	int stop=0;
	int metrs = 0;
	bool pause = true;
	int y = 17, x = 9; //the cars coordinates
	srand(time(0));
	int a = 1, b = rand() % 15 + 2; //the obstacles coordiantes
	int points = 0; //points that the player has earned
	int speed = 100; //determines the speed of the obstacles (and the car)
	bool startup = true;

	int end = 0;
	//char car Centre;
	**map = cars.carCentreLocation(map, x, y);
	//the game loop
	for (;;) {
		start = clock();
		++metrs;
		clearscreen();
		//places the car at its default location
		**map = cars.defaultLocation(map, x, y);
		
		//generates the obstacles
		**map,a=obstacles.generatesTheObstacles1(map, a, b);
		if (a > 20)
		{
			a = 0;
			b = rand() % 15 + 2;
		}
		//displays the map
		maps.displaysTheMap(map);
		end = clock();
		
		cout << "    metrs: " << metrs<<"|";
		cout << "    sec: " << (start-stop) / CLOCKS_PER_SEC<<"|";
		cout << "    speed: " << 200-speed<<"|";
		//does so the game starts after a key is pressed
		if (startup) 
		{
			_getch();
			startup = false;
		}
		//moves the car to the left
		if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y][x - 3] == obstacles.getObstacle()) 
			{
				return moves.crash();
			}
			else if (map[y][x - 3] != '|') {
				**map,x = moves.movesLeft(map, x, y);
			}
		}
		//moves the car to the right
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y][x + 4] == obstacles.getObstacle()) 
			{
				return moves.crash();
			}
			else if (map[y][x + 4] != '|') {
				**map, x = moves.movesRight(map, x, y);
			}
		}
		//checks if the car crashed
		if (map[y - 2][x] == obstacles.getObstacle() || map[y - 2][x - 1] == obstacles.getObstacle() || map[y - 2][x + 1] == obstacles.getObstacle()) 
		{

			return moves.crash();
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (speed >= 20){
				speed -= 20;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (speed <= 180){
				speed += 20;
			}
		}
		if (GetAsyncKeyState(13))
		{
			st = start;
			end = 0;
			end = clock();
			for (;;){
				Sleep(100);
				if (GetAsyncKeyState(13)){
					stop = end;
					break;
				}
			}
		}
		if (GetAsyncKeyState(27))
		{
			break;
		}
		Sleep(speed);
	}
//system("pause");
return 0;
}
void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
