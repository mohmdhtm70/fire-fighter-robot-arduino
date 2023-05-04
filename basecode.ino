// motor defines 
#define M1 2 
#define M2 3 
#define M3 4 
#define M4 5 
#define EN1 10 
#define EN2 11 
#define SPEED 120 
#define RIGHT_SPEED 150 
#define LEFT_SPEED 150 

 
// ultrasoinc defines 
#define ULTRA_TRIGER 6 
#define ULTRA_ECHO 7 
 
// mov enum

enum moveEnum {straight, right, left};
 
 
 
void setup() 
{ 
 
    // debug 
    Serial.begin(9600); 
    // define motors pin mode 
    pinMode(M1, OUTPUT); 
    pinMode(M2, OUTPUT); 
    pinMode(M3, OUTPUT); 
    pinMode(M4, OUTPUT); 
    pinMode(EN1, OUTPUT); 
    pinMode(EN2, OUTPUT); 
 
    // define ultrasonic pin mode 
    pinMode(ULTRA_TRIGER, OUTPUT); 
    pinMode(ULTRA_ECHO, INPUT); 
 
    // init state 
    turnMotors(LOW); 
} 
 
// turn on/off motors 
void turnMotors(int moveType) 
{ 
    switch(moveType){
        case straight :
            analogWrite(EN1, SPEED); 
            analogWrite(EN2, SPEED); 
            digitalWrite(M1, HIGH); 
            digitalWrite(M2, LOW); 
            digitalWrite(M3, LOW); 
            digitalWrite(M4, HIGH);
        break;
        case right:
            analogWrite(EN1, RIGHT_SPEED); 
            analogWrite(EN2, RIGHT_SPEED); 
            digitalWrite(M1, HIGH); 
            digitalWrite(M2, LOW); 
            digitalWrite(M3, HIGH); 
            digitalWrite(M4, LOW);
        break;
        case left:
            analogWrite(EN1, LEFT_SPEED); 
            analogWrite(EN2, LEFT_SPEED); 
            digitalWrite(M1, LOW); 
            digitalWrite(M2, HIGH); 
            digitalWrite(M3, LOW); 
            digitalWrite(M4, HIGH);
        break;
    
    }
 
} 
 

// get distance in cm form ultrasonic 
int getDistance() 
{ 
    int t; 
    digitalWrite(ULTRA_TRIGER, LOW); 
    digitalWrite(ULTRA_ECHO, LOW); 
    delayMicroseconds(10); 
    digitalWrite(ULTRA_TRIGER, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(ULTRA_TRIGER, LOW); 
    t = pulseIn(ULTRA_ECHO, HIGH) / 2; 
    return 0.034079 * t; 
} 
 
/// move logic 
 
void moveLogic() 
{ 
    turnMotors(straight); 
    int distance = getDistance(); 
    if (distance <= 30) 
    { 
        turnMotors(right);
    } 
    else 
    { 
        turnMotors(straight);
    } 
} 
 
void loop() 
{ 
    delay(4); 
    moveLogic(); 
}
