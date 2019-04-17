//Matthew Strapp
//EE1301
//17 April 2019
//HW 6A: Dice Class
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int maxNumDie=50;

int* userInputParser(string s);

class Dice {
private:
  int min;
  int max;
public:
  int roll(int min, int max) {
    return rand() % (max-min+1) + min;
  };
  Dice() { //Default constructor for debugging purposes
      min=1;
      max=1;
  }
  Dice(int gotMin, int gotMax){
      min = gotMin;
      max = gotMax;
  };
};

int main() {
    int rounds;
    Dice die[maxNumDie];
    int roll[maxNumDie];
    int max=0, min=999999, sum=0, sample=0;
    double avg;
    srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
    cout << "What do you want to roll?  ";
    string s;
    getline(cin, s);
    cout << "How many rounds do you want to roll? ";
    cin >> rounds;
    int* pairs = userInputParser(s);

    // This will display the array of die information retrieved from user.
    // Replace the following code when you submit your solution.

    // pairs is an array with the following format:
    // {num_dice,
    //  first_die_start,
    //  first_die_end,
    //  second_die_start,
    //  ... }
    double numRolls=0;
    for (int j=0; j<rounds; j++) {
      int curRoll=0;
      numRolls+=1.0;
      for(int i=1; i < pairs[0]; i+=2) {
//        cout << "["<<pairs[i]<<","<<pairs[i+1] <<"]" << endl;
        die[i-1] = Dice(pairs[i], pairs[i + 1]);
        roll[i-1] = die[i-1].roll(pairs[i], pairs[i+1]);
        curRoll += roll[i-1];
      }
      
      if (curRoll > max) {
        max = curRoll;
      }
      if (curRoll < min) {
        min = curRoll;
      }
      sum+=curRoll;
  }
  avg = sum / numRolls;
  cout << "Sample roll: " << sample << endl
       << "Minimum roll: " << min << endl
       << "Maximum roll: " << max << endl
       << "Average roll: " << avg << endl;

}


int* userInputParser(string s) {
    static int dice[2*maxNumDie+1] = {0}; // array format:
    // {num_dice,
    //  first_die_start,
    //  first_die_end,
    //  second_die_start,
    //  ... }
    // max of maxNumDie dice supported

    string data[4*maxNumDie];  // Intermediate storage for parsing input string

    // count how many '+'s or 'd's there are...
    int parts = 0;
    for(unsigned int i=0; i < s.length(); i++)
    {
        if(s[i] == 'd' || s[i] == '+')
        {
            parts++;
        }
    }
    // ... so we know the number of times to decode values

    int index=0;
    unsigned d = s.find('d');
    unsigned p = s.find('+');
    while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1))
    {
        bool dFirst = d < p;
        if(dFirst)
        {
            string before = s.substr(0,d); // part before the 'd' (should be just one number)
            // figure out what number is after 'd'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-d-1); i++)
            {
                if(isdigit(s[count+d+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+d+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(d+1,count); //should be just the number after 'd'

            // store these two parts
            data[index] = before;
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(d+count+1); // discard these two parts
        }
        else // same idea for the '+'
        {
            // figure out what number is after '+'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-p-1); i++)
            {
                if(isdigit(s[count+p+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+p+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(p+1,count); //should be just the number after '+'

            // store this part
            data[index] = "+";
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(p+count+1); // discard these two parts
        }

        // update d and p for next loop interation
        d = s.find('d');
        p = s.find('+');

    }

    // now we need to figure out how many dice there are (as 2d4 is 2 dice)
    // we will treat "+2" as a die that rolls [2,2]
    int diceCount = 0;
    for(int i=0; i < parts*2; i+=2)
    {
        if(data[i][0] == '+')
        {
            diceCount++;
        }
        else
        {
            diceCount+=atoi(data[i].c_str());
        }
    }

    dice[0] = diceCount*2+1; // put size in first index

    int ind=1; // index for the "dice" array (as not same as data array)
    for(int i=0; i < parts*2; i+=2)
    {
        // if we have a +, add a "Dice" that has a range of 0
        if(data[i][0] == '+')
        {
            dice[ind] = atoi(data[i+1].c_str());
            dice[ind+1] = atoi(data[i+1].c_str());

            ind+=2;
        }
        else // otherwise add however many of the dice requested
        {
            for(int j=0; j < atoi(data[i].c_str()); j++)
            {
                dice[ind] = 1;
                dice[ind+1] = atoi(data[i+1].c_str());

                ind += 2;
            }
        }
    }

    return dice;
}
