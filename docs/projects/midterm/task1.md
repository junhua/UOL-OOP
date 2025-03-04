---
layout: default
title: Task 1 - Computing Candlestick Data
parent: Midterm Project
nav_order: 1
---

# Task 1: Computing Candlestick Data

This task involves reading temperature data from a CSV file and computing candlestick data for a particular European country between 1980 and 2019.

## Understanding the Data

The temperature data is stored in a CSV file with the following structure:

```
DateTime,AT_temperature,BE_temperature,BG_temperature,...,GB_temperature,...
1980-01-01 00:00:00,3.2,4.5,1.2,...,5.7,...
1980-01-01 06:00:00,2.8,3.9,0.8,...,4.9,...
...
```

Where:
- The first column contains timestamps in "YYYY-MM-DD HH:MM:SS" format
- Each country has its own column with a prefix (e.g., "GB_temperature" for Great Britain)
- Temperature values are in degrees Celsius

## Step 1: Implementing the DataLoader Class

The `DataLoader` class is responsible for reading the CSV file and extracting temperature records for a specific country and date range.

Let's look at the function signature from the header file:

```cpp
// From DataLoader.h
static std::vector<TemperatureRecord> loadCSV(const std::string& filename, 
                                             const std::string& countryCode, 
                                             int startYear, 
                                             int endYear);
```

### CSV Parsing Algorithm

To implement this function, you'll need to:

1. Open the CSV file using `std::ifstream`
2. Read the header row to find the column index for the specified country
3. Process each data row:
   - Extract the date string from the first column
   - Check if the year is within the specified range
   - Extract the temperature value from the country's column
   - Create a `TemperatureRecord` and add it to the result vector

Here's a visual representation of the CSV parsing process:

{% mermaid %}
flowchart TD
    A[Open CSV file] --> B{File opened?}
    B -->|No| C[Return empty vector]
    B -->|Yes| D[Read header row]
    D --> E[Find country column index]
    E --> F{Country found?}
    F -->|No| G[Return empty vector]
    F -->|Yes| H[Read data row]
    H --> I{End of file?}
    I -->|Yes| J[Return data vector]
    I -->|No| K[Extract date]
    K --> L{Year in range?}
    L -->|No| H
    L -->|Yes| M[Extract temperature]
    M --> N[Create record]
    N --> O[Add to vector]
    O --> H
{% endmermaid %}

### Error Handling

Remember to handle potential errors:
- Check if the file was opened successfully
- Validate that the country column exists in the CSV
- Handle invalid data formats (e.g., non-numeric temperature values)

## Step 2: Implementing the CandlestickCalculator Class

The `CandlestickCalculator` class computes candlestick data from the raw temperature records.

Let's look at the function signature from the header file:

```cpp
// From CandlestickCalculator.h
static std::vector<Candlestick> computeCandlesticks(
    const std::vector<TemperatureRecord>& records, 
    TimeFrame timeframe);
```

### Understanding Candlestick Data

A candlestick represents aggregated data for a time period with four key values:
- **Open**: The starting value (average temperature of the previous period)
- **Close**: The ending value (average temperature of the current period)
- **High**: The highest temperature during the period
- **Low**: The lowest temperature during the period

Here's a visual representation of a candlestick:

```
    High
     │
     ┼
     │
     │
  ┌──┴──┐  Open
  │     │
  │     │
  │     │
  └──┬──┘  Close
     │
     │
     ┼
     │
    Low
```

Alternatively, you may use a simpler design:

```
 |   High
 | 
 | 
+++  Close
+++
+++  Open
 | 
 | 
 |   Low
```

### Candlestick Computation Algorithm

To implement this function, you'll need to:

1. Group records by the appropriate time period (year, month, or day)
2. For each group:
   - Calculate the average temperature (Close)
   - Set the Open value to the previous period's Close
   - Find the highest and lowest temperatures (High and Low)
   - Create a Candlestick object with these values

Here's a visual representation of the grouping process:

{% mermaid %}
flowchart TD
    A[Raw Temperature Records] --> B[Group by Timeframe]
    B --> C[Yearly Groups]
    B --> D[Monthly Groups]
    B --> E[Daily Groups]
    C --> F[Compute OHLC for each group]
    D --> F
    E --> F
    F --> G[Create Candlestick objects]
    G --> H[Return Candlestick vector]
{% endmermaid %}

### Special Cases

Remember to handle these special cases:
- For the first period, set Open equal to Close (since there's no previous period)
- Ensure proper date formatting for the candlestick labels
- Handle empty input gracefully

## Data Table Output

You may print a simple tabular representation of the data to justify your completion of task 1:

```
Date   | Open | Close | High | Low  | Trend
-------|------|-------|------|------|------
1980   | 7.5  | 8.2   | 9.1  | 6.3  | UP
1981   | 8.2  | 7.1   | 9.0  | 6.5  | DOWN
1982   | 7.1  | 7.8   | 8.7  | 6.2  | UP
```


## Key Points for Task 1

1. **CSV Parsing**:
   - Identify the correct column for the requested country
   - Extract the date and temperature values
   - Filter by year range

2. **Candlestick Computation**:
   - Group records by the appropriate time period (year, month, or day)
   - Calculate statistics for each group (sum, count, high, low)
   - Set the Open value to the previous period's Close
   - Handle the first period as a special case

3. **Data Structures**:
   - Use `TemperatureRecord` to store raw data
   - Use `Candlestick` to store aggregated data
   - Use vectors to store collections of records

4. **Error Handling**:
   - Check for empty input
   - Handle file opening errors
   - Validate country code existence in the CSV

## Navigation

- [Back to Project Overview](index.html)
- [Next: Task 2 - Text-Based Candlestick Plot](task2.html)
