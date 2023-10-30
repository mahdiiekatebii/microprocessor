int LED = 9;
int pt = 3;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(pt, INPUT);
}

void loop() {
  int A = analogRead(pt);
  int B = map(A, 0, 1023, 0, 255);
  analogWrite(LED, B);
}
