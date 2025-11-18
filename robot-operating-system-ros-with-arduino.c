// Simulate ROS pub/sub via serial bridge with topic frames
#include <stdio.h> // Logs

static void ros_publish(const char* topic, const char* payload) { // Publish
  printf("PUB %s %s\n", topic, payload); // Log publish
}

static void ros_receive(const char* topic) { // Subscribe handler
  printf("SUB %s -> CMD=FORWARD\n", topic); // Log command
}

int main(void) { // Entry
  printf("Robot Operating System (ROS) with Arduino\n"); // Title
  ros_publish("/arduino/sensor", "{\"temp\":26}"); // Publish sensor
  ros_receive("/arduino/motor_cmd"); // Receive command
  ros_publish("/arduino/status", "{\"ok\":true}"); // Publish status
  return 0; // Exit
} // End main
