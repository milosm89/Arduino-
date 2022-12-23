/*
 Wash machine programer sketch for Arduino writr in C++.
 This is a simply illustration of wash machine prgramer.
*/

int E12 = 3;
int pin1 = 4;
int pin2 = 5;
int ledPin7 = 7;
int ledPin8 = 8;
int ledPin12 =12;

void setup()
{
  Serial.begin(9600);
  pinMode(E12, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  
  Serial.println("Chose the wash program: ");
  Serial.println("1. 30 C at 400pm");
  Serial.println("2. 30 C at 800pm");
  Serial.println("3. 30 C at 1200pm");
  Serial.println("4. 60 C at 400pm");
  Serial.println("5. 60 C at 800pm");
  Serial.println("6. 60 C at 1200pm");
  Serial.println("7. 90 C at 400pm");
  Serial.println("8. 90 C at 800pm");
  Serial.println("9. 90 C at 1200pm");
  
  while (Serial.available() == 0) {}

  int washProgram = Serial.parseInt();
 
  switch (washProgram) {
    case 1:

      // 30 C program
      Serial.println("The 30 C at 400 Rpm program start: ");
    
      degres_30(100 , 12);
        
        break;
    
    case 2:

      // 30 C program
      Serial.println("The 30 C at 800 Rpm program start: ");
    
      degres_30(100 , 24);
        
        break;
    
    case 3:

      // 30 C program
      Serial.println("The 30 C at 1200 Rpm program start: ");
    
      degres_30(100 , 36);
        
        break;
    
    case 4:

      // 60 C program
      Serial.println("The 60 C at 400 Rpm program start: ");
    
      degres_60(150 , 12);
        
        break;
    
    case 5:

      // 60 C program
      Serial.println("The 60 C at 800 Rpm program start: ");
    
      degres_60(150 , 24);
        
        break;
    
    case 6:

      // 60 C program
      Serial.println("The 60 C at 1200 Rpm program start: ");
    
      degres_60(150 , 36);
        
        break;
    
    case 7:

      // 90 C program
      Serial.println("The 90 C at 400 Rpm program start: ");
    
      degres_90(200 , 12);
        
        break;
    
    case 8:

      // 90 C program
      Serial.println("The 90 C at 800 Rpm program start: ");
    
      degres_90(200 , 24);
        
        break;
    
    case 9:

      // 90 C program
      Serial.println("The 90 C at 1200 Rpm program start: ");
    
      degres_90(200 , 36);
        
        break;

    default:
      Serial.println("Please choose a valid option");
  }
  
}

void loop()
{
 	// 
}
// Water In funcion
void waterIn(int j) {

    if(j <=10) {
        digitalWrite(ledPin7, HIGH);
    }
    else {
        digitalWrite(ledPin7, LOW);
    }
}

// Water Out function
void waterOut(int j, int min, int max) {

    if(j >= min && j <= max) {
        digitalWrite(ledPin12, HIGH);
    }
    else {
        digitalWrite(ledPin12, LOW);
    }
}

// Heater function
void heater(int j, int min, int max) {

    if(j >= min && j <=max) {
        digitalWrite(ledPin8, HIGH);
        Serial.println("Heater is on");
    }
    else {
        digitalWrite(ledPin8, LOW);
    }
}

// Rotate function
void rotate(int j, int min, int max) {

    if(j >= min && j <= max) {

        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        analogWrite(E12, 8);
        delay(500);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        delay(500);
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        analogWrite(E12, 8);
        delay(500);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        delay(500);       
    } 
}

// Centrifuge function
void centrifuge(int j, int min, int max, int speed) {

    if(j >= min && j <= max) {
        
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        analogWrite(E12, speed);
        delay(1000);
    }
}

// Second loop for wash program
void secondLoop(int speed) {

    for (int j = 0; j <=80; j++) {

            //Water in
            waterIn(j);
            //Ratation
            rotate(j, 5, 45); 
            //Water Out
            waterOut(j, 40, 70);
            //Centrifuge
            centrifuge(j, 50, 65, speed);
            //Roation
            rotate(j, 72, 80);  
    }
    //Finish message    
    Serial.println("Program finished!");
}

// main loop 
void degres_30(int max, int speed) {
	
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) {

            for (int j = 0; j <= max; j++) {

                //Water in
                waterIn(j);
                //Ratation
                rotate(j, 5, 62); 
                //Heater
                heater(j, 15, 25);
                //Water Out
                waterOut(j, 60, 85);
                //Centrifuge
                centrifuge(j, 60, 85, speed);
                //Roation
                rotate(j, 85, 95);
            }
        }else {
            
            secondLoop(speed);
        }
    }
  
}
void degres_60(int max, int speed) {
	
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) {

            for (int j = 0; j <= max; j++) {

                //Water in
                waterIn(j);
                //Ratation
                rotate(j, 5, 82); 
                //Heater
                heater(j,15, 55);
                //Water Out
                waterOut(j, 90, 145);
                //Centrifuge
                centrifuge(j, 100, 135, 24);
                //Roation
                rotate(j, 140, 150);
            }
        }else {
            
            secondLoop(speed);
        }
    }
  
}
void degres_90(int max, int speed) {
	
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) {

            for (int j = 0; j <= max; j++) {

               //Water in
                waterIn(j);
                //Ratation
                rotate(j, 5, 135); 
                //Heater
                heater(j,15, 75);
                //Water Out
                waterOut(j, 140, 180);
                //Centrifuge
                centrifuge(j, 120, 170, 24);
                //Roation
                rotate(j, 175, 195);
            }
        }else {
            
            secondLoop(speed);
        }
    }
  
}