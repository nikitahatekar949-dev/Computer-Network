#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ip;
    int a, b, c, d;

    cout << "Enter IPv4 Address: ";
    cin >> ip;

    // Separate the four parts
    sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);

    // Check validity
    if (a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
    {
        cout << "Invalid IPv4 Address";
        return 0;
    }

    cout << "\nValid IPv4 Address\n";

    // Class A
    if (a >= 1 && a <= 126)
    {
        cout << "Class: A" << endl;
        cout << "Network ID: " << a << ".0.0.0" << endl;
        cout << "Host ID: " << b << "." << c << "." << d << endl;
    }

    // Class B
    else if (a >= 128 && a <= 191)
    {
        cout << "Class: B" << endl;
        cout << "Network ID: " << a << "." << b << ".0.0" << endl;
        cout << "Host ID: " << c << "." << d << endl;
    }

    // Class C
    else if (a >= 192 && a <= 223)
    {
        cout << "Class: C" << endl;
        cout << "Network ID: " << a << "." << b << "." << c << ".0" << endl;
        cout << "Host ID: " << d << endl;
    }

    // Class D
    else if (a >= 224 && a <= 239)
    {
        cout << "Class: D" << endl;
        cout << "Multicasting Address";
    }

    // Class E
    else
    {
        cout << "Class: E" << endl;
        cout << "Experimental Address";
    }

    return 0;
}