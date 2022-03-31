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

            return result;
        }
    }
}
