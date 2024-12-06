#include<iostream>
#include<fstream>
using namespace std;
void displayOutput(int age, string name)
{
    //output file 
    if(age%2==0)
    {
        fstream file2;
        file2.open("D:\\PF\\PD13\\output\\output.txt", ios::out);
        file2 <<"###############" << endl;
        file2 << age << " HB " << name <<"! " << age << endl;
        file2 <<"###############" << endl;
        file2.close();
    }
    else
    {
        fstream file3;
        file3.open("D:\\PF\\PD13\\output\\output.txt", ios::out);
        file3 <<"***************" << endl;
        file3 << age << " HB " << name <<"! " << age << endl;
        file3 <<"***************" << endl;
        file3.close();
    }
}
main()
{
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
    
     //writing data
    fstream file;
    file.open("D:\\PF\\PD13\\output\\names.txt", ios::out);
    file << name;
    file <<",";
    file << age;
    file.close();
    //reading data now
    string line;
    fstream file1;
    file1.open("D:\\PF\\PD13\\output\\names.txt", ios::in);
    getline(file1, line);
    file1.close();
    
    displayOutput(age,name);
}

#include<iostream>
#include<fstream>
using namespace std;
string checkAlpha(string alphabets)
{
    bool letters[26] = {false};
    for(char c : alphabets) 
    {
        if(c >= 'a' && c <= 'z')
        {
            letters[c - 'a'] = true;
        }
    }
    fstream file;
    file.open("alphabets.txt", ios::app);
    string missing = "";
    for(int i = 0; i < 26; i++) 
    {
        if(!letters[i]) 
        {
            missing += char(i + 97);
        }
    }
    if(!missing.empty())
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
    cout << "Enter alphabets(a-z): ";
    cin >> alphabets;
    fstream inputFile;
    inputFile.open("alphabets.txt", ios::out);
    getline(inputFile,alphabets);
    inputFile.close();
    checkAlpha(alphabets);
}