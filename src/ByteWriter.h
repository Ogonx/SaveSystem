#pragma once

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

class ByteWriter {
public:
	void WriteU32(uint32_t value);
	void WriteFloat(float value);
	void WriteString(const std::string& s);
	const std::vector<uint8_t>& Data() const { return m_data; }

private:
	std::vector<uint8_t> m_data;
};