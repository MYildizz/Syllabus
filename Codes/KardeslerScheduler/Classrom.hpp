#ifndef CLASSROM_H_
#define CLASSROM_H_
#include <iostream>
#include <string>

using namespace std;

static string constant = "-------------";

class Classrom
{  
public:
   string morning = constant;
   string afternoon = constant;

   Classrom(){
   }
   
   /* void setMoning(string m){
      morning = m;
   }
   
   void setAfternoon(string a){
      morning = a;
   } */       // DEGISKENLERI PUBLIC YAPIP GETTER SETTER KOYAN HANGI GERIZEKALI ? KENDI SILSIN ONU BURDAN DIYE BEN SILMIYOM
   
   ~Classrom() {
   }
};
#endif