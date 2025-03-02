#ifndef PLOTTER_H
#define PLOTTER_H

#include <vector>
#include "Candlestick.h"

/**
 * Plotter class to generate text-based candlestick charts.
 */
class Plotter {
public:
    /**
     * Outputs a text-based plot of the candlestick data to the console.
     */
    static void plotCandlesticks(const std::vector<Candlestick>& candlesticks);
};

#endif
