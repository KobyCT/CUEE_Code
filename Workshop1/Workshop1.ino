#include <Wire.h>

#define MMA8451 0x1C // กำหนด address ของเซ็นเซอร์ (default = 0x1C)

int readRegister(byte reg)
{
  Wire.beginTransmission(MMA8451); // ระบุ address ของเซ็นเซอร์
  Wire.write(reg);                 // ระบุ register ที่ต้องการอ่าน(internal address)
  Wire.endTransmission(false);

  Wire.requestFrom(MMA8451, 1); // ขอข้อมูลจากเซ็นเซอร์ จำนวน 1 byte
  return Wire.read();
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MMA8451); // ระบุ address ของเซ็นเซอร์
  Wire.write(0x2A);                // ระบุ register ที่ต้องการเขียนค่า (CTRL_REG1)
  Wire.write(0x01);                // เขียนค่า 0x01 เพื่อเปิดเซ็นเวอร์
  Wire.endTransmission();
}

int16_t x, y, z;

void loop()
{

  int x_msb = readRegister(0x01); // อ่านค่า byte ทางซ้ายของ X
  int x_lsb = readRegister(0x02); // อ่านค่า byte ทางขวาของ X

  int y_msb = readRegister(0x03); // อ่านค่า byte ทางซ้ายของ Y
  int y_lsb = readRegister(0x04); // อ่านค่า byte ทางขวาของ Y

  int z_msb = readRegister(0x05); // อ่านค่า byte ทางซ้ายของ Z
  int z_lsb = readRegister(0x06); // อ่านค่า byte ทางขวาของ Z

  // รวมค่า byte ทางซ้ายและขวา
  int16_t x = (x_msb << 8) | x_lsb;
  int16_t y = (y_msb << 8) | y_lsb;
  int16_t z = (z_msb << 8) | z_lsb;

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.println(z);
  delay(200);
}
