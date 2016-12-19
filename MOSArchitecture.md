# MOS Architecture
**mainBootloader.asm** is on the first sector, it loads the **secondStageBootloader** file.</br>
**secondStageBootloader** is on the second (or more it depends on it size) and loads a C kernel.
