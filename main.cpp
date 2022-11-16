#include "inc.h"
#include "student.h"

void generateList();
void createManualList();

/*
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector) {
    //spausdinam vektoriu elementus su cout <<, skirtas testavimui.
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}
*/

int main()
{
    system("cls");
    cout << "Pasirinkite norima veiksma nuspausdami tam tikra skaiciu:\n";
    cout << "1. Sudaryti studentu sarasa\n";
    cout << "2. Sugeneruoti atsitiktinius studentu sarasus\n";
    cout << "\nSpustelekite bet koki klavisa, kad iseiti is programos.\n";
    char id = _getch();  //#include <conio.h>, laukiam vartotojo mygtuko nuspaudimo

    if (id == '1') {
        createManualList();
    } else if (id == '2') {
        generateList();
    } else {
        cout << "Iseinama...\n";
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
void createManualList() {
    system("cls");
    
    ofstream SOutput("surasytas_studentu_sarasas.txt");

    //cout << "Iveskite studentu skaiciu: ";
    int /*n,*/ m; char kl = 'y';
    //cin >> n; cout << "\n";

    vector<Student> mas;
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
    cout << "\x1B[32mSarasas issaugotas i 'surasytas_studentu_sarasas.txt' programos aplankale.\033[0m\n";
    cout << "Spustelekite bet koki klavisa, kad grizti i pagrindini meniu.";
    int e = _getch();
    main();
}
//-----------------------------------------------------------------------------------------------------------------
void generateList() {
    system("cls");

    // overkomplikuotas sprendimas, pasitelkiantis "vaizdingus" vardus ir pavardes is 2 duomenu failu, vietoj Vardas1 Pavarde1.

    ifstream names("vardai.txt");
    ifstream surnames("pavardes.txt");
    bool fail = false;

    try {
        if (names.fail()) {
            throw "\x1B[31mNerastas vardu sarasas! (truksta 'vardai.txt')\033[0m";
        }
    } catch (const char* msg) {
        cerr << msg << endl;
        fail = true;
    }

    try {
        if (surnames.fail()) {
            throw "\x1B[31mNerastas pavardziu sarasas! (truksta 'pavardes.txt')\033[0m";
        }
    } catch (const char* msg) {
        cerr << msg << endl;
        fail = true;
    }

    if (!fail) {
        vector <string> name, surn, fname, mname, fsurn, msurn;
        bool gender;

        string x, d;
        //cout << "Maisomi vardai ir pavardes...\n";
        while (names >> x >> gender) {
            name.push_back(x);
            if (gender == 0) {
                mname.push_back(x);     //vyru vardu vektorius
            }
            else {
                fname.push_back(x);     //moteru vardu vektorius
            }
        }
        while (surnames >> d >> gender) {
            surn.push_back(d);
            if (gender == 0) {
                msurn.push_back(d);     //vyrisku "pavardziu" vektorius
            }
            else {
                fsurn.push_back(d);     //moterisku "pavardziu" vektorius
            }
        }

        ofstream varg("sugeneruoti_vargsiukai.txt");
        ofstream kiet("sugeneruoti_kietuoliai.txt");
        int amount;
        cout << "Iveskite studentu kieki:\n";
        cin >> amount;
        cout << "Generuojami studentu sarasai...\n";
        varg << setw(20) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(30) << left << "Galutinis (vid.)\n";
        kiet << setw(20) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(30) << left << "Galutinis (vid.)\n";
        varg << "--------------------------------------------------------------------------------------------\n";
        kiet << "--------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < amount; i++) {
            random_device rd;
            default_random_engine generator(rd()); // rd() duoda atsitiktini seed'a
            uniform_int_distribution<int> randStudent(0, 1);
            uniform_real_distribution<double> randMark(3.30, 10);

            shuffle(begin(mname), end(mname), generator);
            shuffle(begin(msurn), end(msurn), generator);
            shuffle(begin(fname), end(fname), generator);
            shuffle(begin(fsurn), end(fsurn), generator);
            int rand = randStudent(generator);
            double gal = randMark(generator);
            if (gal < 5.0) {
                if (rand == 0) {
                    for (size_t i = 0; i < 1; i += 2)
                        //cout << mname[i] << " " << msurn[i] << '\n';
                        varg << setw(20) << left << mname[i] << setw(25) << left << msurn[i] << setw(30) << left << fixed << setprecision(2) << gal << "\n";
                }
                else if (rand == 1) {
                    for (size_t i = 0; i < 1; i += 2)
                        //cout << fname[i] << " " << fsurn[i] << '\n';
                        varg << setw(20) << left << fname[i] << setw(25) << left << fsurn[i] << setw(30) << left << fixed << setprecision(2) << gal << "\n";
                }
            }
            else if (gal >= 5.0) {
                if (rand == 0) {
                    for (size_t i = 0; i < 1; i += 2)
                        //cout << mname[i] << " " << msurn[i] << '\n';
                        kiet << setw(20) << left << mname[i] << setw(25) << left << msurn[i] << setw(30) << left << fixed << setprecision(2) << gal << "\n";
                }
                else if (rand == 1) {
                    for (size_t i = 0; i < 1; i += 2)
                        //cout << fname[i] << " " << fsurn[i] << '\n';
                        kiet << setw(20) << left << fname[i] << setw(25) << left << fsurn[i] << setw(30) << left << fixed << setprecision(2) << gal << "\n";
                }
            }
        }
        varg.close();
        kiet.close();
        cout << "\x1B[32mKietuoliu sarasas issaugotas i 'sugeneruoti_kietuoliai.txt'\033[0m\n";
        cout << "\x1B[32mVargsiuku sarasas issaugotas i 'sugeneruoti_vargsiukai.txt'\033[0m\n";
        cout << "Baigta.\nSpustelekite bet koki klavisa, kad grizti i pagrindini meniu.";
        int e = _getch();
        main();
    }
    else {
        cout << "Programa negali pradeti sio darbo. Spustelekite bet koki klavisa, kad grizti i pagrindini meniu.\n";
        int e = _getch();
        main();
    }
}