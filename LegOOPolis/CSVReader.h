#pragma once

#include <fstream>
#include <vector>

using namespace std;

class CSVReader {
    ifstream is;
    string delimiter;
    bool ignoreComments;

public:
    CSVReader(string filename, string delimiter = ",", bool ignoreComments = true);

    ~CSVReader();

    bool readLine(vector<string> &vec);
};