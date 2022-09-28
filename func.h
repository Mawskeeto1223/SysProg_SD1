#pragma once
#include "reqlibs.h"

double getAverage(vector<int> const& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
    // sudeda vektoriaus elementus nuo pradzios (v.begin) iki pabaigos (v.end) ir padalina is vektoriaus elemento kiekio (v.size)
}

double getMedian(vector<int> median) {  //medianos algoritmas
    size_t size = median.size();
    sort(median.begin(), median.end());
    if (size % 2 == 0)
    {
        return (median[size / 2 - 1] + median[size / 2]) / 2;
    }
    else
    {
        return median[size / 2];
    }
}