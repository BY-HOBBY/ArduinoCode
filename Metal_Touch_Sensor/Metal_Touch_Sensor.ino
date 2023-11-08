int digitalPin = 7;   // KY-036 digital interface
int analogPin = A0;   // KY-036 analog interface
int ledPin = LED_BUILTIN;      // Arduino LED pin
int digitalVal;       // digital readings
int analogVal;        // analog readings
boolean wasTouched = false; // Flag to track touch state

void setup()
{
  pinMode(digitalPin, INPUT); 
  pinMode(analogPin, INPUT);
  pinMode(ledPin, OUTPUT);      
  Serial.begin(9600);
}

void loop()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin); 
  
  if (digitalVal == HIGH) 
  {
    digitalWrite(ledPin, HIGH); // Turn ON Arduino's LED
    if (!wasTouched) {
      // Sensor is touched, print analog value
      analogVal = analogRead(analogPin);
      Serial.println(analogVal);  // Print analog value to serial
      wasTouched = true;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW);  // Turn OFF Arduino's LED
    wasTouched = false; // Reset the touch state flag
  }
  
  delay(100);
}
