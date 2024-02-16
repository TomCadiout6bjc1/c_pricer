#include "../include/IOlib/io.h"
using namespace std;

// Constructor
CsvWriter::CsvWriter(string path_, char sep_)
    : path(path_)
    , sep(sep_) {};
CsvWriter::CsvWriter(string path_)
    : path(path_)
    , sep(';') {};
CsvWriter::CsvWriter()
    : path("io/output.csv")
    , sep(';') {};

// Destructor
CsvWriter::~CsvWriter() {};

// Writer
void CsvWriter::write(const vector<string>& header, const vector<vector<double>>& content) const
{
    ofstream myFile(path);

    if (myFile.is_open()) {
        // Write headers
        for (size_t i = 0; i < header.size(); ++i) {
            myFile << header[i];
            if (i != header.size() - 1) {
                myFile << sep;
            }
        }
        myFile << "\n";

        // Write content
        for (const auto& row : content) {
            for (size_t i = 0; i < row.size(); ++i) {
                myFile << row[i];
                if (i != row.size() - 1) {
                    myFile << sep;
                }
            }
            myFile << "\n";
        }

        myFile.close();
    } else {
        // Handle file opening failure here if needed
        // For example: throw an exception, log an error, etc.
        cout << "Error, cannot open the output stream" << endl;
    };
};
