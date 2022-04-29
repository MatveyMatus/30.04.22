#include <iostream>
#include <fstream>
#include <cmath>
#include "random.h"

int main()
{
    RandomValue();

    int people, num;

    std::ifstream Values("input.txt");
    std::ofstream result("output.txt");
    Values >> people >> num;
    Values.close();

    if (num == 1) {
        std::cout << people;
        return 0;
    }
    else if (num == 2) {
        std::cout << 1;
        return 0;
    }

    int* players = new int[people] {};
    for (int i = 0; i < people; ++i) {
        players[i] = i+1;
    }
    bool bFlag = false;
    int motion = 0;
    int temp2 = 0;
    for (int i = 0; i < people+2; ++i) {
        int temp1 = people;
        players = winPlayer(players, people);
        for (int j = 0; j < people; ++j) {
            if (players[j] == num) {
                bFlag = true;
                motion++;
            }
        }
        if (people % 2 == 0) {
            people = floor(people / 2);
        }
        else {
            people = floor(people / 2)+1;
        }
        if (bFlag) {
            temp2 +=  temp1 - people;
            bFlag = false;
        }
    }
    result << temp2+1;
    result.close();
    
    delete[] players;
}