byte led1 = 7; 
byte led2 = 6; 
byte led3 = 5; 
byte led4 = 8; 
byte led5 = 9; 
byte led6 = 10; 
byte led7 = 2; 
byte led8 = 3; 
byte led9 = 4; 
void setup() {

pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);

}

void loop() {
 
digitalWrite(led3, HIGH); //Hijau atas
digitalWrite(led4, HIGH); //Merah Kiri
digitalWrite(led7, HIGH); //Merah Kanan
delay(5000); 
digitalWrite(led3, LOW); //Hijau Atas
digitalWrite(led7, LOW); //Merah Kanan

digitalWrite(led2, HIGH); //Kuning atas
digitalWrite(led8, HIGH); //kuning Kanan
delay(800);
digitalWrite(led2, LOW); //Kuning atas
digitalWrite(led8, LOW); //kuning Kanan


//KONDISI 2
digitalWrite(led9, HIGH); //Hijau Kanan
digitalWrite(led4, HIGH); //Merah Kiri
digitalWrite(led1, HIGH); //Merah Atas
delay(5000); 
digitalWrite(led9, LOW); //Hijau Kanan
digitalWrite(led4, LOW); //Merah Kiri

digitalWrite(led8, HIGH); //kuning Kanan
digitalWrite(led5, HIGH); //Kuning Kiri
delay(800);
digitalWrite(led8, LOW); //kuning Kanan
digitalWrite(led5,LOW); //Kuning Kiri


//KONDISI 3
digitalWrite(led6, HIGH); // Hijau Kiri
digitalWrite(led7, HIGH); //Merah Kanan
digitalWrite(led1, HIGH); //Merah atas
delay(5000);
digitalWrite(led6, LOW); //Hijau Kiri
digitalWrite(led1, LOW); //Merah Atas

digitalWrite(led2, HIGH); //Kuning atas
digitalWrite(led5, HIGH); //Kuning Kiri
digitalWrite(led8, HIGH); //kuning Kanan
delay(800);
digitalWrite(led2, LOW); //Kuning atas
digitalWrite(led5,LOW); //Kuning Kiri



}
