#pragma once

// объявление константы - кода цвета в консоли
const short BLACK   = 0b0000;
const short BLUE    = 0b0001;
const short GREEN   = 0b0010;
const short CYAN    = 0b0011;
const short RED     = 0b0100;
const short MAGENTA = 0b0101;
const short YELLOW  = 0b0110;
const short GRAY    = 0b0111;

const short LTBLACK   = 0b1000;
const short LTBLUE    = 0b1001;
const short LTGREEN   = 0b1010;
const short LTCYAN    = 0b1011;
const short LTRED     = 0b1100;
const short LTMAGENTA = 0b1101;
const short LTYELLOW  = 0b1110;
const short WHITE     = 0b1111;

// Цвета на черном фоне
const short BLACK_ON_BLACK     = BLACK   | BLACK << 4;
const short BLUE_ON_BLACK      = BLUE    | BLACK << 4;
const short GREEN_ON_BLACK     = GREEN   | BLACK << 4;
const short CYAN_ON_BLACK      = CYAN    | BLACK << 4;
const short RED_ON_BLACK       = RED     | BLACK << 4;
const short MAGENTA_ON_BLACK   = MAGENTA | BLACK << 4;
const short YELLOW_ON_BLACK    = YELLOW  | BLACK << 4;
const short GRAY_ON_BLACK      = GRAY    | BLACK << 4;

const short LTBLACK_ON_BLACK   = LTBLACK   | BLACK << 4;
const short LTBLUE_ON_BLACK    = LTBLUE    | BLACK << 4;
const short LTGREEN_ON_BLACK   = LTGREEN   | BLACK << 4;
const short LTCYAN_ON_BLACK    = LTCYAN    | BLACK << 4;
const short LTRED_ON_BLACK     = LTRED     | BLACK << 4;
const short LTMAGENTA_ON_BLACK = LTMAGENTA | BLACK << 4;
const short LTYELLOW_ON_BLACK  = LTYELLOW  | BLACK << 4;
const short WHITE_ON_BLACK     = WHITE     | BLACK << 4;

// Цвета на cинем фоне
const short BLACK_ON_BLUE     = BLACK   | BLUE << 4;
const short BLUE_ON_BLUE      = BLUE    | BLUE << 4;
const short GREEN_ON_BLUE     = GREEN   | BLUE << 4;
const short CYAN_ON_BLUE      = CYAN    | BLUE << 4;
const short RED_ON_BLUE       = RED     | BLUE << 4;
const short MAGENTA_ON_BLUE   = MAGENTA | BLUE << 4;
const short YELLOW_ON_BLUE    = YELLOW  | BLUE << 4;
const short GRAY_ON_BLUE      = GRAY    | BLUE << 4;

const short LTBLACK_ON_BLUE   = LTBLACK   | BLUE << 4;
const short LTBLUE_ON_BLUE    = LTBLUE    | BLUE << 4;
const short LTGREEN_ON_BLUE   = LTGREEN   | BLUE << 4;
const short LTCYAN_ON_BLUE    = LTCYAN    | BLUE << 4;
const short LTRED_ON_BLUE     = LTRED     | BLUE << 4;
const short LTMAGENTA_ON_BLUE = LTMAGENTA | BLUE << 4;
const short LTYELLOW_ON_BLUE  = LTYELLOW  | BLUE << 4;
const short WHITE_ON_BLUE     = WHITE     | BLUE << 4;

// Цвета на зеленом фоне
const short BLACK_ON_GREEN     = BLACK   | GREEN << 4;
const short BLUE_ON_GREEN      = BLUE    | GREEN << 4;
const short GREEN_ON_GREEN     = GREEN   | GREEN << 4;
const short CYAN_ON_GREEN      = CYAN    | GREEN << 4;
const short RED_ON_GREEN       = RED     | GREEN << 4;
const short MAGENTA_ON_GREEN   = MAGENTA | GREEN << 4;
const short YELLOW_ON_GREEN    = YELLOW  | GREEN << 4;
const short GRAY_ON_GREEN      = GRAY    | GREEN << 4;

const short LTBLACK_ON_GREEN   = LTBLACK   | GREEN << 4;
const short LTBLUE_ON_GREEN    = LTBLUE    | GREEN << 4;
const short LTGREEN_ON_GREEN   = LTGREEN   | GREEN << 4;
const short LTCYAN_ON_GREEN    = LTCYAN    | GREEN << 4;
const short LTRED_ON_GREEN     = LTRED     | GREEN << 4;
const short LTMAGENTA_ON_GREEN = LTMAGENTA | GREEN << 4;
const short LTYELLOW_ON_GREEN  = LTYELLOW  | GREEN << 4;
const short WHITE_ON_GREEN     = WHITE     | GREEN << 4;

// Цвета на голубом фоне
const short BLACK_ON_CYAN     = BLACK   | CYAN << 4;
const short BLUE_ON_CYAN      = BLUE    | CYAN << 4;
const short GREEN_ON_CYAN     = GREEN   | CYAN << 4;
const short CYAN_ON_CYAN      = CYAN    | CYAN << 4;
const short RED_ON_CYAN       = RED     | CYAN << 4;
const short MAGENTA_ON_CYAN   = MAGENTA | CYAN << 4;
const short YELLOW_ON_CYAN    = YELLOW  | CYAN << 4;
const short GRAY_ON_CYAN      = GRAY    | CYAN << 4;

const short LTBLACK_ON_CYAN   = LTBLACK   | CYAN << 4;
const short LTBLUE_ON_CYAN    = LTBLUE    | CYAN << 4;
const short LTGREEN_ON_CYAN   = LTGREEN   | CYAN << 4;
const short LTCYAN_ON_CYAN    = LTCYAN    | CYAN << 4;
const short LTRED_ON_CYAN     = LTRED     | CYAN << 4;
const short LTMAGENTA_ON_CYAN = LTMAGENTA | CYAN << 4;
const short LTYELLOW_ON_CYAN  = LTYELLOW  | CYAN << 4;
const short WHITE_ON_CYAN     = WHITE     | CYAN << 4;

// Цвета на красном фоне
const short BLACK_ON_RED     = BLACK   | RED << 4;
const short BLUE_ON_RED      = BLUE    | RED << 4;
const short GREEN_ON_RED     = GREEN   | RED << 4;
const short CYAN_ON_RED      = CYAN    | RED << 4;
const short RED_ON_RED       = RED     | RED << 4;
const short MAGENTA_ON_RED   = MAGENTA | RED << 4;
const short YELLOW_ON_RED    = YELLOW  | RED << 4;
const short GRAY_ON_RED      = GRAY    | RED << 4;

const short LTBLACK_ON_RED   = LTBLACK   | RED << 4;
const short LTBLUE_ON_RED    = LTBLUE    | RED << 4;
const short LTGREEN_ON_RED   = LTGREEN   | RED << 4;
const short LTCYAN_ON_RED    = LTCYAN    | RED << 4;
const short LTRED_ON_RED     = LTRED     | RED << 4;
const short LTMAGENTA_ON_RED = LTMAGENTA | RED << 4;
const short LTYELLOW_ON_RED  = LTYELLOW  | RED << 4;
const short WHITE_ON_RED     = WHITE     | RED << 4;

// Цвета на лиловом фоне
const short BLACK_ON_MAGENTA     = BLACK   | MAGENTA << 4;
const short BLUE_ON_MAGENTA      = BLUE    | MAGENTA << 4;
const short GREEN_ON_MAGENTA     = GREEN   | MAGENTA << 4;
const short CYAN_ON_MAGENTA      = CYAN    | MAGENTA << 4;
const short RED_ON_MAGENTA       = RED     | MAGENTA << 4;
const short MAGENTA_ON_MAGENTA   = MAGENTA | MAGENTA << 4;
const short YELLOW_ON_MAGENTA    = YELLOW  | MAGENTA << 4;
const short GRAY_ON_MAGENTA      = GRAY    | MAGENTA << 4;

const short LTBLACK_ON_MAGENTA   = LTBLACK   | MAGENTA << 4;
const short LTBLUE_ON_MAGENTA    = LTBLUE    | MAGENTA << 4;
const short LTGREEN_ON_MAGENTA   = LTGREEN   | MAGENTA << 4;
const short LTCYAN_ON_MAGENTA    = LTCYAN    | MAGENTA << 4;
const short LTRED_ON_MAGENTA     = LTRED     | MAGENTA << 4;
const short LTMAGENTA_ON_MAGENTA = LTMAGENTA | MAGENTA << 4;
const short LTYELLOW_ON_MAGENTA  = LTYELLOW  | MAGENTA << 4;
const short WHITE_ON_MAGENTA     = WHITE     | MAGENTA << 4;

// Цвета на желтом фоне
const short BLACK_ON_YELLOW     = BLACK   | YELLOW << 4;
const short BLUE_ON_YELLOW      = BLUE    | YELLOW << 4;
const short GREEN_ON_YELLOW     = GREEN   | YELLOW << 4;
const short CYAN_ON_YELLOW      = CYAN    | YELLOW << 4;
const short RED_ON_YELLOW       = RED     | YELLOW << 4;
const short MAGENTA_ON_YELLOW   = MAGENTA | YELLOW << 4;
const short YELLOW_ON_YELLOW    = YELLOW  | YELLOW << 4;
const short GRAY_ON_YELLOW      = GRAY    | YELLOW << 4;

const short LTBLACK_ON_YELLOW   = LTBLACK   | YELLOW << 4;
const short LTBLUE_ON_YELLOW    = LTBLUE    | YELLOW << 4;
const short LTGREEN_ON_YELLOW   = LTGREEN   | YELLOW << 4;
const short LTCYAN_ON_YELLOW    = LTCYAN    | YELLOW << 4;
const short LTRED_ON_YELLOW     = LTRED     | YELLOW << 4;
const short LTMAGENTA_ON_YELLOW = LTMAGENTA | YELLOW << 4;
const short LTYELLOW_ON_YELLOW  = LTYELLOW  | YELLOW << 4;
const short WHITE_ON_YELLOW     = WHITE     | YELLOW << 4;

// Цвета на сером фоне
const short BLACK_ON_GRAY     = BLACK   | GRAY << 4;
const short BLUE_ON_GRAY      = BLUE    | GRAY << 4;
const short GREEN_ON_GRAY     = GREEN   | GRAY << 4;
const short CYAN_ON_GRAY      = CYAN    | GRAY << 4;
const short RED_ON_GRAY       = RED     | GRAY << 4;
const short MAGENTA_ON_GRAY   = MAGENTA | GRAY << 4;
const short YELLOW_ON_GRAY    = YELLOW  | GRAY << 4;
const short GRAY_ON_GRAY      = GRAY    | GRAY << 4;

const short LTBLACK_ON_GRAY   = LTBLACK   | GRAY << 4;
const short LTBLUE_ON_GRAY    = LTBLUE    | GRAY << 4;
const short LTGREEN_ON_GRAY   = LTGREEN   | GRAY << 4;
const short LTCYAN_ON_GRAY    = LTCYAN    | GRAY << 4;
const short LTRED_ON_GRAY     = LTRED     | GRAY << 4;
const short LTMAGENTA_ON_GRAY = LTMAGENTA | GRAY << 4;
const short LTYELLOW_ON_GRAY  = LTYELLOW  | GRAY << 4;
const short WHITE_ON_GRAY     = WHITE     | GRAY << 4;

// Цвета на светло-черном фоне
const short BLACK_ON_LTBLACK     = BLACK   | LTBLACK << 4;
const short BLUE_ON_LTBLACK      = BLUE    | LTBLACK << 4;
const short GREEN_ON_LTBLACK     = GREEN   | LTBLACK << 4;
const short CYAN_ON_LTBLACK      = CYAN    | LTBLACK << 4;
const short RED_ON_LTBLACK       = RED     | LTBLACK << 4;
const short MAGENTA_ON_LTBLACK   = MAGENTA | LTBLACK << 4;
const short YELLOW_ON_LTBLACK    = YELLOW  | LTBLACK << 4;
const short GRAY_ON_LTBLACK      = GRAY    | LTBLACK << 4;

const short LTBLACK_ON_LTBLACK   = LTBLACK   | LTBLACK << 4;
const short LTBLUE_ON_LTBLACK    = LTBLUE    | LTBLACK << 4;
const short LTGREEN_ON_LTBLACK   = LTGREEN   | LTBLACK << 4;
const short LTCYAN_ON_LTBLACK    = LTCYAN    | LTBLACK << 4;
const short LTRED_ON_LTBLACK     = LTRED     | LTBLACK << 4;
const short LTMAGENTA_ON_LTBLACK = LTMAGENTA | LTBLACK << 4;
const short LTYELLOW_ON_LTBLACK  = LTYELLOW  | LTBLACK << 4;
const short WHITE_ON_LTBLACK     = WHITE     | LTBLACK << 4;

// Цвета на светло-cинем фоне
const short BLACK_ON_LTBLUE     = BLACK   | LTBLUE << 4;
const short BLUE_ON_LTBLUE      = BLUE    | LTBLUE << 4;
const short GREEN_ON_LTBLUE     = GREEN   | LTBLUE << 4;
const short CYAN_ON_LTBLUE      = CYAN    | LTBLUE << 4;
const short RED_ON_LTBLUE       = RED     | LTBLUE << 4;
const short MAGENTA_ON_LTBLUE   = MAGENTA | LTBLUE << 4;
const short YELLOW_ON_LTBLUE    = YELLOW  | LTBLUE << 4;
const short GRAY_ON_LTBLUE      = GRAY    | LTBLUE << 4;

const short LTBLACK_ON_LTBLUE   = LTBLACK   | LTBLUE << 4;
const short LTBLUE_ON_LTBLUE    = LTBLUE    | LTBLUE << 4;
const short LTGREEN_ON_LTBLUE   = LTGREEN   | LTBLUE << 4;
const short LTCYAN_ON_LTBLUE    = LTCYAN    | LTBLUE << 4;
const short LTRED_ON_LTBLUE     = LTRED     | LTBLUE << 4;
const short LTMAGENTA_ON_LTBLUE = LTMAGENTA | LTBLUE << 4;
const short LTYELLOW_ON_LTBLUE  = LTYELLOW  | LTBLUE << 4;
const short WHITE_ON_LTBLUE     = WHITE     | LTBLUE << 4;

// Цвета на светло-зеленом фоне
const short BLACK_ON_LTGREEN     = BLACK   | LTGREEN << 4;
const short BLUE_ON_LTGREEN      = BLUE    | LTGREEN << 4;
const short GREEN_ON_LTGREEN     = GREEN   | LTGREEN << 4;
const short CYAN_ON_LTGREEN      = CYAN    | LTGREEN << 4;
const short RED_ON_LTGREEN       = RED     | LTGREEN << 4;
const short MAGENTA_ON_LTGREEN   = MAGENTA | LTGREEN << 4;
const short YELLOW_ON_LTGREEN    = YELLOW  | LTGREEN << 4;
const short GRAY_ON_LTGREEN      = GRAY    | LTGREEN << 4;

const short LTBLACK_ON_LTGREEN   = LTBLACK   | LTGREEN << 4;
const short LTBLUE_ON_LTGREEN    = LTBLUE    | LTGREEN << 4;
const short LTGREEN_ON_LTGREEN   = LTGREEN   | LTGREEN << 4;
const short LTCYAN_ON_LTGREEN    = LTCYAN    | LTGREEN << 4;
const short LTRED_ON_LTGREEN     = LTRED     | LTGREEN << 4;
const short LTMAGENTA_ON_LTGREEN = LTMAGENTA | LTGREEN << 4;
const short LTYELLOW_ON_LTGREEN  = LTYELLOW  | LTGREEN << 4;
const short WHITE_ON_LTGREEN     = WHITE     | LTGREEN << 4;

// Цвета на светло-голубом фоне
const short BLACK_ON_LTCYAN     = BLACK   | LTCYAN << 4;
const short BLUE_ON_LTCYAN      = BLUE    | LTCYAN << 4;
const short GREEN_ON_LTCYAN     = GREEN   | LTCYAN << 4;
const short CYAN_ON_LTCYAN      = CYAN    | LTCYAN << 4;
const short RED_ON_LTCYAN       = RED     | LTCYAN << 4;
const short MAGENTA_ON_LTCYAN   = MAGENTA | LTCYAN << 4;
const short YELLOW_ON_LTCYAN    = YELLOW  | LTCYAN << 4;
const short GRAY_ON_LTCYAN      = GRAY    | LTCYAN << 4;

const short LTBLACK_ON_LTCYAN   = LTBLACK   | LTCYAN << 4;
const short LTBLUE_ON_LTCYAN    = LTBLUE    | LTCYAN << 4;
const short LTGREEN_ON_LTCYAN   = LTGREEN   | LTCYAN << 4;
const short LTCYAN_ON_LTCYAN    = LTCYAN    | LTCYAN << 4;
const short LTRED_ON_LTCYAN     = LTRED     | LTCYAN << 4;
const short LTMAGENTA_ON_LTCYAN = LTMAGENTA | LTCYAN << 4;
const short LTYELLOW_ON_LTCYAN  = LTYELLOW  | LTCYAN << 4;
const short WHITE_ON_LTCYAN     = WHITE     | LTCYAN << 4;

// Цвета на светло-красном фоне
const short BLACK_ON_LTRED     = BLACK   | LTRED << 4;
const short BLUE_ON_LTRED      = BLUE    | LTRED << 4;
const short GREEN_ON_LTRED     = GREEN   | LTRED << 4;
const short CYAN_ON_LTRED      = CYAN    | LTRED << 4;
const short RED_ON_LTRED       = RED     | LTRED << 4;
const short MAGENTA_ON_LTRED   = MAGENTA | LTRED << 4;
const short YELLOW_ON_LTRED    = YELLOW  | LTRED << 4;
const short GRAY_ON_LTRED      = GRAY    | LTRED << 4;

const short LTBLACK_ON_LTRED   = LTBLACK   | LTRED << 4;
const short LTBLUE_ON_LTRED    = LTBLUE    | LTRED << 4;
const short LTGREEN_ON_LTRED   = LTGREEN   | LTRED << 4;
const short LTCYAN_ON_LTRED    = LTCYAN    | LTRED << 4;
const short LTRED_ON_LTRED     = LTRED     | LTRED << 4;
const short LTMAGENTA_ON_LTRED = LTMAGENTA | LTRED << 4;
const short LTYELLOW_ON_LTRED  = LTYELLOW  | LTRED << 4;
const short WHITE_ON_LTRED     = WHITE     | LTRED << 4;

// Цвета на светло-лиловом фоне
const short BLACK_ON_LTMAGENTA     = BLACK   | LTMAGENTA << 4;
const short BLUE_ON_LTMAGENTA      = BLUE    | LTMAGENTA << 4;
const short GREEN_ON_LTMAGENTA     = GREEN   | LTMAGENTA << 4;
const short CYAN_ON_LTMAGENTA      = CYAN    | LTMAGENTA << 4;
const short RED_ON_LTMAGENTA       = RED     | LTMAGENTA << 4;
const short MAGENTA_ON_LTMAGENTA   = MAGENTA | LTMAGENTA << 4;
const short YELLOW_ON_LTMAGENTA    = YELLOW  | LTMAGENTA << 4;
const short GRAY_ON_LTMAGENTA      = GRAY    | LTMAGENTA << 4;

const short LTBLACK_ON_LTMAGENTA   = LTBLACK   | LTMAGENTA << 4;
const short LTBLUE_ON_LTMAGENTA    = LTBLUE    | LTMAGENTA << 4;
const short LTGREEN_ON_LTMAGENTA   = LTGREEN   | LTMAGENTA << 4;
const short LTCYAN_ON_LTMAGENTA    = LTCYAN    | LTMAGENTA << 4;
const short LTRED_ON_LTMAGENTA     = LTRED     | LTMAGENTA << 4;
const short LTMAGENTA_ON_LTMAGENTA = LTMAGENTA | LTMAGENTA << 4;
const short LTYELLOW_ON_LTMAGENTA  = LTYELLOW  | LTMAGENTA << 4;
const short WHITE_ON_LTMAGENTA     = WHITE     | LTMAGENTA << 4;

// Цвета на светло-желтом фоне
const short BLACK_ON_LTYELLOW     = BLACK   | LTYELLOW << 4;
const short BLUE_ON_LTYELLOW      = BLUE    | LTYELLOW << 4;
const short GREEN_ON_LTYELLOW     = GREEN   | LTYELLOW << 4;
const short CYAN_ON_LTYELLOW      = CYAN    | LTYELLOW << 4;
const short RED_ON_LTYELLOW       = RED     | LTYELLOW << 4;
const short MAGENTA_ON_LTYELLOW   = MAGENTA | LTYELLOW << 4;
const short YELLOW_ON_LTYELLOW    = YELLOW  | LTYELLOW << 4;
const short GRAY_ON_LTYELLOW      = GRAY    | LTYELLOW << 4;

const short LTBLACK_ON_LTYELLOW   = LTBLACK   | LTYELLOW << 4;
const short LTBLUE_ON_LTYELLOW    = LTBLUE    | LTYELLOW << 4;
const short LTGREEN_ON_LTYELLOW   = LTGREEN   | LTYELLOW << 4;
const short LTCYAN_ON_LTYELLOW    = LTCYAN    | LTYELLOW << 4;
const short LTRED_ON_LTYELLOW     = LTRED     | LTYELLOW << 4;
const short LTMAGENTA_ON_LTYELLOW = LTMAGENTA | LTYELLOW << 4;
const short LTYELLOW_ON_LTYELLOW  = LTYELLOW  | LTYELLOW << 4;
const short WHITE_ON_LTYELLOW     = WHITE     | LTYELLOW << 4;

// Цвета на белом (светло-сером) фоне
const short BLACK_ON_WHITE     = BLACK   | WHITE << 4;
const short BLUE_ON_WHITE      = BLUE    | WHITE << 4;
const short GREEN_ON_WHITE     = GREEN   | WHITE << 4;
const short CYAN_ON_WHITE      = CYAN    | WHITE << 4;
const short RED_ON_WHITE       = RED     | WHITE << 4;
const short MAGENTA_ON_WHITE   = MAGENTA | WHITE << 4;
const short YELLOW_ON_WHITE    = YELLOW  | WHITE << 4;
const short GRAY_ON_WHITE      = GRAY    | WHITE << 4;

const short LTBLACK_ON_WHITE   = LTBLACK   | WHITE << 4;
const short LTBLUE_ON_WHITE    = LTBLUE    | WHITE << 4;
const short LTGREEN_ON_WHITE   = LTGREEN   | WHITE << 4;
const short LTCYAN_ON_WHITE    = LTCYAN    | WHITE << 4;
const short LTRED_ON_WHITE     = LTRED     | WHITE << 4;
const short LTMAGENTA_ON_WHITE = LTMAGENTA | WHITE << 4;
const short LTYELLOW_ON_WHITE  = LTYELLOW  | WHITE << 4;
const short WHITE_ON_WHITE     = WHITE     | WHITE << 4;