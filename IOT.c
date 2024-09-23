#include <WiFi.h>
#include <HTTPClient.h>
#include <Base64.h>
#include <TinyGPS++.h>
#include <WebServer.h>

// WiFi Credentials
static const char *ssid = "#";
static const char *password = "#";

// Twilio Credentials
static const char *account_sid = "#";
static const char *auth_token = "#";
static const char *from_number = "#";
static const char *to_number = "+918248731433";

// Define the RX and TX pins for Serial 2 (for GPS)
#define RXD2 16
#define TXD2 17
#define GPS_BAUD 9600
#define BUZZ 19
// Define the pins for the buttons, LED, water sensor, and ultrasonic sensors
#define BUTTON_PIN_GPS 4    // Button for GPS location sharing
#define BUTTON_PIN_ONOFF 5  // Button for ON/OFF
#define LED_PIN 18          // LED pin to indicate ON/OFF status
#define WATER_SENSOR_PIN 34 // Water sensor pin
#define WATER_SENSOR_LED 32 // LED pin to indicate water detection
#define ULTRA_LED 33        // LED to indicate distance < 20 cm for either ultrasonic sensor

// Ultrasonic Sensor 1
#define TRIG_PIN1 27  // Trigger pin for Ultrasonic sensor 1
#define ECHO_PIN1 26  // Echo pin for Ultrasonic sensor 1

// Ultrasonic Sensor 2
#define TRIG_PIN2 22  // Trigger pin for Ultrasonic sensor 2
#define ECHO_PIN2 23 // Echo pin for Ultrasonic sensor 2

// Web Server
WebServer server(80);  // Web server on port 80

// The TinyGPS++ object
TinyGPSPlus gps;

// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial gpsSerial(2);

// Variable to track the system state (ON/OFF)
bool systemOn = false;

// Variable to store the previous button state for debouncing
bool lastButtonState = HIGH;

void setup() {
  // Serial Monitor
  Serial.begin(115200);

  // Start Serial 2 with the defined RX and TX pins and a baud rate of 9600
  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial 2 started at 9600 baud rate");

  // Initialize WiFi (system will connect when powered on)
  Serial.print("Connecting to WiFi network '");
  Serial.print(ssid);
  Serial.println("'...");
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(500);
  }
  Serial.println("Connected to WiFi");

  // Print the device IP
  Serial.print("ESP32 A IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize the buttons, LEDs, water sensor, and ultrasonic sensors
  pinMode(BUTTON_PIN_GPS, INPUT_PULLUP);
  pinMode(BUTTON_PIN_ONOFF, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(WATER_SENSOR_LED, OUTPUT);
  pinMode(ULTRA_LED, OUTPUT);
  
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);

  // Turn OFF the system indicator LED initially
  digitalWrite(LED_PIN, LOW);
  // Turn OFF the water detection LED initially
  digitalWrite(WATER_SENSOR_LED, LOW);
  // Turn OFF the ultrasonic sensor LED initially
  digitalWrite(ULTRA_LED, LOW);

  // Setup route for receiving object detection data
  server.on("/send-object", HTTP_POST, handleObjectDetection);
  server.begin();  // Start the server
  Serial.println("Web Server started at port 80");
}

void handleObjectDetection() {
  if (server.hasArg("plain")) {
    String objectName = server.arg("plain");  // Read the data sent in POST
    Serial.println("Received object from ESP32 B: " + objectName); 
    if(objectName =="person"){
      Serial.println("buzzer");
      digitalWrite(BUZZ, HIGH);
      delay(5000);
      digitalWrite(BUZZ, LOW);
    }
     // Print the object name
    server.send(200, "text/plain", "Object received from ESP32 B");  // Send a response back
  } else {
    server.send(400, "text/plain", "No object name sent");  // Bad request response
  }
}

void sendSMS(String message) {
  HTTPClient http;
  String url = "https://api.twilio.com/2010-04-01/Accounts/" + String(account_sid) + "/Messages.json";
  http.begin(url);

  // Base64 encode the account_sid and auth_token for Basic Auth
  String auth = String(account_sid) + ":" + String(auth_token);
  String auth_base64 = base64::encode(auth);
  http.addHeader("Authorization", "Basic " + auth_base64);

  // Set the request content type
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Prepare the POST data
  String postData = "To=" + String(to_number) + "&From=" + String(from_number) + "&Body=" + message;

  // Send the POST request
  int httpResponseCode = http.POST(postData);

  // Check the response code
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response:");
    Serial.println(response);
  } else {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  }

  // End the HTTP connection
  http.end();
}

void toggleSystem() {
  // Change the state of the system
  systemOn = !systemOn;

  if (systemOn) {
    Serial.println("System is ON.");
    digitalWrite(LED_PIN, HIGH); // Turn ON the system indicator LED
  } else {
    Serial.println("System is OFF.");
    digitalWrite(LED_PIN, LOW);  // Turn OFF the system indicator LED
    digitalWrite(WATER_SENSOR_LED, LOW); // Turn OFF the water detection LED
    digitalWrite(ULTRA_LED, LOW);  // Turn OFF the ultrasonic sensor LED
  }
}

void checkWaterSensor() {
  int sensorValue = digitalRead(WATER_SENSOR_PIN);

  if (sensorValue == HIGH) {
    // Water detected, turn on the water detection LED
    digitalWrite(WATER_SENSOR_LED, HIGH);
    digitalWrite(ULTRA_LED, HIGH);
    Serial.println("Water detected! LED ON");
  } else {
    // No water detected, turn off the water detection LED
    digitalWrite(WATER_SENSOR_LED, LOW);
    digitalWrite(ULTRA_LED, LOW);
    Serial.println("No water detected. LED OFF");
  }
}

long getUltrasonicDistance(int trigPin, int echoPin) {
  // Send a 10µs pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  long distance = duration * 0.034 / 2; // Speed of sound is 343 m/s or 0.034 cm/µs
  return distance;
}

void checkUltrasonicSensors() {
  long distance1 = getUltrasonicDistance(TRIG_PIN1, ECHO_PIN1);
  long distance2 = getUltrasonicDistance(TRIG_PIN2, ECHO_PIN2);

  Serial.print("Distance from Sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distance from Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Check if the distance from either sensor is less than 20 cm
  if (distance1 < 20 || distance2 >7) {
    digitalWrite(ULTRA_LED, HIGH);  // Turn ON the LED
    Serial.println("Object detected within 20 cm! LED ON");
  } else {
    digitalWrite(ULTRA_LED, LOW);  // Turn OFF the LED
    Serial.println("No object within 20 cm. LED OFF");
  }
}

void loop() {
  // Handle incoming web server requests
  server.handleClient();

  // Read the ON/OFF button state
  bool currentButtonState = digitalRead(BUTTON_PIN_ONOFF);

  // Check for a button press (LOW indicates pressed with INPUT_PULLUP)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    toggleSystem(); // Toggle system ON/OFF
    delay(300);     // Debounce delay
  }

  // Update the button state
  lastButtonState = currentButtonState;

  if (systemOn) {
    checkWaterSensor();      // Check water sensor
    checkUltrasonicSensors(); // Check ultrasonic sensors

    if (digitalRead(BUTTON_PIN_GPS) == LOW) {
      Serial.println("GPS Button pressed!");

      // Wait for valid GPS data
      while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
      }

      if (gps.location.isUpdated()) {
        double latitude = gps.location.lat();
        double longitude = gps.location.lng();

        // Create a Google Maps URL with the GPS coordinates
        String googleMapsUrl = "https://maps.google.com/?q=" + String(latitude, 6) + "," + String(longitude, 6);

        // Construct the message
        String message = "Help me! My live location: " + googleMapsUrl;

        // Send the message via Twilio
        sendSMS(message);

        // Print for debugging
        Serial.println("LAT: " + String(latitude, 6));
        Serial.println("LONG: " + String(longitude, 6));
        Serial.println("SMS Sent: " + message);
      } else {
        Serial.println("Waiting for valid GPS data...");
      }
      delay(3000); // Debounce delay for the GPS button
    }
  }

  delay(500);  // Main loop delay
}
