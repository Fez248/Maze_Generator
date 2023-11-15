/*
Creator: Ferran Benéitez Borrut
Last Edit: 15/11/2023
I forgor: https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository
**/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Maze;

typedef vector<bool> Row2;
typedef vector<Row2> Maze2;

struct position
{
    int x;
    int y;
};

bool in_range(const int sx, const int sy, int x, int y)
{
    return x < sx and x > -1 and y < sy and y > -1;
}

bool prision(const Maze2& visited, const int sx, const int sy, int i, int j)
{
    bool r1, r2, r3, r4;
    if (in_range(sx, sy, i + 1, j))
    {
        if (visited[i + 1][j]) r1 = true;
        else r1 = false;
    }
    else r1 = true;
    if (in_range(sx, sy, i - 1, j))
    {
        if (visited[i - 1][j]) r2 = true;
        else r2 = false;
    }
    else r2 = true;
    if (in_range(sx, sy, i, j + 1))
    {
        if (visited[i][j + 1]) r3 = true;
        else r3 = false;
    }
    else r3 = true;
    if (in_range(sx, sy, i, j - 1))
    {
        if (visited[i][j - 1]) r4 = true;
        else r4 = false;
    }
    else r4 = true;
}

void gen_cami(Maze& map, const int sx, const int sy, position& start, position&exit)
{
    int length = rand() % (sx * sy / 2);
    int i, j;
    i = exit.x = sx - 1;
    j = exit.y = sy -1;
    Maze2 visited(sx, Row2(sy, false));
    visited[i][j] = true;
    pair<int, int> anterior = make_pair(i, j);

    while (length != 0)
    {
        int dir = rand() % 4;
        switch(dir)
        {
            case 0:
                if (in_range(sx, sy, i + 1, j) and !visited[i + 1][j])
                {
                    map[i + 1][j] = '.';
                    visited[i + 1][j] = true;
                    --length;
                    ++i;
                }
                break;
            case 1:
                if (in_range(sx, sy, i - 1, j) and !visited[i -1][j])
                {
                    map[i - 1][j] = '.';
                    visited[i -1][j] = true;
                    --length;
                    --i;
                }
                break;
            case 2:
                if (in_range(sx, sy, i, j + 1) and !visited[i][j + 1])
                {
                    map[i][j + 1] = '.';
                    visited[i][j + 1] = true;
                    --length;
                    ++j;
                }
                break;
            case 3:
                if (in_range(sx, sy, i, j - 1) and !visited[i][j - 1])
                {
                    map[i][j - 1] = '.';
                    visited[i][j -1] = true;
                    --length;
                    --j;
                }
                break;

            default:
                break;
        }
    }

    start.x = i;
    start.y = j;
    map[i][j] = 'S';
    map[exit.x][exit.y] = 'E';
}

//void gen_maze(Maze& map, const int sx, const int sy, position& start, position& exit)
//{

//}

int main ()
{
    int sx, sy;
    sx = sy = 20;
    int h = 0;

    while (h < 20)
    {
        srand(time(NULL) + h);
        Maze map(sx, Row(sy, 'X'));

        position start, exit;

        gen_cami(map, sx, sy, start, exit);

        for (int i = 0; i < sx; ++i)
        {
            for (int j = 0; j < sy; ++j)
            {
                cout << map[i][j];
            }
            cout << endl;
        }   

        cout << endl;
        cout << "____________________" << endl;
        ++h;
    }
}