#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp;

int tiempo=0;
void setup() {
  Serial.begin(9600);
  
  while ( !Serial ) delay(100);  
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status) {
    Serial.println(F("Error!"));
    while (1) delay(10);
  }


  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,   
                  Adafruit_BMP280::SAMPLING_X2,   
                  Adafruit_BMP280::SAMPLING_X16,  
                  Adafruit_BMP280::FILTER_X16,    
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
    Serial.print(bmp.readTemperature());
    Serial.print(",");
    Serial.print(bmp.readPressure());
    Serial.print(",");
    Serial.print(bmp.readAltitude(1013.25)); 
    Serial.print(",");
    Serial.println(tiempo); 
    tiempo++;
    delay(1000);
}


