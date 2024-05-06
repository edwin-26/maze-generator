#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>
#include "get_validate_inputs.h"

using namespace std;

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
