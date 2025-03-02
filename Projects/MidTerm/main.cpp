#include <iostream>
#include <vector>
#include "DataLoader.h"
#include "CandlestickCalculator.h"
#include "Plotter.h"
#include "DataFilter.h"
#include "Prediction.h"

int main() {
    std::string filename = "weather_data.csv";
    std::string country = "GB";       // Country code (Great Britain in this example)
    int startYear = 1980;
    int endYear = 2019;
    // TODO: Optionally, allow user input for country code and date range instead of hardcoding.

    // 1. Load raw temperature data for the specified country and year range
    std::vector<TemperatureRecord> records = DataLoader::loadCSV(filename, country, startYear, endYear);
    std::cout << "Loaded " << records.size() << " records for " << country 
              << " from " << startYear << " to " << endYear << ".\n";

    // 2. Compute candlestick data (default to yearly aggregation)
    std::vector<Candlestick> candlesticks = CandlestickCalculator::computeCandlesticks(records, TimeFrame::Yearly);
    std::cout << "Computed " << candlesticks.size() << " candlestick entries.\n";

    // 3. Plot the candlestick data as text output
    std::cout << "\nCandlestick chart for " << country << " (" << startYear << "-" << endYear << "):\n";
    Plotter::plotCandlesticks(candlesticks);

    // 4. Demonstrate filtering (e.g., focus on years 2000-2010) and plot the filtered subset
    std::string filterStart = "2000-01-01";
    std::string filterEnd   = "2010-01-01";
    std::vector<Candlestick> filtered = DataFilter::filterByDateRange(candlesticks, filterStart, filterEnd);
    std::cout << "\nCandlestick chart for " << country << " (" << filterStart << " to " << filterEnd << "):\n";
    Plotter::plotCandlesticks(filtered);

    // 5. Predict future temperature trend using different models
    double predLin  = Prediction::predictLinear(candlesticks);
    double predMA   = Prediction::predictMovingAverage(candlesticks, 3);
    double predHeur = Prediction::predictHeuristic(candlesticks);
    std::cout << "\nPredicted next period average temperature for " << country << ":\n";
    std::cout << " Linear Regression model: " << predLin << "\n";
    std::cout << " Moving Average model: " << predMA << "\n";
    std::cout << " Heuristic model: " << predHeur << "\n";
    
    // TODO: Consider enhancing the application with additional features:
    // - Allow user to select which prediction model to use
    // - Implement additional filtering options (by temperature range, trend, etc.)
    // - Add error handling for edge cases
    // - Implement a simple command-line interface for better user interaction
    // - Add the ability to save results to a file

    return 0;
}
