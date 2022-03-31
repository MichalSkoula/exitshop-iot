using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exitshop_iot_uploader
{
    class Uploader
    {
        public void upload(Dictionary<string,string> userSettings, int comPort)
        {
            string input = Program.debug ? "..\\..\\..\\..\\exitshop-iot-code\\exitshop-iot-code.ino" : "exitshop-iot-code\\exitshop-iot-code.ino";
            string output = Program.debug ? "..\\..\\..\\..\\exitshop-iot-code-modified\\exitshop-iot-code-modified.ino" : "exitshop-iot-code-modified\\exitshop-iot-code-modified.ino";
            string arduino = Program.debug ? "..\\..\\..\\..\\arduino-bin\\arduino_debug.exe" : "arduino-bin\\arduino_debug.exe";

            // read default program
            string program = File.ReadAllText(input);

            // make changes
            program = program.Replace("SSID_PLACEHOLDER", userSettings["ssid"]);
            program = program.Replace("PASSWORD_PLACEHOLDER", userSettings["password"]);
            program = program.Replace("SECRET_PLACEHOLDER", userSettings["secret"]);

            // save modified file
            File.WriteAllText(output, program);

            Console.WriteLine("\nOK! Nahrávám. Prosím počkejte, bude to chvíli trvat, asi 1-2 minuty.\nJakmile program napíše \"Hard resetting via RTS pin...\", je hotovo.\n");

            // upload game - start arduino ide
            var p = new System.Diagnostics.Process();
            p.StartInfo.FileName = arduino;
            p.StartInfo.Arguments = "--board esp8266:esp8266:generic --port COM" + comPort + " --upload " + output;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.CreateNoWindow = false;
            p.Start();
        }
    }
}
