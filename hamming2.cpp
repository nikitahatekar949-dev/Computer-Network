#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;
    int n;

    cout << "Enter received Hamming code: ";
    cin >> code;

    n = code.length();

    int b[20];

    for (int i = 1; i <= n; i++)
        b[i] = code[n - i] - '0';

    cout << "\nReceived Hamming Code: " << code << endl;

    cout << "\nBits with positions:\n";
    for (int i = n; i >= 1; i--)
        cout << "Position " << i << " = " << b[i] << endl;

    int r1 = 0, r2 = 0, r4 = 0, r8 = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            r1 ^= b[i];

        if (i & 2)
            r2 ^= b[i];

        if (i & 4)
            r4 ^= b[i];

        if (i & 8)
            r8 ^= b[i];
    }

    cout << "\nParity Check Results:\n";
    cout << "R1 = " << r1 << endl;
    cout << "R2 = " << r2 << endl;
    cout << "R4 = " << r4 << endl;
    cout << "R8 = " << r8 << endl;

    int errorPosition = r8 * 8 + r4 * 4 + r2 * 2 + r1;

    cout << "\nError Position (Binary): "
         << r8 << r4 << r2 << r1 << endl;

    cout << "Error Position (Decimal): "
         << errorPosition << endl;

    if (errorPosition == 0)
    {
        cout << "\nNo error is detected." << endl;
    }
    else
    {
        cout << "\nError detected at position "
             << errorPosition << endl;

        b[errorPosition] = b[errorPosition] ^ 1;

        cout << "Corrected bit: "
             << b[errorPosition] << endl;
    }

    string corrected = "";

    for (int i = n; i >= 1; i--)
        corrected += char(b[i] + '0');

    cout << "\nCorrected Hamming Code: "
         << corrected << endl;

    cout << "\nOriginal Data Bits: ";

    for (int i = n; i >= 1; i--)
    {
        if (i != 1 && i != 2 && i != 4 && i != 8)
            cout << b[i];
    }

    cout << endl;

    return 0;
}