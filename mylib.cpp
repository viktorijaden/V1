#include "mylibheader.h"
int minimum(int a, int b) { return a < b ? a : b; }

Student::Student() {
	//cout << " Data declareted\n";
	mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	int_distribution dist(0, 9);
	string vardai[10] = { "Petras", "Jonas", "Onute", "Kazys", "Antanas", "Egle", "Ilma", "Linas", "Anna", "Saule" };
	string pavardes_m[10] = { "Pavardaite1","Pavardaite2","Pavardaite3","Pavardaite4","Pavardaite5","Pavardaite6","Pavardaite7","Pavardaite8","Pavardaite9","Pavardaite10" };
	string pavardes_v[10] = { "Pavardenis1","Pavardenis2","Pavardenis3","Pavardenis4","Pavardenis5","Pavardenis6","Pavardenis7","Pavardenis8","Pavardenis9","Pavardenis10" };
	Name = vardai[dist(mt)];
	switch (*Name.rbegin()) {
	case 's':
		Surname = pavardes_v[dist(mt)];
		break;
	default:
		Surname = pavardes_m[dist(mt)];
		break;
	};
	for (int i = 0; i < 5; i++) {
		HW.push_back(dist(mt) + 1);
	}
	Exam = dist(mt) + 1;
	//Rez = 0.4 * (std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size()) + 0.6 * Exam;
	Rezult('v');
}
Student::Student(string N, string S, vector <int> H, int E) {
	Name = N; Surname = S;
	HW = H;
	Exam = E;
	Rezult('v');
}
Student::Student(const Student& A) {
	Name = A.Name; Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	Rez = A.Rez;
}
Student& Student::operator=(const Student& A) {
	if (this == &A) return *this;
	Name = A.Name; Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	Rez = A.Rez;
	return *this;
}
Student::~Student() {
	Name.clear();
	Surname.clear();
	HW.clear();
	Exam = 0;
	Rez = 0;
}
float Student::Vid() {
	return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size() * 1.0;
}
float Student::Med() {
	std::sort(HW.begin(), HW.end());
	int n = HW.size() / 2;
	return (n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
}
void Student::Rezult(char pas) {
	if (pas == 'v') { Rez = 0.4 * Vid() + 0.6 * Exam; }
	else { Rez = 0.4 * Med() + 0.6 * Exam; }
}
void Student::printas() {
	cout << Name << " ; " << Surname << " | ";
	for (auto& i : HW) cout << i << " | ";
	cout << Exam << " | ";
	cout << " Rezultatas = " << Rez << endl;
}
void Student::printasrez()
{
	printf("%-10s|%20s", Name.c_str(), Surname.c_str());
	for (auto& a : HW)printf("%3d|", a);
	printf("%10d|\n", Exam);
}

std::string Student::output_to_string() {
	std::stringstream buffer;
	buffer << left << setw(15) << Name << right << setw(15) << Surname;
	buffer << setw(10) << Exam << endl;
	return buffer.str();
}

std::ostream& operator<<(std::ostream& out, const Student& A) {
	out << A.Name << " ; " << A.Surname << " | ";
	for (auto& i : A.HW) cout << i << " | ";
	out << A.Exam << " | ";
	out << " Rezultatas = " << A.Rez << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Student& a) {
	in >> a.Name;
	in >> a.Surname;
	a.HW.clear();
	for (int i = 0; i < 5; i++) {
		int k;
		in >> k; a.HW.push_back(k);
	}
	in >> a.Exam;
	a.Rezult('v');
	return in;
}

bool mazVid(const Student& A, const Student& B) {
	return A.GetRez() < B.GetRez();
}

bool mazVard(const Student& A, const Student& B)
{
	return A.GetName() < B.GetName();
}

bool mazPav(const Student& A, const Student& B)
{
	return A.GetSurname() < B.GetSurname();
}

//visa kita
/*
//printai
void Student::printStudent() {
	cout << left << setw(15) << Name << setw(15) << Surname << " | ";
	for (auto& ref : HW) cout << setw(3) << ref;
	cout << setw(3) << Exam << " ; final points: "
	<< setw(5) << setprecision(2) << fixed << Rez << endl;
}
void Student::printasrez()
{
	printf("|%-10s|%20s|", Name.c_str(), Surname.c_str());
	printf("%.2f|\n", Rez);
}

std::ostream& Student::printasFilePr(std::ostream& out) {
	out << Name << " ; " << Surname << " | ";
	for (auto& i : HW) out << i << " | ";
	out << Exam << " | " << std::endl;
	return out;
}

std::ostream& Student::printasRez(std::ostream& out) {
	out << Name << " ; " << Surname << " | ";
	out << Exam << " | ";
	out << std::fixed << Rez << std::endl;
	return out;
}
//operatoriai

bool operator<(const Student& A, const Student& B) {
	return A.GetRez() < B.GetRez();
}
bool operator>(const Student& A, const Student& B)
{
	return A.GetRez() > B.GetRez();
}
bool operator==(const Student& A, const Student& B)
{
	return A.GetRez() == B.GetRez();
}

Student operator+(const Student& A, const Student& B) {
	Student C;
	C.SetName(A.GetName() + " " + B.GetName());
	C.SetSurname(A.GetSurname() + B.GetSurname());
	return C;
}
*/