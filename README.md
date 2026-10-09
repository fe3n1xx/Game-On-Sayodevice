# Game-On-Sayodevice
LICENSE: CC BY-NC-SA 4.0. <br />
Allows you to run games on a Sayodevice <br />
WIP <br />
Tree: <br />
/Game-On-Sayodevice/ <br />
├── src/ <br />
│   ├── main.c          # Boot, menu, launch/exit game <br />
│   ├── input.c         # Read keys and knob <br />
│   ├── display.c       # Screen drawing primitives <br />
│   ├── storage.c       # List, read, write, delete game files <br />
│   ├── runtime.c       # Load and execute a script safely <br />
│   └── game_api.c      # Functions exposed to scripts <br />
├── include/ <br />
│   ├── input.h <br />
│   ├── display.h <br />
│   ├── storage.h <br />
│   ├── runtime.h <br />
│   └── game_api.h <br />
├── scripts/ <br />
│   └── snake.py     # A sample game (snake on python) <br />
└── README.md <br />
