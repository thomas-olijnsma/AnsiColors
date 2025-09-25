/**
 * This source header was made by Thomas Olijnsma. (2025)
 * With the purpose of making working with the ANSI 256 color codes more easy and save.
 * Read the documentation for more information.
 * This header is only for C++ v17 and higher. 
 */

// Copyright: (c) 2025 Thomas Olijnsma
// License: see LICENSE for more details
 

#ifndef LEMONCODE_ANSICOLORS_HPP
#define LEMONCODE_ANSICOLORS_HPP

#include <iostream>
#include <cstdint>
#include <exception>
#include <limits>

#ifndef LEMONCODE_ANSICOLORS_CPP20_OR_NEWER
    #if defined(_MSC_VER)
        #if _MSVC_LANG >= 202002L
            #define LEMONCODE_ANSICOLORS_CPP20_OR_NEWER 1
        #else
            #define LEMONCODE_ANSICOLORS_CPP20_OR_NEWER 0
        #endif
    #elif __cplusplus >= 202002L
        #define LEMONCODE_ANSICOLORS_CPP20_OR_NEWER 1
    #else
        #define LEMONCODE_ANSICOLORS_CPP20_OR_NEWER 0
    #endif
#endif

#ifdef _WIN32
    #include <windows.h> 
    /// @warning This namespace should never be used by the end user. It's only a helper namespace to enable virtual terminal processing on Windows hosts! 
    namespace __LMN_Windows_Ansi_Codes__Terminal_HELPER_ns_ {
        class ConsoleVtGuard {
            HANDLE hConsole;
            DWORD old_mode;
        public:
            ConsoleVtGuard(){
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                if(hConsole == INVALID_HANDLE_VALUE)
                    throw std::runtime_error("Cannot get console handle!");

                if(!GetConsoleMode(hConsole, &old_mode))
                    throw std::runtime_error("Cannot read the current console mode!");

                DWORD new_mode = old_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                if(!SetConsoleMode(hConsole, new_mode))
                    throw std::runtime_error("Cannot enable Virtual Terminal Processing!");
            }   

            ConsoleVtGuard(const ConsoleVtGuard&) = delete;
            ConsoleVtGuard&operator=(const ConsoleVtGuard&) = delete;

            ~ConsoleVtGuard() noexcept {
                SetConsoleMode(hConsole, old_mode);
            }
        };
        /// @brief This allows for the ANSI 256 color codes to be used in Windows terminals. 
        inline ConsoleVtGuard GlobalVtGuard;
    }
#endif

/// @brief Provides wrapper interfaces for ANSI 256‑color codes.
namespace ansi_colors {
    /// @brief Interface for applying text style attributes.
    struct TextStyle {
        TextStyle() noexcept = delete;

        inline static constexpr const char* Bold =          "\033[1m";
        inline static constexpr const char* Faint =         "\033[2m";
        inline static constexpr const char* Italic =        "\033[3m";
        inline static constexpr const char* Underline =     "\033[4m";
        inline static constexpr const char* Blink =         "\033[5m";
        inline static constexpr const char* Inverse =       "\033[7m";
        inline static constexpr const char* Hidden =        "\033[8m";
        inline static constexpr const char* Strikethrough = "\033[9m";

        ~TextStyle() noexcept = delete; 
    };

    /// @brief Interface for resetting (text) style and color attributes. 
    struct Reset {
        /// @brief  Resets the terminal to its original state.
        inline static constexpr const char* All = "\033[0m";
       
        /// @brief Resets the `foreground` color of the terminal to its original state.
        inline static constexpr const char* FgColor = "\033[39m";
        /// @brief Resets the `background` color of the terminal to its original state.
        inline static constexpr const char* BgColor = "\033[49m";

        /// @brief Turns off bold text (`TextStyles::Bold`) in the terminal.
        inline static constexpr const char* Bold =          "\033[22m";
        /// @brief Turns off faint text (`TextStyles::Faint`) in the terminal.
        inline static constexpr const char* Faint =         "\033[22m";
        /// @brief Turns off italic text (`TextStyles::Italic`) in the terminal.
        inline static constexpr const char* Italic =        "\033[23m";
        /// @brief Turns off underline text (`TextStyles::Underline`) in the terminal.
        inline static constexpr const char* Underline =     "\033[24m";
        /// @brief Turns off blinking text (`TextStyles::Blink`) in the terminal.
        inline static constexpr const char* Blink =         "\033[25m";
        /// @brief Turns off inverse text (`TextStyles::Inverse`) in the terminal.
        inline static constexpr const char* Inverse =       "\033[27m";
        /// @brief Turns off hidden text (`TextStyles::Hidden`) in the terminal.
        inline static constexpr const char* Hidden =        "\033[28m";
        /// @brief Turns off strikethrough text (`TextStyles::Strikethrough`) in the terminal.
        inline static constexpr const char* Strikethrough = "\033[29m";

        Reset() noexcept = delete;
        ~Reset() noexcept = delete;
    };
}
    
/// @brief  Helper namespace for the color definitions in the ansi_colors namespace.
/// @warning Users of this header should not modify the declarations or definitions in this namespace.
namespace __LMN_color_categories_defined_ {
    namespace __CONSTEXPR_ANSI_code_conv_helper_funcs_ {
        /// @brief constexpr helper that translates a uint8_t value into an ANSI code and selects the appropriate color mode.
        /// @param code The ANSI 256‑color index.
        /// @param bgColor If true, applies the color as a background; if false, applies it to text.
        /// @return The ANSI escape sequence for the specified color and mode.
        inline constexpr const char* getAnsi256Code(uint8_t code, bool bgColor);
    }
    
    /// @brief Helper structure that groups color codes into their respective color categories.
    struct Defined_Colors {
        enum class Red : uint8_t {
            Red1 = 1,
            Red9 = 9,
            Red52 = 52,      
            Red88 = 88,
            Red124 = 124,
            Red160 = 160,
            Red167 = 167,
            Red196 = 196,
            Red203 = 203,
            Red210 = 210,
            Red217 = 217
        };
        enum class Orange : uint8_t {
            Orange130 = 130,
            Orange166 = 166,
            Orange172 = 172,
            Orange202 = 202,
            Orange208 = 208,
            Orange209 = 209,
            Orange214 = 214,
            Orange215 = 215,
            Orange216 = 216,
            Orange217 = 217
        };
        enum class Yellow : uint8_t {
            Yellow3 = 3,
            Yellow11 = 11,
            Yellow100 = 100,
            Yellow142 = 142,
            Yellow143 = 143,
            Yellow144 = 144,
            Yellow178 = 178,
            Yellow184 = 184,
            Yellow185 = 185, 
            Yellow186 = 186,
            Yellow187 = 187,
            Yellow190 = 190,
            Yellow191 = 191,
            Yellow192 = 192,
            Yellow220 = 220,
            Yellow221 = 221,
            Yellow222 = 222,
            Yellow226 = 226,
            Yellow227 = 227,
            Yellow228 = 228,
            Yellow229 = 229,
            Yellow230 = 230
        };
        enum class Green : uint8_t {
            Green2 = 2,
            Green10 = 10,
            Green22 = 22,
            Green28 = 28,
            Green29 = 29,
            Green34 = 34,
            Green35 = 35,
            Green40 = 40,
            Green41 = 41,
            Green42 = 42,
            Green46 = 46,
            Green47 = 47,
            Green48 = 48,
            Green49 = 49,
            Green58 = 58,
            Green64 = 64,
            Green65 = 65,
            Green70 = 70,
            Green71 = 71,
            Green72 = 72,
            Green76 = 76,
            Green77 = 77,
            Green78 = 78,  
            Green82 = 82,
            Green83 = 83,
            Green84 = 84,
            Green85 = 85,
            Green101 = 101,
            Green106 = 106,
            Green107 = 107,
            Green108 = 108,
            Green112 = 112,
            Green113 = 113,
            Green114 = 114,
            Green118 = 118,
            Green119 = 119,
            Green120 = 120,
            Green121 = 121,
            Green148 = 148,
            Green149 = 149,
            Green150 = 150,
            Green151 = 151,
            Green154 = 154,
            Green155 = 155,
            Green156 = 156,
            Green157 = 157,
            Green193 = 193,
            Green194 = 194
        };
        enum class Cyan : uint8_t {
            Cyan6 = 6,
            Cyan14 = 14,
            Cyan23 = 23,
            Cyan24 = 24,
            Cyan30 = 30,
            Cyan31 = 31,
            Cyan36 = 36,
            Cyan37 = 37,
            Cyan43 = 43,
            Cyan44 = 44,
            Cyan50 = 50,
            Cyan51 = 51,
            Cyan66 = 66,
            Cyan73 = 73,
            Cyan79 = 79,
            Cyan80 = 80,
            Cyan86 = 86,
            Cyan87 = 87,
            Cyan109 = 109,
            Cyan115 = 115,
            Cyan116 = 116,
            Cyan117 = 117,
            Cyan122 = 122,
            Cyan123 = 123,
            Cyan152 = 152,
            Cyan158 = 158,
            Cyan159 = 159,
            Cyan195 = 195
        };
        enum class Blue : uint8_t {
            Blue4 = 4,
            Blue12 = 12,
            Blue17 = 17,
            Blue18 = 18,
            Blue19 = 19,
            Blue20 = 20,
            Blue21 = 21,
            Blue25 = 25,
            Blue26 = 26,
            Blue27 = 27,
            Blue32 = 32,
            Blue33 = 33,
            Blue38 = 38,
            Blue39 = 39,
            Blue45 = 45,
            Blue60 = 60,
            Blue61 = 61,
            Blue62 = 62,
            Blue63 = 63,
            Blue67 = 67,
            Blue68 = 68,
            Blue69 = 69,
            Blue74 = 74,
            Blue75 = 75,
            Blue81 = 81,
            Blue103 = 103,
            Blue104 = 104,
            Blue105 = 105,
            Blue110 = 110,
            Blue111 = 111,
            Blue146 = 146,
            Blue147 = 147,
            Blue153 = 153,
            Blue189 = 189
        };
        enum class Violet : uint8_t {
            Violet54 = 54,
            Violet55 = 55,
            Violet56 = 56,
            Violet57 = 57,
            Violet92 = 92,
            Violet93 = 93,
            Violet97 = 97,
            Violet98 = 98,
            Violet99 = 99,
            Violet135 = 135,
            Violet140 = 140,
            Violet141 = 141,
            Violet177 = 177,
            Violet182 = 182,
            Violet183 = 183,
        };
        enum class Pink : uint8_t {
            Pink13 = 13,
            Pink89 = 89,
            Pink125 = 125,
            Pink132 = 132,
            Pink161 = 161,
            Pink162 = 162,
            Pink163 = 163,
            Pink168 = 168,
            Pink169 = 169,
            Pink174 = 174,
            Pink175 = 175,
            Pink197 = 197,
            Pink198 = 198,
            Pink199 = 199,
            Pink200 = 200,
            Pink204 = 204,
            Pink205 = 205,
            Pink206 = 206,
            Pink211 = 211,
            Pink212 = 212,
            Pink218 = 218,
            Pink224 = 224
        };
        enum class Purple : uint8_t {
            Purple5 = 5,
            Purple53 = 53,
            Purple90 = 90,
            Purple91 = 91,
            Purple96 = 96,
            Purple126 = 126,
            Purple127 = 127,
            Purple128 = 128,
            Purple129 = 129,
            Purple133 = 133,
            Purple134 = 134,
            Purple139 = 139,
            Purple164 = 164,
            Purple165 = 165,
            Purple170 = 170,
            Purple171 = 171,
            Purple176 = 176,
            Purple201 = 201,
            Purple207 = 207,
            Purple213 = 213,
            Purple219 = 219,
            Purple225 = 225
        };
        enum class Brown : uint8_t {
            Brown94 = 94,
            Brown95 = 95,
            Brown131 = 131,
            Brown136 = 136,
            Brown137 = 137,
            Brown138 = 138,
            Brown173 = 173,
            Brown179 = 179,
            Brown180 = 180,
            Brown181 = 181,
            Brown223 = 223
        };
        enum class GrayScale : uint8_t {
            Black232 = 232,
            Black233 = 233,
            
            Gray234 = 234,
            Gray235 = 235,
            Gray236 = 236,
            Gray237 = 237,
            Gray238 = 238,
            Gray239 = 239,
            Gray240 = 240,
            Gray241 = 241,
            Gray242 = 242,
            Gray243 = 243,
            Gray244 = 244,
            Gray245 = 245,
            Gray246 = 246,
            Gray247 = 247,
            Gray248 = 248,
            Gray249 = 249,
            Gray250 = 250,
            Gray251 = 251,
            Gray252 = 252,
            Gray253 = 253,
            Gray254 = 254,
            White255 = 255
        };
        enum class Gray : uint8_t {
            Gray8 = 8,
            Gray59 = 59,
            Gray102 = 102,
            Gray145 = 145,  
            Gray188 = 188,
            Gray234 = 234,
            Gray235 = 235,
            Gray236 = 236,
            Gray237 = 237,
            Gray238 = 238,
            Gray239 = 239,
            Gray240 = 240,
            Gray241 = 241,
            Gray242 = 242,
            Gray243 = 243,
            Gray244 = 244,
            Gray245 = 245,
            Gray246 = 246,
            Gray247 = 247,
            Gray248 = 248,
            Gray249 = 249,
            Gray250 = 250,
            Gray251 = 251,
            Gray252 = 252,
            Gray253 = 253,
            Gray254 = 254
        };
        enum class White : uint8_t {
            White7 = 7,
            White15 = 15,
            White231 = 231,
            White255 = 255
        };
        enum class Black : uint8_t {
            Black0 = 0,
            Black16 = 16,
            Black232 = 232,
            Black233 = 233
        };
        Defined_Colors() noexcept = delete;
        ~Defined_Colors() noexcept = delete;
    };
}

/// @brief Provides wrapper interfaces for ANSI 256‑color codes.
namespace ansi_colors {
    /// @brief Represents an ANSI 256 color (foreground or background) and provides helper methods and conversions for ANSI escape sequences.
    class Color {
        typedef __LMN_color_categories_defined_::Defined_Colors Defined_Colors;
        uint8_t color_code;
        bool bg_color;
        
        template<typename Type>
        constexpr uint8_t getColorCode(Type color){
            return static_cast<uint8_t>(color);
        }
    public:
        Color() = delete;
        // --- COPY CONSTRUCTOR ---
        Color(const Color& other) noexcept : color_code(other.color_code), bg_color(other.bg_color){};
        // --- MOVE CONSTRUCTOR ---
        Color(Color&& other) noexcept : color_code(other.color_code), bg_color(other.bg_color){};
        
        explicit Color(uint8_t color_code, bool bg_color) noexcept : color_code(color_code), bg_color(bg_color){};
        explicit Color(Defined_Colors::Black black, bool bg_color) noexcept : color_code(getColorCode(black)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Blue blue_color, bool bg_color) noexcept : color_code(getColorCode(blue_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Brown brown_color, bool bg_color) noexcept : color_code(getColorCode(brown_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Cyan cyan_color, bool bg_color) noexcept : color_code(getColorCode(cyan_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Gray gray, bool bg_color) noexcept : color_code(getColorCode(gray)), bg_color(bg_color){};
        explicit Color(Defined_Colors::GrayScale gray_scale, bool bg_color) noexcept : color_code(getColorCode(gray_scale)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Green green_color, bool bg_color) noexcept : color_code(getColorCode(green_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Orange orange_color, bool bg_color) noexcept : color_code(getColorCode(orange_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Pink pink_color, bool bg_color) noexcept : color_code(getColorCode(pink_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Purple purple_color, bool bg_color) noexcept : color_code(getColorCode(purple_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Red red_color, bool bg_color) noexcept : color_code(getColorCode(red_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Violet violet_color, bool bg_color) noexcept : color_code(getColorCode(violet_color)), bg_color(bg_color){};
        explicit Color(Defined_Colors::White white, bool bg_color) noexcept : color_code(getColorCode(white)), bg_color(bg_color){};
        explicit Color(Defined_Colors::Yellow yellow_color, bool bg_color) noexcept : color_code(getColorCode(yellow_color)), bg_color(bg_color){};   
       
        /// @brief Returns the ANSI escape sequence corresponding to this color and mode.
        /// @return A const char* with the ANSI escape sequence.
        constexpr const char* c_str() const noexcept {
            using __LMN_color_categories_defined_::__CONSTEXPR_ANSI_code_conv_helper_funcs_::getAnsi256Code;
            return getAnsi256Code(color_code, bg_color);
        }

        /// @brief Returns the ANSI 256 color code as a uint8_t.
        /// @return The ANSI color code.
        constexpr uint8_t colorCode() const noexcept { return color_code; }

        /// @brief Indicates whether the color is used as a background.
        /// @return true if background color; false if foreground color.
        constexpr bool isBackgroundColor() const noexcept { return bg_color; }

        // --- COPY ASSIGNMENT OPERATOR ---
        Color&operator=(const Color& other) noexcept {
            if(this != &other){
                color_code = other.color_code;
                bg_color = other.bg_color;
            }
            return *this;
        }

        // --- MOVE ASSIGNMENT OPERATOR ---
        Color&operator=(Color&& other) noexcept {
            if(this != &other){
                color_code = other.color_code;
                bg_color = other.bg_color;
            }
            return *this;
        }

        /// @brief Returns the ANSI escape sequence using the dereference operator. Useful with functions like printf().
        /// @return A constexpr const char* from c_str().
        constexpr const char* operator*() const noexcept { return c_str(); }

        /// @brief Implicit conversion to const char* (ANSI escape sequence).
        constexpr operator const char*() const noexcept { return c_str(); }

        /// @brief Implicit conversion to std::string containing the ANSI escape sequence.
        operator std::string() const { return std::string(c_str()); } 

        /// @brief Implicit conversion to uint8_t (ANSI color code).
        constexpr operator uint8_t() const noexcept { return color_code; }

        /// @brief Overloaded ostream operator for direct output using std::cout or similar.
        friend std::ostream&operator<<(std::ostream& os, const Color& color) {
            using __LMN_color_categories_defined_::__CONSTEXPR_ANSI_code_conv_helper_funcs_::getAnsi256Code;
            
            os<< (color.bg_color ? Reset::BgColor : Reset::FgColor)<< getAnsi256Code(color.color_code, color.bg_color);
            return os;
        }

        ~Color() noexcept = default;
    };
}

/// @brief  Helper namespace for the color definitions in the ansi_colors namespace.
/// @warning Users of this header should not modify the declarations or definitions in this namespace.
namespace __LMN_color_categories_defined_ {
    using ansi_colors::Color;
    
    template<typename classType>
    class const_Color_iterator final {
        const classType* self;
        uint8_t idx;
    public:
        const_Color_iterator(const classType* s, uint8_t i) noexcept : self(s), idx(i){};
        const Color& operator*() const noexcept {
            return self->*(classType::table[idx]);
        }
        const_Color_iterator&operator++() noexcept { ++idx; return *this; }
        bool operator!=(const const_Color_iterator& o) const noexcept { return idx != o.idx; }
    };
     
    /// @brief This class defines the primary colors: Red, Green and Blue. 
    class PrimaryColors {
        /// @brief Helper method for checking if the given index isn't out of range, else it will throw an instance of 'std::out_of_range' with an appropriate error message.
        /// @param classInstance The class (color palette color) name of the caller method/ operator.
        /// @param index The given index.
        /// @param max_index The maximum index.
        /// @param at True in case the caller is the .at() method. Default = false.
        static void checkForOutOfRange(const std::string& classInstance, uint8_t index, uint8_t max_index, bool at = false){
            auto getOperator = [&classInstance]() -> std::string {
                return (classInstance.length() == 1 ? "->" : ".");
            };
            auto getErrorStart = [=]() -> std::string {
                if(at){
                    return "\nERROR: Illegal index in method 'PrimaryColors"+getOperator()+classInstance+".at("+std::to_string(index)+")'";
                } else {
                    return "\nERROR: Illegal index in operator 'PrimaryColors"+getOperator()+classInstance+"["+std::to_string(index)+"]'";
                }
            };
            if(index > 0 && index <= max_index) return;
            if(index == 0){
                throw std::out_of_range(getErrorStart()+"\n\n\t-Indexing starts at 1 (corresponding to the first color palette name) and aligns with the member color definition names.\n");
            } else {
                throw std::out_of_range(getErrorStart()+"\n\n\t-Your index exceeds the available color range (1 - "+std::to_string(max_index)+")\n");
            }
        }

        friend class _Red;
        /// @brief Defines the primary color Red in to 2 uniquely named color palettes. 
        class _Red {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class RedColorRange {
                friend const_Color_iterator<RedColorRange>;
                typedef Defined_Colors::Red RED;
                bool short_cut;
            public:
                const Color Red1; 
                const Color Red2;
                const Color Red3;
                const Color Red4;
                const Color Red5;
                const Color Red6;
                const Color Red7;
                const Color Red8;
                const Color Red9;
                const Color Red10;
                const Color Red11;
                RedColorRange() noexcept = delete;
                RedColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Red1(RED::Red52, bg_c), Red2(RED::Red88, bg_c), 
                    Red3(RED::Red124, bg_c), Red4(RED::Red1, bg_c), Red5(RED::Red160, bg_c), Red6(RED::Red196, bg_c), Red7(RED::Red9, bg_c), 
                    Red8(RED::Red167, bg_c), Red9(RED::Red203, bg_c), Red10(RED::Red210, bg_c), Red11(RED::Red217, bg_c){}; 

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 11).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "R" : "Red"), index, 11);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 11).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "R" : "Red"), index, 11, true);    
                    return this->*(table[--index]);
                }

                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<RedColorRange> begin() const { return {this, 0}; }

                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 11).
                const const_Color_iterator<RedColorRange> end() const { return {this, 11}; }
            private:
                inline static const constexpr Color RedColorRange::* table[11] = {
                    &RedColorRange::Red1,
                    &RedColorRange::Red2,
                    &RedColorRange::Red3,
                    &RedColorRange::Red4,
                    &RedColorRange::Red5,
                    &RedColorRange::Red6,
                    &RedColorRange::Red7,
                    &RedColorRange::Red8,
                    &RedColorRange::Red9,
                    &RedColorRange::Red10,
                    &RedColorRange::Red11
                };
            };
            const RedColorRange Red_Color_Range;
            bool bg_color;  
        public:
            _Red() noexcept = delete;
            _Red(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Red_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_Red =               Color (Defined_Colors::Red::Red1, bg_color);
            const Color std_Bright_Red =        Color (Defined_Colors::Red::Red9, bg_color);
            const Color Dark_Blood_Red =        Color (Defined_Colors::Red::Red52, bg_color);
            const Color Deep_Red =              Color (Defined_Colors::Red::Red88, bg_color);
            const Color Dark_Red =              Color (Defined_Colors::Red::Red124, bg_color);
            const Color Bright_Red =            Color (Defined_Colors::Red::Red160, bg_color);
            const Color Rust_Red =              Color (Defined_Colors::Red::Red167, bg_color);
            const Color Pure_Red =              Color (Defined_Colors::Red::Red196, bg_color);
            const Color Blush_Red =             Color (Defined_Colors::Red::Red203, bg_color);
            const Color Rosy_Red =              Color (Defined_Colors::Red::Red210, bg_color);
            const Color Pastel_Red =            Color (Defined_Colors::Red::Red217, bg_color);
            
            /// @brief Enables range-based for loops over the Red color range.
            /// @return A const iterator to the first element of `Red_Color_Range`.
            const const_Color_iterator<RedColorRange> begin() const { return Red_Color_Range.begin(); } 
            
            /// @brief Enables range-based for loops over the Red color range.
            /// @return A const iterator one past the last element of `Red_Color_Range`.
            const const_Color_iterator<RedColorRange> end() const { return Red_Color_Range.end(); }

            /// @brief Retrieves a Red color by index (valid range: 1 – 11) from the `Red_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Red color.
            /// @return A reference to the corresponding `Color` object in `Red_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "R" : "Red"), index, 11);
                return Red_Color_Range[index]; 
            }

            /// @brief Retrieves a Red color by index (valid range: 1 – 11) from the `Red_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Red color.
            /// @return A reference to the corresponding `Color` object in `Red_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "R" : "Red"), index, 11, true);
                return Red_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Red_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Red_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const RedColorRange* operator->() const noexcept { return &Red_Color_Range; }

            /// @brief Overloads `operator<<` to insert the Pure_Red ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Red color wrapper containing the Pure_Red escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Red& red){
                os<< red.Pure_Red;
                return os;
            }
            ~_Red() noexcept = default; 
        };

        friend class _Green;
        /// @brief Defines the primary color Green in to 2 uniquely named color palettes. 
        class _Green {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class GreenColorRange {
                friend const_Color_iterator<GreenColorRange>;
                bool short_cut;
                typedef Defined_Colors::Green GREEN;
            public:
                const Color Green1;
                const Color Green2;
                const Color Green3;
                const Color Green4;
                const Color Green5;
                const Color Green6;
                const Color Green7;
                const Color Green8;
                const Color Green9;
                const Color Green10;
                const Color Green11;
                const Color Green12;
                const Color Green13;
                const Color Green14;
                const Color Green15;
                const Color Green16;
                const Color Green17;
                const Color Green18;
                const Color Green19;
                const Color Green20;
                const Color Green21;
                const Color Green22;
                const Color Green23;
                const Color Green24;
                const Color Green25;
                const Color Green26;
                const Color Green27;
                const Color Green28;
                const Color Green29;
                const Color Green30;
                const Color Green31;
                const Color Green32;
                const Color Green33;
                const Color Green34;
                const Color Green35;
                const Color Green36;
                const Color Green37;
                const Color Green38;
                const Color Green39;
                const Color Green40;
                const Color Green41;
                const Color Green42;
                const Color Green43;
                const Color Green44;
                const Color Green45;
                const Color Green46;
                const Color Green47;
                const Color Green48;
                GreenColorRange() noexcept = delete;
                GreenColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Green1(GREEN::Green22, bg_c), Green2(GREEN::Green58, bg_c), 
                    Green3(GREEN::Green28, bg_c), Green4(GREEN::Green29, bg_c), Green5(GREEN::Green64, bg_c), Green6(GREEN::Green65, bg_c), Green7(GREEN::Green2, bg_c), 
                    Green8(GREEN::Green34, bg_c), Green9(GREEN::Green35, bg_c), Green10(GREEN::Green101, bg_c), Green11(GREEN::Green70, bg_c), Green12(GREEN::Green71, bg_c), 
                    Green13(GREEN::Green10, bg_c), Green14(GREEN::Green40, bg_c), Green15(GREEN::Green106, bg_c), Green16(GREEN::Green72, bg_c), Green17(GREEN::Green41, bg_c), 
                    Green18(GREEN::Green107, bg_c), Green19(GREEN::Green42, bg_c), Green20(GREEN::Green108, bg_c), Green21(GREEN::Green76, bg_c), Green22(GREEN::Green77, bg_c), 
                    Green23(GREEN::Green46, bg_c), Green24(GREEN::Green112, bg_c), Green25(GREEN::Green78, bg_c), Green26(GREEN::Green47, bg_c), Green27(GREEN::Green113, bg_c), 
                    Green28(GREEN::Green148, bg_c), Green29(GREEN::Green48, bg_c), Green30(GREEN::Green114, bg_c), Green31(GREEN::Green49, bg_c), Green32(GREEN::Green149, bg_c), 
                    Green33(GREEN::Green150, bg_c), Green34(GREEN::Green82, bg_c), Green35(GREEN::Green151, bg_c), Green36(GREEN::Green83, bg_c), Green37(GREEN::Green118, bg_c), 
                    Green38(GREEN::Green84, bg_c), Green39(GREEN::Green85, bg_c), Green40(GREEN::Green119, bg_c), Green41(GREEN::Green154, bg_c), Green42(GREEN::Green120, bg_c), 
                    Green43(GREEN::Green121, bg_c), Green44(GREEN::Green155, bg_c), Green45(GREEN::Green156, bg_c), Green46(GREEN::Green157, bg_c), Green47(GREEN::Green193, bg_c), 
                    Green48(GREEN::Green194, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 48).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "G" : "Green"), index, 48);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 48).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "G" : "Green"), index, 48, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<GreenColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 48).
                const const_Color_iterator<GreenColorRange> end() const { return {this, 48}; }
            private:
                inline static const constexpr Color GreenColorRange::* table[48] = {
                    &GreenColorRange::Green1,
                    &GreenColorRange::Green2,
                    &GreenColorRange::Green3,
                    &GreenColorRange::Green4,
                    &GreenColorRange::Green5,
                    &GreenColorRange::Green6,
                    &GreenColorRange::Green7,
                    &GreenColorRange::Green8,
                    &GreenColorRange::Green9,
                    &GreenColorRange::Green10,
                    &GreenColorRange::Green11,
                    &GreenColorRange::Green12,
                    &GreenColorRange::Green13,
                    &GreenColorRange::Green14,
                    &GreenColorRange::Green15,
                    &GreenColorRange::Green16,
                    &GreenColorRange::Green17,
                    &GreenColorRange::Green18,
                    &GreenColorRange::Green19,
                    &GreenColorRange::Green20,
                    &GreenColorRange::Green21,
                    &GreenColorRange::Green22,
                    &GreenColorRange::Green23,
                    &GreenColorRange::Green24,
                    &GreenColorRange::Green25,
                    &GreenColorRange::Green26,
                    &GreenColorRange::Green27,
                    &GreenColorRange::Green28,
                    &GreenColorRange::Green29,
                    &GreenColorRange::Green30,
                    &GreenColorRange::Green31,
                    &GreenColorRange::Green32,
                    &GreenColorRange::Green33,
                    &GreenColorRange::Green34,
                    &GreenColorRange::Green35,
                    &GreenColorRange::Green36,
                    &GreenColorRange::Green37,
                    &GreenColorRange::Green38,
                    &GreenColorRange::Green39,
                    &GreenColorRange::Green40,
                    &GreenColorRange::Green41,
                    &GreenColorRange::Green42,
                    &GreenColorRange::Green43,
                    &GreenColorRange::Green44,
                    &GreenColorRange::Green45,
                    &GreenColorRange::Green46,
                    &GreenColorRange::Green47,
                    &GreenColorRange::Green48
                };
            };
            GreenColorRange Green_Color_Range;
            bool bg_color;
        public:
            _Green() noexcept = delete;
            _Green(bool bg_color, bool short_cut = false) : bg_color(bg_color), Green_Color_Range(bg_color, short_cut) {
                this->short_cut = short_cut;
            }

            const Color std_Green =                     Color (Defined_Colors::Green::Green2, bg_color);
            const Color std_Bright_Green =              Color (Defined_Colors::Green::Green10, bg_color);
            const Color Dark_Green =                    Color (Defined_Colors::Green::Green22, bg_color);
            const Color Medium_Green =                  Color (Defined_Colors::Green::Green28, bg_color);
            const Color Deep_Sea_Green =                Color (Defined_Colors::Green::Green29, bg_color);
            const Color Spring_Green =                  Color (Defined_Colors::Green::Green34, bg_color);
            const Color Jade_Green =                    Color (Defined_Colors::Green::Green35, bg_color);
            const Color Lime_Green =                    Color (Defined_Colors::Green::Green40, bg_color);
            const Color Light_Spring_Green =            Color (Defined_Colors::Green::Green41, bg_color);
            const Color Caribbean_Green =               Color (Defined_Colors::Green::Green42, bg_color);
            const Color Pure_Green =                    Color (Defined_Colors::Green::Green46, bg_color);
            const Color Vibrant_Spring_Green =          Color (Defined_Colors::Green::Green47, bg_color);
            const Color Soft_Spring_Green =             Color (Defined_Colors::Green::Green48, bg_color);
            const Color Brilliant_Spring_Green =        Color (Defined_Colors::Green::Green49, bg_color);
            const Color Dark_Olive_Green =              Color (Defined_Colors::Green::Green58, bg_color);
            const Color Olive_Green =                   Color (Defined_Colors::Green::Green64, bg_color);
            const Color Glade_Green =                   Color (Defined_Colors::Green::Green65, bg_color);
            const Color Kelly_Green =                   Color (Defined_Colors::Green::Green70, bg_color);
            const Color Dark_Sea_Green =                Color (Defined_Colors::Green::Green71, bg_color);
            const Color Cadet_Green =                   Color (Defined_Colors::Green::Green72, bg_color);
            const Color Strong_Green =                  Color (Defined_Colors::Green::Green76, bg_color);
            const Color Moderate_Lime_Green =           Color (Defined_Colors::Green::Green77, bg_color);
            const Color Sea_Green =                     Color (Defined_Colors::Green::Green78, bg_color);
            const Color Chartreuse =                    Color (Defined_Colors::Green::Green82, bg_color);
            const Color Light_Lime_Green =              Color (Defined_Colors::Green::Green83, bg_color);
            const Color Light_Sea_Green =               Color (Defined_Colors::Green::Green84, bg_color);
            const Color Luminous_Spring_Green =         Color (Defined_Colors::Green::Green85, bg_color);
            const Color Clay_Creek_Green =              Color (Defined_Colors::Green::Green101, bg_color);
            const Color Apple_Green =                   Color (Defined_Colors::Green::Green106, bg_color);
            const Color Asparagus_Green =               Color (Defined_Colors::Green::Green107, bg_color);
            const Color Pistachio_Green =               Color (Defined_Colors::Green::Green112, bg_color);
            const Color Mantis_Green =                  Color (Defined_Colors::Green::Green113, bg_color);
            const Color Pale_Green =                    Color (Defined_Colors::Green::Green114, bg_color);
            const Color Bright_Chartreuse =             Color (Defined_Colors::Green::Green118, bg_color);
            const Color Light_Green =                   Color (Defined_Colors::Green::Green119, bg_color);
            const Color Soft_Green =                    Color (Defined_Colors::Green::Green120, bg_color);
            const Color Mint_Green =                    Color (Defined_Colors::Green::Green121, bg_color);
            const Color Green_Yellow =                  Color (Defined_Colors::Green::Green148, bg_color);
            const Color June_Bud_Green =                Color (Defined_Colors::Green::Green149, bg_color);
            const Color Pastel_Lime =                   Color (Defined_Colors::Green::Green150, bg_color);
            const Color Grayish_Lime_Green =            Color (Defined_Colors::Green::Green151, bg_color);
            const Color Spring_Bud_Green =              Color (Defined_Colors::Green::Green154, bg_color);
            const Color Pastel_Sea_Green =              Color (Defined_Colors::Green::Green155, bg_color);
            const Color Seafoam_Green =                 Color (Defined_Colors::Green::Green156, bg_color);
            const Color Caladon_Green =                 Color (Defined_Colors::Green::Green157, bg_color);
            const Color Tea_Green =                     Color (Defined_Colors::Green::Green193, bg_color);
            const Color Pastel_Green =                  Color (Defined_Colors::Green::Green194, bg_color);
                                
            /// @brief Enables range-based for loops over the Green color range.
            /// @return A const iterator to the first element of `Green_Color_Range`.
            const const_Color_iterator<GreenColorRange> begin() const { return Green_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Green color range.
            /// @return A const iterator one past the last element of `Green_Color_Range`.
            const const_Color_iterator<GreenColorRange> end() const { return Green_Color_Range.end(); }

            /// @brief Retrieves a Green color by index (valid range: 1 – 48) from the `Green_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Green color.
            /// @return A reference to the corresponding `Color` object in `Green_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "G" : "Green"), index, 48);    
                return Green_Color_Range[index]; 
            }

            /// @brief Retrieves a Green color by index (valid range: 1 – 48) from the `Green_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Green color.
            /// @return A reference to the corresponding `Color` object in `Green_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "G" : "Green"), index, 48, true);
                return Green_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Green_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Green_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const GreenColorRange* operator->() const noexcept { return &Green_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_Green ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Green color wrapper containing the Pure_Green escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Green& green) {
                os<< green.Pure_Green;
                return os;
            }
            ~_Green() noexcept = default;
        };

        friend class _Blue;
        /// @brief Defines the primary color Blue in to 2 uniquely named color palettes. 
        class _Blue {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class BlueColorRange {
                friend const_Color_iterator<BlueColorRange>;
                typedef Defined_Colors::Blue BLUE;
                bool short_cut;
            public:
                const Color Blue1;
                const Color Blue2;
                const Color Blue3;
                const Color Blue4;
                const Color Blue5;
                const Color Blue6;
                const Color Blue7;
                const Color Blue8;
                const Color Blue9;
                const Color Blue10;
                const Color Blue11;
                const Color Blue12;
                const Color Blue13;
                const Color Blue14;
                const Color Blue15;
                const Color Blue16;
                const Color Blue17;
                const Color Blue18;
                const Color Blue19;
                const Color Blue20;
                const Color Blue21;
                const Color Blue22;
                const Color Blue23;
                const Color Blue24;
                const Color Blue25;
                const Color Blue26;
                const Color Blue27;
                const Color Blue28;
                const Color Blue29;
                const Color Blue30;
                const Color Blue31;
                const Color Blue32;
                const Color Blue33;
                const Color Blue34;
                BlueColorRange() noexcept = delete;
                BlueColorRange(bool bg_c, bool short_cut) noexcept : short_cut(short_cut), Blue1(BLUE::Blue17, bg_c), Blue2(BLUE::Blue18, bg_c),
                    Blue3(BLUE::Blue19, bg_c), Blue4(BLUE::Blue20, bg_c), Blue5(BLUE::Blue4, bg_c), Blue6(BLUE::Blue21, bg_c), Blue7(BLUE::Blue25, bg_c), 
                    Blue8(BLUE::Blue26, bg_c), Blue9(BLUE::Blue27, bg_c), Blue10(BLUE::Blue60, bg_c), Blue11(BLUE::Blue61, bg_c), Blue12(BLUE::Blue62, bg_c), 
                    Blue13(BLUE::Blue63, bg_c), Blue14(BLUE::Blue32, bg_c), Blue15(BLUE::Blue12, bg_c), Blue16(BLUE::Blue33, bg_c), Blue17(BLUE::Blue67, bg_c), 
                    Blue18(BLUE::Blue68, bg_c), Blue19(BLUE::Blue69, bg_c), Blue20(BLUE::Blue103, bg_c), Blue21(BLUE::Blue38, bg_c), Blue22(BLUE::Blue104, bg_c), 
                    Blue23(BLUE::Blue39, bg_c), Blue24(BLUE::Blue105, bg_c), Blue25(BLUE::Blue74, bg_c), Blue26(BLUE::Blue75, bg_c), Blue27(BLUE::Blue110, bg_c), 
                    Blue28(BLUE::Blue45, bg_c), Blue29(BLUE::Blue111, bg_c), Blue30(BLUE::Blue146, bg_c), Blue31(BLUE::Blue147, bg_c), Blue32(BLUE::Blue81, bg_c), 
                    Blue33(BLUE::Blue153, bg_c), Blue34(BLUE::Blue189, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 34).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "B" : "Blue"), index, 34);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 34).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "B" : "Blue"), index, 34, true);    
                    return this->*(table[--index]);
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<BlueColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 34).
                const const_Color_iterator<BlueColorRange> end() const { return {this, 34}; }
            private:
                inline static const constexpr Color BlueColorRange::* table[34] = {
                    &BlueColorRange::Blue1,
                    &BlueColorRange::Blue2,
                    &BlueColorRange::Blue3,
                    &BlueColorRange::Blue4,
                    &BlueColorRange::Blue5,
                    &BlueColorRange::Blue6,
                    &BlueColorRange::Blue7,
                    &BlueColorRange::Blue8,
                    &BlueColorRange::Blue9,
                    &BlueColorRange::Blue10,
                    &BlueColorRange::Blue11,
                    &BlueColorRange::Blue12,
                    &BlueColorRange::Blue13,
                    &BlueColorRange::Blue14,
                    &BlueColorRange::Blue15,
                    &BlueColorRange::Blue16,
                    &BlueColorRange::Blue17,
                    &BlueColorRange::Blue18,
                    &BlueColorRange::Blue19,
                    &BlueColorRange::Blue20,
                    &BlueColorRange::Blue21,
                    &BlueColorRange::Blue22,
                    &BlueColorRange::Blue23,
                    &BlueColorRange::Blue24,
                    &BlueColorRange::Blue25,
                    &BlueColorRange::Blue26,
                    &BlueColorRange::Blue27,
                    &BlueColorRange::Blue28,
                    &BlueColorRange::Blue29,
                    &BlueColorRange::Blue30,
                    &BlueColorRange::Blue31,
                    &BlueColorRange::Blue32,
                    &BlueColorRange::Blue33,
                    &BlueColorRange::Blue34
                };
            };
            bool bg_color;
            const BlueColorRange Blue_Color_Range;
        public:   
            _Blue() noexcept = delete;
            _Blue(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Blue_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }
            
            const Color std_Blue =                  Color (Defined_Colors::Blue::Blue4, bg_color);
            const Color std_Bright_Blue =           Color (Defined_Colors::Blue::Blue12, bg_color);
            const Color Dark_Navy_Blue =            Color (Defined_Colors::Blue::Blue17, bg_color);
            const Color Deep_Navy_Blue =            Color (Defined_Colors::Blue::Blue18, bg_color);
            const Color Navy_Blue =                 Color (Defined_Colors::Blue::Blue19, bg_color);
            const Color Dark_Blue =                 Color (Defined_Colors::Blue::Blue20, bg_color);
            const Color Deep_Blue =                 Color (Defined_Colors::Blue::Blue21, bg_color);
            const Color Deep_Sky_Blue =             Color (Defined_Colors::Blue::Blue25, bg_color);
            const Color Science_Blue =              Color (Defined_Colors::Blue::Blue26, bg_color);
            const Color Pure_Blue =                 Color (Defined_Colors::Blue::Blue27, bg_color);
            const Color Ocean_Blue =                Color (Defined_Colors::Blue::Blue32, bg_color);
            const Color Vivid_Blue =                Color (Defined_Colors::Blue::Blue33, bg_color);
            const Color Cerulean_Blue =             Color (Defined_Colors::Blue::Blue38, bg_color);
            const Color Azure_Blue =                Color (Defined_Colors::Blue::Blue39, bg_color);
            const Color Vivid_Sky_Blue =            Color (Defined_Colors::Blue::Blue45, bg_color);
            const Color Misty_Slate_Blue =          Color (Defined_Colors::Blue::Blue60, bg_color);
            const Color Comet_Blue =                Color (Defined_Colors::Blue::Blue61, bg_color);
            const Color Slate_Blue =                Color (Defined_Colors::Blue::Blue62, bg_color);
            const Color Bright_Blue =               Color (Defined_Colors::Blue::Blue63, bg_color);
            const Color Lochmara_Blue =             Color (Defined_Colors::Blue::Blue67, bg_color);
            const Color Steel_Blue =                Color (Defined_Colors::Blue::Blue68, bg_color);
            const Color Light_Slate_Blue =          Color (Defined_Colors::Blue::Blue69, bg_color);
            const Color Aegean_Blue =               Color (Defined_Colors::Blue::Blue74, bg_color);
            const Color Iceberg_Blue =              Color (Defined_Colors::Blue::Blue75, bg_color);
            const Color Dusky_Sky_Blue =            Color (Defined_Colors::Blue::Blue81, bg_color);
            const Color Dusky_Cobalt_Blue =         Color (Defined_Colors::Blue::Blue103, bg_color);
            const Color Soft_Indigo_Blue =          Color (Defined_Colors::Blue::Blue104, bg_color);
            const Color Misty_Cornflower_Blue =     Color (Defined_Colors::Blue::Blue105, bg_color);
            const Color Horizon_Blue =              Color (Defined_Colors::Blue::Blue110, bg_color);
            const Color Soft_Sky_Blue =             Color (Defined_Colors::Blue::Blue111, bg_color);
            const Color Light_Pearl_Blue =          Color (Defined_Colors::Blue::Blue146, bg_color);
            const Color Light_Steel_Blue =          Color (Defined_Colors::Blue::Blue147, bg_color);
            const Color Pastel_Blue =               Color (Defined_Colors::Blue::Blue153, bg_color);
            const Color Pale_Blue =                 Color (Defined_Colors::Blue::Blue189, bg_color);
            
            /// @brief Enables range-based for loops over the Blue color range.
            /// @return A const iterator to the first element of `Blue_Color_Range`.
            const const_Color_iterator<BlueColorRange> begin() const { return Blue_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Blue color range.
            /// @return A const iterator one past the last element of `Blue_Color_Range`.
            const const_Color_iterator<BlueColorRange> end() const { return Blue_Color_Range.end(); }
            
            /// @brief Retrieves a Blue color by index (valid range: 1 – 34) from the `Blue_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Blue color.
            /// @return A reference to the corresponding `Color` object in `Blue_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Blue"), index, 34);    
                return Blue_Color_Range[index]; 
            }

            /// @brief Retrieves a Blue color by index (valid range: 1 – 34) from the `Blue_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Blue color.
            /// @return A reference to the corresponding `Color` object in `Blue_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Blue"), index, 34, true);
                return Blue_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Blue_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Blue_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const BlueColorRange* operator->() const noexcept { return &Blue_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_Blue ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Blue color wrapper containing the Pure_Blue escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Blue& blue) {
                os<< blue.Pure_Blue;
                return os;
            }
            ~_Blue() noexcept = default;
        };
        /// @brief Shortcut struct for easy access to ANSI 256 color definitions without typing full names.
        ///        Use 'R' for Red, 'G' for Green, and 'B' for Blue to select the corresponding palette.
        struct ShortCut {
            const _Red R;
            const _Green G;
            const _Blue B;
            ShortCut(bool bg_color) noexcept : R(bg_color, true), G(bg_color, true), B(bg_color, true){};
        };
        const ShortCut short_cut;
    public:
        const _Red Red;
        const _Green Green;
        const _Blue Blue;    
    
        PrimaryColors() noexcept = delete;
        PrimaryColors(bool bg_color) noexcept : short_cut(bg_color), Red(bg_color), Green(bg_color), Blue(bg_color){};
        
        /// @brief Overloads the `operator->()` as a shortcut for easy access to the (`ShortCut`) ANSI 256 palettes.
        ///        Use 'R' for Red, 'G' for Green, and 'B' for Blue instead of their full palette names.
        /// @return A pointer to the internal `short_cut` instance.
        const ShortCut* operator->() const noexcept {
            return &short_cut;
        }
        ~PrimaryColors() noexcept = default;
    };

    /// @brief This class defines the secondary colors: Cyan, Yellow and Purple.
    class SecondaryColors {
        /// @brief Helper method for checking if the given index isn't out of range, else it will throw an instance of 'std::out_of_range' with an appropriate error message.
        /// @param classInstance The class (color palette color) name of the caller method/ operator.
        /// @param index The given index.
        /// @param max_index The maximum index.
        /// @param at True in case the caller is the .at() method. Default = false.
        static void checkForOutOfRange(const std::string& classInstance, uint8_t index, uint8_t max_index, bool at = false){
            auto getOperator = [&classInstance]() -> std::string {
                return (classInstance.length() == 1 ? "->" : ".");
            };
            auto getErrorStart = [=]() -> std::string {
                if(at){
                    return "\nERROR: Illegal index in method 'SecondaryColors"+getOperator()+classInstance+".at("+std::to_string(index)+")'";
                } else {
                    return "\nERROR: Illegal index in operator 'SecondaryColors"+getOperator()+classInstance+"["+std::to_string(index)+"]'";
                }
            };
            if(index > 0 && index <= max_index) return;
            if(index == 0){
                throw std::out_of_range(getErrorStart()+"\n\n\t-Indexing starts at 1 (corresponding to the first color palette name) and aligns with the member color definition names.\n");
            } else {
                throw std::out_of_range(getErrorStart()+"\n\n\t-Your index exceeds the available color range (1 - "+std::to_string(max_index)+")\n");
            }
        }
            
        friend class _Cyan;
        /// @brief Defines the secondary color Cyan in to 2 uniquely named color palettes. 
        class _Cyan {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class CyanColorRange {
                friend const_Color_iterator<CyanColorRange>;
                bool short_cut;
                typedef Defined_Colors::Cyan CYAN;
            public:
                const Color Cyan1;
                const Color Cyan2;
                const Color Cyan3;
                const Color Cyan4;
                const Color Cyan5;
                const Color Cyan6;
                const Color Cyan7;
                const Color Cyan8;
                const Color Cyan9;
                const Color Cyan10;
                const Color Cyan11;
                const Color Cyan12;
                const Color Cyan13;
                const Color Cyan14;
                const Color Cyan15;
                const Color Cyan16;
                const Color Cyan17;
                const Color Cyan18;
                const Color Cyan19;
                const Color Cyan20;
                const Color Cyan21;
                const Color Cyan22;
                const Color Cyan23;
                const Color Cyan24;
                const Color Cyan25;
                const Color Cyan26;
                const Color Cyan27;
                const Color Cyan28;
                CyanColorRange() noexcept = delete;
                CyanColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Cyan1(CYAN::Cyan23, bg_c), Cyan2(CYAN::Cyan24, bg_c), 
                    Cyan3(CYAN::Cyan6, bg_c), Cyan4(CYAN::Cyan30, bg_c), Cyan5(CYAN::Cyan31, bg_c), Cyan6(CYAN::Cyan66, bg_c), Cyan7(CYAN::Cyan36, bg_c), 
                    Cyan8(CYAN::Cyan37, bg_c), Cyan9(CYAN::Cyan73, bg_c), Cyan10(CYAN::Cyan43, bg_c), Cyan11(CYAN::Cyan109, bg_c), Cyan12(CYAN::Cyan44, bg_c), 
                    Cyan13(CYAN::Cyan79, bg_c), Cyan14(CYAN::Cyan14, bg_c), Cyan15(CYAN::Cyan80, bg_c), Cyan16(CYAN::Cyan115, bg_c), Cyan17(CYAN::Cyan50, bg_c), 
                    Cyan18(CYAN::Cyan116, bg_c), Cyan19(CYAN::Cyan51, bg_c), Cyan20(CYAN::Cyan117, bg_c), Cyan21(CYAN::Cyan152, bg_c), Cyan22(CYAN::Cyan86, bg_c), 
                    Cyan23(CYAN::Cyan87, bg_c), Cyan24(CYAN::Cyan122, bg_c), Cyan25(CYAN::Cyan123, bg_c), Cyan26(CYAN::Cyan158, bg_c), Cyan27(CYAN::Cyan159, bg_c), 
                    Cyan28(CYAN::Cyan195, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 28).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "C" : "Cyan"), index, 28);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 28).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "C" : "Cyan"), index, 28, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<CyanColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 28).
                const const_Color_iterator<CyanColorRange> end() const { return {this, 28}; }
            private:
                inline static const constexpr Color CyanColorRange::* table[28] = {
                    &CyanColorRange::Cyan1,
                    &CyanColorRange::Cyan2,
                    &CyanColorRange::Cyan3,
                    &CyanColorRange::Cyan4,
                    &CyanColorRange::Cyan5,
                    &CyanColorRange::Cyan6,
                    &CyanColorRange::Cyan7,
                    &CyanColorRange::Cyan8,
                    &CyanColorRange::Cyan9,
                    &CyanColorRange::Cyan10,
                    &CyanColorRange::Cyan11,
                    &CyanColorRange::Cyan12,
                    &CyanColorRange::Cyan13,
                    &CyanColorRange::Cyan14,
                    &CyanColorRange::Cyan15,
                    &CyanColorRange::Cyan16,
                    &CyanColorRange::Cyan17,
                    &CyanColorRange::Cyan18,
                    &CyanColorRange::Cyan19,
                    &CyanColorRange::Cyan20,
                    &CyanColorRange::Cyan21,
                    &CyanColorRange::Cyan22,
                    &CyanColorRange::Cyan23,
                    &CyanColorRange::Cyan24,
                    &CyanColorRange::Cyan25,
                    &CyanColorRange::Cyan26,
                    &CyanColorRange::Cyan27,
                    &CyanColorRange::Cyan28
                };
            };
            CyanColorRange Cyan_Color_Range;
            bool bg_color;
        public:
            _Cyan() noexcept = delete;
            _Cyan(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Cyan_Color_Range(bg_color, short_cut) {
                this->short_cut = short_cut;
            }

            const Color std_Cyan =                  Color (Defined_Colors::Cyan::Cyan6, bg_color);
            const Color std_Bright_Cyan =           Color (Defined_Colors::Cyan::Cyan14, bg_color);
            const Color Dark_Cyan =                 Color (Defined_Colors::Cyan::Cyan23, bg_color);
            const Color Deep_Cyan =                 Color (Defined_Colors::Cyan::Cyan24, bg_color);
            const Color Dark_Turquoise =            Color (Defined_Colors::Cyan::Cyan30, bg_color);
            const Color Medium_Turquoise =          Color (Defined_Colors::Cyan::Cyan31, bg_color);
            const Color Rich_Cyan =                 Color (Defined_Colors::Cyan::Cyan36, bg_color);
            const Color Tiffany_Cyan =              Color (Defined_Colors::Cyan::Cyan37, bg_color);
            const Color Lagoon_Cyan =               Color (Defined_Colors::Cyan::Cyan43, bg_color);
            const Color Vibrant_Turquoise =         Color (Defined_Colors::Cyan::Cyan44, bg_color);
            const Color Pure_Cyan =                 Color (Defined_Colors::Cyan::Cyan50, bg_color);
            const Color Aqua_Cyan =                 Color (Defined_Colors::Cyan::Cyan51, bg_color);
            const Color Juniper_Cyan =              Color (Defined_Colors::Cyan::Cyan66, bg_color);
            const Color Harbor_Cyan =               Color (Defined_Colors::Cyan::Cyan73, bg_color);
            const Color Myrtle_Cyan =               Color (Defined_Colors::Cyan::Cyan79, bg_color);
            const Color Tidewater_Cyan =            Color (Defined_Colors::Cyan::Cyan80, bg_color);
            const Color Reef_Cyan =                 Color (Defined_Colors::Cyan::Cyan86, bg_color);
            const Color Frost_Cyan =                Color (Defined_Colors::Cyan::Cyan87, bg_color);
            const Color Pewter_Cyan =               Color (Defined_Colors::Cyan::Cyan109, bg_color);
            const Color Sage_Cyan =                 Color (Defined_Colors::Cyan::Cyan115, bg_color);
            const Color Bermuda_Cyan =              Color (Defined_Colors::Cyan::Cyan116, bg_color);
            const Color Morning_Mist_Cyan =         Color (Defined_Colors::Cyan::Cyan117, bg_color);
            const Color Aquamarine_Cyan =           Color (Defined_Colors::Cyan::Cyan122, bg_color);
            const Color Opal_Cyan =                 Color (Defined_Colors::Cyan::Cyan123, bg_color);
            const Color Shallows_Cyan =             Color (Defined_Colors::Cyan::Cyan152, bg_color);
            const Color Algae_Cyan =                Color (Defined_Colors::Cyan::Cyan158, bg_color);
            const Color Glacier_Cyan =              Color (Defined_Colors::Cyan::Cyan159, bg_color);
            const Color Ebb_Tide_Cyan =             Color (Defined_Colors::Cyan::Cyan195, bg_color);

            /// @brief Enables range-based for loops over the Cyan color range.
            /// @return A const iterator to the first element of `Cyan_Color_Range`.
            const const_Color_iterator<CyanColorRange> begin() const { return Cyan_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Cyan color range.
            /// @return A const iterator one past the last element of `Cyan_Color_Range`.
            const const_Color_iterator<CyanColorRange> end() const { return Cyan_Color_Range.end(); }

            /// @brief Retrieves a Cyan color by index (valid range: 1 – 28) from the `Cyan_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Cyan color.
            /// @return A reference to the corresponding `Color` object in `Cyan_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "C" : "Cyan"), index, 28);    
                return Cyan_Color_Range[index]; 
            }

            /// @brief Retrieves a Cyan color by index (valid range: 1 – 28) from the `Cyan_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Cyan color.
            /// @return A reference to the corresponding `Color` object in `Cyan_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "C" : "Cyan"), index, 28, true);
                return Cyan_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Cyan_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Cyan_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const CyanColorRange* operator->() const noexcept { return &Cyan_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_Cyan ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Cyan color wrapper containing the Pure_Cyan escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Cyan& cyan) {
                os<< cyan.Pure_Cyan;
                return os;
            }
            ~_Cyan() noexcept = default;
        };

        friend class _Yellow;
        /// @brief Defines the Secondary color Yellow in to 2 uniquely named color palettes. 
        class _Yellow {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class YellowColorRange {
                friend const_Color_iterator<YellowColorRange>;
                typedef Defined_Colors::Yellow YELLOW;
                bool short_cut;
            public:
                const Color Yellow1;
                const Color Yellow2;
                const Color Yellow3;
                const Color Yellow4;
                const Color Yellow5;
                const Color Yellow6;
                const Color Yellow7;
                const Color Yellow8;
                const Color Yellow9;
                const Color Yellow10;
                const Color Yellow11;
                const Color Yellow12;
                const Color Yellow13;
                const Color Yellow14;
                const Color Yellow15;
                const Color Yellow16;
                const Color Yellow17;
                const Color Yellow18;
                const Color Yellow19;
                const Color Yellow20;
                const Color Yellow21;
                const Color Yellow22;
                YellowColorRange() noexcept = delete;
                YellowColorRange(bool bg_c, bool short_cut) noexcept : short_cut(short_cut), Yellow1(YELLOW::Yellow100, bg_c), Yellow2(YELLOW::Yellow3, bg_c), 
                    Yellow3(YELLOW::Yellow142, bg_c), Yellow4(YELLOW::Yellow143, bg_c), Yellow5(YELLOW::Yellow178, bg_c), Yellow6(YELLOW::Yellow144, bg_c), Yellow7(YELLOW::Yellow184, bg_c), 
                    Yellow8(YELLOW::Yellow185, bg_c), Yellow9(YELLOW::Yellow220, bg_c), Yellow10(YELLOW::Yellow186, bg_c), Yellow11(YELLOW::Yellow187, bg_c), Yellow12(YELLOW::Yellow221, bg_c), 
                    Yellow13(YELLOW::Yellow222, bg_c), Yellow14(YELLOW::Yellow190, bg_c), Yellow15(YELLOW::Yellow191, bg_c), Yellow16(YELLOW::Yellow11, bg_c), Yellow17(YELLOW::Yellow226, bg_c), 
                    Yellow18(YELLOW::Yellow192, bg_c), Yellow19(YELLOW::Yellow227, bg_c), Yellow20(YELLOW::Yellow228, bg_c), Yellow21(YELLOW::Yellow229, bg_c), Yellow22(YELLOW::Yellow230, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "Y" : "Yellow"), index, 22);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "Y" : "Yellow"), index, 22, true);
                    return this->*(table[--index]);
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<YellowColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 22).
                const const_Color_iterator<YellowColorRange> end() const { return {this, 22}; }
            private:
                inline static const constexpr Color YellowColorRange::* table[22] = {
                    &YellowColorRange::Yellow1,
                    &YellowColorRange::Yellow2,
                    &YellowColorRange::Yellow3,
                    &YellowColorRange::Yellow4,
                    &YellowColorRange::Yellow5,
                    &YellowColorRange::Yellow6,
                    &YellowColorRange::Yellow7,
                    &YellowColorRange::Yellow8,
                    &YellowColorRange::Yellow9,
                    &YellowColorRange::Yellow10,
                    &YellowColorRange::Yellow11,
                    &YellowColorRange::Yellow12,
                    &YellowColorRange::Yellow13,
                    &YellowColorRange::Yellow14,
                    &YellowColorRange::Yellow15,
                    &YellowColorRange::Yellow16,
                    &YellowColorRange::Yellow17,
                    &YellowColorRange::Yellow18,
                    &YellowColorRange::Yellow19,
                    &YellowColorRange::Yellow20,
                    &YellowColorRange::Yellow21,
                    &YellowColorRange::Yellow22
                };
            };
            const YellowColorRange Yellow_Color_Range;
            bool bg_color;
        public:
            _Yellow() noexcept = delete;
            _Yellow(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Yellow_Color_Range(bg_color, short_cut) {
                this->short_cut = short_cut;
            }
            
            const Color std_Yellow =            Color (Defined_Colors::Yellow::Yellow3, bg_color);
            const Color std_Bright_Yellow =     Color (Defined_Colors::Yellow::Yellow11 , bg_color);
            const Color Mustard_Yellow =        Color (Defined_Colors::Yellow::Yellow100, bg_color);
            const Color Light_Gold =            Color (Defined_Colors::Yellow::Yellow142, bg_color);
            const Color Dark_Khaki =            Color (Defined_Colors::Yellow::Yellow143, bg_color);
            const Color Light_Khaki =           Color (Defined_Colors::Yellow::Yellow144, bg_color);
            const Color Deep_Yellow =           Color (Defined_Colors::Yellow::Yellow178, bg_color);
            const Color Strong_Yellow =         Color (Defined_Colors::Yellow::Yellow184, bg_color);
            const Color Mellow_Yellow =         Color (Defined_Colors::Yellow::Yellow185, bg_color);
            const Color Muted_Yellow =          Color (Defined_Colors::Yellow::Yellow186, bg_color);
            const Color Soft_Yellow =           Color (Defined_Colors::Yellow::Yellow187, bg_color);
            const Color Neon_Yellow =           Color (Defined_Colors::Yellow::Yellow190, bg_color);
            const Color Bright_Lemon =          Color (Defined_Colors::Yellow::Yellow191, bg_color);
            const Color Lemon_Lime =            Color (Defined_Colors::Yellow::Yellow192, bg_color);
            const Color Amber =                 Color (Defined_Colors::Yellow::Yellow220, bg_color);
            const Color Honey_Yellow =          Color (Defined_Colors::Yellow::Yellow221, bg_color);
            const Color Marigold_Yellow =       Color (Defined_Colors::Yellow::Yellow222, bg_color);
            const Color Pure_Yellow =           Color (Defined_Colors::Yellow::Yellow226, bg_color);
            const Color Golden_Yellow =         Color (Defined_Colors::Yellow::Yellow227, bg_color);
            const Color Pastel_Yellow =         Color (Defined_Colors::Yellow::Yellow228, bg_color);
            const Color Light_Yellow =          Color (Defined_Colors::Yellow::Yellow229, bg_color);
            const Color Pale_Yellow =           Color (Defined_Colors::Yellow::Yellow230, bg_color);

            /// @brief Enables range-based for loops over the Yellow color range.
            /// @return A const iterator to the first element of `Yellow_Color_Range`.
            const const_Color_iterator<YellowColorRange> begin() const { return Yellow_Color_Range.begin(); }
            
            /// @brief Enables range-based for loops over the Yellow color range.
            /// @return A const iterator one past the last element of `Yellow_Color_Range`.
            const const_Color_iterator<YellowColorRange> end() const { return Yellow_Color_Range.end(); }

            /// @brief Retrieves a Yellow color by index (valid range: 1 – 22) from the `Yellow_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Yellow color.
            /// @return A reference to the corresponding `Color` object in `Yellow_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "Y" : "Yellow"), index, 22);
                return Yellow_Color_Range[index]; 
            }

            /// @brief Retrieves a Yellow color by index (valid range: 1 – 22) from the `Yellow_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Yellow color.
            /// @return A reference to the corresponding `Color` object in `Yellow_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "Y" : "Yellow"), index, 22, true);    
                return Yellow_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Yellow_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Yellow_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const YellowColorRange* operator->() const noexcept { return &Yellow_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_Yellow ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Yellow color wrapper containing the Pure_Yellow escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Yellow& yellow) {
                os<< yellow.Pure_Yellow;
                return os;
            }
            ~_Yellow() noexcept = default;
        };

        friend class _Purple;
        /// @brief Defines the secondary color Purple in to 2 uniquely named color palettes. 
        class _Purple {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class PurpleColorRange {
                friend const_Color_iterator<PurpleColorRange>;
                bool short_cut;
                typedef Defined_Colors::Purple PURPLE;
            public:
                const Color Purple1;
                const Color Purple2;
                const Color Purple3;
                const Color Purple4;
                const Color Purple5;
                const Color Purple6;
                const Color Purple7;
                const Color Purple8;
                const Color Purple9;
                const Color Purple10;
                const Color Purple11;
                const Color Purple12;
                const Color Purple13;
                const Color Purple14;
                const Color Purple15;
                const Color Purple16;
                const Color Purple17;
                const Color Purple18;
                const Color Purple19;
                const Color Purple20;
                const Color Purple21;
                const Color Purple22;
                PurpleColorRange() noexcept = delete;
                PurpleColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Purple1(PURPLE::Purple53, bg_c), Purple2(PURPLE::Purple90, bg_c), 
                    Purple3(PURPLE::Purple5, bg_c), Purple4(PURPLE::Purple91, bg_c), Purple5(PURPLE::Purple126, bg_c), Purple6(PURPLE::Purple127, bg_c), Purple7(PURPLE::Purple128, bg_c), 
                    Purple8(PURPLE::Purple129, bg_c), Purple9(PURPLE::Purple164, bg_c), Purple10(PURPLE::Purple165, bg_c), Purple11(PURPLE::Purple201, bg_c), Purple12(PURPLE::Purple96, bg_c), 
                    Purple13(PURPLE::Purple133, bg_c), Purple14(PURPLE::Purple134, bg_c), Purple15(PURPLE::Purple170, bg_c), Purple16(PURPLE::Purple171, bg_c), Purple17(PURPLE::Purple207, bg_c), 
                    Purple18(PURPLE::Purple139, bg_c), Purple19(PURPLE::Purple176, bg_c), Purple20(PURPLE::Purple213, bg_c), Purple21(PURPLE::Purple219, bg_c), Purple22(PURPLE::Purple225, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "P" : "Purple"), index, 22);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "P" : "Purple"), index, 22, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<PurpleColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 22).
                const const_Color_iterator<PurpleColorRange> end() const { return {this, 22}; } 
            private:
                inline static const constexpr Color PurpleColorRange::* table[22] = {
                    &PurpleColorRange::Purple1,
                    &PurpleColorRange::Purple2,
                    &PurpleColorRange::Purple3,
                    &PurpleColorRange::Purple4,
                    &PurpleColorRange::Purple5,
                    &PurpleColorRange::Purple6,
                    &PurpleColorRange::Purple7,
                    &PurpleColorRange::Purple8,
                    &PurpleColorRange::Purple9,
                    &PurpleColorRange::Purple10,
                    &PurpleColorRange::Purple11,
                    &PurpleColorRange::Purple12,
                    &PurpleColorRange::Purple13,
                    &PurpleColorRange::Purple14,
                    &PurpleColorRange::Purple15,
                    &PurpleColorRange::Purple16,
                    &PurpleColorRange::Purple17,
                    &PurpleColorRange::Purple18,
                    &PurpleColorRange::Purple19,
                    &PurpleColorRange::Purple20,
                    &PurpleColorRange::Purple21,
                    &PurpleColorRange::Purple22
                };
            };
            PurpleColorRange Purple_Color_Range;
            bool bg_color;
        public:
            _Purple() noexcept = delete;
            _Purple(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Purple_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_Purple =                Color (Defined_Colors::Purple::Purple5, bg_color);
            const Color Imperial_Purple =           Color (Defined_Colors::Purple::Purple53, bg_color);
            const Color Velvet_Plum_Purple =        Color (Defined_Colors::Purple::Purple90, bg_color);
            const Color Mystic_Amethyst_Purple =    Color (Defined_Colors::Purple::Purple91, bg_color);
            const Color Smokey_Orchid_Purple =      Color (Defined_Colors::Purple::Purple96, bg_color);
            const Color Velvet_Magenta_Purple =     Color (Defined_Colors::Purple::Purple126, bg_color);
            const Color Heliotrope_Purple =         Color (Defined_Colors::Purple::Purple127, bg_color);
            const Color Orchid_Purple =             Color (Defined_Colors::Purple::Purple128, bg_color);
            const Color Fuchsia_Purple =            Color (Defined_Colors::Purple::Purple129, bg_color);
            const Color Lilac_Purple =              Color (Defined_Colors::Purple::Purple133, bg_color);
            const Color Heather_Purple =            Color (Defined_Colors::Purple::Purple134, bg_color);
            const Color Mauve_Purple =              Color (Defined_Colors::Purple::Purple139, bg_color);
            const Color Electric_Fuchsia_Purple =   Color (Defined_Colors::Purple::Purple164, bg_color);
            const Color Orchid_Magenta_Purple =     Color (Defined_Colors::Purple::Purple165, bg_color);
            const Color Light_Magenta_Purple =      Color (Defined_Colors::Purple::Purple170, bg_color);
            const Color Haze_Purple =               Color (Defined_Colors::Purple::Purple171, bg_color);
            const Color Pastel_Orchid_Purple =      Color (Defined_Colors::Purple::Purple176, bg_color);
            const Color Radiant_Amethyst_Purple =   Color (Defined_Colors::Purple::Purple201, bg_color);
            const Color Pastel_Fuchsia_Purple =     Color (Defined_Colors::Purple::Purple207, bg_color);
            const Color Cotton_Candy_Purple =       Color (Defined_Colors::Purple::Purple213, bg_color);
            const Color Pastel_Plum_Purple =        Color (Defined_Colors::Purple::Purple219, bg_color);

            /// @brief Enables range-based for loops over the Purple color range.
            /// @return A const iterator to the first element of `Purple_Color_Range`.
            const const_Color_iterator<PurpleColorRange> begin() const { return Purple_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Purple color range.
            /// @return A const iterator one past the last element of `Purple_Color_Range`.
            const const_Color_iterator<PurpleColorRange> end() const { return Purple_Color_Range.end(); }

            /// @brief Retrieves a Purple color by index (valid range: 1 – 22) from the `Purple_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Purple color.
            /// @return A reference to the corresponding `Color` object in `Purple_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "P" : "Purple"), index, 22);    
                return Purple_Color_Range[index]; 
            }

            /// @brief Retrieves a Purple color by index (valid range: 1 – 22) from the `Purple_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Purple color.
            /// @return A reference to the corresponding `Color` object in `Purple_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "P" : "Purple"), index, 22, true);
                return Purple_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Purple_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Purple_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const PurpleColorRange* operator->() const noexcept { return &Purple_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Fuchsia_Purple ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Purple color wrapper containing the Fuchsia_Purple escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Purple& purple) {
                os<< purple.Fuchsia_Purple;
                return os;
            }
            ~_Purple() noexcept = default;
        };
        /// @brief Shortcut struct for easy access to ANSI 256 color definitions without typing full names.
        ///        Use 'C' for Cyan, 'Y' for Yellow, and 'P' for Purple to select the corresponding palette.
        struct ShortCut {
            _Cyan C;
            _Yellow Y;
            _Purple P;
            ShortCut(bool bg_color) noexcept : C(bg_color, true), Y(bg_color, true), P(bg_color, true){};
        };
        const ShortCut short_cut;
    public:
        _Cyan Cyan;
        _Yellow Yellow;
        _Purple Purple;

        SecondaryColors() noexcept = delete;
        SecondaryColors(bool bg_color) noexcept : short_cut(bg_color), Cyan(bg_color), Yellow(bg_color), Purple(bg_color){};
        
        /// @brief Overloads the `operator->()` as a shortcut for easy access to the (`ShortCut`) ANSI 256 palettes.
        ///        Use 'C' for Cyan, 'Y' for Yellow, and 'P' for Purple instead of their full palette names.
        /// @return A pointer to the internal `short_cut` instance.
        const ShortCut* operator->() const noexcept {
            return &short_cut;
        }
        ~SecondaryColors() noexcept = default;
    };

    /// @brief This class defines the Tertiary colors ('catch all' for all colors that are not primary- or secondary colors): Orange, Brown, Violet and Pink.
    class TertiaryColors {
        /// @brief Helper method for checking if the given index isn't out of range, else it will throw an instance of 'std::out_of_range' with an appropriate error message.
        /// @param classInstance The class (color palette color) name of the caller method/ operator.
        /// @param index The given index.
        /// @param max_index The maximum index.
        /// @param at True in case the caller is the .at() method. Default = false.
        static void checkForOutOfRange(const std::string& classInstance, uint8_t index, uint8_t max_index, bool at = false){
            auto getOperator = [&classInstance]() -> std::string {
                return (classInstance.length() == 1 ? "->" : ".");
            };
            auto getErrorStart = [=]() -> std::string {
                if(at){
                    return "\nERROR: Illegal index in method 'TertiaryColors"+getOperator()+classInstance+".at("+std::to_string(index)+")'";
                } else {
                    return "\nERROR: Illegal index in operator 'TertiaryColors"+getOperator()+classInstance+"["+std::to_string(index)+"]'";
                }
            };
            if(index > 0 && index <= max_index) return;
            if(index == 0){
                throw std::out_of_range(getErrorStart()+"\n\n\t-Indexing starts at 1 (corresponding to the first color palette name) and aligns with the member color definition names.\n");
            } else {
                throw std::out_of_range(getErrorStart()+"\n\n\t-Your index exceeds the available color range (1 - "+std::to_string(max_index)+")\n");
            }
        }

        friend class _Orange;
        /// @brief Defines the Tertiary color Orange in to 2 uniquely named color palettes. 
        class _Orange {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class OrangeColorRange {
                friend const_Color_iterator<OrangeColorRange>;
                typedef Defined_Colors::Orange ORANGE;
                bool short_cut;
            public:
                const Color Orange1;
                const Color Orange2;
                const Color Orange3;
                const Color Orange4;
                const Color Orange5;
                const Color Orange6;
                const Color Orange7;
                const Color Orange8;
                const Color Orange9;
                OrangeColorRange() noexcept = delete;
                OrangeColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Orange1(ORANGE::Orange130, bg_c), Orange2(ORANGE::Orange166, bg_c), 
                    Orange3(ORANGE::Orange202, bg_c), Orange4(ORANGE::Orange172, bg_c), Orange5(ORANGE::Orange208, bg_c), Orange6(ORANGE::Orange209, bg_c), Orange7(ORANGE::Orange214, bg_c), 
                    Orange8(ORANGE::Orange215, bg_c), Orange9(ORANGE::Orange216, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 9).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "O" : "Orange"), index, 9);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 9).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "O" : "Orange"), index, 9, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<OrangeColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 9).
                const const_Color_iterator<OrangeColorRange> end() const { return {this, 9}; }
            private:
                inline static const constexpr Color OrangeColorRange::* table[9] = {
                    &OrangeColorRange::Orange1,
                    &OrangeColorRange::Orange2,
                    &OrangeColorRange::Orange3,
                    &OrangeColorRange::Orange4,
                    &OrangeColorRange::Orange5,
                    &OrangeColorRange::Orange6,
                    &OrangeColorRange::Orange7,
                    &OrangeColorRange::Orange8,
                    &OrangeColorRange::Orange9
                };
            };
            const OrangeColorRange Orange_Color_Range;
            bool bg_color;
        public:
            _Orange() noexcept = delete;
            _Orange(bool bg_color, bool short_cut = false) : bg_color(bg_color), Orange_Color_Range(bg_color, short_cut) {
                this->short_cut = short_cut;
            }

            const Color Dark_Orange =               Color (Defined_Colors::Orange::Orange130, bg_color);
            const Color Strong_Orange =             Color (Defined_Colors::Orange::Orange166, bg_color); 
            const Color Burnt_Orange =              Color (Defined_Colors::Orange::Orange172, bg_color);       
            const Color Pure_Orange =               Color (Defined_Colors::Orange::Orange202, bg_color);        
            const Color Amber =                     Color (Defined_Colors::Orange::Orange208, bg_color);        
            const Color Coral_Orange =              Color (Defined_Colors::Orange::Orange209, bg_color);        
            const Color Golden_Orange =             Color (Defined_Colors::Orange::Orange214, bg_color);        
            const Color Sandy_Orange =              Color (Defined_Colors::Orange::Orange215, bg_color);      

            /// @brief Enables range-based for loops over the Orange color range.
            /// @return A const iterator to the first element of `Orange_Color_Range`. 
            const const_Color_iterator<OrangeColorRange> begin() const { return Orange_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Orange color range.
            /// @return A const iterator one past the last element of `Orange_Color_Range`.
            const const_Color_iterator<OrangeColorRange> end() const { return Orange_Color_Range.end(); }

            /// @brief Retrieves a Orange color by index (valid range: 1 – 9) from the `Orange_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Orange color.
            /// @return A reference to the corresponding `Color` object in `Orange_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "O" : "Orange"), index, 9);    
                return Orange_Color_Range[index]; 
            }
            
            /// @brief Retrieves a Orange color by index (valid range: 1 – 9) from the `Orange_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Orange color.
            /// @return A reference to the corresponding `Color` object in `Orange_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "O" : "Orange"), index, 9, true);
                return Orange_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Orange_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Orange_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const OrangeColorRange* operator->() const noexcept { return &Orange_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_Orange ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Orange color wrapper containing the Pure_Orange escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Orange& orange) {
                os<< orange.Pure_Orange;
                return os;
            }
            ~_Orange() noexcept = default;
        };

        friend class _Brown;
        /// @brief Defines the Tertiary color Brown in to 2 uniquely named color palettes. 
        class _Brown {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class BrownColorRange {
                friend const_Color_iterator<BrownColorRange>;
                bool short_cut;
                typedef Defined_Colors::Brown BROWN;
            public:
                const Color Brown1;
                const Color Brown2;
                const Color Brown3;
                const Color Brown4;
                const Color Brown5;
                const Color Brown6;
                const Color Brown7;
                const Color Brown8;
                const Color Brown9;
                const Color Brown10;
                const Color Brown11;
                BrownColorRange() noexcept = delete;
                BrownColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Brown1(BROWN::Brown94, bg_c), Brown2(BROWN::Brown95, bg_c), 
                    Brown3(BROWN::Brown131, bg_c), Brown4(BROWN::Brown136, bg_c), Brown5(BROWN::Brown137, bg_c), Brown6(BROWN::Brown138, bg_c), Brown7(BROWN::Brown173, bg_c), 
                    Brown8(BROWN::Brown179, bg_c), Brown9(BROWN::Brown180, bg_c), Brown10(BROWN::Brown181, bg_c), Brown11(BROWN::Brown223, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 11).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "B" : "Brown"), index, 11);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 11).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "B" : "Brown"), index, 11, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<BrownColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 11).
                const const_Color_iterator<BrownColorRange> end() const { return {this, 11}; }
            private:
                inline static const constexpr Color BrownColorRange::* table[11] = {
                    &BrownColorRange::Brown1,
                    &BrownColorRange::Brown2,
                    &BrownColorRange::Brown3,
                    &BrownColorRange::Brown4,
                    &BrownColorRange::Brown5,
                    &BrownColorRange::Brown6,
                    &BrownColorRange::Brown7,
                    &BrownColorRange::Brown8,
                    &BrownColorRange::Brown9,
                    &BrownColorRange::Brown10,
                    &BrownColorRange::Brown11
                };
            };
            BrownColorRange Brown_Color_Range;
            bool bg_color;
        public:
            _Brown() noexcept = delete;
            _Brown(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Brown_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }
            
            const Color Russet_Brown =              Color (Defined_Colors::Brown::Brown94, bg_color);
            const Color Brick_Rose_Brown =          Color (Defined_Colors::Brown::Brown95, bg_color);
            const Color Chestnut_Brown =            Color (Defined_Colors::Brown::Brown131, bg_color);
            const Color Dark_Goldenrod_Brown =      Color (Defined_Colors::Brown::Brown136, bg_color);
            const Color Desert_Sand_Brown =         Color (Defined_Colors::Brown::Brown137, bg_color);
            const Color Dusty_Taupe_Brown =         Color (Defined_Colors::Brown::Brown138, bg_color);
            const Color Copperfield_Brown =         Color (Defined_Colors::Brown::Brown173, bg_color);
            const Color Sandstone_Brown =           Color (Defined_Colors::Brown::Brown179, bg_color);
            const Color Light_Sandstone_Brown =     Color (Defined_Colors::Brown::Brown180, bg_color);
            const Color Pale_Chestnut_Brown =       Color (Defined_Colors::Brown::Brown181, bg_color);
            const Color Pastel_Moccasin_Brown =     Color (Defined_Colors::Brown::Brown223, bg_color);
            
            /// @brief Enables range-based for loops over the Brown color range.
            /// @return A const iterator to the first element of `Brown_Color_Range`.
            const const_Color_iterator<BrownColorRange> begin() const { return Brown_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Brown color range.
            /// @return A const iterator one past the last element of `Brown_Color_Range`.
            const const_Color_iterator<BrownColorRange> end() const { return Brown_Color_Range.end(); }

            /// @brief Retrieves a Brown color by index (valid range: 1 – 11) from the `Brown_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Brown color.
            /// @return A reference to the corresponding `Color` object in `Brown_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Brown"), index, 11);    
                return Brown_Color_Range[index]; 
            }

            /// @brief Retrieves a Brown color by index (valid range: 1 – 11) from the `Brown_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Brown color.
            /// @return A reference to the corresponding `Color` object in `Brown_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Brown"), index, 11, true);
                return Brown_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Brown_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Brown_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const BrownColorRange* operator->() const noexcept { return &Brown_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Russet_Brown ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Brown color wrapper containing the Russet_Brown escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Brown& brown) {
                os<< brown.Russet_Brown;
                return os;
            }
            ~_Brown() noexcept = default;
        };

        friend class _Violet;
        /// @brief Defines the Tertiary color Violet in to 2 uniquely named color palettes. 
        class _Violet {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class VioletColorRange {
                friend const_Color_iterator<VioletColorRange>;
                bool short_cut;
                typedef Defined_Colors::Violet VIOLET;
            public:
                const Color Violet1;
                const Color Violet2;
                const Color Violet3;
                const Color Violet4;
                const Color Violet5;
                const Color Violet6;
                const Color Violet7;
                const Color Violet8;
                const Color Violet9;
                const Color Violet10;
                const Color Violet11;
                const Color Violet12;
                const Color Violet13;
                const Color Violet14;
                const Color Violet15;
                VioletColorRange() noexcept = delete;
                VioletColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Violet1(VIOLET::Violet54, bg_c), Violet2(VIOLET::Violet55, bg_c), 
                    Violet3(VIOLET::Violet56, bg_c), Violet4(VIOLET::Violet57, bg_c), Violet5(VIOLET::Violet92, bg_c), Violet6(VIOLET::Violet93, bg_c), Violet7(VIOLET::Violet97, bg_c), 
                    Violet8(VIOLET::Violet98, bg_c), Violet9(VIOLET::Violet99, bg_c), Violet10(VIOLET::Violet135, bg_c), Violet11(VIOLET::Violet140, bg_c), Violet12(VIOLET::Violet141, bg_c), 
                    Violet13(VIOLET::Violet177, bg_c), Violet14(VIOLET::Violet182, bg_c), Violet15(VIOLET::Violet183, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 15).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "V" : "Violet"), index, 15);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 15).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "V" : "Violet"), index, 15, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<VioletColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 15).
                const const_Color_iterator<VioletColorRange> end() const { return {this, 15}; }
            private:
                inline static const constexpr Color VioletColorRange::* table[15] = {
                    &VioletColorRange::Violet1,
                    &VioletColorRange::Violet2,
                    &VioletColorRange::Violet3,
                    &VioletColorRange::Violet4,
                    &VioletColorRange::Violet5,
                    &VioletColorRange::Violet6,
                    &VioletColorRange::Violet7,
                    &VioletColorRange::Violet8,
                    &VioletColorRange::Violet9,
                    &VioletColorRange::Violet10,
                    &VioletColorRange::Violet11,
                    &VioletColorRange::Violet12,
                    &VioletColorRange::Violet13,
                    &VioletColorRange::Violet14,
                    &VioletColorRange::Violet15
                };
            };
            VioletColorRange Violet_Color_Range;
            bool bg_color;
        public:
            _Violet() noexcept = delete;
            _Violet(bool bg_color, bool short_cut = false) : bg_color(bg_color), Violet_Color_Range(bg_color, short_cut) {
                this->short_cut = short_cut;
            }

            const Color Deep_Orchid_Violet =        Color (Defined_Colors::Violet::Violet54, bg_color);
            const Color Amethyst_Violet =           Color (Defined_Colors::Violet::Violet55, bg_color);
            const Color Orchid_Violet =             Color (Defined_Colors::Violet::Violet56, bg_color);
            const Color Blue_Violet =               Color (Defined_Colors::Violet::Violet57, bg_color);
            const Color Strong_Violet =             Color (Defined_Colors::Violet::Violet92, bg_color);
            const Color Electric_Violet =           Color (Defined_Colors::Violet::Violet93, bg_color);
            const Color Smokey_Amethyst_Violet =    Color (Defined_Colors::Violet::Violet97, bg_color);
            const Color Dusty_Lavender_Violet =     Color (Defined_Colors::Violet::Violet98, bg_color);
            const Color Munstead_Violet =           Color (Defined_Colors::Violet::Violet99, bg_color);
            const Color Light_Violet =              Color (Defined_Colors::Violet::Violet135, bg_color);
            const Color Hazy_Lilac_Violet =         Color (Defined_Colors::Violet::Violet140, bg_color);
            const Color Lavender_Violet =           Color (Defined_Colors::Violet::Violet141, bg_color);
            const Color Misty_Lavender_Violet =     Color (Defined_Colors::Violet::Violet177, bg_color);
            const Color Frosted_Lavender_Violet =   Color (Defined_Colors::Violet::Violet182, bg_color);
            const Color Pearl_Violet =              Color (Defined_Colors::Violet::Violet183, bg_color);

            /// @brief Enables range-based for loops over the Violet color range.
            /// @return A const iterator to the first element of `Violet_Color_Range`.
            const const_Color_iterator<VioletColorRange> begin() const { return Violet_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Violet color range.
            /// @return A const iterator one past the last element of `Violet_Color_Range`.
            const const_Color_iterator<VioletColorRange> end() const { return Violet_Color_Range.end(); }

            /// @brief Retrieves a Violet color by index (valid range: 1 – 15) from the `Violet_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Violet color.
            /// @return A reference to the corresponding `Color` object in `Violet_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "V" : "Violet"), index, 15);    
                return Violet_Color_Range[index]; 
            }

            /// @brief Retrieves a Violet color by index (valid range: 1 – 15) from the `Violet_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Violet color.
            /// @return A reference to the corresponding `Color` object in `Violet_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "V" : "Violet"), index, 15, true);
                return Violet_Color_Range.at(index); 
            }
            
            /// @brief Overload of `operator->()` to access the secondary color palette (`Violet_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Violet_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const VioletColorRange* operator->() const noexcept { return &Violet_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Blue_Violet ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Violet color wrapper containing the Blue_Violet escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Violet& violet) {
                os<< violet.Blue_Violet;
                return os;
            }
            ~_Violet() noexcept = default;
        };

        friend class _Pink;
        /// @brief Defines the Tertiary color Pink in to 2 uniquely named color palettes. 
        class _Pink {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class PinkColorRange {
                friend const_Color_iterator<PinkColorRange>;
                bool short_cut;
                typedef Defined_Colors::Pink PINK;
            public:
                const Color Pink1;
                const Color Pink2;
                const Color Pink3;
                const Color Pink4;
                const Color Pink5;
                const Color Pink6;
                const Color Pink7;
                const Color Pink8;
                const Color Pink9;
                const Color Pink10;
                const Color Pink11;
                const Color Pink12;
                const Color Pink13;
                const Color Pink14;
                const Color Pink15;
                const Color Pink16;
                const Color Pink17;
                const Color Pink18;
                const Color Pink19;
                const Color Pink20;
                const Color Pink21;            
                const Color Pink22;            
                PinkColorRange() noexcept = delete;
                PinkColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Pink1(PINK::Pink89, bg_c), Pink2(PINK::Pink125, bg_c), 
                    Pink3(PINK::Pink13, bg_c), Pink4(PINK::Pink161, bg_c), Pink5(PINK::Pink162, bg_c), Pink6(PINK::Pink163, bg_c), Pink7(PINK::Pink197, bg_c), 
                    Pink8(PINK::Pink198, bg_c), Pink9(PINK::Pink199, bg_c), Pink10(PINK::Pink200, bg_c), Pink11(PINK::Pink132, bg_c), Pink12(PINK::Pink168, bg_c), 
                    Pink13(PINK::Pink169, bg_c), Pink14(PINK::Pink204, bg_c), Pink15(PINK::Pink205, bg_c), Pink16(PINK::Pink206, bg_c), Pink17(PINK::Pink174, bg_c), 
                    Pink18(PINK::Pink175, bg_c), Pink19(PINK::Pink211, bg_c), Pink20(PINK::Pink212, bg_c), Pink21(PINK::Pink218, bg_c), Pink22(PINK::Pink224, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "P" : "Pink"), index, 22);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 22).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "P" : "Pink"), index, 22, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<PinkColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 22).
                const const_Color_iterator<PinkColorRange> end() const { return {this, 22}; } 
            private:
                inline static const constexpr Color PinkColorRange::* table[22] = {
                    &PinkColorRange::Pink1,
                    &PinkColorRange::Pink2,
                    &PinkColorRange::Pink3,
                    &PinkColorRange::Pink4,
                    &PinkColorRange::Pink5,
                    &PinkColorRange::Pink6,
                    &PinkColorRange::Pink7,
                    &PinkColorRange::Pink8,
                    &PinkColorRange::Pink9,
                    &PinkColorRange::Pink10,
                    &PinkColorRange::Pink11,
                    &PinkColorRange::Pink12,
                    &PinkColorRange::Pink13,
                    &PinkColorRange::Pink14,
                    &PinkColorRange::Pink15,
                    &PinkColorRange::Pink16,
                    &PinkColorRange::Pink17,
                    &PinkColorRange::Pink18,
                    &PinkColorRange::Pink19,
                    &PinkColorRange::Pink20,
                    &PinkColorRange::Pink21,
                    &PinkColorRange::Pink22
                };
            };
            PinkColorRange Pink_Color_Range;
            bool bg_color;
        public:
            _Pink() noexcept = delete;
            _Pink(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Pink_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_Pink =                  Color (Defined_Colors::Pink::Pink13, bg_color);
            const Color Dark_Pink =                 Color (Defined_Colors::Pink::Pink89, bg_color);
            const Color Raspberry_Rose_Pink =       Color (Defined_Colors::Pink::Pink125, bg_color);
            const Color Peony_Pink =                Color (Defined_Colors::Pink::Pink132, bg_color);
            const Color Vivid_Pink =                Color (Defined_Colors::Pink::Pink161, bg_color);
            const Color Deep_Fuchsia_Pink =         Color (Defined_Colors::Pink::Pink162, bg_color);
            const Color Fuchsia_Pink =              Color (Defined_Colors::Pink::Pink163, bg_color);
            const Color Rosebud_Pink =              Color (Defined_Colors::Pink::Pink168, bg_color);
            const Color Dreamy_Raspberry_Pink =     Color (Defined_Colors::Pink::Pink169, bg_color);
            const Color Blush_Rose_Pink =           Color (Defined_Colors::Pink::Pink174, bg_color);
            const Color Rose_Quartz_Pink =          Color (Defined_Colors::Pink::Pink175, bg_color);
            const Color Vivid_Raspberry_Pink =      Color (Defined_Colors::Pink::Pink197, bg_color);
            const Color Neon_Rose_Pink =            Color (Defined_Colors::Pink::Pink198, bg_color);
            const Color Dragonfruit_Pink =          Color (Defined_Colors::Pink::Pink199, bg_color);
            const Color Electric_Magenta_Pink =     Color (Defined_Colors::Pink::Pink200, bg_color);
            const Color Watermelon_Candy_Pink =     Color (Defined_Colors::Pink::Pink204, bg_color);
            const Color Cherry_Blossom_Pink =       Color (Defined_Colors::Pink::Pink205, bg_color);
            const Color Silk_Rose_Pink =            Color (Defined_Colors::Pink::Pink206, bg_color);
            const Color Tickle_Me_Pink =            Color (Defined_Colors::Pink::Pink211, bg_color);
            const Color Princess_Perfume_Pink =     Color (Defined_Colors::Pink::Pink212, bg_color);
            const Color Rosewater_Pink =            Color (Defined_Colors::Pink::Pink218, bg_color);
            const Color Powder_Pink =               Color (Defined_Colors::Pink::Pink224, bg_color);
            
            /// @brief Enables range-based for loops over the Pink color range.
            /// @return A const iterator to the first element of `Pink_Color_Range`.
            const const_Color_iterator<PinkColorRange> begin() const { return Pink_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Pink color range.
            /// @return A const iterator one past the last element of `Pink_Color_Range`.
            const const_Color_iterator<PinkColorRange> end() const { return Pink_Color_Range.end(); }

            /// @brief Retrieves a Pink color by index (valid range: 1 – 22) from the `Pink_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Pink color.
            /// @return A reference to the corresponding `Color` object in `Pink_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "P" : "Pink"), index, 22);    
                return Pink_Color_Range[index]; 
            }
            
            /// @brief Retrieves a Pink color by index (valid range: 1 – 22) from the `Pink_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Pink color.
            /// @return A reference to the corresponding `Color` object in `Pink_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "P" : "Pink"), index, 22, true);
                return Pink_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Pink_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Pink_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const PinkColorRange* operator->() const noexcept { return &Pink_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Neon_Rose_Pink ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Pink color wrapper containing the Neon_Rose_Pink escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Pink& pink) {
                os<< pink.Neon_Rose_Pink;
                return os;
            }
            ~_Pink() noexcept = default;
        };
        /// @brief Shortcut struct for easy access to ANSI 256 color definitions without typing full names.
        ///        Use 'O' for Orange, 'B' for Brown, 'V' for Violet, and 'B' for Blue to select the corresponding palette.
        struct ShortCut {
            _Orange O;
            _Brown B;
            _Violet V;
            _Pink P;
            ShortCut(bool bg_color) noexcept : O(bg_color, true), B(bg_color, true), V(bg_color, true), P(bg_color, true){};
        };
        ShortCut short_cut;
    public:
        _Orange Orange;
        _Brown Brown;
        _Violet Violet;
        _Pink Pink;

        TertiaryColors() noexcept = delete;
        TertiaryColors(bool bg_color) noexcept : short_cut(bg_color), Orange(bg_color), Brown(bg_color), Violet(bg_color), Pink(bg_color){};

        /// @brief Overloads the `operator->()` as a shortcut for easy access to the (`ShortCut`) ANSI 256 palettes.
        ///        Use 'O' for Orange, 'B' for Brown, 'V' for Violet, and 'P' for Pink instead of their full palette names.
        /// @return A pointer to the internal `short_cut` instance.
        const ShortCut* operator->() const noexcept {
            return &short_cut;
        }
        ~TertiaryColors() noexcept = default;
    };

    /// @brief This class defines the gray scale: Black, Gray, White and Shades.
    class GrayScaleColors {
        /// @brief Helper method for checking if the given index isn't out of range, else it will throw an instance of 'std::out_of_range' with an appropriate error message.
        /// @param classInstance The class (color palette color) name of the caller method/ operator.
        /// @param index The given index.
        /// @param max_index The maximum index.
        /// @param at True in case the caller is the .at() method. Default = false.
        static void checkForOutOfRange(const std::string& classInstance, uint8_t index, uint8_t max_index, bool at = false){
            auto getOperator = [&classInstance]() -> std::string {
                return (classInstance.length() == 1 ? "->" : ".");
            };
            auto getErrorStart = [=]() -> std::string {
                if(at){
                    return "\nERROR: Illegal index in method 'GrayScaleColors"+getOperator()+classInstance+".at("+std::to_string(index)+")'";
                } else {
                    return "\nERROR: Illegal index in operator 'GrayScaleColorsColors"+getOperator()+classInstance+"["+std::to_string(index)+"]'";
                }
            };
            if(index > 0 && index <= max_index) return;
            if(index == 0){
                throw std::out_of_range(getErrorStart()+"\n\n\t-Indexing starts at 1 (corresponding to the first color palette name) and aligns with the member color definition names.\n");
            } else {
                throw std::out_of_range(getErrorStart()+"\n\n\t-Your index exceeds the available color range (1 - "+std::to_string(max_index)+")\n");
            }
        }
        
        friend class _Black;
        /// @brief Defines the GrayScale (color) Black in to 2 uniquely named color palettes. 
        class _Black {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class BlackColorRange {
                friend const_Color_iterator<BlackColorRange>;
                bool short_cut;
                typedef Defined_Colors::Black BLACK;
            public:
                const Color Black1;
                const Color Black2;
                const Color Black3;
                const Color Black4;
                BlackColorRange() noexcept = delete;
                BlackColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Black1(BLACK::Black16, bg_c), Black2(BLACK::Black232, bg_c), 
                    Black3(BLACK::Black0, bg_c), Black4(BLACK::Black233, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 4).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "B" : "Black"), index, 4);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 4).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "B" : "Black"), index, 4, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<BlackColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 4).
                const const_Color_iterator<BlackColorRange> end() const { return {this, 4}; }
            private:
                inline static const constexpr Color BlackColorRange::* table[4] = {
                    &BlackColorRange::Black1,
                    &BlackColorRange::Black2,
                    &BlackColorRange::Black3,
                    &BlackColorRange::Black4
                };
            };
            BlackColorRange Black_Color_Range;
            bool bg_color;
        public:
            _Black() noexcept = delete;
            _Black(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Black_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_Black =                 Color (Defined_Colors::Black::Black0, bg_color);
            const Color Extended_Black =            Color (Defined_Colors::Black::Black16, bg_color);
            const Color Vampire_Black =             Color (Defined_Colors::Black::Black232, bg_color);
            const Color Nightshade_Black =          Color (Defined_Colors::Black::Black233, bg_color);

            /// @brief Enables range-based for loops over the Black color range.
            /// @return A const iterator to the first element of `Black_Color_Range`.
            const const_Color_iterator<BlackColorRange> begin() const { return Black_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Black color range.
            /// @return A const iterator one past the last element of `Black_Color_Range`.
            const const_Color_iterator<BlackColorRange> end() const { return Black_Color_Range.end(); }

            /// @brief Retrieves a Black color by index (valid range: 1 – 4) from the `Black_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Black color.
            /// @return A reference to the corresponding `Color` object in `Black_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Black"), index, 4);    
                return Black_Color_Range[index]; 
            }

            /// @brief Retrieves a Black color by index (valid range: 1 – 4) from the `Black_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Black color.
            /// @return A reference to the corresponding `Color` object in `Black_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "B" : "Black"), index, 4, true);
                return Black_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Black_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Black_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const BlackColorRange* operator->() const noexcept { return &Black_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Extended_Black ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Black color wrapper containing the Extended_Black escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Black& black) {
                os<< black.Extended_Black;
                return os;
            }
            ~_Black() noexcept = default;
        };

        friend class _Gray;
        /// @brief Defines the GrayScale (color) Gray in to 2 uniquely named color palettes. 
        class _Gray {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class GrayColorRange {
                friend const_Color_iterator<GrayColorRange>;
                bool short_cut;
                typedef Defined_Colors::Gray GRAY;
            public:
                const Color Gray1;
                const Color Gray2;
                const Color Gray3;
                const Color Gray4;
                const Color Gray5;
                const Color Gray6;
                const Color Gray7;
                const Color Gray8;
                const Color Gray9;
                const Color Gray10;
                const Color Gray11;
                const Color Gray12;
                const Color Gray13;
                const Color Gray14;
                const Color Gray15;
                const Color Gray16;
                const Color Gray17;
                const Color Gray18;
                const Color Gray19;
                const Color Gray20;
                const Color Gray21;
                const Color Gray22;
                const Color Gray23;
                const Color Gray24;
                const Color Gray25;
                const Color Gray26;
                GrayColorRange() noexcept = delete;
                GrayColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), Gray1(GRAY::Gray234, bg_c), Gray2(GRAY::Gray235, bg_c), 
                    Gray3(GRAY::Gray236, bg_c), Gray4(GRAY::Gray237, bg_c), Gray5(GRAY::Gray238, bg_c), Gray6(GRAY::Gray239, bg_c), Gray7(GRAY::Gray240, bg_c), 
                    Gray8(GRAY::Gray59, bg_c), Gray9(GRAY::Gray241, bg_c), Gray10(GRAY::Gray242, bg_c), Gray11(GRAY::Gray243, bg_c), Gray12(GRAY::Gray8, bg_c), 
                    Gray13(GRAY::Gray244, bg_c), Gray14(GRAY::Gray102, bg_c), Gray15(GRAY::Gray245, bg_c), Gray16(GRAY::Gray246, bg_c), Gray17(GRAY::Gray247, bg_c), 
                    Gray18(GRAY::Gray248, bg_c), Gray19(GRAY::Gray145, bg_c), Gray20(GRAY::Gray249, bg_c), Gray21(GRAY::Gray250, bg_c), Gray22(GRAY::Gray251, bg_c), 
                    Gray23(GRAY::Gray252, bg_c), Gray24(GRAY::Gray188, bg_c), Gray25(GRAY::Gray253, bg_c), Gray26(GRAY::Gray254, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 26).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "G" : "Gray"), index, 26);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 26).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "G" : "Gray"), index, 26, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<GrayColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 26).
                const const_Color_iterator<GrayColorRange> end() const { return {this, 26}; }  
            private:
                inline static const constexpr Color GrayColorRange::* table[26] = {
                    &GrayColorRange::Gray1,
                    &GrayColorRange::Gray2,
                    &GrayColorRange::Gray3,
                    &GrayColorRange::Gray4,
                    &GrayColorRange::Gray5,
                    &GrayColorRange::Gray6,
                    &GrayColorRange::Gray7,
                    &GrayColorRange::Gray8,
                    &GrayColorRange::Gray9,
                    &GrayColorRange::Gray10,
                    &GrayColorRange::Gray11,
                    &GrayColorRange::Gray12,
                    &GrayColorRange::Gray13,
                    &GrayColorRange::Gray14,
                    &GrayColorRange::Gray15,
                    &GrayColorRange::Gray16,
                    &GrayColorRange::Gray17,
                    &GrayColorRange::Gray18,
                    &GrayColorRange::Gray19,
                    &GrayColorRange::Gray20,
                    &GrayColorRange::Gray21,
                    &GrayColorRange::Gray22,
                    &GrayColorRange::Gray23,
                    &GrayColorRange::Gray24,
                    &GrayColorRange::Gray25,
                    &GrayColorRange::Gray26
                };
            };
            GrayColorRange Gray_Color_Range;
            bool bg_color;
        public:
            _Gray() noexcept = delete;
            _Gray(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), Gray_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_Gray =                  Color (Defined_Colors::Gray::Gray8, bg_color);
            const Color Granite_Gray =              Color (Defined_Colors::Gray::Gray59, bg_color);
            const Color Smoke_Gray =                Color (Defined_Colors::Gray::Gray102, bg_color);
            const Color Fog_Gray =                  Color (Defined_Colors::Gray::Gray145, bg_color);
            const Color Frosted_Gray =              Color (Defined_Colors::Gray::Gray188, bg_color);
            const Color Soot_Gray =                 Color (Defined_Colors::Gray::Gray234, bg_color);
            const Color Graphite_Gray =             Color (Defined_Colors::Gray::Gray235, bg_color);
            const Color Charcoal_Gray =             Color (Defined_Colors::Gray::Gray236, bg_color);
            const Color Dusty_Charcoal_Gray =       Color (Defined_Colors::Gray::Gray237, bg_color);
            const Color Slate_Gray =                Color (Defined_Colors::Gray::Gray238, bg_color);
            const Color Gravel_Gray =               Color (Defined_Colors::Gray::Gray239, bg_color);
            const Color Shadow_Gray =               Color (Defined_Colors::Gray::Gray240, bg_color);
            const Color Nickel_Gray =               Color (Defined_Colors::Gray::Gray241, bg_color);
            const Color Mercury_Gray =              Color (Defined_Colors::Gray::Gray242, bg_color);
            const Color Dove_Gray =                 Color (Defined_Colors::Gray::Gray243, bg_color);
            const Color Flint_Gray =                Color (Defined_Colors::Gray::Gray244, bg_color);
            const Color Driftwood_Gray =            Color (Defined_Colors::Gray::Gray245, bg_color);
            const Color Stone_Gray =                Color (Defined_Colors::Gray::Gray246, bg_color);
            const Color Silver_Gray =               Color (Defined_Colors::Gray::Gray247, bg_color);
            const Color Concrete_Gray =             Color (Defined_Colors::Gray::Gray248, bg_color);
            const Color Aluminum_Gray =             Color (Defined_Colors::Gray::Gray249, bg_color);
            const Color Silver_Foil_Gray =          Color (Defined_Colors::Gray::Gray250, bg_color);
            const Color Chalk_Gray =                Color (Defined_Colors::Gray::Gray251, bg_color);
            const Color Marble_Gray =               Color (Defined_Colors::Gray::Gray252, bg_color);
            const Color Porcelain_Gray =            Color (Defined_Colors::Gray::Gray253, bg_color);
            const Color Snow_Gray =                 Color (Defined_Colors::Gray::Gray254, bg_color);
            
            /// @brief Enables range-based for loops over the Gray color range.
            /// @return A const iterator to the first element of `Gray_Color_Range`.
            const const_Color_iterator<GrayColorRange> begin() const { return Gray_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the Gray color range.
            /// @return A const iterator one past the last element of `Gray_Color_Range`.
            const const_Color_iterator<GrayColorRange> end() const { return Gray_Color_Range.end(); }

            /// @brief Retrieves a Gray color by index (valid range: 1 – 26) from the `Gray_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Gray color.
            /// @return A reference to the corresponding `Color` object in `Gray_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "G" : "Gray"), index, 26);    
                return Gray_Color_Range[index]; 
            }
            
            /// @brief Retrieves a Gray color by index (valid range: 1 – 26) from the `Gray_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired Gray color.
            /// @return A reference to the corresponding `Color` object in `Gray_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "G" : "Gray"), index, 26, true);
                return Gray_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`Gray_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `Gray_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const GrayColorRange* operator->() const noexcept { return &Gray_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Mercury_Gray ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The Gray color wrapper containing the Mercury_Gray escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _Gray& gray) {
                os<< gray.Mercury_Gray;
                return os;
            }
            ~_Gray() noexcept = default;
        };

        friend class _White;
        /// @brief Defines the GrayScale (color) White in to 2 uniquely named color palettes.
        class _White {
            bool short_cut;
            /// @brief A sorted palette mapping color names to their corresponding indices for the [] operator.
            class WhiteColorRange {
                friend const_Color_iterator<WhiteColorRange>;
                bool short_cut;
                typedef Defined_Colors::White WHITE;
            public:
                const Color White1;
                const Color White2;
                const Color White3;
                const Color White4;
                WhiteColorRange() noexcept = delete;
                WhiteColorRange(bool bg_c, bool short_cut = false) noexcept : short_cut(short_cut), White1(WHITE::White7, bg_c), White2(WHITE::White255, bg_c), White3(WHITE::White15, bg_c), 
                    White4(WHITE::White231, bg_c){};

                /// @brief Retrieves a color by index using the [] operator (valid range: 1 – 4).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color&operator[](uint8_t index) const {
                    checkForOutOfRange((short_cut ? "W" : "White"), index, 4);
                    return this->*(table[--index]);
                }

                /// @brief Retrieves a color by index with bounds checking (valid range: 1 – 4).
                /// @param index The 1-based index of the desired color.
                /// @return A reference to the corresponding Color object.
                /// @throws std::out_of_range if the index is outside the valid range.
                const Color& at(uint8_t index) const { 
                    checkForOutOfRange((short_cut ? "W" : "White"), index, 4, true);    
                    return this->*(table[--index]); 
                }
                
                /// @brief Returns a const iterator to the first color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned at the first color (index 0).
                const const_Color_iterator<WhiteColorRange> begin() const { return {this, 0}; }
                
                /// @brief Returns a const iterator one past the last color, enabling range-based for loops.
                /// @return A const_Color_iterator positioned one past the last color (index 4).
                const const_Color_iterator<WhiteColorRange> end() const { return {this, 4}; } 
            private:
                inline static const constexpr Color WhiteColorRange::* table[4] = {
                    &WhiteColorRange::White1,
                    &WhiteColorRange::White2,
                    &WhiteColorRange::White3,
                    &WhiteColorRange::White4
                };
            };
            WhiteColorRange White_Color_Range;
            bool bg_color;
        public: 
            _White() noexcept = delete;
            _White(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), White_Color_Range(bg_color, short_cut){
                this->short_cut = short_cut;
            }

            const Color std_White =                 Color (Defined_Colors::White::White7, bg_color);
            const Color Snowflake_White =           Color (Defined_Colors::White::White15, bg_color);
            const Color Pure_White =                Color (Defined_Colors::White::White231, bg_color);
            const Color Pearl_White =               Color (Defined_Colors::White::White255, bg_color);

            /// @brief Enables range-based for loops over the White color range.
            /// @return A const iterator to the first element of `White_Color_Range`.
            const const_Color_iterator<WhiteColorRange> begin() const { return White_Color_Range.begin(); }
        
            /// @brief Enables range-based for loops over the White color range.
            /// @return A const iterator one past the last element of `White_Color_Range`.
            const const_Color_iterator<WhiteColorRange> end() const { return White_Color_Range.end(); }

            /// @brief Retrieves a White color by index (valid range: 1 – 4) from the `White_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired White color.
            /// @return A reference to the corresponding `Color` object in `White_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const { 
                checkForOutOfRange((short_cut ? "W" : "White"), index, 4);    
                return White_Color_Range[index]; 
            }
            
            /// @brief Retrieves a White color by index (valid range: 1 – 4) from the `White_Color_Range` with bounds checking.
            /// @param index The 1-based index of the desired White color.
            /// @return A reference to the corresponding `Color` object in `White_Color_Range`.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const { 
                checkForOutOfRange((short_cut ? "W" : "White"), index, 4, true);
                return White_Color_Range.at(index); 
            }

            /// @brief Overload of `operator->()` to access the secondary color palette (`White_Color_Range`),  
            /// which is sorted from dark to light, uses a different naming scheme, and provides its own  
            /// index operator (`operator[](uint8_t)`) and STL-style iteration methods.  
            /// @return A pointer to the internal `White_Color_Range`, the only other way (besides indexing and iterators) to access this palette.
            const WhiteColorRange* operator->() const noexcept { return &White_Color_Range; }
            
            /// @brief Overloads `operator<<` to insert the Pure_White ANSI 256 escape sequence into an output stream.
            /// @param os  The output stream to write to.
            /// @param red The White color wrapper containing the Pure_White escape sequence.
            /// @return A reference to the modified `std::ostream`.
            friend std::ostream&operator<<(std::ostream& os, const _White& white) {
                os<< white.Pure_White;
                return os;
            }
            ~_White() noexcept = default;
        };

        friend class _Shades;
        /// @brief Defines the 'GrayScale Shades' in to a subset of 24 color steps going from dark- to light shades. This palette does not define color names nor has it any unique color codes; it only acts as a step up grayscale shades interface ranging from ANSI 256 color code (232 to 255).
        class _Shades {
            friend const_Color_iterator<_Shades>;
            bool bg_color,
                 short_cut;
        public:
            _Shades() noexcept = delete;
            _Shades(bool bg_color, bool short_cut = false) noexcept : bg_color(bg_color), short_cut(short_cut){};

            const Color Shade1 =        Color (Defined_Colors::GrayScale::Black232, bg_color);
            const Color Shade2 =        Color (Defined_Colors::GrayScale::Black233, bg_color);
            
            const Color Shade3 =        Color (Defined_Colors::GrayScale::Gray234, bg_color);
            const Color Shade4 =        Color (Defined_Colors::GrayScale::Gray235, bg_color);
            const Color Shade5 =        Color (Defined_Colors::GrayScale::Gray236, bg_color);
            const Color Shade6 =        Color (Defined_Colors::GrayScale::Gray237, bg_color);
            const Color Shade7 =        Color (Defined_Colors::GrayScale::Gray238, bg_color);
            const Color Shade8 =        Color (Defined_Colors::GrayScale::Gray239, bg_color);
            const Color Shade9 =        Color (Defined_Colors::GrayScale::Gray240, bg_color);
            const Color Shade10 =       Color (Defined_Colors::GrayScale::Gray241, bg_color);
            const Color Shade11 =       Color (Defined_Colors::GrayScale::Gray242, bg_color);
            const Color Shade12 =       Color (Defined_Colors::GrayScale::Gray243, bg_color);
            const Color Shade13 =       Color (Defined_Colors::GrayScale::Gray244, bg_color);
            const Color Shade14 =       Color (Defined_Colors::GrayScale::Gray245, bg_color);
            const Color Shade15 =       Color (Defined_Colors::GrayScale::Gray246, bg_color);
            const Color Shade16 =       Color (Defined_Colors::GrayScale::Gray247, bg_color);
            const Color Shade17 =       Color (Defined_Colors::GrayScale::Gray248, bg_color);
            const Color Shade18 =       Color (Defined_Colors::GrayScale::Gray249, bg_color);
            const Color Shade19 =       Color (Defined_Colors::GrayScale::Gray250, bg_color);
            const Color Shade20 =       Color (Defined_Colors::GrayScale::Gray251, bg_color);
            const Color Shade21 =       Color (Defined_Colors::GrayScale::Gray252, bg_color);
            const Color Shade22 =       Color (Defined_Colors::GrayScale::Gray253, bg_color);
            const Color Shade23 =       Color (Defined_Colors::GrayScale::Gray254, bg_color);
            
            const Color Shade24 =       Color (Defined_Colors::GrayScale::White255, bg_color);

            /// @brief Retrieves a shade by index using the [] operator (valid range: 1 – 24).
            /// @param index The 1-based index of the desired shade.
            /// @return A reference to the corresponding Color object.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color&operator[](uint8_t index) const {
                checkForOutOfRange((short_cut ? "S" : "Shades"), index, 24);
                return this->*(table[--index]);
            }
            
            /// @brief Retrieves a shade by index with bounds checking (valid range: 1 – 24).
            /// @param index The 1-based index of the desired shade.
            /// @return A reference to the corresponding Color object.
            /// @throws std::out_of_range if the index is outside the valid range.
            const Color& at(uint8_t index) const {
                checkForOutOfRange((short_cut ? "S" : "Shades"), index, 24, true);
                return this->*(table[--index]);
            }
            
            /// @brief Returns a const iterator to the first shade, enabling range-based for loops.
            /// @return A const_Color_iterator positioned at the first shade (index 0).
            const const_Color_iterator<_Shades> begin() const { return {this, 0}; }

            /// @brief Returns a const iterator one past the last shade, enabling range-based for loops.
            /// @return A const_Color_iterator positioned one past the last shade (index 24).
            const const_Color_iterator<_Shades> end() const { return {this, 24}; }

            ~_Shades() noexcept = default;
        private:
            inline static const constexpr Color _Shades::* table[24] = {
                &_Shades::Shade1,
                &_Shades::Shade2,
                &_Shades::Shade3,
                &_Shades::Shade4,
                &_Shades::Shade5,
                &_Shades::Shade6,
                &_Shades::Shade7,
                &_Shades::Shade8,
                &_Shades::Shade9,
                &_Shades::Shade10,
                &_Shades::Shade11,
                &_Shades::Shade12,
                &_Shades::Shade13,
                &_Shades::Shade14,
                &_Shades::Shade15,
                &_Shades::Shade16,
                &_Shades::Shade17,
                &_Shades::Shade18,
                &_Shades::Shade19,
                &_Shades::Shade20,
                &_Shades::Shade21,
                &_Shades::Shade22,
                &_Shades::Shade23,
                &_Shades::Shade24
            }; 
        };
        /// @brief Shortcut struct for easy access to ANSI 256 color definitions without typing full names.
        ///        Use 'B' for Black, 'G' for Gray, 'W' for White, and 'S' for Shades to select the corresponding palette.
        struct ShortCut {
            const _Black B;
            const _Gray G;
            const _White W;
            const _Shades S;
            ShortCut(bool bg_color) noexcept : B(bg_color, true), G(bg_color, true), W(bg_color, true), S(bg_color, true){};
        };
        const ShortCut short_cut;
    public:
        const _Black Black;
        const _Gray Gray;
        const _White White;
        const _Shades Shades;
        GrayScaleColors() noexcept = delete;
        GrayScaleColors(bool bg_color) noexcept : short_cut(bg_color), Black(bg_color), Gray(bg_color), White(bg_color), Shades(bg_color){};

        /// @brief Overloads the `operator->()` as a shortcut for easy access to the (`ShortCut`) ANSI 256 palettes.
        ///        Use 'B' for Black, 'G' for Gray, 'W' for White, and 'S' for Shades instead of their full palette names.
        /// @return A pointer to the internal `short_cut` instance.
        const ShortCut* operator->() const noexcept {
            return &short_cut;
        }
        ~GrayScaleColors() noexcept = default;
    }; 
}

/// @brief Provides wrapper interfaces for ANSI 256‑color codes.
namespace ansi_colors {
    /// @brief Defines the `foreground` (text) ANSI 256 colors.
    namespace fg 
    {
        /// @brief This class defines the primary colors: Red, Green and Blue. 
        inline const __LMN_color_categories_defined_::PrimaryColors PrimaryColors (false);
        /// @brief This class defines the secondary colors: Cyan, Yellow and Purple.
        inline const __LMN_color_categories_defined_::SecondaryColors SecondaryColors (false);
        /// @brief This class defines the Tertiary colors ('catch all' for all colors that are not primary- or secondary colors): Orange, Brown, Violet and Pink.
        inline const __LMN_color_categories_defined_::TertiaryColors TertiaryColors (false);
        /// @brief This class defines the gray scale: Black, Gray, White and Shades.
        inline const __LMN_color_categories_defined_::GrayScaleColors GrayScaleColors (false);
    }

    /// @brief Defines the `background` ANSI 256 colors.
    namespace bg 
    {
        /// @brief This class defines the primary colors: Red, Green and Blue. 
        inline const __LMN_color_categories_defined_::PrimaryColors PrimaryColors (true);
        /// @brief This class defines the secondary colors: Cyan, Yellow and Purple.
        inline const __LMN_color_categories_defined_::SecondaryColors SecondaryColors (true);
        /// @brief This class defines the Tertiary colors ('catch all' for all colors that are not primary- or secondary colors): Orange, Brown, Violet and Pink.
        inline const __LMN_color_categories_defined_::TertiaryColors TertiaryColors (true);
        /// @brief This class defines the gray scale: Black, Gray, White and Shades.
        inline const __LMN_color_categories_defined_::GrayScaleColors GrayScaleColors (true);
    }

    /// @brief Contains uint8_t enum classes that group all color code values to there respective color group.
    typedef __LMN_color_categories_defined_::Defined_Colors Defined_Color_Values;

    /// @brief Resets all ANSI settings back to its default state. 
    inline constexpr const char* const Back_To_Default_Terminal_State = "\033[0m";

    /// @brief Calculates the ANSI 256-color code corresponding to the given RGB values.
    /// @param R The red component, as a `uint8_t` (0–255).
    /// @param G The green component, as a `uint8_t` (0–255).
    /// @param B The blue component, as a `uint8_t` (0–255).
    /// @return The corresponding ANSI 256-color code (0–255).
    inline constexpr uint8_t rgb_to_ansi256(uint8_t R, uint8_t G, uint8_t B){
        constexpr int ansi16_rgb[16][3] = {
            {  0,   0,   0}, {128,   0,   0}, {  0, 128,   0}, {128, 128,   0},
            {  0,   0, 128}, {128,   0, 128}, {  0, 128, 128}, {192, 192, 192},
            {128, 128, 128}, {255,   0,   0}, {  0, 255,   0}, {255, 255,   0},
            {  0,   0, 255}, {255,   0, 255}, {  0, 255, 255}, {255, 255, 255}
        };
        constexpr auto dist2 = [](int r1, int g1, int b1, int r2, int g2, int b2){
            int dr = r1-r2;
            int dg = g1-g2;
            int db = b1-b2;
            return dr*dr + dg*dg + db*db;
        };   
        int r = R, g = G, b = B;

        int best16 = 0,
            best16d = std::numeric_limits<int>::max();
        for(int i = 0; i < 16; ++i){
            int d = dist2(r, g, b,
                            ansi16_rgb[i][0],
                            ansi16_rgb[i][1],
                            ansi16_rgb[i][2]);
            if(d < best16d){
                best16d = d;
                best16 = i;
            }
        }

        constexpr int cube_levels[6] = {0, 95, 135, 175, 215, 255};
        constexpr auto to_level = [](int v){
            return (v == 255) ? 5 : (v / 51);
        };
        int lr = to_level(r), lg = to_level(g), lb = to_level(b);
        int cube_index = 16 + 36*lr + 6*lg + lb;
        int dc = dist2(r, g, b,
                        cube_levels[lr],
                        cube_levels[lg],
                        cube_levels[lb]);

        int gray_mean = (r + g + b) / 3;
        int gray_level = (gray_mean < 8) ? 0
                            : (gray_mean > 248) ? 23
                            : ((gray_mean - 8) / 10);
        int gray_index = 232 + gray_level;
        int gray_val = 8 + gray_level * 10;
        int dg2 = dist2(r, g, b, gray_val, gray_val, gray_val);

        if(best16d <= dc && best16d <= dg2){
            return static_cast<uint8_t>(best16);
        }
        else if(dc <= best16d && dc <= dg2){
            return static_cast<uint8_t>(cube_index);
        }
        else return static_cast<uint8_t>(gray_index);
    }
}

#if LEMONCODE_ANSICOLORS_CPP20_OR_NEWER
    #include <format>
    #include <sstream>

    namespace std {
        // Color formatter:
        template<typename CharT>
        struct formatter<ansi_colors::Color, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const ansi_colors::Color& col, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< col;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        // PrimaryColors formatters:
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::PrimaryColors::_Red, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::PrimaryColors::_Red& red, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< red;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::PrimaryColors::_Green, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::PrimaryColors::_Green& green, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< green;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::PrimaryColors::_Blue, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::PrimaryColors::_Blue& blue, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< blue;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        // SecondaryColors formatters:
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::SecondaryColors::_Cyan, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::SecondaryColors::_Cyan& cyan, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< cyan;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::SecondaryColors::_Yellow, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::SecondaryColors::_Yellow& yellow, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< yellow;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::SecondaryColors::_Purple, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::SecondaryColors::_Purple& purple, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< purple;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        // TertiaryColors formatters:
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::TertiaryColors::_Orange, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::TertiaryColors::_Orange& orange, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< orange;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::TertiaryColors::_Brown, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::TertiaryColors::_Brown& brown, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< brown;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::TertiaryColors::_Violet, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::TertiaryColors::_Violet& violet, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< violet;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::TertiaryColors::_Pink, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::TertiaryColors::_Pink& pink, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< pink;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        // GrayScaleColors formatters:
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::GrayScaleColors::_Black, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::GrayScaleColors::_Black& black, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< black;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::GrayScaleColors::_Gray, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::GrayScaleColors::_Gray& gray, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< gray;
                return base_fmt.format(oss.str(), ctx);
            }
        };
        template<typename CharT>
        struct formatter<__LMN_color_categories_defined_::GrayScaleColors::_White, CharT>{
            std::formatter<std::basic_string<CharT>, CharT> base_fmt;

            constexpr auto parse(format_parse_context& ctx){
                return base_fmt.parse(ctx);
            }

            template<typename FormatContext>
            auto format(const __LMN_color_categories_defined_::GrayScaleColors::_White& white, FormatContext& ctx) const {
                std::basic_ostringstream<CharT> oss;
                oss<< white;
                return base_fmt.format(oss.str(), ctx);
            }
        };
    }
#endif


// Intern constexpr helper namespace.
namespace __LMN_color_categories_defined_::__CONSTEXPR_ANSI_code_conv_helper_funcs_ {
    /// @brief This array defines all the `Foreground` color codes.
    inline constexpr const char* fg_color_code[256] {
        "\033[38;5;0m",
        "\033[38;5;1m",
        "\033[38;5;2m",
        "\033[38;5;3m",
        "\033[38;5;4m",
        "\033[38;5;5m",
        "\033[38;5;6m",
        "\033[38;5;7m",
        "\033[38;5;8m",
        "\033[38;5;9m",
        "\033[38;5;10m",
        "\033[38;5;11m",
        "\033[38;5;12m",
        "\033[38;5;13m",
        "\033[38;5;14m",
        "\033[38;5;15m",
        "\033[38;5;16m",
        "\033[38;5;17m",
        "\033[38;5;18m",
        "\033[38;5;19m",
        "\033[38;5;20m",
        "\033[38;5;21m",
        "\033[38;5;22m",
        "\033[38;5;23m",
        "\033[38;5;24m",
        "\033[38;5;25m",
        "\033[38;5;26m",
        "\033[38;5;27m",
        "\033[38;5;28m",
        "\033[38;5;29m",
        "\033[38;5;30m",
        "\033[38;5;31m",
        "\033[38;5;32m",
        "\033[38;5;33m",
        "\033[38;5;34m",
        "\033[38;5;35m",
        "\033[38;5;36m",
        "\033[38;5;37m",
        "\033[38;5;38m",
        "\033[38;5;39m",
        "\033[38;5;40m",
        "\033[38;5;41m",
        "\033[38;5;42m",
        "\033[38;5;43m",
        "\033[38;5;44m",
        "\033[38;5;45m",
        "\033[38;5;46m",
        "\033[38;5;47m",
        "\033[38;5;48m",
        "\033[38;5;49m",
        "\033[38;5;50m",
        "\033[38;5;51m",
        "\033[38;5;52m",
        "\033[38;5;53m",
        "\033[38;5;54m",
        "\033[38;5;55m",
        "\033[38;5;56m",
        "\033[38;5;57m",
        "\033[38;5;58m",
        "\033[38;5;59m",
        "\033[38;5;60m",
        "\033[38;5;61m",
        "\033[38;5;62m",
        "\033[38;5;63m",
        "\033[38;5;64m",
        "\033[38;5;65m",
        "\033[38;5;66m",
        "\033[38;5;67m",
        "\033[38;5;68m",
        "\033[38;5;69m",
        "\033[38;5;70m",
        "\033[38;5;71m",
        "\033[38;5;72m",
        "\033[38;5;73m",
        "\033[38;5;74m",
        "\033[38;5;75m",
        "\033[38;5;76m",
        "\033[38;5;77m",
        "\033[38;5;78m",
        "\033[38;5;79m",
        "\033[38;5;80m",
        "\033[38;5;81m",
        "\033[38;5;82m",
        "\033[38;5;83m",
        "\033[38;5;84m",
        "\033[38;5;85m",
        "\033[38;5;86m",
        "\033[38;5;87m",
        "\033[38;5;88m",
        "\033[38;5;89m",
        "\033[38;5;90m",
        "\033[38;5;91m",
        "\033[38;5;92m",
        "\033[38;5;93m",
        "\033[38;5;94m",
        "\033[38;5;95m",
        "\033[38;5;96m",
        "\033[38;5;97m",
        "\033[38;5;98m",
        "\033[38;5;99m",
        "\033[38;5;100m",
        "\033[38;5;101m",
        "\033[38;5;102m",
        "\033[38;5;103m",
        "\033[38;5;104m",
        "\033[38;5;105m",
        "\033[38;5;106m",
        "\033[38;5;107m",
        "\033[38;5;108m",
        "\033[38;5;109m",
        "\033[38;5;110m",
        "\033[38;5;111m",
        "\033[38;5;112m",
        "\033[38;5;113m",
        "\033[38;5;114m",
        "\033[38;5;115m",
        "\033[38;5;116m",
        "\033[38;5;117m",
        "\033[38;5;118m",
        "\033[38;5;119m",
        "\033[38;5;120m",
        "\033[38;5;121m",
        "\033[38;5;122m",
        "\033[38;5;123m",
        "\033[38;5;124m",
        "\033[38;5;125m",
        "\033[38;5;126m",
        "\033[38;5;127m",
        "\033[38;5;128m",
        "\033[38;5;129m",
        "\033[38;5;130m",
        "\033[38;5;131m",
        "\033[38;5;132m",
        "\033[38;5;133m",
        "\033[38;5;134m",
        "\033[38;5;135m",
        "\033[38;5;136m",
        "\033[38;5;137m",
        "\033[38;5;138m",
        "\033[38;5;139m",
        "\033[38;5;140m",
        "\033[38;5;141m",
        "\033[38;5;142m",
        "\033[38;5;143m",
        "\033[38;5;144m",
        "\033[38;5;145m",
        "\033[38;5;146m",
        "\033[38;5;147m",
        "\033[38;5;148m",
        "\033[38;5;149m",
        "\033[38;5;150m",
        "\033[38;5;151m",
        "\033[38;5;152m",
        "\033[38;5;153m",
        "\033[38;5;154m",
        "\033[38;5;155m",
        "\033[38;5;156m",
        "\033[38;5;157m",
        "\033[38;5;158m",
        "\033[38;5;159m",
        "\033[38;5;160m",
        "\033[38;5;161m",
        "\033[38;5;162m",
        "\033[38;5;163m",
        "\033[38;5;164m",
        "\033[38;5;165m",
        "\033[38;5;166m",
        "\033[38;5;167m",
        "\033[38;5;168m",
        "\033[38;5;169m",
        "\033[38;5;170m",
        "\033[38;5;171m",
        "\033[38;5;172m",
        "\033[38;5;173m",
        "\033[38;5;174m",
        "\033[38;5;175m",
        "\033[38;5;176m",
        "\033[38;5;177m",
        "\033[38;5;178m",
        "\033[38;5;179m",
        "\033[38;5;180m",
        "\033[38;5;181m",
        "\033[38;5;182m",
        "\033[38;5;183m",
        "\033[38;5;184m",
        "\033[38;5;185m",
        "\033[38;5;186m",
        "\033[38;5;187m",
        "\033[38;5;188m",
        "\033[38;5;189m",
        "\033[38;5;190m",
        "\033[38;5;191m",
        "\033[38;5;192m",
        "\033[38;5;193m",
        "\033[38;5;194m",
        "\033[38;5;195m",
        "\033[38;5;196m",
        "\033[38;5;197m",
        "\033[38;5;198m",
        "\033[38;5;199m",
        "\033[38;5;200m",
        "\033[38;5;201m",
        "\033[38;5;202m",
        "\033[38;5;203m",
        "\033[38;5;204m",
        "\033[38;5;205m",
        "\033[38;5;206m",
        "\033[38;5;207m",
        "\033[38;5;208m",
        "\033[38;5;209m",
        "\033[38;5;210m",
        "\033[38;5;211m",
        "\033[38;5;212m",
        "\033[38;5;213m",
        "\033[38;5;214m",
        "\033[38;5;215m",
        "\033[38;5;216m",
        "\033[38;5;217m",
        "\033[38;5;218m",
        "\033[38;5;219m",
        "\033[38;5;220m",
        "\033[38;5;221m",
        "\033[38;5;222m",
        "\033[38;5;223m",
        "\033[38;5;224m",
        "\033[38;5;225m",
        "\033[38;5;226m",
        "\033[38;5;227m",
        "\033[38;5;228m",
        "\033[38;5;229m",
        "\033[38;5;230m",
        "\033[38;5;231m",
        "\033[38;5;232m",
        "\033[38;5;233m",
        "\033[38;5;234m",
        "\033[38;5;235m",
        "\033[38;5;236m",
        "\033[38;5;237m",
        "\033[38;5;238m",
        "\033[38;5;239m",
        "\033[38;5;240m",
        "\033[38;5;241m",
        "\033[38;5;242m",
        "\033[38;5;243m",
        "\033[38;5;244m",
        "\033[38;5;245m",
        "\033[38;5;246m",
        "\033[38;5;247m",
        "\033[38;5;248m",
        "\033[38;5;249m",
        "\033[38;5;250m",
        "\033[38;5;251m",
        "\033[38;5;252m",
        "\033[38;5;253m",
        "\033[38;5;254m",
        "\033[38;5;255m"
    };

    /// @brief This array defines all the `Background` color codes.
    inline constexpr const char* bg_color_code[256] {
        "\033[48;5;0m",
        "\033[48;5;1m",
        "\033[48;5;2m",
        "\033[48;5;3m",
        "\033[48;5;4m",
        "\033[48;5;5m",
        "\033[48;5;6m",
        "\033[48;5;7m",
        "\033[48;5;8m",
        "\033[48;5;9m",
        "\033[48;5;10m",
        "\033[48;5;11m",
        "\033[48;5;12m",
        "\033[48;5;13m",
        "\033[48;5;14m",
        "\033[48;5;15m",
        "\033[48;5;16m",
        "\033[48;5;17m",
        "\033[48;5;18m",
        "\033[48;5;19m",
        "\033[48;5;20m",
        "\033[48;5;21m",
        "\033[48;5;22m",
        "\033[48;5;23m",
        "\033[48;5;24m",
        "\033[48;5;25m",
        "\033[48;5;26m",
        "\033[48;5;27m",
        "\033[48;5;28m",
        "\033[48;5;29m",
        "\033[48;5;30m",
        "\033[48;5;31m",
        "\033[48;5;32m",
        "\033[48;5;33m",
        "\033[48;5;34m",
        "\033[48;5;35m",
        "\033[48;5;36m",
        "\033[48;5;37m",
        "\033[48;5;38m",
        "\033[48;5;39m",
        "\033[48;5;40m",
        "\033[48;5;41m",
        "\033[48;5;42m",
        "\033[48;5;43m",
        "\033[48;5;44m",
        "\033[48;5;45m",
        "\033[48;5;46m",
        "\033[48;5;47m",
        "\033[48;5;48m",
        "\033[48;5;49m",
        "\033[48;5;50m",
        "\033[48;5;51m",
        "\033[48;5;52m",
        "\033[48;5;53m",
        "\033[48;5;54m",
        "\033[48;5;55m",
        "\033[48;5;56m",
        "\033[48;5;57m",
        "\033[48;5;58m",
        "\033[48;5;59m",
        "\033[48;5;60m",
        "\033[48;5;61m",
        "\033[48;5;62m",
        "\033[48;5;63m",
        "\033[48;5;64m",
        "\033[48;5;65m",
        "\033[48;5;66m",
        "\033[48;5;67m",
        "\033[48;5;68m",
        "\033[48;5;69m",
        "\033[48;5;70m",
        "\033[48;5;71m",
        "\033[48;5;72m",
        "\033[48;5;73m",
        "\033[48;5;74m",
        "\033[48;5;75m",
        "\033[48;5;76m",
        "\033[48;5;77m",
        "\033[48;5;78m",
        "\033[48;5;79m",
        "\033[48;5;80m",
        "\033[48;5;81m",
        "\033[48;5;82m",
        "\033[48;5;83m",
        "\033[48;5;84m",
        "\033[48;5;85m",
        "\033[48;5;86m",
        "\033[48;5;87m",
        "\033[48;5;88m",
        "\033[48;5;89m",
        "\033[48;5;90m",
        "\033[48;5;91m",
        "\033[48;5;92m",
        "\033[48;5;93m",
        "\033[48;5;94m",
        "\033[48;5;95m",
        "\033[48;5;96m",
        "\033[48;5;97m",
        "\033[48;5;98m",
        "\033[48;5;99m",
        "\033[48;5;100m",
        "\033[48;5;101m",
        "\033[48;5;102m",
        "\033[48;5;103m",
        "\033[48;5;104m",
        "\033[48;5;105m",
        "\033[48;5;106m",
        "\033[48;5;107m",
        "\033[48;5;108m",
        "\033[48;5;109m",
        "\033[48;5;110m",
        "\033[48;5;111m",
        "\033[48;5;112m",
        "\033[48;5;113m",
        "\033[48;5;114m",
        "\033[48;5;115m",
        "\033[48;5;116m",
        "\033[48;5;117m",
        "\033[48;5;118m",
        "\033[48;5;119m",
        "\033[48;5;120m",
        "\033[48;5;121m",
        "\033[48;5;122m",
        "\033[48;5;123m",
        "\033[48;5;124m",
        "\033[48;5;125m",
        "\033[48;5;126m",
        "\033[48;5;127m",
        "\033[48;5;128m",
        "\033[48;5;129m",
        "\033[48;5;130m",
        "\033[48;5;131m",
        "\033[48;5;132m",
        "\033[48;5;133m",
        "\033[48;5;134m",
        "\033[48;5;135m",
        "\033[48;5;136m",
        "\033[48;5;137m",
        "\033[48;5;138m",
        "\033[48;5;139m",
        "\033[48;5;140m",
        "\033[48;5;141m",
        "\033[48;5;142m",
        "\033[48;5;143m",
        "\033[48;5;144m",
        "\033[48;5;145m",
        "\033[48;5;146m",
        "\033[48;5;147m",
        "\033[48;5;148m",
        "\033[48;5;149m",
        "\033[48;5;150m",
        "\033[48;5;151m",
        "\033[48;5;152m",
        "\033[48;5;153m",
        "\033[48;5;154m",
        "\033[48;5;155m",
        "\033[48;5;156m",
        "\033[48;5;157m",
        "\033[48;5;158m",
        "\033[48;5;159m",
        "\033[48;5;160m",
        "\033[48;5;161m",
        "\033[48;5;162m",
        "\033[48;5;163m",
        "\033[48;5;164m",
        "\033[48;5;165m",
        "\033[48;5;166m",
        "\033[48;5;167m",
        "\033[48;5;168m",
        "\033[48;5;169m",
        "\033[48;5;170m",
        "\033[48;5;171m",
        "\033[48;5;172m",
        "\033[48;5;173m",
        "\033[48;5;174m",
        "\033[48;5;175m",
        "\033[48;5;176m",
        "\033[48;5;177m",
        "\033[48;5;178m",
        "\033[48;5;179m",
        "\033[48;5;180m",
        "\033[48;5;181m",
        "\033[48;5;182m",
        "\033[48;5;183m",
        "\033[48;5;184m",
        "\033[48;5;185m",
        "\033[48;5;186m",
        "\033[48;5;187m",
        "\033[48;5;188m",
        "\033[48;5;189m",
        "\033[48;5;190m",
        "\033[48;5;191m",
        "\033[48;5;192m",
        "\033[48;5;193m",
        "\033[48;5;194m",
        "\033[48;5;195m",
        "\033[48;5;196m",
        "\033[48;5;197m",
        "\033[48;5;198m",
        "\033[48;5;199m",
        "\033[48;5;200m",
        "\033[48;5;201m",
        "\033[48;5;202m",
        "\033[48;5;203m",
        "\033[48;5;204m",
        "\033[48;5;205m",
        "\033[48;5;206m",
        "\033[48;5;207m",
        "\033[48;5;208m",
        "\033[48;5;209m",
        "\033[48;5;210m",
        "\033[48;5;211m",
        "\033[48;5;212m",
        "\033[48;5;213m",
        "\033[48;5;214m",
        "\033[48;5;215m",
        "\033[48;5;216m",
        "\033[48;5;217m",
        "\033[48;5;218m",
        "\033[48;5;219m",
        "\033[48;5;220m",
        "\033[48;5;221m",
        "\033[48;5;222m",
        "\033[48;5;223m",
        "\033[48;5;224m",
        "\033[48;5;225m",
        "\033[48;5;226m",
        "\033[48;5;227m",
        "\033[48;5;228m",
        "\033[48;5;229m",
        "\033[48;5;230m",
        "\033[48;5;231m",
        "\033[48;5;232m",
        "\033[48;5;233m",
        "\033[48;5;234m",
        "\033[48;5;235m",
        "\033[48;5;236m",
        "\033[48;5;237m",
        "\033[48;5;238m",
        "\033[48;5;239m",
        "\033[48;5;240m",
        "\033[48;5;241m",
        "\033[48;5;242m",
        "\033[48;5;243m",
        "\033[48;5;244m",
        "\033[48;5;245m",
        "\033[48;5;246m",
        "\033[48;5;247m",
        "\033[48;5;248m",
        "\033[48;5;249m",
        "\033[48;5;250m",
        "\033[48;5;251m",
        "\033[48;5;252m",
        "\033[48;5;253m",
        "\033[48;5;254m",
        "\033[48;5;255m"
    };

    /// @brief constexpr helper that translates a uint8_t value into an ANSI code and selects the appropriate color mode.
    /// @param code The ANSI 256‑color index.
    /// @param bgColor If true, applies the color as a background; if false, applies it to text.
    /// @return The ANSI escape sequence for the specified color and mode.
    inline constexpr const char* getAnsi256Code(uint8_t code, bool bgColor){
        return (bgColor ? bg_color_code[code] : fg_color_code[code]);
    }
}


#endif
