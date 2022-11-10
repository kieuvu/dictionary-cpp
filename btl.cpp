#include <iostream>
#include "dictionary.h"

using namespace std;

void initial(int option)
{
    while (true)
    {
        Dictionary dict;
        cout << "Enter your text or -1 to ecscape: ";
        string inp;
        getline(cin, inp);
        if (inp == "-1")
            break;
        if (inp == "")
            continue;
        if (option == 1)
            dict.insert(inp, 1);
        else if (option == 2)
            dict.setParagraph(inp)->checkParagraph();
    }
}

int main()
{
    while (true)
    {
        cout << "1. Add new word" << endl;
        cout << "2. Check paragraph" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";

        int choice;

        cin >> choice;
        cin.ignore(1);

        switch (choice)
        {
        case 1:
        case 2:
            initial(choice);
            break;
        case 3:
            return 0;
        }
    }

    return 0;
}