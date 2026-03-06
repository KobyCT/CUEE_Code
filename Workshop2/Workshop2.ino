// import libraries
#include <Wire.h>
#include "i2c.h"
#include "i2c_MMA8451.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD Screen
MMA8451 mma8451;                    // Initialize MMA8451

void setup()
{
    Serial.begin(9600);
    // Initialize MMA8451
    Serial.print("Probe MMA8451: ");
    if (mma8451.initialize())
        Serial.println("Sensor found!");
    else
    {
        Serial.println("Sensor missing");
        while (1)
        {
        };
    }

    // Setting LCD Screen
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("x:");
    lcd.setCursor(7, 0);
    lcd.print("y:");
    lcd.setCursor(0, 1);
    lcd.print("z:");
}

void loop()
{
    static float xyz_g[3];

    mma8451.getMeasurement(xyz_g); // getting x y z data by library
    // Printing x y z data to Serial Monitor and LCD Screen
    Serial.print(" X: ");
    Serial.print(xyz_g[0], 2);
    lcd.setCursor(2, 0);
    lcd.print(xyz_g[0], 2);
    Serial.print(" \tY: ");
    Serial.print(xyz_g[1], 2);
    lcd.setCursor(9, 0);
    lcd.print(xyz_g[1], 2);
    Serial.print(" \tZ: ");
    Serial.print(xyz_g[2], 2);
    lcd.setCursor(2, 1);
    lcd.print(xyz_g[2], 2);
    Serial.println("");
    delay(500);
}