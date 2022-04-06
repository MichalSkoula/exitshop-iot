# ExitShop IOT

ExitShop Internet of Things - krabička, která vás upozorní na novou objednávku zvukovým signálem a blikáním diody. Kontrola probíhá každou minutu.

## Instalace

1. Nainstalujte USB ovladač - usb_driver.exe
2. Připojte ExitShop IOT k počítači přes micro USB kabel
3. Spusťte uploader.exe - možná vám v tom bude chtít zabránit antivir
    * Nejprve vyplňte číslo portu - bude to pravděpodobně to nejvyšší
    * Vyplňte postupně název vaší WiFi sítě, heslo a tajný klíč z ExitShopu - vše prosím přesně
4. Následně proběhne kompilace, trvá cca minutku a program se nahraje do krabičky - měl by se po chvíli rozsvítit displej a krabička je připravená


## Prototypy


Prototyp #3 "Milan" se zesilovačem, zde použito NodeMCU v2, které je menší

![obrazek](https://user-images.githubusercontent.com/5922575/161611237-dce3ebb6-aeca-4ee6-85d4-abc36649dac7.png)

Prototyp #2 "Radek" v krabičce včetně i bez zesilovače

![277007822_10217682465007998_7174850170749182197_n](https://user-images.githubusercontent.com/5922575/161612031-4c05ad36-d206-4aa2-811e-ee4666cbebf4.jpg)

![Clipboard01](https://user-images.githubusercontent.com/5922575/162078604-9afa6520-541e-4949-8a73-3a0f8567300d.jpg)

Prototyp #1 "Michal" na breadboardu

![Clipboard01](https://user-images.githubusercontent.com/5922575/161611923-df3fe6a3-d874-4a26-9f33-47d449abeacc.jpg)


## Poznámka pro vývojáře

V rootu aplikace je nutné mít ve složce arduino-bin portable verzi Arduino IDE včetně doinstalovaných knihoven Adafruit_GFX, Adafruit_SSD1306, Arduino_JSON

Ve složce hardware naleznete krabičku pro 3D tisk a schéma zapojení.

![zapojeni](https://user-images.githubusercontent.com/5922575/161611123-c4956708-c17e-46df-a374-8cb1b98d4d99.png)

## Credits

* [Michal Škoula](https://skoula.cz)
* [ExitShop](https://www.exitshop.cz)
