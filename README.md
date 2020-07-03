# Plant-Watering

This project is an automatic plant watering system. Arduino controls the pump based on the soil moisture level read. Raspberry Pi shows you the soil moisture level through the Arduino IDE app. When the soil moisture drops below the threshold value (default 5), water is pumped through the tubing for 1 second.

![ProjectJPG](https://github.com/carolinedunn/Plant-Watering/blob/master/photos/wateringsystemfinal.jpg)

Materials:
- <a href="https://amzn.to/2BAau65">Your potted plant. I'm using this Bonsai Tree.</a> (It is best to start this project with dry soil.)
- Arduino Uno - https://amzn.to/2VIyRW5
- 9V snap connector kit - https://amzn.to/3gsXhur
  - Battery and battery pack to power the pump (I'm using a 9V battery with snap-on connector and power supply module)
  - Male-to-Male Jumper wires - https://amzn.to/2TIyXMj
  - Male-to-Female Jumper wires - https://amzn.to/2TIyXMj
  - Breadboard - https://amzn.to/2VKjJrd
- Plant watering kit: - https://amzn.to/31FSpht
  - Relay Module
  - Soil Moisture sensor (Please use a capacitive soil moisture sensor, NOT a resistive soil moisture sensor)
  - Water pump & tubing
- Small screwdriver to unscrew the relay module
- Raspberry Pi 4 - https://amzn.to/2D4nm4J
  - microSD card formatted with Raspberry Pi OS
  - power supply for Raspberry Pi and Arduino (I'm using a USB-C power bank - https://amzn.to/2VZSitN )
- Container filled with water.
- Casing for electronics (protect from rain) I'm using a 12x12 scrapbook case - https://www.michaels.com/12in-x-12in-clear-scrapbook-case/10373070.html
- Optional: Soldering iron, flux, and wire

## Step 1 - Hardware Assembly
Hardware Assembly from https://www.littlebird.com.au/a/how-to/71/automatic-plant-watering-with-arduino
1. Connect the VCC on the relay to 5V pin on Arduino
2. Connect GND from the relay to the negative power rail of the breadboard
3. Connect IN on relay to Pin 8 on Arduino
4. Connect negative (black) wire from the battery pack to the negative power rail of the breadboard
5. Connect the black wire of the pump to the negative power rail of the breadboard
6. Connect the AOut from the soil moisture sensor to A0 on the Arduino
7. Connect the GND from the soil moisture sensor to GND on the Arduino
8. Connect the VCC from the soil moisture sensor to 3.3v on the Arduino
9. Connect the red wire from the pump to the NC on the relay
10. Connect the red wire from the battery pack to COM on the relay
11. Connect negative power rail from the breadboard to GND on the Arduino
12. Connect the Arduino to the Raspberry Pi via USB
13. Connect keyboard/mouse and monitor to your Raspberry Pi
14. Connect the water tubing to the pump
15. Place the pump in a container of water
16. Power up your Raspberry Pi

## Step 2 - Install Arduino on your Raspberry Pi
Instructions from - https://magpi.raspberrypi.org/articles/program-arduino-uno-raspberry-pi
1. From your Raspberry Pi OS desktop, open a Terminal
2. Run typical updates ```sudo apt-get update && sudo apt-get upgrade```
3. Next Install Arduino ide with the command ```sudo apt-get install arduino```
4. Click on the raspberry icon in the top left corner, go to "Programming" and click Arduino IDE to launch the program
5. Click File, Examples, Basic, Blink to open the Blink.ino
6. Select your Board and your Port from Tools (Arduino Uno) and the port that your Arduino is plugged into
7. Upload Blink.ino to check your Arduino is connected and working properly. If it works, the light on your Arduino should blink intermitently

## Step 3 - Test Your Soil Moisture Sensor & Calibrate
This part focuses on testing your soil moisture sensor
Code from - https://github.com/BasOnTech/Arduino-Beginners-EN/tree/master/E31-capacitive-soil-moisture-sensor and https://maker.pro/arduino/projects/arduino-soil-moisture-sensor
1. Start a new project on Arduino IDE
2. Copy <a href="https://github.com/carolinedunn/Plant-Watering/blob/master/water.ino">water.ino</a> to your Arduino IDE
3. Verify and Upload to your Arduino
4. Click Tools, then Serial Monitor
5. Dip the soil moisture sensor in and out of the container of water to watch the values change. Note the value when dipped in water.
6. Insert the soil moisture sensor into your plant's soil
7. Note the value of your soil. It is best to start with dry soil

## Step 4 - Water your plant
1. Arrange the tubing so that the water flows back into the water container
2. Start a new project on Arduino IDE
3. Copy <a href="https://github.com/carolinedunn/Plant-Watering/blob/master/soilwatering.ino">soilwatering.ino</a> to your Arduino IDE
4. Verify and Upload to your Arduino
5. Click Tools, then Serial Monitor
6. Dip the soil moisture sensor in and out of the container of water to watch the pump turn on and off. Pump should turn on when sensor is out of water and off when sensor is in water.
7. With the sensor in the water, position the tubing to plant watering. I designed and 3D printed a tube holder to keep my tube in place
8. Insert the sensor into the soil and watch your plant get watered.
9. Assuming your plant is "fully watered," take note of that value as max soil moisture.
9. Adjust the 'threshold' value to a value of your choice between dry soil value and max soil moisture value.
10. Save and upload your adjusted code to your Arduino
11. Continue to monitor your soil moisture level and iterate on your threshold value until you find the right soil moisture level for your plant.

