---
layout: default
title: Improvement Suggestions
parent: Projects
nav_order: 6
---

# Taking Your Midterm Project to the Next Level: Grade-Boosting Strategies

Hopefully, you are able to follow the earlier guide to implement the core features of the project. Otherwise, please focus on building up the core parts instead of going ahead. 

This guide provides concrete suggestions to help you maximize your grade on the midterm project. Below are potential improvements that can help you earn more points in each category, according to the rubrics.

## Understanding the Grading Breakdown

Before diving into improvements, let's understand where the points come from:

| Category | Points |
|----------|--------|
| Task 1: Compute candlestick data (Code + Description) | 16 |
| Task 2: Text-based plot (Code + Description) | 16 |
| Task 3: Filtering and plotting (Code + Description) | 16 |
| Task 4: Prediction models (Code + Description) | 16 |
| Code style: indentation, descriptive comments | 6 |
| Originality and challenge of implementation | 10 |
| Clearly labeled code sections | 6 |
| Submission requirements | 4 |
| Video demonstration | 10 |
| **TOTAL** | **100** |

## Task 1: Compute Candlestick Data (16 points)

### Code Implementation (10 points)

1. **Robust CSV Parsing**

   CSV parsing is a critical foundation of your project, and robust error handling can significantly improve your grade by demonstrating professional coding practices. Many students lose points by assuming ideal conditions, but real-world data is often messy.

   - **File Operation Error Handling**: Always check if a file was successfully opened before attempting to read from it. This prevents your program from crashing when the file doesn't exist or can't be accessed:
     ```
     // TODO: Implement file opening with error handling
     open_file(filename)
     if file_not_opened then
         display error message
         return empty_collection
     end if
     ```
     This approach not only prevents crashes but also provides meaningful feedback to the user, which is essential for a good user experience.

   - **Country Code Validation**: Don't assume the requested country exists in the dataset. Validate it and provide appropriate feedback:
     ```
     // TODO: Implement country code validation
     if country_not_found then
         display error message
         return empty_collection
     end if
     ```
     This validation is particularly important because the project requires filtering by country, and handling missing countries gracefully demonstrates attention to detail.

   - **Malformed Data Handling**: Real-world data often contains errors. Use try-catch blocks to handle conversion errors gracefully:
     ```
     // TODO: Implement data validation with error handling
     try
         convert string to number
     catch invalid_format
         display warning message
         skip current record
     end try
     ```
     This approach allows your program to continue processing even when encountering bad data, which is a hallmark of robust software.

2. **Optimized Candlestick Class Design**

   The Candlestick class is central to your project, and a well-designed class demonstrates your understanding of object-oriented principles. The grading criteria specifically mentions code style and organization.

   - **Encapsulation with Private Members**: Follow proper encapsulation by making data members private and providing public getters. This prevents accidental modification of your data:
     ```
     // TODO: Create Candlestick class with proper encapsulation
     class Candlestick
         // Private members
         date, open, close, high, low
         
         // Public interface
         constructor
         getters for all properties
     end class
     ```
     This design pattern is a fundamental OOP principle that will earn you points for code style and organization.

   - **Constructor Validation**: Ensure data consistency by validating values in your constructor. This prevents impossible candlestick data (like a "high" value that's lower than the "low" value):
     ```
     // TODO: Implement constructor with data validation
     constructor(date, open, close, high, low)
         // Validate data consistency
         ensure high is maximum of all values
         ensure low is minimum of all values
         set all properties
     end constructor
     ```
     This validation demonstrates attention to detail and understanding of the domain, which can earn points for both code implementation and originality.

3. **Flexible Time Aggregation**

   The project requires handling different timeframes (yearly, monthly, daily). Using design patterns to implement this flexibility demonstrates advanced programming skills and can earn points for originality and challenge.

   - **Strategy Pattern Implementation**: Use the Strategy pattern to make your code more flexible and extensible:
     ```
     // TODO: Implement Strategy pattern for time frame handling
     class TimeFrameStrategy
         // Abstract method for getting group key
         abstract getGroupKey(dateStr)
     end class
     
     class YearlyStrategy extends TimeFrameStrategy
         getGroupKey(dateStr)
             // TODO: Extract year portion from date string
             return year_portion
         end method
     end class
     
     class MonthlyStrategy extends TimeFrameStrategy
         getGroupKey(dateStr)
             // TODO: Extract year and month portion from date string
             return year_month_portion
         end method
     end class
     ```
     This approach allows you to easily add new timeframes without modifying existing code, demonstrating your understanding of the Open-Closed Principle.

   - **Using the Strategy**: Implement the candlestick computation to use the strategy:
     ```
     // TODO: Implement candlestick computation with strategy pattern
     function computeCandlesticks(records, strategy)
         // Group records by time period using strategy
         // Calculate OHLC values for each group
         // Return collection of candlesticks
     end function
     ```
     This implementation shows how you can make your code more flexible and maintainable, which can earn points for originality and challenge.

### Description (6 points)

1. **Document Your Approach**

   The project requires a detailed description of your implementation. A well-documented approach demonstrates your understanding of the problem and solution.

   - **Algorithm Explanation**: Clearly explain how your candlestick computation works, step by step. For example:
     "The candlestick computation algorithm works by first grouping temperature records by time period (year, month, or day) using the strategy pattern. For each group, it calculates the average temperature (Close), finds the highest and lowest temperatures (High and Low), and uses the previous period's Close as the current period's Open. For the first period, Open is set equal to Close."

   - **Edge Case Handling**: Describe how you handle special cases:
     "For the first candlestick, there is no previous period to use for the Open value. In this case, I set Open equal to Close to ensure consistency. For empty datasets, the function returns an empty vector and logs a warning message."

   - **Design Justification**: Explain why you made certain design choices:
     "I chose to implement the Strategy pattern for timeframe handling because it allows for easy extension to new timeframes without modifying existing code. This adheres to the Open-Closed Principle and makes the code more maintainable."

2. **Include Diagrams**

   Visual representations can significantly enhance your description and demonstrate your thorough understanding of the system.

   - **Data Processing Flowchart**: Create a flowchart showing how data moves through your system:
     "Figure 1 shows the data flow from CSV parsing to candlestick computation. Raw temperature records are first filtered by country and date range, then grouped by timeframe, and finally aggregated into candlestick data."

   - **Class Relationship Diagram**: Include a UML diagram showing how your classes interact:
     "Figure 2 illustrates the relationship between the Candlestick class, TimeFrameStrategy interface, and concrete strategy implementations. This design allows for flexible timeframe handling while maintaining clean separation of concerns."

## Task 2: Text-Based Plot (16 points)

### Code Implementation (10 points)

1. **Adaptive Scaling Algorithm**

   A key challenge in creating text-based charts is determining the appropriate scale. Many students use fixed heights, which can result in charts that are either too compressed or too sparse. An adaptive scaling algorithm adjusts the chart dimensions based on the data range.

   ```
   // TODO: Implement adaptive scaling algorithm
   calculate temperature range
   determine appropriate chart height based on range
   calculate temperature value per chart row
   ```

   This algorithm:
   - Calculates the temperature range in your dataset
   - Sets a chart height proportional to this range (2 rows per degree)
   - Enforces minimum (10) and maximum (20) heights to ensure readability
   - Calculates how many degrees each row represents

   This approach ensures your chart is always readable regardless of the temperature range, demonstrating thoughtful design that adapts to different datasets.

2. **Enhanced Visual Clarity**

   The project brief asks for a text-based plot, but many students create basic charts that are difficult to interpret. Adding visual enhancements can significantly improve readability and earn points for originality.

   - **Differentiate Up/Down Trends**: Use different characters to clearly show whether temperatures are rising or falling:
     ```
     // TODO: Implement visual differentiation for trends
     if closing_temperature >= opening_temperature then
         use uptrend character
     else
         use downtrend character
     end if
     ```
     This makes it immediately obvious which periods saw temperature increases ('+') versus decreases ('#'), providing valuable visual information at a glance.

   - **Formatted Temperature Scale**: Add a properly formatted temperature scale to make your chart more professional:
     ```
     // TODO: Implement formatted temperature scale
     for each row in chart
         calculate temperature for this row
         format temperature with fixed precision and width
         add formatted temperature and separator to chart row
     end for
     ```
     This code:
     - Uses fixed-point notation for consistent decimal places
     - Sets precision to one decimal place for temperatures
     - Aligns all temperature labels with consistent width
     - Adds a vertical line to separate the scale from the chart

   - **Clear Date Labels**: Format date labels for better readability:
     ```
     // TODO: Implement date labels for chart
     add spacing to align with temperature scale
     for each candlestick
         format and display date label
     end for
     ```
     This ensures dates are properly aligned with their corresponding candlesticks.

3. **Multiple Visualization Options**

   The project only requires a candlestick chart, but implementing multiple visualization options demonstrates initiative and can earn points for originality and challenge.

   ```
   // TODO: Implement multiple visualization options
   define chart types (Candlestick, Line, Table)
   
   function plot(data, chartType)
       // Select appropriate plotting method based on type
       if chartType is Candlestick then
           plot candlestick chart
       else if chartType is Line then
           plot line chart
       else if chartType is Table then
           display data as table
       end if
   end function
   ```

   This approach:
   - Provides flexibility for different visualization needs
   - Demonstrates your understanding of the Strategy pattern
   - Shows initiative beyond the basic requirements

   Implementing a line chart option can be particularly useful for showing trends more clearly:
   ```
   // TODO: Implement line chart visualization
   function plotLine(data)
       // Setup chart dimensions and scaling
       // For each data point after the first
       //   Draw line connecting previous close value to current close value
   end function
   ```

### Description (6 points)

1. **Explain Visualization Choices**

   Your report should clearly explain the reasoning behind your visualization decisions to demonstrate your understanding of data visualization principles.

   - **Character Selection Justification**: Explain why you chose specific characters:
     "I selected '+' for upward trends and '#' for downward trends because these characters have visual properties that intuitively represent their meanings. The '+' symbol suggests addition or increase, while the denser '#' symbol suggests a heavier or declining value. This makes the chart immediately interpretable without requiring a legend."

   - **Scaling Algorithm Explanation**: Describe your approach to scaling:
     "My adaptive scaling algorithm ensures the chart is always readable regardless of the temperature range. It calculates an appropriate height based on the data range, with approximately 2 rows per degree Celsius. This provides sufficient detail for small temperature variations while preventing excessive height for large ranges. I enforce minimum and maximum heights (10-20 rows) to ensure the chart remains usable across all datasets."

   - **Edge Case Handling**: Explain how you handle special cases:
     "For empty datasets, the function displays a 'No data to plot' message rather than attempting to create an empty chart. For datasets with a single point, the chart still displays correctly by setting both the minimum and maximum temperature to that single value with a small buffer to ensure visibility."


## Task 3: Filtering and Plotting (16 points)

### Code Implementation (10 points)

1. **Comprehensive Filter Framework**

   The project requires implementing at least two filter options. Creating a well-designed filter framework demonstrates your understanding of object-oriented design principles and can earn points for both implementation and originality.

   ```
   // TODO: Implement filter framework using Strategy pattern
   class Filter
       // Abstract method to check if candlestick matches criteria
       abstract matches(candlestick)
   end class
   
   class DateRangeFilter extends Filter
       // Private members
       startDate, endDate
       
       constructor(startDate, endDate)
           initialize members
       end constructor
       
       matches(candlestick)
           // TODO: Check if candlestick date is within range
           return date_is_within_range
       end method
   end class
   ```

   This approach:
   - Uses the Strategy pattern to define a common interface for all filters
   - Encapsulates filter criteria within specific filter classes
   - Makes it easy to add new filter types without modifying existing code
   - Follows the Single Responsibility Principle by giving each filter class one job

   The abstract `Filter` interface provides a clean way to implement the required filtering functionality while demonstrating good software design principles. This approach is much more sophisticated than implementing filtering directly in the main function, which many students might do.

2. **Composable Filters**

   Going beyond the basic requirements, implementing composable filters demonstrates advanced programming skills and can earn points for originality and challenge.

   ```
   // TODO: Implement composite filters for complex criteria
   class AndFilter extends Filter
       // Private members
       leftFilter, rightFilter
       
       constructor(leftFilter, rightFilter)
           initialize members
       end constructor
       
       matches(candlestick)
           // TODO: Return true only if both filters match
           return leftFilter.matches(candlestick) AND rightFilter.matches(candlestick)
       end method
   end class
   
   class OrFilter extends Filter
       // Private members
       leftFilter, rightFilter
       
       constructor(leftFilter, rightFilter)
           initialize members
       end constructor
       
       matches(candlestick)
           // TODO: Return true if either filter matches
           return leftFilter.matches(candlestick) OR rightFilter.matches(candlestick)
       end method
   end class
   ```

   This implementation:
   - Uses the Composite pattern to create complex filters from simple ones
   - Allows for logical combinations (AND, OR) of different filter criteria
   - Demonstrates understanding of advanced design patterns
   - Creates a flexible system that can handle complex filtering requirements

   For example, you could create a filter that finds candlesticks within a date range AND with high volatility:
   ```
   // TODO: Create and combine filters
   create dateFilter for range 2000-01-01 to 2010-12-31
   create volatilityFilter with threshold 2.0
   create combinedFilter that requires both conditions
   ```

3. **Additional Filter Types**

   While the DateRangeFilter is a good starting point, implementing additional filter types demonstrates a deeper understanding of the domain and can earn points for originality and challenge. One particularly useful filter for temperature data is the TemperatureRangeFilter.

   ```
   // TODO: Implement temperature range filter with multiple modes
   class TemperatureRangeFilter extends Filter
       // Private members
       minTemp, maxTemp
       comparisonMode (CLOSE, HIGH, LOW, OPEN, ANY, ALL)
       
       // Constructors
       constructor(min, max) with default mode
       constructor(min, max, mode) with specified mode
       
       matches(candlestick)
           // TODO: Check if temperature values match criteria based on mode
           // For CLOSE mode: check if close value is in range
           // For HIGH mode: check if high value is in range
           // For LOW mode: check if low value is in range
           // For OPEN mode: check if open value is in range
           // For ANY mode: check if any value is in range
           // For ALL mode: check if all values are in range
       end method
       
       // Factory methods
       static createHeatWaveFilter(threshold)
           // TODO: Create filter for high temperatures
       end method
       
       static createColdSnapFilter(threshold)
           // TODO: Create filter for low temperatures
       end method
   end class
   ```

   This implementation:
   - Allows filtering based on temperature ranges (e.g., 20-25°C)
   - Provides flexibility to check different temperature metrics (Open, High, Low, Close)
   - Includes advanced modes to check if ANY or ALL values are within range
   - Offers factory methods for common scenarios like heat waves and cold snaps
   - Demonstrates good object-oriented design with encapsulation and polymorphism

   You could extend this further with variations like:

   ```
   // TODO: Implement relative temperature filter
   class RelativeTemperatureFilter extends Filter
       // Private members
       baselineTemp, deviation, above
       
       constructor(baseline, deviation, isAbove)
           initialize members
       end constructor
       
       matches(candlestick)
           // TODO: Check if temperature deviates from baseline
           if checking for above baseline then
               return close >= (baseline + deviation)
           else
               return close <= (baseline - deviation)
           end if
       end method
       
       // Factory method
       static createAboveAverageFilter(data, deviationAmount)
           // TODO: Calculate average temperature from data
           // Create filter for temperatures above average by specified amount
       end method
   end class
   ```

   This relative filter allows you to find periods where temperatures deviate significantly from a baseline (such as a historical average), which is particularly useful for identifying anomalies or climate change trends.

1. **Document Filter Design**

   Your report should clearly explain your filter architecture to demonstrate your understanding of software design principles.

   - **Filter Architecture Explanation**: Describe your overall approach:
     "I implemented a filter framework using the Strategy pattern, which defines a common interface for all filters. This design allows for easy extension with new filter types without modifying existing code, adhering to the Open-Closed Principle. Each concrete filter class encapsulates specific filtering logic while maintaining a consistent interface."

   - **Composition Mechanism**: Explain how filters can be combined:
     "To support complex filtering scenarios, I implemented the Composite pattern through AndFilter and OrFilter classes. These composite filters contain references to other filters and combine their results using logical operations. This allows users to create sophisticated queries by combining simple filters, similar to how SQL WHERE clauses work."

   - **Design Justification**: Explain why you made certain design choices:
     "I chose this approach over simpler alternatives (like hardcoded filtering functions) because it provides greater flexibility and extensibility. The object-oriented design makes it easy to add new filter types without changing existing code, and the composition mechanism allows for arbitrarily complex filter combinations. This design also separates the filtering logic from the data processing and visualization components, improving code organization and maintainability."

2. **Provide Usage Examples**

   Including concrete examples in your report helps demonstrate the practical benefits of your design.

   - **Basic Filter Usage**: Show how to create and apply simple filters:
     ```
     // TODO: Implement basic filter usage
     // Create date range filter
     create dateFilter for years 2000-2010
     
     // Apply filter to data (method 1)
     create empty result collection
     for each candlestick in data
         if candlestick matches filter criteria then
             add to result collection
         end if
     end for
     
     // Alternative implementation (method 2)
     // TODO: Use language-specific collection filtering function
     ```

   - **Complex Filter Combinations**: Demonstrate how to create and use composite filters:
     ```
     // TODO: Implement complex filter combinations
     // Create individual filters
     create summerFilter for June-August months
     create warmFilter for temperatures above 25°C
     create volatilityFilter for high temperature variations
     
     // Combine filters
     combine summerFilter AND warmFilter
     combine result with volatilityFilter
     
     // Apply combined filter
     create empty result collection
     for each candlestick in data
         if candlestick matches combined filter then
             add to result collection
         end if
     end for
     ```

   - **Filter Application Utility**: Show a helper function that applies filters:
     ```
     // TODO: Implement filter application utility
     function applyFilter(data, filter)
         create empty result collection
         add all items from data that match filter criteria
         return result collection
     end function
     
     // Usage
     filtered_data = applyFilter(candlesticks, dateFilter)
     ```

## Task 4: Prediction Models (16 points)

### Code Implementation (10 points)

1. **Robust Prediction Models**

   The project requires implementing at least three prediction models. Going beyond basic implementation to include confidence metrics demonstrates a deeper understanding of prediction techniques and can earn points for originality.

   ```
   // TODO: Implement prediction model with confidence metrics
   structure PredictionResult
       prediction value
       confidence metric
       model name
   end structure
   
   function predictLinearWithConfidence(data)
       // Check for sufficient data
       if data size < 2 then
           return result with error indication
       end if
       
       // TODO: Calculate linear regression using least squares method
       // 1. Initialize sum variables
       // 2. Calculate sums for x, y, xy, x², y²
       // 3. Calculate slope and intercept
       // 4. Calculate prediction for next period
       
       // TODO: Calculate confidence metric (R²)
       // 1. Calculate mean of y values
       // 2. Calculate total sum of squares
       // 3. Calculate residual sum of squares
       // 4. Calculate R² = 1 - (residual SS / total SS)
       
       return result with prediction, confidence, and model name
   end function
   ```

   This implementation:
   - Calculates a prediction using linear regression
   - Computes the R² value to indicate how well the model fits the data
   - Returns both the prediction and a confidence metric
   - Handles edge cases (insufficient data)
   - Provides a descriptive model name

   The addition of confidence metrics demonstrates a more sophisticated understanding of prediction models and provides valuable context for interpreting the results.

2. **Cross-Validation**

   Cross-validation is not required by the project, but implementing it shows advanced knowledge of model evaluation techniques and can earn points for originality and challenge.

   ```
   // TODO: Implement cross-validation for model evaluation
   function validateModel(data, modelFunction)
       // Check for sufficient data
       if data size < 4 then
           return error code
       end if
       
       // TODO: Perform leave-one-out cross-validation
       // 1. Initialize error accumulator
       // 2. For each point after minimum required:
       //    a. Create training data from all previous points
       //    b. Generate prediction using model function
       //    c. Compare with actual value
       //    d. Add absolute error to accumulator
       
       // Calculate and return mean absolute error
       return totalError / number_of_predictions
   end function
   ```

   This implementation:
   - Uses leave-one-out cross-validation to assess model accuracy
   - Calculates the mean absolute error (MAE) as a performance metric
   - Handles edge cases (insufficient data)
   - Accepts any prediction model via a function pointer, demonstrating flexible design

   Cross-validation is a standard technique in machine learning for evaluating model performance. Implementing it shows that you understand the importance of validating predictions rather than just generating them.

3. **Ensemble Model**

   The project requires three prediction models, but implementing an ensemble model that combines them demonstrates advanced knowledge and can earn points for originality.

   ```
   // TODO: Implement ensemble prediction model
   function predictEnsemble(data)
       // Check for sufficient data
       if data size < 2 then
           return fallback prediction
       end if
       
       // TODO: Get predictions from individual models
       // 1. Linear regression prediction
       // 2. Moving average prediction
       // 3. Heuristic prediction
       
       // TODO: Validate each model to determine weights
       // 1. Create function references for each model
       // 2. Calculate error metrics for each model
       
       // TODO: Handle validation failures
       // If any validation fails, use equal weights
       
       // TODO: Convert errors to weights
       // 1. Calculate total error
       // 2. Convert errors to weights (smaller error = higher weight)
       // 3. Normalize weights to sum to 1
       
       // Calculate and return weighted average prediction
       return weighted_sum_of_predictions
   end function
   ```

   This implementation:
   - Combines predictions from all three models
   - Uses cross-validation to determine optimal weights
   - Handles edge cases and potential division by zero
   - Dynamically adjusts weights based on each model's historical accuracy

   Ensemble methods are widely used in machine learning because they often outperform individual models. Implementing an ensemble approach demonstrates sophisticated understanding of prediction techniques.

### Description (6 points)

1. **Justify Model Selection**

   Your report should clearly explain why you chose specific prediction models and how they work, demonstrating your understanding of forecasting techniques.

   - **Model Selection Rationale**: Explain why you chose each model:
     "I implemented three complementary prediction models, each with different strengths. The linear regression model captures long-term trends by fitting a straight line to historical data. The moving average model reduces the impact of short-term fluctuations by averaging recent values. The heuristic model is responsive to recent changes, assuming that the most recent trend will continue."

   - **Strengths and Weaknesses Analysis**: Discuss the tradeoffs of each model:
     "The linear regression model performs well when there's a consistent long-term trend but may miss cyclical patterns or recent changes. The moving average model effectively smooths out noise but lags behind when there are sudden shifts in the data. The heuristic model responds quickly to recent changes but can be overly sensitive to anomalies in the most recent data points."

   - **Mathematical Foundation**: Explain the mathematical basis of your models:
     "The linear regression model uses the least squares method to find the line that minimizes the sum of squared differences between observed and predicted values. The formula for the slope is m = (n*Σxy - Σx*Σy)/(n*Σx² - (Σx)²), and for the y-intercept is b = (Σy - m*Σx)/n. The moving average simply takes the mean of the last n values. The heuristic model extrapolates based on the most recent change: prediction = last + (last - secondLast)."

2. **Include Error Analysis**

   A thorough error analysis demonstrates your critical thinking about the models' performance and limitations.

   - **Comparative Accuracy**: Compare how well each model performs:
     "I evaluated each model using leave-one-out cross-validation on the historical data. The linear regression model achieved a mean absolute error of 0.42°C, the moving average model 0.38°C, and the heuristic model 0.51°C. The moving average performed best overall, but the linear regression was more accurate for longer-term predictions."

   - **Factors Affecting Prediction Quality**: Discuss what influences prediction accuracy:
     "Several factors affected prediction quality. The amount of historical data had a significant impact—models performed better with at least 10 data points. Seasonal temperature patterns created challenges for the linear model, while sudden temperature shifts reduced the accuracy of the moving average. The heuristic model was particularly sensitive to anomalous years."

   - **Visualization of Predictions**: Include charts comparing predictions:
     "Figure 4 shows the actual temperatures (black) alongside predictions from the linear model (blue), moving average (green), and heuristic model (red) for the years 2010-2019. The chart illustrates how the linear model captures the overall warming trend, while the moving average provides more stable predictions, and the heuristic model sometimes overreacts to year-to-year fluctuations."

   - **Future Improvements**: Suggest ways to enhance the models:
     "Future improvements could include implementing seasonal adjustment to account for cyclical patterns, developing a polynomial regression model for non-linear trends, and creating a more sophisticated ensemble method that dynamically adjusts weights based on recent performance. Additionally, incorporating external factors like El Niño/La Niña cycles could improve prediction accuracy."

## Code Style (6 points)

Code style is often overlooked, but it accounts for 6% of your grade and is one of the easiest areas to score full points. Professional code style demonstrates your attention to detail and understanding of software engineering best practices.

1. **Consistent Formatting**

   Consistent formatting makes your code more readable and maintainable. The grading criteria specifically mentions indentation and descriptive comments.

   - **Consistent Indentation**: Choose a standard indentation style and apply it consistently:
     ```cpp
     // TODO: Use consistent indentation
     // Good example:
     if condition then
         doSomething()
         if nestedCondition then
             doSomethingElse()
         end if
     end if
     
     // Bad example - avoid inconsistent indentation:
     if condition then
       doSomething()
         if nestedCondition then
           doSomethingElse()
         end if
     end if
     ```
     Most modern IDEs can automatically format your code. Consider using a tool like `clang-format` to ensure consistency across all files.

   - **Naming Conventions**: Follow standard C++ naming conventions:
     ```cpp
     // Class names: PascalCase
     class TemperatureAnalyzer {};
     
     // Methods/functions: camelCase
     double calculateAverage(const std::vector<double>& values);
     
     // Variables: camelCase
     int numberOfRecords = 0;
     
     // Constants: UPPER_SNAKE_CASE
     const int MAX_ITERATIONS = 100;
     ```
     Consistent naming makes your code more predictable and easier to understand. It also demonstrates your familiarity with industry standards.

   - **Brace Style**: Choose a brace style and apply it consistently:
     ```cpp
     // K&R style (common in C++)
     if (condition) {
         statement;
     } else {
         otherStatement;
     }
     ```
     The specific style matters less than consistency throughout your code.

2. **Comprehensive Comments**

   Good comments explain why code exists, not just what it does. The code itself should be clear enough to show what it's doing, but comments should provide context and reasoning.

   - **File Headers**: Include a descriptive header at the top of each file:
     ```cpp
     /**
      * @file DataLoader.cpp
      * @brief Implementation of the DataLoader class for reading temperature data
      * @author Your Name
      * @date 2025-02-28
      */
     ```
     File headers provide a quick overview of the file's purpose and ownership, which is particularly important in a graded project where you need to clearly indicate your work.

   - **Class and Method Documentation**: Document the purpose and behavior of classes and methods:
     ```cpp
     /**
      * @brief Computes candlestick data from raw temperature records
      * @param records Vector of temperature records
      * @param timeframe Aggregation timeframe (Yearly, Monthly, Daily)
      * @return Vector of Candlestick objects
      * 
      * Groups temperature records by the specified timeframe and calculates
      * Open, High, Low, Close values for each period.
      */
     std::vector<Candlestick> computeCandlesticks(...);
     ```
     This documentation style follows the Javadoc/Doxygen format, which is widely used in C++ projects. It clearly describes what the function does, its parameters, and its return value.

   - **Algorithm Explanations**: Add comments to explain complex algorithms or non-obvious code:
     ```cpp
     // Linear regression using least squares method:
     // 1. Calculate sums for x, y, xy, x²
     // 2. Compute slope (m) and intercept (b)
     // 3. Predict using y = mx + b
     
     // Calculate sums
     double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
     for (int i = 0; i < data.size(); i++) {
         double x = i;
         double y = data[i].getClose();
         sumX += x;
         sumY += y;
         sumXY += x * y;
         sumX2 += x * x;
     }
     ```
     These comments help readers understand your implementation approach without having to decipher complex code. They're particularly important for mathematical algorithms like those used in prediction models.

   - **TODO Comments**: Use TODO comments to indicate areas for future improvement:
     ```cpp
     // TODO: Implement seasonal adjustment to improve prediction accuracy
     ```
     These comments show that you're aware of potential improvements even if you haven't implemented them yet. They demonstrate forward thinking and an understanding of the domain.

## Originality and Challenge (10 points)

The "Originality and challenge of implementation" category is worth 10% of your grade and offers an excellent opportunity to showcase your creativity and technical skills. This section rewards going beyond the basic requirements to create something unique and sophisticated.

1. **Implement Advanced Features**

   Adding features beyond the basic requirements demonstrates initiative and can significantly boost your grade in this category.

   - **Export Functionality**: Allow users to save results to files:
     ```cpp
     void exportToFile(const std::string& filename, const std::vector<Candlestick>& data) {
         std::ofstream file(filename);
         if (!file.is_open()) {
             std::cerr << "Error: Could not open file " << filename << " for writing\n";
             return;
         }
         
         // Write header
         file << "Date,Open,High,Low,Close\n";
         
         // Write data
         for (const auto& c : data) {
             file << c.getDate() << ","
                  << c.getOpen() << ","
                  << c.getHigh() << ","
                  << c.getLow() << ","
                  << c.getClose() << "\n";
         }
         
         std::cout << "Data exported to " << filename << "\n";
     }
     ```
     This feature adds practical utility to your application, allowing users to save their analysis results for further processing in other tools like Excel or Python. It demonstrates your understanding of file I/O operations and data serialization.

   - **Interactive Command-Line Interface**: Create a menu-driven interface for better user experience:
     ```cpp
     void showMenu() {
         std::cout << "\n===== Temperature Analysis Tool =====\n"
                   << "1. Load data from CSV\n"
                   << "2. View candlestick chart\n"
                   << "3. Filter data\n"
                   << "4. Make predictions\n"
                   << "5. Export data\n"
                   << "6. Exit\n"
                   << "Enter your choice (1-6): ";
     }
     
     void runApplication() {
         int choice;
         std::vector<Candlestick> candlesticks;
         
         while (true) {
             showMenu();
             std::cin >> choice;
             
             switch (choice) {
                 case 1:
                     // Load data
                     break;
                 case 2:
                     // View chart
                     break;
                 // ...other cases
                 case 6:
                     std::cout << "Exiting program. Goodbye!\n";
                     return;
                 default:
                     std::cout << "Invalid choice. Please try again.\n";
             }
         }
     }
     ```
     A well-designed CLI demonstrates your ability to create user-friendly applications. It shows that you're thinking about the user experience, not just the technical implementation.

   - **Configuration System**: Add the ability to save and load settings:
     ```cpp
     struct Config {
         std::string defaultCountry = "GB";
         int startYear = 1980;
         int endYear = 2019;
         TimeFrame timeframe = TimeFrame::Yearly;
         ChartType chartType = ChartType::Candlestick;
     };
     
     void saveConfig(const Config& config, const std::string& filename) {
         // Save configuration to file
     }
     
     Config loadConfig(const std::string& filename) {
         // Load configuration from file
         // Return default config if file doesn't exist
     }
     ```
     A configuration system demonstrates your understanding of application state management and persistence. It shows that you're thinking about how users might want to customize their experience.

2. **Apply Design Patterns**

   Using design patterns demonstrates your understanding of software engineering principles and can earn significant points for originality and challenge.

   - **Observer Pattern for Real-Time Updates**: Implement the Observer pattern to update views when data changes:
     ```cpp
     class DataObserver {
     public:
         virtual void update(const std::vector<Candlestick>& data) = 0;
     };
     
     class DataSubject {
     private:
         std::vector<std::shared_ptr<DataObserver>> observers;
         std::vector<Candlestick> data;
     
     public:
         void attach(std::shared_ptr<DataObserver> observer) {
             observers.push_back(observer);
         }
         
         void setData(const std::vector<Candlestick>& newData) {
             data = newData;
             notifyObservers();
         }
         
         void notifyObservers() {
             for (auto& observer : observers) {
                 observer->update(data);
             }
         }
     };
     
     class ChartView : public DataObserver {
     public:
         void update(const std::vector<Candlestick>& data) override {
             std::cout << "Chart updated with " << data.size() << " candlesticks\n";
             plotCandlesticks(data);
         }
     };
     
     class StatisticsView : public DataObserver {
     public:
         void update(const std::vector<Candlestick>& data) override {
             // Calculate and display statistics
         }
     };
     ```
     The Observer pattern allows for loose coupling between data and views, making your application more maintainable and extensible. It demonstrates your understanding of advanced object-oriented design principles.

   - **Factory Pattern for Creating Filters**: Use the Factory pattern to create filter objects:
     ```cpp
     class FilterFactory {
     public:
         static std::shared_ptr<Filter> createDateRangeFilter(const std::string& start, const std::string& end) {
             return std::make_shared<DateRangeFilter>(start, end);
         }
         
         static std::shared_ptr<Filter> createTemperatureFilter(double min, double max) {
             return std::make_shared<TemperatureRangeFilter>(min, max);
         }
         
         static std::shared_ptr<Filter> createTrendFilter(bool upward) {
             return std::make_shared<TrendFilter>(upward);
         }
         
         static std::shared_ptr<Filter> createAndFilter(std::shared_ptr<Filter> left, std::shared_ptr<Filter> right) {
             return std::make_shared<AndFilter>(left, right);
         }
     };
     
     // Usage
     auto dateFilter = FilterFactory::createDateRangeFilter("2000-01-01", "2010-12-31");
     auto tempFilter = FilterFactory::createTemperatureFilter(20.0, 30.0);
     auto combinedFilter = FilterFactory::createAndFilter(dateFilter, tempFilter);
     ```
     The Factory pattern centralizes object creation logic and provides a clean interface for creating complex objects. It demonstrates your understanding of creational design patterns and promotes code reuse.

   - **Command Pattern for User Actions**: Implement the Command pattern for user operations:
     ```cpp
     class Command {
     public:
         virtual void execute() = 0;
         virtual void undo() = 0;
     };
     
     class FilterCommand : public Command {
     private:
         std::vector<Candlestick>& data;
         std::vector<Candlestick> originalData;
         std::shared_ptr<Filter> filter;
         
     public:
         FilterCommand(std::vector<Candlestick>& d, std::shared_ptr<Filter> f)
             : data(d), originalData(d), filter(f) {}
         
         void execute() override {
             std::vector<Candlestick> filtered;
             std::copy_if(data.begin(), data.end(), 
                         std::back_inserter(filtered),
                         [this](const Candlestick& c) { return filter->matches(c); });
             data = filtered;
         }
         
         void undo() override {
             data = originalData;
         }
     };
     ```
     The Command pattern encapsulates operations as objects, allowing for features like undo/redo and operation queuing. It demonstrates your understanding of behavioral design patterns and promotes separation of concerns.

## Video Demonstration (10 points)

The video demonstration is worth 10% of your grade and provides an opportunity to showcase your project in action. A well-produced video can make a strong impression on the grader and help them understand your implementation better.

1. **Create a Professional Video**

   A structured, professional video demonstrates your ability to communicate technical concepts clearly and effectively.

   - **Introduction (30 seconds)**:
     Begin with a brief introduction that sets the context for your project:
     "Hello, my name is [Your Name]. In this video, I'll demonstrate my Weather Data Analysis and Prediction application. This project processes historical temperature data for European countries, visualizes it using candlestick charts, applies various filters, and implements prediction models to forecast future temperature trends."

   - **Project Architecture Overview (1 minute)**:
     Explain the overall structure of your application:
     "My application follows an object-oriented design with six main components: DataLoader for reading CSV files, Candlestick for representing aggregated temperature data, CandlestickCalculator for computing OHLC values, Plotter for visualization, DataFilter for filtering data, and Prediction for forecasting. These components work together to provide a comprehensive temperature analysis tool."

     Consider showing a diagram of your architecture to make it easier to understand the relationships between components.

   - **Task Demonstrations (30-45 seconds each)**:
     Show each task in action with clear narration:

     * **Task 1**: "Here I'm loading temperature data for Great Britain from 1980 to 2019. The application parses the CSV file, extracts the relevant temperature records, and computes yearly candlestick data. You can see the data being processed and the resulting candlesticks displayed."

     * **Task 2**: "Now I'll demonstrate the text-based candlestick chart. Notice how the chart clearly shows temperature trends over time, with the vertical lines representing the high-low range and the boxes showing the open-close range. The '+' symbols indicate years with rising temperatures, while '#' symbols show years with falling temperatures."

     * **Task 3**: "Let's apply some filters to focus on specific data. First, I'll filter for the years 2000-2010. Now I'll add a filter for high volatility periods. The application supports combining filters using logical operators, as you can see with this AND filter that shows warm summers with high volatility."

     * **Task 4**: "Finally, I'll demonstrate the prediction models. The linear regression model predicts a temperature of 9.2°C for the next period, with an R² value of 0.78 indicating a good fit. The moving average predicts 8.9°C, and the heuristic model predicts 9.5°C. The ensemble model combines these predictions with weights based on historical accuracy."

   - **Innovative Features (30 seconds)**:
     Highlight any additional features you implemented:
     "I've also implemented several features beyond the basic requirements. The application includes an interactive command-line interface, the ability to export data to CSV files, and a configuration system for saving user preferences. I've applied design patterns like Observer, Factory, and Command to make the code more maintainable and extensible."

   - **Code Walkthrough (30 seconds)**:
     Show and explain key parts of your code:
     "Let me walk you through some key components of my implementation. Here's the Filter interface and concrete implementations, demonstrating the Strategy pattern. And here's the ensemble prediction model that combines multiple forecasting techniques for improved accuracy."

   - **Conclusion (15 seconds)**:
     Summarize your project and what you learned:
     "In conclusion, this project demonstrates a comprehensive approach to temperature data analysis and prediction. I've applied object-oriented design principles, implemented various algorithms, and created a user-friendly interface. Thank you for watching."

2. **Prepare a Script**

   A well-prepared script ensures your video is concise, clear, and covers all important aspects of your project.

   - **Write Key Points for Each Section**:
     For each section of your video, list the main points you want to cover. For example:
     
     * Introduction:
       - Project purpose and scope
       - Main features
       - Technologies used
     
     * Architecture Overview:
       - Component diagram
       - Class relationships
       - Design patterns used
     
     * Task 1 Demonstration:
       - CSV parsing process
       - Candlestick computation
       - Error handling features
     
     And so on for each section.

   - **Practice the Demonstration Flow**:
     Rehearse your demonstration several times to ensure smooth transitions and clear explanations. Pay attention to:
     
     * Timing: Ensure you stay within the 3-minute limit
     * Clarity: Speak clearly and at a moderate pace
     * Transitions: Move smoothly between different parts of your application
     * Highlighting: Emphasize key features and innovative aspects

   - **Test Your Setup**:
     Before recording, test your setup to ensure:
     
     * Your application runs correctly
     * Your screen recording software works properly
     * Your microphone produces clear audio
     * Your demonstration environment is free from distractions

   - **Record in a Quiet Environment**:
     Find a quiet place to record your video to minimize background noise and distractions. Consider using a headset microphone for better audio quality.

## Submission Requirements (4 points)

While only worth 4% of your grade, meeting all submission requirements is essential to avoid unnecessary point deductions. The grading criteria specifically mentions that failure to submit required files will result in zero marks for the corresponding tasks.

1. **Prepare All Required Files**

   The project brief requires several specific files to be submitted. Ensure you prepare each one carefully.

   - **CODE PDF**:
     This should contain all your source code with clear labeling of sections you wrote personally:
     
     * Include all .cpp and .h files
     * Use syntax highlighting if possible for better readability
     * Add page numbers for easy reference
     * Include a table of contents listing all files
     * Ensure the PDF is searchable (not scanned images)
     
     Example structure:
     ```
     Table of Contents
     1. Candlestick.h .................... 1
     2. Candlestick.cpp .................. 2
     3. DataLoader.h ..................... 3
     4. DataLoader.cpp ................... 4
     ...
     ```

   - **REPORT PDF**:
     This should provide a detailed explanation of your implementation:
     
     * Introduction explaining the project goals
     * Detailed description of each task implementation
     * Explanation of design decisions and algorithms
     * Screenshots of output and visualizations
     * Analysis of prediction model performance
     * Discussion of challenges and solutions
     * Conclusion summarizing achievements
     
     Example structure:
     ```
     1. Introduction
     2. Task 1: Computing Candlestick Data
        2.1 CSV Parsing Implementation
        2.2 Candlestick Computation Algorithm
        2.3 Error Handling Approach
     3. Task 2: Text-Based Plotting
        ...
     ```

   - **ZIP File**:
     Include all source files and any necessary resources:
     
     * All .cpp and .h files
     * Any data files used for testing
     * Makefile or build instructions
     * README.md with setup and usage instructions
     
     Ensure the ZIP file is organized with a clear directory structure:
     ```
     project/
     ├── src/
     │   ├── Candlestick.h
     │   ├── Candlestick.cpp
     │   ├── DataLoader.h
     │   └── ...
     ├── data/
     │   └── weather_data.csv
     ├── Makefile
     └── README.md
     ```

   - **Video**:
     Create a 3-minute demonstration with voice narration:
     
     * Use a common video format (MP4 recommended)
     * Keep the file size reasonable (compress if necessary)
     * Ensure the video has good resolution for code visibility
     * Check that audio is clear and at an appropriate volume

2. **Label Your Code Clearly**

   The grading criteria specifically mentions that you must "clearly label all sections of the code that you personally wrote without assistance." This is worth 6% of your grade.

   - **Add Clear Comments**:
     Use distinctive comment blocks to indicate your original code:
     
     ```cpp
     // START OF MY CODE
     // Implementation of the linear regression prediction model
     double Prediction::predictLinear(const std::vector<Candlestick>& data) {
         // Calculate linear regression using least squares method
         double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
         
         for (int i = 0; i < data.size(); i++) {
             double x = i;
             double y = data[i].getClose();
             sumX += x;
             sumY += y;
             sumXY += x * y;
             sumX2 += x * x;
         }
         
         // Calculate slope and intercept
         double m = (data.size() * sumXY - sumX * sumY) / 
                    (data.size() * sumX2 - sumX * sumX);
         double b = (sumY - m * sumX) / data.size();
         
         // Predict next value
         return m * data.size() + b;
     }
     // END OF MY CODE
     ```
     
     These clear markers make it easy for the grader to identify your original contributions.

   - **Be Honest About Sources**:
     If you adapted code from external sources, clearly indicate this:
     
     ```cpp
     // ADAPTED FROM: [source]
     // The original code performed basic linear regression.
     // I modified it to include R² calculation and error handling.
     ```
     
     Honesty about your sources demonstrates academic integrity.

   - **Explain Complex Algorithms**:
     For complex algorithms, add comments explaining your implementation approach:
     
     ```cpp
     // MY IMPLEMENTATION OF ENSEMBLE PREDICTION
     // This combines three prediction models with weights based on
     // their historical accuracy using cross-validation.
     // 1. Calculate predictions from each model
     // 2. Validate each model to determine error rates
     // 3. Convert errors to weights (smaller error = higher weight)
     // 4. Normalize weights to sum to 1
     // 5. Return weighted average of predictions
     ```
     
     These explanations help the grader understand your thought process.

## Implementation Strategy

To maximize your grade, follow this approach:

1. **Start with core functionality** for each task
2. **Add error handling** to make your code robust
3. **Implement advanced features** that demonstrate originality
4. **Refine code style and documentation**
5. **Prepare submission materials** carefully

Remember that the grading emphasizes both working code and clear documentation. Balance your effort between implementation and explanation to achieve the highest possible score.

Good luck with your project!
