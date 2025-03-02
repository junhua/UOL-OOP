#include "Plotter.h"
#include <iostream>
#include <iomanip>

void Plotter::plotCandlesticks(const std::vector<Candlestick>& candlesticks) {
    if (candlesticks.empty()) {
        std::cout << "No candlestick data to plot.\n";
        return;
    }

    // TODO: Generate an ASCII art candlestick chart representing the data.
    // For now, we will print each Candlestick's values and indicate trend with an arrow.
    for (const auto& c : candlesticks) {
        bool up = c.getClose() >= c.getOpen();
        char trendChar = up ? '^' : 'v';  // '^' if temperature went up, 'v' if went down
        std::cout << c.getDate()
                  << " O:" << c.getOpen() << " C:" << c.getClose()
                  << " H:" << c.getHigh() << " L:" << c.getLow()
                  << " " << trendChar << std::endl;
    }

    // TODO: Replace the above with a true candlestick plot using characters like '|' and '-' for stalks and boxes.
    // Hint: You might determine a vertical scale based on min and max temperature, and draw each candlestick column accordingly.
}
