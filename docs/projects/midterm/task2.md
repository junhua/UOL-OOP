---
layout: default
title: Task 2 - Text-Based Candlestick Plot
parent: Midterm Project
nav_order: 2
---

# Task 2: Text-Based Candlestick Plot

This task involves creating a text-based candlestick chart to visualize the computed candlestick data.

## Step 1: Understanding Candlestick Visualization

A candlestick chart represents four key values for each time period:
- **Open**: The starting value (average temperature of the previous period)
- **Close**: The ending value (average temperature of the current period)
- **High**: The highest value during the period
- **Low**: The lowest value during the period

In a traditional candlestick chart:
- The "body" of the candlestick represents the range between Open and Close
- The "wick" or "shadow" extends to the High and Low values
- The body is often filled/colored differently depending on whether Close > Open (up) or Close < Open (down)

Here's what a typical candlestick chart looks like:

```
Temperature
35.3 | |   |   |              
32.3 | |   |   |   |   |   |  
29.3 | |   |   |   |   |   |  
26.4 | |   |   |   |   |   |  
23.4 | |   |   |   |   |   |  
20.4 | |   |   |   |   |   |  
17.5 | |   |   |   |   |   |  
14.5 |+++ ---  |   |  +++ --- 
11.6 | |  --- +++ --- +++ --- 
8.64 | |   |   |   |   |   |  
5.68 | |   |   |   |   |   |  
2.71 | |   |   |   |   |   |  
-0.2 | |   |   |   |   |   |  
-3.2 | |   |   |   |   |   |  
-6.1 |     |       |          
-9.1 |     |                  
------------------------------
1990 1991 1992 1993 1994 1995 
```

In this ASCII representation:
- The vertical line represents the High-Low range (the "wick")
- The +++ or --- signs represent the Open-Close range (the "body")
- The + or - symbols can indicate whether the temperature rose or fell

## Step 2: Implementing the Plotter Class

The `Plotter` class needs to generate a text-based representation of the candlestick chart. Let's look at the function signature from the header file:

```cpp
// From Plotter.h
static void plotCandlesticks(const std::vector<Candlestick>& candlesticks);
```

### Visualization Algorithm

To implement this function, you'll need to:

1. Find the minimum and maximum temperatures across all candlesticks
2. Determine the chart dimensions and scale
3. Create a 2D grid to represent the chart
4. For each candlestick:
   - Calculate the row positions for Open, Close, High, and Low
   - Draw the vertical wick from High to Low
   - Draw the body from Open to Close with appropriate characters
5. Add temperature labels on the left axis
6. Add date labels at the bottom

Here's a visual representation of the process:

{% mermaid %}
flowchart TD
    %% Main sections with styling
    subgraph Initialization ["Initialization"]
        direction TB
        A["Find min/max temperatures"] --> B["Calculate scale"]
        B --> C["Create empty chart grid"]
        C --> D["Add temperature labels"]
    end

    subgraph Processing ["Data Processing"]
        direction TB
        E["For each candlestick"] --> F["Calculate row positions"]
        F --> G["Draw wick"]
        G --> H["Draw body"]
    end

    subgraph Output ["Output Generation"]
        direction TB
        J["Print chart"] --> K["Print date labels"]
    end

    %% Connect sections with styled edges
    Initialization --> Processing
    Processing --> I{More candlesticks?}
    I -->|Yes| E
    I -->|No| Output

    %% Style definitions
    classDef initialization fill:#d4f1f9,stroke:#05a8e6,stroke-width:2px
    classDef processing fill:#ffe6cc,stroke:#ff9900,stroke-width:2px
    classDef output fill:#e6ffcc,stroke:#70c030,stroke-width:2px
    classDef decision fill:#f8cecc,stroke:#b85450,stroke-width:2px,color:#333

    %% Apply styles
    class Initialization initialization
    class Processing processing
    class Output output
    class I decision
{% endmermaid %}

### Chart Scaling

The key to a good visualization is proper scaling. You'll need to map temperature values to row positions in your chart:

```
Row position = (maxTemp - temperature) / tempPerRow
```

Where:
- `maxTemp` is the highest temperature in your dataset
- `tempPerRow` is the temperature range represented by each row
- The result is the row index from the top of the chart


## Implementation Tips

1. **Start Simple**: Begin with a basic implementation and gradually enhance it
2. **Handle Edge Cases**: Check for empty input and ensure proper bounds checking
3. **Use Constants**: Define chart dimensions as constants for easy adjustment
4. **Test Incrementally**: Test with small datasets first to verify your visualization logic

## Key Points for Task 2

1. **Chart Scaling**:
   - Determine the temperature range (min to max)
   - Calculate the vertical scale (temperature per row)
   - Map temperature values to row positions

2. **Candlestick Representation**:
   - Use '\|' for the wick (High to Low)
   - Use characters like '+', '#', or '█' to fill the body
   - Use different characters for up trends vs. down trends

3. **Chart Layout**:
   - Include a temperature axis on the left
   - Include date labels at the bottom
   - Ensure proper spacing between candlesticks

4. **Simplification Options**:
   - Start with a tabular representation if ASCII art is challenging
   - Gradually enhance the visualization as you progress

## Navigation

- [Back to Project Overview](index.html)
- [Previous: Task 1 - Computing Candlestick Data](task1.html)
- [Next: Task 3 - Filtering Data](task3.html)
