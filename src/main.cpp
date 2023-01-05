#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Fonts/FreeSans12pt7b.h>

const uint8_t PIN_SPI_RST = 2; // Used for ST7789
const uint8_t PIN_SPI_DC = 4; // Used for ST7789
const uint8_t PIN_SPI_CS_SS = 15; // Used for ST7789
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13; // Used for ST7789
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12;
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 14; // Used for ST7789
const uint8_t PIN_I2C_SDA = 21;
const uint8_t PIN_I2C_SCL = 22;
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;

const uint16_t DISPLAY_COLOR = ST77XX_BLACK;
const uint16_t DISPLAY_TEXT_COLOR = ST77XX_WHITE;

Adafruit_ST7789 display = Adafruit_ST7789(
        PIN_SPI_CS_SS,
        PIN_SPI_DC,
        PIN_SPI_SDA_SDI_DARA_IN_MOSI,
        PIN_SPI_SCK_CLK_SCL_SCLK,
        PIN_SPI_RST
);

TaskHandle_t Task1;
TaskHandle_t Task2;

void setupDisplay() {
    display.init(240, 280);
    display.fillScreen(DISPLAY_COLOR);
    display.setRotation(2);
    display.setTextSize(1);
    display.setFont(&FreeSans12pt7b);
    display.setTextColor(DISPLAY_TEXT_COLOR);
    display.setCursor(90, 140);
    display.println("Start");
}

void task1(void *pvParameters) {
    while (true) {

    }
}

void task2(void *pvParameters) {
    while (true) {

    }
}

void setupTasks() {
    xTaskCreatePinnedToCore(
            task1,
            "task1",
            50000,
            NULL,
            1,
            &Task1,
            0);
    xTaskCreatePinnedToCore(
            task2,
            "task2",
            50000,
            NULL,
            1,
            &Task2,
            1);
}

void setup() {
    setupDisplay();
//    setupTasks();
}

void loop() {
}