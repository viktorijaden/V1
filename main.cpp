#include "mylibheader.h"
#include "files.h"

char skaiciavimo_Strategija = 'v';

int main()
{
    cout << "generuoti studentus - 1, skaityti is failo - 2, generuoti failus - 3, ivesti ranka - 4\n";
    int choice; cin >> choice;
    switch (choice) {
    case 1: {
        vector<Student> Grupe;
        cout << "Iveskite studentu skaiciu: ";
        int nr; cin >> nr;
        Grupe.reserve(nr);
        for (int i = 0; i < nr; i++) {
            vector <int> Vec;
            Student Laikinas;
            Student Laikinas2(Laikinas);
            Student Laikinas3;
            Laikinas3 = Laikinas2;

            string laiks;
            Grupe.push_back(Laikinas);
            Laikinas.~Student();
        }

        sort(Grupe.begin(), Grupe.end(), mazVid);
        for (auto& duom : Grupe) cout << duom;

        cout << "\nAr norite issaugoti duomenis i 'gen_rezultatai.txt'? (t/n): ";
        char saveChoice;
        cin >> saveChoice;
        if (saveChoice == 't' || saveChoice == 'T') {
            std::ofstream out_f("gen_rezultatai.txt");
            out_f << "\n" << Grupe.size() << "\n";
            out_f << "|Vardas    |             Pavarde|  Galutinis (v)|  Galutinis (m)|\n";

            for (auto& a : Grupe) {
                out_f << "|";
                out_f << setw(10) << a.GetName() << "|";
                out_f << setw(20) << a.GetSurname() << "|";
                out_f << setw(15) << fixed << setprecision(2) << a.Vid() << "|";
                out_f << setw(15) << fixed << setprecision(2) << a.Med() << "|\n";
            }
            out_f.close();
            cout << "Duomenys issaugoti i 'gen_rezultatai.txt'\n";
        }
        break;
    }
    case 2: {
        vector<Student> Grupe;
        cout << "Iveskite failo pavadinima: ";
        system("dir *.txt");
        string vardas;
        cin >> vardas;

        Data_read(vardas, Grupe);
        sort(Grupe.begin(), Grupe.end(), mazVid);

        vector<Student>geri;
        vector<Student>blogi;
        for (auto& a : Grupe)
            if (a.GetRez() < 5) blogi.push_back(a);
            else geri.push_back(a);
        printf("%-20s%-20s%-20s%\n", "Vardas", "Pavarde", "Galutinis");
        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;
        for (auto& student : Grupe) {
            printf("%-20s%-20s%-20.2f%\n", student.GetName().c_str(), student.GetSurname().c_str(), student.GetRez());
        }
        std::ofstream out_f("Blogi.txt");
        for (auto& duom : blogi) out_f << duom;
        out_f.close();
        std::ofstream out_f2("Geri.txt");
        for (auto& duom : geri) out_f2 << duom;
        out_f2.close();
        break;
    }
    case 3:
    {
        generateFiles();
        break;
    }
    case 4:;
    {
        vector<Student> Grupe;
        cout << "Iveskite studentu skaiciu: ";
        int nr;
        cin >> nr;
        for (int i = 0; i < nr; i++) {
            Student Laikinas;
            string laiks;
            vector <int> Vec;
            cout << "Iveskite varda: ";
            cin >> laiks; Laikinas.SetName(laiks);
            cout << "Iveskite pavarde: ";
            cin >> laiks; Laikinas.SetSurname(laiks);
            cout << "Kiek namu darbu norite ivesti? ";
            int ndNr; cin >> ndNr;
            for (int i = 0; i < ndNr; i++) {
                int pazin;
                cout << "Iveskite " << i + 1 << " pazymi: ";
                cin >> pazin; Vec.push_back(pazin);
                Laikinas.SetHW(Vec);
            }
            cout << "Koks egzamino balas? "; cin >> ndNr;
            Laikinas.SetExam(ndNr);
            Laikinas.Rezult('v');
            Grupe.push_back(Laikinas);
            Laikinas.~Student();
        }
        cout << endl << Grupe.size() << endl;
        printf("%-10s|%20s", "Vardas", "Pavarde");
        for (int i = 0; i < Grupe[0].getHW().size(); i++)
            printf("%s%d", " ND", i + 1);
        printf("%10s|\n", "Egzaminas");
        for (auto& a : Grupe) a.printasrez();

        int isved;
        cout << "isvesti vidurki - 1, mediana - 2, abu - 3\n";
        cin >> isved;
        switch (isved) {
        case 1:
            printf("|%-10s|%20s|%15s|\n", "Vardas", "Pavarde", "Galutinis (v)");
            for (auto& a : Grupe) {
                printf("|%-10s|%20s|%15.2f|\n", a.GetName().c_str(), a.GetSurname().c_str(), a.GetRez());
            }
            break;
        case 2:
            printf("|%-10s|%20s|%15s|\n", "Vardas", "Pavarde", "Galutinis (m)");
            for (auto& a : Grupe) {
                printf("|%-10s|%20s|%15.2f|\n", a.GetName().c_str(), a.GetSurname().c_str(), a.Med());
            }
            break;
        case 3:
            printf("|%-10s|%20s|%15s|%15s|\n", "Vardas", "Pavarde", "Galutinis (v)", "Galutinis (m)");
            for (auto& a : Grupe) {
                printf("|%-10s|%20s|%15.2f|%15.2f|\n", a.GetName().c_str(), a.GetSurname().c_str(), a.GetRez(), a.Med());
            }
            break;
        default:
            cout << "Neteisingas pasirinkimas. Rinkites is naujo." << endl;
            break;
        }

        cout << "\nAr norite issaugoti duomenis i 'rezultatai.txt'? (t/n): ";
        char saveChoice;
        cin >> saveChoice;
        if (saveChoice == 't' || saveChoice == 'T') {
            std::ofstream out_f("rezultatai.txt");
            out_f << "\n" << Grupe.size() << "\n";
            out_f << "|Vardas    |             Pavarde|  Galutinis (v)|  Galutinis (m)|\n";

            for (auto& a : Grupe) {
                out_f << "|";
                out_f << setw(10) << a.GetName() << "|";
                out_f << setw(20) << a.GetSurname() << "|";
                out_f << setw(15) << fixed << setprecision(2) << a.Vid() << "|";
                out_f << setw(15) << fixed << setprecision(2) << a.Med() << "|\n";
            }
            out_f.close();
            cout << "Duomenys issaugoti i 'rezultatai.txt'\n";
        }
        break;
    }
    }
    system("pause");
}