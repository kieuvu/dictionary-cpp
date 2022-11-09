#include <iostream>
#include "dictionary.h"

using namespace std;

void initial(Dictionary &d, int option)
{
    while (true)
    {
        string inp;
        getline(cin, inp);
        if (inp == "-1")
            break;
        if (inp == "")
            continue;
        if (option == 1)
            d.insert(inp, 1);
        else if (option == 2)
            d.setParagraph(inp)->checkParagraph();
    }
}

int main()
{
    Dictionary *dict = new Dictionary();

    while (true)
    {
        cout << "1. Add new word" << endl;
        cout << "2. Check paragraph" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;

        cin >> choice;
        cout << "Enter your text or -1 to ecscape: " << endl;

        switch (choice)
        {
        case 1:
        case 2:
            initial(*dict, choice);
            break;
        case 3:
            delete dict;
            return 0;
        }
    }

    delete dict;
    return 0;
}