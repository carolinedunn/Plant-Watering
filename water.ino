int sensor_pin = A0; 
int output_value ;

void setup() {
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }

void loop() {

  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,0,0,100);
  Serial.print("Moisture : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);
  }
