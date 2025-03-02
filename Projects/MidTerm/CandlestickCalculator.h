#ifndef CANDLESTICKCALCULATOR_H
#define CANDLESTICKCALCULATOR_H

#include <vector>
#include <string>
#include "Candlestick.h"
#include "DataLoader.h"

/**
 * Enum to represent the aggregation timeframe for candlesticks.
 * (Yearly, Monthly, or Daily candlesticks)
 */
enum class TimeFrame { Yearly, Monthly, Daily };

/**
 * CandlestickCalculator class to compute candlestick data from raw temperature records.
 */
class CandlestickCalculator {
public:
    /**
     * Compute candlestick data from temperature records, grouping by the specified timeframe.
     * Returns a vector of Candlestick objects for each period.
     */
    static std::vector<Candlestick> computeCandlesticks(const std::vector<TemperatureRecord>& records, TimeFrame timeframe);
};

#endif
