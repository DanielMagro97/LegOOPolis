#include <sstream>

#include "CSVReader.h"

#define WHITE_SPACE " \t"

string trimLeft(string &s);
string trimRight(string &s);
string trim(string &s);

CSVReader::CSVReader(string filename, string delimiter, bool ignoreComments) {
    is.open(filename);
    if (!is.good()) {
        ostringstream oss;
        oss << "Error opening file \"" << filename << "\"";
        throw ifstream::failure(oss.str());
    }

    this->delimiter = delimiter;
    this->ignoreComments = ignoreComments;
}

CSVReader::~CSVReader() {
    is.close();
}

bool CSVReader::readLine(vector<string> &vec) {
    vec.clear();
    string line;

    // Get the next line.
    for (;;) {
        if (is.eof())
            return false;

        getline(is, line);

        // Abort if no data could be read and the EOF has not been reached.
        if (is.fail() && !is.eof())
            throw ifstream::failure("Error reading from file");

        line = trim(line);

        // Ignore empty line.
        if (line.length() == 0)
            continue;

        if (ignoreComments) {
            // Ignore comment.
            if (line[0] == '#')
                continue;
        }

        break;
    }

    // Extract tokens from the line and populate the passed-in vector.

    string token;
    size_t pos;

    for (;;) {
        pos = line.find(delimiter);

        if (pos != string::npos) {// delimiter found
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            token = trim(token);
            vec.push_back(token);
        }
        else {
            token = trim(line);
            vec.push_back(token);
            break;
        }
    }

    return true;
}


// remove all whitespaces before data in the textfile
string trimLeft(string &s){
    size_t pos;
    pos = s.find_first_not_of(" \t\r\n\f\v", 0);

    if (pos == string::npos){
        return s;
    }
    return s.substr(pos, string::npos); // npos means till the end of the string
}

string trimRight(string &s){
    size_t pos = s.find_last_not_of(WHITE_SPACE);

    if (pos == string::npos)
        return "";

    return s.substr(0, pos + 1);
}

string trim(string &s){
    string tmpStr = trimLeft(s);
    return trimRight(tmpStr);
}