
#include <SPI.h>
#include <Ethernet.h>

EthernetClient client;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

#define SENSES_HOST "www.sensesiot.com"
#define SENSES_PORT 4000
#define retry_wait 1000
#define LAGTIME 100

char server[] = "api.anto.io";    // name address for Google (using DNS)

IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);

unsigned int count_temp = 0;
unsigned int count_humi = 100;

// Variables to measure the speed
unsigned long beginMicros, endMicros;
unsigned long byteCount = 0;
bool printWebData = true;  // set to false for better speed measurement

String Senses_Sent_Data(int slotnum, float data) {
  String _response = "";
  
  if (client.connect(SENSES_HOST, SENSES_PORT)) {
    String _path = "";
    _path = "GET /send/";
    _path += String(374);
    _path += "/";
    _path += String("trpgy7c4d10c");
    _path += "/";
    _path += String(slotnum);
    _path += "/";
    _path += String(data);

    _path += " HTTP/1.1\r\n";
    _path += "Host: ";
    _path += SENSES_HOST;
    _path += ":";
    _path += SENSES_PORT;
    _path += "\r\n";
    _path += "Connection: keep-alive\r\n\r\n";

    client.print(_path);
    delay(LAGTIME);
    
    while (client.available()) {
      String _response = client.readStringUntil('\r');
    }
    return _response;
  }
}

void setup() {
  
  pinMode(53, OUTPUT);
  Ethernet.init(53);   // MKR ETH shield

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.print("connecting to ");
  Serial.print(server);
  Serial.println("...");

//  Senses_Sent_Data(1, count_temp);
//  Senses_Sent_Data(2, count_humi);
}
  
void loop() {

  Senses_Sent_Data(1, count_temp);
  Senses_Sent_Data(2, count_humi);

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    endMicros = micros();
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    Serial.print("Received ");
    Serial.print(byteCount);
    Serial.print(" bytes in ");
    float seconds = (float)(endMicros - beginMicros) / 1000000.0;
    Serial.print(seconds, 4);
    float rate = (float)byteCount / seconds / 1000.0;
    Serial.print(", rate = ");
    Serial.print(rate);
    Serial.print(" kbytes/second");
    Serial.println();
  }

  count_temp++;
  count_humi--;
  if(count_temp>=101)count_temp=0;
  if(count_humi<=0)count_humi=100;
  delay(1000);
}
