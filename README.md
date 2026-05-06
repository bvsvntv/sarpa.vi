<p align="center">
    <strong>sarpa.vi</strong>
</p>

I developed this simple Snake Game using the SDL2 library in C.
I was inspired by a video on the [CS50](https://www.youtube.com/@cs50) YouTube channel, which demonstrated [2D Games in C using SDL](https://www.youtube.com/watch?v=yFLa3ln16w0).
The name **`sarpa.vi`** (with 'sarpa/सर्प' meaning 'snake' in Nepali) playfully describes the snake-like behavior of my friends, while 'vi' refers to the Vim keybindings used for controls.

## Project setup

### Prerequisites

- [SDL2](https://www.libsdl.org/)
- C Compiler (gcc, g++ etc.)

#### Void linux

```bash
sudo xbps-install gcc SDL2 SDL2-devel -y
```
#### Ubuntu

```bash
sudo apt-get install libsdl2-2.0-0 libsdl2-dev -y
```

### Getting Started

- Clone the repository
    ```bash
    git clone git@github.com:bvsvntv/sarpa.vi.git
    ```
- Navigate to the project directory

    ```bash
    cd sarpa.vi
    ```
- Project Structure
    - `logic.{h,c}` - Contains core game state and mechanics
    - `rendering.{h,c}` - Handles all SDL-specific drawing logic
    - `main.c` - Contains the game loop and event handling, delegating logic and rendering to the respective modules

- Build and run the game using `make`

    ```bash
    make run
    ```

## Controls

| KEY                         | ACTION              |
| ----------------------------| --------------------|
| `i`/`<enter>`               | start game          |
| `h`                         | move left           |
| `j`                         | move down           |
| `k`                         | move up             |
| `l`                         | move right          |
| `esc`                       | quit the game       |
| `<space>`                   | pause/play the game |
| `<super>/<control>+q`       | quit the game       |
