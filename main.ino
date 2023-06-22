#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const int irSensorPin1 = 2; // IR sensor input pin for lane 1
const int irSensorPin2 = 3; // IR sensor input pin for lane 2
const int irSensorPin3 = 4; // IR sensor input pin for lane 3
const int irSensorPin4 = 5; // IR sensor input pin for lane 4
const int redLED1 = 6; // Red LED pin for traffic signal in lane 1
const int greenLED1 = 7; // Green LED pin for traffic signal in lane 1
const int redLED2 = 8; // Red LED pin for traffic signal in lane 2
const int greenLED2 = 9; // Green LED pin for traffic signal in lane 2
const int redLED3 = 10; // Red LED pin for traffic signal in lane 3
const int greenLED3 = 11; // Green LED pin for traffic signal in lane 3
const int redLED4 = 12; // Red LED pin for traffic signal in lane 4
const int greenLED4 = 13; // Green LED pin for traffic signal in lane 4

int trafficDensity1; // variable to store traffic density for lane 1
int trafficDensity2; // variable to store traffic density for lane 2
int trafficDensity3; // variable to store traffic density for lane 3
int trafficDensity4; // variable to store traffic density for lane 4

void setup() {
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
  pinMode(irSensorPin3, INPUT);
  pinMode(irSensorPin4, INPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  pinMode(redLED3, OUTPUT);
  pinMode(greenLED3, OUTPUT);
  pinMode(redLED4, OUTPUT);
  pinMode(greenLED4, OUTPUT);
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  
  Serial.begin(9600);
  
}

void loop() {
  // Measure traffic density using IR sensors for both lanes
  trafficDensity1 = digitalRead(irSensorPin1);
  trafficDensity2 = digitalRead(irSensorPin2);
  trafficDensity3 = digitalRead(irSensorPin3);
  trafficDensity4 = digitalRead(irSensorPin4);
  

  // Set the traffic signal timing based on the traffic density in both lanes
  if (trafficDensity1 == 0 && trafficDensity2 == 1 && trafficDensity3 == 1 && trafficDensity4 == 1) {
    
    // CLEAR LANE 1 
    digitalWrite(redLED1, LOW);
    digitalWrite(greenLED1, HIGH);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.print("CLEARING LANE 1");
    
    delay(5000); 
    lcd.clear();
  } 
  else if (trafficDensity1 == 1 && trafficDensity2 == 0 && trafficDensity3 == 1 && trafficDensity4 == 1) {

     // CLEAR LANE 2
     digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, LOW);
    digitalWrite(greenLED2, HIGH);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.print("CLEARING LANE 2");
    
    delay(5000); 
    lcd.clear();
  } 
  else if (trafficDensity1 == 1 && trafficDensity2 == 1 && trafficDensity3 == 0 && trafficDensity4 == 1) {
     
    // CLEAR LANE 3
    digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, LOW);
    digitalWrite(greenLED3, HIGH);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.print("CLEARING LANE 3");
    
    delay(5000);
    lcd.clear();
    
  } 
  else if(trafficDensity1 == 1 && trafficDensity2 == 1 && trafficDensity3 == 1 && trafficDensity4 == 0){

     // CLEAR LANE 4
     digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, LOW);
    digitalWrite(greenLED4, HIGH);
    lcd.print("CLEARING LANE 4");
    
    delay(5000); 
    lcd.clear();
    
    }
    else{
    // CLEAR ALL THE LANES
      
    // CLEAR LANE 1 
    digitalWrite(redLED1, LOW);
    digitalWrite(greenLED1, HIGH);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("CLEARING ALL");
    lcd.setCursor(0, 1); // Set the cursor to the second column of the first row
    lcd.print("LANE 1");
    delay(5000); 
    lcd.clear();

    // CLEAR LANE 2
     digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, LOW);
    digitalWrite(greenLED2, HIGH);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("CLEARING ALL");
    lcd.setCursor(0, 1); // Set the cursor to the second column of the first row
    lcd.print("LANE 2");
    delay(5000); 
    lcd.clear();

    // CLEAR LANE 3
    digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, LOW);
    digitalWrite(greenLED3, HIGH);
    digitalWrite(redLED4, HIGH);
    digitalWrite(greenLED4, LOW);
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("CLEARING ALL");
    lcd.setCursor(0, 1); // Set the cursor to the second column of the first row
    lcd.print("LANE 3");
    delay(5000); 
    lcd.clear();

    // CLEAR LANE 4
     digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED4, LOW);
    digitalWrite(greenLED4, HIGH);
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("CLEARING ALL");
    lcd.setCursor(0, 1); // Set the cursor to the second column of the first row
    lcd.print("LANE 4");
    delay(5000); 
    lcd.clear();


    }
   }