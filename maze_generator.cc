/*
Creator: Ferran Benéitez Borrut
Last Edit: 16/11/2023
I forgor: https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository
**/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef std::vector<char> Row;
typedef std::vector<Row> Maze;

typedef std::vector<bool> Row2;
typedef std::vector<Row2> Maze2;

struct position
{
    int x;
    int y;
};

bool in_range(const int sx, const int sy, int x, int y)
{
    return x < sx and x > -1 and y < sy and y > -1;
}

bool prision(const Maze& map, const int sx, const int sy, int i, int j)
{
    int invalid = 0;
    if (in_range(sx, sy, i + 1, j) and map[i + 1][j] == '.') invalid = invalid - 1;
    if (in_range(sx, sy, i - 1, j) and map[i - 1][j] == '.') invalid = invalid - 1;
    if (in_range(sx, sy, i, j + 1) and map[i][j + 1] == '.') invalid = invalid - 1;
    if (in_range(sx, sy, i, j - 1) and map[i][j - 1] == '.') invalid = invalid - 1;
    return invalid < -1;
}

void reset(std::vector<bool>& tried)
{
    for (int i = 0; i < 4; ++i) tried[i] = false;
}

void gen_cami(Maze& map, const int sx, const int sy, position& start, position&exit)
{
    Maze2 visited(sx, Row2(sy, false));
    int i, j, max;

    max = (sx * sy) / 4;
    i = exit.x = sx - 1;
    j = exit.y = sy -1;
    map[i][j] = '.';
    visited[i][j] = true;
    int fuck = 0;
    std::vector<bool> tried(4, false);

    while (fuck != 4 and max != 0)
    {
        int dir = rand() % 4;
        while(tried[dir] and fuck < 4)
        {
            if (dir == 3) dir = 0;
            else ++dir;
            ++fuck;
        }
        if (fuck != 4) fuck = 0;

        switch(dir)
        {
            case 0:
                if (in_range(sx, sy, i + 1, j) and !visited[i + 1][j] and !prision(map, sx, sy, i + 1, j)) //abajo
                {
                    map[i + 1][j] = '.';
                    visited[i + 1][j] = true;
                    --max;
                    ++i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 1:
                if (in_range(sx, sy, i - 1, j) and !visited[i -1][j] and !prision(map, sx, sy, i - 1, j)) //arriba
                {
                    map[i - 1][j] = '.';
                    visited[i - 1][j] = true;
                    --max;
                    --i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 2:
                if (in_range(sx, sy, i, j + 1) and !visited[i][j + 1] and !prision(map, sx, sy, i, j + 1)) //derecha
                {;
                    map[i][j + 1] = '.';
                    visited[i][j + 1] = true;
                    --max;
                    ++j;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 3:
                if (in_range(sx, sy, i, j - 1) and !visited[i][j - 1] and !prision(map, sx, sy, i, j - 1)) //izquierda
                {
                    map[i][j - 1] = '.';
                    visited[i][j -1] = true;
                    --max;
                    --j;
                    reset(tried);
                }
                else tried[dir] = true;
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

int main ()
{
    int sx, sy;
    sx = sy = 10;
    int h = 0;

    while (h < 10)
    {
        srand(time(NULL) + h);
        Maze map(sx, Row(sy, 'X'));

        position start, exit;

        gen_cami(map, sx, sy, start, exit);

        for (int i = 0; i < sx; ++i)
        {
            for (int j = 0; j < sy; ++j)
            {
                std::cout << map[i][j];
            }
            std::cout << std::endl;
        }   

        std::cout << std::endl;
        std::cout << "____________________" << std::endl;
        ++h;
    }
}