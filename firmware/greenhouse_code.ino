#include <Wire.h>
#include <Adafruit_GFX.h> //Include Adafruit graphics library for OLED
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 //OLED display height in pixels
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_BMP085 bmp;
Servo ventServo; //create a servo object to control the opening of it 

//pin assignments
const int SWITCH_S1  = 4;//switch S1 mapped to digital Pin 4
const int SWITCH_S2  = 2;
const int POT_PIN = A0;
const int SERVO_PIN  = 11;
const int BUZZER_PIN = 12;
const int RELAY_PIN  = 13;
const int LED_PIN= 8;
//Servo positions
const int SERVO_CLOSED_ANGLE = 150;// 5 o'clock position (Closed position)
const int SERVO_OPEN_ANGLE = 90;

//Control parameters
const float HYSTERESIS = 0.5;
const long BLINK_INTERVAL = 500;

int threshold = 0;
float currentTemp = 0.0;// Variable to store temperature data
float pressure = 0.0;

bool ventOpen = false;//track state of the ventilation window
bool ledState = false;
unsigned long lastBlinkMillis = 0;

void setup() {
  Serial.begin(9600);//open serial communications at 9600 baud


  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_S1, INPUT_PULLUP);
  pinMode(SWITCH_S2, INPUT_PULLUP); //configure Switch 2 with internal pull up resistor
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);//configure Relay pin as a digital output

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(RELAY_PIN, LOW);// relay OFF until we deliberately pulse it

  //Initialise OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
  }

  display.clearDisplay();
  display.display();

  //Initialise BMP180
  if (!bmp.begin()) {
    Serial.println("BMP180 failed");
  }

  //Initialise servo in closed position
  ventServo.attach(SERVO_PIN);//attach the servo object to its control pin
  digitalWrite(RELAY_PIN,HIGH);//Engage relay to give servo temporary setup power
  delay(100);
  ventServo.write(SERVO_CLOSED_ANGLE);
  delay(600);
  digitalWrite(RELAY_PIN,LOW);
}


void openVent() {
  if (!ventOpen) {
    digitalWrite(RELAY_PIN,HIGH);
    delay(100);
    ventServo.write(SERVO_OPEN_ANGLE);
    delay(600);
    digitalWrite(RELAY_PIN,LOW);
    ventOpen = true;
  }
}


void closeVent() {
  if (ventOpen) {
    digitalWrite(RELAY_PIN,HIGH);
    delay(100);// lets the voltage increase
    ventServo.write(SERVO_CLOSED_ANGLE);
    delay(600);
    digitalWrite(RELAY_PIN,LOW);//turns off power to relay to be more efficent
    ventOpen = false;
  }
}


void loop() {

  currentTemp = bmp.readTemperature();//fetch temperature data from BMP180
  pressure = bmp.readPressure()/100.0F;//fetches  pressure and convert to hPa
  //Read user adjustable temperature threshold
  int potValue = analogRead(POT_PIN);
  threshold = map(potValue, 0, 1023, 20, 35);

  bool manualOpen  = digitalRead(SWITCH_S1) ==LOW;
  bool manualClose = digitalRead(SWITCH_S2) == LOW;
  bool overTemperature = currentTemp > threshold;


  if (manualOpen) {
    openVent();
  }
  else if (manualClose) {
    closeVent();
  }
  else if (!ventOpen && currentTemp>threshold + HYSTERESIS) {//checks if the ventilation window is currently closed
    openVent();
  }
  else if (ventOpen &&currentTemp <threshold - HYSTERESIS) {
    closeVent();
  }

  if (overTemperature) {
    digitalWrite(BUZZER_PIN,HIGH);
    unsigned long currentMillis = millis();

    if (currentMillis -lastBlinkMillis>= BLINK_INTERVAL) {
      lastBlinkMillis =currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN,ledState);
    }
  }
  else {
    digitalWrite(BUZZER_PIN,LOW);
    ledState = false;
    digitalWrite(LED_PIN,LOW);
  }


  Serial.print("Temp:");//displays temp
  Serial.println(currentTemp);
  Serial.print("Pressure:");
  Serial.println(pressure);

  Serial.print("Threshold: ");
  Serial.println(threshold);


  display.clearDisplay();//clears oled
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Temp:");
  display.print(currentTemp);
  display.println(" C");
  display.print("Pressure:");
  display.print(pressure);
  display.println(" hPa");
  display.print("Threshold:");
  display.print(threshold);
  display.println(" C");
  display.print("Window: ");
  display.println(ventOpen? "OPEN":"CLOSED");
  display.print("Status:");
  display.println(overTemperature? "ALARM":"NORMAL");
  display.display();
  delay(200);
}
                                   
}
