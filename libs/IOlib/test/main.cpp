#include "../include/IOlib/io.h"
using namespace std;

int main()
{
    // Create a writer object
    string path = "/tmp/test_library_c_io.csv";
    char sep = '|';
    CsvWriter writer_object(path, sep);

    // Define a toy csv sample
    vector<string> header { "t", "St" };
    vector<double> row_1 { 1., 10 };
    vector<double> row_2 { 2., 12.5 };
    vector<vector<double>> content { row_1, row_2 };

    // Write the toy example into io folder
    writer_object.write(header, content);
    cout << "\n\033[33m[INFO]\nOutput file has been writen in /tmp/test_library_c_io.csv\033[0m\n\n";

    return 0;
}
