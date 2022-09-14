#pragma once
class Student {
    string name_, surname_;
    vector <int> nd_;
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
    Student(Student&);
    //desktruktorius
    ~Student();
    //getteriai
    const string getName();
    const string getSurname();
    const vector<int> getNd();
    const int getEgz();
    //metodai
    void studEdit(string, string, vector<int>, int);
};

void Student::name(std::string temp){name_=temp;}
void Student::surname(std::string temp){surname_=temp;}
void Student::nd(vector<int> temp){nd_=temp;}
void Student::egz(int temp){egz_=temp;}

Student::Student() {
    name(" ");
    surname(" ");
    nd({0});
    egz(0);
}

Student::Student(Student &temp) {
    this->name(temp.getName());
    this->surname(temp.getSurname());
    this->nd(temp.getNd());
    this->egz(temp.getEgz());
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

void Student::studEdit(string y, string p, vector<int> a, int e) {
    name(y);
    surname(p);
    nd(a);
    egz(e);
}