#ifndef SCHEDULER_H_
#define SCHEDULER_H_


#include "compulsoryCourse.hpp"
#include "electiveCourse.h"
#include "BigClassrom.hpp"
#include "SmallClassrom.hpp"



static vector<electiveCourse> ElectiveCourseList;
static vector<compulsoryCourse> Compulsory_CourseList;



class Scheduler
{

public:

   Scheduler(){
   }
   
   
   ~Scheduler() {
         
   }

   static void readCourse();
   static void controlVectors();
   static void createClasses();
   static void readServiceCourse();
   static void SetServiceCourse(string,string,string);
   static void SetBusyDaysAndTimes();
   static void arrange(string, string, string);
   static void showBusyCourses();
   static void AllocateCourses();
};

#endif