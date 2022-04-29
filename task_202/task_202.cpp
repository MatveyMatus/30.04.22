#include <iostream>
#include <fstream>

int main()
{
    std::ifstream Values("input.txt");
    std::ofstream result("output.txt");

    std::string str, substr;
    Values >> str >> substr;

    Values.close();

    for (int i = 0; i < str.length(); ++i) {
        int temp = i;
        bool bFalg = true;
        for (int q = 0; q < substr.length(); ++q) {
            if (str[temp++] != substr[q]) {
                bFalg = false;
                break;
            }
        }
        if (bFalg) {
            result << i << " ";
        }
    }
    result.close();
}

