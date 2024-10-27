/*陀螺儀*/
unsigned char Re_buf[11], counter = 0;
unsigned char sign = 0;
float roll, pitch, yaw;

void setup() {
  Serial2.begin(115200);
}

void Event() {
  while (Serial2.available()) {
    Re_buf[counter] = (unsigned char)Serial2.read();
    if (counter == 0 && Re_buf[0] != 0x55) return;  //第0号数据不是帧头
    counter++;
    if (counter == 11)  //接收到11个数据
    {
      counter = 0;  //重新赋值，准备下一帧数据的接收
      sign = 1;
      if (Re_buf[0] != 0x55 || Re_buf[1] != 0x53) sign = 0;  //第0号数据不是帧头
    }
  }
}
//重置陀螺儀
void REset() {
  //Z-axis angle to zero
  Serial.println("RESET");
  Serial2.write(0xFF);
  Serial2.write(0xAA);
  Serial2.write(0x52);
  //Z-axis angle to zero
}
//檢查當下角度
void checkMPU() {
  Event();
  if (sign) {
    sign = 0;
    if (Re_buf[0] == 0x55 && Re_buf[1] == 0x53)  //检查帧头
    {
      yaw = (short(Re_buf[7] << 8 | Re_buf[6])) / 32768.0 * 180;    //偏航角
      pitch = (short(Re_buf[3] << 8 | Re_buf[2])) / 32768.0 * 180;  //俯仰角
      roll = (short(Re_buf[5] << 8 | Re_buf[4])) / 32768.0 * 180;   //橫滾角
    }
  }
}