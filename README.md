# Game-On-Sayodevice
Allows you to run games on a Sayodevice
WIP
Tree:
device-firmware/
├── src/
│   ├── main.c          # Boot, menu, launch/exit game
│   ├── input.c         # Read keys and knob
│   ├── display.c       # Screen drawing primitives
│   ├── storage.c       # List, read, write, delete game files
│   ├── runtime.c       # Load and execute a script safely
│   └── game_api.c      # Functions exposed to scripts
├── include/
│   ├── input.h
│   ├── display.h
│   ├── storage.h
│   ├── runtime.h
│   └── game_api.h
├── scripts/
│   └── snake.py     # A sample game (snake on python)
└── README.md
