# mp3
A WIP decomp of Mario Party 3.

Note: This repository does not include the game ROM. You must provide the ROM yourself to build.

# To use
1. Place the US Mario Party 3 rom into the root of the repository as "baserom.u.z64".
2. Set up tools and extract the rom: `make setup`
3. Re-assemble the rom: `make -j`

After substantial changes, sometimes it is necessary to run: `make clean-all && make setup && make -j`

# Modifications
Only a small percentage of the game is decompiled, so it is not possible to modify and recompile
a working game in most cases. However, certain overlays that are fully decompiled can be modified,
since the major sections of the ROM are able to be shifted. For example, you can successfully modify
`intro.c` from the decompiled intro overlay and recompile a working ROM.

If you want to try this, you need to do a few things:
1. In splat.yaml, set `shiftable: True` in the options.
2. Clean and resplit the repo (standard setup, see above).
3. Open the marioparty3.ld (not the one in `build/`, the one in the root).
    - Add `__romPos = 0x0;` as the first line within `SECTIONS`. (Workaround for [splat #97](https://github.com/ethteck/splat/issues/97))
    - Delete all lines that say `. = __romPos;`
    - Find this line: `A7590_A75A8bin_ROM_START = __romPos;` and just before it, add this line: `__romPos += SIZEOF(.A7590);`
    - Find this line: `__romPos += SIZEOF(.A7590);` (not the one you just added, there's another existing one just below) and change it to be `__romPos += SIZEOF(.A7590_A75A8bin);`
4. In the Makefile, uncomment the `PATCHES_ASFLAGS` line near the top. (Not strictly necessary, but the save type patch is helpful, else the game tends to not boot in some emulators due to unrecognized checksum.)
5. Make changes to a C file.
6. Compile.
7. Use the ROM created at `build/marioparty3.z64`.
