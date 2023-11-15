/*
Creator: Ferran Benéitez Borrut
Last Edit: 15/11/2023
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

bool prision(const Maze2& visited, const int sx, const int sy, int i, int j)
{
    int conected = 0;
    if (in_range(sx, sy, i + 1, j) and visited[i + 1][j]) ++conected;
    if (in_range(sx, sy, i - 1, j) and visited[i - 1][j]) ++conected;
    if (in_range(sx, sy, i, j + 1) and visited[i][j + 1]) ++conected;
    if (in_range(sx, sy, i, j - 1) and visited[i][j - 1]) ++conected;
    return conected;
}

void reset(std::vector<bool>& tried)
{
    for (int i = 0; i < 4; ++i) tried[i] = false;
}

void gen_cami(Maze& map, const int sx, const int sy, position& start, position&exit)
{
    Maze2 visited(sx, Row2(sy, false));
    int length = (sx * sy) / 2;
    int i, j;

    i = exit.x = sx - 1;
    j = exit.y = sy -1;
    visited[i][j] = true;

    std::vector<bool> tried(4, false);

    while (length != 0)
    {
        int dir = rand() % 4;
        while(tried[dir])
        {
            if (dir == 3) dir = 0;
            else ++dir;
        }

        switch(dir)
        {
            case 0:
                if (in_range(sx, sy, i + 1, j) and !visited[i + 1][j] and 2 > prision(visited, sx, sy, i + 1, j))
                {
                    std::cout << "d" << std::endl;
                    map[i + 1][j] = '.';
                    visited[i + 1][j] = true;
                    --length;
                    ++i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 1:
                if (in_range(sx, sy, i - 1, j) and !visited[i -1][j] and 2 > prision(visited, sx, sy, i - 1, j))
                {
                    std::cout << "i" << std::endl;
                    map[i - 1][j] = '.';
                    visited[i - 1][j] = true;
                    --length;
                    --i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 2:
                if (in_range(sx, sy, i, j + 1) and !visited[i][j + 1] and 2 > prision(visited, sx, sy, i, j + 1))
                {
                    std::cout << "a" << std::endl;
                    map[i][j + 1] = '.';
                    visited[i][j + 1] = true;
                    --length;
                    ++j;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 3:
                if (in_range(sx, sy, i, j - 1) and !visited[i][j - 1] and 2 > prision(visited, sx, sy, i, j - 1))
                {
                    std::cout << "ab" << std::endl;
                    map[i][j - 1] = '.';
                    visited[i][j -1] = true;
                    --length;
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

//void gen_maze(Maze& map, const int sx, const int sy, position& start, position& exit)
//{

//}

int main ()
{
    int sx, sy;
    sx = sy = 20;
    int h = 0;

    while (h < 1)
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