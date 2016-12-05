# MOS Operating System
MOS (**Minimalist Operating System**) is a minimalist operating system.</br>
You can find all the **MOS** sources in this **repository**.</br>
Also, you can **modify** it or **build** it as long as you provide this [Github repository](https://github.com/leosncz/OperatingSystem).</br>
# How to build the sources ?
I used the **nasm** compiler to build all the **.ASM** files and **QEMU** to test it.
## First step
The first step is to compile the **bootloader**, you can do that with the following command :</br>
```batch
nasm -f bin boot.txt -o boot.bin
```
Now you have your compiled **bootloader** !</br>
It loads the **second sector** of the **USB** key (or **disk**).
