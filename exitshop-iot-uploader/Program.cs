using System;

namespace exitshop_iot_uploader
{
    internal class Program
    {
#if DEBUG
        public static bool debug = true;
#else
        public static bool debug = false;
#endif

        static void Main(string[] args)
        {
            Console.Beep(1500, 500);

            // print nice ASCI logo
            string title = @"
  ________   _______ _______ _____ _    _  ____  _____    _____ ____ _______ 
 |  ____\ \ / /_   _|__   __/ ____| |  | |/ __ \|  __ \  |_   _/ __ \__   __|
 | |__   \ V /  | |    | | | (___ | |__| | |  | | |__) |   | || |  | | | |   
 |  __|   > <   | |    | |  \___ \|  __  | |  | |  ___/    | || |  | | | |   
 | |____ / . \ _| |_   | |  ____) | |  | | |__| | |       _| || |__| | | |   
 |______/_/ \_\_____|  |_| |_____/|_|  |_|\____/|_|      |_____\____/  |_|                                                                           
";
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write(title);
            Console.WriteLine(" __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ ");

            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine();
            Console.WriteLine("Dobrý den, přátelé ExitShopáci. Tento program vás provede nastavením vaší ExitShop IOT krabičky.");
            Console.WriteLine("Program si bude nastavení pamatovat a příště vám nabídne výchozí hodnoty.");
            Console.WriteLine("");
            Console.WriteLine("Pokud jste tak ještě neučinili, nainstalujte si prosím USB ovladač z přiloženého souboru usb_driver.exe");
            Console.WriteLine("Poté připojte vaší IOT krabičku k počítači pomocí micro USB kabelu. Pokračujte stisknutím ENTER");
            Console.ReadLine();

            // COM ports
            COMPort comPorts = new COMPort();
            comPorts.printCOMPorts();
            int comPort = comPorts.selectCOMPort();

            // SETTINGS
            Settings settings = new Settings();
            var userSettings = settings.getSettingsFromUser();

            // UPLOAD
            Uploader uploader = new Uploader();
            uploader.upload(userSettings, comPort);

            Console.ReadLine();
        }
    }
}





                                                                             