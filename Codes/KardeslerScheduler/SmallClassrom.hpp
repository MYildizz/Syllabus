#ifndef SMALLCLASSROM_H_
#define	SMALLCLASSROM_H_	

#include "Classrom.hpp"

class SmallClassrom : public Classrom
{
	
public:
	SmallClassrom() : Classrom ()
	{
	}
   
	~SmallClassrom(){
	
	}
	static int NumberOfSmallClassrom;
};
#endif