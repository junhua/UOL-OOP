#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <string>
#include "Candlestick.h"

/**
 * DataFilter class to filter candlestick data based on criteria like date range.
 */
class DataFilter {
public:
    /**
     * Filter candlesticks by a date range [startDate, endDate] (inclusive).
     * Dates are expected in "YYYY-MM-DD" format.
     */
    static std::vector<Candlestick> filterByDateRange(const std::vector<Candlestick>& data, const std::string& startDate, const std::string& endDate);
    
    // TODO: Consider implementing these additional filter methods:
    
    /**
     * Filter candlesticks by temperature range [minTemp, maxTemp] (inclusive).
     * This could filter based on any of the OHLC values (e.g., high temperature).
     */
    // static std::vector<Candlestick> filterByTemperatureRange(const std::vector<Candlestick>& data, double minTemp, double maxTemp);
    
    /**
     * Filter candlesticks by trend (rising or falling).
     * A rising trend means close >= open, falling means close < open.
     */
    // static std::vector<Candlestick> filterByTrend(const std::vector<Candlestick>& data, bool risingTrend);
    
    /**
     * Filter candlesticks by volatility (difference between high and low).
     * Returns candlesticks where (high - low) >= minVolatility.
     */
    // static std::vector<Candlestick> filterByVolatility(const std::vector<Candlestick>& data, double minVolatility);
};

#endif
