#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "Arduino.h"

// Definisikan pin GPIO
#define LED_MERAH   25
#define LED_KUNING  26
#define LED_HIJAU   27

#define TOMBOL_1    32
#define TOMBOL_2    15
#define TOMBOL_3    4

// Variabel global untuk status LED
volatile int led_state = 0;

// Task untuk mengontrol LED
void led_task(void *pvParameters) {
    while(1) {
        switch (led_state) {
            case 0: // Semua LED mati
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, LOW);
                break;
            case 1: // Pola LED Blink ALL
                Serial.println("Mode: Blink All");
                digitalWrite(LED_MERAH, HIGH);
                digitalWrite(LED_KUNING, HIGH);
                digitalWrite(LED_HIJAU, HIGH);
                vTaskDelay(pdMS_TO_TICKS(500));
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;
            case 2: //  Pola Running Kekiri
                Serial.println("Mode: Running Kekiri");
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, HIGH);
                vTaskDelay(pdMS_TO_TICKS(500));
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, HIGH);
                digitalWrite(LED_HIJAU, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
                digitalWrite(LED_MERAH, HIGH);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;
            case 3: // Pola Running Kekanan
                Serial.println("Mode: Running Kekanan");
                digitalWrite(LED_MERAH, HIGH);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, HIGH);
                digitalWrite(LED_HIJAU, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
                digitalWrite(LED_MERAH, LOW);
                digitalWrite(LED_KUNING, LOW);
                digitalWrite(LED_HIJAU, HIGH);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;
        }
    }
}

// Task untuk Tombol 1
void tombol_1_task(void *pvParameters) {
    int last_button_state = HIGH;
    while(1) {
        int current_button_state = digitalRead(TOMBOL_1);
        if (current_button_state == LOW && last_button_state == HIGH) {
            led_state = 1;
            Serial.println("Tombol 1 ditekan. Mengubah mode ke Blink All.");
            vTaskDelay(pdMS_TO_TICKS(200)); // Debouncing
        }
        last_button_state = current_button_state;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

// Task untuk Tombol 2
void tombol_2_task(void *pvParameters) {
    int last_button_state = HIGH;
    while(1) {
        int current_button_state = digitalRead(TOMBOL_2);
        if (current_button_state == LOW && last_button_state == HIGH) {
            led_state = 2;
            Serial.println("Tombol 2 ditekan. Mengubah mode ke Running Kekiri.");
            vTaskDelay(pdMS_TO_TICKS(200));
        }
        last_button_state = current_button_state;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

// Task untuk Tombol 3
void tombol_3_task(void *pvParameters) {
    int last_button_state = HIGH;
    while(1) {
        int current_button_state = digitalRead(TOMBOL_3);
        if (current_button_state == LOW && last_button_state == HIGH) {
            led_state = 3;
            Serial.println("Tombol 3 ditekan. Mengubah mode ke Running Kekanan.");
            vTaskDelay(pdMS_TO_TICKS(200));
        }
        last_button_state = current_button_state;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void setup() {
    Serial.begin(115200); // Inisialisasi Serial Monitor
    Serial.println("Program FreeRTOS dimulai.");
    
    // Konfigurasi pin LED sebagai OUTPUT
    pinMode(LED_MERAH, OUTPUT);
    pinMode(LED_KUNING, OUTPUT);
    pinMode(LED_HIJAU, OUTPUT);
    
    // Konfigurasi pin Tombol sebagai INPUT_PULLUP
    pinMode(TOMBOL_1, INPUT_PULLUP);
    pinMode(TOMBOL_2, INPUT_PULLUP);
    pinMode(TOMBOL_3, INPUT_PULLUP);

    // Membuat task LED
    xTaskCreate(led_task, "LED_Task", 2048, NULL, 1, NULL);

    // Membuat task untuk setiap tombol
    xTaskCreate(tombol_1_task, "Tombol_1_Task", 2048, NULL, 2, NULL);
    xTaskCreate(tombol_2_task, "Tombol_2_Task", 2048, NULL, 2, NULL);
    xTaskCreate(tombol_3_task, "Tombol_3_Task", 2048, NULL, 2, NULL);
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000));
}
