#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int size, prev, nex;
    int maxLen = 1, max1 = 1, max2;

    ifstream Values("input.txt");
    ofstream result("output.txt");
    Values >> size;

    if (size == 1) {
        cout << 1; return 0; 
    } 

    Values >> prev >> nex;

    size -= 2;
    int flag = nex - prev;
    if (flag != 0) max1++; 
    maxLen = max(maxLen, max1);
    max2 = maxLen;

    while (size > 0) {
        prev = nex;
        Values >> nex;
        if (nex - prev != 0) { 
            if (max1 == 1 && nex - prev != 0) {
                max1++; maxLen = max(maxLen, max1); 
            }
            if (flag * (nex - prev) < 0) {
                max1++;
                maxLen = max(maxLen, max1);
            }
            else max1 = max2;
        }
        else { 
            max1 = max2;
        }
        flag = nex- prev;
        size--;
    }

    Values.close();
    result << maxLen;
    result.close();

}