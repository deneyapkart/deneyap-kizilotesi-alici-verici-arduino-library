/*
 *   Kızılötesi verici örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Kızılötesi alıcı butona basıldığında seçilen veriyi göndermektedir. 
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Kızılötesi Alıcı&Verici için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-kzlotesi-alc-ve-verici-m53  <------
 *      ------>  https://github.com/deneyapkart/deneyap-kizilotesi-alici-verici-arduino-library  <------
 *
 */
#include <Deneyap_KizilotesiAliciVerici.h>            // Deneyap Kızılötesi Alıcı&Verici kutuphanesi eklenmesi

Transceiver IR;                                       // Transceiver için class tanımlaması

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatılması
    if (!IR.begin(0x22)) {                            // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }  
    pinMode(GPKEY,INPUT);                             // Deneyap Kartlarındaki buton giriş olarak ayarlanması
}

void loop() {
    if (digitalRead(GPKEY) == 0) {                    // Butona basılırsa
        Serial.println("butona basıldı");
        IR.transceiverWrite(0x2A);                    // Vericiden 0x2A verisi gönderilmesi ->0xFE2AD5<- 
    }
    delay(100);                                       // Veri gönderdikten sonra 100 ms beklemesi gerekmektedir
}
