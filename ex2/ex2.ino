int led = 9;
int key = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(key, INPUT);
}

void loop() {
  if (digitalRead(key) == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
