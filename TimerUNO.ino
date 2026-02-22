#include <LiquidCrystal.h>
#include <Adafruit_Keypad.h>

// --- LCD Pin Mapping ---
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// --- Adafruit Keypad Configuration ---
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, A1, A2, A3}; 

// Initialize Adafruit Keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- Component Pins ---
const int buzzer = 13;

// --- Timer Variables ---
long timerSeconds = 0;
String inputString = "";
bool running = false;
unsigned long previousMillis = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  customKeypad.begin(); // Required for Adafruit library
  resetTimer();
}

void loop() {
  // Required: tick() tells the library to scan the hardware
  customKeypad.tick();

  // Check for new keypad events
  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    
    // Only trigger when the key is first pressed
    if(e.bit.EVENT == KEY_JUST_PRESSED) {
      char key = (char)e.bit.KEY;

      if (key >= '0' && key <= '9' && !running) {
        if (inputString.length() < 4) {
          inputString += key;
          timerSeconds = inputString.toInt();
          updateDisplay();
        }
      } else if (key == '#') { // START
        if (timerSeconds > 0) running = true;
      } else if (key == 'C' || key == '*') { // RESET
        resetTimer();
      }
    }
  }

  // Countdown Logic
  if (running) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1000) {
      previousMillis = currentMillis;
      timerSeconds--;
      updateDisplay();

      if (timerSeconds <= 0) {
        running = false;
        alarm();
      }
    }
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(running ? "Counting Down:" : "Enter Secs:");
  lcd.setCursor(0, 1);
  lcd.print(timerSeconds);
  lcd.print("s");
}

void resetTimer() {
  running = false;
  timerSeconds = 0;
  inputString = "";
  noTone(buzzer);
  updateDisplay();
}

void alarm() {
  lcd.clear();
  lcd.print("TIME'S UP!");
  for(int i = 0; i < 5; i++) {
    tone(buzzer, 3000);
    delay(300);
    noTone(buzzer);
    delay(200);
  }
}
