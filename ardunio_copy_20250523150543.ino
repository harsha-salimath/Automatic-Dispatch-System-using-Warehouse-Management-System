// Arduino Code for EM-18 RFID Module
  #include<SoftwareSerial.h>
  SoftwareSerial rfidSerial(7,3);

  String rfidUID = "";
  String rfidID = "";

  void productdispatch();
  void database();
  void setup() {
  Serial.begin(9600);
  rfidSerial.begin(9600);
  Serial.println("RFID Dispatch System - Room A");
}

void loop() {
  productdispatch();
   database(); 
}
void productdispatch(){
   if (Serial.available() > 0) {
    char ch = Serial.read();
    rfidUID += ch;
    
    if (rfidUID.length() >= 12) { // EM-18 sends 12 characters
      Serial.println(rfidUID);    // Send UID to PC
      delay(100);                // Debounce
       if(rfidUID == "4900F814DF7A"){
         Serial.println(" moved to Room A");
     delay(1000);
   //  rfidUID="";
    } 
    }
  }
}
void database(){
   if (rfidSerial.available() > 0) {
    char ch = rfidSerial.read();
    rfidID += ch;
    
    if (rfidID.length() >= 12) { // EM-18 sends 12 characters
      Serial.println(rfidID);    // Send UID to PC
      delay(100);                // Debounce
     if(rfidID == "4900F814DF7A"){
         Serial.println(" moved to Room B");
     delay(1000);
      rfidID="";
    }
    }
   }
}
    
