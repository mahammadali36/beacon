#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated BLE Beacon structure
struct Beacon {
    char mac_address[18];
    int battery_level;
    int accelerometer_data[3];
};

// Virtual function to send beacon packets
void sendBeaconPacket(struct Beacon *beacon) {
    // Simulate sending beacon packets
    // In a real-world scenario, this function would interact with BLE hardware to send packets
    // For now, let's print the beacon information
    printf("Sent Beacon Packet:\n");
    printf("MAC Address: %s\n", beacon->mac_address);
    printf("Battery Level: %d\n", beacon->battery_level);
    printf("Accelerometer Data: [%d, %d, %d]\n", beacon->accelerometer_data[0],
           beacon->accelerometer_data[1], beacon->accelerometer_data[2]);
}

// Function to check if the beacon is moving based on accelerometer data
int isMoving(struct Beacon *beacon) {
    // For simplicity, let's assume the beacon is considered moving if any accelerometer value is non-zero
    for (int i = 0; i < 3; i++) {
        if (beacon->accelerometer_data[i] != 0) {
            return 1; // Moving
        }
    }
    return 0; // Stationary
}

int main() {
    // Create a sample Beacon
    struct Beacon myBeacon;
    strcpy(myBeacon.mac_address, "00:11:22:33:44:55");
    myBeacon.battery_level = 80;
    myBeacon.accelerometer_data[0] = 0;
    myBeacon.accelerometer_data[1] = 0;
    myBeacon.accelerometer_data[2] = 0;

    // Send beacon packet
    sendBeaconPacket(&myBeacon);

    // Check if the beacon is moving and print the status
    if (isMoving(&myBeacon)) {
        printf("Beacon is moving.\n");
    } else {
        printf("Beacon is stationary.\n");
    }

    return 0;
}
