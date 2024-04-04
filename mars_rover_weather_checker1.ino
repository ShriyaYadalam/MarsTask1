#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
Servo servo; //I'm creating a servo object. 
void setup()
{
  Serial.begin(9600); 
  lcd.init();
  lcd.setCursor(0,0);
  lcd.backlight();
  lcd.display();
  pinMode(A1,INPUT); 
  servo.attach(A1);
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  pinMode(A3,INPUT);
  pinMode(6,OUTPUT);
}
void loop()
{
  int temp=analogRead(A0);
  float v=temp*(5.0/1023.0);//analog V to V
  float t=(v-0.5)*100.0;//V to temp in Celsius
  Serial.print("Temperature=");
  Serial.print(t);
  Serial.println("C");
  delay(1000);
  lcd.print("Temperature=");
  lcd.println(t); 
  delay(1000); 
  if(t>=90)
    digitalWrite(6,HIGH);
  lcd.setCursor(0,1); 
  lcd.print("Light int=");
  lcd.println(analogRead(A2));
  delay(3000);
  lcd.clear(); 
  int moisture = analogRead(A3);
  int moisturepercentage = map(moisture, 0, 1023, 0, 100);
  Serial.print("moisture percentage content = ");
  Serial.println(moisturepercentage);
  if(moisturepercentage>=0&&moisturepercentage<=15)
  {
    //dry
    servo.write(0);
  }
  else if(moisturepercentage>=35&&moisturepercentage<=50)
  {
    //medium
    servo.write(90);
  }
  else if(moisturepercentage>=70&&moisturepercentage<=85)
  {
    //wet
    servo.write(180);
  }
} 