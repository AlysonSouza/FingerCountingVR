// Tactile Stimulation Device Firmware

int received;
boolean newData = false;

//These numbers are related to which pin in the Arduino each motor is connected.
//Change the numbers if you connect the motors in different pins.

int led = 2;
int motor1 = 3;
int motor2 = 5;
int motor3 = 6;
int motor4 = 9;
int motor5 = 11;

//This number defines the stimuli duration in milliseconds.
int stimuliDuration = 500;



char fingers[6] = "000000";

void setup() {
    Serial.begin(9600);
    Serial.println("Ho");
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);
    pinMode(motor4, OUTPUT);
    pinMode(motor5, OUTPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    recvArray();
    vibrateMotors();
}

void recvArray() {
    if (Serial.available() > 0) {
        received = Serial.readBytes(fingers, 6);
        newData = true;
    }
}

void vibrateMotors() {
    if (newData == true) {
        newData = false;
        if (fingers[5] == '1') {
          stimuliDuration = 1000;
        } else {
          stimuliDuration = 500;
        }
        digitalWrite(led, HIGH);
        if (fingers[0] == '1') {
            digitalWrite(motor1, HIGH);
        }
        if (fingers[1] == '1') {
            digitalWrite(motor2, HIGH);
        }
        if (fingers[2] == '1') {
            digitalWrite(motor3, HIGH);
        }
        if (fingers[3] == '1') {
            digitalWrite(motor4, HIGH);
        }
        if (fingers[4] == '1') {
            digitalWrite(motor5, HIGH);
        }
        delay(stimuliDuration);
        if (fingers[0] == '1') {
            digitalWrite(motor1,LOW);
        }
        if (fingers[1] == '1') {
            digitalWrite(motor2,LOW);
        }
        if (fingers[2] == '1') {
            digitalWrite(motor3,LOW);
        }
        if (fingers[3] == '1') {
            digitalWrite(motor4,LOW);
        }
        if (fingers[4] == '1') {
            digitalWrite(motor5,LOW);
        }
        digitalWrite(led, LOW);
    }
}
