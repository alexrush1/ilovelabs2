//
// Created by ivan on 30.09.2019.
//

#ifndef INTRO_COUNTER_H
#define INTRO_COUNTER_H

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class counter {
    map<string, int> mp;
    int count = 0;
    vector<pair<int, string>> list;
public:
    void push_to_map(map<string, int> &mp, string &word) {
        count++;
        mp[word]++;
        word.clear();
    }

    void wordcount(char *infile) {
        string str, word;
        ifstream in;
        in.open(infile);
        while (getline(in, str)) {
            int str_length = str.length();
            for (int i = 0; i < str_length; i++) {
                if (isalpha(str[i]) || isdigit(str[i])) {
                    word += str[i];
                } else {
                    if (word != "") {
                        push_to_map(mp, word);
                    }
                }
            }
        }
        if (word != "") {
            push_to_map(mp, word);
        }
        for (pair<string, int> it : mp) {
            list.emplace_back(it.second, it.first);
        }
        in.close();
    }

    void count_print(char *outfile) {
        ofstream out;
        out.open(outfile);
        sort(list.begin(), list.end());
        reverse(list.begin(), list.end());
        for (pair<int,string> i: list) {
            out << i.second + ";" + to_string(i.first) + ";" + to_string(i.first/ (float)count * 100) + "\n";
        }
        out.close();
    }
};
#endif //INTRO_COUNTER_H
