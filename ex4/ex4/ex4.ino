int led = 6;
int pt = 3;
float val = 0.0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(pt, INPUT);
  Serial.begin(9600);
}

void loop() {
  float B = val * 5 / 1024;
  Serial.print("Put voltage is: ");
  Serial.println(B);
  analogWrite(led, B);
}
