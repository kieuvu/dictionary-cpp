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
    void checkParagraph(string _paragraph)
    {
        this->setParagraph(_paragraph)
            .formatString(this->paragraph)
            .extractWords()
            .getNewWords()
            .updateDictionary();
    }

    /**
     * Them tu vao trong tu dien
     */
    void insert(string word, int isUserInput = 0)
    {
        if (isUserInput)
            this->formatString(word).getFirstWord(word);

        if (this->file->checkExist(word))
            cout << "The word '" << word << "' is existed!" << endl;
        else
        {
            this->file->writeFile(word);
            cout << "Saved a new word: '" << word << "'!" << endl;
        }
    }

    /**
     * Cap nhat tu dien
     */
    void updateDictionary()
    {
        string word;
        string replaceWord;
        for (int i = 0; i < this->newWords.size(); i++)
        {
            word = this->newWords.at(i);
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
    }

    /**
     * set doan van
     */
    Dictionary &setParagraph(string paragraph)
    {
        this->paragraph = paragraph;
        return *this;
    }

    /**
     * Tach tu tu doan van cho vao vector
     */
    Dictionary &extractWords()
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
        return *this;
    }

    /**
     * Dinh dang chuoi
     */
    Dictionary &formatString(string &_string)
    {
        return this->removeIllegalCharacter(_string)
            .trim(_string)
            .decapitalize(_string);
    }

    /**
     * Xoa khoang cach giua 2 dau
     */
    Dictionary &trim(string &_string)
    {
        size_t first = _string.find_first_not_of(' ');
        if (first == string::npos)
            _string = "";
        size_t last = _string.find_last_not_of(' ');
        _string = _string.substr(first, (last - first + 1));
        return *this;
    }

    /**
     * Chuyen thanh chu khong viet hoa
     */
    Dictionary &decapitalize(string &_string)
    {
        transform(_string.begin(), _string.end(), _string.begin(), ::tolower);
        return *this;
    }

    /**
     * Xoa so va ki tu dac biet
     */
    Dictionary &removeIllegalCharacter(string &_string)
    {
        _string.erase(
            remove_if(
                _string.begin(), _string.end(), [](char c)
                { return !isalpha(c) && c != ' '; }),
            _string.end());
        return *this;
    }

    /**
     * Lay tu dau tien
     */
    Dictionary &getFirstWord(string &word)
    {
        word = word.substr(0, word.find(" "));
        return *this;
    }

    /**
     * Tim nhung tu chua co trong tu dien
     */
    Dictionary &getNewWords()
    {
        string word;
        for (int i = 0; i < this->words.size(); i++)
        {
            word = this->words.at(i);
            if (!file->checkExist(word))
                newWords.push_back(word);
        }
        return *this;
    }
};
