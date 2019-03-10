/*
13 March 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 4A
Making the Grade
*/

#include <iostream>
#include <fstream>
std::ifstream fin;
std::ofstream fout;

int main()
{
    std::string Useless;
    char letter, garbage;
    int Count, hiCount=0;
    fin.open("output_files/statistics.csv");
    if (!fin.is_open()) {
        std::cout << "File read failed!\n";
        return -1;
    }
    fout.open("output_files/histogram.txt");
    if (!fout.is_open()) {
        std::cout << "File write failed!";
        return -2;
    }
    fin >> Useless >> Useless;
    while (fin >> letter >> garbage >> Count) {
        fout << " " << letter;
        if (Count>hiCount) {
            hiCount=Count;
        }
        for (int i=Count; i>0; i--) {
            fout << " X";
        }
        fout << std::endl;
    }
    fin.close();
    for (int h=0; h<=(hiCount+1); h++) {
        fout << "==";
    }
    fout << std::endl << "  ";
    for (int j=1; j<=hiCount; j++) {
        fout << " " << j;
    }
    fout.close();
}