#include <fstream>
#include <string>
#include <map>
#include "counter.h"

using namespace std;
counter table;
int main(int argc, char** argv) {
	char *infile, *outfile;
	infile = argv[argc - 2];
	outfile = argv[argc - 1];
	table.wordcount(infile);
	table.count_print(outfile);
	return 0;
}