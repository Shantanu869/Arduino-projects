const int pushbutton= 2;
const int led_pin= 13;
int button_state=0;
void setup()
{
  pinMode(pushbutton,INPUT);
  pinMode(led_pin,OUTPUT);
}

void loop()
{
  button_state=digitalRead(pushbutton);
  if(button_state== HIGH)
  {
    digitalWrite(led_pin,HIGH);
    delay(500);
    digitalWrite(led_pin,LOW);
  }
  else
  {
    digitalWrite(led_pin,LOW);
  }
}

