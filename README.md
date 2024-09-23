# Smart Blind Stick: IoT and AI-Powered Assistive Device

## Problem Statement
Visually impaired individuals struggle with safe, independent navigation. Traditional white canes have limitations in obstacle detection, object recognition, and real-time navigation assistance.

## Existing Work
- **IoT-Based Smart Stick for the Blind (Varsha Vimal Soo)**
- **B09010914-libre.pdf Project**
- **IoT-Based Smart Blind Stick (SpringerLink)**

### Common Features
- Obstacle detection
- Water sensing
- GPS tracking
- GSM communication

## Unique Ideas in Our Project
- **Rotating ultrasonic sensor with servo motor**
  - Wider detection range and precise obstacle localization
  - More efficient than multiple fixed sensors
- **Object detection using ESP32-CAM and AI**
  - Enhanced environmental awareness through visual recognition
- **Advanced navigation with Gemini API**
  - AI-powered route planning and guidance
- **Bluetooth headphone integration**
  - Private and clear audio feedback
- **Dual-board architecture (Raspberry Pi 5 + ESP32)**
  - Efficient task distribution and power management
- **Edge computing capabilities**
  - On-device AI processing, reduced reliance on the internet

## Main Objectives
- Comprehensive environmental awareness and navigation assistance
- Advanced obstacle detection with rotating sensor
- Visual object recognition using AI
- Clear, private audio feedback
- Real-time, AI-powered navigation
- Energy-efficient operation

## Algorithm Overview
1. Scan environment (rotate sensor, capture images)
2. Detect objects and obstacles
3. Process location and plan routes
4. Provide audio feedback to user
5. Manage data between ESP32 and Raspberry Pi 5

## Component Uses
1. **Raspberry Pi 5**: AI processing, system control, navigation
2. **ESP32**: Sensor management, image capture, Bluetooth communication
3. **Ultrasonic Sensor + Servo**: Wide-range obstacle detection
4. **ESP32-CAM**: Image capture for object detection
5. **Water Sensor**: Detect wet surfaces
6. **GPS Module**: Location tracking
7. **Bluetooth Module**: Wireless audio output
8. **Trigger Button**: Emergency alerts

## Research Gap
Our project addresses limitations in existing solutions by integrating:
- Comprehensive obstacle detection
- AI-powered object recognition and navigation
- Efficient power management
- Private audio feedback
- Edge computing for real-time processing

## References
- **IoT-Based Smart Stick for the Blind (Varsha Vimal Soo)**
- **B09010914-libre.pdf Project**
- **IoT-Based Smart Blind Stick (SpringerLink)**
