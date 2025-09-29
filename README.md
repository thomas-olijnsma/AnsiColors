# AnsiColors.hpp
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) <br> 
[AnsiColors](https://github.com/thomas-olijnsma/AnsiColors/blob/main/src/AnsiColors.hpp) is a C++17(+) header-only API that provides an easy to use, high level API. The goal of this project is to be a low overhead, typesafe, and logical abstraction layer; build on top of the 
[ANSI 256](https://en.wikipedia.org/wiki/ANSI_escape_code) escape codes. <br>
## Summary
This API will contain the following features, that all within the `ansi_colors` **namespace**: 
  * **A `Color` *(helper)* class** that is almost completely ***constexpr*** and only takes up ***2 bytes of memory***. It can hold all **256** ANSI color codes; as either a ***foreground*** or a ***background*** color;  
  * **All ANSI 256** color codes are sorted and grouped in to one of the following color classes: `Red`, `Green`, `Blue`, `Cyan`, `Yellow`, `Purple`, `Orange`, `Brown`, `Violet`, `Pink`, `Black`, `Gray` or `White`; 
  * **Those color classes themselfs** are categorized and sorted in to classes: <br>
    * **`PrimairyColors`** **which contains:** *`Red`*, *`Green`*, and *`Blue`*;<br>
    * **`SecondaryColors` which contains:** *`Cyan`*, *`Yellow`*, and *`Purple`*;<br>
    * **`TertiaryColors` which contains:** *`Orange`*, *`Brown`*, *`Violet`*, and *`Pink`*;<br>
    * **`GrayScaleColors` which contains:** *`Black`*, *`Gray`*, *`White`*, and *`Shades`* **->** a class that redefines the color codes `232 - 255`, also better known as the **(ANSI)** [grayscale](https://en.wikipedia.org/wiki/Grayscale) **colors**; <br>
  * **Namespace** `fg` and `bg`, which both contain an object of type *`PrimaryColors`*, *`SecondaryColors`*, ***etc***. Namespace **`fg`** contains the *foreground* and namespace **`bg`** contains the *background* version of the color codes; <br>
  * **A static struct** `TextStyles` that conains the styles: *`Bold`*, *`Faint`*, *`Italic`*, *`Underline `*, *`Blink`*, *`Inverse`*, *`Hidden`*, and *`Striketrough`*;
  * **A static struct** `Reset` that contains the ***reset*** codes for: *`All`*, *`FgColor`*, *`BgColor`*, *`Bold`*, *`Faint`*, *`Italic`*, *`Underline`*, *`Blink`*, *`Inverse`*, *`Hidden`*, and *`Striketrough`*;
  * 


## Table of Contents
