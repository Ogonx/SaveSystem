#include <iostream>
#include <vector>
#include <string>
#include "ByteWriter.h"
#include "ByteReader.h"

int main()
{
    ByteWriter writer;
    writer.WriteU32(258);
    writer.WriteFloat(1.0f);
    writer.WriteString("ogonx");

    for (uint8_t b : writer.Data()) {
        std::cout << static_cast<int>(b) << " ";
    }
    std::cout << "\n";

    ByteReader reader(writer.Data());
    uint32_t result = 0;
    bool ok = reader.ReadU32(result);
    std::cout << "ok: " << ok << " result: " << result << "\n";

    float floatResult = 0.0f;
    bool floatOk = reader.ReadFloat(floatResult);
    std::cout << "float ok: " << floatOk << " value: " << floatResult << "\n";

    ByteWriter floatWriter;
    floatWriter.WriteFloat(3.5f);
    floatWriter.WriteFloat(-2.25f);
    ByteReader floatReader(floatWriter.Data());
    float a = 0.0f;
    float b = 0.0f;
    floatReader.ReadFloat(a);
    floatReader.ReadFloat(b);
    std::cout << "floats: " << a << " " << b << "\n";

    std::vector<uint8_t> shortData = { 1, 2 };
    ByteReader shortReader(shortData);
    uint32_t dummy = 0;
    bool shortOk = shortReader.ReadU32(dummy);
    std::cout << "short ok: " << shortOk << "\n";

    ByteReader stringReader(writer.Data());
    uint32_t skipU32 = 0;
    float skipFloat = 0.0f;
    std::string text;
    stringReader.ReadU32(skipU32);
    stringReader.ReadFloat(skipFloat);
    bool stringOk = stringReader.ReadString(text);
    std::cout << "string ok: " << stringOk << " value: " << text << "\n";

    std::vector<uint8_t> corrupt = { 255, 255, 255, 255 };
    ByteReader corruptReader(corrupt);
    std::string junk;
    bool corruptOk = corruptReader.ReadString(junk);
    std::cout << "corrupt ok: " << corruptOk << "\n";

    ByteWriter emptyWriter;
    emptyWriter.WriteString("");
    ByteReader emptyReader(emptyWriter.Data());
    std::string empty = "x";
    bool emptyOk = emptyReader.ReadString(empty);
    std::cout << "empty ok: " << emptyOk << " size: " << empty.size() << "\n";

    return 0;
}