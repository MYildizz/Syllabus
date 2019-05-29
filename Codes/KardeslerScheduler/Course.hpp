#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

 class  Course
{
protected:
	//string courseCode;
	string courseName;
	string courseSemasterYear;
	string credit;
	string Status;
	string DepartOrSer;
	string courseinstructor;
	vector <string>BusyTimes;
	vector <string>BusyDays;
	bool isService; // Servis Kurs ise true olacak degilse false
	//string ServiceDay;      /* Eðer objenin isService elemani true ise set fonksiyonu ile bunlari  doldurcaz degilse null string ile doldurcaz*/
	//string ServiceTime;
	
public:	
	string courseCode;
	string ServiceDay;      /* Eðer objenin isService elemani true ise set fonksiyonu ile bunlari  doldurcaz degilse null string ile doldurcaz*/
	string ServiceTime;
	Course() {
	}
	Course(string courseC, string courseN, string courseSY, 
	string crdt, string Stts,string DepartmentOrS, string courseIns,bool isServiceB) {
	
		courseCode = courseC;
		courseName = courseN;
		courseSemasterYear = courseSY;
		credit = crdt;
		Status = Stts;
		DepartOrSer = DepartmentOrS;
		courseinstructor = courseIns;
		isService = isServiceB;
		ServiceDay = "";
		ServiceTime = "";
	}
	~Course()
	{
	}

	void setBusy(string Bday, string Btime) {
		BusyDays.push_back(Bday);
		BusyTimes.push_back(Btime);
	}

	int checkBusy(string day, string time)
	{
		if (BusyDays.empty() == true)
			return 1;

		for (int i = 0; i < BusyDays.size(); i++)
		{
			if(BusyDays[i]==day)
			{ 
				for (int k = 0; k < BusyTimes.size(); k++)
				{
					if (BusyTimes[k]==time)
						return 0;

				}
			}
		}
		return 1;
	}

	void setService(string Sday, string Stime) {
		ServiceDay = Sday;
		ServiceTime = Stime;
	}

	void toString() {

			
		cout << courseCode << " " << courseName << " " << courseSemasterYear << " "
			<< credit << " " << Status << " " << DepartOrSer <<
			" " << courseinstructor;
		if (isService && ServiceDay != "")
		{
			cout << " ||| Service Day:" << ServiceDay << " Service Time:" << ServiceTime << "\n";
		}
		else {
			cout << "\n";
		}
		
		
	}

	bool isEqual(string CCod) {

		if (CCod == courseCode)
		{
			return true;
		}
		else {
			return false;
		}

	}
};
#endif