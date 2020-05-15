//client program collects temperature data, converts it into degree celcius and sends it to server
#include <ESP8266WiFi.h>
#include "DHT.h"

//Initialize network parameters
const char* ssid = "h4r735";
const char* password = "NH301tre";
const char* host ="192.168.1.228";

//setup Client Object
WiFiClient client;

//setUp sensor options 
DHT dht(0,DHT11);
float humidity,temperature;
void setup()
{
//config input pin (optional)
    Serial.begin(9600);
    dht.begin();
    //connect to the server
    WiFi.begin(ssid,password);
    Serial.println("StartWorking");
    while(WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    Serial.print("IP address (AP): ");Serial.println(WiFi.localIP());

    
    //get a measurement from sensor and send them to server
}

void loop()
{
        if((WiFi.status() != WL_CONNECTED)){Serial.println("Connection to internet lost!");}
        if(client.connect(host,1234))
        {
          Serial.println("Connected to server!");
          while(client.connected())
          {
              humidity = dht.readHumidity();
              temperature = dht.readTemperature();
              Serial.print("Temperature: ");Serial.print(temperature);
              Serial.print("     Humidity: ");Serial.println(humidity); 
                            
                    String url = String(temperature)+"$"+String(humidity);
                    client.print(url);
                    url = "";
                  
                    //Read all the lines from server and print them to Serial 
                    /*Serial.println("Response: ");
                    delay(1000);
                    if(client.available())
                        {
                          String line = client.readStringUntil('\r');
                          Serial.println(line);
                        }*/
                    delay(1000);
          }
            if(!client.connected()){Serial.println("Connection to server lost!");}
        }
          else
            Serial.println("Couldn`t connect to server!");
}
