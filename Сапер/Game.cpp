#include "Game.h"

char** Game::Alocate_memory(int N, int M)
{
    char** A = new char* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new char[M];
    }
    return A;
}

void Game::fill(char** A, char c)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = c;
        }
    }
}

void Game::plant_bomb()
{
    char c = '*';
    for (int i = 0; i < millitary; i++)
    {
        int A = rand() % N;
        int B = rand() % M;
        if (field[A][B] != '*')
        {
            place_bomb(A, B);
        }
        else
        {
            i--;
        }
    }
}

void Game::place_bomb(int A, int B)
{
    field[A][B] = '*';
    for (int i = A-1; i < A+2 ; i++)
    {
        for (int j = B-1; j < B+2; j++)
        {
            if (i >= 0 && j >= 0 && i < N && j < M) {
                if (field[i][j] == '.')
                {
                    field[i][j] = '1';
                }
                else if (field[i][j] != '*')
                {
                    field[i][j]++;
                }
            }
        }
    }
}

void Game::show(char** A)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
    }
}

void Game::open_dot(int x, int y)
{
    if (x >= N || y >= M || x < 0 || y < 0)
    {
        return;
    }
    if (field[x][y] == '.')
    {
        if (display[x][y] != '.')
        {
            display[x][y] = '.';
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        continue;
                    }
                    open_dot(x + i, y + j);
                }
            }
        }
    }
    else
    {
        display[x][y] = field[x][y];
    }
}

status_game Game::get_status()
{
    return status;
}

int Game::get_plant_flag()
{
    return millitary - flag_bombs;
}

void Game::show_display()
{
    show(display);
}

void Game::show_field()
{
    show(field);
}

void Game::move(int x, int y)
{
    if (field[x][y] == '*')
    {
        status = status_game::lose;
    }
    else if (field[x][y] == '.')
    {
        open_dot(x, y);
    }
    else
    {
        display[x][y] = field[x][y];
    }
}
bool Game::flag(int x, int y)
{
    if (display[x][y] == 'f')
    {
        display[x][y] = field[x][y];
        flag_bombs--;
        if (field[x][y] == '*')
        {
            flag_bomb_correct--;
        }
        return true;
    }
    else if (display[x][y] == '#')
    {
        display[x][y] = 'f';
        flag_bombs++;
        if (field[x][y] == '*')
        {
            flag_bomb_correct++;
        }
        if (flag_bomb_correct == millitary)
        {
            status = status_game::win;
        }
        return true;
    }
    else
    {
        return false;
    }
}
