int m;// initialise variable m
float n;//initialise variable n
int maxValue = 0;

void setup()
{
  pinMode(A0,INPUT); // set pin a0 as input pin
  Serial.begin(9600);// begin serial communication between arduino and pc
}

void loop()
{
  m=analogRead(A0);// read analog values from pin A0 across capacitor

  if (m > maxValue)
  {
   maxValue = m ;
  };
  if (m == 0)
  {
    maxValue = 0;
  };
   n=((maxValue *(5.0/1023.0)) /.34131);// converts analog value(x) into input ac supply value using this formula ( explained in woeking section)
   Serial.print("   Analog Value  " ) ; // specify name to the corresponding value to be printed
   Serial.print(m) ;
   Serial.print("   maxValue  " ) ; // specify name to the corresponding value to be printed
   Serial.print(maxValue) ; // print input analog value on serial monitor
   Serial.print("   ac voltage  ") ; // specify name to the corresponding value to be printed
   Serial.print(n) ; // prints the ac value on Serial monitor
   Serial.println();

   //delay(5000);
}
