#ifndef IOSTREAM_h
#define IOSTREAM_h

#ifndef _STDARG_H
#ifndef _ANSI_STDARG_H_
#ifndef __need___va_list
#define _STDARG_H
#define _ANSI_STDARG_H_
#endif /* not __need___va_list */
#undef __need___va_list

/* Define __gnuc_va_list.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

/* Define the standard macros for the user,
   if this invocation was from the user program.  */
#ifdef _STDARG_H

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
    || __cplusplus + 0 >= 201103L
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif
#define __va_copy(d,s)	__builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */

#ifdef _BSD_VA_LIST
#undef _BSD_VA_LIST
#endif

#if defined(__svr4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
/* SVR4.2 uses _VA_LIST for an internal alias for va_list,
   so we must avoid testing it and setting it here.
   SVR4 uses _VA_LIST as a flag in stdarg.h, but we should
   have no conflict with that.  */
#ifndef _VA_LIST_
#define _VA_LIST_
#ifdef __i860__
#ifndef _VA_LIST
#define _VA_LIST va_list
#endif
#endif /* __i860__ */
typedef __gnuc_va_list va_list;
#ifdef _SCO_DS
#define __VA_LIST
#endif
#endif /* _VA_LIST_ */
#else /* not __svr4__ || _SCO_DS */

/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */
#if !defined (_VA_LIST_) || defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__) || defined(WINNT)
/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
#ifndef _VA_LIST_DEFINED
/* The macro _VA_LIST is used in SCO Unix 3.2.  */
#ifndef _VA_LIST
/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
#ifndef _VA_LIST_T_H
/* The macro __va_list__ is used by BeOS.  */
#ifndef __va_list__
typedef __gnuc_va_list va_list;
#endif /* not __va_list__ */
#endif /* not _VA_LIST_T_H */
#endif /* not _VA_LIST */
#endif /* not _VA_LIST_DEFINED */
#if !(defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__))
#define _VA_LIST_
#endif
#ifndef _VA_LIST
#define _VA_LIST
#endif
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif
#ifndef _VA_LIST_T_H
#define _VA_LIST_T_H
#endif
#ifndef __va_list__
#define __va_list__
#endif

#endif /* not _VA_LIST_, except on certain systems */

#endif /* not __svr4__ */

#endif /* _STDARG_H */

#endif /* not _ANSI_STDARG_H_ */
#endif /* not _STDARG_H */

//^
//|
// This is a workaround for the stdarg.h file not being included. 
typedef char* va_list;

#define va_start(ap, last) (ap = (va_list)&last + sizeof(last))
#define va_arg(ap, type) (*(type*)((ap += sizeof(type)) - sizeof(type)))
#define va_end(ap) (ap = (va_list)0)

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SD.h>
enum displayType{
    LCD,
    I2CLCD,
    OLED
};
enum LCDType{
    LCD16x2,
    LCD20x4
};
enum OLEDType{
    OLED128x64,
    OLED128x32
};
class iostream {
private:
    
    bool scrollDisplay = true; // scroll display.
    bool scrollLeftToRight = false; // if false, scroll right to left.
    bool clearOnUpdate = true; // clear display on update.
    bool blinkCursor = false; // blink cursor.
    bool cursor = false; // Show Cursor
    LCDType lcdType = LCD16x2; // LCD Type (default 16x2)
    OLEDType oledType = OLED128x64; // OLED Type (default 128x64)
    LiquidCrystal lcd = LiquidCrystal(12, 11, 5, 4, 3, 2); // LCD
    LiquidCrystal_I2C i2cLCD = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

public:
    void print(const char* str) {
        Serial.print(str);
    }
    
    void println(const char* str) {
        Serial.println(str);
    }

    //%d or %i: Signed integer.
    //%u: Unsigned integer.
    //%f: Floating-point number (double). For float arguments, float is promoted to double when passed through ....
    //%s: Null-terminated string.
    //%c: Single character.
    //%x or %X: Unsigned hexadecimal integer.
    //%p: Pointer address.
    //%%: A literal % character.  
    void printf(const char* format, ...){
        va_list args;
        va_start(args, format); // Initialize the argument list
        while (*format != '\0') {
            if (*format == '%') {
                format++; // Move past '%'
                switch (*format) {
                    case 's': {
                        // Handle string argument
                        char *str = va_arg(args, char*);
                        Serial.print(str);
                        break;
                    }
                    case 'd': {
                        // Handle integer argument
                        int i = va_arg(args, int);
                        Serial.print(i);
                        break;
                    }
                    case '%': {
                        // Handle escaped '%'
                        Serial.print('%');
                        break;
                    }
                    default:
                        // Unknown format specifier, print as-is
                        Serial.print('%');
                        Serial.print(*format);
                        break;
                }
            } else {
                // Not a format specifier, print the character
                Serial.print(*format);
            }
            format++;
        }
        va_end(args); // Clean up the argument list
    }

//TODO: Add scroll ability
    void printLCD(const char* str, LiquidCrystal& lcd, int line = 0, bool clear = false) {
        if(clearOnUpdate){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 16; j++){
                    lcd.setCursor(j, i);
                    lcd.print(" ");
                }
            }
           lcd.setCursor(0, 0);
            lcd.print("                "); 
        }
        if (clear) {
            lcd.setCursor(0, line);
            lcd.print("                ");
        }
        lcd.setCursor(0, line);
        lcd.print(str);
    }

    void clearScreen(LCDType = LCD16x2){
        if(lcdType == LCD16x2){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 16; j++){
                    lcd.setCursor(j, i);
                    lcd.print(" ");
                }
            }
        }
        else if(lcdType == LCD20x4){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 20; j++){
                    lcd.setCursor(j, i);
                    lcd.print(" ");
                }
            }
        }
    }
    void printI2CLCD(const char* str, LiquidCrystal_I2C& lcd, int line, bool clear = false) {
        if (clear) {
            lcd.setCursor(0, line);
            lcd.print("                ");
        }
        lcd.setCursor(0, line);
        lcd.print(str);
        if (strlen(str) > 16) {
            for (int i = 0; i < strlen(str) - 16; i++) {
                lcd.scrollDisplayLeft();
                delay(200);
            }
        }
    }

    bool saveToFile(const char* filename, const char* data) {
        File file = SD.open(filename, FILE_WRITE);
        if (!file) {
            return false;
        }
        file.print(data);
        file.close();
        return true;
    }
    
    // Load data from a file on the SD card
    bool loadFromFile(const char* filename, char* buffer, size_t bufferSize) {
        File file = SD.open(filename);
        if (!file) {
            return false;
        }
        size_t bytesRead = file.readBytes(buffer, bufferSize);
        buffer[bytesRead] = '\0';
        file.close();
        return true;
    }
    //... Add other I/O methods as needed 
};

extern iostream cout; // Typically, cout is used for console output.

#endif //IOSTREAM_h
