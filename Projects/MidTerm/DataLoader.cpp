#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<TemperatureRecord> DataLoader::loadCSV(const std::string& filename, const std::string& countryCode, int startYear, int endYear) {
    std::vector<TemperatureRecord> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        // TODO: print an error message if the file cannot be opened.
        // Example: std::cerr << "Error: Could not open file " << filename << std::endl;
        // Make sure you customize the error message to be informative.

        return data;
    }

    std::string header;
    if (std::getline(file, header)) {
        // TODO: Parse header to identify the column index for the given countryCode.
        // Example: If header is "DateTime, AT_temperature, BE_temperature, ..., GB_temperature, ...",
        // find the index of "GB_temperature" (or appropriate column label for country).
    }

    std::string line;
    while (std::getline(file, line)) {
        // TODO: Parse each line of the CSV to extract the date and the temperature value for countryCode.
        // Hint: Use std::stringstream to split by commas, or find commas manually.
        // - Extract the timestamp (date string) from the first column.
        // - Extract the temperature value from the countryCode's column.
        // - Parse the year from the date string (first 4 characters) to filter by startYear and endYear.
        // - If the year is within [startYear, endYear], store the record in the data vector.
    }

    return data;
}
