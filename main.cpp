#include "reqlibs.h"
#include "student.h"

int main()
{
    vector<Student> mas;
    //cout << "Iveskite studentu skaiciu: ";
    int /*n,*/ m; char kl = 'y';
    //cin >> n; cout << "\n";

    string var, pav; vector<int> temp; int egz;

    while (kl == 'y' || kl == 'Y') {
        cout << "Iveskite varda: "; cin >> var; cout << "\n";
        cout << "Iveskite pavarde: "; cin >> pav; cout << "\n";
        cout << "Iveskite egzamino pazymi: "; cin >> egz; cout << "\n";
        cout << "Iveskite semestro pazymius: ";
        while (true) {
            cin >> m;
            temp.push_back(m);
            cout << "Ar vesite dar? (y/n): "; cin >> kl;
            if (kl != 'y') break;
        }
        Student tempas(var, pav, temp, egz);
        mas.push_back(tempas);
        temp.clear();
        temp.resize(0);
        cout << "----------------------------------------------\n";
        cout << "Ar vesite dar? (y/n): "; cin >> kl;
    }
    system("cls");
    cout << "Vardas\t\tPavarde\t\tGalutinis (vid.)\n";
    cout << "-------------------------------------------------\n";
    for(Student &laik: mas)
        cout << laik.getName() << "\t\t" << laik.getSurname() << "\t\t" << fixed << setprecision(2) << getAverage(laik.getNd()) << "\n";
}