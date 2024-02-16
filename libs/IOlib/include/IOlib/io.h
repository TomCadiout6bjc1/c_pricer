#pragma once

#include<string>
#include<vector>
#include <fstream>
#include <iostream>

class CsvWriter
{
private:
    // The path of the output file
    // For example: "io/foo.csv"
    std::string path;

    // The separator use to save the .csv file
    char sep;

public:
    // Constructor
    CsvWriter(std::string path_, char sep_);
    CsvWriter(std::string path_);
    CsvWriter();

    // Destructor
    ~CsvWriter();

    // Writer
    void write(const std::vector<std::string> &header, const std::vector<std::vector<double>> &content) const;
};
