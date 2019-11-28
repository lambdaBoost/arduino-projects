#include <EEPROM.h>;
String SID="WIFI-NAME";
String PASS="PASSWORD";
String API="API-KEY";


void setup() {
      EEPROM_writeString(1, SID);
      EEPROM_writeString(128, PASS);
      EEPROM_writeString(256, API); 
}

void loop() {
  // put your main code here, to run repeatedly:

}




///////////EEPROM functions
void EEPROM_writeString(int add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.update(add+i,data[i]);
  }
  EEPROM.update(add+_size,'\0');   //Add termination null character for String Data

}
 
 
String EEPROM_readString(int add)
{
  int i;
  char data[50]; //Max 50 Bytes - may need to optimise this if dynamic memory becomes an issue
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
