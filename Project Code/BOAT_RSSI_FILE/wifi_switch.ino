#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>
SoftwareSerial ss(D3, D5);
int  sno = 1 , i = 1, a;
String arr[10];
const char* ssid = "rssisand";
const char* password = "rssisand";
String voice;
/*int switch1 = 16; // GPIO13---D7 of NodeMCU
  int switch2 = D6; //  WIFI connected switch
  int switch3 = D5;//*/
int RSSI1 = D0;
int RSSI2 = D1;
int RSSI3 = D2;

WiFiServer server(80);
int32_t getRSSI(const char* target_ssid) {
  byte available_networks = WiFi.scanNetworks();

  for (int network = 0; network < available_networks; network++) {
    if (WiFi.SSID(network).compareTo(target_ssid) == 0) {     //stringOne.compareTo(stringTwo) < 0
      return WiFi.RSSI(network);
    }
  }
  return 0;
}

void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  delay(10);
  /*pinMode(switch1, OUTPUT);
    pinMode(switch2, OUTPUT);
    pinMode(switch3, OUTPUT);*/
  pinMode(RSSI1, OUTPUT);
  pinMode(RSSI2, OUTPUT);
  pinMode(RSSI3, OUTPUT);
  pinMode(D4, OUTPUT);
  /* digitalWrite(switch1, HIGH);
    digitalWrite(switch2, LOW);
    digitalWrite(switch3, LOW);*/
  digitalWrite(RSSI1, LOW);
  digitalWrite(RSSI2, LOW);
  digitalWrite(RSSI3, LOW);

  // Connect to WiFi network
  //Serial.println();
  //Serial.println();
  //Serial.print("Connecting to ");
  // Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
   // Serial.println("rssisand");
    digitalWrite(D4, HIGH);
  }

 // Serial.println("WiFi connected");
  digitalWrite(D4, LOW );

  // Start the server
  server.begin();
  //Serial.println("Server started");

  // Print the IP address
//  Serial.print("Use this URL to connect: ");
//  Serial.print("http://");
//  Serial.print(WiFi.localIP());
//  Serial.println("/");
  ss.print(WiFi.localIP());
  ss.print('#');
  Serial.print(WiFi.localIP());
  Serial.print('#');
  delay(1000);

}

void loop()
{

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  //  Serial.println("rssi");
    digitalWrite(D4, HIGH);
    if (WiFi.status() == WL_CONNECTED)
    { digitalWrite(D4, LOW );
     // Serial.println("");
     // Serial.println("WiFi connected");

      server.begin();
    //  Serial.println("Server started");

      //Print the IP address
//      Serial.print("Use this URL to connect: ");
//      Serial.print("http://");
//      Serial.print(WiFi.localIP());
//      Serial.println("/");
     // ss.print(WiFi.localIP());
    }
  }


  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  //Wait until the client sends some data
  //Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
  int32_t rssi = getRSSI(ssid);
  rssi = rssi * (-1);

  // For debugging purpose only
 // Serial.print("Signal strength: ");
  //Serial.print(rssi);
 // Serial.println("dBm");


  // Read the first line of the request
  String request = client.readStringUntil('\r');
 // Serial.println(request);
  client.flush();



  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta http-equiv=refresh content=2>");
  client.println("</head>");
  client.println("<body style=background-color:#85929E    ;>");
  client.println("<center>");
  client.println("<br><br>");
  client.println("<h1 style=color:red;>RECEIVED SIGNAL STRENGTH IDENTICATOR</h1>");
  client.print(" RSSI");

  client.println(" ");


  client.println("<center>");
  client.println("<hr color=yellow width= 100%>");
  client.println("<br>");
  client.println("<h1 style=color:blue;>PROJECT TITLE</h1>");
  client.println("<br>"); client.println("<br>");
  client.println("BOAT LOCALIZATION");
  client.println("<br>"); client.println("<br>"); client.println("<br>"); client.println("<br>");
  client.println("<hr color=yellow width= 100%>");
  ////////////////////////////////////////////////////////////////////////////

  client.println("<h1 style=color:#4A213A    ;>BOAT  RANGE</h1>");
  client.println("<br>"); client.println("<br>");
  if ((rssi <= 50 && rssi != 0)) // if rssi is greater then -70 dbm or it's 0 dbm, then the light will turn ON
  {
    Serial.print('A');
    digitalWrite(RSSI1, HIGH);
    digitalWrite(RSSI2, LOW);
    digitalWrite(RSSI3, LOW);
    client.println("<table style=width:50%>");
    client.println("<tr>");
    client.println("<td>");
    client.println("SIGNAL STRENGTH :"); //client.println("</td>");
    client.println(rssi);
    client.println("<tr>");
    client.println("<td colspan=2>");
    client.println("BOAT IN RANGE"); client.println("</tr>");
    client.println("<style>table,td{background-color:#0E6136  ;padding: 50px;} </style>");
    client.println("</table>");
    client.println("<br>");
    client.println("<hr color=yellow width= 100%>");
  }
  if (rssi <= 70 && rssi >= 51)
  {
    Serial.print('B');
    digitalWrite(RSSI2, HIGH);
    digitalWrite(RSSI1, LOW);
    digitalWrite(RSSI3, LOW);
    client.println("<table style=width:50%>");  client.println("<tr>");
    client.println("<td>"); client.println("SIGNAL STRENGTH :");
    client.println(rssi); client.println("<tr>");
    client.println("<td colspan=1>");
    client.println("BOAT WARINING "); client.println("</tr>");
    client.println("<style>table,td{background-color:#FE9124;padding: 50px;} </style>");
    client.println("</table>");
    client.println("<br>");
    client.println("<hr color=yellow width= 100%>");
  }
  if (rssi >= 71 )
  {
    Serial.print('C');
    digitalWrite(RSSI3, HIGH);
    digitalWrite(RSSI1, LOW);
    digitalWrite(RSSI2, LOW);
    client.println("<table style=width:50%>"); client.println("<tr>");
    client.println("<td>"); client.println("SIGNAL STRENGTH :");
    client.println(rssi); client.println("<tr>");
    client.println("<td colspan=2>");
    client.println("BOAT OUT OF RANGE EMERGENCY"); client.println("</td>"); client.println("</tr>");
    client.println("<style>table,td{background-color:#CD0808;padding: 50px;} </style>");
    client.println("</table>");
    client.println("<br>");
    client.println("<hr color=yellow width= 100%>");
  }
  client.println("</body>");
  client.println("</html>");
  delay(1);
  // Serial.println("Client disonnected");
  //  Serial.println("");

}
