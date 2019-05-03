#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class houseData {
public:
    //id,value,bedrooms,bathrooms,sqft,yr_built,zipcode
    long int id = 0;
    int price = 0;
    int bedrooms = 0;
    int bathrooms = 0;
    int sqft = 0;
    int yr_built = 0;
    int zipcode = 0;
    houseData *nextZip = nullptr;
    void printShort();
    void printRecord();

    };

void ProcHeader(ifstream &file); 
houseData* ReadRecord(ifstream &file);
void DelRecord(houseData *record);

void printAllHousesByZip(houseData* head);

int main(int argc, char* argv[]) {
    // This line must be removed in your final 
    // program (see HINT 1).
    houseData* initHouseData[10];
    
    ifstream fin;
    if(argc > 1) {
        fin.open(argv[1]);  // Small file to test with
    } else {
        fin.open("./house-info-v4-short.csv");  // Small file to test with
        //fin.open("./house-info-v4.csv");  // Use this file for final
    }

    if(fin.is_open()) {
        ProcHeader(fin);  // Just dumps header

        int numRec = 0;
        while(!fin.eof()) {
            houseData* tempHouse = ReadRecord(fin);
            if(tempHouse != nullptr) {
                //tempHouse->printRecord();
                tempHouse->printShort();
                initHouseData[numRec] = tempHouse;  // DO NOT store data like this!
                numRec++;
            }
        }

        // The following is just to show how printAllHousesByZip() works
        // DO NOT use this method to organize your linked list!
        houseData* head = initHouseData[2];
        initHouseData[2]->nextZip = initHouseData[1];
        initHouseData[1]->nextZip = initHouseData[3];
        initHouseData[3]->nextZip = initHouseData[4];
        initHouseData[4]->nextZip = initHouseData[0];

        printAllHousesByZip(head);

        //This loop will also have to change in your 
        // final program (see HINT 1).
        for(int a = 0; a<numRec ; a++) {  
            DelRecord(initHouseData[a]);
        }

        fin.close();
        
    } else {
        cout << "File missing!" << endl;
        return 1;
    }

    return 0;
}

void ProcHeader(ifstream &file) {
    int endOfHeader = 0;
    char curChar;

    while(!endOfHeader) {
        curChar = file.get();

        if (curChar == '\n') {
            //End of line found
            endOfHeader = 1;
        }
    }
}

houseData* ReadRecord(ifstream &file) {
    int b = 0;
    int endOfHeader = 0;
    int c = 0;
    long int tempData[7] = {0};
    houseData* localHouseData = new houseData();
    string tempString = " ";

    while(!endOfHeader) {
        char curChar;
        
        //Get the next character in file
        curChar = file.get();
        
        //Check what the character is
        if (curChar == EOF) {
            return nullptr;
        } else if (curChar == '\n') {
            //Final symbol of row found: put in array and end loop
            tempString.append(1,'\0');
            tempData[c++] = stol(tempString);
            endOfHeader = 1;
        } else if (curChar == ',') {
            //End of current symbol found: put in array
            tempString.append(1,'\0');
            tempData[c++] = stol(tempString);
            tempString.clear();
        } else {
            // Append to array
            tempString.append(1,curChar);
            b++;
        }
    }

    localHouseData->id = tempData[0];
    localHouseData->price = tempData[1];
    localHouseData->bedrooms = tempData[2];
    localHouseData->bathrooms = tempData[3];
    localHouseData->sqft = tempData[4];
    localHouseData->yr_built = tempData[5];
    localHouseData->zipcode = tempData[6];

    return localHouseData;
}

void houseData::printRecord() {
    cout <<  "Printing House Record:" << endl;
    cout << "ID:" << id << endl;
    cout << "Price:" << price << endl;
    cout << "Bedrooms:" << bedrooms << endl;
    cout << "Bathrooms:" << bathrooms << endl;
    cout << "Square Feet:" << sqft << endl;
    cout << "Year Built:" << yr_built << endl;
    cout << "Zipcode:" << zipcode << endl;
}

void DelRecord(houseData *record) {
    delete record;
}

void houseData::printShort() {
    cout << id << "," << zipcode << endl;
}

void printAllHousesByZip(houseData* head){
    cout << endl << "Printing List of All Houses by Zip:" << endl;
    houseData* current = head;
    while(current != nullptr) {
        current->printShort();
        current = current->nextZip;
    }
}