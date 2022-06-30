# Deneyap Kızılötesi Alıcı&Verici Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Kızılötesi Alıcı&Verici için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M53**, **mpv1.0**
- `MCU` STM8S003F3
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x22, 0x56, 0x26, 0x27

| Adres |  | 
| :--- | :---     |
| 0x22 | varsayılan adres |
| 0x56 | ADR1 kısa devre yapıldığındaki adres |
| 0x26 | ADR2 kısa devre yapıldığındaki adres |
| 0x27 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
Deneyap Kızılötesi Alıcı&Verici 

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
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Kızılötesi Alıcı&Verici ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

| Kızılötesi Alıcı&Verici | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     | Güç    | 3.3V    |
| GND      | Toprak |GND      |
| SDA      | I2C Data  | SDA pini |
| SCL      | I2C Clock | SCL pini|
|SWIM | Debug | bağlantı yok |
|RES  | Debug | bağlantı yok |
|TX| Transmit pin | |
|RX|  Receive pin | |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-kizilotesi-alici-verici-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
