#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    getline(cin, tmp); // Read the entire line into `tmp`

    string temp;
    getline(cin, temp);

    stringstream ss(tmp); // Create a stringstream from `tmp`
    string k;

    while (ss >> k) // Extract each word from the stringstream
    {
        printf("%s, %s\n", temp.c_str(), k.c_str()); // Print `temp` and `k`
    }

    return 0;
}
