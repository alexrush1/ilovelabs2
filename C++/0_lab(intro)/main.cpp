#include <fstream>
#include <string>
#include <map>
#include <iostream>

#include "counter.h"

using namespace std;
int main(int argc, char** argv) {
    counter table;

    char *infile, *outfile;
	infile = argv[argc - 2];
	outfile = argv[argc - 1];
    try {
        table.wordcount(infile);
        table.count_print(outfile);

    } catch (std::exception & ex)
    {
        cout << "Error: " << ex.what();
    }catch (int &i) {
        cout << "Error: " << i;

    }

	return 0;
}