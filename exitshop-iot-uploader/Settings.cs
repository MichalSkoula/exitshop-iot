using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exitshop_iot_uploader
{
    internal class Settings
    {
        public Dictionary<string, string> getSettingsFromUser()
        {
            var result = new Dictionary<string, string>();

            Console.WriteLine("\nZadejte PŘESNÝ název vaší WiFi sítě (pouze 2.4Ghz, ne 5 Ghz):");
            result.Add("ssid", Console.ReadLine());

            Console.WriteLine("\nZadejte heslo k vaší WiFi síti:");
            result.Add("password", Console.ReadLine());

            Console.WriteLine("\nZadejte tajný klíč, který získáte v ExitShop administraci:");
            result.Add("secret", Console.ReadLine());

            Console.WriteLine("\nZadejte číslo melodie, která má hrát při přijetí objednávky:");
            Console.WriteLine("0: nic");
            Console.WriteLine("1: bzučení");
            Console.WriteLine("2: Super Mario");
            Console.WriteLine("3: Take On Me");
            Console.WriteLine("4: StarWars");
            Console.WriteLine("5: The Lion Sleeps Tonight");
            Console.WriteLine("6: DOOM");
            Console.WriteLine("\nNapište číslo melodie:");
            result.Add("melody", Console.ReadLine());

            return result;
        }
    }
}
