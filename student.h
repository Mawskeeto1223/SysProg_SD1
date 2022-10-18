#pragma once
#include "inc.h"

class Student {
    string name_, surname_;
    vector <int> nd_;
    vector <int> median_;
    int egz_;
    //setteriai
    void name(string);
    void surname(string);
    void nd(vector<int>);
    void egz(int);

public:
    //konstruktoriai
    Student();
    Student(string, string, vector<int>, int);
    Student(const Student&);
    //desktruktorius
    ~Student();
    //getteriai
    const string getName();
    const string getSurname();
    const vector<int> getNd();
    const int getEgz();
    //metodai
    Student& operator=(const Student&);
    void studEdit(string, string, vector<int>, int);
};

void Student::name(string temp){name_=temp;}
void Student::surname(string temp){surname_=temp;}
void Student::nd(vector<int> temp){nd_=temp;}
void Student::egz(int temp){egz_=temp;}

Student::Student() {
    name(" ");
    surname(" ");
    nd({0});
    egz(0);
}

Student::Student(const Student &temp) {
    this->name(temp.name_);
    this->surname(temp.surname_);
    this->nd(temp.nd_);
    this->egz(temp.egz_);
}

Student::Student(string y, string p, vector<int> a, int e) {
    name(y);
    surname(p);
    nd(a);
    egz(e);
}

Student::~Student(){name_=""; surname_= ""; nd_.clear();}

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