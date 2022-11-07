/*
 *   Kızılötesi alıcı örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Kızılötesi alıcıdan gelen veriyi seri port ekranına yazdırmaktadır. 
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Kızılötesi Alıcı&Verici için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-kzlotesi-alc-ve-verici-m53  <------
 *      ------>  https://github.com/deneyapkart/deneyap-kizilotesi-alici-verici-arduino-library  <------
*/
#include <Deneyap_KizilotesiAliciVerici.h>              // Deneyap Kızılötesi Alıcı&Verici kutuphanesi eklenmesi

Transceiver IR;                                         // Transceiver için class tanımlaması

void setup() {
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if (!IR.begin(0x22)) {                              // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }
}

void loop() {
    IR.transceiverRead();                               // Alıcıdan alınan veri seri port ekranına yazdırılması
    delay(100);                                         // Veri alındıktan sonra 100 ms beklemesi gerekmektedir
}
