String lora_band = "866000000"; //Bande de frequence (Hz)
String lora_networkid = "5";    //Identificacion de notre réseau LoRa
String lora_address = "1";      //Addresse de notre module
String lora_RX_address = "2";   //Addresse du module voisin

int bouton = 2;

void setup() {

  Serial.begin(115200);
  pinMode(bouton, INPUT);

  delay(1500);
  Serial.println("AT+BAND=" + lora_band);
  delay(500);
  Serial.println("AT+ADDRESS=" + lora_address);
  delay(500);
  Serial.println("AT+NETWORKID=" + lora_networkid);
  delay(1500);

}

void loop()
{
  delay(500);
  
  if (digitalRead(bouton) == HIGH) {
    String message = "AT+SEND=2,2,ON\r\n";
    Serial.print(message);
  }
  else {
    //Serial.print("AT+SEND=2,3,OFF\r\n");
  }
}
