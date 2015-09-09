#include <platform/pin_descriptor.hpp>
#include <cstddef>
#include "target/pinconfig.hpp"

extern "C" {
// TODO: HACK - move it somewhere
void *memcpy(uint8_t *dst, const uint8_t *src, size_t cnt)
{
	uint8_t *dest = dst;
	while (cnt--) {
		*dst++ = *src++;
	}

	return dest;
}
}

// TODO: mopve it to the target.cpp / target.h module
void initializePins()
{
	constexpr PinDescr toInit[] = {
		// Console
		// USART3 TX
		createPin(PinPort::PORT_D, PinNum::PIN_8, PinAssignment::UART3, PinType::NOPULL),
		// USART3 RX
		createPin(PinPort::PORT_D, PinNum::PIN_9, PinAssignment::UART3, PinType::NOPULL),

		// Nokia5110 PCD8544
		// SPI2 NSS
		createPin(PinPort::PORT_B, PinNum::PIN_12, PinAssignment::PIN_SPI2, PinType::NOPULL),
		// SPI2 SCK
		createPin(PinPort::PORT_B, PinNum::PIN_13, PinAssignment::PIN_SPI2, PinType::NOPULL),
		// SPI2 MISO
		createPin(PinPort::PORT_B, PinNum::PIN_14, PinAssignment::PIN_SPI2, PinType::NOPULL),
		// SPI2 MOSI
		createPin(PinPort::PORT_B, PinNum::PIN_15, PinAssignment::PIN_SPI2, PinType::NOPULL),

		// RESET pin
		createPin(PinPort::PORT_C, PinNum::PIN_1, PinAssignment::GPIO_OUT, PinType::NOPULL),

		// Data/Instruction selection GPIO
		createPin(PinPort::PORT_C, PinNum::PIN_2, PinAssignment::GPIO_OUT, PinType::NOPULL),

	};

	for (auto pin : toInit) {
		pin.init();
	}
}