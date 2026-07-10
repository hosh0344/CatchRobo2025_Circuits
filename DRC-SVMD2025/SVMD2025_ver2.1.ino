#include <Arduino_CAN.h>
#include <Servo.h>

//通信関係
#define CAN_RX 5
#define CAN_TX 4
//LED関係
#define LED 13
#define RGB 8
//DIPスイッチ
#define SW0 A0
#define SW1 A1
#define SW2 A2
#define SW3 A3
//Servo出力
#define SV0 3
#define SV1 6
#define SV2 10
#define SV3 9

//CANID
int ID ;

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

//DIPスイッチを読み取る
void readSwitch() {
  int readNumber = !digitalRead(SW0) + 2 * !digitalRead(SW1) + 4 * !digitalRead(SW2) + 8 * !digitalRead(SW3);

  ID = 0x10 + readNumber;
  Serial.print("ID:");
  Serial.println(ID);
}

//ここに処理を記入(case0は例なので注意)
void readData(uint32_t command, int32_t value) {
  switch (command) {
    case 0:
    servo0.write(constrain(value, 0, 180));
      break;
  }
}

void setup() {

  pinMode(SW0, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(RGB, OUTPUT);

  Serial.begin(115200);  //シリアル初期化

  if (!CAN.begin(CanBitRate::BR_500k)) {
    Serial.println("CAN.begin(...) failed.");
  }
  readSwitch();  //DIPスイッチの読み出し

  servo0.attach(SV0);
  servo1.attach(SV1);
  servo2.attach(SV2);
  servo3.attach(SV3);
}

void loop() {
  //CAN受信かつid一致(0x12)で受信データ読み出し＆目標の再設定
  if (CAN.available()) {
    CanMsg const msg = CAN.read();
    int id = msg.id;  //IDを取得
    int length = msg.data_length;

    for (int i = 0; i < 8; i++) {
      Serial.print(msg.data[i], HEX);
    }
    Serial.println();

    if (id == ID && length == 8) {
      uint32_t command = 0;
      int32_t value = 0;

      for (int i = 0; i < 4; i++) {
        command |= (msg.data[i] << (8 * (3 - i)));
        value |= (msg.data[4 + i] << (8 * (3 - i)));
      }
      //command,value毎の処理
      readData(command, value);
    }
  }
}