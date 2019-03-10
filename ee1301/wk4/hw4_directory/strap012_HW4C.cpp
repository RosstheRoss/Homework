/*
13 March 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 4C
Most Popular Vowel
*/

#include <iostream>
#include <fstream>
std::ifstream fin;
std::ofstream fout;

int main()
{
    char Char, winner;
    int A=0, E=0, I=0, O=0, U=0;
    fin.open("input_files/blahblah.txt");
    if (!fin.is_open()) {
        std::cout << "File read failed!\n";
        return -1;
    }
    while (fin >> Char) {
        if (Char=='A' || Char=='a') {
            A++;
        } if (Char=='E' || Char=='e') {
            E++;
        } if (Char=='I' || Char=='i') {
            I++;
        } if (Char=='O' || Char=='o') {
            O++;
        } if (Char=='U' || Char=='u') {
            U++;
        }
    } fin.close();
    if (A>E && A>I && A>O && A>U)
        winner = 'A';
    if (E > A && E > I && E > O && E > U)
        winner = 'E';
    if (I > E && I > A && I > O && I > U)
        winner = 'I';
    if (O > E && O > I && O > A && O > U)
        winner = 'O';
    if (U > E && U > I && U > O && U > A)
        winner = 'U';

    std::cout << "The results are in!\n"
              << "A/a received " << A << " votes\n"
              << "E/e received " << E << " votes\n"
              << "I/i received " << I << " votes\n"
              << "O/o received " << O << " votes\n"
              << "U/u received " << U << " votes\n"
              << "The winner is the letter \"" << winner
              << "\"!\n";


    fout.open("output_files/election_results.txt");
    if (!fout.is_open()) {
        std::cout << "File write failed!\n";
        return -2;
    }
    fout << "A," << A
         << "\nE," << E
         << "\nI," << I
         << "\nO," << O
         << "\nU," << U;
    fout.close();
}