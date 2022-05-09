#include <LiquidCrystal_I2C.h>
#include <hiduniversal.h>
#include <usbhid.h>
#include <Usb.h>
#include <usbhub.h>
#include <hidboot.h>

LiquidCrystal_I2C lcd (0x27, 16,2);  
USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);

#include <SPI.h>
String ScanCode = "";
int i=1;
int a=0;


class KbdRptParser : public KeyboardReportParser
{
  
  protected:    

    void OnKeyDown  (uint8_t mod, uint8_t key);    
    void OnKeyPressed(uint8_t key);
};


void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  
//  PrintKey(mod, key);
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
    
}


//******************* Barcode ********************
void KbdRptParser::OnKeyPressed(uint8_t key)
{  
   ScanCode = ScanCode + String((char)key);
            
}


KbdRptParser Prs;

void setup()
{
  Serial.begin( 115200 );
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
  digitalWrite(16, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(12, LOW);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(12, OUTPUT);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect boards with built-in USB CDC serial connection
#endif
  Serial.println("Start");

  if (Usb.Init() == -1)
    Serial.println("OSC did not start.");

  delay( 200 );

  Hid.SetReportParser(0, &Prs);

     // Initialize the LCD connected 
  lcd. init ();
  
  // Turn on the backlight on LCD. 
  lcd. backlight ();
}

void loop()
{
  delay(1);
  Usb.Task();
  i=i+1;
  if(i==2000){    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vending Machine");
    if(ScanCode!=""){
      a+=1;
      if(a==1){          
        lcd.clear();
        lcd.print("Despachando..13");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, LOW);
        digitalWrite(15, HIGH);
        delay(300); 
        digitalWrite(15, LOW);
        delay(300);
        digitalWrite(13, LOW);
        digitalWrite(2, HIGH);
        delay(300); 
        digitalWrite(2, LOW);
        digitalWrite(12, LOW);  
          ScanCode="";
      }
      else if(a==2){          
        lcd.clear();
        lcd.print("Despachando..29");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, HIGH);
        digitalWrite(15, HIGH);
        delay(300); 
        digitalWrite(15, LOW);
        delay(300);
        digitalWrite(13, LOW);
        digitalWrite(3, HIGH);
        delay(300); 
        digitalWrite(3, LOW);
        digitalWrite(12, LOW);  
        ScanCode="";
      }
      else if(a==3){          
        lcd.clear();
        lcd.print("Despachando..40");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, HIGH);
        digitalWrite(2, HIGH);
        delay(300); 
        digitalWrite(2, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        delay(300); 
        digitalWrite(3, LOW);
        digitalWrite(12, LOW); 
        ScanCode="";
      }
      else if(a==4){          
        lcd.clear();
        lcd.print("Despachando..45");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, HIGH);
        digitalWrite(2, HIGH);
        delay(300); 
        digitalWrite(2, LOW);
        delay(300);
        digitalWrite(13, LOW);
        digitalWrite(4, HIGH);
        delay(300); 
        digitalWrite(4, LOW);
        digitalWrite(12, LOW);  
        ScanCode="";
        }
       else if(a==5){          
        lcd.clear();
        lcd.print("Despachando..58");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, LOW);
        digitalWrite(4, HIGH);
        delay(300); 
        digitalWrite(4, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        digitalWrite(16, HIGH);
        delay(300); 
        digitalWrite(16, LOW);
        digitalWrite(12, LOW); 
        ScanCode="";
       }
       else if(a==6){          
        lcd.clear();
        lcd.print("Despachando..67");
        lcd.setCursor(0, 1);      
        lcd.print(ScanCode);
        digitalWrite(12, HIGH);      
        digitalWrite(13, HIGH);
        digitalWrite(4, HIGH);
        delay(300); 
        digitalWrite(4, LOW);
        delay(300);
        digitalWrite(13, LOW);
        digitalWrite(16, HIGH);
        delay(300); 
        digitalWrite(16, LOW);
        digitalWrite(12, LOW);
        a=0;  
        ScanCode="";
      }
    }     
  i=0;  
  }
}



