#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4) {
        cout << "Invalid input!" << endl << "   USAGE: ./rand-array m n max" << endl;
        return 2;
    }
    srand(time(NULL));
    int m, n, max;
    m = atoi(argv[1]); //number of rows
    n = atoi(argv[2]); //number of columns
    int randArray[m][n];
    max = atoi(argv[3]); //Maximum number
    for (int curRow = 0; curRow < m; curRow++)
    {
        for (int curCol = 0; curCol < n; curCol++)
        { 
            if (rand() % 2 == 1) {
                randArray[curRow][curCol] = -1 * (rand() % max);
            } else {
                randArray[curRow][curCol] = (rand() % max);
            }
        }
    }

    cout << endl;
}