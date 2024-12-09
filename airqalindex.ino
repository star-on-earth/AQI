// void setup() {
//   // put your setup code here, to run once:
// Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// int sensorValue = analogRead(A0);
// Serial.println(sensorValue);
// delay(20);
// }




// void setup()
// {
//    Serial.begin(9600);
// }
 
// void loop()
// {
//     float sensor_volt;
//     float RS; //  Get the value of RS via in a clear air
//     float R0;  // Get the value of R0 via in Alcohol
//     float sensorValue;
 
//     for(int i = 0 ; i < 100 ; i++)
//     {
//         sensorValue = sensorValue + analogRead(A0);
//     }
 
//     sensorValue = sensorValue/100.0;     //get average of reading
//     sensor_volt = sensorValue/1024*5.0;
//     RS = (5.0-sensor_volt)/sensor_volt; // 
//     R0 = RS/60.0; // 60 is found using interpolation
//     Serial.print("R0 = ");
//     Serial.println(R0);
//     delay(1000);
 
// }






















// //mq8
// // #define         RL_VALUE                     (10)    //define the load resistance on the board, in kilo ohms
// // #define         RO_CLEAN_AIR_FACTOR          (9.21)  //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
// //                                                      //which is derived from the chart in datasheet

// #define         MQ_PIN                       (0)     //define which analog input channel you are going to use
// #define         RL_VALUE                     (5)     //define the load resistance on the board, in kilo ohms
// #define         RO_CLEAN_AIR_FACTOR          (9.83)  //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
//                                                      //which is derived from the chart in datasheet
 
// /*Software Related Macros*/
// #define         CALIBARAION_SAMPLE_TIMES     (50)    //define how many samples you are going to take in the calibration phase
// #define         CALIBRATION_SAMPLE_INTERVAL  (500)   //define the time interal(in milisecond) between each samples in the
//                                                      //cablibration phase
// #define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
// #define         READ_SAMPLE_TIMES            (5)     //define the time interal(in milisecond) between each samples in 
//                                                      //normal operation
 
// /*Application Related Macros*/
// #define         GAS_LPG                      (0)
// #define         GAS_CO                       (1)
// #define         GAS_SMOKE                    (2)
// #define         GAS_H2                       (3)


// float           LPGCurve[3]  =  {2.3,0.21,-0.47};   //two points are taken from the curve. 
//                                                     //with these two points, a line is formed which is "approximately equivalent"
//                                                     //to the original curve. 
//                                                     //data format:{ x, y, slope}; point1: (lg200, 0.21), point2: (lg10000, -0.59) 
// float           COCurve[3]  =  {2.3,0.72,-0.34};    //two points are taken from the curve. 
//                                                     //with these two points, a line is formed which is "approximately equivalent" 
//                                                     //to the original curve.
//                                                     //data format:{ x, y, slope}; point1: (lg200, 0.72), point2: (lg10000,  0.15) 
// float           SmokeCurve[3] ={2.3,0.53,-0.44};    //two points are taken from the curve. 
//                                                     //with these two points, a line is formed which is "approximately equivalent" 
//                                                     //to the original curve.
//                                                     //data format:{ x, y, slope}; point1: (lg200, 0.53), point2: (lg10000,  -0.22)                                                     
// float           H2Curve[3]  =  {2.3, 0.93,-1.44};    //two points are taken from the curve in datasheet. 
//                                                      //with these two points, a line is formed which is "approximately equivalent" 
//                                                      //to the original curve. 
//                                                      //data format:{ x, y, slope}; point1: (lg200, lg8.5), point2: (lg10000, lg0.03) 
// float           Ro          =  10;                  //Ro is initialized to 10 kilo ohms

// void setup()
// {
//   Serial.begin(9600);                               //UART setup, baudrate = 9600bps
//   Serial.print("Calibrating...\n");                
//   Ro = MQCalibration(MQ_PIN);                       //Calibrating the sensor. Please make sure the sensor is in clean air 
//                                                     //when you perform the calibration                    
//   Serial.print("Calibration is done...\n"); 
//   Serial.print("Ro=");
//   Serial.print(Ro);
//   Serial.print("kohm");
//   Serial.print("\n");
// }
 
// void loop()
// {
//    Serial.print("H2:"); 
//    Serial.print(MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_H2) );         //H2 in ppm
//    Serial.print( "ppm" );
//    Serial.print("    ");
//    Serial.print("LPG:"); 
//    Serial.print(MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_LPG) );
//    Serial.print( "ppm" );
//    Serial.print("    ");   
//    Serial.print("CO:"); 
//    Serial.print(MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_CO) );
//    Serial.print( "ppm" );
//    Serial.print("    ");   
//    Serial.print("SMOKE:"); 
//    Serial.print(MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_SMOKE) );
//    Serial.print( "ppm" );
//    Serial.print("\n");
//    delay(200);
// }
// float MQResistanceCalculation(int raw_adc)
// {
//   return ( ((float)RL_VALUE*(1023-raw_adc)/raw_adc));
// }
// float MQCalibration(int mq_pin)
// {
//   int i;
//   float val=0;
 
//   for (i=0;i<CALIBARAION_SAMPLE_TIMES;i++) {            //take multiple samples
//     val += MQResistanceCalculation(analogRead(mq_pin));
//     delay(CALIBRATION_SAMPLE_INTERVAL);
//   }
//   val = val/CALIBARAION_SAMPLE_TIMES;                   //calculate the average value
 
//   val = val/RO_CLEAN_AIR_FACTOR;                        //divided by RO_CLEAN_AIR_FACTOR yields the Ro 
//                                                         //according to the chart in the datasheet 
 
//   return val; 
// }
// float MQRead(int mq_pin)
// {
//   int i;
//   float rs=0;
 
//   for (i=0;i<READ_SAMPLE_TIMES;i++) {
//     rs += MQResistanceCalculation(analogRead(mq_pin));
//     delay(READ_SAMPLE_INTERVAL);
//   }
 
//   rs = rs/READ_SAMPLE_TIMES;
 
//   return rs;  
// }
// int MQGetGasPercentage(float rs_ro_ratio, int gas_id)
// {
//   if ( gas_id == GAS_LPG ) {
//      return MQGetPercentage(rs_ro_ratio,LPGCurve);
//   } else if ( gas_id == GAS_CO ) {
//      return MQGetPercentage(rs_ro_ratio,COCurve);
//   } else if ( gas_id == GAS_SMOKE ) {
//      return MQGetPercentage(rs_ro_ratio,SmokeCurve);
//   } else if ( gas_id == GAS_H2) {
//      return MQGetPercentage(rs_ro_ratio,H2Curve);
//   }   
 
//   return 0;
// }
// int  MQGetPercentage(float rs_ro_ratio, float *pcurve)
// {
//   return (pow(10,( ((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
// }








//including thingspeak arduino ethernet
/*To integrate your gas sensor code with the ThingSpeak code so that the measured gas concentrations in ppm and percentages are uploaded to ThingSpeak, you'll need to modify the `loop()` function to include the necessary ThingSpeak updates. Here’s how you can combine the two pieces of code:

### Complete Integrated Code

```cpp*/
/*#include <Ethernet.h>
#include <ThingSpeak.h>

// MQ Sensor Configuration
#define MQ_PIN                       (0)
#define RL_VALUE                     (5)
#define RO_CLEAN_AIR_FACTOR          (9.83)
// //mq8
// // #define         RL_VALUE                     (10)    //define the load resistance on the board, in kilo ohms
// // #define         RO_CLEAN_AIR_FACTOR          (9.21)  //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
#define CALIBARAION_SAMPLE_TIMES     (50)
#define CALIBRATION_SAMPLE_INTERVAL  (500)
#define READ_SAMPLE_INTERVAL         (50)
#define READ_SAMPLE_TIMES            (5)

#define GAS_LPG                      (0)
#define GAS_CO                       (1)
#define GAS_SMOKE                    (2)
#define GAS_H2                       (3)

float LPGCurve[3]  =  {2.3, 0.21, -0.47};
float COCurve[3]  =  {2.3, 0.72, -0.34};
float SmokeCurve[3] = {2.3, 0.53, -0.44};
float H2Curve[3]  =  {2.3, 0.93, -1.44};
float Ro          =  10;

// ThingSpeak Configuration
#define SECRET_MAC {0x90, 0xA2, 0xDA, 0x10, 0x40, 0x4F}
#define SECRET_CH_ID 12345               // Replace with your channel ID
#define SECRET_WRITE_APIKEY "YOUR_WRITE_API_KEY" // Replace with your Write API Key

byte mac[] = SECRET_MAC;
EthernetClient client;

void setup() {
  Serial.begin(9600);
  // Initialize Ethernet with DHCP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, IPAddress(192, 168, 0, 177)); // Use static IP if DHCP fails
  }
  delay(1000);
  ThingSpeak.begin(client); // Initialize ThingSpeak

  Serial.print("Calibrating...\n");
  Ro = MQCalibration(MQ_PIN);
  Serial.print("Calibration is done...\n");
  Serial.print("Ro="); Serial.print(Ro); Serial.println("kohm");
}

void loop() {
  // Read gas concentrations
  float h2PPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_H2);
  float lpgPPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_LPG);
  float coPPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_CO);
  float smokePPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_SMOKE);

  // Print to Serial Monitor
  Serial.print("H2: "); Serial.print(h2PPM); Serial.print(" ppm");
  Serial.print("    LPG: "); Serial.print(lpgPPM); Serial.print(" ppm");
  Serial.print("    CO: "); Serial.print(coPPM); Serial.print(" ppm");
  Serial.print("    SMOKE: "); Serial.print(smokePPM); Serial.println(" ppm");

  // Update ThingSpeak
  ThingSpeak.setField(1, h2PPM);     // Field 1 for H2 ppm
  ThingSpeak.setField(2, lpgPPM);    // Field 2 for LPG ppm
  ThingSpeak.setField(3, coPPM);     // Field 3 for CO ppm
  ThingSpeak.setField(4, smokePPM);  // Field 4 for Smoke ppm

  // Write to ThingSpeak
  int result = ThingSpeak.writeFields(SECRET_CH_ID, SECRET_WRITE_APIKEY);
  if (result == 200) {
    Serial.println("Data updated successfully.");
  } else {
    Serial.println("Problem updating data. HTTP error code: " + String(result));
  }

  delay(20000); // Update every 20 seconds
}

float MQResistanceCalculation(int raw_adc) {
  return (((float)RL_VALUE * (1023 - raw_adc) / raw_adc));
}

float MQCalibration(int mq_pin) {
  int i;
  float val = 0;

  for (i = 0; i < CALIBARAION_SAMPLE_TIMES; i++) {
    val += MQResistanceCalculation(analogRead(mq_pin));
    delay(CALIBRATION_SAMPLE_INTERVAL);
  }
  val = val / CALIBARAION_SAMPLE_TIMES;
  val = val / RO_CLEAN_AIR_FACTOR;
  return val;
}

float MQRead(int mq_pin) {
  int i;
  float rs = 0;

  for (i = 0; i < READ_SAMPLE_TIMES; i++) {
    rs += MQResistanceCalculation(analogRead(mq_pin));
    delay(READ_SAMPLE_INTERVAL);
  }
  rs = rs / READ_SAMPLE_TIMES;
  return rs;
}

int MQGetGasPercentage(float rs_ro_ratio, int gas_id) {
  if (gas_id == GAS_LPG) {
    return MQGetPercentage(rs_ro_ratio, LPGCurve);
  } else if (gas_id == GAS_CO) {
    return MQGetPercentage(rs_ro_ratio, COCurve);
  } else if (gas_id == GAS_SMOKE) {
    return MQGetPercentage(rs_ro_ratio, SmokeCurve);
  } else if (gas_id == GAS_H2) {
    return MQGetPercentage(rs_ro_ratio, H2Curve);
  }
  return 0;
}

int MQGetPercentage(float rs_ro_ratio, float *pcurve) {
  return (pow(10, ((log(rs_ro_ratio) - pcurve[1]) / pcurve[2]) + pcurve[0]));
}
### Key Changes
1. **ThingSpeak Integration**: Added code to upload gas concentrations to ThingSpeak after reading the sensor values.
2. **Field Assignments**: Defined how each gas concentration is assigned to specific fields in ThingSpeak.
3. **Data Update Interval**: Set the update interval to 20 seconds (adjust as needed).

### Important Notes
- Replace `SECRET_CH_ID` and `SECRET_WRITE_APIKEY` with your actual ThingSpeak channel ID and write API key.
- Make sure to connect your Ethernet module correctly and that the library versions you use are compatible with your hardware.*/

#include <Ethernet.h>
#include <ThingSpeak.h>

// MQ Sensor Configuration
#define MQ_PIN                       (0)          // Pin connected to the MQ sensor (analog input pin)
#define RL_VALUE                     (5)          // Load resistance in kilo ohms
#define RO_CLEAN_AIR_FACTOR          (9.83)       // Calibration factor for clean air
#define CALIBARAION_SAMPLE_TIMES     (50)         // Number of calibration samples
#define CALIBRATION_SAMPLE_INTERVAL  (500)        // Time interval between calibration samples (ms)
#define READ_SAMPLE_INTERVAL         (50)         // Time interval between read samples (ms)
#define READ_SAMPLE_TIMES            (5)          // Number of samples to average for reading

#define GAS_LPG                      (0)          // Gas ID for LPG
#define GAS_CO                       (1)          // Gas ID for CO
#define GAS_SMOKE                    (2)          // Gas ID for Smoke
#define GAS_H2                       (3)          // Gas ID for H2
#define GAS_PROPANE                  (4)          // Gas ID for Propane

float LPGCurve[3]  =  {2.3, 0.21, -0.47};
float COCurve[3]  =  {2.3, 0.72, -0.34};
float SmokeCurve[3] = {2.3, 0.53, -0.44};
float H2Curve[3]  =  {2.3, 0.93, -1.44};
float PropaneCurve[3] = {2.3, 0.72, -0.34};  // Propane curve
float Ro          =  10;                     // Sensor resistance in clean air (calibration value)

// ThingSpeak Configuration
#define SECRET_MAC {0x90, 0xA2, 0xDA, 0x10, 0x40, 0x4F}
#define SECRET_CH_ID 2731380                   // Replace with your ThingSpeak channel ID
#define SECRET_WRITE_APIKEY "PC3EQCVXOSHE2OI0" // Replace with your ThingSpeak Write API Key

byte mac[] = SECRET_MAC;
EthernetClient client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

// Initialize gas sensor values
float h2PPM, lpgPPM, coPPM, smokePPM, propanePPM;

void setup() {
  Serial.begin(9600);
  // Initialize Ethernet with DHCP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, IPAddress(192, 168, 0, 177)); // Use static IP if DHCP fails
  }
  delay(1000);
  ThingSpeak.begin(client); // Initialize ThingSpeak

  Serial.print("Calibrating...\n");
  Ro = MQCalibration(MQ_PIN);
  Serial.print("Calibration is done...\n");
  Serial.print("Ro="); Serial.print(Ro); Serial.println("kohm");
}

void loop() {
  // Read gas concentrations
  h2PPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_H2);
  lpgPPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_LPG);
  coPPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_CO);
  smokePPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_SMOKE);
  propanePPM = MQGetGasPercentage(MQRead(MQ_PIN) / Ro, GAS_PROPANE); // Read Propane

  // Print to Serial Monitor
  Serial.print("H2: "); Serial.print(h2PPM); Serial.print(" ppm");
  Serial.print("LPG: "); Serial.print(lpgPPM); Serial.print(" ppm");
  Serial.print("CO: "); Serial.print(coPPM); Serial.print(" ppm");
  Serial.print("SMOKE: "); Serial.print(smokePPM); Serial.print(" ppm");
  Serial.print("PROPANE: "); Serial.print(propanePPM); Serial.println(" ppm");

  // Update ThingSpeak with gas concentrations
  ThingSpeak.setField(1, h2PPM);     // Field 1 for H2 ppm
  ThingSpeak.setField(2, lpgPPM);    // Field 2 for LPG ppm
  ThingSpeak.setField(3, smokePPM);  // Field 3 for CO ppm
  ThingSpeak.setField(4, coPPM);     // Field 4 for Smoke ppm
  ThingSpeak.setField(7, propanePPM); // Field 5 for Propane ppm

  // Write to ThingSpeak
  int result = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (result == 200) {
    Serial.println("Data updated successfully.");
  } else {
    Serial.println("Problem updating data. HTTP error code: " + String(result));
  }

  delay(20000); // Update every 20 seconds
}

// Function to calculate the resistance of the gas sensor
float MQResistanceCalculation(int raw_adc) {
  return (((float)RL_VALUE * (1023 - raw_adc) / raw_adc));
}

// Function to calibrate the sensor (measure Ro value)
float MQCalibration(int mq_pin) {
  int i;
  float val = 0;

  for (i = 0; i < CALIBARAION_SAMPLE_TIMES; i++) {
    val += MQResistanceCalculation(analogRead(mq_pin));
    delay(CALIBRATION_SAMPLE_INTERVAL);
  }
  val = val / CALIBARAION_SAMPLE_TIMES;
  val = val / RO_CLEAN_AIR_FACTOR;
  return val;
}

// Function to read sensor values (average multiple readings)
float MQRead(int mq_pin) {
  int i;
  float rs = 0;

  for (i = 0; i < READ_SAMPLE_TIMES; i++) {
    rs += MQResistanceCalculation(analogRead(mq_pin));
    delay(READ_SAMPLE_INTERVAL);
  }
  rs = rs / READ_SAMPLE_TIMES;
  return rs;
}

// Function to calculate the gas percentage (ppm) from sensor reading
int MQGetGasPercentage(float rs_ro_ratio, int gas_id) {
  if (gas_id == GAS_LPG) {
    return MQGetPercentage(rs_ro_ratio, LPGCurve);
  } else if (gas_id == GAS_CO) {
    return MQGetPercentage(rs_ro_ratio, COCurve);
  } else if (gas_id == GAS_SMOKE) {
    return MQGetPercentage(rs_ro_ratio, SmokeCurve);
  } else if (gas_id == GAS_H2) {
    return MQGetPercentage(rs_ro_ratio, H2Curve);
  } else if (gas_id == GAS_PROPANE) {  // Check for Propane
    return MQGetPercentage(rs_ro_ratio, PropaneCurve);
  }
  return 0;
}

// Function to calculate the percentage of gas
int MQGetPercentage(float rs_ro_ratio, float *pcurve) {
  return (pow(10, ((log(rs_ro_ratio) - pcurve[1]) / pcurve[2]) + pcurve[0]));
}