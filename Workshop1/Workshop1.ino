#include <Wire.h>

#define MMA8451 0x1C

int readRegister(byte reg)
{
  Wire.beginTransmission(MMA8451);
  Wire.write(reg);
  Wire.endTransmission(false);

  Wire.requestFrom(MMA8451, 1);
  return Wire.read();
}



void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MMA8451);
  Wire.write(0x2A);      // CTRL_REG1
  Wire.write(0x01);      // Active mode
  Wire.endTransmission();
  
  // put your setup code here, to run once:

}

int16_t x, y, z;

void loop() {

  int x_msb = readRegister(0x01);
  int x_lsb = readRegister(0x02);

  int y_msb = readRegister(0x03);
  int y_lsb = readRegister(0x04);

  int z_msb = readRegister(0x05);
  int z_lsb = readRegister(0x06);

  int16_t x = (x_msb << 8) | x_lsb;
  int16_t y = (y_msb << 8) | y_lsb;
  int16_t z = (z_msb << 8) | z_lsb;

  Serial.print("X: "); Serial.print(x);
  Serial.print(" Y: "); Serial.print(y);
  Serial.print(" Z: "); Serial.println(z);
  delay(200);
}
