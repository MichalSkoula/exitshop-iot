using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;

namespace exitshop_iot_uploader
{
    internal class Settings
    {
        public Dictionary<string, string> getSettingsFromUser()
        {
            var result = new Dictionary<string, string>();
            var resultDefault = new Dictionary<string, string>();

            // load default values?
            if (File.Exists("config.json"))
            {
                resultDefault = JsonConvert.DeserializeObject<Dictionary<string, string>>(File.ReadAllText("config.json"));
            }

            Console.WriteLine("\nZadejte PŘESNÝ název vaší WiFi sítě (pouze 2.4Ghz, ne 5 Ghz)");
            string ssid;
            if (resultDefault.ContainsKey("ssid"))
            {
                Console.Write("(" + resultDefault["ssid"] + "): ");
            }
            ssid = Console.ReadLine();
            if (ssid == "" && resultDefault.ContainsKey("ssid")) {
                ssid = resultDefault["ssid"];
            }
            result.Add("ssid", ssid);


            Console.WriteLine("\nZadejte heslo k vaší WiFi síti:");
            string password;
            if (resultDefault.ContainsKey("password"))
            {
                Console.Write("(" + resultDefault["password"] + "): ");
            }
            password = Console.ReadLine();
            if (password == "" && resultDefault.ContainsKey("password"))
            {
                password = resultDefault["password"];
            }
            result.Add("password", password);


            Console.WriteLine("\nZadejte tajný klíč, který získáte v ExitShop administraci");
            string secret;
            if (resultDefault.ContainsKey("secret"))
            {
                Console.Write("(" + resultDefault["secret"] + "): ");
            }
            secret = Console.ReadLine();
            if (secret == "" && resultDefault.ContainsKey("secret"))
            {
                secret = resultDefault["secret"];
            }
            result.Add("secret", secret);


            Console.WriteLine("\nZadejte číslo melodie, která má hrát při přijetí objednávky");
            Console.WriteLine("0: nic");
            Console.WriteLine("1: bzučení");
            Console.WriteLine("2: Super Mario");
            Console.WriteLine("3: Take On Me");
            Console.WriteLine("4: StarWars");
            Console.WriteLine("5: The Lion Sleeps Tonight");
            Console.WriteLine("6: DOOM");

            string melody;
            if (resultDefault.ContainsKey("melody"))
            {
                Console.Write("(" + resultDefault["melody"] + "): ");
            }
            melody = Console.ReadLine();
            if (melody == "" && resultDefault.ContainsKey("melody"))
            {
                melody = resultDefault["melody"];
            }
            result.Add("melody", melody);


            // save default values 
            File.WriteAllText("config.json", JsonConvert.SerializeObject(result, Formatting.Indented));

            return result;
        }
    }
}
