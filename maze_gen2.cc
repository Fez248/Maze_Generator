#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef std::vector<char> Row;
typedef std::vector<Row> Maze;

struct position
{
    int i;
    int j;
};

bool in_range(const int sx, const int sy, const position& pos)
{
    return pos.j < sx and pos.j > -1 and  < sy and y > -1;
}


void gen_cami(Maze& map, const int sx, const int sy, position& start, const position& pos, int dir)
{
    if (!in_range(sx, sy, ))
}

void gen_maze(Maze& map, const int sx, const int sy, position& start, position&exit)
{
    exit.i = rand() % sy;
    exit.j = rand() % sx;
    map[i][j] = '.';

    //need to declare dir
    gen_cami(map, sx, sy, start, exit, dir);

    map[exit.i][exit.j] = 'E';
    map[start.i][start.j] = 'S';
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
        int jan = 0;

        for (int i = 0; i < 10; ++i) 
        {
            srand(time(NULL) + h + i + jan);
            gen_maze(map, sx, sy, start, exit);
            jan = 50 + jan;
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