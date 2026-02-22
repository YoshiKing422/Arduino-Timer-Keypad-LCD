# ⏲️ Arduino Keypad Countdown Timer

A simple, functional countdown timer using an Arduino Uno. Users can input a time in seconds via a membrane keypad, start the countdown, and receive an audible alert when the time reaches zero.

## 🚀 Features
- **Manual Input:** Set any time (0-9999 seconds) using the number pad.
- **Real-time Display:** 16x2 LCD shows "Set Time" and "Time Left" states.
- **Audible Alarm:** 2-pin buzzer sounds a 5-beep sequence upon completion.
- **Reset Function:** Quickly clear or restart the timer using the '*' or 'C' keys.

## 🛠️ Components
- **Arduino Uno**
- **16x2 LCD Display** (16-pin)
- **4x4 Matrix Keypad** (8-pin)
- **2-pin Buzzer** (Passive/Active)
- **10k Potentiometer** (For LCD contrast)
- **Breadboard & Jumper Wires**

## 🔌 Wiring Diagram

| Component | Arduino Pin |
| **Buzzer (+)** | Pin 13 |
| **Keypad Row 1** | Pin A0 (14) |
| **Keypad Rows 2-4** | Pins 3, 4, 5 |
| **Keypad Columns 1-4**| Pins 6, A1, A4, A5 |
| **LCD RS / Enable** | Pins 7, 8 |
| **LCD D4 - D7** | Pins 9, 10, 11, 12 |
| **LCD RW** | GND (Crucial!) |
| **Potentiometer** | Middle Pin to LCD Pin 3 (V0) |

## 💻 Libraries Used
This project requires the following libraries available in the Arduino IDE:
1. `Adafruit_Keypad`
2. `LiquidCrystal` (Standard)

## 📖 How to Use
1. **Power on** the Arduino.
2. **Enter Seconds:** Use the keypad to type your desired time (e.g., `60` for 1 minute).
3. **Start:** Press `#` to begin the countdown.
4. **Reset:** Press `*` or `C` at any time to clear the input or stop the alarm.
5. **Adjust Contrast:** If the screen is blank, turn the 10k potentiometer knob.

## 📝 License
This project is open-source and free to use for hobbyist and educational purposes.

