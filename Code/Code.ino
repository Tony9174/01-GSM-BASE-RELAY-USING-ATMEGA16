                      ////////////////////////
                     ////Tony////////////////
                    ///////Tech/////////////
                   ///////////1220/////////
                  ////////////////////////
    
                    char Byte; 
                    String string;
                      void setup() 
                           {
                           pinMode(13, OUTPUT);   //Relay
                           digitalWrite(13, LOW); //Relay oFF
                           Serial.begin(9600);    
                           while(!Serial.available())
                                {
                                Serial.println("AT");
                                delay(300); 
                                }
                           delay(5000);
                           Serial.println("AT+CMGF=1"); //messege mode
                           delay(1000);  
                           Serial.println("AT+CNMI=1,2,0,0,0");  //new messege come first
                           delay(1000);
                           Serial.println("AT+CMGDA=\"DEL ALL\""); //Del all messege for space
                           delay(1000);
                           Serial.println("AT+CMGL=\"REC UNREAD\"");  //read unread 
                           }
        
        
                      void loop()
                           {  
                           if(Serial.available())
                                    {
                                    delay(100);
                                    while(Serial.available())
                                         {
                                          Byte = Serial.read();
                                          string += Byte; 
                                         }
                                    delay(100);      
                                    string.toUpperCase();   //all char of messege are in uppercase
                                    if (string.indexOf("ON") > -1)  // if on
                                       {
                                       digitalWrite(13, HIGH); //Relay Is On
                                       }
                                    if (string.indexOf("OFF") > -1)   //off
                                       {
                                       digitalWrite(13, LOW);   //Relay is Off
                                       }          
                                     delay(1000);
                               string = "";     //clear The string
                                     }
                            }
