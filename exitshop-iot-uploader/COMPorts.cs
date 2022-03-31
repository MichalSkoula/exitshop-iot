using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.IO.Ports;

namespace exitshop_iot_uploader
{
    class COMPort
    {
        private int comPort;
        private List<int> availablePortNumbers;

        public void printCOMPorts()
        {
            Console.WriteLine("Nejprve zadejte číslo COM portu, ke kterému je krabička připojena. Pravděpodobně to bude to nejvyšší.");

            availablePortNumbers = new List<int>();
            foreach (string s in SerialPort.GetPortNames())
            {
                Console.WriteLine(s.Substring(3) + ": " + s);
                availablePortNumbers.Add(int.Parse(s.Substring(3)));
            }
        }

        public int selectCOMPort()
        {
            do
            {
                Console.WriteLine("\nNapište číslo COM portu a zmáčkněte enter.");
                string comPortRead = Console.ReadLine();
                if (!Regex.IsMatch(comPortRead, @"^\d+$"))
                {
                    comPort = -1;
                }
                else
                {
                    comPort = int.Parse(comPortRead);
                }
            } while (availablePortNumbers.IndexOf(comPort) == -1);

            return comPort;
        }

        public int getCOMPort()
        {
            return comPort;
        }
    }
}
