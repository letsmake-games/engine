# Notes

Trying out meson for the first time here are some notes.

# Setup

## Linux

- `pip3 install --user meson`
- `sudo apt-get install build-essential`
- `sudo apt-get install ninja-build`
- `meson setup build/linux`
- `ninja -C build/linux`
  - `ninja -C build/linux benchmark`
  - `ninja -C build/linux test`

## Windows

- `choco install python3`
- `py -m pip install --user meson`
- `choco install ninja`
- `meson setup build/windows`
  - `ninja -C build/linux benchmark`
  - `ninja -C build/linux test`
