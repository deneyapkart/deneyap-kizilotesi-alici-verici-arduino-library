# Deneyap Kızılötesi Alıcı&Verici Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Kızılötesi Alıcı&Verici için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M53**, **mpv1.0**
- `MCU` STM8S003F3, TSOP2238, IR12-21C/TR8
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 25,4 mm
- `I2C Adres` 0x22, 0x56, 0x26, 0x27

| Adres |  | 
| :--- | :---     |
| 0x22 | varsayılan adres |
| 0x56 | ADR1 kısa devre yapıldığındaki adres |
| 0x26 | ADR2 kısa devre yapıldığındaki adres |
| 0x27 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
[Deneyap Kızılötesi Alıcı&Verici](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-kzlotesi-alc-ve-verici-m53)

[Deneyap Kızılötesi Alıcı&Verici Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/RCUEAfKv1djiBgGqmZ3aGDLyIjuitj8l.pdf)

[Deneyap Kızılötesi Alıcı&Verici Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/nkjtUEbPHdyuWbOrYQRJaQrbdgkd5l8Q.pdf)

[Vishay TSOP2238-datasheet](https://www.vishay.com/docs/82459/tsop48.pdf)

[Everlight IR12-21C/TR8-datasheet](https://eu.mouser.com/datasheet/2/143/EVER_S_A0007423485_1-2548612.pdf)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Kızılötesi Alıcı&Verici
Bu Arduino kütüphanesi Deneyap Kızılötesi Alıcı&Verici'nin I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.1 - hata giderildi (Arduino 2.0'da kütüphane örneklerinin görünmemesi)

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Kızılötesi Alıcı&Verici ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

| Kızılötesi Alıcı&Verici | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     |3.3V Besleme Gerilimi| 3.3V    |
| GND      | Toprak |GND      |
| SDA      |Çift Yönlü Veri Hattı| SDA pini |
| SCL      |Veri Hattı Zaman Senkronizasyon İşaret| SCL pini|
|SWIM | Debug | bağlantı yok |
|RES  | Debug | bağlantı yok |
|TX|UART Arayüzü Veri Çıkışı| |
|RX|UART Arayüzü Veri Girişi| |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-kizilotesi-alici-verici-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
