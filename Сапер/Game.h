#pragma once
#include <iostream>

using namespace std;

enum class level
{
	easy, medium, hard
};

enum class status_game
{
	win, lose, play
};
class Game
{
private:
	char** field;
	char** display;
	int millitary;
	int N;
	int M;
	status_game status;
	int flag_bombs;
	int flag_bomb_correct;
	char** Alocate_memory(int N, int M);
	void fill(char** A, char c);
	void plant_bomb();
	void place_bomb(int A, int B);
	void show(char** A);
	void open_dot(int x, int y);
public:
	Game(level A)
	{
		status = status_game::play;
		flag_bombs = 0;
		flag_bomb_correct = 0;
		if (A == level::easy)
		{
			N = 9;
			M = 9;
			millitary = 15;
		}
		else if (A == level::medium)
		{
			N = 10;
			M = 10;
			millitary = 20;
		}
		else if (A == level::hard)
		{
			N = 12;
			M = 12; 
			millitary = 30;
		}
		field = Alocate_memory(N, M);
		display = Alocate_memory(N, M);
		fill(field, '.');
		fill(display, '#');
		plant_bomb();
	}
	status_game get_status();
	int get_plant_flag();
	void show_display();
	void show_field();
	void move(int x, int y);
	bool flag(int x, int y);
};

