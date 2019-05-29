#include "Scheduler.hpp"
int BigClassrom::NumberOfBigClassrom = 0;
int SmallClassrom::NumberOfSmallClassrom = 0;


void Scheduler::readCourse() {
	{
		string line = "";

		string arr[7];
		int sayac = 0;
		ifstream file("courses.csv");
		if (file.is_open())
		{

			while (getline(file, line))
			{
				sayac++;

				vector <string> tokens;
				stringstream check1(line);
				string intermediate;

				while (getline(check1, intermediate, ';'))
				{
					tokens.push_back(intermediate);
				}

				//Printing the token vector 
				/*for (int i = 0; i < tokens.size(); i++) {
					cout << tokens[i] << " ";
				}*/
				

				if (tokens[4] == "C") {
					bool service = tokens[5] == "S" ? true : false;
					
					compulsoryCourse tmp(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6],service);
					//tmp.toString();
					Compulsory_CourseList.push_back(tmp);
				}
				else if (tokens[4] == "E") {
					bool service = tokens[5] == "S" ? true : false;

					electiveCourse tmp2(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6],service);
					//tmp2.toString();
					ElectiveCourseList.push_back(tmp2);
				}
			//	cout << endl;

			}

		}
		else {
			cout << "File cannot be read";
		}
	}
}

void Scheduler::controlVectors()
{
	cout << "Elective Courses\n------------------------\n\n";
	for (int i = 0; i < ElectiveCourseList.size(); i++)
	{
		ElectiveCourseList.at(i).toString();
	}
	cout << "\nCompulsory Courses\n-------------------\n\n";

	for (int i = 0; i < Compulsory_CourseList.size(); i++)
	{
		Compulsory_CourseList.at(i).toString();
	}


	cout << "\nCompulsory Vector size: " << Compulsory_CourseList.size() << endl;
	cout << "Elective Vector size: " << ElectiveCourseList.size() << endl;

}

void Scheduler::createClasses() {
	string line = "";

	ifstream file("classroom.csv");

	if (file.is_open())
	{
		
		while (getline(file, line))
		{
			vector <string> tokens;
			stringstream check1(line);
			string intermediate;

			while (getline(check1, intermediate, ';'))
			{
				tokens.push_back(intermediate);
			}

			/*//Printing the token vector 
			for (int i = 0; i < tokens.size(); i++) {
				cout << tokens[i] << " ";
			}*/
			
			if (tokens[0] == "bigClass") {

				istringstream iss(tokens[1]);
				iss >> BigClassrom::NumberOfBigClassrom; //Parse value string to integer and assign to NumberOfBigClassrom 

			}
			else if (tokens[0] == "smallClass") {

				istringstream iss(tokens[1]);
				iss >> SmallClassrom::NumberOfSmallClassrom; //Parse value string to integer and assign to NumberOfSmallClassrom 

			}
		}
	}
	else {

	}

	cout << "Num of Big Classes: " << BigClassrom::NumberOfBigClassrom << endl;
	cout << "Num of Small Classes: " << SmallClassrom::NumberOfSmallClassrom << endl;

}

void Scheduler::SetServiceCourse(string CourseCOD,string Sday,string Stime) {
	int adress = 0;
	bool isFound = false;

	for (int i = 0; i < ElectiveCourseList.size(); i++)
	{

		isFound = ElectiveCourseList.at(i).isEqual(CourseCOD);
		if (isFound)
		{
			adress = i;
			break;
		}

	}

	if (isFound)
	{
		ElectiveCourseList.at(adress).setService(Sday, Stime);

	}
	else {
		for (int i = 0; i < Compulsory_CourseList.size(); i++)
		{
			isFound = Compulsory_CourseList.at(i).isEqual(CourseCOD);
			if (isFound)
			{
				adress = i;
				break;
			}
		}
		Compulsory_CourseList.at(adress).setService(Sday, Stime);

	}

}

void Scheduler::readServiceCourse() {

	string line = "";

	ifstream file("service.csv");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vector <string> tokens;
			stringstream check1(line);
			string intermediate;

			while (getline(check1, intermediate, ';'))
			{
				tokens.push_back(intermediate);
			}
			SetServiceCourse(tokens[0], tokens[1], tokens[2]);

		}

	}
	else {
		cout << "File cannot be opened! \n";
	}

}


void Scheduler::arrange(string cCode, string cBusyDay, string cBusyTime) {
	int adress = 0;
	bool isFound = false;

	for (int i = 0; i < ElectiveCourseList.size(); i++)
	{

		isFound = ElectiveCourseList.at(i).isEqual(cCode);
		if (isFound)
		{
			adress = i;
			break;
		}

	}

	if (isFound)
	{
		ElectiveCourseList.at(adress).setBusy(cBusyDay, cBusyTime);
	}
	else {
		for (int i = 0; i < Compulsory_CourseList.size(); i++)
		{
			isFound = Compulsory_CourseList.at(i).isEqual(cCode);
			if (isFound)
			{
				adress = i;
				break;
			}
		}
		Compulsory_CourseList.at(adress).setBusy(cBusyDay, cBusyTime);

	}

}

void Scheduler::SetBusyDaysAndTimes() {
	string line = "";

	ifstream file("busy.csv");

	if (file.is_open())
	{
		while (getline(file, line))
		{

			vector <string> tokens;
			stringstream check1(line);
			string intermediate;

			while (getline(check1, intermediate, ';'))
			{
				tokens.push_back(intermediate);
			}

			arrange(tokens[0], tokens[1], tokens[2]);
		}

	}
	else {
		cout << "File Cannot Be Opened !";
	}


}

void Scheduler::showBusyCourses() {
	cout << "\n\n-----------------------------------\n\nCOURSES THAT HAVE BUSY DAY AND TIME\n\n------------------------------------\n\n";
	for (int i = 0; i < Compulsory_CourseList.size(); i++)
	{
		Compulsory_CourseList.at(i).toShowBusy();
	}

}

void Scheduler::AllocateCourses()
{
	cout << "**************************************" << endl;
	cout << "*              SYLLABUS              *" << endl;
	cout << "**************************************" << endl;


	string BigClass1[2][5] = { {"*","*","*","*","*"},{"*","*","*","*","*"} };
	string BigClass2[2][5] = { {"*","*","*","*","*"},{"*","*","*","*","*"} };
	string SmallClass[2][5] = { {"*","*","*","*","*"},{"*","*","*","*","*"} };
	string DayTime[2][5] = { {"Monday    Morning  ","Thuesday  Morning  ","Wednesday Morning  ","Thursday  Morning  ","Friday    Morning  "},
		{"Monday    Afternoon","Thuesday  Afternoon","Wednesday Afternoon","Thursday  Afternoon","Friday    Afternoon"} };

	vector <string> exposed;

	string days[5] = { "Monday","Tuesday","Wednesday","Thursday","Friday" };
	string times[2] = { "Morning","Afternoon" };

	int day=0, time=0;

	for (int i = 0; i < Compulsory_CourseList.size(); i++)
	{
		int k = 0,l=0;
		if (Compulsory_CourseList[i].ServiceDay != "")
		{
			for (k = 0; k < 5; k++)
			{
				if (Compulsory_CourseList[i].ServiceDay == days[k])
					break;
			}

			for (l = 0; l < 2; l++)
			{
				if (Compulsory_CourseList[i].ServiceTime == times[l])
					break;
			}

			if (BigClass1[l][k] == "*")
				BigClass1[l][k] = DayTime[l][k] + " BigClass1  " + Compulsory_CourseList[i].courseCode;
			else if (BigClass2[l][k] == "*")
				BigClass2[l][k] = DayTime[l][k] + " BigClass2  " + Compulsory_CourseList[i].courseCode;
			else if (SmallClass[l][k] == "*")
				SmallClass[l][k] = DayTime[l][k] + " SmallClass " + Compulsory_CourseList[i].courseCode;
			else
				exposed.push_back("No class found for " + Compulsory_CourseList[i].courseCode + " course");
			
		}

	}

	for (int i = 0; i < ElectiveCourseList.size(); i++)
	{

		int k = 0, l = 0;
		if (ElectiveCourseList[i].ServiceDay != "")
		{
			for (k = 0; k < 5; k++)
			{
				if (ElectiveCourseList[i].ServiceDay == days[k])
					break;
			}

			for (l = 0; l < 2; l++)
			{
				if (ElectiveCourseList[i].ServiceTime == times[l])
					break;
			}

			if (SmallClass[l][k] == "*")
				SmallClass[l][k] = DayTime[l][k] + " SmallClass " + ElectiveCourseList[i].courseCode;
			else if (BigClass2[l][k] == "*")
				BigClass2[l][k] = DayTime[l][k] + " BigClass2  " + ElectiveCourseList[i].courseCode;
			else if (SmallClass[l][k] == "*")
				BigClass1[l][k] = DayTime[l][k] + " BigClass1  " + ElectiveCourseList[i].courseCode;
			else
				exposed.push_back("No class found for " + Compulsory_CourseList[i].courseCode + " course");

		}

	}

	int i = 0;
	while (i < 16)
	{
		int checkExit = 0;

		if (checkExit == 0)
		{
			for (day = 0; day < 5; day++)
			{

				for (time = 0; time < 2; time++)
				{

					if (Compulsory_CourseList[i].checkBusy(days[day], times[time]) == 1 && Compulsory_CourseList[i].ServiceDay == "" && checkExit == 0)
					{
						if (BigClass1[time][day] == "*")
						{
							BigClass1[time][day] = DayTime[time][day] + " BigClass1  " + Compulsory_CourseList[i].courseCode;
							checkExit = 1;

						}
						
					}
				}

			}
		}

		if (checkExit == 0)
		{
			for (day = 0; day < 5; day++)
			{

				for (time = 0; time < 2; time++)
				{

					if (Compulsory_CourseList[i].checkBusy(days[day], times[time]) == 1 && Compulsory_CourseList[i].ServiceDay == "" && checkExit == 0)
					{
						if (BigClass2[time][day] == "*")
						{
							BigClass2[time][day] = DayTime[time][day] + " BigClass2  " + Compulsory_CourseList[i].courseCode;
							checkExit = 1;

						}
					}
				}

			}
		}

		if (checkExit == 0  && Compulsory_CourseList[i].ServiceDay == "")
			exposed.push_back("No class found for " + Compulsory_CourseList[i].courseCode + " course");


		i++;
		
	}
		
	i = 0;
	while (i < 15)
	{
		int checkExit = 0;

		if (checkExit == 0)
		{
			for (day = 0; day < 5; day++)
			{

				for (time = 0; time < 2; time++)
				{

					if (ElectiveCourseList[i].checkBusy(days[day], times[time]) == 1 && ElectiveCourseList[i].ServiceDay == "" && checkExit == 0)
					{
						if (BigClass1[time][day] == "*")
						{
							BigClass1[time][day] = DayTime[time][day] + " BigClass1  " + ElectiveCourseList[i].courseCode;
							checkExit = 1;

						}

					}
				}

			}
		}

		if (checkExit == 0)
		{
			for (day = 0; day < 5; day++)
			{

				for (time = 0; time < 2; time++)
				{

					if (ElectiveCourseList[i].checkBusy(days[day], times[time]) == 1 && ElectiveCourseList[i].ServiceDay == "" && checkExit == 0)
					{
						if (BigClass2[time][day] == "*")
						{
							BigClass2[time][day] = DayTime[time][day] + " BigClass2  " + ElectiveCourseList[i].courseCode;
							checkExit = 1; 

						}
					}
				}

			}
		}

		if (checkExit == 0)
		{
			for (day = 0; day < 5; day++)
			{

				for (time = 0; time < 2; time++)
				{

					if (ElectiveCourseList[i].checkBusy(days[day], times[time]) == 1 && ElectiveCourseList[i].ServiceDay == "" && checkExit == 0)
					{
						if (SmallClass[time][day] == "*")
						{
							SmallClass[time][day] = DayTime[time][day] + " SmallClass " + ElectiveCourseList[i].courseCode;
							checkExit = 1;

						}

					}
				}

			}
		}

		if (checkExit == 0 && ElectiveCourseList[i].ServiceDay == "")
			exposed.push_back("No class found for "+ElectiveCourseList[i].courseCode+" course");
			

		i++;

	}


	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << BigClass1[k][i] <<endl;
			cout << BigClass2[k][i] << endl;
			cout << SmallClass[k][i] << endl;
			
		}
		cout << "" << endl;

	}

	cout << "**************************************" << endl;
	cout << "" << endl;
	

	for (int i = 0; i < exposed.size(); i++)
		cout << exposed[i]<<endl;

	cout << "*********************************" << endl;

	ofstream allocation;
	allocation.open("allocation.txt");

	allocation << "**************************************" << endl;
	allocation << "*              SYLLABUS              *" << endl;
	allocation << "**************************************" << endl;



	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			allocation << BigClass1[k][i] << endl;
			allocation << BigClass2[k][i] << endl;
			allocation << SmallClass[k][i] << endl;

		}
		allocation << "" << endl;

	}

	allocation << "**************************************" << endl;
	allocation << "" << endl;


	for (int i = 0; i < exposed.size(); i++)
		allocation << exposed[i] << endl;

	allocation << "*********************************" << endl;
	cout << "" << endl;
	

	cout << "course program written to file" << endl;
	cout << "******************************" << endl;
}