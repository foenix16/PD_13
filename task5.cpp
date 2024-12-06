#include <iostream>
#include <fstream>
using namespace std;

string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
string Morse[100] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                       "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-.-"};

string convertToMorse(char c) 
{
    if(c>='a' && c<='z') 
    {
        c = c-32; 
    }
    for(int i=0; i<alphabets.length(); i++) 
    {
        if(alphabets[i] == c) 
        {
            return Morse[i];
        }
    }
    return "";
}

void encryptMessage(string message) 
{
    fstream outputFile;
    outputFile.open("D:\\PF\\PD13\\output\\MorseOutput.txt", ios::out);
    
    string morseCode = "";
    for(int i=0; i<message.length(); i++) 
    {
        string code = convertToMorse(message[i]);
        if(!code.empty()) 
        {
            morseCode += code + " ";
        }
    }
    
    outputFile << "Original message: " << message << endl;
    outputFile << "Morse code: " << morseCode << endl;
    outputFile.close();
    
}

int main() 
{
    string message;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    
    encryptMessage(message);
    
    return 0;
}