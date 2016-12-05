# MOS Operating System
MOS (**Minimalist Operating System**) is a minimalist operating system.</br>
You can find all the **MOS** sources in this **repository**.</br>
Also, you can **modify** it or **build** it as long as you provide this [Github repository](https://github.com/leosncz/OperatingSystem).</br>
# How to build the sources ?
I used the **nasm** compiler to build all the **.ASM** files and **QEMU** to test it.
## First step : Bootloader
The first step is to download the bootloader sources in the **'bootloader'** directory of this repository located in the **root** folder.</br>
Then, compile the **bootloader** main file, you can do that with the following command :</br>
```batch
nasm -f bin bootMan.txt -o boot.bin
```
Now you have your compiled **bootloader** !</br>
It loads the **second sector** of the **USB** key (or **disk**).
