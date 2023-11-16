/*
Creator: Ferran Benéitez Borrut
Last Edit: 16/11/2023
I forgor: https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository

Solved problem:

Works for small mazes, with dimensions of 50 x 50 it starts to crete relative small paths due
to the fact that it traps himself. Hovewer, the idea, is to run the same algorithm x times on the same map
and take the largest path formed as the solution. All the other ones remaining will be dead ends that make the maze
more difficult. The problem I have to face know is making the algorithm able to cross other paths perpendiculary,
what I mean by that is making sure it doesn't creatre any area bigger than 1 x 1.

The code still needs a lot of work.

Idea: Last path can overrite other paths, E and S
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

void directions(int& dir, int& stucked, const std::vector<bool>& tried)
{
    dir = rand() % 4;
    while(tried[dir] and stucked < 4)
    {
        if (dir == 3) dir = 0;
        else ++dir;
        ++stucked;
    }
    if (stucked != 4) stucked = 0;
}

bool in_range(const int sx, const int sy, int x, int y)
{
    return x < sx and x > -1 and y < sy and y > -1;
}

bool prision(const Maze& map, const int sx, const int sy, int i, int j)
{
    int invalid = 0;
    if (in_range(sx, sy, i + 1, j) and (map[i + 1][j] == '.' or map[i + 1][j] == 'S' or map[i + 1][j] == 'E')) invalid = invalid - 1;
    if (in_range(sx, sy, i - 1, j) and (map[i - 1][j] == '.' or map[i - 1][j] == 'S' or map[i - 1][j] == 'E')) invalid = invalid - 1;
    if (in_range(sx, sy, i, j + 1) and (map[i][j + 1] == '.' or map[i][j + 1] == 'S' or map[i][j + 1] == 'E')) invalid = invalid - 1;
    if (in_range(sx, sy, i, j - 1) and (map[i][j - 1] == '.' or map[i][j - 1] == 'S' or map[i][j - 1] == 'E')) invalid = invalid - 1;
    return invalid < -1;
}

void reset(std::vector<bool>& tried)
{
    for (int i = 0; i < 4; ++i) tried[i] = false;
}

void gen_cami(Maze& map, const int sx, const int sy, position& start, position& exit, int rosell)
{
    std::vector<bool> tried(4, false);                                                  //Tried directions to know when is trapped

    int i, j, max, stucked, dir;
    i = exit.x = rand() % sx;                                                           //We start from the exit
    j = exit.y = rand() % sy;
    max = (sx * sy) / 4;                                                                //Maz lenght that the pace can take
    stucked = 0;

    while(map[i][j] == 'E' or map[i][j] == 'S')
    {
        i = exit.x = rand() % sx;                                                       //We start from the exit
        j = exit.y = rand() % sy;
    }
    map[i][j] = '.';                                                                    //This coordinate with later get replaced by E but it's initialized as . for prision()

    while (stucked != 4 and max != 0)
    {
        directions(dir, stucked, tried);
        switch(dir)
        {
            case 0:
                if (in_range(sx, sy, i + 1, j) and map[i + 1][j] != '.' and !prision(map, sx, sy, i + 1, j)) //abajo
                {
                    map[i + 1][j] = '.';
                    --max;
                    ++i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 1:
                if (in_range(sx, sy, i - 1, j) and map[i -1][j] != '.' and !prision(map, sx, sy, i - 1, j)) //arriba
                {
                    map[i - 1][j] = '.';
                    --max;
                    --i;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 2:
                if (in_range(sx, sy, i, j + 1) and map[i][j + 1] != '.' and !prision(map, sx, sy, i, j + 1)) //derecha
                {;
                    map[i][j + 1] = '.';
                    --max;
                    ++j;
                    reset(tried);
                }
                else tried[dir] = true;
                break;
            case 3:
                if (in_range(sx, sy, i, j - 1) and map[i][j - 1] != '.' and !prision(map, sx, sy, i, j - 1)) //izquierda
                {
                    map[i][j - 1] = '.';
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
    if (rosell == 1)
    {
        map[i][j] = 'S';
        map[exit.x][exit.y] = 'E';
    }
    else
    {
        map[i][j] = '.';
        map[exit.x][exit.y] = '.';
    }
}

int main ()
{
    int sx, sy;
    sx = sy = 10;
    int h = 0;

    while (h < 1)
    {
        Maze map(sx, Row(sy, 'X'));

        position start, exit;
        int jan = 0;

        srand(time(NULL) + h + jan);
        gen_cami(map, sx, sy, start, exit, 1);
        for (int i = 0; i < 4; ++i) 
        {
            srand(time(NULL) + h + i + jan);
            gen_cami(map, sx, sy, start, exit, 0);
            jan = jan + 50;
        }

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