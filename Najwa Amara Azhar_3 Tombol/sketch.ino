// Pin definisi
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int button1 = 10;  // Tombol untuk running dari kiri ke kanan
const int button2 = 9;  // Tombol untuk running dari kanan ke kiri
const int button3 = 8;  // Tombol untuk running bolak-balik

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  // Atur pin LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Atur pin tombol sebagai input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Awal status LED mati
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  // Baca status tombol
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);

  // Jika tombol pertama ditekan, jalankan LED dari kiri ke kanan
  if (buttonState1 == HIGH) {
    runLeftToRight();
  }

  // Jika tombol kedua ditekan, jalankan LED dari kanan ke kiri
  if (buttonState2 == HIGH) {
    runRightToLeft();
  }

  // Jika tombol ketiga ditekan, jalankan LED bolak-balik
  if (buttonState3 == HIGH) {
    runBackAndForth();
  }
}

// Fungsi untuk menjalankan LED dari kiri ke kanan
void runLeftToRight() {
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);

  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);

  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
}

// Fungsi untuk menjalankan LED dari kanan ke kiri
void runRightToLeft() {
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);

  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);

  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
}

// Fungsi untuk menjalankan LED bolak-balik
void runBackAndForth() {
  // Kiri ke kanan
  runLeftToRight();
  // Kanan ke kiri
  runRightToLeft();
}