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
#include <cstring>

using namespace std;

class counter {
    map<string, int> mp;
    int count = 0;
    void print_prepare(    vector<pair<int, string>> &list) {
        for (pair<string, int> it : mp) {
            list.emplace_back(it.second, it.first);
        }

        sort(list.begin(), list.end());
        reverse(list.begin(), list.end());
    }
    void push_to_map(map<string, int> &mp, string &word) {
        count++;
        mp[word]++;
    }

public:

    void wordcount(char *infile) {
        string str, word;
        ifstream in;
        in.open(infile);
        if (!in) {
            throw 1;
            //throw std::exception();
        }
        while (getline(in, str)) {
            int str_length = str.length();
            for (int i = 0; i <= str_length; i++) {
                if (isalpha(str[i]) || isdigit(str[i])) {
                    word += str[i];
                } else {
                    if (word != "") {
                        push_to_map(mp, word);
                        word.clear();
                    }
                }
            }
        }
        in.close();
    }


    void count_print(char *outfile) {
        vector<pair<int, string>> list;

        print_prepare(list);
        ofstream out;
        out.open(outfile);
        for (pair<int,string> i: list) {
            out << i.second + ";" + to_string(i.first) + ";" + to_string(i.first/ (float)count * 100) + "\n";
        }
        out.close();
    }
};
#endif //INTRO_COUNTER_H
