#include <XInput.h>

const int Pin_ButtonA = 1;
const int Pin_ButtonB = 3;
const int Pin_ButtonX = 5;
const int Pin_ButtonY = 7;
const int Pin_ButtonLB = 9;
const int Pin_ButtonRB = 11;
const int Pin_ButtonStart = 13;

const int Pin_DpadUp    = A0;
const int Pin_DpadDown  = A1;
const int Pin_DpadLeft  = A2;
const int Pin_DpadRight = A3;

void setup() {
	pinMode(2, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(12, OUTPUT);
	
	digitalWrite(2, LOW);
	digitalWrite(4, LOW);
	digitalWrite(6, LOW);
	digitalWrite(8, LOW);
	digitalWrite(10, LOW);
	digitalWrite(12, LOW);
	
	pinMode(Pin_ButtonA, INPUT_PULLUP);
	pinMode(Pin_ButtonB, INPUT_PULLUP);
	pinMode(Pin_ButtonX, INPUT_PULLUP);
	pinMode(Pin_ButtonY, INPUT_PULLUP);

	pinMode(Pin_ButtonLB, INPUT_PULLUP);
	pinMode(Pin_ButtonRB, INPUT_PULLUP);

	pinMode(Pin_ButtonStart, INPUT_PULLUP);

	pinMode(Pin_DpadUp, INPUT_PULLUP);
	pinMode(Pin_DpadDown, INPUT_PULLUP);
	pinMode(Pin_DpadLeft, INPUT_PULLUP);
	pinMode(Pin_DpadRight, INPUT_PULLUP);

	XInput.setAutoSend(false); 

	XInput.begin();
}

void loop() {
	boolean buttonA = !digitalRead(Pin_ButtonA);
	boolean buttonB = !digitalRead(Pin_ButtonB);
	boolean buttonX = !digitalRead(Pin_ButtonX);
	boolean buttonY = !digitalRead(Pin_ButtonY);

	boolean buttonLB = !digitalRead(Pin_ButtonLB);
	boolean buttonRB = !digitalRead(Pin_ButtonRB);

	boolean buttonStart = !digitalRead(Pin_ButtonStart);


	boolean dpadUp    = !digitalRead(Pin_DpadUp);
	boolean dpadDown  = !digitalRead(Pin_DpadDown);
	boolean dpadLeft  = !digitalRead(Pin_DpadLeft);
	boolean dpadRight = !digitalRead(Pin_DpadRight);

	
	XInput.setButton(BUTTON_A, buttonA);
	XInput.setButton(BUTTON_B, buttonB);
	XInput.setButton(BUTTON_X, buttonX);
	XInput.setButton(BUTTON_Y, buttonY);

	XInput.setButton(BUTTON_LB, buttonLB);
	XInput.setButton(BUTTON_RB, buttonRB);

	XInput.setButton(BUTTON_START, buttonStart);


	
	XInput.setDpad(dpadUp, dpadDown, dpadLeft, dpadRight);
	
	XInput.send();
}
