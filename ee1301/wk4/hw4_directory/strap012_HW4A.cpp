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

int main () {
    int score, A, B, C, D, F;
    A = B = C = D = F = 0;
    std::string garbage; //Everything except the number is unneeded garbage.
    fin.open("input_files/grades.txt");
    if (!fin.is_open() ) {
        std::cout << "File read failed!\n";
        return -1;
    }
    while (fin >> garbage >> garbage >> score) {
        getline(fin, garbage);      //Any decimals are not needed and will be culled
        if (score>90) {
            A++;
        } else if (score>80) {
            B++;
        } else if (score>70) {
            C++; //Nice.
        } else if (score>60) {
            D++; 
        } else {
            F++;
        }
    }
    std::cout << A << " A\n"
              << B << " B\n"
              << C << " C\n"
              << D << " D\n"
              << F << " F\n";
    fin.close();


    fout.open("output_files/statistics.csv");
    if (!fout.is_open()) {
        std::cout << "File write failed!";
        return -2;
    }
    fout << "Grade, NumStudents"
         << "\nA," << A
         << "\nB," << B
         << "\nC," << C
         << "\nD," << D
         << "\nF," << F;
    fout.close();
}