/*
 * Course: Robot Operating System Ros With Arduino
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Robot Operating System Ros With Arduino" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/robot-operating-system-ros-with-arduino/
 * Repository: https://github.com/engasm89/robot-operating-system-ros-with-arduino
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

// Simulate ROS pub/sub via serial bridge with topic frames
#include <stdio.h> // Logs

static void ros_publish(const char* topic, const char* payload) { // Publish
  printf("PUB %s %s\n", topic, payload); // Log publish
}

static void ros_receive(const char* topic) { // Subscribe handler
  printf("SUB %s -> CMD=FORWARD\n", topic); // Log command
}

int main(void) { // Program entry point
  printf("Robot Operating System (ROS) with Arduino\n"); // Title
  ros_publish("/arduino/sensor", "{\"temp\":26}"); // Publish sensor
  ros_receive("/arduino/motor_cmd"); // Receive command
  ros_publish("/arduino/status", "{\"ok\":true}"); // Publish status
  return 0; // Exit
} // End of main function
