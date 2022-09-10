#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//takes in a char called letter and returns the encrypted char
char rot13(char letter);

//writes the encrypted char to the specified output file
void WriteTranslatedChar(char letter, ofstream &outfile);

int main() {
    //obtain the names of the input and outpute files from user
    string inputFileName;
    string outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    //open up then input and output files
    ifstream infile(inputFileName);
    ofstream outfile(outputFileName);

    char letter; //input char
    char rotLetter; //input char + 13

    if (infile.is_open()) {

        //while input file is valid
        while(infile) {
            letter = infile.get();                      //obtain the next char 
            rotLetter = rot13(letter);                  //call rot13 and assign the new char to rotLetter
            WriteTranslatedChar(rotLetter, outfile);    //write the rotLetter to the specified output file
        }

        //close both files
        infile.close();
        outfile.close();

        //reopen the input file, and open the output file
        ifstream inputFile(inputFileName);
        ifstream encryptedFile(outputFileName);

        //displays input info
        if (inputFile.is_open()) {
            string inputContents;
            char ch;

            //obtains the next char in input file and appends it to a string
            while (inputFile) {
                ch = inputFile.get();   //obtain the next char
                inputContents += ch;    //appends the char to the string
            }

            //gets rid of the End Of File character
            inputContents.erase(inputContents.size() - 1);

            cout << endl;
            cout << inputFileName << " data is: " << endl;
            cout << "***************************" << endl;
            cout << inputContents << endl;
            cout << "***************************" << endl;
            cout << endl << endl;
        } 
        
        //displays output info
        if (encryptedFile.is_open()) {  
            string outputContents;
            char ch;

            //obtains next char, appends it to the string outputContents
            while (encryptedFile) {
                ch = encryptedFile.get();
                outputContents += ch;
            }

            //gets rid of End Of File character
            outputContents.erase(outputContents.size() - 1);

            cout << outputFileName << " data is: " << endl;
            cout << "***************************" << endl;
            cout << outputContents << endl;
            cout << "***************************" << endl;
        }

        //close the files
        inputFile.close();
        encryptedFile.close();
    }
    else {
        cout << "Input file not found!" << endl;
    }
    return 0;
}

char rot13(char letter) {
    char newLetter;

    //if letter is A-M or a-m
    if ((letter >= 65 && letter <= 77) || (letter >= 97 && letter <= 109)) { 
        newLetter = letter + 13;
    }

    //if letter is N-Z or n-z
    else if ((letter >= 78 && letter <= 90) || (letter >= 110 & letter <= 122)) { 
        newLetter = letter - 13;
    }

    //space, period, new line
    else if (letter == ' ') {
        newLetter = letter;
    }
    else if (letter == '.'){
        newLetter = letter;
    }
    else if (letter == '\n') {
        newLetter = letter;
    }

    return newLetter;
}

void WriteTranslatedChar(char letter, ofstream &outfile) {
    //writes the translated letter to the output file
    if (outfile.is_open()) {
        outfile << letter;
    }
    return;
}
