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
2. In the Makefile, uncomment the `PATCHES_ASFLAGS` line near the top. (Not strictly necessary, but the save type patch is helpful, else the game tends to not boot in some emulators due to unrecognized checksum.)
3. Clean and resplit the repo (standard setup, see above).
4. Make changes to a C file.
5. Compile.
6. Use the ROM created at `build/marioparty3.z64`.
