# キャチロボ2025で使用した回路 <br>

MCUにはArduino Uno R4に搭載のRenesasの[R7FA4M1AB3CFM](https://akizukidenshi.com/catalog/g/g118159/)を使用し、Arduino IDEで開発を行いました。 <br>

## 1. SVMD2025

4chのシンプルなサーボモータ制御回路です。

<img width="575" height="416" alt="{0E094BF4-E675-41B7-8FDE-F80BCE52A67B}" src="https://github.com/user-attachments/assets/3e7f3daa-f5a3-4d16-bbb2-107ab4c6313a" />

ファイルは[こちら](https://github.com/hosh0344/CatchRobo2025_Circuits/tree/main/DRC-SVMD2025) <br><br>

## 2. SLVD2025

4chの電磁弁駆動回路。電源電圧は5Vでも対応可能。

NMOSは[2SK4017](https://akizukidenshi.com/catalog/g/g107597/)

<img width="583" height="403" alt="{9A8F03F5-9690-44D8-8994-A85B7CA72C55}" src="https://github.com/user-attachments/assets/4e0c5b1f-a596-45ad-88d8-156277b88003" />

ファイルは[こちら](https://github.com/hosh0344/CatchRobo2025_Circuits/tree/main/DRC-SLVD2025) <br> <br>


## 3. DCDCコンバータ

Murataの[OKL-T/6-W12N-C](https://akizukidenshi.com/catalog/g/g106187/)を用いた5Vの降圧チョッパ回路。

出力電圧は可変抵抗で4.5V-5.5Vまで調整可能です。

ファイルは[こちら](https://github.com/hosh0344/CatchRobo2025_Circuits/tree/main/DCDC_Converter)
