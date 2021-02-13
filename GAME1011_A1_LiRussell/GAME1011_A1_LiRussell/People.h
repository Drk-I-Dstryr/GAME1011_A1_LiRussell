#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person()
	{
		SetName("None");
		SetAge(0);
	}

	Person(string n, int a)
	{
		SetName(n);
		SetAge(a);
	}

	void SetName(string n)
	{
		this->name = n;
	}
	virtual string GetName() const
	{
		return name;
	}

	void SetAge(int a)
	{
		this->age = a;
	}
	virtual int GetAge() const
	{
		return age;
	}
};

class Student : public Person
{
protected:
	string collegeName;
	string programEnrolled;
	int currentSemester;
public:
	Student()
	{
		SetCName("None");
		SetPEnrolled("none");
		SetCurrSem(0);
	}

	Student(string cn, string pe, int cs, string n, int a) : Person(n, a)
	{
		SetCName(cn);
		SetPEnrolled(pe);
		SetCurrSem(cs);
	}

	void SetCName(string cn)
	{
		this->collegeName = cn;
	}
	virtual string GetCName() const
	{
		return collegeName;
	}

	void SetPEnrolled(string pe)
	{
		this->programEnrolled = pe;
	}
	virtual string GetPEnrolled() const
	{
		return programEnrolled;
	}

	void SetCurrSem(int cs)
	{
		this->currentSemester = cs;
	}
	virtual int GetCurrSem() const
	{
		return currentSemester;
	}
};

class NonGamingStudent : public Student
{
protected:
	string prefStreamServ;
	int hrNonGmEnt;
	bool gamr;
public:
	NonGamingStudent()
	{
		SetPrefStream("none");
		SetHrsNonGm(0);
		Setgamer(false);
	}

	NonGamingStudent(string pss, int hrs, string cn, string pe, int cs, string n, int a, bool gam) : Student(cn, pe, cs ,n , a)
	{
		SetPrefStream(pss);
		SetHrsNonGm(hrs);
		Setgamer(gam);
	}

	void Setgamer(bool gam)
	{
		this->gamr = gam;
	}
	virtual bool Getgamer() const
	{
		return gamr;
	}

	void SetPrefStream(string pss)
	{
		this->prefStreamServ = pss;
	}
	virtual string GetPrefStream() const
	{
		return prefStreamServ;
	}

	void SetHrsNonGm(int hrs)
	{
		this->hrNonGmEnt = hrs;
	}
	virtual int GetHrsNonGm() const
	{
		return hrNonGmEnt;
	}
};

class GamingStudent : public Student
{
protected:
	string prefGmDev;
	int hoursGam;
	bool gamr;
public:
	GamingStudent()
	{
		SetPrefGameDev("none");
		SetHrsGame(0);
		Setgamer(false);
	}

	GamingStudent(string pgd, int hrsgm, string cn, string pe, int cs, string n, int a, bool gam) : Student(cn, pe, cs, n, a)
	{
		SetPrefGameDev(pgd);
		SetHrsGame(hrsgm);
		Setgamer(gam);
	}

	void Setgamer(bool gam)
	{
		this->gamr = gam;
	}
	virtual bool Getgamer() const
	{
		return gamr;
	}

	void SetPrefGameDev(string pgd)
	{
		this->prefGmDev = pgd;
	}
	virtual string GetPrefGameDev() const
	{
		return prefGmDev;
	}

	void SetHrsGame(int hrsgm)
	{
		this->hoursGam = hrsgm;
	}
	virtual int GetHrsGame() const
	{
		return hoursGam;
	}
};

class Survey
{
protected:
	Person list[500];
	int numPeeps;
public:
	Survey()
	{
		SetPeeps(0);
		for (int i = 0; i < 500; i++)
		{
			list[i] = Person();
		}
	}

	Survey(int numP, Person l[])
	{
		SetPeeps(numP);
		for (int a = 0; a < numPeeps; a++)
		{
			list[a] = l[a];
		}
	}

	void SetPeeps(int numP)
	{
		this->numPeeps = numP;
	}
	virtual int GetPeeps() const
	{
		return numPeeps;
	}

	/*void ProcessSurvey()
	{
		for (int a = 0; a < numPeeps; a++)
		{
			if(list[a].NonGamingStudent::gamr)
		}
	}*/
};