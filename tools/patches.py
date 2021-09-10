#!/usr/bin/env python3

# Applies some manual changes after splitting the ROM.

# Nonmatching functions accessing HVQ ROM_START are patched to refer to that symbol.
hvq_asm_files = [
    "asm/nonmatchings/overlays/overlay110/4C8050/func_8010FC98_4CCEC8.s",
    "asm/nonmatchings/overlays/overlay115/4F01F0/func_801059A0_4F01F0.s",
    "asm/nonmatchings/overlays/overlay124/5486A0/func_8010D1E8_549A68.s",
    "asm/nonmatchings/overlays/overlay125/54F360/func_80107204_54F574.s"
]

for file_path in hvq_asm_files:
    with open(file_path, 'r') as file :
        filedata = file.read()

    filedata = filedata.replace('$a0, 0x129', '$a0, %hi(bin_hvq_ROM_START)')
    filedata = filedata.replace('$a0, $a0, -0x33a0', '$a0, $a0, %lo(bin_hvq_ROM_START)')

    with open(file_path, 'w') as file:
        file.write(filedata)
