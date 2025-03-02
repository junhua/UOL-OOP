#ifndef CANDLESTICK_H
#define CANDLESTICK_H

#include <string>

/**
 * Candlestick class to hold aggregated temperature data (Open, High, Low, Close) for a time period.
 */
class Candlestick {
private:
    std::string date;   // Label date for the time period (e.g., "1980-01-01" for year 1980)
    double open;
    double close;
    double high;
    double low;
public:
    // Constructors
    Candlestick();
    Candlestick(const std::string& date, double open, double close, double high, double low);

    // Accessors
    std::string getDate() const;
    double getOpen() const;
    double getClose() const;
    double getHigh() const;
    double getLow() const;
};

#endif
