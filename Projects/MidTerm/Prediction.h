#ifndef PREDICTION_H
#define PREDICTION_H

#include <vector>
#include "Candlestick.h"

/**
 * Prediction class housing different models for forecasting temperature trends.
 */
class Prediction {
public:
    /**
     * Predict the next period's average temperature using Linear Regression model.
     */
    static double predictLinear(const std::vector<Candlestick>& data);

    /**
     * Predict the next period's average temperature using a Moving Average model.
     * windowSize: number of last periods to average (default 3).
     */
    static double predictMovingAverage(const std::vector<Candlestick>& data, int windowSize = 3);

    /**
     * Predict the next period's average temperature using a heuristic-based model.
     */
    static double predictHeuristic(const std::vector<Candlestick>& data);
};

#endif
