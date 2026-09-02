#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, generator;

    cout << "Enter received codeword: ";
    cin >> codeword;

    cout << "Enter generator: ";
    cin >> generator;

    string temp = codeword;
    int n = codeword.length();
    int g = generator.length();

    // Modulo-2 division
    for (int i = 0; i <= n - g; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < g; j++)
            {
                temp[i + j] = (temp[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Check remainder
    string remainder = temp.substr(n - g + 1);

    cout << "Remainder: " << remainder << endl;

    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error detected!" << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}