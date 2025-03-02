#include "Candlestick.h"

Candlestick::Candlestick() : date(""), open(0), close(0), high(0), low(0) {}

Candlestick::Candlestick(const std::string& date, double open, double close, double high, double low)
    : date(date), open(open), close(close), high(high), low(low) {}

std::string Candlestick::getDate() const { return date; }
double Candlestick::getOpen() const { return open; }
double Candlestick::getClose() const { return close; }
double Candlestick::getHigh() const { return high; }
double Candlestick::getLow() const { return low; }
