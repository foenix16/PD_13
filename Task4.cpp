#include<iostream>
#include<fstream>
using namespace std;

void checkAlpha(string alphabets) 
{
    bool letters[26] = {false};
    
       for (int i=0; i<alphabets.size(); i++) 
       {
        char c = alphabets[i];
        if(c >= 'a' && c <= 'z') 
        {
            letters[c - 'a'] = true;
        }
    }
    
    string missing = "";
    for (int i = 0; i < 26; i++) 
    {
        if (!letters[i]) 
        {
            missing =missing + char(i + 97);
        }
    }
    fstream file;
    file.open("alphabets.txt", ios::app);
    if (!missing.empty()) 
    {
        file << "\n" << missing;
    } 
    else 
    {
        file << "\n";
    }
    file.close();
}

main() 
{
    string alphabets;
    cout << "Enter alphabets (a-z): ";
    cin >> alphabets;
    
    fstream inputFile;
    inputFile.open("alphabets.txt", ios::out); 
    inputFile << alphabets;
    inputFile.close();
    
    checkAlpha(alphabets);

}
