//Matthew Strapp
//EE1301
//HW7A: The house database
//8 May 2019


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
houseData* Scanlist(houseData* head, int Zipcode);
void DelRecord(houseData *record);
void bsort(int list[], int length);
void swap (int &a, int &b);
void printAllHousesByZip(houseData* head);

int main(int argc, char* argv[]) {
    houseData* head = nullptr;
    houseData* tail = nullptr;

    ifstream fin;
    if(argc > 1) {
        fin.open(argv[1]);  // Small file to test with
    } else {
        //fin.open("./house-info-v4-short.csv");  // Small file to test with
        fin.open("./house-info-v4.csv");  // Use this file for final
    }

    if(fin.is_open()) {
        ProcHeader(fin);  // Just dumps header

        int numRec = 0;
        while(!fin.eof()) {
            houseData* tempHouse = ReadRecord(fin);
            if(tempHouse != nullptr) {
                if (head == nullptr) { //Make head of list if one does not exist
                  head=tempHouse;
                  tail=tempHouse;
                  tempHouse=nullptr;
                } else {
                  tail->nextZip=tempHouse;
                  tail=tempHouse;
                }
                //tempHouse->printRecord();
                //tempHouse->printShort();
                //initHouseData[numRec] = tempHouse;  // DO NOT store data like this!
                numRec++;
                if (numRec%1000==0 && numRec!=0) {
                  cout << "Still working...num records processed: " << numRec << endl;
                }
            }
        }


        houseData* currentZipFind = head;
          int zipSort[10000]; bool newZip=true; int currentUnique=0;
          for (int i=0; i<9999; i++) {zipSort[i]=0;}
          while(currentZipFind!=nullptr) {
          for (int i=0; i<999; i++) {
            //Find a new zipcode to average
            if (currentZipFind->zipcode==zipSort[i]) {
              //Only find unique ZIPs
              newZip=false;
              break;
            }
            newZip=true;
          }
          if ( (newZip) ) {
            zipSort[currentUnique]=currentZipFind->zipcode;
            //cout << zipSort[currentUnique] << endl;
            currentUnique++;
          }
          currentZipFind = currentZipFind->nextZip;
        }
        bsort(zipSort, 10000);  //Sort array of zipcodes by bubblesort.

        houseData* findAvg = head;
          int costPerZip[10000]={0}, totalPerZip[10000]={0};
          //Set all of the values to zero
          for (int i=0; i<9999; i++) {costPerZip[i]=0; totalPerZip[i]=0;}
          
          while (findAvg!=nullptr) {
            for(int j=0; j<9999; j++) {
              if (zipSort[j]==findAvg->zipcode) {
                costPerZip[j]+=findAvg->price;
                totalPerZip[j]++;
                break; //Break for loop
              }
            } //end for
            findAvg=findAvg->nextZip;
          } //end while
          for (int k=0; k<9999; k++) {
            if (zipSort[k]!=0) {
              cout << zipSort[k] << ":average price=" << costPerZip[k]/totalPerZip[k] << endl;
            }
          }

        //printAllHousesByZip(head);

        //This loop will also have to change in your
        // final program (see HINT 1).

        DelRecord(head);

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

//Bubble sort the zipcode algorithm
void bsort(int list[], int length) {
  for (int i=0; i<length; i++) {
    for (int j=0; j<length-1; j++) {
      if (list[j]>list[j+1]) {
        //This is so the bubble can happen
        swap(list[j], list[j+1]);
      }
    }
  }
}

//This function simply swaps two values so the bubbling can commence
void swap (int &a, int &b) {
  int temp;
  temp=a; a=b; b=temp;
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

houseData* Scanlist(houseData* head, int Zipcode) {
  houseData* previous; houseData* current;
  previous=head;
  current=head->nextZip;
  while ((current!=NULL) && !(current->zipcode >= Zipcode)) {
    previous=current;
    current=current->nextZip;
  }
  return previous;
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
  houseData* next;
  while (record!=NULL) {
    next=record->nextZip;
    delete record;
    record = next;
  }

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
