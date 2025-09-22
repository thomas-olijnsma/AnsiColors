# AnsiColors.hpp
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) <br> 
[AnsiColors](https://github.com/thomas-olijnsma/AnsiColors) is a C++17(+) header-only API that provides an easy to use, high level API. The goal of this project is to be a low overhead, typesafe, and logical abstraction layer; build on top of the [ANSI 256](https://en.wikipedia.org/wiki/ANSI_escape_code) escape codes. <br>
<br>
This API offers sorted and named color palettes for **all 256 color codes**. Both the **foreground** and **background** colors are separated from each other by the `fg` and the `bg` namespace. It also contains among other things: a `TextStyles` struct containing the escape codes for all common **text style** attributes. It also offers a `Reset` struct with multiple **reset** options. Both the *fg* and *bg* namespace contain the color category classes: `PrimaryColors`, `SecondaryColors`, `TertiaryColors`, and `GrayScaleColors`; which in turn contain the actual pallettes. Each palette 
<br>
## Table of Contents
