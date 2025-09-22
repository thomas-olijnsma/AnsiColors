# AnsiColors.hpp
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) <br> 
[AnsiColors](https://github.com/thomas-olijnsma/AnsiColors) is a C++17(+) header-only API that provides an easy to use, high level API. The goal of this project is to be a low overhead, typesafe, and logical abstraction layer; build on top of the [ANSI 256](https://en.wikipedia.org/wiki/ANSI_escape_code) escape codes. <br>
<br>
This API offers sorted and named color palettes for **all 256 color codes**. Both the **foreground** and **background** colors are separated from each other by the `fg` and the `bg` namespace. It also a `TextStyle` struct containing the ANSI codes for all common **text style** attributes. It also contains a `Reset` struct with multiple **reset** options. Both the *fg* and *bg* namespace contain the color categories: `PrimaryColors`, `SecondaryColors`, `TertiaryColors`, and `GrayScaleColors`; which in turn contain the actual pallettes (colors). Each color listed in the color  categories **(exept for the `Shades` palette)** consists out of two differently designed color palettes using the same color codes associated to that specific color.
<br>
## Table of Contents
