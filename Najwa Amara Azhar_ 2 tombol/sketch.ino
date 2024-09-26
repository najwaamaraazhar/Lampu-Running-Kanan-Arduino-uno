
 const int ledPins[] = {13, 12, 11}; // Array pin LED
const int buttonPin1 = 10; // Pin tombol 1
const int buttonPin2 = 9;  // Pin tombol 2
const int ledCount = 3; // Jumlah LED
const int debounceDelay = 50; // Debounce delay in milliseconds

bool running = false; // Status untuk menjalankan LED
bool lastButtonState1 = LOW; // Status tombol 1 sebelumnya
bool lastButtonState2 = LOW; // Status tombol 2 sebelumnya
bool buttonState1 = LOW; // Status tombol 1 saat ini
bool buttonState2 = LOW; // Status tombol 2 saat ini
unsigned long lastDebounceTime1 = 0; // Waktu terakhir tombol 1 berubah status
unsigned long lastDebounceTime2 = 0; // Waktu terakhir tombol 2 berubah status

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // Baca status tombol 1 saat ini
  int reading1 = digitalRead(buttonPin1);

  // Jika status tombol 1 berubah, reset timer debounce
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }

  // Jika cukup waktu telah berlalu sejak perubahan terakhir pada tombol 1
  if ((millis() - lastDebounceTime1) > debounceDelay) {
    // Jika tombol 1 saat ini berbeda dari tombol 1 sebelumnya
    if (reading1 != buttonState1) {
      buttonState1 = reading1;
      // Jika tombol 1 ditekan (bukan dilepas) dan tidak sedang running
      if (buttonState1 == HIGH && !running) {
        running = true; // Set status running
        // Jalankan LED dari kiri ke kanan
        for (int i = 0; i < ledCount; i++) {
          digitalWrite(ledPins[i], HIGH);
          delay(300);
          digitalWrite(ledPins[i], LOW);
        }
        running = false; // Reset status running setelah selesai
      }
    }
  }

  // Baca status tombol 2 saat ini
  int reading2 = digitalRead(buttonPin2);

  // Jika status tombol 2 berubah, reset timer debounce
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  // Jika cukup waktu telah berlalu sejak perubahan terakhir pada tombol 2
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    // Jika tombol 2 saat ini berbeda dari tombol 2 sebelumnya
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
      // Jika tombol 2 ditekan (bukan dilepas) dan tidak sedang running
      if (buttonState2 == HIGH && !running) {
        running = true; // Set status running
        // Jalankan LED dari kanan ke kiri
        for (int i = ledCount - 1; i >= 0; i--) {
          digitalWrite(ledPins[i], HIGH);
          delay(300);
          digitalWrite(ledPins[i], LOW);
        }
        running = false; // Reset status running setelah selesai
      }
    }
  }

  // Simpan status tombol terakhir
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
}
