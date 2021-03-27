#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

map<string, int> everyWord{
        { "jeden", 1 }, { "dwa", 2 }, { "trzy", 3 }, { "cztery", 4 }, { "piec", 5 }, { "szesc", 6 }, { "siedem", 7 }, { "osiem", 8 }, { "dziewiec", 9 },

        { "jedenascie", 11 }, { "dwanascie", 12 }, { "trzynascie", 13 }, { "czternascie", 14 }, { "pietnascie", 15 }, { "szesnascie", 16 }, { "siedemnascie", 17 }, { "osiemnascie", 18 }, { "dziewietnascie", 19 },

        { "dziesiec", 10 }, { "dwadziescia", 20 }, { "trzydziesci", 30 }, { "czterdziesci", 40 }, { "piecdziesiat", 50 }, { "szescdziesiat", 60 }, { "siedemdziesiat", 70 }, { "osiemdziesiat", 80 }, { "dziewiecdziesiat", 90 },

        { "sto", 100 }, { "dwiescie", 200 }, { "trzysta", 300 }, { "czterysta", 400 }, { "piecset", 500 }, { "szescset", 600 }, { "siedemset", 700 }, { "osiemset", 800 }, { "dziewiecset", 900 },

        { "tysiac", 1000 }, { "tysiace", 1000 }, { "tysiecy", 1000 },

        { "milion", 1000000 }, { "miliony", 1000000 }, { "milionow", 1000000 },

        { "miliard", 1000000000 },

        { "jednosci", 1 },
};

map<string, int> hundreds{
    { "sto", 100 }, { "dwiescie", 200 }, { "trzysta", 300 }, { "czterysta", 400 }, { "piecset", 500 },
    { "szescset", 600 }, { "siedemset", 700 }, { "osiemset", 800 }, { "dziewiecset", 900 },
};

map<string, int> tens{
    { "dziesiec", 10 }, { "dwadziescia", 20 }, { "trzydziesci", 30 }, { "czterdziesci", 40 }, { "piecdziesiat", 50 },
    { "szescdziesiat", 60 }, { "siedemdziesiat", 70 }, { "osiemdziesiat", 80 }, { "dziewiecdziesiat", 90 },
};

map<string, int> elevenToNineteen{
    { "jedenascie", 11 }, { "dwanascie", 12 }, { "trzynascie", 13 }, { "czternascie", 14 }, { "pietnascie", 15 },
    { "szesnascie", 16 }, { "siedemnascie", 17 }, { "osiemnascie", 18 }, { "dziewietnascie", 19 },
};

map<string, int> units{
    { "jeden", 1 }, { "dwa", 2 }, { "trzy", 3 }, { "cztery", 4 }, { "piec", 5 },
    { "szesc", 6 }, { "siedem", 7 }, { "osiem", 8 }, { "dziewiec", 9 },
};

string thousands[] = { "tysiac", "tysiace", "tysiecy" };
string millions[] = { "milion", "miliony", "milionow" };

void wrongInput() {
    cout << "NIE" << endl;
    exit(0);
}

bool isSuffixCorrect(string suffix, int num, bool previousNum) {
    if ((num == 1 and !previousNum) and (suffix == thousands[0] or suffix == millions[0])) return true;
    else if ((num >= 2 and num <= 4) and (suffix == thousands[1] or suffix == millions[1])) return true;
    else if ((num > 4 or (num == 1 and previousNum)) and (suffix == thousands[2] or suffix == millions[2])) return true;

    return false;
}

void checkSuffix(vector<string> block, string word) {
    int blockSize = block.size();

    if (blockSize == 0) {
        wrongInput();
    }
    else if (blockSize == 1 and !isSuffixCorrect(word, everyWord[block.back()], false)) {
        wrongInput();
    }
    else if (blockSize > 1 and !isSuffixCorrect(word, everyWord[block.back()], everyWord[block.end()[-2]])) {
        wrongInput();
    }
}

int main()
{
    int sum = 0;

    vector<vector<string>> blocks;
    vector<string> block;
    vector<int> magnitude;

    bool isBillion = false;

    string word;
    while (cin >> word) {
        if (isBillion or !everyWord[word]) wrongInput();

        block.push_back(word);

        if (word == thousands[0] or word == thousands[1] or word == thousands[2]) {
            block.pop_back();

            checkSuffix(block, word);

            blocks.push_back(block);
            block.clear();

            magnitude.push_back(1e3);
        }
        else if (word == millions[0] or word == millions[1] or word == millions[2]) {
            block.pop_back();

            checkSuffix(block, word);

            blocks.push_back(block);
            block.clear();

            magnitude.push_back(1e6);
        }
        else if (word == "miliard") {
            isBillion = true;
        }
    }
    if (!block.empty()) {
        blocks.push_back(block);
        magnitude.push_back(1);
    }

    if (isBillion) {
        cout << 1000000000 << endl;
        return 0;
    }

    vector<int> magnitudeCopy = magnitude;
    sort(magnitudeCopy.begin(), magnitudeCopy.end(), greater <>());
    for (int i = 0; i < magnitude.size(); i++) {
        if (magnitudeCopy[i] != magnitude[i]) wrongInput();
    }

    for (int i = 0; i < blocks.size(); i++) {
        bool foundHundreds = false, foundTens = false, foundTen = false, foundElevenToNineteen = false, foundUnits = false;

        for (string word : blocks[i]) {
            if (hundreds[word]) {
                if (foundHundreds or foundTens or foundElevenToNineteen or foundUnits) wrongInput();

                foundHundreds = true;
                sum += hundreds[word] * magnitude[i];
            }
            else if (tens[word]) {
                if (foundTens or foundElevenToNineteen or foundUnits) wrongInput();

                if (tens[word] == 10) {
                    foundTen = true;
                }
                foundTens = true;
                sum += tens[word] * magnitude[i];
            }
            else if (elevenToNineteen[word]) {
                if (foundElevenToNineteen or foundTens or foundUnits) wrongInput();

                foundElevenToNineteen = true;
                sum += elevenToNineteen[word] * magnitude[i];
            }
            else if (units[word]) {
                if (foundTen or foundElevenToNineteen or foundUnits) wrongInput();

                foundUnits = true;
                sum += units[word] * magnitude[i];
            }
        }
    }

    if (sum == 0) wrongInput();
    else {
        cout << sum << endl;
    }
}