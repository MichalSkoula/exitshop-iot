# ExitShop IOT

ExitShop Internet of Things - krabička, která vás upozorní na novou objednávku zvukovým signálem a blikáním diody. Kontrola probíhá každou minutu.

## Instalace

1. Nainstalujte USB ovladač - usb_driver.exe
2. Připojte ExitShop IOT k počítači přes micro USB kabel
3. Spusťte uploader.exe - možná vám v tom bude chtít zabránit antivir
    * Nejprve vyplňte číslo portu - bude to pravděpodobně to nejvyšší
    * Vyplňte postupně název vaší WiFi sítě, heslo a tajný klíč z ExitShopu - vše prosím přesně
4. Následně proběhne kompilace, trvá cca minutku a program se nahraje do krabičky - měl by se po chvíli rozsvítit displej a krabička je připravená

## Poznámka pro vývojáře

V rootu aplikace je nutné mít ve složce arduino-bin portable verzi Arduino IDE včetně doinstalovaných knihoven Adafruit_GFX, Adafruit_SSD1306, Arduino_JSON

## Credits

* [Michal Škoula](https://skoula.cz)
* [ExitShop](https://www.exitshop.cz)
