#ifndef COMPULSORYCOURSE_H_
#define	COMPULSORYCOURSE_H_	

#include "Course.hpp"

class compulsoryCourse : public Course
{

public:
	compulsoryCourse(string courseCode, string courseName, string courseSemasterYear, 
		string credit, string Status, string DepartOrSer , string courseinstructor, bool isServiceB) : Course(courseCode,courseName,courseSemasterYear,
			credit, Status, DepartOrSer, courseinstructor, isServiceB)
	{	
		courseCode = courseCode;
		courseName = courseName;
		courseSemasterYear = courseSemasterYear;
		credit = credit;
		Status = Status;
		DepartOrSer = DepartOrSer;
		courseinstructor = courseinstructor;

		//setBusy("" , "");  //setBusy Parametere olarak String ald?g? icin NULL ya da nullptr kabul etmiyor.
						   //kontrol ederken bos olup olmamas?na gore kontrol ederiz.
	}
	~compulsoryCourse() {
	}

	/*void toString() {
		cout << courseCode << " " << courseName << " " << courseSemasterYear << " "
			<< credit << " " << Status << " " << DepartOrSer <<
			" " << courseinstructor;
	}*/

	void toShowBusy() {
		if (BusyDays.size() != 0 && BusyTimes.size() != 0)
		{
			cout << "Course CODE: " << courseCode<< "\n";
			for (int i = 0; i < BusyDays.size(); i++)
			{
				cout << BusyDays.at(i) << " " << BusyTimes.at(i);
				cout << "\n";
			}

			cout << "\n";
		}


	}


};

#endif