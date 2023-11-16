#include <iostream>
#include <chrono>
#include <thread>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
    std::cout << getpid() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    int i = 0;
    while(i < 11)
    {
        system("clear");
        std::cout << i << std::endl;
        if (i == 10) i = 0;
        else ++i;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}