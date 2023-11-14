#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//test
typedef vector<char> Row;
typedef vector<Row> Maze;

struct position
{
    int x;
    int y;
};

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

}