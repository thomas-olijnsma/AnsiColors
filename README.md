# AnsiColors.hpp
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) <br> 
[AnsiColors](https://github.com/thomas-olijnsma/AnsiColors/blob/main/src/AnsiColors.hpp) is a C++17(+) header-only API that provides an easy to use, high level API. The goal of this project is to be a low overhead, typesafe, and logical abstraction layer; build on top of the 
[ANSI 256](https://en.wikipedia.org/wiki/ANSI_escape_code) escape codes. <br>
## Summary
This API will contain the following features:
  * **All ANSI 256** color codes are sorted and grouped in to one of the following color classes: `Red`, `Green`, `Blue`, `Cyan`, `Yellow`, `Purple`, `Orange`, `Brown`, `Violet`, `Pink`, `Black`, `Gray` or `White`; 
  * **Those color classes themselfs** are categorized in to classes: `PrimairyColors` **containing:** ***Red***, ***Green***, and ***Blue***; `SecondaryColors` **containing:** ***Cyan***, ***Yellow***, and ***Purple***; `TertiaryColors` **containing:** ***Orange***, ***Brown***, ***Violet***, and ***Pink***; `GrayScaleColors` **containing:** ***Black***, ***Gray***, ***White***, and ***Shades*** (Which is diverent from the other colors, since it redefines the gray color codes *232 - 255*);
  * 


## Table of Contents
