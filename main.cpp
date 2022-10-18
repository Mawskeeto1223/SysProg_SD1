#include "inc.h"
#include "student.h"

void generateList();
void createList();

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector) {
    //spausdinam vektoriu elementus su <<, skirtas testavimui.
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

int main()
{
    char id;
    cout << "Pasirinkite norima veiksma nuspausdami tam tikra skaiciu:\n";
    cout << "1. Sudaryti studentu sarasa\n";
    cout << "2. Sugeneruoti atsitiktinius studentu sarasus\n";
    cout << "\nSpauskit bet koki mygtuka, kad uzbaigti programos darba\n";
    id = _getch();  //#include <conio.h>, laukiam vartotojo mygtuko nuspaudimo

    if (id == '1') {
        createList();
    } else if (id == '2') {
        generateList();
    } else {
        cout << "Iseinama...\n";
    }
}

void createList() {
    system("cls");
    vector<Student> mas;
    ofstream SOutput("surasytas_studentu_sarasas.txt");

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
    SOutput << setw(20) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(30) << left << "Galutinis (vid.)" << setw(20) << left << "Galutinis (med.)\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    SOutput << "--------------------------------------------------------------------------------------------\n";
    for (Student& laik : mas) {
        cout << setw(20) << left << laik.getName() << setw(25) << left << laik.getSurname() << setw(30) << left << fixed << setprecision(2) << getAverage(laik.getNd()) << setw(20) << left << getMedian(laik.getNd()) << "\n";
        SOutput << setw(20) << left << laik.getName() << setw(25) << left << laik.getSurname() << setw(30) << left << fixed << setprecision(2) << getAverage(laik.getNd()) << setw(20) << left << getMedian(laik.getNd()) << "\n";
    }
    SOutput.close();
}

void generateList() {
    system("cls");

    ifstream names("vardai.txt");
    ifstream surnames("pavardes.txt");
    vector <string> name, surn, fname, mname, fsurn, msurn;
    bool gender;

    if (names.fail() || surnames.fail()) {
        cout << "KLAIDA: Nerasta vardu saraso!";
    } else {
        string x, d;
        while (names >> x >> gender) {
            name.push_back(x);
            if (gender == 0) {
                mname.push_back(x);     //vyru vardai
            }
            else {
                fname.push_back(x);     //moteru vardai
            }
        }
        while (surnames >> d >> gender) {
            surn.push_back(d);
            if (gender == 0) {
                msurn.push_back(d);     //vyriskos "pavardes"
            }
            else {
                fsurn.push_back(d);     //moteriskos "pavardes"
            }
        }
    }
    //cout << mname;

    ofstream varg("sugeneruoti_vargsiukai.txt");
    ofstream kiet("sugeneruoti_kietuoliai.txt");
}