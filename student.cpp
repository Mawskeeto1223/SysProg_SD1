#include "reqlibs.h"
#include "func.h"
#include "student.h"

const string Student::getName() {
    return name_;
}

const string Student::getSurname() {
    return surname_;
}

const vector<int> Student::getNd() {
    return nd_;
}

const int Student::getEgz() {
    return egz_;
}

Student& Student::operator=(const Student& kint) {
    if (this != &kint) {
        name_ = kint.name_;
        surname_ = kint.surname_;
        nd_ = kint.nd_;
        egz_ = kint.egz_;
        median_ = kint.nd_;
    }
    return *this;
}

void Student::studEdit(string y, string p, vector<int> a, int e) {
    name(y);
    surname(p);
    nd(a);
    egz(e);
}

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