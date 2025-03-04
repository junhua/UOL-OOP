---
layout: default
title: Midterm Project
parent: Projects
nav_order: 1
---

# Weather Data Analysis and Prediction Project

This guide provides a comprehensive walkthrough for implementing the Weather Data Analysis and Prediction project. The project involves processing historical temperature data, visualizing it using candlestick charts, filtering data based on criteria, and implementing prediction models to forecast future temperature trends.

## Project Overview

The Weather Data Analysis and Prediction project is designed to analyze temperature data for European countries between 1980 and 2019. The application will:

1. Read temperature data from a CSV file
2. Compute candlestick data (Open, High, Low, Close) for temperature readings
3. Create text-based candlestick plots to visualize the data
4. Filter data by date range and country
5. Predict future temperature trends using multiple models

## Key Requirements

1. **Data Processing**:
   - Parse CSV files containing temperature data
   - Filter data by country and date range
   - Aggregate data into different timeframes (yearly, monthly, daily)

2. **Candlestick Computation**:
   - Calculate Open, High, Low, Close values for each time period
   - Open: Average temperature of the previous period
   - Close: Average temperature of the current period
   - High: Maximum temperature in the current period
   - Low: Minimum temperature in the current period

3. **Visualization**:
   - Create text-based candlestick charts
   - Represent temperature data visually using ASCII characters
   - Show trends clearly (rising vs. falling temperatures)

4. **Filtering**:
   - Filter data by date range
   - Filter by country

5. **Prediction**:
   - Implement at least three prediction models:
     - Linear Regression
     - Moving Average
     - Heuristic-based

## Project Structure

The project is organized into several classes, each with a specific responsibility:

1. **Candlestick**: Represents aggregated temperature data for a time period
2. **DataLoader**: Reads and parses CSV data
3. **CandlestickCalculator**: Computes candlestick data from raw temperature records
4. **Plotter**: Generates text-based candlestick charts
5. **DataFilter**: Filters candlestick data based on criteria
6. **Prediction**: Implements prediction models for forecasting

## Things to Note

1. **CSV Format**:
   - The CSV file contains temperature data for multiple countries
   - Each country has its own column with a prefix (e.g., "GB_temperature")
   - The first column contains timestamps in the format "YYYY-MM-DD HH:MM:SS"

2. **Data Aggregation**:
   - When aggregating data, you need to track the previous period's average to use as the Open value
   - For the first period, you may set Open equal to Close as an initial value

3. **Text-Based Plotting**:
   - ASCII art requires careful planning of the vertical scale
   - Consider using characters like '\|' for the candlestick's wick and '-' or '+' for the body

4. **Error Handling**:
   - Handle missing data gracefully
   - Check for file existence before attempting to read
   - Validate user inputs for filtering

5. **Performance Considerations**:
   - Large CSV files may require efficient parsing strategies
   - Consider memory usage when processing large datasets

## Implementation Tasks

- [Task 1: Computing Candlestick Data](task1.html)
- [Task 2: Text-Based Candlestick Plot](task2.html)
- [Task 3: Filtering Data](task3.html)
- [Task 4: Prediction Models](task4.html)
