//LT33001 ic

//UCPOL=0,UCPHA=1 SPI_MODE1

/*
 * this code is for only one LT33001 in stack
 * 
 * Table 2. Command Byte Bit Mapping
(Defaults to 0x00 in Reset State)
1(MSB) 0 1 0 1 CMDA CMDB Parity Bit
(LSB)
Table 3. Command Bits
CMDA CMDB Communication Action
0 0 Write Balance Command (without Executing)  --> 0
0 1 Readback Balance Command                   --> 1
1 0 Read Balance Status                        --> 2
1 1 Execute Balance Command                    --> 3
The 8th bit in the command byte must be set such that the entire 8-bit command byte has even parity.

Table 4. Write Balance Command Data Bit Mapping (Defaults to 0x000F in Reset State)
D1A (MSB) D1B D2A D2B D3A D3B D4A D4B D5A D5B D6A D6B CRC[3] CRC[2] CRC[1] CRC[0](LSB)

Table 5. Cell Balancer Control Bits
DnA DnB Balancing Action (n = 1 to 6)
0 0 None
0 1 Discharge Cell n (Nonsynchronous)
1 0 Discharge Cell n (Synchronous)
1 1 Charge Cell n

Note:
the first 16 bits will be the write data for the topmost LTC3300-1 in the stack and will have shifted through all other LTC3300-1 ICs in the stack. 
The last 16 bits will be the write data for the bottom-most LTC3300-1 in the stack.

Note that the CRC bits in the Write Balance Command are inverted.
 */
 #include<SPI.h>

int chipselect =10;
uint16_t control_byte;
uint16_t CRC;
char r1=0;
char r2=0;
void setup() {
  // put your setup code here, to run once:
  //init spi
   Serial.begin(9600);
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE1));

  pinMode(chipselect, OUTPUT); 
  control_byte=0x0020;
  commandwrite(0,control_byte);
}

void loop() {
  
  
  commandwrite(2,control_byte);
  
  delay(100);
  
  
  
  
  // put your main code here, to run repeatedly:
  //here balancing algorithm

  //sense cells voltages and balance voltage accorrding 
  
}


  void commandwrite(int commandBit, uint16_t control_byte ){
  //calculate CRC
  CRCcalculate( control_byte);
  
  // assert chip */+selct signal
  uint8_t data =0x00;
  digitalWrite(chipselect, LOW);

  //send command byte
  data = 0xA8 + (commandBit<<1);
  if (commandBit == 3 || commandBit ==0)
  data= data+1; // even parity
  SPI.transfer(data);
 
  if(commandBit==2)
  {r1= SPI.transfer(data);
  
 r2=SPI.transfer(data);

  // de-assert chip select
  digitalWrite(chipselect, HIGH);
Serial.println(r1);
Serial.println(r2);

  }
  else
  { //send databyte1
  data = (control_byte>>8);
  SPI.transfer(data);

  //send databyte0  add crc bit here
  
  data = control_byte;
  data+= CRC;
  SPI.transfer(data);
  
  // de-assert chip select
  digitalWrite(chipselect, HIGH);}
  
  
}
 void CRCcalculate(uint16_t n)
 {
  //1x4 + 0x3 + 0x2 + 1x1 + 1x0 polynomial function
  uint16_t r = n;
  uint16_t d =0b10011;
  for(int i=11;i>=0;i--){
        if((r&(1<<(i+4))) >(uint16_t)0)
        {
            // do xor
             r= r^(d<<i);

        }
        else {
            r= r^(0<<i);

        }
        CRC=r^0xff;
    }
  
 }

