
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter generator bits: ";
    cin >> generator;

    int dataLen = data.length();
    int genLen = generator.length();

    
    string temp = data;
    for (int i = 0; i < genLen - 1; i++)
        temp += '0';

    
    for (int i = 0; i <= temp.length() - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                temp[i + j] =
                    (temp[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }


    string remainder = temp.substr(dataLen, genLen - 1);

    
    string codeword = data + remainder;

    cout << "\nRemainder: " << remainder;
    cout << "\nTransmitted Codeword: " << codeword << endl;

    return 0;
}



//output:-
Enter data bits: 10111
Enter generator bits: 1101

Remainder: 000
Transmitted Codeword: 10111000