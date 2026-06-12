const uint8_t buttonpins[] = {0, 1, 2, 3};  
const uint8_t ledpins[] = {4, 5, 6, 7};
const uint8_t buzzerpin = 8;
const uint8_t numbuttons = sizeof(buttonpins) / sizeof(buttonpins[0]);
const int buzzerfrequency[] = {500, 700, 900, 1100};
void setup() {
    for (int i = 0; i < numbuttons; i++) {
        pinMode(buttonpins[i], INPUT_PULLUP);
        pinMode(ledpins[i], OUTPUT);
        pinMode(buzzerpin, OUTPUT);
        digitalWrite(ledpins[i], HIGH);
    }
long starttime = millis();



}
void lightandsound(byte ledindex) {
    digitalWrite(ledpins[ledindex], LOW);
    tone(buzzerpin, buzzerfrequency[ledindex], 200);
    delay(200);
     digitalWrite(ledpins[ledindex], HIGH);
  
}

void loop() {
    int pitch = 0;
    for (int i = 0; i < numbuttons; i++) {
        if (digitalRead(buttonpins[i]) == LOW) {
            lightandsound(i);
        }
    }
    if (pitch > 0) {
        tone(buzzerpin, pitch);
    } else {
        noTone(buzzerpin);
    }
}



