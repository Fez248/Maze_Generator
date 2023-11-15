#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//test
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

    return 
}

void gen_cami(Maze& map, const int sx, const int sy, position& start, position&exit)
{
    int lx = exit.x - start.x;
    int ly = exit.y - start.y;
    while(lx != 0 or ly != 0)
    {
        map[start.x][start.y] = '.';

    }
}

void gen_maze(Maze& map, const int sx, const int sy, position& start, position& exit)
{
    srand(time(NULL));
}

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