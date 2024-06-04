#include "Game.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выберите уровень сложности: 1 - easy, 2 - medium, 3 - hard" << endl;
	int i;
	cin >> i;
	level l = (level)(i - 1);
	Game game(l);
	game.show_display();
	//game.show_field();
	while (true)
	{
		int a;
		cout << "1. Сделать ход" << endl;
		cout << "2. Поставить флаг" << endl;
		cin >> a;
		cout << "Введите координаты" << endl;
		int x, y;
		cin >> x >> y;
		if (a == 1)
		{
			game.move(x, y);
			if (game.get_status() == status_game::play)
			{
				game.show_display();
			}
			else if (game.get_status() == status_game::win)
			{
				cout << "Поздравляю, вы выиграли игру" << endl;
				break;
			}
			else
			{
				cout << "К сожалению вы проиграли" << endl;
				break;
			}
		}
		else if (a == 2)
		{
			if (game.get_plant_flag() != 0)
			{
				if (game.flag(x, y) == true)
				{
					game.show_display();
					if (game.get_status() == status_game::win)
					{
						cout << "Поздравляю, вы выиграли игру" << endl;
						break;
					}
					else
					{
						cout << "Сюда нельзя поставить флаг" << endl;
					}
				}
			}
		}
		else
		{
			cout << "Incorrect data" << endl;
		}
	}
}