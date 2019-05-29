#ifndef ELECTIVECOURSE_H_
#define	ELECTIVECOURSE_H_	

#include "Course.hpp"

class electiveCourse : public Course
{

public:
	electiveCourse(string courseCode, string courseName, string courseSemasterYear,
		string credit, string Status, string DepartOrSer, string courseinstructor, bool isServiceB)
		: Course(courseCode, courseName, courseSemasterYear, credit, Status, DepartOrSer, courseinstructor,isServiceB)
	{
		courseCode = courseCode;
		courseName = courseName;
		courseSemasterYear = courseSemasterYear;
		credit = credit;
		Status = Status;
		DepartOrSer = DepartOrSer;
		courseinstructor = courseinstructor;
		setBusy("", "");
	}
	~electiveCourse() {

	}

	/*void toString() {
		cout << courseCode << " " << courseName << " " << courseSemasterYear << " "
			<< credit << " " << Status << " " << DepartOrSer <<
			" " << courseinstructor;
	}*/
};

#endif // !ELECTIVECOURSE_H_