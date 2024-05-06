#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "get_validate_inputs.h"
#include "functions.h"

using namespace std;
using namespace cgicc;

int getAndValidateSize(const Cgicc &cgi); 

int main()
{
    Cgicc cgi;
    srand(time(0));

    cout << HTTPHTMLHeader() << endl;
    cout << html() << head() << title("Maze Generator") << head() << endl;
    cout << body() << endl;

    int size = getAndValidateSize(cgi);
    if (size != -1)
    {
        vector<vector<char>> maze(size, vector<char>(size));
        generateMaze(maze);

        // Display starting and ending points
        cout << "s(1,1) e(" << size << "," << size << ")"
             << "<br>";

        for (auto &row : maze)
        {
            for (char c : row)
            {
                cout << c;
            }
            cout << br();
        }
        cout << "<br>";
        cout << "<a href=\"../CPS3525/project3.html\"><button type=\"button\">Back to Main Page</button></a>" << endl;
    }
    else
    {
        cout << "<h4>Maze size must be 20 or less.</h4>" << endl;
        cout << "<a href=\"../CPS3525/project3.html\"><button type=\"button\">Back to Main Page</button></a>" << endl;
    }

    cout << body() << html() << endl;

    return 0;
}