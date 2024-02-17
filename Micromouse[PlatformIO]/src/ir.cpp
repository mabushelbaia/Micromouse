// Define the GPIO numbers for the IR sensors
// The pins are defined as per the GPIO numbers on the Arduino Mega 2560 board
const int irPowerPin1 = 9;  // GPIO 9
const int irPowerPin2 = 12;  // GPIO 12
const int irPowerPin3 = 11;  // GPIO 11
const int irPowerPin4 = 10;  // GPIO 10

const int irSignalPin1 = A0;  // Analog pin 0
const int irSignalPin2 = A1;  // Analog pin 1
const int irSignalPin3 = A2;  // Analog pin 2
const int irSignalPin4 = A3;  // Analog pin 3

void setup() {
    // Initialize the serial communication for debugging
    Serial.begin(9600);

    // Set the IR power pins as outputs
    pinMode(irPowerPin1, OUTPUT);
    pinMode(irPowerPin2, OUTPUT);
    pinMode(irPowerPin3, OUTPUT);
    pinMode(irPowerPin4, OUTPUT);

    // Set the IR signal pins as outputs
    pinMode(irSignalPin1, INPUT);
    pinMode(irSignalPin2, INPUT);
    pinMode(irSignalPin3, INPUT);
    pinMode(irSignalPin4, INPUT);
}

void loop() {
    // Activate and read IR sensor 1
    digitalWrite(irPowerPin1, HIGH);
    delay(1);
    // delayMicroseconds(1000);
    int IR1Reading = analogRead(irSignalPin1);
    Serial.println(IR1Reading);
    digitalWrite(irPowerPin1, LOW);

    // Activate and read IR sensor 2
    digitalWrite(irPowerPin2, HIGH);
    delay(1);
    // delayMicroseconds(1000);
    int IR2Reading = analogRead(irSignalPin2);
    Serial.println(IR2Reading);
    digitalWrite(irPowerPin2, LOW);

    // Activate and read IR sensor 3
    digitalWrite(irPowerPin3, HIGH);
    delay(1);
    // delayMicroseconds(1000);
    int IR3Reading = analogRead(irSignalPin3);
    Serial.println(IR3Reading);
 
    digitalWrite(irPowerPin3, LOW);

    // Activate and read IR sensor 4
    digitalWrite(irPowerPin4, HIGH);
    delay(1);
    // delayMicroseconds(1000);
    int IR4Reading = analogRead(irSignalPin4);
    Serial.println(IR4Reading);
    digitalWrite(irPowerPin4, LOW);

    // Serial.println("End of cycle");
    // delay(900); // Delay before starting the next cycle
}
