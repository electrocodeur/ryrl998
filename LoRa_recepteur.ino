String lora_band = "866000000";   //Bande de frequence (Hz)
String lora_networkid = "5";      //Identificacion de notre réseau LoRa
String lora_address = "2";        //Addresse de notre module
//String lora_RX_address = "1";   //Addresse du module voisin

int led = 12;

String reception;

void setup()
{

  pinMode(led, OUTPUT);
  Serial.begin(115200);


  delay(1500);
  Serial.println("AT+BAND=" + lora_band);
  delay(500);
  Serial.println("AT+NETWORKID=" + lora_networkid);
  delay(500);
  Serial.println("AT+ADDRESS=" + lora_address);
  delay(1000);

}

void loop() {
  if (Serial.available()) {

    reception = Serial.readString();
    //Serial.println(reception);
    
    if (reception.indexOf("ON") > 0) {
      digitalWrite(led, !digitalRead(led));
    }
  }
}
