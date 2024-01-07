#include "mylibheader.h"
#include "files.h"


void Data_read(string FailoVardas, vector<Student>& Grupe)
{
	std::ifstream open_f(FailoVardas);
	string NuskEil;
	std::getline(open_f, NuskEil);
	while (open_f) {
		if (!open_f.eof()) {
			std::getline(open_f, NuskEil);
			std::stringstream my_buffer(NuskEil);
			Student Temp;
			string TEil;
			my_buffer >> TEil; Temp.SetName(TEil);
			my_buffer >> TEil; Temp.SetSurname(TEil);
			vector<int>LaikPaz;
			int t;
			while (my_buffer >> t) {
				if (t >= 0 && t < 11) LaikPaz.push_back(t);
				else std::cerr << "Blogi pazymiai, bandykite dar karta\n";
			}
			if (LaikPaz.empty()) std::cerr << "Studentas neturi pazymiu\n";
			else {
				Temp.SetExam(LaikPaz.back());
				LaikPaz.pop_back();
				Temp.SetHW(LaikPaz);
				Temp.Rezult('v');
				Grupe.push_back(Temp);
			}
			LaikPaz.clear();
			Temp.SetHW(LaikPaz);
		}
		else break;
	}
	open_f.close();

//rusiavimo strategijos:
/*
cout << "Pasirinkite kaip norite rusiuoti, pagal: 1 - varda, 2 - pavarde, 3 - pazymius";
	int select;
	cin >> select;
	switch (select)
	{
	case 1: sort(Grupe.begin(), Grupe.end(), lessName); break;
	case 2: sort(Grupe.begin(), Grupe.end(), lessSurname); break;
	case 3: sort(Grupe.begin(), Grupe.end(), myless);
	}
	sort(Grupe.begin(), Grupe.end());
	std::deque<Student> good, bad;
	int band2;
	std::cout << "Pasirinkite skaidymo strategija: 1 - pirmoji, 2 - antroji: ";
	std::cin >> band2;

	std::ofstream output_fg("Blogi.txt");
	std::ofstream output_fb("Geri.txt");

	switch (band2) {
	case 1:
		std::sort(Grupe.begin(), Grupe.end());

		for (auto& Student : Grupe) {
			if (Student.GetRez() > 5.0)
				good.push_back(Student);
			else
				bad.push_back(Student);
		}
		std::cout << "\nGeri studentai: " << good.size() << "\nBlogi Studentai: " << bad.size() << "\n";
		Grupe.clear();
		break;
	case 2:
		std::sort(Grupe.begin(), Grupe.end());
		auto it = Grupe.end();
		for (auto pr = it; pr >= Grupe.begin(); pr--) {
			if (pr->GetRez() >= 5.0) {
				good.push_back(*pr);
				Grupe.pop_back();
			}
		}
		std::cout << "\nGeri studentai: " << good.size() << "\n";
		for (auto& student : good) {
			output_buffer << student;
		}

		output_fg << output_buffer.str();
		output_fg.close();

		std::cout << "\nLike studentai grupese: " << Grupe.size() << "\n";
		for (auto& student : Grupe) {
			output_buffer2 << student;
		}
		output_fb << output_buffer2.str();
		output_fb.close();
		break;
	}
*/
}
void generateFiles() {
	vector <int> files{ 5, 10, 15 };
	for (auto a : files) {
		std::string temp = std::to_string(a) + ".txt";
		std::ofstream output_f(temp);
		std::stringstream buffer;

		buffer << left << setw(15) << "Name" << right << setw(15) << "Surname";
		for (int i = 0; i < 10; i++) {
			buffer << setw(5) << "HW" + std::to_string(i + 1);
		}
		buffer << setw(10) << "Exam" << endl;

		for (int i = 0; i < a; i++) {
			Student temp;
			buffer << temp.output_to_string();
			//temp.~Student();
		}
		output_f << buffer.str();
		output_f.close();
		buffer.clear();
		temp.clear();
	}
}
