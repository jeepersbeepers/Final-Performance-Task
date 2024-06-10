#define RELAY_PIN 7
#define airHumidity A0

#define THRESHOLD 530

void setup() {
  // put your setup code here, to run once:
  pinMode(airHumidity, INPUT);
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(airHumidity); // reads the analog value from sensor
  Serial.println(val);
  if(val > THRESHOLD)
  {
    Serial.print("The air temperature is DRY => activate pump");
    digitalWrite(RELAY_PIN, HIGH);
    
  } else {
    Serial.print("The air temperature is HUMID => deactivate the pump");
    digitalWrite(RELAY_PIN, LOW);
    
  }
   Serial.print(" (");
  Serial.print(450);
  Serial.println(")");

  delay(1000);
}

