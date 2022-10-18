#include "inc.h"
#include "student.h"

void generateList();
void createList();

int main()
{
    int id;
    int stn = 1000;
    cout << "Pasirinkite norima veiksma:\n";
    cout << "1. Sudaryti studentu sarasa\n";
    cout << "2. Sugeneruoti atsitiktinius studentu sarasus\n";

    cin >> id;

    if (id == 1) {
        createList();
    } else if (id == 2) {
        generateList();
    }
}

void createList() {
    system("cls");
    vector<Student> mas;
    ofstream studoutput("surasytas_studentu_sarasas.txt");

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
            //cout << "Ar vesite dar? (y/n): "; cin >> kl;
            if (!cin.good()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        Student tempas(var, pav, temp, egz);
        mas.push_back(tempas);
        temp.clear();
        temp.resize(0);
        cout << "----------------------------------------------\n";
        cout << "Ar vesite dar? (y/n): "; cin >> kl;
    }
    system("cls");
    cout << setw(20) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(30) << left << "Galutinis (vid.)" << setw(20) << left << "Galutinis (med.)\n";
    studoutput << setw(20) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(30) << left << "Galutinis (vid.)" << setw(20) << left << "Galutinis (med.)\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    studoutput << "--------------------------------------------------------------------------------------------\n";
    for (Student& laik : mas) {
        cout << setw(20) << left << laik.getName() << setw(25) << left << laik.getSurname() << setw(30) << left << fixed << setprecision(2) << getAverage(laik.getNd()) << setw(20) << left << getMedian(laik.getNd()) << "\n";
        studoutput << setw(20) << left << laik.getName() << setw(25) << left << laik.getSurname() << setw(30) << left << fixed << setprecision(2) << getAverage(laik.getNd()) << setw(20) << left << getMedian(laik.getNd()) << "\n";
    }
}

void generateList() {

}