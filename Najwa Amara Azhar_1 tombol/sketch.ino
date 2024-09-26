const int ledPins[] = {13, 12, 11};  
const int buttonPin = 10;          
int ledCount = 3;                 
int currentLed = 0;               
bool buttonState = false;          
bool running = false;              // Status untuk menjalankan LED

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);  
  }
  pinMode(buttonPin, INPUT);      
}

void loop() {
  if (digitalRead(buttonPin) == HIGH && !running) { // Cek jika tombol ditekan dan belum running
    running = true;  // Set status running
    currentLed = 0;  // Reset currentLed ke awal
    for (int i = 0; i < ledCount; i++) { // Jalankan LED satu kali dari kiri ke kanan
      digitalWrite(ledPins[i], HIGH); 
      delay(300); 
      digitalWrite(ledPins[i], LOW);
    }
    running = false; // Reset status running setelah selesai
  }
}



