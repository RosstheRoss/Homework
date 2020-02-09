/*
Date: April 4 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE 1301
Term: Spring 2019
Lab/assignment number: HW 5B
Short Program Description: Random Array
*/

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
    max = atoi(argv[3]); //Maximum number in array
    
    //Loop to make the random array
    for (int curRow = 0; curRow < m; curRow++)
    {
        for (int curCol = 0; curCol < n; curCol++)
        {
            if (rand() % 2 + 1 == 2) { //Decide the sign of the number
                randArray[curCol][curRow] = -1 * (rand() % (max+1));
            } else {
                randArray[curCol][curRow] = (rand() % (max+1));
            }
        }
    }
    
    //Loop to output the array in the console
    for (int curRow = 0; curRow < m; curRow++)
    {
        for (int curCol = 0; curCol < n; curCol++)
        {
           cout << randArray[curCol][curRow] << " ";
        }
        cout << endl;
    }
}