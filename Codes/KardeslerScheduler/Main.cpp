#ifndef Course
using namespace std;
#include "Scheduler.hpp"


int main(){

  	Scheduler::readCourse();	
	Scheduler::readServiceCourse();
	Scheduler::controlVectors();
	Scheduler::createClasses();
	Scheduler::SetBusyDaysAndTimes();
	Scheduler::showBusyCourses();
	Scheduler::AllocateCourses();

}
#endif