const int og_bit_1 = 1; //Pin for bit 1 of the original message
const int og_bit_2 = 2; //Pin for bit 2 of the original message
const int og_bit_3 = 3; //Pin for bit 3 ""
const int og_bit_4 = 4; //Pin for bit 4 ""

String _message = "";

const double BAUD_RATE = 115200;

void setup() {
  // put your setup code here, to run once:
  pinMode(og_bit_1, OUTPUT);
  pinMode(og_bit_2, OUTPUT);
  pinMode(og_bit_3, OUTPUT);
  pinMode(og_bit_4, OUTPUT);

  Serial.begin(BAUD_RATE);
  Serial.println("---- Program Started ----");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool messageReceived = ReadFromSerial();

  if (messageReceived == true)
  {
    ProcessMessage(_message);
  }

}

bool ReadFromSerial()
{    
    // Local variables   
    static String msgBuffer;        // Stores the received message
    static bool isMessage = true;
    byte recByte;                   // Byte received from the serial port
    
    // Check if any new data is available, if not exit
    if (Serial.available() == false)
        return false;
    
    // Read single byte from serial port
    recByte = Serial.read();
    
    // Check if byte is termination character (carraige return)
    if (recByte == '\r')
    {
        // Save buffers to global variables
        msgBuffer.toUpperCase();
        _message = msgBuffer;
      
        // Write what was received back to the serial port
        Serial.print("Received: "); 
        Serial.println(_message); 
        // Clear local variables
        msgBuffer = "";
        if (isMessage == false)
        {
          Serial.println("Invalid Message");
        }
        isMessage = true;
      
        return true;
    }

    // Save data to one of the receive buffers
    if ((char)recByte == '1' || (char)recByte == '0')
    {
      if (isMessage == true)
      {
        msgBuffer += (char)recByte;
      }
    }
    else
    {
      isMessage = false;
      return false;
    }
    
    return false;
}

// Processes the command and data, sends result to serial port

void ProcessMessage(String message)
{  
    // Process command
    if (message.length() == 4)
    {
      Serial.print("Sending message:  ");
      Serial.println(message);
      String bit_1 = message.substring(0, 1);
      String bit_2 = message.substring(1, 2);
      String bit_3 = message.substring(2, 3);
      String bit_4 = message.substring(3, 4);

      if (bit_1 == "1")
      {
        digitalWrite(og_bit_1, HIGH);
      }
      else if (bit_1 == "0")
      {
        digitalWrite(og_bit_1, LOW);
      }

      if (bit_2 == "1")
      {
        digitalWrite(og_bit_2, HIGH);
      }
      else
      {
        digitalWrite(og_bit_2, LOW);
      }

      if (bit_3 == "1")
      {
        digitalWrite(og_bit_3, HIGH);
      }
      else
      {
        digitalWrite(og_bit_3, LOW);
      }

      if (bit_4 == "1")
      {
        digitalWrite(og_bit_4, HIGH);
      }
      else
      {
        digitalWrite(og_bit_4, LOW);
      }
      Serial.println("Message Sent");
    }
    else
    {
      Serial.println("Invalid code.");
    }
}

/*
void ReadMessage()
{
  static String fin_msg;
  if digitalRead(final_bit_1) == "HIGH":
  {
    fin_msg += '1'
  }
  else
  {
    fin_msg += '0'
  }
  if digitalRead(final_bit_2) == "HIGH":
  {
    fin_msg += '1'
  }
  else
  {
    fin_msg += '0'
  }
  if digitalRead(final_bit_3) == "HIGH":
  {
    fin_msg += '1'
  }
  else
  {
    fin_msg += '0'
  }
  if digitalRead(final_bit_4) == "HIGH":
  {
    fin_msg += '1'
  }
  else
  {
    fin_msg += '0'
  }
  

}
*/
