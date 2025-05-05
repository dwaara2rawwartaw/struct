#include <iostream>
#include <cmath>
using namespace std;
struct CELL 
{ 
    unsigned short character  : 8;
    unsigned short foreground : 3;
    unsigned short intensity  : 1;
    unsigned short background : 3;
    unsigned short blink      : 1;
} screen[25][80];

int main() {
    CELL apelsin;
    cout << "putb apelsin'a = "     << &apelsin           << endl;
    apelsin.character   = 'g';
    apelsin.intensity   = 0;
    apelsin.blink       = 1;
    apelsin.foreground  = 3;
    
    cout << "apelsin.character = "  << apelsin.character  << endl;
    cout << "apelsin.intensity = "  << apelsin.intensity  << endl;
    cout << "apelsin.blink = "      << apelsin.blink      << endl;
    cout << "apelsin.foreground = " << apelsin.foreground << endl;
    cout << " " << endl;

    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&apelsin); // Обращение непосредственно к apelsin. Меняет местами байты.
    *bytePtr |= (1<<(3));

    cout << "After Izmeneniya: " << endl;
    cout << "apelsin.character = "  << apelsin.character  << endl;
    cout << "apelsin.intensity = "  << apelsin.intensity  << endl;
    cout << "apelsin.blink = "      << apelsin.blink      << endl;
    cout << "apelsin.foreground = " << apelsin.foreground << endl;
    cout << " " << endl;

    cout << "Poly4enie baitov v pamyati: " << endl; // Перевод значений в шестнадцатиричную систему
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&apelsin);
    cout << std::hex << static_cast<int>(bytes[0]) << endl;
    cout << std::hex << static_cast<int>(bytes[1]) << endl;
    cout << " " << endl;

    cout << "After eshe odni izmeneniya: " << endl;
    cout << "apelsin.character = "  << apelsin.character  << endl;
    cout << "apelsin.intensity = "  << apelsin.intensity  << endl;
    cout << "apelsin.blink = "      << apelsin.blink      << endl;
    cout << "apelsin.foreground = " << apelsin.foreground << endl;

    return 0;
}