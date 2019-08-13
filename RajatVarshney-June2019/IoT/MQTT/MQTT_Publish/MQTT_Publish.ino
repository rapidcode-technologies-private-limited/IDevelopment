#include <WiFi.h>
#include <PubSubClient.h>

IPAddress server(192, 168, 43, 222);

const char* mqtt_server = "192.168.43.222";

const char* ssid = "vivo 1723";
const char* password = "rajatvar";

void callback(char* topic, byte* payload, unsigned int length);

WiFiClient espClient;
PubSubClient client(server, 1883, callback, espClient);

long lastMsg = 0;

// Callback function
void callback(char* topic, byte* payload, unsigned int length) {

  // Allocate the correct amount of memory for the payload copy
  byte* p = (byte*)malloc(length);
  
  // Copy the payload to the new buffer
  memcpy(p,payload,length);
  
  client.publish("outTopic", p, length);
  
  // Free the memory
 free(p);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("mqtt_server")) {
      Serial.println("connected");
      // Subscribe
      //client.subscribe("esp32/output");
      Publish();
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void Publish(){
 if (client.connect("esp32/data")) {
    client.publish("test_channel","hello world");
    //client.subscribe("inTopic");
  } 
}

void setup()
{
  Serial.begin(115200);
//  Ethernet.begin(mac, ip);
    Serial.begin(115200);
  
    setup_wifi();
   Publish();
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
  }
}
