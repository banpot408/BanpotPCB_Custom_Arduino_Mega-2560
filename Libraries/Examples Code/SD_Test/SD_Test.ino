#include <SPI.h>
#include <SD.h>

File myFile; // สร้างออฟเจก File สำหรับจัดการข้อมูล
const int chipSelect = 49;

void setup()
{
Serial.begin(9600);
while (!Serial) {
; // รอจนกระทั่งเชื่อมต่อกับ Serial port แล้ว สำหรับ Arduino Leonardo เท่านั้น
}


Serial.print("Initializing SD card...");
pinMode(chipSelect, OUTPUT);

if (!SD.begin(chipSelect)) {
Serial.println("initialization failed!");
return;
}
Serial.println("initialization done.");

myFile = SD.open("bes.txt", FILE_WRITE); // เปิดไฟล์ที่ชื่อ test.txt เพื่อเขียนข้อมูล โหมด FILE_WRITE

// ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
if (myFile) {
Serial.print("Writing to bes.txt...");
myFile.println("Designed by BanpotPCBDesign Tel: 062 482 0181, Line: banpot_ya"); // สั่งให้เขียนข้อมูล
myFile.close(); // ปิดไฟล์
Serial.println("done.");
} else {
// ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
Serial.println("error opening bes.txt");
}

// เปิดไฟล์เพื่ออ่าน
myFile = SD.open("bes.txt"); // สั่งให้เปิดไฟล์ชื่อ test.txt เพื่ออ่านข้อมูล
if (myFile) {
Serial.println("bes.txt:");
// อ่านข้อมูลทั้งหมดออกมา
while (myFile.available()) {
Serial.write(myFile.read());
}
myFile.close(); // เมื่ออ่านเสร็จ ปิดไฟล์
} else {
// ถ้าอ่านไม่สำเร็จ ให้แสดง error 
Serial.println("error opening bes.txt");
}
}

void loop()
{
}
