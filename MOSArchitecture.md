# MOS Architecture
**mainBootloader.asm** is on the first sector, it loads the **secondStageBootloader** file at **0x500**.</br>
**secondStageBootloader** is on the second (or more it depends on it size) and loads a C kernel at **0x7E00**.
