#include "ByteWriter.h"

void ByteWriter::WriteU32(uint32_t value) {

	m_data.push_back(static_cast<uint8_t>(value & 0xFF));
	m_data.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
	m_data.push_back(static_cast<uint8_t>((value >> 16) & 0xFF));
	m_data.push_back(static_cast<uint8_t>((value >> 24) & 0xFF));

}

void ByteWriter::WriteFloat(float value) {

	uint32_t bits;
	std::memcpy(&bits, &value, sizeof(bits));
	WriteU32(bits);
}

void ByteWriter::WriteString(const std::string& s) {
	
	WriteU32(static_cast<uint32_t>(s.size()));

	for (char c : s) {
		m_data.push_back(static_cast<uint8_t>(c));
	}
}