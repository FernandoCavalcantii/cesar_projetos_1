#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the Arduino pin number it is connected to
const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte quadrado_vazio[8] = {
    B11111,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B11111,
};

byte quadrado_preenchido[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
};

String tempoPrim;
String tempoRec;
String tempoSeg; 

// CODE THAT RUNS ONCE
void setup() {
    // set up start communications
    Serial.begin(9600);

    Serial.println("initializing setup...");
    Serial.println("digite o tempo(em segundos) que vai durar o primeiro horário:");

    while (true) {
        tempoPrim = Serial.readString();
        if (tempoPrim.length() > 0) {
            break;
        }
    }
    
    Serial.println("digite o tempo(em segundos) que vai durar o recreio:");

    while (true) {
        tempoRec = Serial.readString();
        if (tempoRec.length() > 0) {
            break;
        }
    }

    Serial.println("digite o tempo (em segundos) ate o final da aula:");

    while (true) {
        tempoSeg = Serial.readString();
        if (tempoSeg.length() > 0) {
            break;
        }
    }
    
    // ## Display LCD
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Create 02 custom chars to write to display in the LCD
    lcd.createChar(0, quadrado_vazio);
    lcd.createChar(1, quadrado_preenchido);
    lcd.write(byte(0));
    lcd.write(byte(1));
    // Clear the display of the LCD.
    lcd.clear();
    // Display Message Initializing on Display LCD
    lcd.setCursor(0, 0);
    lcd.print("Iniciando...");
    delay(1000);
    lcd.setCursor(8, 1);
    lcd.print("SETUP...");
    delay(2000);
    lcd.clear();

    Serial.println("Projeto Sala Inteligente: Display do Recreio");

    // Print a message to the LCD.
    Serial.println("Projeto");
    lcd.setCursor(0, 0);
    lcd.print("Projeto");
    delay(1000);
    Serial.println("Display Recreio");
    lcd.setCursor(0, 1);
    lcd.print("Display Recreio");
    delay(2000);
    lcd.clear();

    Serial.println("Carregando... ");

    // Iteração do display LCD inicial movendo as letras em um FOR LOOP
    for (int i = 0; i <= 15; i++) {
        lcd.setCursor(0, 0);
        lcd.print("Carregando...");
        lcd.setCursor(i, 1);
        lcd.print("*");
        delay(200);
        lcd.clear();
    }

    Serial.println("## SETUP COMPLETO ##");
}

void montaTelaHello(int tempo2) {
    Serial.println("called montaTelaHello()");
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Hora do...");
    delay(2000);
    lcd.setCursor(2, 0);
    lcd.print("Recreio! :)");
    lcd.setCursor(0, 1);

    for (int i = 0; i < 16; i++) {
        lcd.write(byte(0));
    }

    for (int i = 0; i < 16; i++) {
        lcd.setCursor(i, 1);
        lcd.write(byte(1));
        delay(tempo2 * 1000 / 16); // Dividir o tempo total pelo número de quadrados para preencher
    }
}

void montaTelaBlank(int tempo3) {
    Serial.println("called montaTelaBlank()");
    lcd.clear();
    
    delay(tempo3 * 1000);

}

void loop() {
    int tempo1 = tempoPrim.toInt(); 
    int tempo2 = tempoRec.toInt(); 
    int tempo3 = tempoSeg.toInt(); 
    delay(tempo1 * 1000);
    
    montaTelaHello(tempo2);
    montaTelaBlank(tempo3);
    lcd.setCursor(0,0);
    lcd.print("A Aula Acabou!");
    delay(3000);
    lcd.clear();
}
