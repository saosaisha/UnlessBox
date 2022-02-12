
/*Unless  Box Attiny85 Digispark
 * https://www.youtube.com/c/Radal05/videos
 * 05 Januari 2022
 * 
 */
#include <SoftRcPulseOut.h> 
int switchStatus=0, action=1, vot, randNumber=0;
 
SoftRcPulseOut handServo;
SoftRcPulseOut boxServo;
// a maximum of eight servo objects can be created 
#define handServoPin      3 //PB3
#define frontSwitchPin    2 //PB2 
#define ledPin            1 //PB1
#define boxServoPin       4 //PB0
#define REFRESH_PERIOD_MS 20
#define NOW               1


int pos = 0;    // variable to store the servo position 

 
void setup() 
{ 
  pinMode(ledPin, OUTPUT);         //Tentukan pin LED sebagai output
  digitalWrite(ledPin,HIGH);
  handServo.attach(handServoPin); // Untuk menonaktifkan saklar
  boxServo.attach(boxServoPin);   // Untuk buka box
             
  /* 
   *  Set awal servo
   */
   
  boxServo.write(90);
   delay(REFRESH_PERIOD_MS);        // waits 20ms for refresh period 
    SoftRcPulseOut::refresh(NOW);
   digitalWrite(ledPin,LOW); 
  
} 
 
 
void loop() 
{ 
  switchStatus = digitalRead(frontSwitchPin);
  if (switchStatus == LOW){
    
/*
 * Aksi pertama
 * pukul 5x
 * buka lambat tutup cepat
 */
    if (action == 1)
    { 
     delay(1000);
     digitalWrite(ledPin,HIGH);
     for(int i=1; i<=5; i++){
      for(pos = 90; pos >=70; pos -= 1)
      {
        boxServo.write(pos); // Gerak 2x
        delay(2);
        SoftRcPulseOut::refresh(NOW);        
        }

      for(pos = 70; pos <=90; pos += 1) 
      {
        boxServo.write(pos);
        delay(2);
        SoftRcPulseOut::refresh(NOW);
        }  
     }

        //**********//
      delay(1000);
      for(pos = 90; pos <=160; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(20);
        SoftRcPulseOut::refresh(NOW);
        }
        delay(1000);

         for(pos = 90; pos <=160; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(20);
        SoftRcPulseOut::refresh(NOW);
        }
     delay (3000);
      for(pos = 160; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(2);
        SoftRcPulseOut::refresh(NOW);        
        }
        delay(2000);
        digitalWrite(ledPin,LOW);
        delay(2000);
      action++;
    }
/*
 * Aksi kedua
 * buka lambat 
 * Nyalakan lampu selama 3 detik
 * Tutup lambat
 */
    else if (action == 2)
    {
      delay(1000);
      for(pos = 90; pos <=160; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(100);
        SoftRcPulseOut::refresh(NOW);
        }
        delay(1000);
        digitalWrite(ledPin,HIGH);
        delay(3000);
        
     
      for(pos = 160; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(100);
        SoftRcPulseOut::refresh(NOW);        
        }
        digitalWrite(ledPin,LOW);
        delay(2000);
      action++;
    }
    /*
     * Aksi 3
     * intip buka lambat selama 3 detik
     * tutup cepat
     */

    else if (action == 3)
    {
      delay(1000);
      for(pos = 90; pos <=170; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(100);
        SoftRcPulseOut::refresh(NOW);
        }
     delay(3000);
      for(pos = 170; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(20);
        SoftRcPulseOut::refresh(NOW);        
        }
        delay(2000);
      action++;
    }
    /*
     * Aksi 4
     * Buka perlahan
     * Diam 3 detik
     * Tutup perlahan
     * buka tutup sedikit 4x cepat
     */
    
    else if (action == 4)
    {
      delay(1000);
      for(pos = 90; pos <=170; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(100);
        SoftRcPulseOut::refresh(NOW);
        }
        
        digitalWrite(ledPin,HIGH);
        delay(3000);
        digitalWrite(ledPin,LOW);
     
      for(pos = 170; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(100);
        SoftRcPulseOut::refresh(NOW);        
        }

digitalWrite(ledPin,HIGH);        

     for(int i=1; i<=7; i++){
      for(pos = 90; pos <=150; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(2);
        SoftRcPulseOut::refresh(NOW);
        }        
            
      for(pos = 150; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(2);
        SoftRcPulseOut::refresh(NOW);        
        }
      
      
     }
        digitalWrite(ledPin,LOW);
        delay(2000);
      action++;
    }

    /*
     * Aksi 5
     * Getar 10x
     * delay 3 detik
     * getar 10x
     * Buka cepat
     * delay 3 detik
     * tutup lambat
     */
      else if (action == 5)
    {
      delay(1000);
     for(int i=1; i<=10; i++){
      for(pos = 90; pos >=70; pos -= 1)
      {
        boxServo.write(pos); // Gerak 2x
        delay(2);
        SoftRcPulseOut::refresh(NOW);        
        }

      for(pos = 70; pos <=90; pos += 1) 
      {
        boxServo.write(pos);
        delay(2);
        SoftRcPulseOut::refresh(NOW);
        }     
     }

     delay(3000);

     for(int i=1; i<=10; i++){
      for(pos = 90; pos >=70; pos -= 1)
      {
        boxServo.write(pos); // Gerak 2x
        delay(2);
        SoftRcPulseOut::refresh(NOW);        
        }

      for(pos = 70; pos <=90; pos += 1) 
      {
        boxServo.write(pos);
        delay(2);
        SoftRcPulseOut::refresh(NOW);
        }     
     }

     delay(1000);
      for(pos = 90; pos <=120; pos += 1) //Buka box cepat tutup lambat
      {
        boxServo.write(pos);
        delay(20);
        SoftRcPulseOut::refresh(NOW);
        }
     delay(3000);
      for(pos = 120; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(100);
        SoftRcPulseOut::refresh(NOW);        
        }
        
     delay(1000);
      for(pos = 90; pos <=160; pos += 1) //Buka box cepat tutup lambat
      {
        boxServo.write(pos);
        delay(20);
        SoftRcPulseOut::refresh(NOW);
        }
     delay(3000);
      for(pos = 160; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(100);
        SoftRcPulseOut::refresh(NOW);        
        }
        delay(2000);
      action++;
    }
    
    /*
       * Aksi 6
       */

       else if (action == 6)    
                
    {
      digitalWrite(ledPin,HIGH);        

     for(int i=1; i<=7; i++){
      for(pos = 90; pos <=160; pos += 1) //Buka box lambat tutup cepat
      {
        boxServo.write(pos);
        delay(40);
        SoftRcPulseOut::refresh(NOW);
        }        
            
      for(pos = 160; pos >=90; pos -= 1)
      {
        boxServo.write(pos); // Tutup Box
        delay(40);
        SoftRcPulseOut::refresh(NOW);        
        }
      
      
     }
        digitalWrite(ledPin,LOW);
        delay(2000);
      
      action++;
    }

    /*
       * Aksi 7
       */
    else if (action == 7)
    {    
       
        action = 1;  // Kembali ke awal              

   }
  }
} 
