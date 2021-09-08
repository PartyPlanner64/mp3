# mp3
A WIP decomp of Mario Party 3.

Note: This repository does not include the game ROM. You must provide the ROM yourself to build.

# To use
1. Place the US Mario Party 3 rom into the root of the repository as "baserom.u.z64".
2. Set up tools and extract the rom: `make setup`
3. Re-assemble the rom: `make -j`

After substantial changes, sometimes it is necessary to run: `make clean-all && make setup && make -j`
