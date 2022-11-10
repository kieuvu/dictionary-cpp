#include <iostream>
#include <fstream>

using namespace std;

class File
{
private:
    ofstream wDictFile;
    ifstream rDictFile;

public:
    /**
     *Kiem tra tu ton tai
     */
    int checkExist(string word)
    {
        string currentWord;
        this->rDictFile.open("btl_dictionary.txt", ios_base::in);
        int isExisted = 0;
        while (getline(this->rDictFile, currentWord))
        {
            if (currentWord == word)
            {
                isExisted = 1;
                break;
            }
        }
        this->rDictFile.close();
        return isExisted;
    }

    /**
     *Ghi tu moi vao file
     */
    void writeFile(string word)
    {
        this->wDictFile.open("btl_dictionary.txt", ios_base::app);
        this->wDictFile << word << endl;
        this->wDictFile.close();
    }
};