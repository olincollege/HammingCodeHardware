/*
HAMMING-CODE-ENCODER

Instructions:
Recommended use in Arduino IDE.
Open serial monitor and make sure that Arduino is connected to a serial port on your computer. 
Set baud rate in serial monitor to 115200, or you can change it below but make sure your serial
monitor baud rate is always equal to BAUD-RATE.
Send valid 4 bit message such as "1111", "0000", "1101", "0100", etc. to the serial monitor. 
High or low value will be sent from pins 1-4 according to the message.
To send a new message just send a new message in the serial monitor.
*/

const int og_bit_1 = 1; // Pin for bit 1 of the original message
const int og_bit_2 = 2; // Pin for bit 2 of the original message
const int og_bit_3 = 3; // Pin for bit 3 ""
const int og_bit_4 = 4; // Pin for bit 4 ""

String _message = ""; // Defining a blank message to start with

const double BAUD_RATE = 115200; // Baud rate for the serial monitor

void setup() {
  // Assign each of the pins an OUTPUT mode
  pinMode(og_bit_1, OUTPUT); 
  pinMode(og_bit_2, OUTPUT);
  pinMode(og_bit_3, OUTPUT);
  pinMode(og_bit_4, OUTPUT);

  // Begin the serial monitor and send a start up message
  // (Edit: message doesn't seem to work right now idk why, not important though)
  Serial.begin(BAUD_RATE); 
  Serial.println("---- Program Started ----");
}

void loop() {
  // Make sure the message sent to the serial monitor is an acutal message to be processed
  bool messageReceived = ReadFromSerial(); 

  // Process the message only if it is a valid message
  if (messageReceived == true) 
  {
    ProcessMessage(_message);
  }

}

bool ReadFromSerial()
{    
    // Local variables   
    static String msgBuffer;        // Stores the received message
    static bool isMessage = true;   // Stores if the message is valid or not
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

        // If message is invalid then tell the user
        if (isMessage == false)
        {
          Serial.println("Invalid Message");
        }

        // Reset local variables
        isMessage = true;
      
        return true;
    }

    // Check that the message sent is only 1s or 0s 
    if ((char)recByte == '1' || (char)recByte == '0')
    {
      if (isMessage == true)
      {
        // If the message is valid then add it to the message to be processed
        msgBuffer += (char)recByte;
      }
    }
    else
    {
      // If the message is not valid then don't add it 
      isMessage = false;
      return false;
    }
    
    return false;
}

// Processes the message, sends result to serial port

void ProcessMessage(String message)
{  
    // Process command only if it is 4 bits long
    if (message.length() == 4)
    {
      // Show user what message they are sending
      Serial.print("Sending message:  ");
      Serial.println(message);

      // Encode the message to local variables
      String bit_1 = message.substring(0, 1);
      String bit_2 = message.substring(1, 2);
      String bit_3 = message.substring(2, 3);
      String bit_4 = message.substring(3, 4);

      // 
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
