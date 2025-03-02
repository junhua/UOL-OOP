#include "Prediction.h"
#include <cmath>

double Prediction::predictLinear(const std::vector<Candlestick>& data) {
    if (data.empty()) return 0.0;
    
    // TODO: Implement linear regression to fit a line to (index, close) data points and predict next value.
    // 
    // Steps:
    // 1. Calculate the sums needed for the least squares formula:
    //    - Sum of x values (indices)
    //    - Sum of y values (close prices)
    //    - Sum of x*y products
    //    - Sum of x^2 values
    //
    // 2. Calculate the slope (m) using the formula:
    //    m = (N*Σ(x*y) - Σx*Σy) / (N*Σ(x^2) - (Σx)^2)
    //    where N is the number of data points
    //
    // 3. Calculate the y-intercept (b) using the formula:
    //    b = (Σy - m*Σx) / N
    //
    // 4. Predict the next value using the formula:
    //    y = m*x + b
    //    where x is the next index (N)
    
    // For now, just return the last known value as a placeholder
    return data.back().getClose();
}

double Prediction::predictMovingAverage(const std::vector<Candlestick>& data, int windowSize) {
    if (data.empty()) return 0.0;
    
    // TODO: Implement a moving average prediction model
    // 
    // Steps:
    // 1. Determine the actual window size (use the minimum of the requested window size and available data points)
    // 2. Calculate the sum of the closing values for the last 'windowSize' periods
    // 3. Divide the sum by the window size to get the average
    // 4. Return this average as the prediction for the next period
    
    // For now, just return the last known value as a placeholder
    return data.back().getClose();
}

double Prediction::predictHeuristic(const std::vector<Candlestick>& data) {
    if (data.empty()) return 0.0;
    
    // TODO: Implement a simple heuristic-based prediction model
    // 
    // Steps:
    // 1. Check if we have at least 2 data points (otherwise we can't calculate a change)
    // 2. Get the last and second-to-last closing values
    // 3. Calculate the last change (last - secondLast)
    // 4. Predict that the same change will happen again (last + change)
    //
    // Hint: This is a momentum-based approach assuming recent trends will continue
    
    // For now, just return the last known value as a placeholder
    return data.back().getClose();
}
