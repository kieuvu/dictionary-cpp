#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include "file.h"

using namespace std;

class Dictionary
{
private:
    File *file;
    string paragraph;
    vector<string> words, newWords;

public:
    /**
     * Ham khoi tao
     */
    Dictionary()
    {
        file = new File();
    }

    /**
     * Ham huy
     */
    ~Dictionary()
    {
        delete file;
    }

    /**
     * Kiem tra doan van
     */
    void checkParagraph()
    {
        this->decapitalize(this->paragraph)->wordExtractor()->getNewWords()->updateDictionary();
    }

    /**
     * set doan van
     */
    Dictionary *setParagraph(string paragraph)
    {
        this->paragraph = paragraph;
        return this;
    }

    /**
     * Tach tu tu doan van cho vao vector
     */
    Dictionary *wordExtractor()
    {
        istringstream stream(this->paragraph);
        string word;
        while (getline(stream, word, ' '))
        {
            if (find(this->words.begin(), this->words.end(), word) == this->words.end())
            {
                this->words.push_back(word);
            }
        }
        return this;
    }

    /**
     * Chuyen thanh chu khong viet hoa
     */
    Dictionary *decapitalize(string &word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return this;
    }

    /**
     * Lay tu dau tien
     */
    Dictionary *getFirstWord(string &word)
    {
        word = word.substr(0, word.find(" "));
        return this;
    }

    /**
     * Tim nhung tu chua co trong tu dien
     */
    Dictionary *getNewWords()
    {
        for (int i = 0; i < this->words.size(); i++)
        {
            string word = this->words.at(i);
            if (!file->checkExist(word))
                newWords.push_back(word);
        }
        return this;
    }

    /**
     * Cap nhat tu dien
     */
    Dictionary *updateDictionary()
    {
        for (int i = 0; i < this->newWords.size(); i++)
        {
            string word = this->newWords.at(i);
            string replaceWord = "";
            cout << "Found a new word: '" << word << "'.Press enter to save or type the correct word, -1 to ignore: ";
            getline(cin, replaceWord);
            if (replaceWord == "-1")
                continue;
            if (replaceWord == "")
                this->insert(word);
            else
                this->insert(replaceWord, 1);
        }
        cout << "Done!" << endl;
        return this;
    }

    /**
     * Them tu vao trong tu dien
     */
    Dictionary *insert(string word, int isUserInput = 0)
    {
        if (isUserInput)
            this->decapitalize(word)->getFirstWord(word);

        if (this->file->checkExist(word))
            cout << "The word '" << word << "' is existed!" << endl;
        else
        {
            this->file->writeFile(word);
            cout << "Saved a new word: '" << word << "'!" << endl;
        }

        return this;
    }
};
