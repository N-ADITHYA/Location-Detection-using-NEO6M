# 🛰️ Real-Time GPS Tracking System

A real-time GPS tracking system built with an **ESP8266**, **NEO-6M GPS Module**, **FastAPI**, and **Leaflet.js**. This project allows you to visualize live location updates on a dynamic web map.

---

##  Features

-   **Live Tracking**: Stream live latitude and longitude data.
-   **Interactive Map**: Displays real-time location on a Leaflet.js map.
-   **Efficient Backend**: Uses **FastAPI** for fast and modern data handling.
-   **Simple Hardware**: Easy to set up with an **ESP8266** and **NEO-6M**.

---

##  Tech Stack

| Component | Purpose |
| :--- | :--- |
| **ESP8266** (NodeMCU) | Microcontroller for reading and sending GPS data. |
| **NEO-6M GPS Module** | Fetches location coordinates from satellites. |
| **FastAPI** | High-performance Python backend server. |
| **Leaflet.js** | Open-source JavaScript library for interactive maps. |
| **TinyGPS++** | Arduino library for parsing GPS data. |
| **ArduinoJson** | Library for creating JSON payloads. |

---

##  Hardware Connections

Connect the **NEO-6M GPS Module** to the **ESP8266** as shown in the table below:

| NEO-6M Pin | ESP8266 Pin (NodeMCU) |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| TX | D4 (GPIO2) |
| RX | D3 (GPIO0) |

---

## ⚙️ Setup Instructions

### 1. ESP8266 Firmware

1.  **Install Libraries**: In the Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries...` and install:
    -   `TinyGPS++` by Mikal Hart
    -   `ArduinoJson` by Benoit Blanchon
2.  **Update Credentials**: Open the ESP8266 code file (`.ino`).
    -   Set your WiFi SSID and password:
        ```cpp
        const char* ssid = "YOUR_WIFI_NAME";
        const char* password = "YOUR_WIFI_PASSWORD";
        ```
    -   Find your computer's **IPv4 address** by running `ipconfig` (Windows) or `ifconfig` (macOS/Linux) and update the `serverUrl`:
        ```cpp
        const char* serverUrl = "[http://xxx.xxx.x.xx:8000/gps](http://xxx.xxx.x.xx/gps)"; // replace xxx.xxx.x.xx with the ipv4 you have on your machine
        ```
3.  **Upload Code**:
    -   Connect your ESP8266.
    -   In Arduino IDE, select `Board: NodeMCU 1.0 (ESP-12E Module)` and your correct COM port.
    -   Click **Upload**.

### 2.  FastAPI Backend

1.  **Clone the Repository**:
    ```bash
    git clone https://github.com/N-ADITHYA/Location-Detection-using-NEO6M.git
    cd dev-app
    ```
2.  **Install Dependencies**: Make sure you have Python 3.9+ installed.
    ```bash
    pip install -r requirements.txt
    ```
3.  **Run the Server**:
    ```bash
    uvicorn main:app --reload
    ```
    Your backend will now be running and ready to receive data from the ESP8266.

---

##  Viewing the Dashboard

Open the `index.html` file in your web browser. The map will automatically update with the live GPS coordinates being sent from your ESP8266.

---

##  Contribution

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/N-ADITHYA/Location-Detection-using-NEO6M/issues).

---

## 📜 License

This project is licensed under the [MIT License](https://github.com/N-ADITHYA/Location-Detection-using-NEO6M/blob/main/LICENSE).

---

##  Author

-   **Adithya N**
-   **Portfolio**: [iadiee.live](https://www.iadiee.live/)
-   **GitHub**: [@N-ADITHYA](https://github.com/N-ADITHYA)

---

⭐ **Show your support by giving this project a star on GitHub!**
