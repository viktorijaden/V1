#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>
#include <list>
#include <deque>
#include <filesystem>
#include <iomanip>


using std::cout;
using std::cin;
using std::array;
using std::mt19937;
using std::deque;
using std::domain_error;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::move;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::sort;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;
int minimum(int a, int b);

class Student {
public:
	string Name, Surname;
	vector<int> HW;
	int Exam;
	float Rez;
public:
	Student();
	Student(string N, string S, vector<int>H, int E);
	Student(const Student& A);
	Student& operator=(const Student& A);
	~Student();
	float Vid();
	float Med();
	void Rezult(char pas);

	inline void SetName(string N) { Name = N; };
	inline void SetSurname(string S) { Surname = S; };
	inline void SetHW(vector <int> Vec) { HW = Vec; };
	inline void SetExam(int n) { Exam = n; };

	inline float GetRez() const { return Rez; }
	inline int GetExam() const { return Exam; }
	inline string GetName() const { return Name; }
	inline string GetSurname() const { return Surname; }
	inline vector <int> getHW() { return HW; }

	void printas();
	void printasrez();
	std::string output_to_string();

	friend std::ostream& operator<<(std::ostream& out, const Student& A);
	friend std::istream& operator>>(std::istream& in, Student& a);
};
bool mazVid(const Student& A, const Student& B);
bool mazVard(const Student& A, const Student& B);
bool mazPav(const Student& A, const Student& B);

//visa kita
/*
void printStudent();
void printasrez();
std::ostream& printasFilePr(std::ostream& out);
std::ostream& printasRez(std::ostream& out);

bool operator<(const Student& A, const Student& B);
bool operator>(const Student& A, const Student& B);
bool operator==(const Student& A, const Student& B);
*/