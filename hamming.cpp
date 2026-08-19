#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string data;
    int m, r = 0, n;

    cout << "Enter data bits: ";
    cin >> data;

    // Step 3: Number of data bits
    m = data.length();

    // Step 4: Find number of redundant bits
    while (pow(2, r) < (m + r + 1))
    {
        r++;
    }

    // Step 5: Total number of bits
    n = m + r;

    cout << "\n----- HAMMING CODE CALCULATION -----\n";
    cout << "Data bits (m)        = " << m << endl;
    cout << "Redundant bits (r)   = " << r << endl;
    cout << "Total bits (n)       = " << n << endl;

    // Create array H[1...n]
    int H[100] = {0};

    // Step 8: Display redundant bit positions
    cout << "\nRedundant bit positions:\n";

    for (int i = 0; i < r; i++)
    {
        int position = pow(2, i);
        cout << position << " -> R" << position << endl;
    }

    // Step 9: Place data bits in remaining positions
    int j = m - 1;

    for (int i = 1; i <= n; i++)
    {
        // If position is NOT power of 2
        if ((i & (i - 1)) != 0)
        {
            H[i] = data[j] - '0';
            j--;
        }
    }

    // Display positions and initial values
    cout << "\nPositions and bits before parity calculation:\n";

    for (int i = n; i >= 1; i--)
    {
        cout << "Position " << i << " = " << H[i];

        if ((i & (i - 1)) == 0)
            cout << " (Redundant)";

        cout << endl;
    }

    // Step 10-14: Calculate redundant bits
    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;

        cout << "\nR" << p << " checks positions: ";

        for (int i = p; i <= n; i++)
        {
            for (int j = 0; j < p && (i + j) <= n; j++)
            {
                int position = i + j;

                cout << position << " ";

                if (position != p)
                {
                    count = count + H[position];
                }
            }

            i = i + p - 1;
        }

        // Even parity
        H[p] = count % 2;

        cout << "\nNumber of 1s = " << count;
        cout << "\nR" << p << " = " << H[p] << endl;
    }

    // Display final values at each position
    cout << "\n----- FINAL BIT POSITIONS -----\n";

    for (int i = n; i >= 1; i--)
    {
        cout << "Position " << i << " = " << H[i];

        if ((i & (i - 1)) == 0)
            cout << "  <-- Redundant bit";

        cout << endl;
    }

    // Step 16: Final Hamming code
    cout << "\n----- FINAL HAMMING CODE -----\n";

    for (int i = n; i >= 1; i--)
    {
        cout << H[i];
    }

    cout << endl;

    cout << "\nHamming code generated successfully!" << endl;

    return 0;
}