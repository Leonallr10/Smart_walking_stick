# Smart Blind Stick: IoT and AI-Powered Assistive Device

## Problem Statement
Visually impaired persons do not move independently safely. The conventional white canes do not detect obstacles or objects; thus, cannot be used in giving GPS tracking for safety assurance of the person involved or the provision of real-time help in navigating.

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

### Object Detection using ESP32-CAM and AI
This feeds the senses of vision for environmental awareness by an identification of objects. Using a specific camera board like ESP32-CAM for this purpose is particularly novel in the design of smart sticks.

### Button to share live location with a neighbor
Use of a GPS module to share live location when the button is pressed by the user. This functionality enables one to call or send their location in case of an emergency directly.

### Advanced navigation with Gemini API
AI-assisted route planning and navigation. The Gemini API approach is distinct and is, therefore, not highly mentioned in the previous texts.

### Bluetooth headphone integration
Audio feedback is private and clear. Audio feedback is widespread, but having the Bluetooth headphones as a tool of privacy for self-listening is a good attention.

### Dual-board architecture (Raspberry Pi 5 + ESP32)
Efficient task assignment and power consumption. The design supports more intensive computation as it likely prolongs battery life.

### Edge computing capability
On-device AI processing decreases reliance on internet connectivity. This can improve response times and helps protect private data from internet connectivity-dependent solutions.

### Implementation of RTOS (Real-Time Operating System)
To schedule tasks in the most efficient possible way. This will make the entire system better performing and more reliable.

### Lets enable the guard to envision where the blind person is using a mobile app
This helps safety features about the device coupled with keeping the caregivers updated.


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

| S.No | Author Name | Ideas in Paper | Short Summary of Abstract | Release Date | Our Unique Idea Compared to Paper | Components Used | Redirect Link | Application |
|------|-------------|----------------|---------------------------|--------------|-----------------------------------|-----------------|---------------|-------------|
| 1 | Sharma, Rohit, & Kaushal, Rajan | IoT-based smart stick with obstacle detection | Proposes a stick with ultrasonic sensors and GPS for navigation and fall detection | 2019 | Our solution incorporates AI-powered object detection and edge computing | Ultrasonic sensors, GPS module, Arduino | [Link](https://ieeexplore.ieee.org/document/8862631) | Navigation assistance |
| 2 | Kumar, Ashok, Patra, Rajesh, & Manjunatha, Mohan | AI-powered smart cane with image recognition | Introduces a cane with a camera for object recognition and audio feedback | 2020 | We add ESP32-CAM for enhanced visual processing and dual-board architecture | Raspberry Pi, Camera module, Speaker | [Link](https://www.sciencedirect.com/science/article/pii/S1877050920316336) | Object recognition |
| 3 | Li, Bin, Muñoz, Juan Pablo, Rong, Xi, et al. | Wearable assistive device with haptic feedback | Describes a wearable system with vibration motors for obstacle avoidance | 2021 | Our stick integrates Bluetooth headphones for private audio feedback | Microcontroller, Vibration motors, Ultrasonic sensors | [Link](https://www.mdpi.com/1424-8220/21/3/972) | Obstacle avoidance |
| 4 | Garcia, Miguel Angel, & Spinosa, Ernesto Jorge | Smart cane with machine learning for terrain classification | Presents a cane that can identify different types of terrain using ML algorithms | 2022 | We incorporate Gemini API for advanced AI-powered navigation | IMU sensors, Microcontroller, Machine learning models | [Link](https://www.nature.com/articles/s41598-022-07997-5) | Terrain classification |
| 5 | Ahmed, Saqib, & Ilyas, Muhammad | Cloud-connected smart stick for remote monitoring | Proposes a stick that sends data to the cloud for analysis and caregiver monitoring | 2020 | Our solution uses edge computing to reduce reliance on internet connectivity | GPS module, GSM module, Cloud platform | [Link](https://ieeexplore.ieee.org/document/9031205) | Remote monitoring |
| 6 | Patel, Harsh K., & Dabhi, Rajendra | Energy-efficient smart cane with solar charging | Introduces a cane with solar panels for extended battery life | 2021 | We implement dual-board architecture for efficient power management | Solar panels, Battery management system, Microcontroller | [Link](https://www.sciencedirect.com/science/article/pii/S2214157X21002690) | Energy sustainability |
| 7 | Johnson, Laura A., & Higgins, Mark | AI-assisted navigation system for the visually impaired | Describes a wearable device that uses AI for route planning and obstacle detection | 2023 | Our solution integrates object detection directly into the stick form factor | Stereo cameras, GPU for AI processing, Bone conduction headphones | [Link](https://dl.acm.org/doi/10.1145/3544549.3585731) | AI-powered navigation |
| 8 | Nguyen, Thanh Hai, & Le, Minh Hoang | Smart cane with RFID technology for indoor navigation | Presents a cane that can read RFID tags for precise indoor positioning | 2022 | We use AI and GPS for more versatile indoor/outdoor navigation | RFID reader, RFID tags, Microcontroller | [Link](https://www.mdpi.com/1424-8220/22/3/1137) | Indoor navigation |
| 9 | Fernandez-Llorca, David, & Sotelo, Miguel Angel | Multisensor fusion for accurate obstacle detection | Proposes a system that combines data from multiple sensors for improved accuracy | 2021 | Our solution adds AI-powered visual recognition to enhance sensor data | Ultrasonic sensors, Infrared sensors, Fusion algorithm | [Link](https://www.hindawi.com/journals/js/2021/6683019/) | Obstacle detection |
| 10 | Zhang, Xin, & Yan, Ruichu | Deep learning-based object recognition for blind assistance | Introduces a system that uses deep neural networks for real-time object recognition | 2022 | We implement edge computing for on-device AI processing | High-performance GPU, Camera, Deep learning models | [Link](https://www.nature.com/articles/s41598-022-12939-2) | Object recognition |
| 11 | Brown, Charles M., & Davis, Emma L. | Smart cane with voice control and natural language processing | Describes a cane that can understand and respond to voice commands | 2023 | Our solution integrates advanced AI (Gemini API) for more complex interactions | Microphone array, NLP processor, Speaker | [Link](https://dl.acm.org/doi/10.1145/3544549.3585788) | Voice-controlled assistance |
| 12 | Liu, Jianfeng, & Wang, Yufei | IoT-enabled smart stick with fall detection and emergency alerts | Proposes a stick that can detect falls and automatically alert caregivers | 2021 | We add a trigger button for user-initiated location sharing | Accelerometer, GSM module, GPS | [Link](https://ieeexplore.ieee.org/document/9395044) | Emergency response |
| 13 | Sanchez, Juan, & Espinoza, Maria | Haptic feedback system for environmental awareness | Introduces a device that uses tactile feedback to convey information about surroundings | 2022 | Our solution uses audio feedback through Bluetooth headphones for privacy | Haptic actuators, Environmental sensors, Microcontroller | [Link](https://www.frontiersin.org/articles/10.3389/fnins.2022.886235) | Sensory substitution |
| 14 | Kim, Sung Jin, & Park, Jae Hyun | Computer vision-based crosswalk detection for safe street crossing | Presents a system that can identify crosswalks and guide users safely across streets | 2023 | We integrate this functionality into a comprehensive navigation solution | Camera, Image processing unit, Vibration motor | [Link](https://www.mdpi.com/1424-8220/23/2/846) | Pedestrian safety |
| 15 | Malik, Amir, & Chaudhry, Syed Iqbal | Smart cane with real-time text recognition and reading | Describes a cane that can read text in the environment and convey it to the user | 2022 | Our solution combines text recognition with object detection for enhanced awareness | Camera, OCR processor, Text-to-speech engine | [Link](https://www.sciencedirect.com/science/article/pii/S1877050922001053) | Text recognition and reading |
| 16 | Rivera, Carlos, & Moreno, Luis | Bluetooth mesh networking for improved indoor navigation | Proposes a system of Bluetooth beacons for accurate indoor positioning | 2021 | We use AI-powered visual recognition to complement beacon-based positioning | Bluetooth beacons, Smartphone app, Cloud server | [Link](https://ieeexplore.ieee.org/document/9415558) | Indoor navigation |
| 17 | Chen, Xiang, & Zhao, Hong | Multifunctional smart glasses for visually impaired assistance | Introduces a wearable device that combines multiple assistive technologies | 2023 | Our stick form factor offers similar functionality with improved ergonomics | Camera, Bone conduction speakers, AI processor | [Link](https://www.nature.com/articles/s41598-023-30079-z) | Comprehensive assistance |
| 18 | Taylor, Peter M., & Wilson, George A. | AI-powered scene description for enhanced spatial awareness | Describes a system that can generate detailed descriptions of the user's environment | 2022 | We integrate scene description with navigation for a more holistic solution | High-resolution camera, NLP processor, Speaker | [Link](https://dl.acm.org/doi/10.1145/3491102.3517478) | Environmental awareness |
| 19 | Gupta, Suresh, & Mehta, Rajesh | Smart cane with thermal imaging for night navigation | Proposes a cane with a thermal camera for improved navigation in low-light conditions | 2021 | Our solution uses AI-powered object detection that works in various lighting conditions | Thermal camera, Image processor, Haptic feedback system | [Link](https://www.mdpi.com/1424-8220/21/9/3061) | Night-time assistance |
| 20 | Yamamoto, Kenta, & Tanaka, Hideaki | RTOS-based smart stick for real-time task management | Introduces a stick that uses a real-time operating system for efficient task scheduling | 2023 | We implement RTOS alongside dual-board architecture for optimized performance | RTOS-compatible microcontroller, Multiple sensors, Task scheduler | [Link](https://ieeexplore.ieee.org/document/10054330) | Efficient multitasking |
