#include "Vehicle_starter.h"

// TODO: Implement Vehicle constructor
// Parameters:
// - make: Vehicle manufacturer
// - model: Vehicle model name
// - year: Manufacturing year
// - price: Original price
// Expected behavior:
// 1. Initialize all member variables
// 2. Print creation message:
//    "Creating vehicle: [year] [make] [model]"

// TODO: Implement Vehicle destructor
// Expected behavior:
// 1. Print destruction message:
//    "Destroying vehicle: [year] [make] [model]"

// TODO: Implement getter methods
// - Return corresponding member variables
// - Keep const correctness

// TODO: Implement displayInfo()
// Expected output format:
// Vehicle Information:
// ===================
// Make: [make]
// Model: [model]
// Year: [year]
// Original Price: $[price]
// Current Value: $[calculated value]

// TODO: Implement calculateValue()
// Algorithm:
// 1. Calculate age = current year (2024) - manufacturing year
// 2. Apply 15% depreciation per year:
//    value = price * pow(0.85, age)
// 3. Return calculated value
