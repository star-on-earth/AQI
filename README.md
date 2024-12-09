# AQI
This repository provides tools and scripts to track, analyze, and visualize air quality data. It includes features for fetching real-time data from APIs, calculating AQI, and generating reports or dashboards. Supports multiple data sources and provides customizable thresholds for different regions and pollutants.

🚨 **Air Quality Monitoring System with Arduino and ThingSpeak**

This project uses multiple gas sensors with an Arduino UNO and an Ethernet Shield to measure air quality and upload the data to ThingSpeak for real-time visualization and analysis.

---

## 📋 **Table of Contents**

1. [Description](#description)  
2. [Hardware Components](#hardware-components)  
3. [Software and Libraries](#software-and-libraries)  
4. [Wiring Diagram](#wiring-diagram)  
5. [Installation and Setup](#installation-and-setup)  
6. [Code Explanation](#code-explanation)  
7. [ThingSpeak Dashboard](#thingspeak-dashboard)  
8. [Usage](#usage)  

---

## 📑**Description**

This project reads data from multiple MQ-series gas sensors and a DHT-11 temperature/humidity sensor. The collected data is sent to ThingSpeak for online monitoring and visualization.

**Supported Sensors:**
- **MQ-9:** CO, LPG, Methane  
- **MQ-8:** Hydrogen (H₂)  
- **MQ-5:** LPG, CO, Propane  
- **MQ-135:** Smoke, CO₂  
- **MQ-4:** Methane, CNG  
- **MQ-6:** LPG, Propane  
- **DHT-11:** Temperature and Humidity  

---

## 🛠️ **Hardware Components**

1. **Arduino UNO**  
2. **Ethernet Shield (W5100)**  
3. **Gas Sensors (MQ-9, MQ-8, MQ-5, MQ-135, MQ-4, MQ-6)**  
4. **DHT-11 Temperature/Humidity Sensor**  
5. **Jumper Wires**  
6. **Breadboard**  

---

## 💻 **Software and Libraries**

1. **Arduino IDE**  
2. **ThingSpeak Library**  
3. **Ethernet Library**  

### Required Libraries:

Install these libraries using the Arduino Library Manager (`Sketch -> Include Library -> Manage Libraries`):

- `ThingSpeak`  
- `Ethernet`  

---

## 🔌 **Wiring Diagram**

| **Sensor** | **Arduino Pin**   |
|------------|------------------|
| MQ 5 | Analog Pin `A4`  |
| MQ 135 | Analog Pin `A0`  |
| MQ 4 | Analog Pin `A5`  |
| MQ 6 | Analog Pin `A3`  |
| MQ 8 | Analog Pin `A2`  |
| MQ 9 | Analog Pin `A1`  |
| DHT-11     | Digital Pin `D2` |
| Ethernet Shield | Follows standard SPI pins on the UNO |

---

## 🚀 **Installation and Setup**

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/air-quality-monitor.git
   cd air-quality-monitor
   ```

2. **Configure ThingSpeak:**

   - Sign up at [ThingSpeak](https://thingspeak.com/).  
   - Create a new channel and note the **Channel ID** and **Write API Key**.  
   - Update the following constants in the code with your details:

     ```cpp
     #define SECRET_CH_ID 2731380                   // Your ThingSpeak Channel ID
     #define SECRET_WRITE_APIKEY "YOUR_WRITE_API_KEY"
     ```

3. **Upload Code to Arduino:**

   - Connect the Arduino to your PC.  
   - Open the project in the Arduino IDE.  
   - Select the correct board and port (`Tools -> Board -> Arduino UNO`).  
   - Click **Upload**.

---

## 📝 **Code Explanation**

- **Gas Sensors Configuration:**  
  Reads values from different MQ sensors, calculates gas concentrations in ppm, and sends data to ThingSpeak.

- **Ethernet Configuration:**  
  Uses DHCP or a static IP to connect the Ethernet Shield to the network.

- **ThingSpeak Integration:**  
  Sends sensor readings to ThingSpeak fields for real-time monitoring.

### **ThingSpeak Fields Mapping:**

| **Field** | **Gas Measurement**      |
|-----------|--------------------------|
| Field 1   | Hydrogen (H₂)            |
| Field 2   | LPG                      |
| Field 3   | Smoke                    |
| Field 4   | Carbon Monoxide (CO)     |
| Field 7   | Propane                  |

---

## 📊 **ThingSpeak Dashboard**

Log in to ThingSpeak to visualize real-time graphs and analyze trends based on your sensor data.

---

## ▶️ **Usage**

1. Power the Arduino and ensure the Ethernet Shield is connected to the network.  
2. Open the Serial Monitor (9600 baud) to see real-time sensor readings.  
3. Visit your ThingSpeak channel to view the data visualization.

---

👨‍💻 **Author:** *Avrrodeep Banerjee*  
📧 **Contact:** *2328158@kiit.ac.in*  

