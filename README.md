# SDL2 Graphics Prototype

An early C++/SDL2 graphics and movement prototype, published as a snapshot of an existing learning project for a University of Edinburgh INF1-CRISP reflective portfolio.

## Implemented behaviour

`Main.cpp` creates an 800 x 600 SDL2 window and a software renderer. It draws a black 40 x 40 rectangle on a white background, updates its position automatically, reverses its velocity at the window boundaries, and handles the window-close event. It cleans up the renderer, window and SDL on exit.

`test.cpp` is a separate earlier rendering experiment with three coloured rectangles and its own event loop and `main` function. It is included for context and is not compiled into the default target. Do not compile both source files into one executable.

This is an early graphics prototype. Ray casting, a first-person shooter, multiplayer networking, keyboard movement controls and a complete game engine are not implemented.

## Files

- `Main.cpp`: existing movement and boundary-collision prototype.
- `test.cpp`: separate static rendering experiment.
- `CMakeLists.txt`: C++17 `GamingEngine` target, SDL2 linkage and runtime DLL copying.
- `CMakePresets.json`: Windows x64 Debug presets using an environment-supplied vcpkg root.
- `.gitignore`: generated output and local environment exclusions.
- `README.md`: scope, build instructions and verification limits.

No compiled binaries, dependencies, textbooks, unrelated tutorials or external media assets are included.

## Requirements

- Windows x64.
- Visual Studio 2022 with Desktop development with C++ and a Windows SDK.
- CMake 3.25 or newer, for preset schema version 6.
- vcpkg with SDL2 installed for `x64-windows`.

The checked configuration uses MSVC and SDL2 2.x. SDL3 is not a drop-in replacement. Other operating systems and compilers have not been validated for this snapshot.

## Build and run

In PowerShell, set `VCPKG_ROOT` to your own vcpkg checkout. The example path is illustrative, not a path embedded in the build files:

```powershell
$env:VCPKG_ROOT = 'C:/tools/vcpkg'
& "$env:VCPKG_ROOT/vcpkg.exe" install sdl2:x64-windows
cmake --preset windows-x64
cmake --build --preset windows-x64-debug
& './build/Debug/GamingEngine.exe'
```

Use the native window close button to exit. The rectangle moves automatically; there is no input-controlled player.

The build defines `SDL_MAIN_HANDLED` because the supplied source has a no-argument `main`. It links `SDL2::SDL2` without adding `SDL2main` or changing the source entry point. The matching SDL2 runtime DLL is copied beside the executable after building.

## Validation of this snapshot

On 27 October 2026, the original local project was configured and built with CMake 4.4.2, Visual Studio 2022/MSVC x64 and its installed vcpkg SDL2 package. The Debug build completed with 0 warnings and 0 errors. The actual SDL window was inspected: the rectangle moved, reversed direction at horizontal and vertical boundaries, and the window closed normally. These are limited local checks, not an independent review, comprehensive automated test suite or guarantee on another computer.

The portable preset and extracted archive are also checked during packaging. `test.cpp` is not part of the default build or the runtime acceptance check. No VS Code breakpoint/debugger session is claimed.

## Limitations and possible follow-ups

Movement is updated by a fixed amount each loop with `SDL_Delay(1)`, so speed depends on timing and the machine. The source contains simple floating-point-to-integer rendering conversions and a minimal error path. These were preserved rather than redesigned. There is no frame-time-based movement, automated test coverage, gameplay system or external asset pipeline.

Possible follow-ups include improving timing, reviewing error handling and adding focused tests. These are ideas for later work, not completed features or a promised development schedule.

## Authorship and publication record

The C++ files were supplied in the owner's existing local project and were copied without changing their contents. Earlier development history and the original learning sources were not independently reconstructed. This initial upload records the current snapshot; it does not claim to date earlier work.

OpenAI Codex assistance was used to correct the stale CMake source filename, prepare a portable preset, write this documentation, verify and package the snapshot, and assist with publication. No C++ implementation or new game feature was generated or modified during this publication task.

SDL2 is an external dependency and retains its own licensing. No licence grant for the project source has been added by this upload.
