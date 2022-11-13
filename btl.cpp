#include <iostream>
#include "dictionary.h"

using namespace std;

void initial()
{
    while (true)
    {
        Dictionary dict;
        string inp;
        cout << "Enter your text or -1 to ecscape: ";
        getline(cin, inp);
        if (inp == "-1")
            break;
        if (inp == "")
            continue;
        dict.checkParagraph(inp);
    }
}

int main()
{
    initial();
    return 0;
}