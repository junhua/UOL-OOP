#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>

/**
 * TemperatureRecord struct to represent a raw data entry from the CSV (timestamp and temperature value).
 */
struct TemperatureRecord {
    std::string date;    // Date/time string (e.g., "1980-01-01 00:00:00")
    double temperature;
};

/**
 * DataLoader class for reading temperature data from a CSV file.
 */
class DataLoader {
public:
    /**
     * Reads the CSV file and returns all temperature records for the given country code between startYear and endYear (inclusive).
     */
    static std::vector<TemperatureRecord> loadCSV(const std::string& filename, const std::string& countryCode, int startYear, int endYear);
};

#endif
