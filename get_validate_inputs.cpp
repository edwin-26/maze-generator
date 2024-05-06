#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>
#include "get_validate_inputs.h"

using namespace std;

// Function to receive and validate inputs
void getAndValidateInputs()
{
    // Get maze input from the user
    cout << "Enter maze data: ";
    string mazeInput;
    getline(cin, mazeInput);

    // Remove leading and trailing whitespaces
    mazeInput.erase(0, mazeInput.find_first_not_of(" \t\n\r\f\v"));
    mazeInput.erase(mazeInput.find_last_not_of(" \t\n\r\f\v") + 1);

    // Parse maze input
    size_t headerEnd = mazeInput.find("\n");
    if (headerEnd != string::npos)
    {
        string header = mazeInput.substr(0, headerEnd);
        string mazeBody = mazeInput.substr(headerEnd + 1);

        regex pattern("s\\((\\d+),(\\d+)\\)\\s*e\\((\\d+),(\\d+)\\)");
        smatch match;
        if (regex_search(header, match, pattern))
        {
            int startX = stoi(match[1]) - 1;
            int startY = stoi(match[2]) - 1;
            int endX = stoi(match[3]) - 1;
            int endY = stoi(match[4]) - 1;

            vector<string> mazeLines;
            stringstream ss(mazeBody);
            string line;
            while (getline(ss, line, '\n'))
            {
                mazeLines.push_back(line);
            }
            bool validSize = mazeLines.size() <= 20;
            bool validFormat = all_of(mazeLines.begin(), mazeLines.end(), [](const string &s)
                                      { return s.size() <= 20; });

            if (validSize && validFormat)
            {
                vector<vector<char>> maze(mazeLines.size(), vector<char>(mazeLines[0].size()));
                for (size_t i = 0; i < mazeLines.size(); ++i)
                {
                    for (size_t j = 0; j < mazeLines[i].size(); ++j)
                    {
                        maze[i][j] = mazeLines[i][j];
                    }
                }
            }
            else
            {
                cout << "Invalid maze configuration or size. Ensure the format is correct and the maze is up to 20x20." << endl;
            }
        }
        else
        {
            cout << "Invalid maze header format." << endl;
        }
    }
    else
    {
        cout << "Invalid maze input format." << endl;
    }
}

// Function to get and validate the maze size
int getAndValidateSize(const cgicc::Cgicc &cgi)
{
    int size = -1;

    const_form_iterator sizeInput = cgi.getElement("size");

    if (!sizeInput->isEmpty() && sizeInput != (*cgi).end())
    {
        try
        {
            size = std::stoi(**sizeInput);

            if (size <= 0 || size > 20)
            {
                size = -1;
            }
        }
        catch (const std::invalid_argument &)
        {
            size = -1;
        }
    }
    return size;
}
