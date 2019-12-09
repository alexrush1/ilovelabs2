#include "parser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void parser::parse(const char *fileName) {
    std::ifstream infile(fileName);
    if (!infile.is_open()) {
        throw std::invalid_argument("inFile was not opened");
    }
    std::string buffer;
    std::getline(infile, buffer);
    if (buffer != "desc")
        throw std::invalid_argument("Unsupported inFile format");
    while (true) {
        int count = 0;
        std::getline(infile, buffer);
        if (buffer == "csed")
            break;
        if (infile.eof()) {
            throw std::logic_error("Unsupported inFile format");
            break;
        }
        std::string command_id;
        std::string command;
        std::string argument;

        std::vector<std::string> arguments; //Тут кстати тоже

        std::pair<std::string, std::vector<std::string>> parsedString;

        while (buffer[count] != '=') {  // Get command id
            command_id += buffer[count];
            if (count == buffer.length())
                throw std::logic_error("Unsupported inFile content");
            count++;
        }

        count++;  // skip '=' symbol
        while (buffer[count] == ' ') //Skip space symbols
            count++;

        while ((buffer[count] != ' ') && (buffer[count] != '\0')) { //Get command name
            command += buffer[count];
            count++;
        }
        count++;

        //Checking command name for dynamic arguments size
        short arg_num;
        if ((command == "grep") || (command == "readfile") || (command == "writefile") || (command == "dump")) {
            arg_num = 1;
        } else if (command == "sort") {
            arg_num = 0;
        } else {
            arg_num = 2;
        }

        if (buffer[count] != '\0') {
            for (int i = 0; i < arg_num; i++) {
                while ((buffer[count] != ' ') && (buffer[count] != '\0')) {
                    argument += buffer[count];
                    count++;
                }
                count++;
                arguments.push_back(argument);
                argument.clear();
            }
        }

        /*Preparing pair
        * parsedString stores command name + all arguments
        */
        parsedString.first = command;
        parsedString.second = arguments;

        arguments.clear();

        parsedText[stoi(command_id)] = parsedString;
    }
    if (buffer != "csed") {
        throw std::logic_error("Unsupported inFile content");
    }

    //Getting the program execution order
    getline(infile, buffer);
    if (buffer.empty()) {
        throw std::logic_error("Unsupported inFile content");
    }

    for (int counter = 0; counter <= buffer.length(); counter++) {
        std::string part;
        while (buffer[counter] == ' ') {
            counter++;
        }
        while ((buffer[counter] != ' ') && (buffer[counter] != '\0')) {
            part += buffer[counter];
            counter++;
        }
        if (part != "->") {
            ex_order.push_back(std::stol(part));
        }
    }
}