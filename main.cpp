#include <reqlibs.h>
#include <student.h>

int main()
{
    /*
    Student a;
    Student b("Vardenis", "Pavardenis", { 9,8,5,6,8,7,4,5,9,6 }, 10);
    a = b;
    cout << a.getName() << " " << a.getSurname() << " " << a.getEgz() << "\n";
    a.studEdit("Vardenis", "Pavardenis", { 9,8,5,6,8,7,4,5,9,6 }, 2);
    cout << a.getName() << " " << a.getSurname() << " " << a.getEgz() << "\n";
    */

    Student* mas;
    cout << "Iveskite studentu skaiciu: ";
    int n, m; char kl='y';
    cin >> n; cout << "\n";

    string var, pav; vector<int> temp; int egz;
    mas = new Student[n];

    for (int i = 0; i < n; i++) {
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
        //mas[i].studEdit(var, pav, temp, egz);
        Student tempas(var, pav, temp, egz);
        mas[i] = tempas;
        temp.clear();
        temp.resize(0);
    }

    for(int i = 0; i < n; i++)
        cout << mas[i].getName() << " " << mas[i].getSurname() << " " << mas[i].getEgz() << "\n";

    delete [] mas;
}