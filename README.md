# Game-On-Sayodevice
LICENSE: CC BY-NC-SA 4.0. <br />
Allows you to run games on a Sayodevice <br />
WIP <br />
Tree: <br />
/Game-On-Sayodevice/ <br />
├── src/ <br />
│   ├── main.c             # Boot, menu, launch/exit game <br />
│   ├── input.c            # Read keys and knob <br />
│   ├── display.c          # Screen drawing primitives <br />
│   ├── storage.c          # List, read, write, delete game files <br />
│   ├── runtime.c          # Load and execute a script safely <br />
│   └── game_api.c         # Functions exposed to scripts <br />
├── include/ <br />
│   ├── input.h <br />
│   ├── display.h <br />
│   ├── storage.h <br />
│   ├── runtime.h <br />
│   └── game_api.h <br />
├── scripts/ <br />
│   └── snake.py            # A sample game (snake on python) <br />
│   └── snake.txt           # A sample game data text <br />
├── installer/ <br/>
│   └── app_installer.swift # Basic swift script to add files and their data texts to the scripts/ folder<br />
├── 3rd-party/ <br/>
│   └── ST7735S             # Driver for ST7735S display controller<br />
│       └── st7735s.c       # Driver for ST7735S display controller<br />
│       └── st7735s.h       # Driver for ST7735S display controller<br />
└── README.md <br />
└── hdwinf                  # Hardware Information<br />
└── howtodo.txt             # Code Order<br />
└── todo                    # todo<br />
