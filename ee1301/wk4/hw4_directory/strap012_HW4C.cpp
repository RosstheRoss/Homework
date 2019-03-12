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
    fout.open("output_files/election_results.txt");
    if (!fout.is_open())
    {
        std::cout << "File write failed!\n";
        return -2;
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
    //This bit compares to see which vowel wins.
    if (A>E && A>I && A>O && A>U)
        { winner = 'A'; }
    if (E > A && E > I && E > O && E > U)
        { winner = 'E'; }
    if (I > E && I > A && I > O && I > U)
        { winner = 'I'; }
    if (O > E && O > I && O > A && O > U)
        { winner = 'O'; }
    if (U > E && U > I && U > O && U > A)
        { winner = 'U'; }

    std::cout << "The results are in!" << std::endl
              << "A/a received " << A << " votes" << std::endl
              << "E/e received " << E << " votes" << std::endl
              << "I/i received " << I << " votes" << std::endl
              << "O/o received " << O << " votes" << std::endl
              << "U/u received " << U << " votes" << std::endl
              << "The winner is the letter \"" << winner
              << "\"!" << std::endl;

    fout << "A," << A << std::endl
         << "E," << E << std::endl
         << "I," << I << std::endl
         << "O," << O << std::endl
         << "U," << U;
    fout.close();
}