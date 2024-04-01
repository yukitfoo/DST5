// Potentiometer is connected to GPIO 26 (Analog ADC0)
const int potPin = 28;
const int pwmOut = 26;

// variable for storing the potentiometer value
int potValue = 0;
float pwmVal = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(potPin, INPUT);
  pinMode(pwmOut, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  pwmVal = (255./4095.)*potValue;
  analogWrite(pwmOut, pwmVal);
  analogWrite(LED_BUILTIN, pwmVal);
  Serial.println(String(potValue) + " "+ String(pwmVal));
}