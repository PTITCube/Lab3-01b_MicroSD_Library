/**
 * VÍ DỤ 3-1b: LƯU TRỮ LOG VÀO THẺ NHỚ VỚI THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_Storage myDisk;

void setup() {
    cdh.begin(115200);
    myDisk.init();
    myDisk.logData("BOOT: PTITCUBE C&DH");
}

void loop() {
    static int counter = 0;
    
    char buf[64];
    snprintf(buf, sizeof(buf), "DATA #%d | Uptime: %lums", counter++, millis());
    cdh.println(buf);
    
    myDisk.logData(buf);
    delay(3000);
}
