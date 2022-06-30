/*
 *   Kızılötesi alıcı örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Kızılötesi alıcıdan gelen veriyi seri terminale yazdırmaktadır. 
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Kızılötesi Alıcı&Verici için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-kizilotesi-alici-verici-arduino-library  <------
 *
 */
#include <Deneyap_KizilotesiAliciVerici.h>              // Deneyap_kizilotesiAliciVerici kutuphanesi eklenmesi

Transceiver IR;                                         // Transceiver için class tanımlaması

void setup() {
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if (!IR.begin(0x22)) {                              // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1) ;
    }
}

void loop() {
    IR.transceiverRead();                               // Alıcıdan alınan veri seri terminale yazdırıldı
    delay(100);                                         // Veri alındıktan sonra 100 ms beklemesi gerekmektedir
}
