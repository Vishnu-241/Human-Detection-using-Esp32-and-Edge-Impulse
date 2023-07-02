// 27_EdgeImpulse_FOMO.ino
#define MAX_RESOLUTION_VGA 1
int buzzerPin = 4; // Pin connected to the buzzer



/**
 * Run Edge Impulse FOMO model on the Esp32 camera
 */

// replace with the name of your library


#include <esp32-cam-object-detection_inferencing.h>
#include "esp32cam.h"
#include "esp32cam/http/LiveFeed.h"
#include "esp32cam/tinyml/edgeimpulse/FOMO.h"


#define WIFI_SSID "siri2"
#define WIFI_PASS "7997171047"

using namespace Eloquent::Esp32cam;

Cam cam;
TinyML::EdgeImpulse::FOMO fomo;
Eloquent::Esp32cam::Http::LiveFeed feed(cam, 80);


void setup() {

   pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
 
    Serial.begin(115200);
    Serial.println("Init");

    cam.aithinker();
    cam.highQuality();
    cam.highestSaturation();
    cam.vga();

    while (!cam.begin())
        Serial.println(cam.getErrorMessage());
    while (!cam.connect(WIFI_SSID, WIFI_PASS))
        Serial.println(cam.getErrorMessage());

    //Initialize live feed http server
    // If something goes wrong, print the error message
    while (!feed.begin())
        Serial.println(feed.getErrorMessage());

    // make the camera accessible at http://esp32cam.local
    if (!cam.viewAt("esp32cam"))
        Serial.println("Cannot create alias, use the IP address");
    else
        Serial.println("Live Feed available at http://esp32cam.local");

    // display the IP address of the camera
    Serial.println(feed.getWelcomeMessage());
}

void loop() {
    if (!cam.capture()) {
        Serial.println(cam.getErrorMessage());
        delay(1000);
        return;
    }

    // run FOMO model
    if (!fomo.detectObjects(cam)) {
        Serial.println(fomo.getErrorMessage());
        delay(1000);
        return;
    }

    // print found bounding boxes
    if (fomo.hasObjects()) {
      
      
        Serial.printf("Found %d objects in %d millis\n", fomo.count(), fomo.getExecutionTimeInMillis());

        fomo.forEach([](size_t ix, ei_impulse_result_bounding_box_t bbox) {
            Serial.print(" > BBox of label ");
            Serial.print(bbox.label);
            Serial.print(" at (");
            Serial.print(bbox.x);
            Serial.print(", ");
            Serial.print(bbox.y);
            Serial.print("), size ");
            Serial.print(bbox.width);
            Serial.print(" x ");
            Serial.print(bbox.height);
            Serial.println();
        });
  digitalWrite(buzzerPin,HIGH);
  
    
    }
    else {
     
        Serial.println("No objects detected");
        digitalWrite(buzzerPin, LOW);
  
    }

}