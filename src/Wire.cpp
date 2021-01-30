#include "ArduinoFake.h"
#include "Wire.h"

void TwoWire::begin(void)
{
  return ArduinoFakeInstance(TwoWire, this)->begin();
}

void TwoWire::begin(uint8_t address)
{
  return ArduinoFakeInstance(TwoWire, this)->begin(address);
}

void TwoWire::begin(int address)
{
  return ArduinoFakeInstance(TwoWire, this)->begin(address);
}

void TwoWire::end(void)
{
  ArduinoFakeInstance(TwoWire, this)->end();
}

void TwoWire::setClock(uint32_t clock)
{
  ArduinoFakeInstance(TwoWire, this)->setClock(clock);
}

void TwoWire::setWireTimeout(uint32_t timeout, bool reset_with_timeout){
  ArduinoFakeInstance(TwoWire, this)->setWireTimeout(timeout, reset_with_timeout);
}

void TwoWire::clearWireTimeoutFlag(void){
  ArduinoFakeInstance(TwoWire, this)->clearWireTimeoutFlag();
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize, uint8_t sendStop)
{
  return ArduinoFakeInstance(TwoWire, this)->requestFrom(address, quantity, iaddress, isize, sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop) {
  return ArduinoFakeInstance(TwoWire, this)->requestFrom(address, quantity,sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return ArduinoFakeInstance(TwoWire, this)->requestFrom(address, quantity);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return ArduinoFakeInstance(TwoWire, this)->requestFrom(address, quantity);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return ArduinoFakeInstance(TwoWire, this)->requestFrom(address, quantity, sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{
  ArduinoFakeInstance(TwoWire, this)->beginTransmission(address);
}

void TwoWire::beginTransmission(int address)
{
  ArduinoFakeInstance(TwoWire, this)->beginTransmission(address);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  return ArduinoFakeInstance(TwoWire, this)->endTransmission(sendStop);
}

uint8_t TwoWire::endTransmission(void)
{
  return ArduinoFakeInstance(TwoWire, this)->endTransmission();
}

int TwoWire::available(void)
{
  return ArduinoFakeInstance(TwoWire, this)->available();
}

int TwoWire::read(void)
{
  return ArduinoFakeInstance(TwoWire, this)->read();
}

int TwoWire::peek(void)
{
  return ArduinoFakeInstance(TwoWire, this)->peek();
}

void TwoWire::flush(void)
{
  ArduinoFakeInstance(TwoWire, this)->flush();
}

/*void TwoWire::onReceiveService(uint8_t* inBytes, int numBytes)
{
  ArduinoFakeInstance(TwoWire)->onReceiveService(inBytes, numBytes);
}

void TwoWire::onRequestService(void)
{
  ArduinoFakeInstance(TwoWire)->onRequestService();
}*/

void TwoWire::onReceive( void (*function)(int) )
{
  ArduinoFakeInstance(TwoWire, this)->onReceive(function);
}

void TwoWire::onRequest( void (*function)(void) )
{
  ArduinoFakeInstance(TwoWire, this)->onRequest(function);
}

size_t TwoWire::write(uint8_t value)
{
    return ArduinoFakeInstance(TwoWire, this)->write(value);
}

size_t TwoWire::write(const uint8_t * pData, size_t len)
{
    return ArduinoFakeInstance(TwoWire, this)->write(pData, len);
}

TwoWire Wire = TwoWireFakeProxy(ArduinoFakeInstance(TwoWire));